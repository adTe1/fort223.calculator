
%{

    //#include "tokens.h"
    #include <stdio.h>
    #include <stdlib.h> 
    #include "syntax.tab.h"

    
    char str_buf[256];
    int error_counter = 0;
    void tokenPrint(int token_id);
    void yyerror(const char* err);
    int strToInt(char *str);
    int length ;
    int count = 0;
    

%}

/* Read only 1 File */
%option noyywrap
/* Case insensitive tokens (e.x ClaSS == class) */
%option case-insensitive
/* count lines */
%option yylineno

%x STRING
%x SINGLE_LINE_COMMENT

/* Ισοδυναμιες Κλασεων */
STRINGG                 {DIGIT}+H
DIGIT                   [0-9]
LETTER                  [a-zA-Z]
ALPHANUM                {LETTER}|{DIGIT}


IDENTIFIER              _?{LETTER}{ALPHANUM}*_?{LETTER}{ALPHANUM}*_|{LETTER}{ALPHANUM}*
ICONST                  ([1-9][0-9]*)|(0[Xx][1-9A-Fa-f][0-9A-Fa-f]*)|(0[Oo][1-7][0-7]*)|(0[Bb][1-9][01]*)|(0)
RCONST                  [.]?[0-9]*[εΕeE][-+]?[0-9]+|(0[XxΧχ][0-9A-Fa-f]*\.[0-9A-Fa-f]*)|(0[oOοΟ][0-7]*\.[0-7]+)|(0[Bb][01]*\.[01]+)|([0-9]+\.[0-9]*|[0-9]*\.[0-9]+)|[0-9]+\.
LCONST                  (".TRUE."|".FALSE.") 
CCONST                  ('[ -~]')|('\\[nftrbv]')

%%/* <- Diaxorisths */

"FUNCTION"                                          {tokenPrint(T_FUNCTION); return T_FUNCTION; }
"SUBROUTINE"                                        {tokenPrint(T_SUBROUTINE); return T_SUBROUTINE; }
"END"                                               {tokenPrint(T_END); return T_END; }
"COMMON"                                            {tokenPrint(T_COMMON); return T_COMMON; }
"INTEGER"                                           {tokenPrint(T_INTEGER); return T_INTEGER; }
"REAL"                                              {tokenPrint(T_REAL); return T_REAL; }
"COMPLEX"                                           {tokenPrint(T_COMPLEX); return T_COMPLEX; }
"LOGICAL"                                           {tokenPrint(T_LOGICAL); return T_LOGICAL; }
"CHARACTER"                                         {tokenPrint(T_CHARACTER); return T_CHARACTER; }
"DATA"                                              {tokenPrint(T_DATA); return T_DATA; }
"CONTINUE"                                          {tokenPrint(T_CONTINUE); return T_CONTINUE; }
"GOTO"                                              {tokenPrint(T_GOTO); return T_GOTO; }
"call"                                              {tokenPrint(T_CALL); return T_CALL; }
"READ"                                              {tokenPrint(T_READ); return T_READ; }
"WRITE"                                             {tokenPrint(T_WRITE); return T_WRITE; }
"IF"                                                {tokenPrint(T_IF); return T_IF; }
"THEN"                                              {tokenPrint(T_THEN); return T_THEN; }
"ELSE"                                              {tokenPrint(T_ELSE); return T_ELSE; }
"ENDIF"                                             {tokenPrint(T_ENDIF); return T_ENDIF; }
"DO"                                                {tokenPrint(T_DO); return T_DO; }
"ENDDO"                                             {tokenPrint(T_ENDDO); return T_ENDDO; }
"STOP"                                              {tokenPrint(T_STOP); return T_STOP; }
"RETURN"                                            {tokenPrint(T_RETURN); return T_RETURN; }
"LENGTH"                                            {tokenPrint(T_LENGTH); return T_LENGTH; }

{IDENTIFIER}                                        {tokenPrint(T_ID); yylval.strval = strdup(yytext); return T_ID; }

{ICONST}                                            {tokenPrint(T_ICONST); yylval.intval = strToInt(yytext); return T_ICONST;}

{RCONST}                                            {tokenPrint(T_RCONST); yylval.realval = atof(yytext); return T_RCONST;}

{LCONST}                                            {tokenPrint(T_LCONST); yylval.booleanval = strdup(yytext); return T_LCONST;}                                            

{CCONST}                                            {tokenPrint(T_CCONST); yylval.charval = yytext[1]; return T_CCONST; } 



".OR."                                              {tokenPrint(T_OROP); return T_OROP;}
".AND."                                             {tokenPrint(T_ANDOP); return T_ANDOP;}                
".NOT."                                             {tokenPrint(T_NOTOP); return T_NOTOP;}
".GT."|".GE."|".LT."|".LE."|".EQ."|".NE."           {tokenPrint(T_RELOP); return T_RELOP;}
"+"                                                 {tokenPrint(T_ADDOP); return T_ADDOP;}
"-"                                                 {tokenPrint(T_ADDOP); return T_ADDOP;}
"*"                                                 {tokenPrint(T_MULOP); return T_MULOP;}
"/"                                                 {tokenPrint(T_DIVOP); return T_DIVOP;}
"**"                                                {tokenPrint(T_POWEROP); return T_POWEROP;}




"("                                                 {tokenPrint(T_LPAREN); return T_LPAREN; }
")"                                                 {tokenPrint(T_RPAREN); return T_RPAREN; }
","                                                 {tokenPrint(T_COMMA); return T_COMMA; }
"="                                                 {tokenPrint(T_ASSIGN); return T_ASSIGN; }
"["                                                 {tokenPrint(T_LBRACK); return T_LBRACK; }
"]"                                                 {tokenPrint(T_RBRACK); return T_RBRACK; }
":"                                                 {tokenPrint(T_COLON); return T_COLON; }

{STRINGG} {
    
    strcpy(str_buf, "");
    BEGIN(STRING);
    length = atoi(yytext); // Αποθήκευση του μήκους συμβολοσειράς
    count = 0; 
    printf("Μήκος συμβολοσειράς: %d\n", length);
     if (length == 0){
        BEGIN(INITIAL);
        printf("%d\n", length);
    }
   
}


<STRING>. {
    strcat(str_buf, yytext); // Προσθήκη του κειμένου στο str_buf
    count += strlen(yytext); // Ενημέρωση του μετρητή χαρακτήρων
    //printf("%s\n", str_buf); // Εκτύπωση της συμβολοσειράς
   
    if(count >= length) { // Ελέγχουμε αν έχουμε φτάσει στο τέλος της συμβολοσειράς
        //printf("%s\n", str_buf); // Εκτύπωση της συμβολοσειράς
        BEGIN(INITIAL); // Επιστροφή στην αρχική κατάσταση
        printf("%s\n", str_buf); // Εκτύπωση της συμβολοσειράς
        yylval.strval = strdup(str_buf);
        //strcat( T_STRING , str_buf);
        return T_STRING;    
    }
}

<STRING>\\(\n|\r\n) { }




<STRING>(\\.|[^\\]) {
        if(strlen(yytext) == 2 ){
            if(strcmp(yytext, "\\n") == 0) {
                count++;
                strcat(str_buf, "\n");
            }else if (strcmp(yytext, "\\t") == 0) {
                count++;
                strcat(str_buf, "\t");
            }else if (strcmp(yytext, "\\f") == 0) {
                count++;
                strcat(str_buf, "\f");
            }else if (strcmp(yytext, "\\r") ==0) {
                count++;
                strcat(str_buf, "\r");
            }else if (strcmp(yytext, "\\b") == 0) {
                count++;
                strcat(str_buf, "\b");
                count++;
            }else {
                strcat(str_buf, &yytext[1]);
                count++;
            }
        } else {
            strcat(str_buf, yytext);
            
        }
        
}



<STRING><<EOF>>                                     { yyerror("End of string without closing it\n"); }

"$"                                                 { BEGIN(SINGLE_LINE_COMMENT); }
<SINGLE_LINE_COMMENT>(\n|\r\n)                      { BEGIN(INITIAL); }
<SINGLE_LINE_COMMENT>.                             { }



[ \t]               {  } /* kenoi xarakthres */
[\n]               {  } /* new line for linux */
[\r\n]              {  } /* new line for windows */

<<EOF>>                                             {return T_EOF; }

.                                               {yyerror("Unrecognized character !\n"); }




%%

void tokenPrint (int token_id){
    //printf("Found token '%s' (%d) at line %d\n", yytext,token_id, yylineno);
    //printf("Found token (%s) \n", yytext);
    //yytext deixnei thn parousa anagnvrismenh le3i

    if(token_id == T_ICONST) {
       // printf("[LINE %d] INTEGER TOKEN \'%s\' . Base 10: %d\n", yylineno, yytext,  strToInt(yytext) );
    }else if(token_id == T_RCONST) {
        //printf("[LINE %d] REAL TOKEN \'%s\' . Base 10: %d\n", yylineno, yytext,  strToInt(yytext) );
    }else {
        //printf("[LINE %d]  TOKEN \'%s' (%d)\n", yylineno, yytext, token_id );
    }
}


int strToInt(char *str) {

    if(strncmp(str, "0o", 2) == 0|strncmp(str, "0O", 2) == 0) {//8diko arithmo
        return (int) strtoll(&str[2], NULL, 8);
    }else if (strncmp(str, "0B", 2) == 0|strncmp(str, "0b", 2) == 0) {//2diko arithmo
        return (int) strtoll(&str[2], NULL, 2);
    }else if (strncmp(str, "0X", 2) == 0|strncmp(str, "0x", 2) == 0) {//16diko arithmo
        return (int) strtoll(&str[2], NULL, 16);
    }else  {
        return (int) strtoll(str, NULL, 10);
    }
}

int strTofloat(char *str) {

    if(strncmp(str, "0o", 2) == 0|strncmp(str, "0O", 2) == 0) {//8diko arithmo
        return (float) strtoll(&str[2], NULL, 8);
    }else if (strncmp(str, "0B", 2) == 0|strncmp(str, "0b", 2) == 0) {//2diko arithmo
        return (float) strtoll(&str[2], NULL, 2);
    }else if (strncmp(str, "0X", 2) == 0|strncmp(str, "0x", 2) == 0) {//16diko arithmo
        return (float) strtoll(&str[2], NULL, 16);
    }else  {
        return (float) strtoll(str, NULL, 10);
    }
}

void yyerror(const char* err) {
    error_counter++;
    printf("[ERROR - LINE %d] %s\n", yylineno, err);

    if(error_counter ==5) {
        printf("maximoum errors found\n");
        exit(EXIT_FAILURE);
    }

    yyless(1);
}

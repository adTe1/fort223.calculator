%{

    #include "tokens.h"
    #include <stdio.h>
    #include <stdlib.h>

    
    char str_buf[256];

    void tokenPrint(int token_id);
    void yyerror(const char* err);
    int strToInt(char *str);
    int length ;

    int current_length = 0;
    int target_length = 0; // Θα ορίζεται από τον αριθμό πριν το 'H'
    

%}

/* Read only 1 File */
%option noyywrap
/* Case insensitive tokens (e.x ClaSS == class) */
%option case-insensitive
/* count lines */
%option yylineno

%x STRING
%option noyywrap

/* Ισοδυναμιες Κλασεων */
STRINGG                 [0-9]+H




%%/* <- Diaxorisths */



{STRINGG} {
    BEGIN(STRING);
    // Αποθήκευση του μήκους συμβολοσειράς 
    length = atoi(yytext); 
    str_buf[0] = '\0'; // Εκκαθάριση του str_buf πριν τη χρήση
    printf("mhkos string: %d", length);
    //<STRING>[^\n\\]*         { strncat(str_buf, yytext, length - strlen(str_buf)); printf("found string: %s \n", str_buf); }

}

<STRING>[^\n\\]*         { 
    if(current_length + strlen(yytext) > target_length) {
        strncat(str_buf, yytext, target_length - current_length); // Προσθήκη μόνο των χαρακτήρων που χρειάζονται
        BEGIN(INITIAL); 
        printf("String: %s\n", str_buf);
        str_buf[0] = '\0'; // Επαναφορά του str_buf για την επόμενη χρήση
    } else {
        strcat(str_buf, yytext);
        current_length += strlen(yytext);
    }
}

<STRING>(\\\n|\\\r\n)                               {  }
<STRING>(\\.[^\\])                               { strcat(str_buf, yytext); }
<STRING>(\n|\r\n)                               { printf("new line found without \\"); }
<STRING><<EOF>>                                 { printf("End of string without closing it\n"); }
<STRING>.                                        {printf("uNKNOWN CHARACTER. \n ");}


              






"("                                                 {tokenPrint(T_LPAREN); return T_LPAREN; }
")"                                                 {tokenPrint(T_RPAREN); return T_RPAREN; }
","                                                 {tokenPrint(T_COMMA); return T_COMMA; }
"="                                                 {tokenPrint(T_ASSIGN); return T_ASSIGN; }
"["                                                 {tokenPrint(T_LBRACK); return T_LBRACK; }
"]"                                                 {tokenPrint(T_RBRACK); return T_RBRACK; }
":"                                                 {tokenPrint(T_COLON); return T_COLON; }



[ \t]               {  } /* kenoi xarakthres */
[ \n]               {  } /*  */
[\r\n]              {  } /* new line for windows */

<<EOF>>                                             {return T_EOF; }

.                                               {printf("Unrecognized character at line %d !\n", yylineno); }




%%


int main(int argc, char *argv[]){
    int token;
    
    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if (yyin == NULL){
            perror ("Error opening file"); 
            return -1;
        }
    }

   do{
        token = yylex();
    }while (token != 0);

    fclose (yyin);
    yyterminate();

}

void tokenPrint (int token_id){
    printf("Found token '%s' (%d) at line %d\n", yytext,token_id, yylineno);
    //printf("Found token (%s) \n", yytext);
    //yytext deixnei thn parousa anagnvrismenh le3i

    if(token_id == T_ICONST) {
        printf("[LINE %d] INTEGER TOKEN \'%s\' (%d). Base 10: %d\n", yylineno, yytext, token_id, strToInt);
    }else if(token_id == T_RCONST) {
        printf("[LINE %d] FLOATING TOKEN \'%s\' (%d). Base 10: %d\n", yylineno, yytext, token_id);
    }else {
        //printf("[LINE %d]  TOKEN \'%s' (%d, %s)\n", yylineno, yytext, token_id, TOKEN_NAME[token_id]);
    }
}


int strToInt(char *str) {

    if(strncmp(str, "0o", 2) == 0) {//8diko arithmo
        return (int) strtoll(&str[2], NULL, 8);
    }else if (strncmp(str, "0b", 2) == 0) {//2diko arithmo
        return (int) strtoll(&str[2], NULL, 2);
    }else if (strncmp(str, "0x", 2) == 0) {//16diko arithmo
        return (int) strtoll(&str[2], NULL, 16);
    }else  {
        return (int) strtoll(&str[2], NULL, 10);
    }
}


%{
#include "tr.h" 
#include "syntax.tab.h"
#include <stdio.h>
#include <stdlib.h>

#include <math.h>

   
    void yyerror(const char* err);

%}

/* Read only 1 File */
%option noyywrap

/* Case insensitive tokens (e.x ClaSS == class) */
%option case-insensitive
/* count lines */
%option yylineno


DIGIT      [0-9]

%%/* <- Diaxorisths */

{DIGIT}+ {
    double doubleval = atof(yytext);
    yylval.doubleval = doubleval;
    return T_NUM;
}


"+"                     { return T_PLUS;}
"-"                     { return T_MINUS;}   
"*"                     { return T_MULT;}
"/"                     { return T_DIV;}
"^"                     { return T_POWER;}
";"                     { return T_SEMI;}


"sin"                   { return T_SIN;}
"cos"                   { return T_COS;}
"tan"                   { return T_TAN;}
"cot"                   { return T_COT;}
"mod"                   { return T_MOD;}


"NOT"|"!="              { return T_NOT;}
"AND"|"&&"              { return T_AND;}
"OR"|"||"               { return T_OR;}
"XOR"                   { return T_XOR;}
"NAND"                  { return T_NAND;}


"log"                   { return T_LOG;}
"!"                     { return T_FACTORIAL;}
"π"                     { return T_PI;}
"root"                  { return T_ROOT;}
"e"                     { return T_LNE;}
"("                     { return T_LPAREN;}
")"                     { return T_RPAREN;}




[ \t]                   {  }
[ \n]                   {  }
[\r\n]                  {  }
 
<<EOF>>                 {return 0; }
.                       { printf("Μη έγκυρος χαρακτήρας: %s\n", yytext); }
%%








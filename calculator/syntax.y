%{
#include "tr.h"
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "syntax.tab.h"
#include <stdlib.h>  // Για τη συνάρτηση atof




    extern FILE *yyin;
    typedef struct ast_node ast_node;
    extern int yyparse();
    extern int yylex();
    extern void yyerror(const char* err);
    

%}
%define parse.error verbose


%union {
    double doubleval;
    ast_node* ast;
    char *strval;
}



%token <doubleval> T_NUM               "number"           

// Operator
%token <strval> T_PLUS                "+"
%token <strval> T_MINUS               "-"
%token <strval> T_MULT                "*"
%token <strval> T_DIV                 "/"

%token <strval> T_POWER               "^"
%token <strval> T_LOG                 "log"
%token <strval> T_FACTORIAL           "!"
%token <strval> T_MOD                 "mod"
%token <strval> T_ROOT                "root"

// Constants
%token <strval> T_PI                  "π"
%token <strval> T_LNE                 "e"

// Other Tokens
%token <strval> T_LPAREN              "("
%token <strval> T_RPAREN              ")"
%token <strval> T_SEMI                ";"

%token <strval> T_SIN                 "sin"
%token <strval> T_COS                 "cos"
%token <strval> T_TAN                 "tan"
%token <strval> T_COT                 "cot"

// Operators
%token <strval> T_NOT                 "not"
%token <strval> T_AND                 "and"
%token <strval> T_OR                  "OR"
%token <strval> T_XOR                 "xor"
%token <strval> T_NAND                "nand"

%token T_EOF               0          "EOF"

%right T_NOT
%left T_AND T_NAND
%left T_OR
%left T_XOR
%left T_PLUS T_MINUS
%left T_MULT T_DIV T_MOD
%left T_LOG T_ROOT T_PI T_LNE
%left T_SIN T_COS T_TAN T_COT
%right T_POWER 
%nonassoc T_LPAREN T_RPAREN
%right T_FACTORIAL


%type <ast> expression



%%
statements:
                            | statements expression T_SEMI                { print_ast($2); free_ast($2); }
                            | expression T_SEMI                           { print_ast($1); free_ast($1); }
                            ;

expression:
                            T_NUM                                         { 
                                                                            char str[20]; // Υποθέτουμε μέγιστο μέγεθος 20
                                                                            sprintf(str, "%lf", $1); // Μετατροπή διπλού σε συμβολοσειρά
                                                                            $$ = create_ast_node(NULL, NULL, NULL);
                                                                            $$->doubleval = atof(str); 
                                                                          }
                            | expression T_PLUS expression                { $$ = create_ast_node("+", $1, $3); }
                            | expression T_MINUS expression               { $$ = create_ast_node("-", $1, $3); }
                            | expression T_MULT expression                { $$ = create_ast_node("*", $1, $3); }
                            | expression T_DIV expression                 { $$ = create_ast_node("/", $1, $3); }
                            | T_LPAREN expression T_RPAREN                { $$ = $2; }
                            | T_SIN T_LPAREN expression T_RPAREN          { $$ = create_ast_node("sin", NULL, $3); }
                            | T_COS T_LPAREN expression T_RPAREN          { $$ = create_ast_node("cos", NULL, $3); }
                            | T_TAN T_LPAREN expression T_RPAREN          { $$ = create_ast_node("tan", NULL, $3); }
                            | T_COT T_LPAREN expression T_RPAREN          { $$ = create_ast_node("cot", NULL, $3); }
                            | T_PI                                        { $$ = create_ast_node("π", NULL, NULL); $$->doubleval = M_PI; }
                            | T_LNE                                       { $$ = create_ast_node("e", NULL, NULL); $$->doubleval = M_E; }
                            | expression T_POWER expression               { $$ = create_ast_node("^", $1, $3); }
                            | T_ROOT T_LPAREN expression T_RPAREN         { $$ = create_ast_node("root", NULL, $3); }
                            | T_LOG T_LPAREN expression T_RPAREN          { $$ = create_ast_node("log", NULL, $3); }
                            | expression T_MOD expression                 { $$ = create_ast_node("mod", $1, $3); }
                            | expression T_FACTORIAL                      { $$ = create_ast_node("!", $1, NULL); }
                            | T_NOT expression                            { $$ = create_ast_node("NOT", $2, NULL); }
                            | expression T_AND expression                 { $$ = create_ast_node("AND", $1, $3); }
                            | expression T_OR expression                  { $$ = create_ast_node("OR", $1, $3); }
                            | expression T_XOR expression                 { $$ = create_ast_node("XOR", $1, $3); }
                            | expression T_NAND expression                { $$ = create_ast_node("NAND", $1, $3); }
                            ;
  




%%

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    yyin = file;
    
    // Αρχικοποίηση του ριζικού κόμβου
    ast_node *root = NULL;

    // Ανάλυση της εισόδου και δημιουργία του AST
    yyparse();

    fclose(file);

    return 0;
}



void yyerror(const char* err) {
    fprintf(stderr, "Error: %s\n", err);
    exit(EXIT_FAILURE);
}



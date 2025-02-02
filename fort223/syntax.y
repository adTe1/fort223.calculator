%{    
    #include <stdio.h>
    #include <stdlib.h>
    #include "extra/hashtbl.h"
     

    extern FILE *yyin; //sumperilamvanw to yyin popu exw dhlvmenv sto lexer.l
    extern int yylineno;
    extern int yylex();
    extern void yyerror(const char* err);

    HASHTBL *symbol_table;
    int scope = 0;
%}

%define parse.error verbose

%union {
    int intval;
    float realval;
    char *booleanval;
    char charval;
    char *strval; 
}

%token T_FUNCTION                        "function"
%token T_SUBROUTINE                      "subroutine"
%token T_END                             "end"
%token T_COMMON                          "common"
%token T_INTEGER                         "int"
%token T_REAL                            "real"
%token T_COMPLEX                         "complex"
%token T_LOGICAL                         "logical"
%token T_CHARACTER                       "char"
%token T_DATA                            "data"
%token T_CONTINUE                        "continue"
%token T_GOTO                            "goto"
%token T_CALL                            "call"
%token T_READ                            "read"
%token T_WRITE                           "write"
%token T_IF                              "if"
%token T_THEN                            "then"
%token T_ELSE                            "else"
%token T_ENDIF                           "endif"
%token T_DO                              "do"
%token T_ENDDO                           "enddo"
%token T_STOP                            "stop"
%token T_RETURN                          "return"
%token T_LENGTH                          "length"


%token <strval>      T_ID                "id"

%token <intval>      T_ICONST            "iconst"
%token <realval>     T_RCONST            "rconst"
%token <booleanval>  T_LCONST            "lconst"
%token <charval>     T_CCONST            "cconst"

%token <strval>      T_STRING            "string" 

//operators
%token T_OROP                            ".OR."  
%token T_ANDOP                           ".AND."  
%token T_NOTOP                           ".NOT." 
%token T_RELOP                           ".GT. or.GE. or .LT. or .LE. or .EQ. or .NE."
%token T_ADDOP                           "+ or -"
%token T_MULOP                           "*" 
%token T_DIVOP                           "/"
%token T_POWEROP                         "**" 




%token T_LPAREN                          "("
%token T_RPAREN                          ")"
%token T_COMMA                           ","
%token T_ASSIGN                          "="
%token T_LBRACK                          "["
%token T_RBRACK                          "]"
%token T_COLON                           ":" 

%token T_EOF          0                  "end of file"
/*
%type <strval> program body declarations type vars undef_variable dims dim cblock_list cblock id_list vals value_list values value sign constant simple_constant complex_constant statements labeled_statement label statement simple_statement assignment variable expressions expression goto_statement labels if_statement subroutine_call io_statement read_list read_item iter_space step write_list write_item compound_statement branch_statement tail loop_statement subprograms subprogram header formal_parameters
*/


%left T_COMMA
%right T_ASSIGN
%right T_COLON
%left T_OROP
%left T_ANDOP
%left T_RELOP
%left T_ADDOP                           
%left T_DIVOP
%left T_MULOP 
%right T_NOTOP
%left T_POWEROP 
%left T_LBRACK
%left T_RBRACK 
%left T_LPAREN
%left T_RPAREN


%start program

%%

program:            body T_END subprograms
                    ;
body:               declarations statements
                    ;
declarations:       declarations type vars
                    | declarations T_COMMON cblock_list
                    | declarations T_DATA vals
                    | %empty                                                                        { }
                    ;
type:               T_INTEGER | T_REAL | T_COMPLEX | T_LOGICAL | T_CHARACTER 
                    ;
vars:               vars T_COMMA undef_variable
                    | undef_variable
                    ;
undef_variable:     T_ID T_LPAREN dims T_RPAREN                                                     { hashtbl_insert(symbol_table, $1 ,  yylineno, scope); }
                    | T_ID                                                                          { hashtbl_insert(symbol_table, $1 ,  yylineno, scope); }
                    ;
dims :              dims T_COMMA dim
                    | dim
                    ;
dim:                T_ICONST
                    | T_ID                                                                          { hashtbl_insert(symbol_table, $1 ,  yylineno, scope); }
                    ;
cblock_list:        cblock_list cblock
                    | cblock
                    ;
cblock:             T_DIVOP T_ID T_DIVOP id_list                                                    { hashtbl_insert(symbol_table, $2 ,  yylineno, scope); }
                    ;
id_list:            id_list T_COMMA T_ID                                                            { hashtbl_insert(symbol_table, $3 ,  yylineno, scope); }
                    | T_ID                                                                          { hashtbl_insert(symbol_table, $1 ,  yylineno, scope); }
                    ;
vals:               vals T_COMMA T_ID value_list                                                    { hashtbl_insert(symbol_table, $3 ,  yylineno, scope); }
                    | T_ID value_list                                                               { hashtbl_insert(symbol_table, $1 ,  yylineno, scope); }
                    ;
value_list:         T_DIVOP values T_DIVOP
                    ;
values:             values T_COMMA value
                    | value
                    ;
value:              sign constant
                    | T_STRING
                    ;
sign:               T_ADDOP | %empty                                                                { }
                    ;
constant:           simple_constant
                    | complex_constant
                    ;
simple_constant:    T_ICONST | T_RCONST | T_LCONST | T_CCONST
                    ;
complex_constant:   T_LBRACK T_RCONST T_COLON sign T_RCONST T_RBRACK
                    ;
statements:         statements labeled_statement
                    | labeled_statement
                    ;
labeled_statement:  label statement
                    | statement
                    ;
label:              T_ICONST
                    ;
statement:          simple_statement
                    | compound_statement  
                    ;
simple_statement:   assignment
                    | goto_statement
                    | if_statement
                    | subroutine_call
                    | io_statement
                    | T_CONTINUE
                    | T_RETURN
                    | T_STOP
                    ;
assignment:         variable T_ASSIGN expression
                    | variable T_ASSIGN T_STRING
                    ;
variable:           T_ID T_LPAREN expressions T_RPAREN                                          { hashtbl_insert(symbol_table, $1 ,  yylineno, scope); }
                    | T_ID                                                                      { hashtbl_insert(symbol_table, $1 ,  yylineno, scope); }
                    ;
expressions:        expressions T_COMMA expression
                    | expression
                    ;
expression:         expression T_OROP expression
                    | expression T_ANDOP expression
                    | expression T_RELOP expression
                    | expression T_ADDOP expression
                    | expression T_MULOP expression
                    | expression T_DIVOP expression
                    | expression T_POWEROP expression
                    | T_NOTOP expression
                    | T_ADDOP expression
                    | variable
                    | simple_constant
                    | T_LPAREN expression T_RPAREN
                    | T_LBRACK expression T_COLON expression T_RBRACK
                    | T_LENGTH T_LPAREN expression T_RPAREN
                    ;
goto_statement:     T_GOTO label
                    | T_GOTO T_ID T_COMMA T_LPAREN labels T_RPAREN                           { hashtbl_insert(symbol_table, $2 , yylineno, scope); }
                    ;
labels:             labels T_COMMA label
                    | label
                    ;
if_statement:       T_IF T_LPAREN expression T_RPAREN label T_COMMA label T_COMMA label
                    | T_IF T_LPAREN expression T_RPAREN simple_statement
                    ;
subroutine_call:    T_CALL variable
                    ;
io_statement:       T_READ read_list
                    | T_WRITE write_list
                    ;
read_list:          read_list T_COMMA read_item
                    | read_item
                    ;
read_item:          variable
                    | T_LPAREN read_list T_COMMA T_ID T_ASSIGN iter_space T_RPAREN          { hashtbl_insert(symbol_table, $4 , yylineno, scope); }           
                    ;
iter_space:         expression T_COMMA expression step
                    ;
step:               T_COMMA expression
                    | %empty                                                               { }
                    ;
write_list:         write_list T_COMMA write_item
                    | write_item
                    ;
write_item:         expression
                    | T_LPAREN write_list T_COMMA T_ID T_ASSIGN iter_space T_RPAREN         { hashtbl_insert(symbol_table, $4 , yylineno, scope); }
                    | T_STRING
                    ;
compound_statement:   branch_statement                                          // { scope++; }
                    |  loop_statement                                               //{ scope++; }
                    ;
branch_statement:   T_IF   T_LPAREN  expression T_RPAREN T_THEN {scope++; } body tail     // { scope++; }                          
                    ;
tail:                T_ELSE  body T_ENDIF                                { hashtbl_get(symbol_table, scope); scope--;}                               
                    | T_ENDIF                                           { hashtbl_get(symbol_table, scope); scope--;}
                    ;
loop_statement:     T_DO T_ID T_ASSIGN iter_space {scope++; } body T_ENDDO                              { hashtbl_get(symbol_table, scope); scope--; hashtbl_insert(symbol_table, $2 , yylineno, scope);  }
                    ;
subprograms:        subprograms subprogram
                    | %empty                                                                { }
                    ;
subprogram:         header body T_END                                         
                    ;
header:             type T_FUNCTION T_ID T_LPAREN formal_parameters T_RPAREN                { hashtbl_insert(symbol_table, $3 , yylineno, scope); }
                    | T_SUBROUTINE T_ID T_LPAREN formal_parameters T_RPAREN                 { hashtbl_insert(symbol_table, $2 , yylineno, scope); }
                    | T_SUBROUTINE T_ID                                                     { hashtbl_insert(symbol_table, $2 , yylineno, scope); }
                    ;
formal_parameters:  type  vars     T_COMMA formal_parameters
                    | error  vars  T_COMMA formal_parameters                       {yyerror("wrong use formal parameter "); yyerrok; }
                    | type   error T_COMMA formal_parameters                       {yyerror("wrong use formal parameter "); yyerrok; }
                    | type   vars  error   formal_parameters                       {yyerror("wrong use formal parameter "); yyerrok; }
                    | type   vars  T_COMMA error                                   {yyerror("wrong use formal parameter "); yyerrok; }
                    | type   vars  
                    | error  vars                                                  {yyerror("wrong use formal parameter "); yyerrok; }
                    |type  error                                                   {yyerror("wrong use formal parameter "); yyerrok; }
                    ;                    
%%

   int main(int argc, char *argv[]){
    int token;

  
    /* diavase arxeio */
    if(argc > 1){
        yyin = fopen(argv[1], "r");
        if (yyin == NULL){
            perror ("[Error] opening file"); 
            return EXIT_FAILURE;
        }
    }

    symbol_table = hashtbl_create(23, NULL);

   /* syntaktikh ANALYSH */
   yyparse();

    fclose (yyin);
    hashtbl_destroy(symbol_table);
    return 0;
    
}


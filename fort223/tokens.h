
//keywords
# define T_FUNCTION          1
# define T_SUBROUTINE        2
# define T_END               3
# define T_COMMON            4
# define T_INTEGER           5
# define T_REAL              6
# define T_COMPLEX           7
# define T_LOGICAL           8
# define T_CHARACTER         9
# define T_DATA              10
# define T_CONTINUE          11
# define T_GOTO              12
# define T_CALL              13
# define T_READ              14
# define T_WRITE             15
# define T_IF                16
# define T_THEN              17
# define T_ELSE              18
# define T_ENDIF             19
# define T_DO                20
# define T_ENDDO             21
# define T_STOP              22
# define T_RETURN            23
# define T_LENGTH            24


#define T_ID                   25
#define T_ICONST               26
#define T_RCONST               27
#define T_LCONST               28
#define T_CCONST               29

//operators
# define T_OROP                30 
# define T_ANDOP               31
# define T_NOTOP               32
# define T_RELOP               33
# define T_ADDOP               34
# define T_MULOP               35
# define T_DIVOP               36
# define T_POWEROP             37


#define T_STRING               38

#define T_LPAREN               39
#define T_RPAREN               40
#define T_COMMA                41
#define T_ASSIGN               42
#define T_LBRACK               43
#define T_RBRACK               44
#define T_COLON                45

# define T_EOF                 0


char* TOKEN_NAME[] = {"T_EOF", "T_FUNCTION", "T_SUBROUTINE", "T_END", "T_COMMON", "T_INTEGER", "T_REAL", "T_COMPLEX", "T_LOGICAL", "T_CHARACTER", "T_DATA", "T_CONTINUE", "T_GOTO", "T_CALL", "T_READ", "T_WRITE", "T_IF", "T_THEN", "T_ELSE", "T_ENDIF", "T_DO", "T_ENDDO", "T_STOP", "T_RETURN", "T_LENGTH", "T_ID", "T_ICONST", "T_RCONST", "T_LCONST", "T_CCONST", "T_OROP", "T_ANDOP", "T_NOTOP", "T_RELOP", "T_ADDOP", "T_MULOP", "T_DIVOP", "T_POWEROP", "T_STRING", "T_LPAREN", "T_RPAREN", "T_COMMA", "T_ASSIGN", "T_LBRACK", "T_RBRACK", "T_COLON" };        
                       
/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    T_EOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_FUNCTION = 258,              /* "function"  */
    T_SUBROUTINE = 259,            /* "subroutine"  */
    T_END = 260,                   /* "end"  */
    T_COMMON = 261,                /* "common"  */
    T_INTEGER = 262,               /* "int"  */
    T_REAL = 263,                  /* "real"  */
    T_COMPLEX = 264,               /* "complex"  */
    T_LOGICAL = 265,               /* "logical"  */
    T_CHARACTER = 266,             /* "char"  */
    T_DATA = 267,                  /* "data"  */
    T_CONTINUE = 268,              /* "continue"  */
    T_GOTO = 269,                  /* "goto"  */
    T_CALL = 270,                  /* "call"  */
    T_READ = 271,                  /* "read"  */
    T_WRITE = 272,                 /* "write"  */
    T_IF = 273,                    /* "if"  */
    T_THEN = 274,                  /* "then"  */
    T_ELSE = 275,                  /* "else"  */
    T_ENDIF = 276,                 /* "endif"  */
    T_DO = 277,                    /* "do"  */
    T_ENDDO = 278,                 /* "enddo"  */
    T_STOP = 279,                  /* "stop"  */
    T_RETURN = 280,                /* "return"  */
    T_LENGTH = 281,                /* "length"  */
    T_ID = 282,                    /* "id"  */
    T_ICONST = 283,                /* "iconst"  */
    T_RCONST = 284,                /* "rconst"  */
    T_LCONST = 285,                /* "lconst"  */
    T_CCONST = 286,                /* "cconst"  */
    T_STRING = 287,                /* "string"  */
    T_OROP = 288,                  /* ".OR."  */
    T_ANDOP = 289,                 /* ".AND."  */
    T_NOTOP = 290,                 /* ".NOT."  */
    T_RELOP = 291,                 /* ".GT. or.GE. or .LT. or .LE. or .EQ. or .NE."  */
    T_ADDOP = 292,                 /* "+ or -"  */
    T_MULOP = 293,                 /* "*"  */
    T_DIVOP = 294,                 /* "/"  */
    T_POWEROP = 295,               /* "**"  */
    T_LPAREN = 296,                /* "("  */
    T_RPAREN = 297,                /* ")"  */
    T_COMMA = 298,                 /* ","  */
    T_ASSIGN = 299,                /* "="  */
    T_LBRACK = 300,                /* "["  */
    T_RBRACK = 301,                /* "]"  */
    T_COLON = 302                  /* ":"  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "syntax.y"

    int intval;
    float realval;
    char *booleanval;
    char charval;
    char *strval; 

#line 119 "syntax.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */

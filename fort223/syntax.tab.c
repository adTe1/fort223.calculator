/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax.y"
    
    #include <stdio.h>
    #include <stdlib.h>
    #include "extra/hashtbl.h"
     

    extern FILE *yyin; //sumperilamvanw to yyin popu exw dhlvmenv sto lexer.l
    extern int yylineno;
    extern int yylex();
    extern void yyerror(const char* err);

    HASHTBL *symbol_table;
    int scope = 0;

#line 86 "syntax.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_FUNCTION = 3,                 /* "function"  */
  YYSYMBOL_T_SUBROUTINE = 4,               /* "subroutine"  */
  YYSYMBOL_T_END = 5,                      /* "end"  */
  YYSYMBOL_T_COMMON = 6,                   /* "common"  */
  YYSYMBOL_T_INTEGER = 7,                  /* "int"  */
  YYSYMBOL_T_REAL = 8,                     /* "real"  */
  YYSYMBOL_T_COMPLEX = 9,                  /* "complex"  */
  YYSYMBOL_T_LOGICAL = 10,                 /* "logical"  */
  YYSYMBOL_T_CHARACTER = 11,               /* "char"  */
  YYSYMBOL_T_DATA = 12,                    /* "data"  */
  YYSYMBOL_T_CONTINUE = 13,                /* "continue"  */
  YYSYMBOL_T_GOTO = 14,                    /* "goto"  */
  YYSYMBOL_T_CALL = 15,                    /* "call"  */
  YYSYMBOL_T_READ = 16,                    /* "read"  */
  YYSYMBOL_T_WRITE = 17,                   /* "write"  */
  YYSYMBOL_T_IF = 18,                      /* "if"  */
  YYSYMBOL_T_THEN = 19,                    /* "then"  */
  YYSYMBOL_T_ELSE = 20,                    /* "else"  */
  YYSYMBOL_T_ENDIF = 21,                   /* "endif"  */
  YYSYMBOL_T_DO = 22,                      /* "do"  */
  YYSYMBOL_T_ENDDO = 23,                   /* "enddo"  */
  YYSYMBOL_T_STOP = 24,                    /* "stop"  */
  YYSYMBOL_T_RETURN = 25,                  /* "return"  */
  YYSYMBOL_T_LENGTH = 26,                  /* "length"  */
  YYSYMBOL_T_ID = 27,                      /* "id"  */
  YYSYMBOL_T_ICONST = 28,                  /* "iconst"  */
  YYSYMBOL_T_RCONST = 29,                  /* "rconst"  */
  YYSYMBOL_T_LCONST = 30,                  /* "lconst"  */
  YYSYMBOL_T_CCONST = 31,                  /* "cconst"  */
  YYSYMBOL_T_STRING = 32,                  /* "string"  */
  YYSYMBOL_T_OROP = 33,                    /* ".OR."  */
  YYSYMBOL_T_ANDOP = 34,                   /* ".AND."  */
  YYSYMBOL_T_NOTOP = 35,                   /* ".NOT."  */
  YYSYMBOL_T_RELOP = 36,                   /* ".GT. or.GE. or .LT. or .LE. or .EQ. or .NE."  */
  YYSYMBOL_T_ADDOP = 37,                   /* "+ or -"  */
  YYSYMBOL_T_MULOP = 38,                   /* "*"  */
  YYSYMBOL_T_DIVOP = 39,                   /* "/"  */
  YYSYMBOL_T_POWEROP = 40,                 /* "**"  */
  YYSYMBOL_T_LPAREN = 41,                  /* "("  */
  YYSYMBOL_T_RPAREN = 42,                  /* ")"  */
  YYSYMBOL_T_COMMA = 43,                   /* ","  */
  YYSYMBOL_T_ASSIGN = 44,                  /* "="  */
  YYSYMBOL_T_LBRACK = 45,                  /* "["  */
  YYSYMBOL_T_RBRACK = 46,                  /* "]"  */
  YYSYMBOL_T_COLON = 47,                   /* ":"  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_body = 50,                      /* body  */
  YYSYMBOL_declarations = 51,              /* declarations  */
  YYSYMBOL_type = 52,                      /* type  */
  YYSYMBOL_vars = 53,                      /* vars  */
  YYSYMBOL_undef_variable = 54,            /* undef_variable  */
  YYSYMBOL_dims = 55,                      /* dims  */
  YYSYMBOL_dim = 56,                       /* dim  */
  YYSYMBOL_cblock_list = 57,               /* cblock_list  */
  YYSYMBOL_cblock = 58,                    /* cblock  */
  YYSYMBOL_id_list = 59,                   /* id_list  */
  YYSYMBOL_vals = 60,                      /* vals  */
  YYSYMBOL_value_list = 61,                /* value_list  */
  YYSYMBOL_values = 62,                    /* values  */
  YYSYMBOL_value = 63,                     /* value  */
  YYSYMBOL_sign = 64,                      /* sign  */
  YYSYMBOL_constant = 65,                  /* constant  */
  YYSYMBOL_simple_constant = 66,           /* simple_constant  */
  YYSYMBOL_complex_constant = 67,          /* complex_constant  */
  YYSYMBOL_statements = 68,                /* statements  */
  YYSYMBOL_labeled_statement = 69,         /* labeled_statement  */
  YYSYMBOL_label = 70,                     /* label  */
  YYSYMBOL_statement = 71,                 /* statement  */
  YYSYMBOL_simple_statement = 72,          /* simple_statement  */
  YYSYMBOL_assignment = 73,                /* assignment  */
  YYSYMBOL_variable = 74,                  /* variable  */
  YYSYMBOL_expressions = 75,               /* expressions  */
  YYSYMBOL_expression = 76,                /* expression  */
  YYSYMBOL_goto_statement = 77,            /* goto_statement  */
  YYSYMBOL_labels = 78,                    /* labels  */
  YYSYMBOL_if_statement = 79,              /* if_statement  */
  YYSYMBOL_subroutine_call = 80,           /* subroutine_call  */
  YYSYMBOL_io_statement = 81,              /* io_statement  */
  YYSYMBOL_read_list = 82,                 /* read_list  */
  YYSYMBOL_read_item = 83,                 /* read_item  */
  YYSYMBOL_iter_space = 84,                /* iter_space  */
  YYSYMBOL_step = 85,                      /* step  */
  YYSYMBOL_write_list = 86,                /* write_list  */
  YYSYMBOL_write_item = 87,                /* write_item  */
  YYSYMBOL_compound_statement = 88,        /* compound_statement  */
  YYSYMBOL_branch_statement = 89,          /* branch_statement  */
  YYSYMBOL_90_1 = 90,                      /* $@1  */
  YYSYMBOL_tail = 91,                      /* tail  */
  YYSYMBOL_loop_statement = 92,            /* loop_statement  */
  YYSYMBOL_93_2 = 93,                      /* $@2  */
  YYSYMBOL_subprograms = 94,               /* subprograms  */
  YYSYMBOL_subprogram = 95,                /* subprogram  */
  YYSYMBOL_header = 96,                    /* header  */
  YYSYMBOL_formal_parameters = 97          /* formal_parameters  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   389

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  119
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  232

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   109,   109,   111,   113,   114,   115,   116,   118,   118,
     118,   118,   118,   120,   121,   123,   124,   126,   127,   129,
     130,   132,   133,   135,   137,   138,   140,   141,   143,   145,
     146,   148,   149,   151,   151,   153,   154,   156,   156,   156,
     156,   158,   160,   161,   163,   164,   166,   168,   169,   171,
     172,   173,   174,   175,   176,   177,   178,   180,   181,   183,
     184,   186,   187,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   204,   205,   207,
     208,   210,   211,   213,   215,   216,   218,   219,   221,   222,
     224,   226,   227,   229,   230,   232,   233,   234,   236,   237,
     239,   239,   241,   242,   244,   244,   246,   247,   249,   251,
     252,   253,   255,   256,   257,   258,   259,   260,   261,   262
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "\"function\"",
  "\"subroutine\"", "\"end\"", "\"common\"", "\"int\"", "\"real\"",
  "\"complex\"", "\"logical\"", "\"char\"", "\"data\"", "\"continue\"",
  "\"goto\"", "\"call\"", "\"read\"", "\"write\"", "\"if\"", "\"then\"",
  "\"else\"", "\"endif\"", "\"do\"", "\"enddo\"", "\"stop\"", "\"return\"",
  "\"length\"", "\"id\"", "\"iconst\"", "\"rconst\"", "\"lconst\"",
  "\"cconst\"", "\"string\"", "\".OR.\"", "\".AND.\"", "\".NOT.\"",
  "\".GT. or.GE. or .LT. or .LE. or .EQ. or .NE.\"", "\"+ or -\"", "\"*\"",
  "\"/\"", "\"**\"", "\"(\"", "\")\"", "\",\"", "\"=\"", "\"[\"", "\"]\"",
  "\":\"", "$accept", "program", "body", "declarations", "type", "vars",
  "undef_variable", "dims", "dim", "cblock_list", "cblock", "id_list",
  "vals", "value_list", "values", "value", "sign", "constant",
  "simple_constant", "complex_constant", "statements", "labeled_statement",
  "label", "statement", "simple_statement", "assignment", "variable",
  "expressions", "expression", "goto_statement", "labels", "if_statement",
  "subroutine_call", "io_statement", "read_list", "read_item",
  "iter_space", "step", "write_list", "write_item", "compound_statement",
  "branch_statement", "$@1", "tail", "loop_statement", "$@2",
  "subprograms", "subprogram", "header", "formal_parameters", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-146)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-118)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -146,    23,    39,   170,  -146,  -146,    21,  -146,  -146,  -146,
    -146,  -146,    50,  -146,    82,    58,   -12,   119,    64,    74,
    -146,  -146,    79,  -146,   106,   261,  -146,   309,  -146,  -146,
    -146,    93,  -146,  -146,  -146,  -146,  -146,  -146,  -146,   201,
     125,    21,  -146,   116,   146,   147,  -146,  -146,   -12,  -146,
     148,  -146,   118,  -146,  -146,  -146,  -146,  -146,   228,   228,
     119,   228,  -146,  -146,   134,   150,  -146,   228,   152,   228,
     163,   178,  -146,  -146,  -146,   188,   179,   219,  -146,  -146,
     185,  -146,   -11,  -146,   199,   186,   187,   -12,   228,   228,
     191,    12,   312,   189,    55,   228,   228,   228,   228,   228,
     228,   228,   119,   322,   228,    80,   134,   108,   106,  -146,
     134,   200,   215,   223,   217,  -146,  -146,   -29,  -146,    45,
     116,   218,    -7,  -146,   332,   312,  -146,   208,   228,   349,
     276,   162,    12,   191,   -10,  -146,  -146,   277,    78,  -146,
    -146,   228,  -146,  -146,    97,  -146,  -146,    30,   206,  -146,
    -146,   205,  -146,   -11,   221,  -146,  -146,  -146,  -146,  -146,
     115,    56,  -146,    63,    92,   210,  -146,   209,  -146,   228,
    -146,   134,  -146,   108,   106,     8,   220,    30,   233,  -146,
     214,  -146,   218,   228,   228,  -146,   228,  -146,   218,   304,
     241,  -146,   224,   225,     6,  -146,   229,  -146,   235,  -146,
     238,   239,   342,   141,   227,   228,  -146,  -146,    60,    30,
      30,    71,  -146,   237,  -146,  -146,   293,  -146,  -146,  -146,
     218,   134,  -146,  -146,  -146,   106,  -146,   236,   263,  -146,
    -146,  -146
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       7,     0,     0,     0,     1,   107,     0,     8,     9,    10,
      11,    12,     0,    54,     0,     0,     0,     0,     0,     0,
      56,    55,    60,    46,     0,     3,    43,     0,    45,    47,
      49,     0,    50,    51,    52,    53,    48,    98,    99,     2,
       0,     5,    22,     0,     6,     0,    77,    83,     0,    88,
      84,    87,     0,    37,    38,    39,    40,    97,     0,     0,
       0,     0,    73,    72,    95,    85,    94,     0,     0,     0,
      16,     4,    14,    42,    44,     0,     0,     0,   106,     7,
       0,    21,    34,    27,     0,     0,     0,     0,     0,     0,
      70,    71,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    62,     0,     0,    58,
      57,   111,     0,     0,     0,    32,    33,     0,    30,     0,
       0,     0,     0,    86,     0,     0,    74,     0,     0,    63,
      64,    65,    66,    67,    68,    69,    93,     0,     0,   104,
      59,     0,    20,    19,     0,    18,    13,     0,     0,   108,
      25,    23,    28,    34,     0,    31,    35,    36,    26,    80,
       0,    60,    76,    60,     0,     0,   100,     0,    82,     0,
       7,    61,    15,     0,     0,     0,     0,     0,     0,    29,
       0,    78,     0,     0,     0,    75,     0,     7,     0,    92,
       0,    17,   118,   119,     0,   110,     0,    24,    34,    79,
       0,     0,     0,     0,     0,     0,    90,   105,     0,     0,
       0,     0,   109,     0,    89,    96,     0,     7,   103,   101,
       0,    91,   113,   114,   115,   116,   112,     0,     0,    81,
      41,   102
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -146,  -146,   -74,  -146,     3,   -22,  -105,  -146,   114,  -146,
     256,  -146,  -146,   180,  -146,   145,   101,  -146,   184,  -146,
    -146,   294,   -13,   301,  -133,  -146,    -3,  -146,   -42,  -146,
    -146,  -146,  -146,  -146,   281,   -79,   -18,  -146,   270,   -91,
    -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -146,  -145
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     3,   175,   192,    72,   144,   145,    41,
      42,   151,    44,    83,   117,   118,   119,   155,    62,   157,
      25,    26,    27,    28,    29,    30,    63,   105,    64,    32,
     160,    33,    34,    35,    50,    51,   139,   206,    65,    66,
      36,    37,   187,   219,    38,   170,    39,    78,    79,   176
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      31,    46,    71,   146,   168,   113,    24,   210,   123,   193,
     152,   136,    47,    49,   153,    22,    90,    91,    92,    94,
     161,   115,    31,     4,    31,   103,   116,   106,    99,    48,
     101,   174,   196,   110,    48,    70,   136,     7,     8,     9,
      10,    11,    77,   123,     5,    49,   124,   125,  -117,   211,
      99,   100,   101,   129,   130,   131,   132,   133,   134,   135,
      40,   174,   138,   222,   223,   224,   226,     7,     8,     9,
      10,    11,   225,    53,    54,    55,    56,    43,     7,     8,
       9,    10,    11,   168,    49,    22,   164,    70,    95,    96,
     154,    97,    98,    99,   100,   101,   190,    69,    70,   171,
     183,    68,   128,   146,    69,    67,   146,   184,   159,    45,
      23,    95,    96,   203,    97,    98,    99,   100,   101,    49,
      69,   169,   140,   141,   167,    95,    96,   189,    97,    98,
      99,   100,   101,    70,    31,   142,   143,    75,   185,   172,
     173,   138,   138,   228,   202,    52,    22,    53,    54,    55,
      56,    57,    80,   194,    58,    82,    59,   181,   182,    88,
      60,   217,   218,   221,    61,   200,   201,    95,    96,   199,
      97,    98,    99,   100,   101,   204,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    84,
      85,    87,    19,   102,    20,    21,   104,    22,    23,    98,
      99,   100,   101,   167,   107,    76,   111,   229,     7,     8,
       9,    10,    11,    31,    52,    22,    53,    54,    55,    56,
     109,   108,   112,    58,   114,    59,   120,   121,   149,    89,
     122,   101,   127,    61,    52,   163,    53,    54,    55,    56,
      57,   147,   148,    58,   150,    59,    23,   177,   178,    60,
     180,   186,   188,    61,    52,    22,    53,    54,    55,    56,
     197,   198,   195,    58,   207,    59,   227,   208,   209,    89,
     220,   212,   116,    61,    13,    14,    15,    16,    17,    18,
     214,   215,   230,    19,   231,    20,    21,   191,    22,    23,
      13,    14,    15,    16,    17,   165,   166,    81,   179,   213,
     158,    20,    21,   156,    22,    23,    13,    14,    15,    16,
      17,   165,    97,    98,    99,   100,   101,    20,    21,    73,
      22,    23,    13,    14,    15,    16,    17,    18,    74,    86,
      93,    19,     0,    20,    21,     0,    22,    95,    96,     0,
      97,    98,    99,   100,   101,    95,    96,   205,    97,    98,
      99,   100,   101,     0,   126,    95,    96,     0,    97,    98,
      99,   100,   101,     0,   137,    95,    96,     0,    97,    98,
      99,   100,   101,     0,   162,    95,    96,     0,    97,    98,
      99,   100,   101,    96,   216,    97,    98,    99,   100,   101
};

static const yytype_int16 yycheck[] =
{
       3,    14,    24,   108,   137,    79,     3,     1,    87,     1,
      39,   102,    15,    16,    43,    27,    58,    59,    60,    61,
      27,    32,    25,     0,    27,    67,    37,    69,    38,    41,
      40,     1,   177,    75,    41,    27,   127,     7,     8,     9,
      10,    11,    39,   122,     5,    48,    88,    89,    42,    43,
      38,    39,    40,    95,    96,    97,    98,    99,   100,   101,
      39,     1,   104,   208,   209,   210,   211,     7,     8,     9,
      10,    11,     1,    28,    29,    30,    31,    27,     7,     8,
       9,    10,    11,   216,    87,    27,   128,    27,    33,    34,
      45,    36,    37,    38,    39,    40,   170,    41,    27,   141,
      44,    27,    47,   208,    41,    41,   211,    44,   121,    27,
      28,    33,    34,   187,    36,    37,    38,    39,    40,   122,
      41,    43,    42,    43,   137,    33,    34,   169,    36,    37,
      38,    39,    40,    27,   137,    27,    28,    44,    46,    42,
      43,   183,   184,   217,   186,    26,    27,    28,    29,    30,
      31,    32,    27,   175,    35,    39,    37,    42,    43,    41,
      41,    20,    21,   205,    45,   183,   184,    33,    34,   182,
      36,    37,    38,    39,    40,   188,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    43,
      43,    43,    22,    43,    24,    25,    44,    27,    28,    37,
      38,    39,    40,   216,    41,     4,    27,   220,     7,     8,
       9,    10,    11,   216,    26,    27,    28,    29,    30,    31,
      32,    43,     3,    35,    39,    37,    27,    41,     5,    41,
      43,    40,    43,    45,    26,    27,    28,    29,    30,    31,
      32,    41,    27,    35,    27,    37,    28,    41,    43,    41,
      29,    41,    43,    45,    26,    27,    28,    29,    30,    31,
      27,    47,    42,    35,    23,    37,    29,    43,    43,    41,
      43,    42,    37,    45,    13,    14,    15,    16,    17,    18,
      42,    42,    46,    22,    21,    24,    25,   173,    27,    28,
      13,    14,    15,    16,    17,    18,    19,    41,   153,   198,
     120,    24,    25,   119,    27,    28,    13,    14,    15,    16,
      17,    18,    36,    37,    38,    39,    40,    24,    25,    25,
      27,    28,    13,    14,    15,    16,    17,    18,    27,    48,
      60,    22,    -1,    24,    25,    -1,    27,    33,    34,    -1,
      36,    37,    38,    39,    40,    33,    34,    43,    36,    37,
      38,    39,    40,    -1,    42,    33,    34,    -1,    36,    37,
      38,    39,    40,    -1,    42,    33,    34,    -1,    36,    37,
      38,    39,    40,    -1,    42,    33,    34,    -1,    36,    37,
      38,    39,    40,    34,    42,    36,    37,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    49,    50,    51,     0,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    22,
      24,    25,    27,    28,    52,    68,    69,    70,    71,    72,
      73,    74,    77,    79,    80,    81,    88,    89,    92,    94,
      39,    57,    58,    27,    60,    27,    70,    74,    41,    74,
      82,    83,    26,    28,    29,    30,    31,    32,    35,    37,
      41,    45,    66,    74,    76,    86,    87,    41,    27,    41,
      27,    53,    54,    69,    71,    44,     4,    52,    95,    96,
      27,    58,    39,    61,    43,    43,    82,    43,    41,    41,
      76,    76,    76,    86,    76,    33,    34,    36,    37,    38,
      39,    40,    43,    76,    44,    75,    76,    41,    43,    32,
      76,    27,     3,    50,    39,    32,    37,    62,    63,    64,
      27,    41,    43,    83,    76,    76,    42,    43,    47,    76,
      76,    76,    76,    76,    76,    76,    87,    42,    76,    84,
      42,    43,    27,    28,    55,    56,    54,    41,    27,     5,
      27,    59,    39,    43,    45,    65,    66,    67,    61,    70,
      78,    27,    42,    27,    76,    18,    19,    70,    72,    43,
      93,    76,    42,    43,     1,    52,    97,    41,    43,    63,
      29,    42,    43,    44,    44,    46,    41,    90,    43,    76,
      50,    56,    53,     1,    53,    42,    97,    27,    47,    70,
      84,    84,    76,    50,    70,    43,    85,    23,    43,    43,
       1,    43,    42,    64,    42,    42,    42,    20,    21,    91,
      43,    76,    97,    97,    97,     1,    97,    29,    50,    70,
      46,    21
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    51,    51,    51,    51,    52,    52,
      52,    52,    52,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    58,    59,    59,    60,    60,    61,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    66,
      66,    67,    68,    68,    69,    69,    70,    71,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    73,    73,    74,
      74,    75,    75,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    77,    77,    78,
      78,    79,    79,    80,    81,    81,    82,    82,    83,    83,
      84,    85,    85,    86,    86,    87,    87,    87,    88,    88,
      90,    89,    91,    91,    93,    92,    94,    94,    95,    96,
      96,    96,    97,    97,    97,    97,    97,    97,    97,    97
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     3,     3,     3,     0,     1,     1,
       1,     1,     1,     3,     1,     4,     1,     3,     1,     1,
       1,     2,     1,     4,     3,     1,     4,     2,     3,     3,
       1,     2,     1,     1,     0,     1,     1,     1,     1,     1,
       1,     6,     2,     1,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     3,     4,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     1,     3,     5,     4,     2,     6,     3,
       1,     9,     5,     2,     2,     2,     3,     1,     1,     7,
       4,     2,     0,     3,     1,     1,     7,     1,     1,     1,
       0,     8,     3,     1,     0,     7,     2,     0,     3,     6,
       5,     2,     4,     4,     4,     4,     4,     2,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= T_EOF)
    {
      yychar = T_EOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 7: /* declarations: %empty  */
#line 116 "syntax.y"
                                                                                                    { }
#line 1634 "syntax.tab.c"
    break;

  case 15: /* undef_variable: "id" "(" dims ")"  */
#line 123 "syntax.y"
                                                                                                    { hashtbl_insert(symbol_table, (yyvsp[-3].strval) ,  yylineno, scope); }
#line 1640 "syntax.tab.c"
    break;

  case 16: /* undef_variable: "id"  */
#line 124 "syntax.y"
                                                                                                    { hashtbl_insert(symbol_table, (yyvsp[0].strval) ,  yylineno, scope); }
#line 1646 "syntax.tab.c"
    break;

  case 20: /* dim: "id"  */
#line 130 "syntax.y"
                                                                                                    { hashtbl_insert(symbol_table, (yyvsp[0].strval) ,  yylineno, scope); }
#line 1652 "syntax.tab.c"
    break;

  case 23: /* cblock: "/" "id" "/" id_list  */
#line 135 "syntax.y"
                                                                                                    { hashtbl_insert(symbol_table, (yyvsp[-2].strval) ,  yylineno, scope); }
#line 1658 "syntax.tab.c"
    break;

  case 24: /* id_list: id_list "," "id"  */
#line 137 "syntax.y"
                                                                                                    { hashtbl_insert(symbol_table, (yyvsp[0].strval) ,  yylineno, scope); }
#line 1664 "syntax.tab.c"
    break;

  case 25: /* id_list: "id"  */
#line 138 "syntax.y"
                                                                                                    { hashtbl_insert(symbol_table, (yyvsp[0].strval) ,  yylineno, scope); }
#line 1670 "syntax.tab.c"
    break;

  case 26: /* vals: vals "," "id" value_list  */
#line 140 "syntax.y"
                                                                                                    { hashtbl_insert(symbol_table, (yyvsp[-1].strval) ,  yylineno, scope); }
#line 1676 "syntax.tab.c"
    break;

  case 27: /* vals: "id" value_list  */
#line 141 "syntax.y"
                                                                                                    { hashtbl_insert(symbol_table, (yyvsp[-1].strval) ,  yylineno, scope); }
#line 1682 "syntax.tab.c"
    break;

  case 34: /* sign: %empty  */
#line 151 "syntax.y"
                                                                                                    { }
#line 1688 "syntax.tab.c"
    break;

  case 59: /* variable: "id" "(" expressions ")"  */
#line 183 "syntax.y"
                                                                                                { hashtbl_insert(symbol_table, (yyvsp[-3].strval) ,  yylineno, scope); }
#line 1694 "syntax.tab.c"
    break;

  case 60: /* variable: "id"  */
#line 184 "syntax.y"
                                                                                                { hashtbl_insert(symbol_table, (yyvsp[0].strval) ,  yylineno, scope); }
#line 1700 "syntax.tab.c"
    break;

  case 78: /* goto_statement: "goto" "id" "," "(" labels ")"  */
#line 205 "syntax.y"
                                                                                             { hashtbl_insert(symbol_table, (yyvsp[-4].strval) , yylineno, scope); }
#line 1706 "syntax.tab.c"
    break;

  case 89: /* read_item: "(" read_list "," "id" "=" iter_space ")"  */
#line 222 "syntax.y"
                                                                                            { hashtbl_insert(symbol_table, (yyvsp[-3].strval) , yylineno, scope); }
#line 1712 "syntax.tab.c"
    break;

  case 92: /* step: %empty  */
#line 227 "syntax.y"
                                                                                           { }
#line 1718 "syntax.tab.c"
    break;

  case 96: /* write_item: "(" write_list "," "id" "=" iter_space ")"  */
#line 233 "syntax.y"
                                                                                            { hashtbl_insert(symbol_table, (yyvsp[-3].strval) , yylineno, scope); }
#line 1724 "syntax.tab.c"
    break;

  case 100: /* $@1: %empty  */
#line 239 "syntax.y"
                                                                {scope++; }
#line 1730 "syntax.tab.c"
    break;

  case 102: /* tail: "else" body "endif"  */
#line 241 "syntax.y"
                                                                         { hashtbl_get(symbol_table, scope); scope--;}
#line 1736 "syntax.tab.c"
    break;

  case 103: /* tail: "endif"  */
#line 242 "syntax.y"
                                                                        { hashtbl_get(symbol_table, scope); scope--;}
#line 1742 "syntax.tab.c"
    break;

  case 104: /* $@2: %empty  */
#line 244 "syntax.y"
                                                  {scope++; }
#line 1748 "syntax.tab.c"
    break;

  case 105: /* loop_statement: "do" "id" "=" iter_space $@2 body "enddo"  */
#line 244 "syntax.y"
                                                                                                        { hashtbl_get(symbol_table, scope); scope--; hashtbl_insert(symbol_table, (yyvsp[-5].strval) , yylineno, scope);  }
#line 1754 "syntax.tab.c"
    break;

  case 107: /* subprograms: %empty  */
#line 247 "syntax.y"
                                                                                            { }
#line 1760 "syntax.tab.c"
    break;

  case 109: /* header: type "function" "id" "(" formal_parameters ")"  */
#line 251 "syntax.y"
                                                                                            { hashtbl_insert(symbol_table, (yyvsp[-3].strval) , yylineno, scope); }
#line 1766 "syntax.tab.c"
    break;

  case 110: /* header: "subroutine" "id" "(" formal_parameters ")"  */
#line 252 "syntax.y"
                                                                                            { hashtbl_insert(symbol_table, (yyvsp[-3].strval) , yylineno, scope); }
#line 1772 "syntax.tab.c"
    break;

  case 111: /* header: "subroutine" "id"  */
#line 253 "syntax.y"
                                                                                            { hashtbl_insert(symbol_table, (yyvsp[0].strval) , yylineno, scope); }
#line 1778 "syntax.tab.c"
    break;

  case 113: /* formal_parameters: error vars "," formal_parameters  */
#line 256 "syntax.y"
                                                                                   {yyerror("wrong use formal parameter "); yyerrok; }
#line 1784 "syntax.tab.c"
    break;

  case 114: /* formal_parameters: type error "," formal_parameters  */
#line 257 "syntax.y"
                                                                                   {yyerror("wrong use formal parameter "); yyerrok; }
#line 1790 "syntax.tab.c"
    break;

  case 115: /* formal_parameters: type vars error formal_parameters  */
#line 258 "syntax.y"
                                                                                   {yyerror("wrong use formal parameter "); yyerrok; }
#line 1796 "syntax.tab.c"
    break;

  case 116: /* formal_parameters: type vars "," error  */
#line 259 "syntax.y"
                                                                                   {yyerror("wrong use formal parameter "); yyerrok; }
#line 1802 "syntax.tab.c"
    break;

  case 118: /* formal_parameters: error vars  */
#line 261 "syntax.y"
                                                                                   {yyerror("wrong use formal parameter "); yyerrok; }
#line 1808 "syntax.tab.c"
    break;

  case 119: /* formal_parameters: type error  */
#line 262 "syntax.y"
                                                                                   {yyerror("wrong use formal parameter "); yyerrok; }
#line 1814 "syntax.tab.c"
    break;


#line 1818 "syntax.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= T_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == T_EOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 264 "syntax.y"


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


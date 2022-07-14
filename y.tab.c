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
#line 1 "1805108.y"

#include<stdio.h>
#include<string.h>
#include"SymbolTable.cpp"
#include<fstream>
#include<iostream>
#include<bits/stdc++.h>
#include"Parameter.h"

int lineCount = 1;
int errorCount = 0;

struct nodeVar{
    string name;
    string type;
    int arraySize;
}tempNodeVar;

struct nodeParam{
    string name;
    string type;
}tempNodeParam;


vector<nodeVar> variable_list;
vector<nodeParam> parameter_list;

SymbolTable symbolTable(30);

// FILE *errorFile, *logFile;
ofstream errorFile, logFile;

extern FILE *yyin;
// extern ifstream yyin;

int yyparse(void);
int yylex(void);

void yyerror(const char* str) {
}
    

#line 114 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    VOID = 258,                    /* VOID  */
    NEWLINE = 259,                 /* NEWLINE  */
    NUMBER = 260,                  /* NUMBER  */
    LESS = 261,                    /* LESS  */
    GREATER = 262,                 /* GREATER  */
    EQUAL = 263,                   /* EQUAL  */
    IF = 264,                      /* IF  */
    FOR = 265,                     /* FOR  */
    ELSE = 266,                    /* ELSE  */
    WHILE = 267,                   /* WHILE  */
    BREAK = 268,                   /* BREAK  */
    CONTINUE = 269,                /* CONTINUE  */
    CASE = 270,                    /* CASE  */
    DEFAULT = 271,                 /* DEFAULT  */
    SWITCH = 272,                  /* SWITCH  */
    DO = 273,                      /* DO  */
    RETURN = 274,                  /* RETURN  */
    INCOP = 275,                   /* INCOP  */
    DECOP = 276,                   /* DECOP  */
    ASSIGNOP = 277,                /* ASSIGNOP  */
    LOGICNOT = 278,                /* LOGICNOT  */
    NOT = 279,                     /* NOT  */
    LPAREN = 280,                  /* LPAREN  */
    RPAREN = 281,                  /* RPAREN  */
    LCURL = 282,                   /* LCURL  */
    RCURL = 283,                   /* RCURL  */
    LTHIRD = 284,                  /* LTHIRD  */
    RTHIRD = 285,                  /* RTHIRD  */
    COMMA = 286,                   /* COMMA  */
    SEMICOLON = 287,               /* SEMICOLON  */
    COLON = 288,                   /* COLON  */
    INT = 289,                     /* INT  */
    FLOAT = 290,                   /* FLOAT  */
    DOUBLE = 291,                  /* DOUBLE  */
    CHAR = 292,                    /* CHAR  */
    PLUS = 293,                    /* PLUS  */
    MINUS = 294,                   /* MINUS  */
    SLASH = 295,                   /* SLASH  */
    ASTERISK = 296,                /* ASTERISK  */
    ADDOP = 297,                   /* ADDOP  */
    MULOP = 298,                   /* MULOP  */
    RELOP = 299,                   /* RELOP  */
    BITOP = 300,                   /* BITOP  */
    LOGICOP = 301,                 /* LOGICOP  */
    ID = 302,                      /* ID  */
    CONST_CHAR = 303,              /* CONST_CHAR  */
    CONST_INT = 304,               /* CONST_INT  */
    CONST_FLOAT = 305,             /* CONST_FLOAT  */
    LOWER_THAN_ELSE = 306          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define VOID 258
#define NEWLINE 259
#define NUMBER 260
#define LESS 261
#define GREATER 262
#define EQUAL 263
#define IF 264
#define FOR 265
#define ELSE 266
#define WHILE 267
#define BREAK 268
#define CONTINUE 269
#define CASE 270
#define DEFAULT 271
#define SWITCH 272
#define DO 273
#define RETURN 274
#define INCOP 275
#define DECOP 276
#define ASSIGNOP 277
#define LOGICNOT 278
#define NOT 279
#define LPAREN 280
#define RPAREN 281
#define LCURL 282
#define RCURL 283
#define LTHIRD 284
#define RTHIRD 285
#define COMMA 286
#define SEMICOLON 287
#define COLON 288
#define INT 289
#define FLOAT 290
#define DOUBLE 291
#define CHAR 292
#define PLUS 293
#define MINUS 294
#define SLASH 295
#define ASTERISK 296
#define ADDOP 297
#define MULOP 298
#define RELOP 299
#define BITOP 300
#define LOGICOP 301
#define ID 302
#define CONST_CHAR 303
#define CONST_INT 304
#define CONST_FLOAT 305
#define LOWER_THAN_ELSE 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 45 "1805108.y"

    SymbolInfo *symbolInfo;

#line 273 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VOID = 3,                       /* VOID  */
  YYSYMBOL_NEWLINE = 4,                    /* NEWLINE  */
  YYSYMBOL_NUMBER = 5,                     /* NUMBER  */
  YYSYMBOL_LESS = 6,                       /* LESS  */
  YYSYMBOL_GREATER = 7,                    /* GREATER  */
  YYSYMBOL_EQUAL = 8,                      /* EQUAL  */
  YYSYMBOL_IF = 9,                         /* IF  */
  YYSYMBOL_FOR = 10,                       /* FOR  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_BREAK = 13,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 14,                  /* CONTINUE  */
  YYSYMBOL_CASE = 15,                      /* CASE  */
  YYSYMBOL_DEFAULT = 16,                   /* DEFAULT  */
  YYSYMBOL_SWITCH = 17,                    /* SWITCH  */
  YYSYMBOL_DO = 18,                        /* DO  */
  YYSYMBOL_RETURN = 19,                    /* RETURN  */
  YYSYMBOL_INCOP = 20,                     /* INCOP  */
  YYSYMBOL_DECOP = 21,                     /* DECOP  */
  YYSYMBOL_ASSIGNOP = 22,                  /* ASSIGNOP  */
  YYSYMBOL_LOGICNOT = 23,                  /* LOGICNOT  */
  YYSYMBOL_NOT = 24,                       /* NOT  */
  YYSYMBOL_LPAREN = 25,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 26,                    /* RPAREN  */
  YYSYMBOL_LCURL = 27,                     /* LCURL  */
  YYSYMBOL_RCURL = 28,                     /* RCURL  */
  YYSYMBOL_LTHIRD = 29,                    /* LTHIRD  */
  YYSYMBOL_RTHIRD = 30,                    /* RTHIRD  */
  YYSYMBOL_COMMA = 31,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 32,                 /* SEMICOLON  */
  YYSYMBOL_COLON = 33,                     /* COLON  */
  YYSYMBOL_INT = 34,                       /* INT  */
  YYSYMBOL_FLOAT = 35,                     /* FLOAT  */
  YYSYMBOL_DOUBLE = 36,                    /* DOUBLE  */
  YYSYMBOL_CHAR = 37,                      /* CHAR  */
  YYSYMBOL_PLUS = 38,                      /* PLUS  */
  YYSYMBOL_MINUS = 39,                     /* MINUS  */
  YYSYMBOL_SLASH = 40,                     /* SLASH  */
  YYSYMBOL_ASTERISK = 41,                  /* ASTERISK  */
  YYSYMBOL_ADDOP = 42,                     /* ADDOP  */
  YYSYMBOL_MULOP = 43,                     /* MULOP  */
  YYSYMBOL_RELOP = 44,                     /* RELOP  */
  YYSYMBOL_BITOP = 45,                     /* BITOP  */
  YYSYMBOL_LOGICOP = 46,                   /* LOGICOP  */
  YYSYMBOL_ID = 47,                        /* ID  */
  YYSYMBOL_CONST_CHAR = 48,                /* CONST_CHAR  */
  YYSYMBOL_CONST_INT = 49,                 /* CONST_INT  */
  YYSYMBOL_CONST_FLOAT = 50,               /* CONST_FLOAT  */
  YYSYMBOL_LOWER_THAN_ELSE = 51,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_start = 53,                     /* start  */
  YYSYMBOL_program = 54,                   /* program  */
  YYSYMBOL_unit = 55,                      /* unit  */
  YYSYMBOL_function_declaration = 56,      /* function_declaration  */
  YYSYMBOL_function_definition = 57,       /* function_definition  */
  YYSYMBOL_parameter_list = 58,            /* parameter_list  */
  YYSYMBOL_compound_statement = 59,        /* compound_statement  */
  YYSYMBOL_variable_declaration = 60,      /* variable_declaration  */
  YYSYMBOL_type_specifier = 61,            /* type_specifier  */
  YYSYMBOL_declaration_list = 62,          /* declaration_list  */
  YYSYMBOL_statement_list = 63,            /* statement_list  */
  YYSYMBOL_statement = 64,                 /* statement  */
  YYSYMBOL_expression_statement = 65,      /* expression_statement  */
  YYSYMBOL_variable = 66,                  /* variable  */
  YYSYMBOL_expression = 67,                /* expression  */
  YYSYMBOL_logic_expression = 68,          /* logic_expression  */
  YYSYMBOL_rel_expression = 69,            /* rel_expression  */
  YYSYMBOL_simple_expression = 70,         /* simple_expression  */
  YYSYMBOL_term = 71,                      /* term  */
  YYSYMBOL_unary_expression = 72,          /* unary_expression  */
  YYSYMBOL_factor = 73,                    /* factor  */
  YYSYMBOL_argument_list = 74,             /* argument_list  */
  YYSYMBOL_arguments = 75                  /* arguments  */
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
typedef yytype_int8 yy_state_t;

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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   173

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  114

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    86,    86,    98,   104,   114,   122,   129,   139,   179,
     209,   265,   288,   300,   310,   321,   341,   347,   355,   385,
     391,   397,   403,   416,   434,   451,   467,   487,   494,   503,
     511,   518,   525,   533,   540,   547,   554,   565,   570,   579,
     586,   594,   601,   609,   615,   624,   631,   638,   644,   663,
     669,   677,   684,   691,   701,   708,   715,   722,   729,   736,
     744,   757,   764,   772,   779
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VOID", "NEWLINE",
  "NUMBER", "LESS", "GREATER", "EQUAL", "IF", "FOR", "ELSE", "WHILE",
  "BREAK", "CONTINUE", "CASE", "DEFAULT", "SWITCH", "DO", "RETURN",
  "INCOP", "DECOP", "ASSIGNOP", "LOGICNOT", "NOT", "LPAREN", "RPAREN",
  "LCURL", "RCURL", "LTHIRD", "RTHIRD", "COMMA", "SEMICOLON", "COLON",
  "INT", "FLOAT", "DOUBLE", "CHAR", "PLUS", "MINUS", "SLASH", "ASTERISK",
  "ADDOP", "MULOP", "RELOP", "BITOP", "LOGICOP", "ID", "CONST_CHAR",
  "CONST_INT", "CONST_FLOAT", "LOWER_THAN_ELSE", "$accept", "start",
  "program", "unit", "function_declaration", "function_definition",
  "parameter_list", "compound_statement", "variable_declaration",
  "type_specifier", "declaration_list", "statement_list", "statement",
  "expression_statement", "variable", "expression", "logic_expression",
  "rel_expression", "simple_expression", "term", "unary_expression",
  "factor", "argument_list", "arguments", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-65)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      35,   -65,   -65,   -65,   -65,    36,    35,   -65,   -65,   -65,
     -65,   -34,   -65,   -65,    -2,     1,    13,     4,    -5,   -65,
     -12,    -7,     3,    25,    28,    49,   -65,   -65,    -6,    35,
     -65,   -65,    14,    47,    50,    57,   123,   123,   123,   -65,
     -65,   123,     0,   -65,   -65,   -65,   -65,    42,    83,   -65,
     -65,    58,    62,   -65,    44,    18,    54,   -65,   -65,   -65,
     -65,    53,    71,   123,   113,   123,    72,    67,   -65,    77,
     -65,   123,   123,    76,   -65,   -65,   -65,   -65,   123,   -65,
     123,   123,   123,   123,   -65,   -65,    80,   113,    86,   -65,
     -65,   -65,    87,    78,    84,   -65,   -65,    54,    74,   -65,
     117,   123,   117,   -65,   123,   -65,   110,    96,   -65,   -65,
     117,   117,   -65,   -65
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    22,    19,    20,    21,     0,     2,     4,     6,     7,
       5,     0,     1,     3,    25,     0,     0,     0,     0,    18,
       0,     0,    15,     0,    23,     0,     9,    11,     0,     0,
      14,    26,     0,     0,     0,     0,     0,     0,     0,    17,
      37,     0,    39,    57,    58,    31,    29,     0,     0,    27,
      30,    54,     0,    41,    43,    45,    47,    49,    53,     8,
      10,    13,     0,     0,     0,     0,     0,    54,    52,     0,
      51,    62,     0,    25,    16,    28,    59,    60,     0,    38,
       0,     0,     0,     0,    12,    24,     0,     0,     0,    36,
      56,    64,     0,    61,     0,    42,    44,    48,    46,    50,
       0,     0,     0,    55,     0,    40,    34,     0,    33,    63,
       0,     0,    35,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -65,   -65,   -65,   118,   -65,   -65,   -65,   -10,    11,     6,
     -65,   -65,   -46,   -56,   -37,   -35,   -64,    43,    46,    59,
     -32,   -65,   -65,   -65
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,     8,     9,    21,    45,    46,    47,
      15,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    92,    93
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      67,    66,    75,    69,    67,    68,    11,    91,    87,    70,
      27,    10,    11,    14,    95,    25,     1,    10,    60,    28,
      26,    25,    22,    16,    29,    71,    59,    17,    86,    72,
      88,   101,    18,    19,    67,    61,    12,    94,     1,    20,
     109,    67,    24,    67,    67,    67,    67,     2,     3,     4,
      30,    99,     1,    23,   106,    31,   108,    32,    33,    34,
      81,    35,    82,    62,   112,   113,   107,    67,    36,     2,
       3,     4,    63,    37,    38,    64,    25,    39,    76,    77,
      78,    40,    65,     2,     3,     4,     1,    76,    77,    73,
      80,    41,    33,    34,    79,    35,    42,    83,    43,    44,
      84,    85,    36,    90,    89,    17,   100,    37,    38,   104,
      25,    74,   102,   103,   105,    40,    81,     2,     3,     4,
       1,   110,   111,    96,    13,    41,    33,    34,    98,    35,
      42,     0,    43,    44,     0,     0,    36,    37,    38,     0,
      97,    37,    38,     0,    25,    40,     0,    37,    38,    40,
       0,     2,     3,     4,     0,    41,     0,     0,     0,    41,
      42,     0,    43,    44,    42,    41,    43,    44,     0,     0,
      42,     0,    43,    44
};

static const yytype_int8 yycheck[] =
{
      37,    36,    48,    38,    41,    37,     0,    71,    64,    41,
      20,     0,     6,    47,    78,    27,     3,     6,    28,    26,
      32,    27,    16,    25,    31,    25,    32,    29,    63,    29,
      65,    87,    31,    32,    71,    29,     0,    72,     3,    26,
     104,    78,    47,    80,    81,    82,    83,    34,    35,    36,
      47,    83,     3,    49,   100,    30,   102,    29,     9,    10,
      42,    12,    44,    49,   110,   111,   101,   104,    19,    34,
      35,    36,    25,    24,    25,    25,    27,    28,    20,    21,
      22,    32,    25,    34,    35,    36,     3,    20,    21,    47,
      46,    42,     9,    10,    32,    12,    47,    43,    49,    50,
      47,    30,    19,    26,    32,    29,    26,    24,    25,    31,
      27,    28,    26,    26,    30,    32,    42,    34,    35,    36,
       3,    11,    26,    80,     6,    42,     9,    10,    82,    12,
      47,    -1,    49,    50,    -1,    -1,    19,    24,    25,    -1,
      81,    24,    25,    -1,    27,    32,    -1,    24,    25,    32,
      -1,    34,    35,    36,    -1,    42,    -1,    -1,    -1,    42,
      47,    -1,    49,    50,    47,    42,    49,    50,    -1,    -1,
      47,    -1,    49,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    34,    35,    36,    53,    54,    55,    56,    57,
      60,    61,     0,    55,    47,    62,    25,    29,    31,    32,
      26,    58,    61,    49,    47,    27,    32,    59,    26,    31,
      47,    30,    29,     9,    10,    12,    19,    24,    25,    28,
      32,    42,    47,    49,    50,    59,    60,    61,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    32,
      59,    61,    49,    25,    25,    25,    67,    66,    72,    67,
      72,    25,    29,    47,    28,    64,    20,    21,    22,    32,
      46,    42,    44,    43,    47,    30,    67,    65,    67,    32,
      26,    68,    74,    75,    67,    68,    69,    71,    70,    72,
      26,    65,    26,    26,    31,    30,    64,    67,    64,    68,
      11,    26,    64,    64
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    55,    56,    56,
      57,    57,    58,    58,    58,    58,    59,    59,    60,    61,
      61,    61,    61,    62,    62,    62,    62,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    65,    66,
      66,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    72,    73,    73,    73,    73,    73,    73,
      73,    74,    74,    75,    75
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     5,
       6,     5,     4,     3,     2,     1,     3,     2,     3,     1,
       1,     1,     1,     3,     6,     1,     4,     1,     2,     1,
       1,     1,     7,     5,     5,     7,     3,     1,     2,     1,
       4,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     2,     2,     1,     1,     4,     3,     1,     1,     2,
       2,     1,     0,     3,     1
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

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
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
  case 2: /* start: program  */
#line 87 "1805108.y"
    {
     (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
     logFile << "line number" << lineCount << ": " ;

    logFile << "start: program" << endl;
    // symbolTable.printAllScopes();
    
    }
#line 1426 "y.tab.c"
    break;

  case 3: /* program: program unit  */
#line 99 "1805108.y"
            {
            (yyval.symbolInfo) = new SymbolInfo( (yyvsp[-1].symbolInfo)->getName() +"\n" +(yyvsp[0].symbolInfo)->getName(),"SYMBOL_PROGRAM");
            logFile << "line number" << lineCount << ": " ;
            logFile << "program: program unit \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;
            }
#line 1436 "y.tab.c"
    break;

  case 4: /* program: unit  */
#line 105 "1805108.y"
            {
            (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
            logFile << "line number" << lineCount << ": " ;
            logFile << "program:  unit \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;
            }
#line 1446 "y.tab.c"
    break;

  case 5: /* unit: variable_declaration  */
#line 115 "1805108.y"
        {
        (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
        logFile << "line number" << lineCount << ": " ;
        logFile << "unit: variable_declaration \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;
        // symbolTable.printAllScopesInFile(logFile);

        }
#line 1458 "y.tab.c"
    break;

  case 6: /* unit: function_declaration  */
#line 123 "1805108.y"
        {
        (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
        logFile << "line number" << lineCount << ": " ;
        logFile << "unit: function_declaration \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;

        }
#line 1469 "y.tab.c"
    break;

  case 7: /* unit: function_definition  */
#line 130 "1805108.y"
        {
        (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
        logFile << "line number" << lineCount << ": " ;
        logFile << "unit: function_definition \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;


        }
#line 1481 "y.tab.c"
    break;

  case 8: /* function_declaration: type_specifier ID LPAREN parameter_list RPAREN SEMICOLON  */
#line 140 "1805108.y"
                        {
                        
                      (yyval.symbolInfo) = new SymbolInfo((yyvsp[-5].symbolInfo)->getName()+" "+ (yyvsp[-4].symbolInfo)->getName()+"("+(yyvsp[-2].symbolInfo)->getName()+");", "function_declaration");
                        string functionName = (yyvsp[-4].symbolInfo)->getName();
                        string functionType = (yyvsp[-5].symbolInfo)->getName();
                        if(symbolTable.search(functionName) == NULL)
                        {
                            symbolTable.insert(functionName, functionType);
                            (yyval.symbolInfo)->setDefined(false);
                        }
                        else
                        {
                            errorCount++;
                        logFile << "line number" << lineCount << ": " ;
                            
                            logFile << "error: function "<<functionName<<" already declared\n\n";
                            errorFile << "error: function "<<functionName<<" already declared\n";
                        }
                        // symbolTable.printCurrentScope();
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON";
                        logFile << endl<<endl;
                        logFile << (yyval.symbolInfo)->getName();
                        logFile << endl << endl;

                        SymbolInfo *temp = symbolTable.search(functionName);

                        for(int i = 0; i < parameter_list.size(); i++)
                        {
                            string parameterName = parameter_list[i].name;
                            string parameterType = parameter_list[i].type;
                            temp->insertParameter(parameterName, parameterType);
                        }

                      
                       
                        parameter_list.clear();
                        
                        }
#line 1525 "y.tab.c"
    break;

  case 9: /* function_declaration: type_specifier ID LPAREN RPAREN SEMICOLON  */
#line 180 "1805108.y"
                    {
                        (yyval.symbolInfo) = new SymbolInfo((yyvsp[-4].symbolInfo)->getName()+" "+ (yyvsp[-3].symbolInfo)->getName()+"();", "SYMBOL_FUNCTION");
                        string functionName = (yyvsp[-3].symbolInfo)->getName();
                        string functionType = (yyvsp[-4].symbolInfo)->getName();
                        if(symbolTable.search(functionName) == NULL)
                        {
                            symbolTable.insert(functionName, functionType);
                            (yyval.symbolInfo)->setDefined(false);
                        }
                        else
                        {
                            errorCount++;
                        logFile << "line number" << lineCount << ": " ;
                            
                            logFile << "error: function "<<functionName<<" already declared\n\n";
                            errorFile << "error: function "<<functionName<<" already declared\n";
                        }
                        parameter_list.clear();
                        // symbolTable.printCurrentScope();
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON";
                        logFile << endl<<endl;
                        logFile << (yyval.symbolInfo)->getName();
                        logFile << endl << endl;

                        }
#line 1556 "y.tab.c"
    break;

  case 10: /* function_definition: type_specifier ID LPAREN parameter_list RPAREN compound_statement  */
#line 211 "1805108.y"
                        {
                        (yyval.symbolInfo) = new SymbolInfo((yyvsp[-5].symbolInfo)->getName()+" "+(yyvsp[-4].symbolInfo)->getName()+" ( " +(yyvsp[-2].symbolInfo)->getName()+" ) "+(yyvsp[0].symbolInfo)->getName() + "\n"  , "SYMBOL_FUNCTION");
                        string functionName = (yyvsp[-4].symbolInfo)->getName();
                        string functionType = (yyvsp[-5].symbolInfo)->getName();
                        SymbolInfo* function = symbolTable.search(functionName);
                        if(symbolTable.search(functionName) == NULL)
                        {
                            symbolTable.insert(functionName, functionType);
                            (yyval.symbolInfo)->setDefined(true);
                        }
                        else
                        {
                            if(function->getDefined() == false)
                            {
                                symbolTable.insert(functionName, functionType);
                                (yyval.symbolInfo)->setDefined(true);
                            }
                            else
                            {
                                errorCount++;
                                logFile << "line number" << lineCount << ": " ;
                                logFile << "error: function "<<functionName<<" already defined\n\n";
                                errorFile << "error: function "<<functionName<<" already defined\n";
                            }
                        }

                        SymbolInfo *temp = symbolTable.search(functionName);

                        for(int i = 0; i < temp->getParamSize(); i++ ){
                            string declaredParameterName = temp->getParameterName(i);
                            string declaredParameterType = temp->getParameterType(i);

                            
                       
                            string definedParameterName = parameter_list[i].name;
                            string definedParameterType = parameter_list[i].type;
                            if(declaredParameterType != definedParameterType ){
                                errorCount++;
                                logFile << "line number" << lineCount << ": " ;
                                logFile << "error: parameter "<<definedParameterName<<" has wrong type as declared\n\n";
                                errorFile << "error: parameter "<<definedParameterName<<" has wrong type as declared\n";
                            }else{
                            symbolTable.insert(definedParameterName, definedParameterType);
                            }
                        }
                        parameter_list.clear();
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement";
                        logFile <<(yyval.symbolInfo)->getName()<< endl<<endl;
                        


                        }
#line 1614 "y.tab.c"
    break;

  case 11: /* function_definition: type_specifier ID LPAREN RPAREN compound_statement  */
#line 266 "1805108.y"
                    {
                        string functionName = (yyvsp[-3].symbolInfo)->getName();
                        string functionType = (yyvsp[-4].symbolInfo)->getName();
                        if(symbolTable.search(functionName) == NULL)
                        {

                            symbolTable.insert(functionName, functionType);

                        }
                        else
                        {

                        }
                        (yyval.symbolInfo) = new SymbolInfo((yyvsp[-4].symbolInfo)->getName()+" "+(yyvsp[-3].symbolInfo)->getName()+" ( ) "+(yyvsp[0].symbolInfo)->getName() + "\n"  , "SYMBOL_FUNCTION");
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "func_definition : type_specifier ID LPAREN RPAREN compound_statement"<<endl<<endl;
                        logFile <<(yyval.symbolInfo)->getName()<< endl<<endl;
                        
                    }
#line 1638 "y.tab.c"
    break;

  case 12: /* parameter_list: parameter_list COMMA type_specifier ID  */
#line 290 "1805108.y"
                    {
                    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-3].symbolInfo)->getName() + "," + (yyvsp[-1].symbolInfo)->getName() + " " + (yyvsp[0].symbolInfo)->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : parameter_list COMMA type_specifier ID"<<endl<<endl ;
                    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
                    tempNodeParam.name = (yyvsp[0].symbolInfo)->getName();
                    tempNodeParam.type = (yyvsp[-1].symbolInfo)->getName();
                    parameter_list.push_back(tempNodeParam);
                    
                    }
#line 1653 "y.tab.c"
    break;

  case 13: /* parameter_list: parameter_list COMMA type_specifier  */
#line 301 "1805108.y"
                    {
                    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName() + "," + (yyvsp[0].symbolInfo)->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : parameter_list COMMA type_specifier"<<endl<<endl ;
                    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
                    tempNodeParam.name = "";
                    tempNodeParam.type = (yyvsp[0].symbolInfo)->getName();

                    }
#line 1667 "y.tab.c"
    break;

  case 14: /* parameter_list: type_specifier ID  */
#line 311 "1805108.y"
                    {
                    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-1].symbolInfo)->getName() + " " + (yyvsp[0].symbolInfo)->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : type_specifier ID"<<endl<<endl ;
                    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
                    tempNodeParam.name = (yyvsp[0].symbolInfo)->getName();
                    tempNodeParam.type = (yyvsp[-1].symbolInfo)->getName();
                    parameter_list.push_back(tempNodeParam);
                    
                    }
#line 1682 "y.tab.c"
    break;

  case 15: /* parameter_list: type_specifier  */
#line 322 "1805108.y"
                    {
                    (yyval.symbolInfo) = new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "SYMBOL_PARAMETER");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "parameter_list : type_specifier"<<endl<<endl ;
                    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;

                    tempNodeParam.name = "";
                    tempNodeParam.type = (yyvsp[0].symbolInfo)->getType();
                    parameter_list.push_back(tempNodeParam);
                    
                    }
#line 1698 "y.tab.c"
    break;

  case 16: /* compound_statement: LCURL statement_list RCURL  */
#line 341 "1805108.y"
                                               {
    (yyval.symbolInfo) = new SymbolInfo("{\n"+(yyvsp[-1].symbolInfo)->getName()+"\n}", "SYMBOL_COMPOUND_STATEMENT");
    logFile << "line number" << lineCount << ": " ;
    logFile << "compound_statement : LCURL statement_list RCURL"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 1709 "y.tab.c"
    break;

  case 17: /* compound_statement: LCURL RCURL  */
#line 347 "1805108.y"
              {
    (yyval.symbolInfo) = new SymbolInfo("{\n}", "SYMBOL_COMPOUND_STATEMENT");
    logFile << "line number" << lineCount << ": " ;
    logFile << "compound_statement : LCURL RCURL"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 1720 "y.tab.c"
    break;

  case 18: /* variable_declaration: type_specifier declaration_list SEMICOLON  */
#line 356 "1805108.y"
                        {

                            string variable_name = (yyvsp[-1].symbolInfo)->getName();
                            string variable_type = (yyvsp[-2].symbolInfo)->getName();
                            if(variable_type == "void"){
                                errorCount++;
                                errorFile << "line number" << lineCount << ": " ;
                                errorFile << "variable_declaration: void type is not allowed" << endl;
                                logFile << "line number" << lineCount << ": " ;
                                logFile << "variable_declaration: void type is not allowed" << endl;
                            }
                            else{
                                for(int i = 0;i < variable_list.size();i++){
                                    symbolTable.insert(variable_list[i].name, variable_list[i].type);
                                }
                            }

                            variable_list.clear();

                       
                        
                        (yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName() + " " +(yyvsp[-1].symbolInfo)->getName()+";", "SYMBOL_VARIABLE");
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "variable_declaration: type_specifier declaration_list SEMICOLON \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;

                        }
#line 1751 "y.tab.c"
    break;

  case 19: /* type_specifier: INT  */
#line 386 "1805108.y"
                {
                (yyval.symbolInfo) = new SymbolInfo("int", "INT");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : INT"<<endl<<endl ;
                }
#line 1761 "y.tab.c"
    break;

  case 20: /* type_specifier: FLOAT  */
#line 392 "1805108.y"
                {
                (yyval.symbolInfo) = new SymbolInfo("float", "FLOAT");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : FLOAT"<<endl<<endl ;
                }
#line 1771 "y.tab.c"
    break;

  case 21: /* type_specifier: DOUBLE  */
#line 398 "1805108.y"
                {
                (yyval.symbolInfo) = new SymbolInfo("double", "DOUBLE");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : DOUBLE"<<endl<<endl ;
                }
#line 1781 "y.tab.c"
    break;

  case 22: /* type_specifier: VOID  */
#line 404 "1805108.y"
                {
                (yyval.symbolInfo) = new SymbolInfo("void", "VOID");
                logFile << "line number" << lineCount << ": " ;
                logFile << "type_specifier : VOID"<<endl<<endl ;
                }
#line 1791 "y.tab.c"
    break;

  case 23: /* declaration_list: declaration_list COMMA ID  */
#line 418 "1805108.y"
            {
(yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName() + "," +(yyvsp[0].symbolInfo)->getName(), "SYMBOL_VARIABLE");
   tempNodeVar.name = (yyvsp[0].symbolInfo)->getName();
    // tempNodeVar.type = $1->getName();
    tempNodeVar.arraySize = -1;
    variable_list.push_back(tempNodeVar);
    if(symbolTable.search((yyvsp[0].symbolInfo)->getName()) != NULL)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << (yyvsp[0].symbolInfo)->getName() << " already declared" << endl;
        errorCount++;
    }
    
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: declaration_list COMMA ID \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;
            }
#line 1812 "y.tab.c"
    break;

  case 24: /* declaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD  */
#line 435 "1805108.y"
{
(yyval.symbolInfo) = new SymbolInfo((yyvsp[-5].symbolInfo)->getName() + "," +(yyvsp[-3].symbolInfo)->getName()+"["+(yyvsp[-1].symbolInfo)->getName()+"]", "SYMBOL_VARIABLE");
    tempNodeVar.name = (yyvsp[-3].symbolInfo)->getName();
    // tempNodeVar.type = "array";

    tempNodeVar.arraySize = stoi((yyvsp[-1].symbolInfo)->getName());
    variable_list.push_back(tempNodeVar);
    if(symbolTable.search((yyvsp[-3].symbolInfo)->getName()) != NULL)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << (yyvsp[-3].symbolInfo)->getName() << " already declared" << endl;
        errorCount++;
    }
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: declaration_list COMMA ID LTHIRD CONST INT RTHIRD \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 1833 "y.tab.c"
    break;

  case 25: /* declaration_list: ID  */
#line 452 "1805108.y"
{
(yyval.symbolInfo) = new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "SYMBOL_VARIABLE");
    tempNodeVar.name = (yyvsp[0].symbolInfo)->getName();
    tempNodeVar.type = "SYMBOL_VARIABLE";
    tempNodeVar.arraySize = -1;
        variable_list.push_back(tempNodeVar);
    if(symbolTable.search((yyvsp[0].symbolInfo)->getName()) != NULL)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << (yyvsp[0].symbolInfo)->getName() << " already declared" << endl;
        errorCount++;
    }
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: ID \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 1853 "y.tab.c"
    break;

  case 26: /* declaration_list: ID LTHIRD CONST_INT RTHIRD  */
#line 467 "1805108.y"
                            {
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-3].symbolInfo)->getName() + " [" + (yyvsp[-1].symbolInfo)->getName()+"]", "SYMBOL_VARIABLE");
    tempNodeVar.name = (yyvsp[-3].symbolInfo)->getName();
    tempNodeVar.type = "array";
    tempNodeVar.arraySize = stoi((yyvsp[-1].symbolInfo)->getName());

    variable_list.push_back(tempNodeVar);
    if(symbolTable.search((yyvsp[-3].symbolInfo)->getName()) != NULL)
    {
        errorFile << "line number" << lineCount << ": " ;
        errorFile << "error: variable " << (yyvsp[-3].symbolInfo)->getName() << " already declared" << endl;
        errorCount++;
    }
    
    logFile << "line number" << lineCount << ": " ;
    logFile << "declaration_list: ID LTHIRD CONST INT RTHIRD \n\n" << (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 1875 "y.tab.c"
    break;

  case 27: /* statement_list: statement  */
#line 488 "1805108.y"
                    {
                    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "statement_list : statement"<<endl<<endl ;
                    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
                    }
#line 1886 "y.tab.c"
    break;

  case 28: /* statement_list: statement_list statement  */
#line 495 "1805108.y"
                    {
                    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-1].symbolInfo)->getName() + "\n" + (yyvsp[0].symbolInfo)->getName(), "SYMBOL_STATEMENT_LIST");
                    logFile << "line number" << lineCount << ": " ;
                    logFile << "statement_list : statement_list statement"<<endl<<endl ;
                    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
                    }
#line 1897 "y.tab.c"
    break;

  case 29: /* statement: variable_declaration  */
#line 504 "1805108.y"
            {
            (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : variable_declaration"<<endl<<endl ;
            logFile<< (yyval.symbolInfo)->getName() << endl<<endl;

            }
#line 1909 "y.tab.c"
    break;

  case 30: /* statement: expression_statement  */
#line 512 "1805108.y"
            {
            (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : expression_statement"<<endl<<endl ;
            logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
            }
#line 1920 "y.tab.c"
    break;

  case 31: /* statement: compound_statement  */
#line 519 "1805108.y"
            {
            (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : compound_statement"<<endl<<endl ;
            logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
            }
#line 1931 "y.tab.c"
    break;

  case 32: /* statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 527 "1805108.y"
    {
    (yyval.symbolInfo) = new SymbolInfo("for"+(yyvsp[-4].symbolInfo)->getName()+(yyvsp[-3].symbolInfo)->getName()+(yyvsp[-2].symbolInfo)->getName(), "SYMBOL_FOR_STATEMENT");
    logFile << "line number" << lineCount << ": " ;
    logFile << "statement : FOR LPAREN expression statement expression statement expression RPAREN statement"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
    }
#line 1942 "y.tab.c"
    break;

  case 33: /* statement: WHILE LPAREN expression RPAREN statement  */
#line 534 "1805108.y"
            {
            (yyval.symbolInfo) = new SymbolInfo("while("+(yyvsp[-2].symbolInfo)->getName()+")"+(yyvsp[0].symbolInfo)->getName(), "SYMBOL_WHILE_STATEMENT");
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : WHILE LPAREN expression RPAREN statement"<<endl<<endl ;
            logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
            }
#line 1953 "y.tab.c"
    break;

  case 34: /* statement: IF LPAREN expression RPAREN statement  */
#line 541 "1805108.y"
            {
            (yyval.symbolInfo) = new SymbolInfo("if("+(yyvsp[-2].symbolInfo)->getName()+")"+(yyvsp[0].symbolInfo)->getName(), "SYMBOL_IF_STATEMENT");
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : IF LPAREN expression RPAREN statement"<<endl<<endl ;
            logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
            }
#line 1964 "y.tab.c"
    break;

  case 35: /* statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 548 "1805108.y"
            {
            (yyval.symbolInfo) = new SymbolInfo("if("+(yyvsp[-4].symbolInfo)->getName()+")"+(yyvsp[-2].symbolInfo)->getName()+"else"+(yyvsp[0].symbolInfo)->getName(), "SYMBOL_IF_STATEMENT");
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : IF LPAREN expression RPAREN statement ELSE statement"<<endl<<endl ;
            logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
            }
#line 1975 "y.tab.c"
    break;

  case 36: /* statement: RETURN expression SEMICOLON  */
#line 555 "1805108.y"
            {
            (yyval.symbolInfo) = new SymbolInfo ("return"+(yyvsp[-1].symbolInfo)->getName()+";", "SYMBOL_RETURN_STATEMENT");
            logFile << "line number" << lineCount << ": " ;
            logFile << "statement : RETURN expression"<<endl<<endl ;
            logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
            }
#line 1986 "y.tab.c"
    break;

  case 37: /* expression_statement: SEMICOLON  */
#line 566 "1805108.y"
                        {
                        (yyval.symbolInfo) = new SymbolInfo(";", "SYMBOL_EXPRESSION_STATEMENT");
                        
                        }
#line 1995 "y.tab.c"
    break;

  case 38: /* expression_statement: expression SEMICOLON  */
#line 571 "1805108.y"
                        {
                        (yyval.symbolInfo) = new SymbolInfo((yyvsp[-1].symbolInfo)->getName()+";", "SYMBOL_EXPRESSION_STATEMENT");
                        logFile << "line number" << lineCount << ": " ;
                        logFile << "expression_statement : expression SEMICOLON"<<endl<<endl ;
                        logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
                        }
#line 2006 "y.tab.c"
    break;

  case 39: /* variable: ID  */
#line 579 "1805108.y"
             {
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "SYMBOL_VARIABLE");
    logFile << "line number" << lineCount << ": " ;
    logFile << "variable : ID"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;

}
#line 2018 "y.tab.c"
    break;

  case 40: /* variable: ID LTHIRD expression RTHIRD  */
#line 586 "1805108.y"
                             {
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-3].symbolInfo)->getName()+"["+(yyvsp[-1].symbolInfo)->getName()+"]", "SYMBOL_VARIABLE");
    logFile << "line number" << lineCount << ": " ;
    logFile << "variable : ID LTHIRD expression RTHIRD"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2029 "y.tab.c"
    break;

  case 41: /* expression: logic_expression  */
#line 594 "1805108.y"
                             {
    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : logic expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2040 "y.tab.c"
    break;

  case 42: /* expression: variable ASSIGNOP logic_expression  */
#line 601 "1805108.y"
                                    {
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+"="+(yyvsp[0].symbolInfo)->getName(), "SYMBOL_ASSIGNMENT_EXPRESSION");
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : variable ASSIGNOP logic expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2051 "y.tab.c"
    break;

  case 43: /* logic_expression: rel_expression  */
#line 609 "1805108.y"
                                  {
    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
    logFile << "line number" << lineCount << ": " ;
    logFile << "logic_expression : rel_expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2062 "y.tab.c"
    break;

  case 44: /* logic_expression: rel_expression LOGICOP rel_expression  */
#line 615 "1805108.y"
                                        {
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].symbolInfo)->getName(), "SYMBOL_LOGIC_EXPRESSION");
    logFile << "line number" << lineCount << ": " ;
    logFile << "logic_expression : logic_expression AND rel_expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2073 "y.tab.c"
    break;

  case 45: /* rel_expression: simple_expression  */
#line 625 "1805108.y"
{
    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : simple expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2084 "y.tab.c"
    break;

  case 46: /* rel_expression: simple_expression RELOP simple_expression  */
#line 631 "1805108.y"
                                           {
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].symbolInfo)->getName(), "SYMBOL_REL_EXPRESSION");
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : simple_expression RELOP simple_expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2095 "y.tab.c"
    break;

  case 47: /* simple_expression: term  */
#line 638 "1805108.y"
                        {
    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
    logFile << "line number" << lineCount << ": " ;
    logFile << "simple_expression : term"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2106 "y.tab.c"
    break;

  case 48: /* simple_expression: simple_expression ADDOP term  */
#line 645 "1805108.y"
{
    //problem in getting the plus and minus
    string type;
    if((yyvsp[-2].symbolInfo)->getType() == "INT" && (yyvsp[0].symbolInfo)->getType() == "INT")
    {
        type = "int";
    }
    else
    {
        type = "float";
    }
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].symbolInfo)->getName(), type);
    logFile << "line number" << lineCount << ": " ;
    logFile << "simple_expression : simple_expression ADDOP term"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2127 "y.tab.c"
    break;

  case 49: /* term: unary_expression  */
#line 663 "1805108.y"
                        {
    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
    logFile << "line number" << lineCount << ": " ;
    logFile << "term : unary_expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2138 "y.tab.c"
    break;

  case 50: /* term: term MULOP unary_expression  */
#line 669 "1805108.y"
                              {
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+(yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].symbolInfo)->getName(), "SYMBOL_MUL_EXPRESSION");
    logFile << "line number" << lineCount << ": " ;
    logFile << "term : term MULOP unary_expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2149 "y.tab.c"
    break;

  case 51: /* unary_expression: ADDOP unary_expression  */
#line 678 "1805108.y"
{
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-1].symbolInfo)->getName()+(yyvsp[0].symbolInfo)->getName(), "SYMBOL_UNARY_EXPRESSION");
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : ADDOP unary expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2160 "y.tab.c"
    break;

  case 52: /* unary_expression: NOT unary_expression  */
#line 685 "1805108.y"
{
    (yyval.symbolInfo) = new SymbolInfo(" !"+(yyvsp[0].symbolInfo)->getName(), "SYMBOL_UNARY_EXPRESSION");
    logFile << "line number" << lineCount << ": " ;
    logFile << "expression : NOT unary_expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2171 "y.tab.c"
    break;

  case 53: /* unary_expression: factor  */
#line 692 "1805108.y"
{
    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
    logFile << "line number" << lineCount << ": " ;
    logFile << "unary_expression : factor"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2182 "y.tab.c"
    break;

  case 54: /* factor: variable  */
#line 702 "1805108.y"
{
    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : variable"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2193 "y.tab.c"
    break;

  case 55: /* factor: ID LPAREN argument_list RPAREN  */
#line 709 "1805108.y"
{
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-3].symbolInfo)->getName()+" ( "+(yyvsp[-1].symbolInfo)->getName()+" )", "SYMBOL_FUNCTION_CALL");
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : ID LPAREN argument_list RPAREN"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2204 "y.tab.c"
    break;

  case 56: /* factor: LPAREN expression RPAREN  */
#line 716 "1805108.y"
{
    (yyval.symbolInfo) = new SymbolInfo(" ( "+(yyvsp[-1].symbolInfo)->getName()+" ) ", "SYMBOL_EXPRESSION");
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : LPAREN expression RPAREN"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2215 "y.tab.c"
    break;

  case 57: /* factor: CONST_INT  */
#line 723 "1805108.y"
{
    (yyval.symbolInfo) = yylval.symbolInfo;
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : CONST_INT"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2226 "y.tab.c"
    break;

  case 58: /* factor: CONST_FLOAT  */
#line 729 "1805108.y"
             {
    (yyval.symbolInfo) = yylval.symbolInfo;
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : CONST_FLOAT"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2237 "y.tab.c"
    break;

  case 59: /* factor: variable INCOP  */
#line 737 "1805108.y"
{
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-1].symbolInfo)->getName()+"++", "SYMBOL_INC_EXPRESSION");
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : variable INCOP"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2248 "y.tab.c"
    break;

  case 60: /* factor: variable DECOP  */
#line 745 "1805108.y"
{
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-1].symbolInfo)->getName()+"--", "SYMBOL_DEC_EXPRESSION");
    logFile << "line number" << lineCount << ": " ;
    logFile << "factor : variable DECOP"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2259 "y.tab.c"
    break;

  case 61: /* argument_list: arguments  */
#line 757 "1805108.y"
                         {
    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list : arguments"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2270 "y.tab.c"
    break;

  case 62: /* argument_list: %empty  */
#line 764 "1805108.y"
{
    (yyval.symbolInfo) = new SymbolInfo("", "SYMBOL_ARGUMENT_LIST");
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list :"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2281 "y.tab.c"
    break;

  case 63: /* arguments: arguments COMMA logic_expression  */
#line 773 "1805108.y"
{
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[-2].symbolInfo)->getName()+(yyvsp[0].symbolInfo)->getName(), "SYMBOL_ARGUMENTS");
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list : arguments COMMA logic_expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2292 "y.tab.c"
    break;

  case 64: /* arguments: logic_expression  */
#line 780 "1805108.y"
{
    (yyval.symbolInfo) = (yyvsp[0].symbolInfo);
    (yyval.symbolInfo) = new SymbolInfo((yyvsp[0].symbolInfo)->getName(), "SYMBOL_ARGUMENTS");
    logFile << "line number" << lineCount << ": " ;
    logFile << "argument_list : logic_expression"<<endl<<endl ;
    logFile<< (yyval.symbolInfo)->getName() << endl<<endl;
}
#line 2304 "y.tab.c"
    break;


#line 2308 "y.tab.c"

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
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
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

  return yyresult;
}

#line 798 "1805108.y"


int main(int argc, char *argv[]) {
    	if(argc!=2){
		return 0;
	}
	

    FILE *fin = fopen(argv[1], "r");
	if(fin==NULL){
		return 0;
	}
	
    errorFile.open("1805108_error.txt");
    if(!errorFile){
        return 0;
    }

    logFile.open("1805108_log.txt");
    if(!logFile){
        return 0;
    }

    

    // symbolTable.printAllScopesInFile(logFile);


	yyin = fin;
    yyparse();
    symbolTable.printAllScopesInFile(logFile);
    logFile << "total no. of errors: " << errorCount << endl;
    logFile << "total no. of lines" << lineCount << endl;
   
    logFile.close();
    errorFile.close();
    
    return 0;
}

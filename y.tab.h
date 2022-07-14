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

#line 173 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

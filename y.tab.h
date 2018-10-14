/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ADD = 258,
    SUB = 259,
    MUL = 260,
    DIV = 261,
    AND = 262,
    OR = 263,
    MOD = 264,
    EQ = 265,
    NE = 266,
    GT = 267,
    GE = 268,
    LT = 269,
    LE = 270,
    LOGICAL_AND = 271,
    LOGICAL_OR = 272,
    NOT = 273,
    SN0 = 274,
    SR = 275,
    EQU = 276,
    LP = 277,
    RP = 278,
    SN1 = 279,
    LC = 280,
    RC = 281,
    VAR = 282,
    INTEGER = 283,
    FLOAT = 284,
    STRING_TYPE = 285,
    BYTE = 286,
    IF = 287,
    BOOLEAN = 288,
    ELSE = 289,
    ELIF = 290,
    DO = 291,
    WHILE = 292,
    GOTO = 293,
    BREAK = 294,
    CONTINUE = 295,
    RETURN = 296,
    FOR = 297,
    FUNCTION = 298,
    IDENTIFIER = 299,
    REAL_CONSTANT = 300,
    INT_CONSTANT = 301,
    STRING_CONSTANT = 302,
    BOOLEAN_CONSTANT = 303
  };
#endif
/* Tokens.  */
#define ADD 258
#define SUB 259
#define MUL 260
#define DIV 261
#define AND 262
#define OR 263
#define MOD 264
#define EQ 265
#define NE 266
#define GT 267
#define GE 268
#define LT 269
#define LE 270
#define LOGICAL_AND 271
#define LOGICAL_OR 272
#define NOT 273
#define SN0 274
#define SR 275
#define EQU 276
#define LP 277
#define RP 278
#define SN1 279
#define LC 280
#define RC 281
#define VAR 282
#define INTEGER 283
#define FLOAT 284
#define STRING_TYPE 285
#define BYTE 286
#define IF 287
#define BOOLEAN 288
#define ELSE 289
#define ELIF 290
#define DO 291
#define WHILE 292
#define GOTO 293
#define BREAK 294
#define CONTINUE 295
#define RETURN 296
#define FOR 297
#define FUNCTION 298
#define IDENTIFIER 299
#define REAL_CONSTANT 300
#define INT_CONSTANT 301
#define STRING_CONSTANT 302
#define BOOLEAN_CONSTANT 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 22 "skiffscript.y" /* yacc.c:1909  */

    int int_value;
    double double_value;
    struct _Identifier* id_value;
    struct _Parameter* para_value;
    struct _Statement* stat_value

#line 158 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

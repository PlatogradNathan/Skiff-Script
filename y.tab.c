/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 7 "skiffscript.y" /* yacc.c:339  */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "SkiffScript.h"
#include "Ski_interprter.h"

#define _DEBUG_

int importFile(const char* filename);

char* ski_file_name;


#line 81 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 22 "skiffscript.y" /* yacc.c:355  */

    int int_value;
    double double_value;
    struct _Identifier* id_value;
    struct _Parameter* para_value;
    struct _Statement* stat_value

#line 225 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 242 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   306

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  13
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  142

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    41,    41,    42,    45,    46,    52,    58,    65,    82,
     100,   104,   110,   119,   132,   141,   149,   157,   164,   172,
     181,   190,   198,   206,   223,   224,   230,   236,   242,   248,
     254,   259,   264,   269,   274,   281,   282,   290,   291,   296,
     303,   304,   309,   316,   317,   323,   331,   332,   338,   344,
     350,   358,   359,   364,   371,   372,   377,   382,   389,   390,
     391,   392,   393,   394,   399,   404,   409,   414
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "SUB", "MUL", "DIV", "AND", "OR",
  "MOD", "EQ", "NE", "GT", "GE", "LT", "LE", "LOGICAL_AND", "LOGICAL_OR",
  "NOT", "SN0", "SR", "EQU", "LP", "RP", "SN1", "LC", "RC", "VAR",
  "INTEGER", "FLOAT", "STRING_TYPE", "BYTE", "IF", "BOOLEAN", "ELSE",
  "ELIF", "DO", "WHILE", "GOTO", "BREAK", "CONTINUE", "RETURN", "FOR",
  "FUNCTION", "IDENTIFIER", "REAL_CONSTANT", "INT_CONSTANT",
  "STRING_CONSTANT", "BOOLEAN_CONSTANT", "$accept", "line_list", "line",
  "paralist", "expression", "assign_expression", "logical_expression",
  "and_or_expression", "equ_expression", "compare_expression",
  "add_expression", "term", "primary", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF -36

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-36)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      89,    27,    27,   243,    -7,   -35,    16,    18,    30,   -36,
     -36,   243,    47,   -15,   -20,   -36,   -36,   -36,   -36,    14,
     -36,    28,   -36,     0,    26,    66,     7,    75,    -2,   -36,
      64,   -36,   -36,    69,    70,    67,    72,    77,   243,   -36,
     243,   -36,   135,    78,    27,   166,   -36,   -36,   -36,    27,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    27,   -36,   -36,   243,   243,   -18,    79,
      80,   181,    84,   212,     0,   -36,    57,   -36,    26,    26,
      66,    66,     7,     7,    75,    75,    75,    75,    -2,    -2,
     -36,   -36,   -36,    83,    85,   -36,   -36,   -36,   -36,   -36,
      88,    92,   227,    24,   120,    93,    59,   -36,   243,    94,
     -36,   -36,   -36,    95,    86,   243,    97,   243,    98,    90,
     -36,   116,   -36,   -36,   -36,   119,   122,   -36,   123,   -36,
     258,   -36,   -36,   124,   125,   126,   129,   -36,   -36,   -36,
     131,   -36
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,    10,     0,     0,     0,     0,    31,
      32,    34,     0,     0,    62,    58,    59,    60,    61,     0,
       2,     0,    24,    35,    37,    40,    43,    46,    51,    54,
      62,    64,    65,     0,     0,     0,     0,    30,     0,    11,
       0,    33,     0,     0,     0,     0,     1,     3,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,     8,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    66,     0,    22,    38,    39,
      41,    42,    44,    45,    47,    48,    49,    50,    52,    53,
      55,    56,    57,     0,     0,    25,    26,    27,    28,    29,
       0,     0,     0,     0,     0,     0,     0,    67,     0,     0,
      12,     6,     7,     0,     0,     0,     0,     0,     0,     0,
      21,     0,    23,     9,    17,     0,     0,    16,     0,    18,
       0,     5,    15,     0,     0,     0,     0,    14,    19,    20,
       0,    13
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -36,   -36,   139,    81,    -3,   -36,   104,    35,    36,    37,
     -32,    38,     4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    19,    20,    76,    21,    22,    23,    24,    25,    26,
      27,    28,    29
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,    44,    45,    61,    62,    31,    32,    63,    41,    37,
      95,    96,    97,    98,    46,    99,    49,    50,     1,    55,
      56,    57,    58,    84,    85,    86,    87,    34,    35,    43,
      36,     1,     2,    51,    52,    69,     3,    70,    38,    72,
       4,     5,    77,    39,   115,     2,     6,   116,    48,     3,
       7,     8,    40,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    93,    94,    90,    91,    92,   103,    42,
      77,    30,    15,    16,    17,    18,    53,    54,    59,    60,
     107,   108,   121,   108,    78,    79,    45,    80,    81,    66,
      82,    83,    64,     1,    67,    65,    68,    88,    89,   114,
      73,   119,   100,   101,   104,   122,   109,     2,   110,   125,
     130,     3,   126,   111,   128,     4,     5,   112,   120,   123,
     124,     6,   127,   129,     1,     7,     8,   136,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,     2,     1,
     117,   131,     3,   118,   132,   133,   134,     5,    74,   137,
     138,   139,   140,     2,   106,    71,   141,     3,    47,     9,
      10,    11,     5,     0,    14,    15,    16,    17,    18,     0,
       1,     0,     0,     0,     9,    10,    11,     0,     0,    14,
      15,    16,    17,    18,     2,     1,     0,     0,     3,    75,
       0,     0,     0,     5,     0,     0,     0,     0,     0,     2,
       0,   102,     0,     3,     0,     9,    10,    11,     5,     0,
      14,    15,    16,    17,    18,     0,     1,     0,     0,     0,
       9,    10,    11,     0,     0,    14,    15,    16,    17,    18,
       2,     1,     0,     0,     3,   105,     0,     0,     0,     5,
       0,     0,     0,     0,     0,     2,     0,     1,     0,     3,
     113,     9,    10,    11,     5,     0,    14,    15,    16,    17,
      18,     2,     1,     0,     0,     3,     9,    10,    11,     0,
       5,    14,    15,    16,    17,    18,     2,     0,     0,     0,
       3,   135,     9,    10,    11,     5,     0,    14,    15,    16,
      17,    18,     0,     0,     0,     0,     0,     9,    10,    11,
       0,     0,    14,    15,    16,    17,    18
};

static const yytype_int16 yycheck[] =
{
       3,    21,    22,     5,     6,     1,     2,     9,    11,    44,
      28,    29,    30,    31,     0,    33,    16,    17,     4,    12,
      13,    14,    15,    55,    56,    57,    58,    34,    35,    44,
      37,     4,    18,     7,     8,    38,    22,    40,    22,    42,
      26,    27,    45,    25,    20,    18,    32,    23,    20,    22,
      36,    37,    22,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    66,    67,    61,    62,    63,    71,    22,
      73,    44,    45,    46,    47,    48,    10,    11,     3,     4,
      23,    24,    23,    24,    49,    50,    22,    51,    52,    22,
      53,    54,    23,     4,    22,    25,    19,    59,    60,   102,
      22,   104,    23,    23,    20,   108,    23,    18,    23,    23,
      20,    22,   115,    25,   117,    26,    27,    25,    25,    25,
      25,    32,    25,    25,     4,    36,    37,   130,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    18,     4,
      20,    25,    22,    23,    25,    23,    23,    27,    44,    25,
      25,    25,    23,    18,    73,    20,    25,    22,    19,    39,
      40,    41,    27,    -1,    44,    45,    46,    47,    48,    -1,
       4,    -1,    -1,    -1,    39,    40,    41,    -1,    -1,    44,
      45,    46,    47,    48,    18,     4,    -1,    -1,    22,    23,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,    18,
      -1,    20,    -1,    22,    -1,    39,    40,    41,    27,    -1,
      44,    45,    46,    47,    48,    -1,     4,    -1,    -1,    -1,
      39,    40,    41,    -1,    -1,    44,    45,    46,    47,    48,
      18,     4,    -1,    -1,    22,    23,    -1,    -1,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    18,    -1,     4,    -1,    22,
      23,    39,    40,    41,    27,    -1,    44,    45,    46,    47,
      48,    18,     4,    -1,    -1,    22,    39,    40,    41,    -1,
      27,    44,    45,    46,    47,    48,    18,    -1,    -1,    -1,
      22,    23,    39,    40,    41,    27,    -1,    44,    45,    46,
      47,    48,    -1,    -1,    -1,    -1,    -1,    39,    40,    41,
      -1,    -1,    44,    45,    46,    47,    48
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    18,    22,    26,    27,    32,    36,    37,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    50,
      51,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      44,    61,    61,    53,    34,    35,    37,    44,    22,    25,
      22,    53,    22,    44,    21,    22,     0,    51,    20,    16,
      17,     7,     8,    10,    11,    12,    13,    14,    15,     3,
       4,     5,     6,     9,    23,    25,    22,    22,    19,    53,
      53,    20,    53,    22,    55,    23,    52,    53,    56,    56,
      57,    57,    58,    58,    59,    59,    59,    59,    60,    60,
      61,    61,    61,    53,    53,    28,    29,    30,    31,    33,
      23,    23,    20,    53,    20,    23,    52,    23,    24,    23,
      23,    25,    25,    23,    53,    20,    23,    20,    23,    53,
      25,    23,    53,    25,    25,    23,    53,    25,    53,    25,
      20,    25,    25,    23,    23,    23,    53,    25,    25,    25,
      23,    25
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    52,    52,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    54,    54,    55,    55,    55,
      56,    56,    56,    57,    57,    57,    58,    58,    58,    58,
      58,    59,    59,    59,    60,    60,    60,    60,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     6,     5,     5,     3,     6,
       1,     2,     5,     9,     8,     7,     6,     6,     6,     8,
       8,     5,     1,     3,     1,     4,     4,     4,     4,     4,
       2,     1,     1,     2,     1,     1,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     1,
       1,     1,     1,     3,     2,     2,     3,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 5:
#line 47 "skiffscript.y" /* yacc.c:1646  */
    {
        LocalEnvironment* env;
        env = regsiteFunction((yyvsp[-4].stat_value)->value->id_name,(yyvsp[-2].para_value));
        openLocalEnvironment(env);
    }
#line 1450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 53 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = createIfStatement(getCurrentEnvironment(),(yyvsp[-2].stat_value));
        openLocalEnvironment((yyval.stat_value)->u.if_stat->env);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1460 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 59 "skiffscript.y" /* yacc.c:1646  */
    {
        removeStatementAndCheck(getCurrentEnvironment(),(yyvsp[-2].stat_value));
        (yyval.stat_value) = createWhileStatement(getCurrentEnvironment(),(yyvsp[-2].stat_value),NORMAL_WHILE);
        openLocalEnvironment((yyval.stat_value)->u.while_stat->env);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1471 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 66 "skiffscript.y" /* yacc.c:1646  */
    {
        if(getCurrentEnvironment() != NULL)
        {
            IfStatement* current_if;
            current_if = (IfStatement*)(getCurrentEnvironment()->super);
            current_if->elseenv =createElseLocalEnvironment(getCurrentEnvironment());
            closeLocalEnvironment();
            openLocalEnvironment(current_if->elseenv);
            (yyval.stat_value) = current_if;
            (yyval.stat_value)->line_number = line_number;
        }
        else
        {
            ski_error("else missing if","What's the meaning of a single else?",line_number);
        }
    }
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 83 "skiffscript.y" /* yacc.c:1646  */
    {
        removeStatementAndCheck(getCurrentEnvironment(),(yyvsp[-2].stat_value));
        if (getCurrentEnvironment() != NULL && getCurrentEnvironment()->local_type == LOCAL_IF)
        {
            IfStatement* current_if;
            current_if = (IfStatement*)(getCurrentEnvironment()->super);
            closeLocalEnvironment();
            current_if->elif = createElseIfStatement(getCurrentEnvironment(),(yyvsp[-2].stat_value));
            (yyval.stat_value) = current_if->elif;
            openLocalEnvironment(current_if->elif->u.if_stat->env);
            (yyval.stat_value)->line_number = line_number;
        }
        else
        {
            ski_error("elif missing if","You cannot use elif the same as if",line_number);
        }
    }
#line 1514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 101 "skiffscript.y" /* yacc.c:1646  */
    {
        closeLocalEnvironment();
    }
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 105 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = createWhileStatement(getCurrentEnvironment(),NULL,DO_WHILE);
        openLocalEnvironment((yyval.stat_value)->u.while_stat->env);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 111 "skiffscript.y" /* yacc.c:1646  */
    {
        WhileStatement* current_while;
        removeStatementAndCheck(getCurrentEnvironment(),(yyvsp[-1].stat_value));
        current_while = (WhileStatement*)(getCurrentEnvironment()->super);
        current_while->condition = (yyvsp[-1].stat_value);
        closeLocalEnvironment();
        (yyval.stat_value)->line_number = line_number;
    }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 120 "skiffscript.y" /* yacc.c:1646  */
    {
        //for (a; b; c;)
        //removeStatementAndCheck(getCurrentEnvironment(),$3);
        //removeStatementAndCheck(getCurrentEnvironment(),$5);
        //removeStatementAndCheck(getCurrentEnvironment(),$7);
        removeStatementAndCheck(getCurrentEnvironment(),(yyvsp[-2].stat_value));
        removeStatementAndCheck(getCurrentEnvironment(),(yyvsp[-4].stat_value));
        removeStatementAndCheck(getCurrentEnvironment(),(yyvsp[-6].stat_value));
        (yyval.stat_value) = createForStatement(getCurrentEnvironment(),(yyvsp[-6].stat_value),(yyvsp[-4].stat_value),(yyvsp[-2].stat_value));
        openLocalEnvironment((yyval.stat_value)->u.for_stat->env);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 133 "skiffscript.y" /* yacc.c:1646  */
    {
        //for( ; b; c )
        removeStatementAndCheck(getCurrentEnvironment(),(yyvsp[-4].stat_value));
        removeStatementAndCheck(getCurrentEnvironment(),(yyvsp[-2].stat_value));
        (yyval.stat_value) = createForStatement(getCurrentEnvironment(),NULL,(yyvsp[-4].stat_value),(yyvsp[-2].stat_value));
        openLocalEnvironment((yyval.stat_value)->u.for_stat->env);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1575 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 142 "skiffscript.y" /* yacc.c:1646  */
    {
        //for (; ; c)
        removeStatementAndCheck(getCurrentEnvironment(),(yyvsp[-2].stat_value));
        (yyval.stat_value) = createForStatement(getCurrentEnvironment(),NULL,NULL,(yyvsp[-2].stat_value));
        openLocalEnvironment((yyval.stat_value)->u.for_stat->env);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 150 "skiffscript.y" /* yacc.c:1646  */
    {
        //for (; b; )
        removeStatementAndCheck(getCurrentEnvironment(),(yyvsp[-2].stat_value));
        (yyval.stat_value) = createForStatement(getCurrentEnvironment(),NULL,(yyvsp[-2].stat_value),NULL);
        openLocalEnvironment((yyval.stat_value)->u.for_stat->env);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 158 "skiffscript.y" /* yacc.c:1646  */
    {
        //for (; ;  )
        (yyval.stat_value) = createForStatement(getCurrentEnvironment(),NULL,NULL,NULL);
        openLocalEnvironment((yyval.stat_value)->u.for_stat->env);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 165 "skiffscript.y" /* yacc.c:1646  */
    {
        //for(a; ;)
        removeStatementAndCheck(getCurrentEnvironment(),(yyvsp[-3].stat_value));
        (yyval.stat_value) = createForStatement(getCurrentEnvironment(),(yyvsp[-3].stat_value),NULL,NULL);
        openLocalEnvironment((yyval.stat_value)->u.for_stat->env);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 173 "skiffscript.y" /* yacc.c:1646  */
    {
        //for (a; ; c)
        removeStatementAndCheck(getCurrentEnvironment(),(yyvsp[-5].stat_value));
        removeStatementAndCheck(getCurrentEnvironment(),(yyvsp[-2].stat_value));
        (yyval.stat_value) = createForStatement(getCurrentEnvironment(),(yyvsp[-5].stat_value),NULL,(yyvsp[-2].stat_value));
        openLocalEnvironment((yyval.stat_value)->u.for_stat->env);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 182 "skiffscript.y" /* yacc.c:1646  */
    {
        //for (a; b;)
        removeStatementAndCheck(getCurrentEnvironment(),(yyvsp[-5].stat_value));
        removeStatementAndCheck(getCurrentEnvironment(),(yyvsp[-3].stat_value));
        (yyval.stat_value) = createForStatement(getCurrentEnvironment(),(yyvsp[-5].stat_value),(yyvsp[-3].stat_value),NULL);
        openLocalEnvironment((yyval.stat_value)->u.for_stat->env);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1648 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 191 "skiffscript.y" /* yacc.c:1646  */
    {
        LocalEnvironment* env;
        env = regsiteFunction((yyvsp[-3].stat_value)->value->id_name,NULL);
        openLocalEnvironment(env);
    }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 199 "skiffscript.y" /* yacc.c:1646  */
    {
        removeStatementAndCheck(getCurrentEnvironment(),(yyvsp[0].stat_value));
        (yyval.para_value) = (Parameter*)malloc(sizeof(Parameter));
        (yyval.para_value)->stat = (yyvsp[0].stat_value);
        (yyval.para_value)->para_count = 1;
        (yyval.para_value)->next = NULL;
    }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 207 "skiffscript.y" /* yacc.c:1646  */
    {
        Parameter* iterator;
        iterator = (yyvsp[-2].para_value);
        removeStatementAndCheck(getCurrentEnvironment(),(yyvsp[0].stat_value));
        for(int i = 1;i < (yyvsp[-2].para_value)->para_count;i++)
        {
            iterator = iterator->next;
        }
        iterator->next = (Parameter*)malloc(sizeof(Parameter));
        iterator->next->stat = (yyvsp[0].stat_value);
        iterator->next->next = NULL;
        (yyvsp[-2].para_value)->para_count++;
        (yyval.para_value) = (yyvsp[-2].para_value);
    }
#line 1689 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 225 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyvsp[-2].stat_value)->value->value.type = SKI_INTEGER;
        (yyval.stat_value) = createVariableExpression(getCurrentEnvironment(),(yyvsp[-2].stat_value)->value);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 231 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyvsp[-2].stat_value)->value->value.type = SKI_FLOAT;
        (yyval.stat_value) = createVariableExpression(getCurrentEnvironment(),(yyvsp[-2].stat_value)->value);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 237 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyvsp[-2].stat_value)->value->value.type = SKI_STR;
        (yyval.stat_value) = createVariableExpression(getCurrentEnvironment(),(yyvsp[-2].stat_value)->value);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 243 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyvsp[-2].stat_value)->value->value.type = SKI_BYTE;
        (yyval.stat_value) = createVariableExpression(getCurrentEnvironment(),(yyvsp[-2].stat_value)->value);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 249 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyvsp[-2].stat_value)->value->value.type = SKI_BOOLEAN;
        (yyval.stat_value) = createVariableExpression(getCurrentEnvironment(),(yyvsp[-2].stat_value)->value);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 255 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = createVariableExpression(getCurrentEnvironment(),(yyvsp[0].stat_value)->value);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 260 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = createBreakStatement(getCurrentEnvironment());
        (yyval.stat_value)->line_number = line_number;
    }
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 265 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = createContinueStatement(getCurrentEnvironment());
        (yyval.stat_value)->line_number = line_number;
    }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 270 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = createReturnStatement(getCurrentEnvironment(),(yyvsp[0].stat_value));
        (yyval.stat_value)->line_number = line_number;
    }
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 275 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = createReturnStatement(getCurrentEnvironment(),NULL);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 283 "skiffscript.y" /* yacc.c:1646  */
    {
        removeStatementAndCheck(getCurrentEnvironment(),(yyvsp[0].stat_value));
        (yyval.stat_value) = createBinaryExpression(getCurrentEnvironment(),ASSIGN_EXP,(yyvsp[-2].stat_value),(yyvsp[0].stat_value));
        (yyval.stat_value)->line_number = line_number;
    }
#line 1794 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 292 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = createBinaryExpression(getCurrentEnvironment(),LOGICAL_AND_EXP,(yyvsp[-2].stat_value),(yyvsp[0].stat_value));
        (yyval.stat_value)->line_number = line_number;
    }
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 297 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = createBinaryExpression(getCurrentEnvironment(),LOGICAL_OR_EXP,(yyvsp[-2].stat_value),(yyvsp[0].stat_value));
        (yyval.stat_value)->line_number = line_number;
    }
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 305 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = createBinaryExpression(getCurrentEnvironment(),AND_EXP,(yyvsp[-2].stat_value),(yyvsp[0].stat_value));
        (yyval.stat_value)->line_number = line_number;
    }
#line 1821 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 310 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = createBinaryExpression(getCurrentEnvironment(),OR_EXP,(yyvsp[-2].stat_value),(yyvsp[0].stat_value));
        (yyval.stat_value)->line_number = line_number;
    }
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 318 "skiffscript.y" /* yacc.c:1646  */
    {
        // '=='
        (yyval.stat_value) = createBinaryExpression(getCurrentEnvironment(),EQ_EXP,(yyvsp[-2].stat_value),(yyvsp[0].stat_value));
        (yyval.stat_value)->line_number = line_number;
    }
#line 1840 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 324 "skiffscript.y" /* yacc.c:1646  */
    {
        // '!='
        (yyval.stat_value) = createBinaryExpression(getCurrentEnvironment(),NE_EXP,(yyvsp[-2].stat_value),(yyvsp[0].stat_value));
        (yyval.stat_value)->line_number = line_number;
    }
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 333 "skiffscript.y" /* yacc.c:1646  */
    {
        // '>'
        (yyval.stat_value) = createBinaryExpression(getCurrentEnvironment(),GT_EXP,(yyvsp[-2].stat_value),(yyvsp[0].stat_value));
        (yyval.stat_value)->line_number = line_number;
    }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 339 "skiffscript.y" /* yacc.c:1646  */
    {
        // '>='
        (yyval.stat_value) = createBinaryExpression(getCurrentEnvironment(),GE_EXP,(yyvsp[-2].stat_value),(yyvsp[0].stat_value));
        (yyval.stat_value)->line_number = line_number;
    }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 345 "skiffscript.y" /* yacc.c:1646  */
    {
        // '<'
        (yyval.stat_value) = createBinaryExpression(getCurrentEnvironment(),LT_EXP,(yyvsp[-2].stat_value),(yyvsp[0].stat_value));
        (yyval.stat_value)->line_number = line_number;
    }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 351 "skiffscript.y" /* yacc.c:1646  */
    {
        // '<='
        (yyval.stat_value) = createBinaryExpression(getCurrentEnvironment(),LE_EXP,(yyvsp[-2].stat_value),(yyvsp[0].stat_value));
        (yyval.stat_value)->line_number = line_number;
    }
#line 1890 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 360 "skiffscript.y" /* yacc.c:1646  */
    {
       (yyval.stat_value) = createBinaryExpression(getCurrentEnvironment(),ADD_EXP,(yyvsp[-2].stat_value),(yyvsp[0].stat_value));
       (yyval.stat_value)->line_number = line_number;
    }
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 365 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = createBinaryExpression(getCurrentEnvironment(),SUB_EXP,(yyvsp[-2].stat_value),(yyvsp[0].stat_value));
        (yyval.stat_value)->line_number = line_number;
    }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 373 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = createBinaryExpression(getCurrentEnvironment(),MUL_EXP,(yyvsp[-2].stat_value),(yyvsp[0].stat_value));
        (yyval.stat_value)->line_number = line_number;
    }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 378 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = createBinaryExpression(getCurrentEnvironment(),DIV_EXP,(yyvsp[-2].stat_value),(yyvsp[0].stat_value));
        (yyval.stat_value)->line_number = line_number;
    }
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 383 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = createBinaryExpression(getCurrentEnvironment(),MOD_EXP,(yyvsp[-2].stat_value),(yyvsp[0].stat_value));
        (yyval.stat_value)->line_number = line_number;
    }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 395 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = (yyvsp[-1].stat_value);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 400 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = createMinusExpression(getCurrentEnvironment(),MINUS_EXP,(yyvsp[0].stat_value));
        (yyval.stat_value)->line_number = line_number;
    }
#line 1953 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 405 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = createMinusExpression(getCurrentEnvironment(),NOT_EXP,(yyvsp[0].stat_value));
        (yyval.stat_value)->line_number = line_number;
    }
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 410 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = createFunctionCallExpression(getCurrentEnvironment(),(yyvsp[-2].stat_value)->value->id_name,NULL);
        (yyval.stat_value)->line_number = line_number;
    }
#line 1971 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 415 "skiffscript.y" /* yacc.c:1646  */
    {
        (yyval.stat_value) = createFunctionCallExpression(getCurrentEnvironment(),(yyvsp[-3].stat_value)->value->id_name,(yyvsp[-1].para_value));
        (yyval.stat_value)->line_number = line_number;
    }
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1984 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 420 "skiffscript.y" /* yacc.c:1906  */


extern word isFunnyMsgOpen;

int yyerror(char const *str)
{
    extern char* yytext;
    ski_error("Wrong grammar near \"%s\"","May be there's a low-level mistake near %s",line_number,yytext);
    return 0;
}

int importFile(const char* filename)
{
    extern FILE* yyin;
    extern int yyparse();
    extern Interpreter* interpreter;

    yyin = fopen(filename,"rb");
    if (yyparse())
    {
        exit(1);
    }
}

void readArgs(int argc,char** argv)
{
    int i;
    char* para;
    for (i = 2;i < argc;i++)
    {
        para = argv[i];
        if (strcmp(para,"-f") == 0 || strcmp(para,"/f") == 0) {
            isFunnyMsgOpen = 1;
        } else if (strcmp(para,"-?") == 0 || strcmp(para,"/?") == 0 || strcmp(para,"-help") ==0 || 
        strcmp(para,"/help") == 0) {
            puts("*****************************");
            puts("*  Skiff script help info   *");
            puts("*skis <filename> -f...      *");
            puts("*-f:show funny error message*");
            puts("*-?:show this help info     *");
            puts("*****************************");
        } else {
            printf("Unknow parameter:%s\n\a",para);
            exit(0);
        }
    }
}

int main(int argc,char** argv)
{
    extern int yyparse();
    extern FILE* yyin;
    extern Interpreter* interpreter;

    if (argc > 1)
    {
       ski_file_name = argv[1];
       if (strcmp(argv[1],"-?") == 0 || strcmp(argv[1],"/?") == 0 || strcmp(argv[1],"-help") ==0 || 
        strcmp(argv[1],"/help") == 0) {
            puts("*****************************");
            puts("*  Skiff script help info   *");
            puts("*skis <filename> -f...      *");
            puts("*-f:show funny error message*");
            puts("*-?:show this help info     *");
            puts("*****************************");
            exit(0);
        }
        isFunnyMsgOpen = 0;
       if (argc >= 2) {
            readArgs(argc,argv);
        }
       initializeVariable();
        initializeFunction();
        initializeInterpreter();
        initializeEnvironment();
        regsiteAllNativeFunctions();
       importFile(argv[1]);
        executeStatments(NULL);
        disposeVariable();
        disposeFunction();
        disposeInterpreter();
        fclose(yyin);
    }
}

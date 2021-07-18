/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_TURE = 258,
     T_FALSE = 259,
     T_TYPE = 260,
     T_ID = 261,
     T_ADD = 262,
     T_SUB = 263,
     T_MUL = 264,
     T_DIV = 265,
     T_MOD = 266,
     T_ASSIGNOP = 267,
     T_GT = 268,
     T_LT = 269,
     T_GE = 270,
     T_LE = 271,
     T_AND = 272,
     T_OR = 273,
     T_NUM = 274,
     T_DECIMAL = 275,
     T_LEFTPAREN = 276,
     T_LEFTBRACE = 277,
     T_LEFTBRACKET = 278,
     T_RIGHTPAREN = 279,
     T_RIGHTBRACE = 280,
     T_RIGHTBRACKET = 281,
     T_SEMICOLON = 282,
     T_COMMA = 283,
     T_STRING = 284,
     T_NOT = 285,
     T_IF = 286,
     T_ELSE = 287,
     T_WHILE = 288,
     T_FOR = 289,
     T_RETURN = 290,
     T_EQUAL = 291,
     T_UNEQUAL = 292,
     T_ERROR = 293,
     T_BREAK = 294,
     T_CONTINUE = 295,
     UMINUS = 296
   };
#endif
/* Tokens.  */
#define T_TURE 258
#define T_FALSE 259
#define T_TYPE 260
#define T_ID 261
#define T_ADD 262
#define T_SUB 263
#define T_MUL 264
#define T_DIV 265
#define T_MOD 266
#define T_ASSIGNOP 267
#define T_GT 268
#define T_LT 269
#define T_GE 270
#define T_LE 271
#define T_AND 272
#define T_OR 273
#define T_NUM 274
#define T_DECIMAL 275
#define T_LEFTPAREN 276
#define T_LEFTBRACE 277
#define T_LEFTBRACKET 278
#define T_RIGHTPAREN 279
#define T_RIGHTBRACE 280
#define T_RIGHTBRACKET 281
#define T_SEMICOLON 282
#define T_COMMA 283
#define T_STRING 284
#define T_NOT 285
#define T_IF 286
#define T_ELSE 287
#define T_WHILE 288
#define T_FOR 289
#define T_RETURN 290
#define T_EQUAL 291
#define T_UNEQUAL 292
#define T_ERROR 293
#define T_BREAK 294
#define T_CONTINUE 295
#define UMINUS 296




/* Copy the first part of user declarations.  */
#line 1 "parse.y"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "def.h"


int yylex();
int nowTable=0;//当前符号表
int maxTable = 0;//符号表的总数
int nextinstr = 100;//下一条三地址指令的索引
int ncodes = 0;//记录三地址指令的总数
int tmpVal = 0;//临时变量
int nts=0;//翻译生成的编号
int params=0;//函数参数的个数
void yyerror(const char* msg);
extern FILE *yyin;
extern int numLines;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 21 "parse.y"
{
        char name[256];
        char *namePtr;
        double dval;
        struct symbol *symp;
        struct translate *attr;
        int instr;
}
/* Line 193 of yacc.c.  */
#line 207 "parse.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 220 "parse.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   315

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNRULES -- Number of states.  */
#define YYNSTATES  139

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   296

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     9,    10,    14,    18,    22,    26,
      30,    35,    40,    44,    48,    52,    56,    60,    64,    68,
      72,    75,    78,    80,    82,    84,    86,    88,    90,    92,
      93,    98,   102,   106,   109,   112,   117,   121,   125,   126,
     130,   131,   139,   143,   144,   149,   150,   151,   157,   160,
     161,   165,   166,   174,   184,   187,   188,   192,   193,   204,
     211,   212,   214,   217,   220,   223,   227
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      43,     0,    -1,    48,    43,    -1,    63,    43,    -1,    -1,
      44,     7,    44,    -1,    44,     8,    44,    -1,    44,     9,
      44,    -1,    44,    10,    44,    -1,    44,    11,    44,    -1,
      44,    17,    45,    44,    -1,    44,    18,    45,    44,    -1,
      44,    13,    44,    -1,    44,    15,    44,    -1,    44,    14,
      44,    -1,    44,    16,    44,    -1,    44,    36,    44,    -1,
      44,    37,    44,    -1,     6,    12,    44,    -1,    21,    44,
      24,    -1,     8,    44,    -1,    30,    44,    -1,     6,    -1,
      52,    -1,    20,    -1,    19,    -1,     3,    -1,     4,    -1,
      29,    -1,    -1,    45,    44,    27,    46,    -1,    60,    45,
      46,    -1,    56,    45,    46,    -1,    57,    46,    -1,    63,
      46,    -1,    35,    44,    27,    46,    -1,    39,    27,    46,
      -1,    40,    27,    46,    -1,    -1,    22,    46,    25,    -1,
      -1,     5,     6,    49,    21,    50,    24,    47,    -1,    51,
       5,     6,    -1,    -1,    51,     5,     6,    28,    -1,    -1,
      -1,     6,    53,    21,    54,    24,    -1,    44,    55,    -1,
      -1,    28,    44,    55,    -1,    -1,    33,    45,    21,    44,
      24,    45,    62,    -1,    34,    21,    58,    27,    58,    27,
      58,    24,    62,    -1,    44,    59,    -1,    -1,    59,    28,
      44,    -1,    -1,    31,    21,    44,    24,    45,    62,    61,
      32,    45,    62,    -1,    31,    21,    44,    24,    45,    62,
      -1,    -1,    47,    -1,    39,    27,    -1,    40,    27,    -1,
      64,    27,    -1,    64,    28,     6,    -1,     5,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    91,    91,    92,    93,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   123,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   138,
     141,   141,   144,   145,   148,   149,   152,   152,   155,   156,
     159,   160,   164,   167,   170,   171,   174,   175,   178,   179,
     182,   185,   186,   187,   190,   193,   194
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_TURE", "T_FALSE", "T_TYPE", "T_ID",
  "T_ADD", "T_SUB", "T_MUL", "T_DIV", "T_MOD", "T_ASSIGNOP", "T_GT",
  "T_LT", "T_GE", "T_LE", "T_AND", "T_OR", "T_NUM", "T_DECIMAL",
  "T_LEFTPAREN", "T_LEFTBRACE", "T_LEFTBRACKET", "T_RIGHTPAREN",
  "T_RIGHTBRACE", "T_RIGHTBRACKET", "T_SEMICOLON", "T_COMMA", "T_STRING",
  "T_NOT", "T_IF", "T_ELSE", "T_WHILE", "T_FOR", "T_RETURN", "T_EQUAL",
  "T_UNEQUAL", "T_ERROR", "T_BREAK", "T_CONTINUE", "UMINUS", "$accept",
  "program", "expression", "M", "statements", "block", "func", "@1",
  "parameters", "parameter", "func_call", "@2", "call_parameters",
  "call_parameter", "while_loop", "for_loop", "for_exp", "for_other",
  "if_stmt", "N", "other", "declares", "declare", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    43,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    45,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    47,
      49,    48,    50,    50,    51,    51,    53,    52,    54,    54,
      55,    55,    56,    57,    58,    58,    59,    59,    60,    60,
      61,    62,    62,    62,    63,    64,    64
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     0,     3,     3,     3,     3,     3,
       4,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     0,
       4,     3,     3,     2,     2,     4,     3,     3,     0,     3,
       0,     7,     3,     0,     4,     0,     0,     5,     2,     0,
       3,     0,     7,     9,     2,     0,     3,     0,    10,     6,
       0,     1,     2,     2,     2,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     4,     4,     0,    66,     1,     2,     3,
      64,     0,     0,    65,    43,     0,     0,     0,     0,    29,
      41,    42,     0,     0,    29,     0,     0,     0,     0,     0,
       0,    29,    29,    29,    29,    44,    66,     0,     0,    55,
      26,    27,    22,     0,    25,    24,     0,    28,     0,     0,
      23,    29,    29,     0,    39,    29,    33,    29,    34,     0,
       0,    57,     0,     0,     0,    20,     0,    21,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    29,    29,
       0,     0,    36,    37,    29,    32,    31,    29,     0,    54,
      55,    18,    49,    19,     5,     6,     7,     8,     9,    12,
      14,    13,    15,     0,     0,    35,    16,    17,    30,     0,
      29,     0,     0,    51,     0,    10,    11,     0,     0,    61,
      59,     0,    56,    55,     0,    48,    47,    62,    63,     0,
      52,     0,    51,    29,     0,    50,     0,    53,    58
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    61,    29,    30,   119,     3,    12,    15,    16,
      50,    64,   114,   125,    31,    32,    62,    89,    33,   129,
     120,    34,     5
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -106
static const yytype_int16 yypact[] =
{
       0,     2,    30,     0,     0,    10,   -11,  -106,  -106,  -106,
    -106,    26,    14,  -106,    38,    28,    45,    36,    56,    50,
    -106,    46,    73,    59,  -106,    61,   285,    60,    64,   285,
      67,  -106,    50,  -106,    50,  -106,  -106,   285,    72,   285,
    -106,  -106,    15,   285,  -106,  -106,   285,  -106,   285,   108,
    -106,    50,    50,   123,  -106,    50,  -106,    50,  -106,   154,
     285,   259,    68,   285,    75,  -106,   185,  -106,   285,   285,
     285,   285,   285,   285,   285,   285,   285,  -106,  -106,    50,
     285,   285,  -106,  -106,    50,  -106,  -106,  -106,   216,    66,
     285,   259,   285,  -106,    -7,    -7,  -106,  -106,  -106,   166,
     166,   166,   166,   285,   285,  -106,   197,   197,  -106,   -16,
    -106,   285,    70,   228,    74,   271,     4,    76,    77,  -106,
      69,   -16,   259,   285,   285,  -106,  -106,  -106,  -106,    78,
    -106,    81,   228,  -106,   -16,  -106,   -16,  -106,  -106
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -106,    44,    -4,   -24,    -6,    85,  -106,  -106,  -106,  -106,
    -106,  -106,  -106,   -26,  -106,  -106,   -89,  -106,  -106,  -106,
    -105,    57,  -106
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -61
static const yytype_int16 yytable[] =
{
      38,   112,    70,    71,    72,     1,    19,    55,     6,    57,
     -40,    68,    69,    70,    71,    72,   130,    73,    74,    75,
      76,    77,    49,   117,   118,    53,    56,    63,    58,   137,
       7,   138,    13,    59,   131,    14,   -46,    10,    11,    65,
      80,    81,    66,   -45,    67,    82,    83,     8,     9,    85,
      18,    86,    17,   103,   104,    22,    88,     4,    19,    91,
       4,     4,    21,   109,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   105,    35,   -38,   106,   107,   108,    36,
      37,    23,    39,    24,    25,    26,   121,    51,   113,    27,
      28,    52,    54,    60,   111,    90,    92,   123,   126,   115,
     116,   -60,    20,   127,   128,   134,   135,   122,     0,   136,
     133,     0,     0,     0,     0,    68,    69,    70,    71,    72,
     132,    73,    74,    75,    76,    77,    78,     0,     0,     0,
      68,    69,    70,    71,    72,    79,    73,    74,    75,    76,
      77,    78,     0,     0,    80,    81,     0,     0,     0,     0,
      84,     0,     0,     0,     0,     0,     0,     0,     0,    80,
      81,    68,    69,    70,    71,    72,     0,    73,    74,    75,
      76,    77,    78,    68,    69,    70,    71,    72,    87,   -61,
     -61,   -61,   -61,     0,     0,     0,     0,     0,     0,     0,
      80,    81,    68,    69,    70,    71,    72,     0,    73,    74,
      75,    76,    77,    78,    68,    69,    70,    71,    72,    93,
      73,    74,    75,    76,     0,     0,     0,     0,     0,     0,
       0,    80,    81,    68,    69,    70,    71,    72,     0,    73,
      74,    75,    76,    77,    78,    68,    69,    70,    71,    72,
     110,    73,    74,    75,    76,    77,    78,     0,     0,     0,
       0,     0,    80,    81,     0,     0,   124,     0,     0,     0,
       0,     0,     0,     0,    80,    81,    68,    69,    70,    71,
      72,     0,    73,    74,    75,    76,    77,    78,    68,    69,
      70,    71,    72,     0,    73,    74,    75,    76,    40,    41,
       0,    42,     0,    43,     0,    80,    81,     0,     0,     0,
       0,     0,     0,     0,    44,    45,    46,    80,    81,     0,
       0,     0,     0,     0,    47,    48
};

static const yytype_int16 yycheck[] =
{
      24,    90,     9,    10,    11,     5,    22,    31,     6,    33,
      21,     7,     8,     9,    10,    11,   121,    13,    14,    15,
      16,    17,    26,    39,    40,    29,    32,    12,    34,   134,
       0,   136,     6,    37,   123,    21,    21,    27,    28,    43,
      36,    37,    46,     5,    48,    51,    52,     3,     4,    55,
       5,    57,    24,    77,    78,     5,    60,     0,    22,    63,
       3,     4,     6,    87,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    79,    28,    25,    80,    81,    84,     6,
      21,    31,    21,    33,    34,    35,   110,    27,    92,    39,
      40,    27,    25,    21,    28,    27,    21,    27,    24,   103,
     104,    32,    17,    27,    27,    24,   132,   111,    -1,   133,
      32,    -1,    -1,    -1,    -1,     7,     8,     9,    10,    11,
     124,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
       7,     8,     9,    10,    11,    27,    13,    14,    15,    16,
      17,    18,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    36,
      37,     7,     8,     9,    10,    11,    -1,    13,    14,    15,
      16,    17,    18,     7,     8,     9,    10,    11,    24,    13,
      14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      36,    37,     7,     8,     9,    10,    11,    -1,    13,    14,
      15,    16,    17,    18,     7,     8,     9,    10,    11,    24,
      13,    14,    15,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    37,     7,     8,     9,    10,    11,    -1,    13,
      14,    15,    16,    17,    18,     7,     8,     9,    10,    11,
      24,    13,    14,    15,    16,    17,    18,    -1,    -1,    -1,
      -1,    -1,    36,    37,    -1,    -1,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    36,    37,     7,     8,     9,    10,
      11,    -1,    13,    14,    15,    16,    17,    18,     7,     8,
       9,    10,    11,    -1,    13,    14,    15,    16,     3,     4,
      -1,     6,    -1,     8,    -1,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    21,    36,    37,    -1,
      -1,    -1,    -1,    -1,    29,    30
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    43,    48,    63,    64,     6,     0,    43,    43,
      27,    28,    49,     6,    21,    50,    51,    24,     5,    22,
      47,     6,     5,    31,    33,    34,    35,    39,    40,    45,
      46,    56,    57,    60,    63,    28,     6,    21,    45,    21,
       3,     4,     6,     8,    19,    20,    21,    29,    30,    44,
      52,    27,    27,    44,    25,    45,    46,    45,    46,    44,
      21,    44,    58,    12,    53,    44,    44,    44,     7,     8,
       9,    10,    11,    13,    14,    15,    16,    17,    18,    27,
      36,    37,    46,    46,    27,    46,    46,    24,    44,    59,
      27,    44,    21,    24,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    45,    45,    46,    44,    44,    46,    45,
      24,    28,    58,    44,    54,    44,    44,    39,    40,    47,
      62,    45,    44,    27,    28,    55,    24,    27,    27,    61,
      62,    58,    44,    32,    24,    55,    45,    62,    62
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 91 "parse.y"
    {;}
    break;

  case 3:
#line 92 "parse.y"
    {;}
    break;

  case 4:
#line 93 "parse.y"
    {;}
    break;

  case 5:
#line 96 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;sprintf((yyval.attr)->name,"t%d",tmpVal);tmpVal++;char c[2000];sprintf(c,"%s=%s+%s",(yyval.attr)->name,(yyvsp[(1) - (3)].attr)->name,(yyvsp[(3) - (3)].attr)->name);genCodes(c);;}
    break;

  case 6:
#line 97 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;sprintf((yyval.attr)->name,"t%d",tmpVal);tmpVal++;char c[2000];sprintf(c,"%s=%s-%s",(yyval.attr)->name,(yyvsp[(1) - (3)].attr)->name,(yyvsp[(3) - (3)].attr)->name);genCodes(c);;}
    break;

  case 7:
#line 98 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;sprintf((yyval.attr)->name,"t%d",tmpVal);tmpVal++;char c[2000];sprintf(c,"%s=%s*%s",(yyval.attr)->name,(yyvsp[(1) - (3)].attr)->name,(yyvsp[(3) - (3)].attr)->name);genCodes(c);;}
    break;

  case 8:
#line 99 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;sprintf((yyval.attr)->name,"t%d",tmpVal);tmpVal++;char c[2000];sprintf(c,"%s=%s/%s",(yyval.attr)->name,(yyvsp[(1) - (3)].attr)->name,(yyvsp[(3) - (3)].attr)->name);genCodes(c);;}
    break;

  case 9:
#line 100 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;sprintf((yyval.attr)->name,"t%d",tmpVal);tmpVal++;char c[2000];sprintf(c,"%s=%s+%s",(yyval.attr)->name,(yyvsp[(1) - (3)].attr)->name,(yyvsp[(3) - (3)].attr)->name);genCodes(c);;}
    break;

  case 10:
#line 101 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;backPatch((yyvsp[(1) - (4)].attr)->trueList,(yyvsp[(1) - (4)].attr)->tTop,(yyvsp[(3) - (4)].instr));merge((yyval.attr)->falseList,&((yyval.attr)->fTop),(yyvsp[(1) - (4)].attr)->falseList,(yyvsp[(1) - (4)].attr)->fTop,(yyvsp[(4) - (4)].attr)->falseList,(yyvsp[(4) - (4)].attr)->fTop);assign((yyval.attr)->trueList,&((yyval.attr)->tTop),(yyvsp[(4) - (4)].attr)->trueList,(yyvsp[(4) - (4)].attr)->tTop);;}
    break;

  case 11:
#line 102 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;backPatch((yyvsp[(1) - (4)].attr)->falseList,(yyvsp[(1) - (4)].attr)->fTop,(yyvsp[(3) - (4)].instr));merge((yyval.attr)->trueList,&((yyval.attr)->tTop),(yyvsp[(1) - (4)].attr)->trueList,(yyvsp[(1) - (4)].attr)->tTop,(yyvsp[(4) - (4)].attr)->trueList,(yyvsp[(4) - (4)].attr)->tTop);assign((yyval.attr)->falseList,&((yyval.attr)->fTop),(yyvsp[(4) - (4)].attr)->falseList,(yyvsp[(4) - (4)].attr)->fTop);;}
    break;

  case 12:
#line 103 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;(yyval.attr)->trueList[(yyval.attr)->tTop]=nextinstr;((yyval.attr)->tTop)++;char c[2000];sprintf(c,"if %s>%s goto ",(yyvsp[(1) - (3)].attr)->name,(yyvsp[(3) - (3)].attr)->name);genCodes(c);(yyval.attr)->falseList[(yyval.attr)->fTop]=nextinstr;((yyval.attr)->fTop)++;genCodes("goto ");;}
    break;

  case 13:
#line 104 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;(yyval.attr)->trueList[(yyval.attr)->tTop]=nextinstr;((yyval.attr)->tTop)++;char c[2000];sprintf(c,"if %s>=%s goto ",(yyvsp[(1) - (3)].attr)->name,(yyvsp[(3) - (3)].attr)->name);genCodes(c);(yyval.attr)->falseList[(yyval.attr)->fTop]=nextinstr;((yyval.attr)->fTop)++;genCodes("goto ");;}
    break;

  case 14:
#line 105 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;(yyval.attr)->trueList[(yyval.attr)->tTop]=nextinstr;((yyval.attr)->tTop)++;char c[2000];sprintf(c,"if %s<%s goto ",(yyvsp[(1) - (3)].attr)->name,(yyvsp[(3) - (3)].attr)->name);genCodes(c);(yyval.attr)->falseList[(yyval.attr)->fTop]=nextinstr;((yyval.attr)->fTop)++;genCodes("goto ");;}
    break;

  case 15:
#line 106 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;(yyval.attr)->trueList[(yyval.attr)->tTop]=nextinstr;((yyval.attr)->tTop)++;char c[2000];sprintf(c,"if %s<=%s goto ",(yyvsp[(1) - (3)].attr)->name,(yyvsp[(3) - (3)].attr)->name);genCodes(c);(yyval.attr)->falseList[(yyval.attr)->fTop]=nextinstr;((yyval.attr)->fTop)++;genCodes("goto ");;}
    break;

  case 16:
#line 107 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;(yyval.attr)->trueList[(yyval.attr)->tTop]=nextinstr;((yyval.attr)->tTop)++;char c[2000];sprintf(c,"if %s==%s goto ",(yyvsp[(1) - (3)].attr)->name,(yyvsp[(3) - (3)].attr)->name);genCodes(c);(yyval.attr)->falseList[(yyval.attr)->fTop]=nextinstr;((yyval.attr)->fTop)++;genCodes("goto ");;}
    break;

  case 17:
#line 108 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;(yyval.attr)->trueList[(yyval.attr)->tTop]=nextinstr;((yyval.attr)->tTop)++;char c[2000];sprintf(c,"if %s!=%s goto ",(yyvsp[(1) - (3)].attr)->name,(yyvsp[(3) - (3)].attr)->name);genCodes(c);(yyval.attr)->falseList[(yyval.attr)->fTop]=nextinstr;((yyval.attr)->fTop)++;genCodes("goto ");;}
    break;

  case 18:
#line 109 "parse.y"
    {if (symlook((yyvsp[(1) - (3)].name))==-1){char e[500];sprintf(e,"Not declared Variable: %s!",(yyvsp[(1) - (3)].name));yyerror(e);}(yyval.attr)=&ts[nts];nts++;char c[600];sprintf(c,"%s=%s",(yyvsp[(1) - (3)].name),(yyvsp[(3) - (3)].attr)->name);genCodes(c);;}
    break;

  case 19:
#line 110 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;sprintf((yyval.attr)->name,"%s",(yyvsp[(2) - (3)].attr)->name);assign((yyval.attr)->falseList,&((yyval.attr)->fTop),(yyvsp[(2) - (3)].attr)->falseList,(yyvsp[(2) - (3)].attr)->fTop);assign((yyval.attr)->trueList,&((yyval.attr)->tTop),(yyvsp[(2) - (3)].attr)->trueList,(yyvsp[(2) - (3)].attr)->tTop);;}
    break;

  case 20:
#line 111 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;sprintf((yyval.attr)->name,"t%d",tmpVal);tmpVal++;char c[600];sprintf(c,"%s=-%s",(yyval.attr)->name,(yyvsp[(2) - (2)].attr)->name);genCodes(c);;}
    break;

  case 21:
#line 112 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;assign((yyval.attr)->trueList,&((yyval.attr)->tTop),(yyvsp[(2) - (2)].attr)->falseList,(yyvsp[(2) - (2)].attr)->fTop);assign((yyval.attr)->falseList,&((yyval.attr)->fTop),(yyvsp[(2) - (2)].attr)->trueList,(yyvsp[(2) - (2)].attr)->tTop);;}
    break;

  case 22:
#line 113 "parse.y"
    {if (symlook((yyvsp[(1) - (1)].name))==-1){char e[500];sprintf(e,"Not declared Variable: %s!",(yyvsp[(1) - (1)].name));yyerror(e);}(yyval.attr)=&ts[nts];nts++;sprintf((yyval.attr)->name,"%s",(yyvsp[(1) - (1)].name));;}
    break;

  case 23:
#line 114 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;char t[5];sprintf((yyval.attr)->name,"t%d",tmpVal);tmpVal++;char c[2000];sprintf(c,"%s = call %s, %d",(yyval.attr)->name,(yyvsp[(1) - (1)].attr)->name,params);genCodes(c);params=0;;}
    break;

  case 24:
#line 115 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;sprintf((yyval.attr)->name,"%s",(yyvsp[(1) - (1)].symp)->name);;}
    break;

  case 25:
#line 116 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;sprintf((yyval.attr)->name,"%s",(yyvsp[(1) - (1)].symp)->name);;}
    break;

  case 26:
#line 117 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;(yyval.attr)->trueList[(yyval.attr)->tTop]=nextinstr;((yyval.attr)->tTop)++;genCodes("goto ");;}
    break;

  case 27:
#line 118 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;(yyval.attr)->falseList[(yyval.attr)->fTop]=nextinstr;((yyval.attr)->fTop)++;genCodes("goto ");;}
    break;

  case 28:
#line 119 "parse.y"
    {;}
    break;

  case 29:
#line 123 "parse.y"
    {(yyval.instr)=nextinstr;;}
    break;

  case 30:
#line 127 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;(yyval.attr)->nextList[(yyval.attr)->nTop]=(yyvsp[(1) - (4)].instr);((yyval.attr)->nTop)++;;}
    break;

  case 31:
#line 128 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;assign((yyval.attr)->nextList,&((yyval.attr)->nTop),(yyvsp[(3) - (3)].attr)->nextList,(yyvsp[(3) - (3)].attr)->nTop);backPatch((yyvsp[(1) - (3)].attr)->nextList,(yyvsp[(1) - (3)].attr)->nTop-1,(yyvsp[(2) - (3)].instr));backPatch((yyvsp[(1) - (3)].attr)->falseList,(yyvsp[(1) - (3)].attr)->fTop-1,(yyvsp[(2) - (3)].instr));;}
    break;

  case 32:
#line 129 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;assign((yyval.attr)->nextList,&((yyval.attr)->nTop),(yyvsp[(3) - (3)].attr)->nextList,(yyvsp[(3) - (3)].attr)->nTop);backPatch((yyvsp[(1) - (3)].attr)->nextList,(yyvsp[(1) - (3)].attr)->nTop,(yyvsp[(2) - (3)].instr));;}
    break;

  case 33:
#line 130 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;assign((yyval.attr)->nextList,&((yyval.attr)->nTop),(yyvsp[(2) - (2)].attr)->nextList,(yyvsp[(2) - (2)].attr)->nTop);;}
    break;

  case 34:
#line 131 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;assign((yyval.attr)->nextList,&((yyval.attr)->nTop),(yyvsp[(2) - (2)].attr)->nextList,(yyvsp[(2) - (2)].attr)->nTop);;}
    break;

  case 35:
#line 132 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;assign((yyval.attr)->nextList,&((yyval.attr)->nTop),(yyvsp[(4) - (4)].attr)->nextList,(yyvsp[(4) - (4)].attr)->nTop);char c[300];sprintf(c,"return %s",(yyvsp[(2) - (4)].attr)->name);genCodes(c);;}
    break;

  case 36:
#line 133 "parse.y"
    {;}
    break;

  case 37:
#line 134 "parse.y"
    {;}
    break;

  case 38:
#line 135 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;(yyval.attr)->nextList[(yyval.attr)->nTop]=nextinstr;((yyval.attr)->nTop)++;;}
    break;

  case 39:
#line 138 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;assign((yyval.attr)->nextList,&((yyval.attr)->nTop),(yyvsp[(2) - (3)].attr)->nextList,(yyvsp[(2) - (3)].attr)->nTop);;}
    break;

  case 40:
#line 141 "parse.y"
    {symInsert((yyvsp[(2) - (2)].name),"func",0);pushTable((yyvsp[(2) - (2)].name));char c[300];sprintf(c,"%s:",(yyvsp[(2) - (2)].name));genCodes(c);;}
    break;

  case 41:
#line 141 "parse.y"
    {popTable();;}
    break;

  case 42:
#line 144 "parse.y"
    {symInsert((yyvsp[(3) - (3)].name),(yyvsp[(2) - (3)].name),0);;}
    break;

  case 43:
#line 145 "parse.y"
    {;}
    break;

  case 44:
#line 148 "parse.y"
    {symInsert((yyvsp[(3) - (4)].name),(yyvsp[(2) - (4)].name),0);;}
    break;

  case 45:
#line 149 "parse.y"
    {;}
    break;

  case 46:
#line 152 "parse.y"
    {params=0;;}
    break;

  case 47:
#line 152 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;if (symlook((yyvsp[(1) - (5)].name))==-1){yyerror("function is not declared");}sprintf((yyval.attr)->name,"%s",(yyvsp[(1) - (5)].name));;}
    break;

  case 48:
#line 155 "parse.y"
    {params++;char c[300];sprintf(c,"param %s",(yyvsp[(1) - (2)].attr)->name);genCodes(c);;}
    break;

  case 49:
#line 156 "parse.y"
    {;}
    break;

  case 50:
#line 159 "parse.y"
    {params++;char c[300];sprintf(c,"param %s",(yyvsp[(2) - (3)].attr)->name);genCodes(c);;}
    break;

  case 51:
#line 160 "parse.y"
    {;}
    break;

  case 52:
#line 164 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;backPatch((yyvsp[(4) - (7)].attr)->trueList,(yyvsp[(4) - (7)].attr)->tTop,(yyvsp[(6) - (7)].instr));assign((yyval.attr)->nextList,&((yyval.attr)->nTop),(yyvsp[(4) - (7)].attr)->falseList,(yyvsp[(4) - (7)].attr)->fTop);char c[500];sprintf(c,"goto %d",(yyvsp[(2) - (7)].instr));genCodes(c);;}
    break;

  case 53:
#line 167 "parse.y"
    {;}
    break;

  case 54:
#line 170 "parse.y"
    {;}
    break;

  case 55:
#line 171 "parse.y"
    {;}
    break;

  case 56:
#line 174 "parse.y"
    {;}
    break;

  case 57:
#line 175 "parse.y"
    {;}
    break;

  case 58:
#line 178 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;backPatch((yyvsp[(3) - (10)].attr)->trueList,(yyvsp[(3) - (10)].attr)->tTop,(yyvsp[(5) - (10)].instr));backPatch((yyvsp[(3) - (10)].attr)->falseList,(yyvsp[(3) - (10)].attr)->fTop,(yyvsp[(9) - (10)].instr));struct translate tmp;merge(tmp.nextList,&(tmp.nTop),(yyvsp[(6) - (10)].attr)->nextList,(yyvsp[(6) - (10)].attr)->nTop,(yyvsp[(7) - (10)].attr)->nextList,(yyvsp[(7) - (10)].attr)->nTop);merge((yyval.attr)->nextList,&((yyval.attr)->nTop),tmp.nextList,tmp.nTop,(yyvsp[(10) - (10)].attr)->nextList,(yyvsp[(10) - (10)].attr)->nTop);;}
    break;

  case 59:
#line 179 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;backPatch((yyvsp[(3) - (6)].attr)->trueList,(yyvsp[(3) - (6)].attr)->tTop,(yyvsp[(5) - (6)].instr));merge((yyval.attr)->nextList,&((yyval.attr)->nTop),(yyvsp[(3) - (6)].attr)->falseList,(yyvsp[(3) - (6)].attr)->fTop,(yyvsp[(6) - (6)].attr)->nextList,(yyvsp[(6) - (6)].attr)->nTop);;}
    break;

  case 60:
#line 182 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;(yyval.attr)->trueList[(yyval.attr)->tTop]=nextinstr;((yyval.attr)->tTop)++;genCodes("goto ");;}
    break;

  case 61:
#line 185 "parse.y"
    {(yyval.attr)=&ts[nts];nts++;assign((yyval.attr)->nextList,&((yyval.attr)->nTop),(yyvsp[(1) - (1)].attr)->nextList,(yyvsp[(1) - (1)].attr)->nTop);;}
    break;

  case 62:
#line 186 "parse.y"
    {;}
    break;

  case 63:
#line 187 "parse.y"
    {;}
    break;

  case 65:
#line 193 "parse.y"
    {symInsert((yyvsp[(3) - (3)].name),sTables[nowTable].sym[sTables[nowTable].top-1].type,0);;}
    break;

  case 66:
#line 194 "parse.y"
    {symInsert((yyvsp[(2) - (2)].name),(yyvsp[(1) - (2)].name),0);;}
    break;


/* Line 1267 of yacc.c.  */
#line 1887 "parse.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 197 "parse.y"


void yyerror(const char* msg) {
        printf("At %d line,an error has been checked\n",numLines);
        printf("%s\n",msg);
        exit(1);
}
//根据name在当前符号表和之前的符号表中查找符号,返回下标
int symlook(char *name)
{
    int now = nowTable;
    while(now!=-1){
        for (int j=0;j<sTables[now].top;j++){
            if (!strcmp(sTables[now].sym[j].name, name))
            {
                return j;
            }
        }
        now = sTables[now].pre;
    }
    return -1;
}
//根据name在当前符号表中查找符号,返回下标
int symLookNow(char *name){
    for (int j=0;j<sTables[nowTable].top;j++)
        if (!strcmp(sTables[nowTable].sym[j].name, name))
        {
            return j;
        }
    return -1;
}
//符号表入栈
void pushTable(char *name){
    int tmp;
    if (nowTable==200){
        yyerror("symbol tables stack is full!\n");
    }else{
        maxTable++;
        tmp = nowTable;
        nowTable = maxTable;
        sTables[nowTable].top = 0;
        sTables[nowTable].pre = tmp;
        sprintf(sTables[nowTable].name,"%s",name);
    }
}
//符号表出栈
void popTable(){
    nowTable = sTables[nowTable].pre;
}
//在当前符号表中插入符号
struct symbol *symInsert(char *name,char *type,double value)
{
    if (sTables[nowTable].top==201){
        return NULL;
    }
    int p = symLookNow(name);
    if (p==-1){//当前符号表中不存在这个符号
        sprintf(sTables[nowTable].sym[sTables[nowTable].top].name,"%s",name);
        sprintf(sTables[nowTable].sym[sTables[nowTable].top].type,"%s",type);
        sTables[nowTable].sym[sTables[nowTable].top].value = value;
        sTables[nowTable].top++;
        return &(sTables[nowTable].sym[sTables[nowTable].top-1]);
    }else{
        return &(sTables[nowTable].sym[p]);
    }
    return NULL;
}
//更新符号表(name,type,value)
void symUpdate(char *name,char *type,double value)
{
    int p;
    p = symlook(name);
    if (p!=-1){//符号表中存在这个符号
        sprintf(sTables[nowTable].sym[p].name,"%s",name);
        sprintf(sTables[nowTable].sym[p].type,"%s",type);
        sTables[nowTable].sym[p].value = value;
        return;
    }
    yyerror("symbol not existed");
    return;
}
//生成中间代码，编号,三地址指令
void genCodes(char* code){
    IntermediateLanguage[ncodes].no = nextinstr;
    sprintf(IntermediateLanguage[ncodes].sentence,"%s",code);
    nextinstr++;
    ncodes++;
}
//回填,把链表的区域值填成m
void backPatch(int *b,int n,int m){
    for (int i=0;i<n;i++){
        for (int j=0;j<ncodes;j++){
            if (IntermediateLanguage[j].no == *(b+i)){
                sprintf(IntermediateLanguage[j].sentence,"%s%d",IntermediateLanguage[j].sentence,m);
                break;
            }
        }
    }
}
//合并,将链表b和链表c合并成新的链表a
void merge(int *a,int *na,int *b,int nb,int *c,int nc){
    int i=0;
    int j=0;
    while (i<nb){
        *(a+*na) = *(b+i);
        (*na)++;
        i++;
    }
     while (j<nc){
        *(a+*na) = *(c+j);
        (*na)++;
        j++;
    }
}
//赋值,将链表b的值copy到链表a
void assign(int *a,int *na,int *b,int nb){
    int i=0;
    while (i<nb){
        *(a+*na) = *(b+i);
        (*na)++;
        i++;
    }
}

int main(int argc,char *argv[]) {
    //初始化翻译三地址代码表和符号表
    for(int i=0;i<1000;i++){
        ts[i].tTop=0;
        ts[i].fTop=0;
        ts[i].nTop=0;
    }
     for(int i=0;i<200;i++){
        sTables[i].top=0;
        sTables[i].pre=-1;
    }
    sTables[nowTable].top = 0;
    sprintf(sTables[nowTable].name,"%s","global");
    symInsert("Print","func",0);
    //词法分析和语法分析，中间代码生成
    if (argc==2){
            yyin=fopen(argv[1],"r");
    }
    int result = yyparse();
    //打印符号表
    printSym();
    //打印中间代码
    printf("the intermediate language:\n");
    for (int i=0;i<ncodes;i++){
        printf("%d: %s\n",IntermediateLanguage[i].no,IntermediateLanguage[i].sentence);
    }
    return result;
}
//打印所有符号表中的所有符号的信息
void printSym(){
    for (int i=0;i<=maxTable;i++){
        printf("symbol table of %s:\n",sTables[i].name);
        printf("No. %d  pre: %d\n",i,sTables[i].pre);
        for (int j=0;j<sTables[i].top;j++)
            printf("%-15s%-15s%-15lf\n",sTables[i].sym[j].name,sTables[i].sym[j].type,sTables[i].sym[j].value);
        printf("*****************************************\n\n");
    }
}

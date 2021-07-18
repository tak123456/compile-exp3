/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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
/* Line 1529 of yacc.c.  */
#line 140 "parse.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


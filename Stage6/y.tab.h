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
    begin = 258,                   /* begin  */
    end = 259,                     /* end  */
    READ = 260,                    /* READ  */
    WRITE = 261,                   /* WRITE  */
    GE = 262,                      /* GE  */
    LE = 263,                      /* LE  */
    EQ = 264,                      /* EQ  */
    NEQ = 265,                     /* NEQ  */
    AND = 266,                     /* AND  */
    OR = 267,                      /* OR  */
    IF = 268,                      /* IF  */
    Else = 269,                    /* Else  */
    WHILE = 270,                   /* WHILE  */
    DO = 271,                      /* DO  */
    BREAK = 272,                   /* BREAK  */
    CONTINUE = 273,                /* CONTINUE  */
    REPEAT = 274,                  /* REPEAT  */
    UNTIL = 275,                   /* UNTIL  */
    VOID = 276,                    /* VOID  */
    DECL = 277,                    /* DECL  */
    ENDDECL = 278,                 /* ENDDECL  */
    RETURN = 279,                  /* RETURN  */
    TYPE = 280,                    /* TYPE  */
    ENDTYPE = 281,                 /* ENDTYPE  */
    MALLOC = 282,                  /* MALLOC  */
    ARROW = 283,                   /* ARROW  */
    Null = 284,                    /* Null  */
    NUM = 285,                     /* NUM  */
    ID = 286,                      /* ID  */
    LITERAL = 287,                 /* LITERAL  */
    MAIN = 288                     /* MAIN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define begin 258
#define end 259
#define READ 260
#define WRITE 261
#define GE 262
#define LE 263
#define EQ 264
#define NEQ 265
#define AND 266
#define OR 267
#define IF 268
#define Else 269
#define WHILE 270
#define DO 271
#define BREAK 272
#define CONTINUE 273
#define REPEAT 274
#define UNTIL 275
#define VOID 276
#define DECL 277
#define ENDDECL 278
#define RETURN 279
#define TYPE 280
#define ENDTYPE 281
#define MALLOC 282
#define ARROW 283
#define Null 284
#define NUM 285
#define ID 286
#define LITERAL 287
#define MAIN 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 51 "main.y"

    int Int;
    char Char;
    struct node* nodePtr;
    char* String;
    struct Lnode* listPtr;
    struct Fieldlist* fieldPtr;
    struct Typetable* typePtr;
    struct typeCapsule* typeCapsule;

#line 144 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

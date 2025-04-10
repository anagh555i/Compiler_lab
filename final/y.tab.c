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
#line 1 "main.y"

    #include<stdio.h>
    #include<stdlib.h>
    #include<stdbool.h>
    #include<string.h>
    #include "tree.h"
    #include "codeGen.h"

    // forbidden type for paramteres

    extern FILE *yyin;
    void yyerror(char* s);
    extern int yylex();
    extern int printLineNo();
    extern int yylineno;
    extern char *yytext;
    void installFunction(node* f);
    void functionPreperation(Gsymbol *funct);
    void methodPreperation(Methodlist* method);
    bool isArithmetic(node* left, node* right);
    bool isBoolean(node* left, node* right);
    void prerequisites();
    void installDefaultTypes();
    void installVirtualFunctionTable();
    void printTypes();

    // void debug(int i);

    node* root;          // AST root;
    Gsymbol* Ghead=NULL; // global symbol table head
    Lsymbol* Lhead=NULL; // global symbol table head
    Gsymbol* currFunction=NULL; // current function global symbol entry which is used in codeGen();
    Methodlist* currMethod=NULL; // current function global symbol entry which is used in codeGen();
    Typetable* Types=NULL; // type table for the program;
    Typetable* Classes=NULL; // class table for the program;
    Fieldlist* Fields=NULL; // field list for the program;
    int paramCount=0;

    Typetable* POINTERTYPE=NULL;
    Typetable* VOIDTYPE=NULL;
    Typetable* INTTYPE=NULL;
    Typetable* STRINGTYPE=NULL;
    Typetable* ARRAYTYPE=NULL;
    Typetable* BOOLTYPE=NULL;

    FILE* outFile;
    int currReg;

    int classCount=0;
    int space=0;
    int varBase=4096;
    int SP=4096;
    int label=0;
    int flabel=1;
    int mlabel=1; 
    int vFunctTableStart=0;
    int WHILELABELS[]={-1,-1};// new list based while labels storage required
    Lnode* breakLabels=NULL;
    Lnode* continueLabels=NULL;
    node* functions=NULL;

#line 133 "y.tab.c"

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
    CLASS = 282,                   /* CLASS  */
    ENDCLASS = 283,                /* ENDCLASS  */
    MALLOC = 284,                  /* MALLOC  */
    ARROW = 285,                   /* ARROW  */
    Null = 286,                    /* Null  */
    EXTENDS = 287,                 /* EXTENDS  */
    METHODBEGIN = 288,             /* METHODBEGIN  */
    NEW = 289,                     /* NEW  */
    THIS = 290,                    /* THIS  */
    NUM = 291,                     /* NUM  */
    ID = 292,                      /* ID  */
    LITERAL = 293,                 /* LITERAL  */
    MAIN = 294                     /* MAIN  */
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
#define CLASS 282
#define ENDCLASS 283
#define MALLOC 284
#define ARROW 285
#define Null 286
#define EXTENDS 287
#define METHODBEGIN 288
#define NEW 289
#define THIS 290
#define NUM 291
#define ID 292
#define LITERAL 293
#define MAIN 294

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 64 "main.y"

    int Int;
    char Char;
    struct node* nodePtr;
    char* String;
    struct Lnode* listPtr;
    struct Fieldlist* fieldPtr;
    struct Typetable* typePtr;
    struct typeCapsule* typeCapsule;

#line 275 "y.tab.c"

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
  YYSYMBOL_begin = 3,                      /* begin  */
  YYSYMBOL_end = 4,                        /* end  */
  YYSYMBOL_READ = 5,                       /* READ  */
  YYSYMBOL_WRITE = 6,                      /* WRITE  */
  YYSYMBOL_GE = 7,                         /* GE  */
  YYSYMBOL_LE = 8,                         /* LE  */
  YYSYMBOL_EQ = 9,                         /* EQ  */
  YYSYMBOL_NEQ = 10,                       /* NEQ  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_OR = 12,                        /* OR  */
  YYSYMBOL_IF = 13,                        /* IF  */
  YYSYMBOL_Else = 14,                      /* Else  */
  YYSYMBOL_WHILE = 15,                     /* WHILE  */
  YYSYMBOL_DO = 16,                        /* DO  */
  YYSYMBOL_BREAK = 17,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 18,                  /* CONTINUE  */
  YYSYMBOL_REPEAT = 19,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 20,                     /* UNTIL  */
  YYSYMBOL_VOID = 21,                      /* VOID  */
  YYSYMBOL_DECL = 22,                      /* DECL  */
  YYSYMBOL_ENDDECL = 23,                   /* ENDDECL  */
  YYSYMBOL_RETURN = 24,                    /* RETURN  */
  YYSYMBOL_TYPE = 25,                      /* TYPE  */
  YYSYMBOL_ENDTYPE = 26,                   /* ENDTYPE  */
  YYSYMBOL_CLASS = 27,                     /* CLASS  */
  YYSYMBOL_ENDCLASS = 28,                  /* ENDCLASS  */
  YYSYMBOL_MALLOC = 29,                    /* MALLOC  */
  YYSYMBOL_ARROW = 30,                     /* ARROW  */
  YYSYMBOL_Null = 31,                      /* Null  */
  YYSYMBOL_EXTENDS = 32,                   /* EXTENDS  */
  YYSYMBOL_METHODBEGIN = 33,               /* METHODBEGIN  */
  YYSYMBOL_NEW = 34,                       /* NEW  */
  YYSYMBOL_THIS = 35,                      /* THIS  */
  YYSYMBOL_NUM = 36,                       /* NUM  */
  YYSYMBOL_ID = 37,                        /* ID  */
  YYSYMBOL_LITERAL = 38,                   /* LITERAL  */
  YYSYMBOL_MAIN = 39,                      /* MAIN  */
  YYSYMBOL_40_ = 40,                       /* '<'  */
  YYSYMBOL_41_ = 41,                       /* '>'  */
  YYSYMBOL_42_ = 42,                       /* '+'  */
  YYSYMBOL_43_ = 43,                       /* '-'  */
  YYSYMBOL_44_ = 44,                       /* '*'  */
  YYSYMBOL_45_ = 45,                       /* '/'  */
  YYSYMBOL_46_ = 46,                       /* '%'  */
  YYSYMBOL_47_ = 47,                       /* '{'  */
  YYSYMBOL_48_ = 48,                       /* '}'  */
  YYSYMBOL_49_ = 49,                       /* '('  */
  YYSYMBOL_50_ = 50,                       /* ')'  */
  YYSYMBOL_51_ = 51,                       /* ';'  */
  YYSYMBOL_52_ = 52,                       /* '['  */
  YYSYMBOL_53_ = 53,                       /* ']'  */
  YYSYMBOL_54_ = 54,                       /* ','  */
  YYSYMBOL_55_ = 55,                       /* '='  */
  YYSYMBOL_56_ = 56,                       /* '&'  */
  YYSYMBOL_57_ = 57,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_sourceCode = 59,                /* sourceCode  */
  YYSYMBOL_ClassDefBlock = 60,             /* ClassDefBlock  */
  YYSYMBOL_ClassDefList = 61,              /* ClassDefList  */
  YYSYMBOL_ClassDef = 62,                  /* ClassDef  */
  YYSYMBOL_ClassField = 63,                /* ClassField  */
  YYSYMBOL_Cname = 64,                     /* Cname  */
  YYSYMBOL_MethodDefns = 65,               /* MethodDefns  */
  YYSYMBOL_Mdef = 66,                      /* Mdef  */
  YYSYMBOL_TypeDeclarations = 67,          /* TypeDeclarations  */
  YYSYMBOL_Typedefs = 68,                  /* Typedefs  */
  YYSYMBOL_Typedef = 69,                   /* Typedef  */
  YYSYMBOL_FieldList = 70,                 /* FieldList  */
  YYSYMBOL_Field = 71,                     /* Field  */
  YYSYMBOL_GDelcarations = 72,             /* GDelcarations  */
  YYSYMBOL_GDecList = 73,                  /* GDecList  */
  YYSYMBOL_ArrList = 74,                   /* ArrList  */
  YYSYMBOL_GDecl = 75,                     /* GDecl  */
  YYSYMBOL_VarList = 76,                   /* VarList  */
  YYSYMBOL_ParamList = 77,                 /* ParamList  */
  YYSYMBOL_Param = 78,                     /* Param  */
  YYSYMBOL_VarType = 79,                   /* VarType  */
  YYSYMBOL_FDefBlock = 80,                 /* FDefBlock  */
  YYSYMBOL_Fdef = 81,                      /* Fdef  */
  YYSYMBOL_MainBlock = 82,                 /* MainBlock  */
  YYSYMBOL_LdeclBlock = 83,                /* LdeclBlock  */
  YYSYMBOL_LDecList = 84,                  /* LDecList  */
  YYSYMBOL_LDecl = 85,                     /* LDecl  */
  YYSYMBOL_IdList = 86,                    /* IdList  */
  YYSYMBOL_Body = 87,                      /* Body  */
  YYSYMBOL_Slist = 88,                     /* Slist  */
  YYSYMBOL_Stmt = 89,                      /* Stmt  */
  YYSYMBOL_ReturnStmt = 90,                /* ReturnStmt  */
  YYSYMBOL_LoopStmt = 91,                  /* LoopStmt  */
  YYSYMBOL_Ifstmt = 92,                    /* Ifstmt  */
  YYSYMBOL_InputStmt = 93,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 94,                /* OutputStmt  */
  YYSYMBOL_AssgStmt = 95,                  /* AssgStmt  */
  YYSYMBOL_Array = 96,                     /* Array  */
  YYSYMBOL_Expr = 97,                      /* Expr  */
  YYSYMBOL_Var = 98,                       /* Var  */
  YYSYMBOL_ArgList = 99                    /* ArgList  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   732

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  122
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  296

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
       2,     2,     2,     2,     2,     2,     2,    46,    56,     2,
      49,    50,    44,    42,    54,    43,    57,    45,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
      40,    55,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    53,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   165,   165,   166,   167,   168,   170,   171,   173,   174,
     176,   180,   211,   213,   222,   239,   240,   242,   262,   263,
     265,   266,   268,   289,   297,   299,   303,   310,   311,   313,
     314,   316,   317,   319,   337,   354,   362,   372,   373,   374,
     375,   378,   379,   380,   382,   389,   397,   402,   407,   408,
     411,   436,   464,   478,   479,   480,   482,   483,   485,   499,
     500,   501,   502,   506,   507,   509,   510,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   522,   523,   525,   526,
     527,   529,   530,   532,   540,   542,   548,   554,   567,   572,
     575,   576,   577,   578,   579,   580,   581,   582,   583,   584,
     585,   586,   587,   588,   589,   604,   611,   612,   613,   619,
     623,   648,   694,   697,   711,   717,   721,   726,   730,   744,
     757,   769,   773
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
  "\"end of file\"", "error", "\"invalid token\"", "begin", "end", "READ",
  "WRITE", "GE", "LE", "EQ", "NEQ", "AND", "OR", "IF", "Else", "WHILE",
  "DO", "BREAK", "CONTINUE", "REPEAT", "UNTIL", "VOID", "DECL", "ENDDECL",
  "RETURN", "TYPE", "ENDTYPE", "CLASS", "ENDCLASS", "MALLOC", "ARROW",
  "Null", "EXTENDS", "METHODBEGIN", "NEW", "THIS", "NUM", "ID", "LITERAL",
  "MAIN", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'{'", "'}'",
  "'('", "')'", "';'", "'['", "']'", "','", "'='", "'&'", "'.'", "$accept",
  "sourceCode", "ClassDefBlock", "ClassDefList", "ClassDef", "ClassField",
  "Cname", "MethodDefns", "Mdef", "TypeDeclarations", "Typedefs",
  "Typedef", "FieldList", "Field", "GDelcarations", "GDecList", "ArrList",
  "GDecl", "VarList", "ParamList", "Param", "VarType", "FDefBlock", "Fdef",
  "MainBlock", "LdeclBlock", "LDecList", "LDecl", "IdList", "Body",
  "Slist", "Stmt", "ReturnStmt", "LoopStmt", "Ifstmt", "InputStmt",
  "OutputStmt", "AssgStmt", "Array", "Expr", "Var", "ArgList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-241)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     173,    19,     6,    85,   107,   133,  -241,   114,   111,  -241,
     167,    69,  -241,   138,  -241,   113,   120,   107,   169,  -241,
    -241,   170,  -241,  -241,   169,  -241,  -241,  -241,   189,   146,
     -27,   184,    98,   120,  -241,  -241,   120,   112,   176,   169,
    -241,   192,  -241,  -241,  -241,   156,   191,   179,   177,   182,
     196,  -241,  -241,   120,  -241,   186,   201,  -241,  -241,   146,
     146,   203,   136,   193,    44,  -241,   190,   146,   194,  -241,
    -241,   199,   197,   146,   214,   202,   209,   142,   200,   210,
     218,  -241,  -241,   146,   136,   219,   207,   146,  -241,  -241,
    -241,   216,   217,   146,  -241,   232,   221,   222,   220,  -241,
     249,   228,   233,   146,  -241,  -241,  -241,  -241,   227,   155,
     279,   249,   237,   235,  -241,  -241,   144,   265,   146,   378,
     241,   279,   249,   248,   236,   259,   246,  -241,  -241,   251,
     253,   260,   261,   264,   247,   257,   266,   676,   267,  -241,
     269,  -241,    78,  -241,   278,   283,   676,   283,   378,  -241,
     270,  -241,  -241,   272,   276,   277,   421,   -16,  -241,   281,
     279,   249,   144,   280,  -241,   293,   676,   676,   676,   378,
    -241,  -241,   378,    78,   283,   565,    -5,   146,   146,   642,
     676,   285,  -241,  -241,     2,   433,    74,  -241,   282,   311,
    -241,  -241,  -241,   676,   676,   676,   676,   676,   676,   676,
     676,   676,   676,   676,   676,   676,  -241,   298,   676,   304,
    -241,   294,   279,  -241,   144,   295,   444,   488,   499,   153,
     292,   198,  -241,    74,   297,   303,  -241,    72,   305,    79,
     676,   317,   676,  -241,   352,  -241,   593,   101,   393,   404,
     579,   572,   619,   624,   175,   149,   -24,   312,  -241,   310,
     565,  -241,  -241,   313,  -241,  -241,  -241,   316,   318,   345,
    -241,   346,  -241,  -241,   676,  -241,   320,   565,  -241,   565,
    -241,   659,  -241,   378,   378,   319,   324,  -241,  -241,  -241,
     325,   243,   288,   676,   676,  -241,   360,  -241,   510,   554,
     331,  -241,  -241,   378,   333,  -241
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       7,     0,     0,     0,     0,     7,    19,     0,     0,    21,
      13,     0,     9,     0,     1,     0,     0,     0,     0,    18,
      20,     0,     6,     8,    12,    47,    28,    46,     0,    30,
       0,    47,     0,     0,    49,     4,     0,     0,     0,    24,
      14,     0,    11,    27,    29,    39,     0,     0,     0,     0,
       0,    48,     5,     0,     3,     0,     0,    22,    23,    16,
      43,     0,     0,     0,    40,    33,     0,    43,     0,     2,
      25,     0,     0,    16,     0,     0,    42,     0,     0,    39,
       0,    37,    34,    43,     0,     0,     0,    43,    26,    10,
      15,     0,     0,    43,    44,     0,    32,    40,     0,    38,
      55,     0,     0,    43,    35,    41,    45,    31,     0,     0,
       0,    55,     0,     0,    36,    54,     0,     0,    57,     0,
       0,     0,    55,     0,    61,     0,     0,    53,    56,     0,
       0,     0,     0,     0,     0,     0,     0,    77,     0,   117,
       0,   106,   120,   108,     0,     0,     0,     0,     0,    66,
       0,    73,    72,     0,     0,     0,     0,   109,    52,     0,
       0,    55,     0,    62,    58,     0,     0,     0,     0,     0,
      74,    75,     0,   120,     0,    76,   109,     0,     0,     0,
       0,   114,   107,   120,   113,     0,   112,    65,     0,    71,
      67,    68,    70,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    69,     0,     0,     0,
      50,     0,     0,    59,     0,     0,     0,     0,     0,     0,
       0,     0,   114,   113,     0,     0,   105,   122,     0,     0,
       0,     0,     0,   103,    71,    64,    97,    98,    99,   100,
     101,   102,    96,    95,    90,    91,    92,    93,    94,   119,
      85,   118,    51,     0,    60,    83,    84,     0,     0,     0,
      71,     0,   115,   116,     0,   104,    89,    87,   119,    86,
      63,     0,    17,     0,     0,     0,     0,   121,    88,   111,
       0,     0,     0,     0,     0,   110,    82,    78,     0,     0,
       0,    79,    80,     0,     0,    81
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -241,  -241,   374,  -241,   369,  -241,  -241,   314,  -241,  -241,
    -241,   377,    68,  -241,   371,   357,   296,  -241,   -51,   -49,
    -241,   -13,   354,    42,    -6,  -103,   286,  -241,  -153,  -109,
    -165,  -143,  -106,  -241,  -241,  -241,  -241,  -241,  -172,  -131,
    -119,  -240
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,    11,    12,    41,    13,    72,    73,     5,
       8,     9,    38,    39,    16,    28,    63,    29,    47,    75,
      76,    77,    33,    34,    35,   110,   117,   118,   126,   120,
     148,   149,   220,   151,   152,   153,   154,   155,   181,   156,
     176,   228
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     157,   222,    30,    32,   219,   187,   175,   221,   121,   213,
      45,    81,   159,   150,   207,   185,    30,    46,    86,   160,
      32,   204,   205,    32,   277,   207,   184,    52,   186,   157,
      54,   280,   231,    99,    98,   216,   217,   218,   102,   208,
      32,   209,   188,    10,   105,     6,    74,    69,   227,   229,
     157,   211,   209,   157,   113,   223,     7,   232,   212,   209,
      74,   254,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,    51,   187,   250,   187,   193,
     194,   195,   196,   197,   198,    14,   193,   194,   195,   196,
     197,   198,    42,    83,   278,    51,   116,    22,    84,   267,
     157,   269,   157,   253,   231,   116,    10,    58,   281,   282,
     195,   196,   199,   200,   201,   202,   203,   204,   205,   199,
     200,   201,   202,   203,   204,   205,   264,   179,   294,    15,
     180,   209,   266,   227,    25,    49,    26,    19,   187,   187,
     227,    31,    50,   201,   202,   203,   204,   205,     7,    55,
      27,   187,   288,   289,   157,   157,    56,    27,   129,   130,
       2,    18,   157,   157,   224,   225,   131,    25,   132,   133,
     134,   135,   136,    79,   157,   157,    25,   137,   115,    94,
      80,   124,   138,    27,   139,    24,    95,   140,   125,   141,
     142,   143,    27,   203,   204,   205,   144,   145,     1,    21,
       2,   259,   146,   129,   130,    60,    37,    40,    61,   147,
      62,   131,    43,   132,   133,   134,   135,   136,   202,   203,
     204,   205,   137,    48,    57,    59,    66,   138,    64,   139,
      65,    67,   140,    68,   141,   142,   143,    70,    71,    78,
      85,   144,   145,    87,    82,    89,   261,   146,   129,   130,
      88,    91,    92,    96,   147,    97,   131,   101,   132,   133,
     134,   135,   136,    93,    62,   103,   100,   137,   104,   106,
     108,   109,   138,    61,   139,   111,    84,   140,   114,   141,
     142,   143,   119,   112,   122,   123,   144,   145,   127,   158,
     162,   286,   146,   129,   130,   161,   163,   164,   170,   147,
     165,   131,   166,   132,   133,   134,   135,   136,   171,   167,
     168,   169,   137,   172,   182,   235,   177,   138,   178,   139,
     183,   189,   140,   190,   141,   142,   143,   191,   192,   210,
     215,   144,   145,   234,   214,   249,   287,   146,   129,   130,
     230,   251,   252,   260,   147,   255,   131,   262,   132,   133,
     134,   135,   136,   263,   268,   265,   270,   137,   205,   271,
     275,   272,   138,   273,   139,   274,   276,   140,   283,   141,
     142,   143,   180,   284,   290,   285,   144,   145,   293,    17,
      23,   295,   146,   129,   130,    20,    44,    90,    36,   147,
      53,   131,   107,   132,   133,   134,   135,   136,     0,     0,
       0,     0,   137,   196,   128,     0,     0,   138,     0,   139,
       0,     0,   140,     0,   141,   142,   143,     0,     0,     0,
       0,   144,   145,     0,     0,     0,     0,   146,   193,   194,
     195,   196,   197,   198,   147,   201,   202,   203,   204,   205,
     193,   194,   195,   196,   197,   198,   201,   202,   203,   204,
     205,   193,   194,   195,   196,   197,   198,     0,     0,     0,
       0,   199,   200,   201,   202,   203,   204,   205,     0,     0,
       0,     0,   206,   199,   200,   201,   202,   203,   204,   205,
       0,     0,     0,   233,   199,   200,   201,   202,   203,   204,
     205,     0,     0,     0,   256,   193,   194,   195,   196,   197,
     198,     0,     0,     0,     0,     0,   193,   194,   195,   196,
     197,   198,     0,     0,     0,     0,     0,   193,   194,   195,
     196,   197,   198,     0,     0,     0,     0,     0,   199,   200,
     201,   202,   203,   204,   205,     0,     0,     0,   257,   199,
     200,   201,   202,   203,   204,   205,     0,     0,     0,   258,
     199,   200,   201,   202,   203,   204,   205,     0,     0,     0,
     291,   193,   194,   195,   196,   197,   198,     0,     0,     0,
       0,     0,   193,   194,   195,   196,   197,   198,     0,   193,
     194,   195,   196,   197,     0,     0,   193,   194,   195,   196,
       0,     0,     0,     0,   199,   200,   201,   202,   203,   204,
     205,   194,   195,   196,   292,   199,   200,   201,   202,   203,
     204,   205,   199,   200,   201,   202,   203,   204,   205,   199,
     200,   201,   202,   203,   204,   205,   193,   194,   195,   196,
       0,   193,   194,   195,   196,   201,   202,   203,   204,   205,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     200,   201,   202,   203,   204,   205,   201,   202,   203,   204,
     205,   138,     0,   139,     0,     0,   140,     0,   141,   173,
     143,     0,     0,     0,     0,   144,   174,     0,   138,     0,
     139,   146,   226,   140,     0,   141,   173,   143,   147,     0,
       0,     0,   144,   174,     0,   138,     0,   139,   146,   279,
     140,     0,   141,   173,   143,   147,     0,     0,     0,   144,
     174,     0,     0,     0,     0,   146,     0,     0,     0,     0,
       0,     0,   147
};

static const yytype_int16 yycheck[] =
{
     119,   173,    15,    16,   169,   148,   137,   172,   111,   162,
      37,    62,   121,   119,    30,   146,    29,    44,    67,   122,
      33,    45,    46,    36,   264,    30,   145,    33,   147,   148,
      36,   271,    30,    84,    83,   166,   167,   168,    87,    55,
      53,    57,   148,    37,    93,    26,    59,    53,   179,   180,
     169,   160,    57,   172,   103,   174,    37,    55,   161,    57,
      73,   214,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,    33,   219,   208,   221,     7,
       8,     9,    10,    11,    12,     0,     7,     8,     9,    10,
      11,    12,    24,    49,   266,    53,   109,    28,    54,   230,
     219,   232,   221,   212,    30,   118,    37,    39,   273,   274,
       9,    10,    40,    41,    42,    43,    44,    45,    46,    40,
      41,    42,    43,    44,    45,    46,    54,    49,   293,    22,
      52,    57,    53,   264,    21,    37,    23,    26,   281,   282,
     271,    21,    44,    42,    43,    44,    45,    46,    37,    37,
      37,   294,   283,   284,   273,   274,    44,    37,     5,     6,
      27,    47,   281,   282,   177,   178,    13,    21,    15,    16,
      17,    18,    19,    37,   293,   294,    21,    24,    23,    37,
      44,    37,    29,    37,    31,    47,    44,    34,    44,    36,
      37,    38,    37,    44,    45,    46,    43,    44,    25,    32,
      27,    48,    49,     5,     6,    49,    37,    37,    52,    56,
      54,    13,    23,    15,    16,    17,    18,    19,    43,    44,
      45,    46,    24,    39,    48,    33,    49,    29,    37,    31,
      51,    49,    34,    37,    36,    37,    38,    51,    37,    36,
      50,    43,    44,    49,    51,    48,    48,    49,     5,     6,
      51,    37,    50,    53,    56,    37,    13,    50,    15,    16,
      17,    18,    19,    54,    54,    49,    47,    24,    51,    37,
      50,    22,    29,    52,    31,    47,    54,    34,    51,    36,
      37,    38,     3,    50,    47,    50,    43,    44,    23,    48,
      54,    48,    49,     5,     6,    47,    37,    51,    51,    56,
      49,    13,    49,    15,    16,    17,    18,    19,    51,    49,
      49,    47,    24,    47,    36,     4,    49,    29,    49,    31,
      37,    51,    34,    51,    36,    37,    38,    51,    51,    48,
      37,    43,    44,    51,    54,    37,    48,    49,     5,     6,
      55,    37,    48,    51,    56,    50,    13,    50,    15,    16,
      17,    18,    19,    50,    37,    50,     4,    24,    46,    49,
      15,    48,    29,    47,    31,    47,    20,    34,    49,    36,
      37,    38,    52,    49,    14,    50,    43,    44,    47,     5,
      11,    48,    49,     5,     6,     8,    29,    73,    17,    56,
      36,    13,    96,    15,    16,    17,    18,    19,    -1,    -1,
      -1,    -1,    24,    10,   118,    -1,    -1,    29,    -1,    31,
      -1,    -1,    34,    -1,    36,    37,    38,    -1,    -1,    -1,
      -1,    43,    44,    -1,    -1,    -1,    -1,    49,     7,     8,
       9,    10,    11,    12,    56,    42,    43,    44,    45,    46,
       7,     8,     9,    10,    11,    12,    42,    43,    44,    45,
      46,     7,     8,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    40,    41,    42,    43,    44,    45,    46,    -1,    -1,
      -1,    -1,    51,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    50,    40,    41,    42,    43,    44,    45,
      46,    -1,    -1,    -1,    50,     7,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    -1,     7,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,     7,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    -1,    40,    41,
      42,    43,    44,    45,    46,    -1,    -1,    -1,    50,    40,
      41,    42,    43,    44,    45,    46,    -1,    -1,    -1,    50,
      40,    41,    42,    43,    44,    45,    46,    -1,    -1,    -1,
      50,     7,     8,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,     7,     8,     9,    10,    11,    12,    -1,     7,
       8,     9,    10,    11,    -1,    -1,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    40,    41,    42,    43,    44,    45,
      46,     8,     9,    10,    50,    40,    41,    42,    43,    44,
      45,    46,    40,    41,    42,    43,    44,    45,    46,    40,
      41,    42,    43,    44,    45,    46,     7,     8,     9,    10,
      -1,     7,     8,     9,    10,    42,    43,    44,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    42,    43,    44,    45,    46,    42,    43,    44,    45,
      46,    29,    -1,    31,    -1,    -1,    34,    -1,    36,    37,
      38,    -1,    -1,    -1,    -1,    43,    44,    -1,    29,    -1,
      31,    49,    50,    34,    -1,    36,    37,    38,    56,    -1,
      -1,    -1,    43,    44,    -1,    29,    -1,    31,    49,    50,
      34,    -1,    36,    37,    38,    56,    -1,    -1,    -1,    43,
      44,    -1,    -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,
      -1,    -1,    56
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    25,    27,    59,    60,    67,    26,    37,    68,    69,
      37,    61,    62,    64,     0,    22,    72,    60,    47,    26,
      69,    32,    28,    62,    47,    21,    23,    37,    73,    75,
      79,    21,    79,    80,    81,    82,    72,    37,    70,    71,
      37,    63,    70,    23,    73,    37,    44,    76,    39,    37,
      44,    81,    82,    80,    82,    37,    44,    48,    70,    33,
      49,    52,    54,    74,    37,    51,    49,    49,    37,    82,
      51,    37,    65,    66,    79,    77,    78,    79,    36,    37,
      44,    76,    51,    49,    54,    50,    77,    49,    51,    48,
      65,    37,    50,    54,    37,    44,    53,    37,    77,    76,
      47,    50,    77,    49,    51,    77,    37,    74,    50,    22,
      83,    47,    50,    77,    51,    23,    79,    84,    85,     3,
      87,    83,    47,    50,    37,    44,    86,    23,    84,     5,
       6,    13,    15,    16,    17,    18,    19,    24,    29,    31,
      34,    36,    37,    38,    43,    44,    49,    56,    88,    89,
      90,    91,    92,    93,    94,    95,    97,    98,    48,    87,
      83,    47,    54,    37,    51,    49,    49,    49,    49,    47,
      51,    51,    47,    37,    44,    97,    98,    49,    49,    49,
      52,    96,    36,    37,    98,    97,    98,    89,    90,    51,
      51,    51,    51,     7,     8,     9,    10,    11,    12,    40,
      41,    42,    43,    44,    45,    46,    51,    30,    55,    57,
      48,    87,    83,    86,    54,    37,    97,    97,    97,    88,
      90,    88,    96,    98,    79,    79,    50,    97,    99,    97,
      55,    30,    55,    50,    51,     4,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    37,
      97,    37,    48,    87,    86,    50,    50,    50,    50,    48,
      51,    48,    50,    50,    54,    50,    53,    97,    37,    97,
       4,    49,    48,    47,    47,    15,    20,    99,    96,    50,
      99,    88,    88,    49,    49,    50,    48,    48,    97,    97,
      14,    50,    50,    47,    88,    48
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    58,    59,    59,    59,    59,    60,    60,    61,    61,
      62,    63,    63,    64,    64,    65,    65,    66,    67,    67,
      68,    68,    69,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    74,    75,    75,    75,    75,    76,    76,    76,
      76,    77,    77,    77,    78,    78,    79,    79,    80,    80,
      81,    81,    82,    83,    83,    83,    84,    84,    85,    86,
      86,    86,    86,    87,    87,    88,    88,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    90,    90,    91,    91,
      91,    92,    92,    93,    94,    95,    95,    95,    96,    96,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    98,    98,
      98,    99,    99
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     4,     3,     0,     2,     1,
       6,     1,     0,     1,     3,     2,     0,     9,     3,     2,
       2,     1,     4,     2,     1,     3,     4,     3,     2,     2,
       1,     4,     3,     3,     4,     6,     7,     3,     4,     1,
       2,     3,     1,     0,     2,     3,     1,     1,     2,     1,
       9,    10,     8,     3,     2,     0,     2,     1,     3,     3,
       4,     1,     2,     5,     4,     2,     1,     2,     2,     2,
       2,     2,     1,     1,     2,     2,     2,     1,     7,     8,
       8,    11,     7,     4,     4,     3,     4,     4,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     1,     2,     1,     1,
       6,     5,     2,     2,     2,     4,     4,     1,     3,     3,
       1,     3,     1
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
  case 2: /* sourceCode: TypeDeclarations ClassDefBlock GDelcarations FDefBlock MainBlock  */
#line 165 "main.y"
                                                                                     {}
#line 1632 "y.tab.c"
    break;

  case 3: /* sourceCode: TypeDeclarations ClassDefBlock GDelcarations MainBlock  */
#line 166 "main.y"
                                                                           {}
#line 1638 "y.tab.c"
    break;

  case 4: /* sourceCode: ClassDefBlock GDelcarations MainBlock  */
#line 167 "main.y"
                                                          {}
#line 1644 "y.tab.c"
    break;

  case 5: /* sourceCode: ClassDefBlock GDelcarations FDefBlock MainBlock  */
#line 168 "main.y"
                                                                    {}
#line 1650 "y.tab.c"
    break;

  case 10: /* ClassDef: Cname '{' ClassField METHODBEGIN MethodDefns '}'  */
#line 176 "main.y"
                                                                     {
    Lhead=NULL;
}
#line 1658 "y.tab.c"
    break;

  case 11: /* ClassField: FieldList  */
#line 180 "main.y"
                                {
    Fieldlist* ptr=(yyvsp[0].fieldPtr);
    int size=1;
    Fieldlist* parentField=Classes->fields;
    for(;parentField && parentField->next;parentField=parentField->next){
        parentField->fieldIndex=size;
        size+=parentField->type->size;
    }
    if(parentField){
        parentField->fieldIndex=size;
        size+=parentField->type->size;
    }
    for(;ptr;ptr=ptr->next){
        // debug(3);
        // printf(" %s\n",ptr->name);
        Typetable *type=lookUpType(ptr->type->name);
        // printf("%s %s\n",ptr->name,ptr->type->name);
        if(type==NULL) yyerror("Undefined Type");
        if(type->size==0) yyerror("field type not allowed");
        ptr->fieldIndex=size;
        size+=type->size;
        ptr->type=type;
        if(type==POINTERTYPE){
            Typetable *ptrType=lookUpType(ptr->ptrType->name);
            ptr->ptrType=ptrType;
        }
    }
    Classes->size=size;
    if(parentField)parentField->next=(yyvsp[0].fieldPtr);
    else Classes->fields=(yyvsp[0].fieldPtr);
}
#line 1694 "y.tab.c"
    break;

  case 13: /* Cname: ID  */
#line 213 "main.y"
                                    {
                                    if(lookUpType((yyvsp[0].String))) yyerror("Type already defined");
                                    // debug(0);
                                    InstallClass((yyvsp[0].String),0,NULL,NULL,0,NULL);
                                    // debug(1);
                                    Lhead=NULL;
                                    installL(strdup("this"),POINTERTYPE,Classes,-3);
                                    paramCount=0;
                                    }
#line 1708 "y.tab.c"
    break;

  case 14: /* Cname: ID EXTENDS ID  */
#line 222 "main.y"
                                    {
                                    if(lookUpType((yyvsp[-2].String))) yyerror("Type already defined");
                                    Typetable* parent=lookUpType((yyvsp[0].String));
                                    if(!parent || parent->classIndex==-1) yyerror("parent class undefined");
                                    InstallClass((yyvsp[-2].String),0,NULL,parent,0,NULL);
                                    Classes->fields=cloneFieldList(parent->fields);
                                    Lhead=NULL;
                                    installL(strdup("this"),POINTERTYPE,Classes,-3);
                                    paramCount=0;
                                    }
#line 1723 "y.tab.c"
    break;

  case 15: /* MethodDefns: Mdef MethodDefns  */
#line 239 "main.y"
                                   {}
#line 1729 "y.tab.c"
    break;

  case 17: /* Mdef: VarType ID '(' ParamList ')' '{' LdeclBlock Body '}'  */
#line 242 "main.y"
                                                                        {
                                                                            Lsymbol* params=Lhead;
                                                                            int offset=-3;
                                                                            for(int i=0;i<=paramCount && Lhead;i++){ // "<=paramCount" bcz there is a hidden parameter that is "this"
                                                                                Lhead->binding=offset--;
                                                                                Lhead=Lhead->next;
                                                                            }
                                                                            Lsymbol* fsymbols=Lhead;
                                                                            offset=1;
                                                                            for(;Lhead;Lhead=Lhead->next){
                                                                                Lhead->binding=offset++;
                                                                            }
                                                                            InstallMethod(Classes,Classes->parent,(yyvsp[-7].String),params,fsymbols,0,0,(yyvsp[-1].nodePtr),(yyvsp[-8].typePtr));
                                                                            //clear Lhead and paramCount;
                                                                            Lhead=NULL;
                                                                            installL(strdup("this"),POINTERTYPE,Classes,-3);
                                                                            paramCount=0;
                                                                        }
#line 1752 "y.tab.c"
    break;

  case 18: /* TypeDeclarations: TYPE Typedefs ENDTYPE  */
#line 262 "main.y"
                                                {/*printTypes();*/ }
#line 1758 "y.tab.c"
    break;

  case 22: /* Typedef: ID '{' FieldList '}'  */
#line 268 "main.y"
                                                {   
                                                    if(lookUpType((yyvsp[-3].String))) yyerror("Type already defined");
                                                    InstallType((yyvsp[-3].String),0,NULL);
                                                    Fieldlist* ptr=(yyvsp[-1].fieldPtr);
                                                    int size=1; // because index 0 should store the classNo. for calculating function address from virtual function table
                                                    for(;ptr;ptr=ptr->next){
                                                        Typetable *type=lookUpType(ptr->type->name);
                                                        // printf("---- %s %s\n",ptr->name,ptr->type->name);
                                                        if(type==NULL) yyerror("Undefined Type");
                                                        ptr->fieldIndex=size;
                                                        size+=type->size;
                                                        ptr->type=type;
                                                        if(type==POINTERTYPE){
                                                            Typetable *ptrType=lookUpType(ptr->ptrType->name);
                                                            ptr->ptrType=ptrType;
                                                        }
                                                    }
                                                    Types->size=size;
                                                    Types->fields=(yyvsp[-1].fieldPtr);
                                                }
#line 1783 "y.tab.c"
    break;

  case 23: /* FieldList: Field FieldList  */
#line 289 "main.y"
                                                {
                                                Fieldlist* ptr=(yyvsp[0].fieldPtr);
                                                for(;ptr;ptr=ptr->next){
                                                    if(strcmp(ptr->name,(yyvsp[-1].fieldPtr)->name)==0) yyerror("duplicate field name");
                                                }
                                                (yyvsp[-1].fieldPtr)->next=(yyvsp[0].fieldPtr); 
                                                (yyval.fieldPtr)=(yyvsp[-1].fieldPtr);
                                                }
#line 1796 "y.tab.c"
    break;

  case 24: /* FieldList: Field  */
#line 297 "main.y"
                                                {(yyval.fieldPtr)=(yyvsp[0].fieldPtr);}
#line 1802 "y.tab.c"
    break;

  case 25: /* Field: ID ID ';'  */
#line 299 "main.y"
                                                {
                                                    // don't do type checking yet, do it in Typedef
                                                    (yyval.fieldPtr)=makeField((yyvsp[-1].String),0,makeTypeNode((yyvsp[-2].String)),NULL);
                                                }
#line 1811 "y.tab.c"
    break;

  case 26: /* Field: ID '*' ID ';'  */
#line 303 "main.y"
                                                {
                                                    // don't do type checking yet, do it in Typedef
                                                    (yyval.fieldPtr)=makeField((yyvsp[-1].String),0,makeTypeNode(strdup("pointer")),NULL);
                                                    (yyval.fieldPtr)->ptrType=makeTypeNode((yyvsp[-3].String));
                                                }
#line 1821 "y.tab.c"
    break;

  case 27: /* GDelcarations: DECL GDecList ENDDECL  */
#line 310 "main.y"
                                                 {}
#line 1827 "y.tab.c"
    break;

  case 28: /* GDelcarations: DECL ENDDECL  */
#line 311 "main.y"
                                                {}
#line 1833 "y.tab.c"
    break;

  case 29: /* GDecList: GDecl GDecList  */
#line 313 "main.y"
                                                  {}
#line 1839 "y.tab.c"
    break;

  case 30: /* GDecList: GDecl  */
#line 314 "main.y"
                                                 {}
#line 1845 "y.tab.c"
    break;

  case 31: /* ArrList: '[' NUM ']' ArrList  */
#line 316 "main.y"
                                                {(yyval.listPtr)=makeLnode("",(yyvsp[-2].Int),(yyvsp[0].listPtr));}
#line 1851 "y.tab.c"
    break;

  case 32: /* ArrList: '[' NUM ']'  */
#line 317 "main.y"
                                                {(yyval.listPtr)=makeLnode("",(yyvsp[-1].Int),NULL);}
#line 1857 "y.tab.c"
    break;

  case 33: /* GDecl: VarType VarList ';'  */
#line 319 "main.y"
                                                    {
                                                  Lnode* ptr=(yyvsp[-1].listPtr);
                                                  if((yyvsp[-2].typePtr)->size<1 && (yyvsp[-2].typePtr)->classIndex==-1) yyerror("Type cannot be declared");
                                                  for(;ptr;ptr=ptr->next){
                                                    if(lookUpG(ptr->s)){
                                                        yyerror("Variable already Declared");
                                                        exit(0);
                                                    }
                                                    if(ptr->num==valtype){
                                                        installG(ptr->s,(yyvsp[-2].typePtr),(yyvsp[-2].typePtr)->size,SP);
                                                        SP+=((yyvsp[-2].typePtr)->size);
                                                    }
                                                    else{
                                                        installG(ptr->s,POINTERTYPE,1,SP++); // Pointer is of size 1
                                                        Ghead->ptrType=(yyvsp[-2].typePtr);
                                                    }
                                                  }
                                                }
#line 1880 "y.tab.c"
    break;

  case 34: /* GDecl: VarType ID ArrList ';'  */
#line 337 "main.y"
                                                    {
                                                    if((yyvsp[-3].typePtr)->size<1) yyerror("Type cannot be declared");
                                                    if(lookUpG((yyvsp[-2].String))) yyerror("variable already declared");
                                                    int dim=0;
                                                    int size=(yyvsp[-3].typePtr)->size;
                                                    Lnode* ptr=(yyvsp[-1].listPtr);
                                                    for(;ptr;ptr=ptr->next){
                                                        dim++;
                                                        size*=ptr->num;
                                                    }
                                                    // printf("SIZE OF ARRAY IS %d\n",size);
                                                    installG((yyvsp[-2].String),ARRAYTYPE,size,SP);
                                                    SP+=size;
                                                    // Gsymbol* g=lookUpG($2);
                                                    Ghead->dim=makeLnode("",dim,(yyvsp[-1].listPtr));
                                                    Ghead->ptrType=(yyvsp[-3].typePtr);
                                                }
#line 1902 "y.tab.c"
    break;

  case 35: /* GDecl: VarType ID '(' ParamList ')' ';'  */
#line 354 "main.y"
                                                           {
                                                            if(lookUpG((yyvsp[-4].String))) yyerror("variable already declared");
                                                            if((yyvsp[-5].typePtr)->size>1) yyerror("return type of size>1 not yet possible");
                                                            installG((yyvsp[-4].String),(yyvsp[-5].typePtr),0,0);
                                                            Ghead->flabel=flabel++; // assign label and mark variable as function 
                                                            Ghead->paramlist=Lhead;
                                                            Lhead=NULL; // clear Lhead for other parameters
                                                        }
#line 1915 "y.tab.c"
    break;

  case 36: /* GDecl: VarType '*' ID '(' ParamList ')' ';'  */
#line 362 "main.y"
                                                            {
                                                            if((yyvsp[-6].typePtr)->size<1) yyerror("pointer of Type cannot be declared");
                                                            if(lookUpG((yyvsp[-4].String))) yyerror("variable already declared");
                                                            installG((yyvsp[-4].String),POINTERTYPE,0,0);
                                                            Ghead->ptrType=(yyvsp[-6].typePtr);
                                                            Ghead->flabel=flabel++; // assign label and mark variable as function 
                                                            Ghead->paramlist=Lhead;
                                                            Lhead=NULL; // clear Lhead for other parameters
                                                        }
#line 1929 "y.tab.c"
    break;

  case 37: /* VarList: ID ',' VarList  */
#line 372 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[-2].String),valtype,(yyvsp[0].listPtr));}
#line 1935 "y.tab.c"
    break;

  case 38: /* VarList: '*' ID ',' VarList  */
#line 373 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[-2].String),ptrtype,(yyvsp[0].listPtr));}
#line 1941 "y.tab.c"
    break;

  case 39: /* VarList: ID  */
#line 374 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),valtype,NULL);}
#line 1947 "y.tab.c"
    break;

  case 40: /* VarList: '*' ID  */
#line 375 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),ptrtype,NULL);}
#line 1953 "y.tab.c"
    break;

  case 41: /* ParamList: Param ',' ParamList  */
#line 378 "main.y"
                                    {}
#line 1959 "y.tab.c"
    break;

  case 42: /* ParamList: Param  */
#line 379 "main.y"
                                    {}
#line 1965 "y.tab.c"
    break;

  case 43: /* ParamList: %empty  */
#line 380 "main.y"
                                    {}
#line 1971 "y.tab.c"
    break;

  case 44: /* Param: VarType ID  */
#line 382 "main.y"
                                      {   //printf("Type type=%d\n",$1);  
                                        // if($1 != inttype && $1!=strtype && $1!=intptrtype && $1!=strptrtype) yyerror("forbidden type for paramteres");
                                        if((yyvsp[-1].typePtr)->size<1) yyerror("Type cannot be declared");
                                        if(lookUpL((yyvsp[0].String))) yyerror("duplicate parameter");
                                        installL((yyvsp[0].String),(yyvsp[-1].typePtr),NULL,-1); // add parameter to Lhead
                                        paramCount++; 
                                    }
#line 1983 "y.tab.c"
    break;

  case 45: /* Param: VarType '*' ID  */
#line 389 "main.y"
                                      {   //printf("Type type=%d\n",$1);  
                                        if((yyvsp[-2].typePtr)->size<1) yyerror("Pointer Type cannot be declared");
                                        if(lookUpL((yyvsp[0].String))) yyerror("duplicate parameter");
                                        installL((yyvsp[0].String),POINTERTYPE,(yyvsp[-2].typePtr),-1); // add parameter to Lhead 
                                        paramCount++;
                                    }
#line 1994 "y.tab.c"
    break;

  case 46: /* VarType: ID  */
#line 397 "main.y"
                        {
                            Typetable* type=lookUpType((yyvsp[0].String));
                            if(type==NULL) yyerror("undefined type");
                            (yyval.typePtr)=type;
                        }
#line 2004 "y.tab.c"
    break;

  case 47: /* VarType: VOID  */
#line 402 "main.y"
                        {
                            (yyval.typePtr)=VOIDTYPE;
                        }
#line 2012 "y.tab.c"
    break;

  case 50: /* Fdef: VarType ID '(' ParamList ')' '{' LdeclBlock Body '}'  */
#line 411 "main.y"
                                                                   {/*iterate through paramlist and Lhead and check correctness and assign relative binding*/
                                                                    Gsymbol* funct=lookUpG((yyvsp[-7].String));
                                                                    if(!funct || funct->flabel==-1) yyerror("undeclared function");
                                                                    if(funct->type!=(yyvsp[-8].typePtr)) yyerror("type mismatch in funciton decl and def");
                                                                    Lsymbol* ptr;
                                                                    int offset=-3;
                                                                    ptr=funct->paramlist;
                                                                    funct->paramlist=Lhead;
                                                                    for(;ptr && Lhead;ptr=ptr->next){
                                                                        if(ptr->type!=Lhead->type) yyerror("conflicting function declaration and definition");
                                                                        if(strcmp(ptr->name,Lhead->name)!=0)yyerror("conflicting function declaration and definition");
                                                                        Lhead->binding=offset--;
                                                                        Lhead=Lhead->next;
                                                                    }
                                                                    // original funct->paramlist from declaration is not used anymore, maybe used for future polymorphism implementations
                                                                    // funct->paramlist already contains all the parameters and local declarations
                                                                    // now the rest of Lhead is local variables
                                                                    offset=1;
                                                                    funct->fsymbols=Lhead;
                                                                    for(;Lhead;Lhead=Lhead->next){
                                                                        Lhead->binding=offset++;
                                                                    }
                                                                    installFunction(makeNode(0,funct->type,funct,funct->paramlist,tFUNCT,NULL,(yyvsp[-1].nodePtr),NULL)); //->right points to function definition and left to next function 
                                                                    Lhead=NULL;
                                                                }
#line 2042 "y.tab.c"
    break;

  case 51: /* Fdef: VarType '*' ID '(' ParamList ')' '{' LdeclBlock Body '}'  */
#line 436 "main.y"
                                                                       {/*iterate through paramlist and Lhead and check correctness and assign relative binding*/
                                                                    if((yyvsp[-9].typePtr)->size<1) yyerror("pointer of Type cannot be declared");
                                                                    Gsymbol* funct=lookUpG((yyvsp[-7].String));
                                                                    if(!funct || funct->flabel==-1) yyerror("undeclared function");
                                                                    if(funct->type!=POINTERTYPE) yyerror("type mismatch in funciton decl and def");
                                                                    Lsymbol* ptr;
                                                                    int offset=-3;
                                                                    ptr=funct->paramlist;
                                                                    funct->paramlist=Lhead;
                                                                    for(;ptr && Lhead;ptr=ptr->next){
                                                                        if(ptr->type!=Lhead->type) yyerror("conflicting function declaration and definition");
                                                                        if(strcmp(ptr->name,Lhead->name)!=0)yyerror("conflicting function declaration and definition");
                                                                        Lhead->binding=offset--;
                                                                        Lhead=Lhead->next;
                                                                    }
                                                                    // original funct->paramlist from declaration is not used anymore, maybe used for future polymorphism implementations
                                                                    // funct->paramlist already contains all the parameters and local declarations
                                                                    // now the rest of Lhead is local variables
                                                                    offset=1;
                                                                    funct->fsymbols=Lhead;
                                                                    for(;Lhead;Lhead=Lhead->next){
                                                                        Lhead->binding=offset++;
                                                                    }
                                                                    installFunction(makeNode(0,funct->type,funct,funct->paramlist,tFUNCT,NULL,(yyvsp[-1].nodePtr),NULL)); //->right points to function definition and left to next function 
                                                                    Lhead=NULL;
                                                                }
#line 2073 "y.tab.c"
    break;

  case 52: /* MainBlock: VOID MAIN '(' ')' '{' LdeclBlock Body '}'  */
#line 464 "main.y"
                                                            {
                                                                if(lookUpG((yyvsp[-6].String))) yyerror("only one main function allowed");
                                                                installG((yyvsp[-6].String),VOIDTYPE,0,0);
                                                                Ghead->flabel=0; // assign label and mark variable as function 
                                                                Ghead->paramlist=Lhead;
                                                                Ghead->fsymbols=Lhead;
                                                                int offset=1;
                                                                for(;Lhead;Lhead=Lhead->next){
                                                                    Lhead->binding=offset++;
                                                                }
                                                                installFunction(makeNode(0,VOIDTYPE,Ghead,Ghead->paramlist,tFUNCT,NULL,(yyvsp[-1].nodePtr),NULL));
                                                                Lhead=NULL;
                                                            }
#line 2091 "y.tab.c"
    break;

  case 58: /* LDecl: VarType IdList ';'  */
#line 485 "main.y"
                                   {
                                    Lnode* ptr=(yyvsp[-1].listPtr);
                                    for(;ptr;ptr=ptr->next){
                                        if(lookUpL(ptr->s)) yyerror("variable already declared");
                                        if(ptr->num == valtype){
                                            if((yyvsp[-2].typePtr)->size<1) yyerror("Type cannot be declared ");
                                            installL(ptr->s,(yyvsp[-2].typePtr),NULL,-1);
                                        }
                                        else{
                                            installL(ptr->s,POINTERTYPE,(yyvsp[-2].typePtr),-1);
                                        }
                                    }
                                }
#line 2109 "y.tab.c"
    break;

  case 59: /* IdList: ID ',' IdList  */
#line 499 "main.y"
                                {(yyval.listPtr)=makeLnode((yyvsp[-2].String),valtype,(yyvsp[0].listPtr));}
#line 2115 "y.tab.c"
    break;

  case 60: /* IdList: '*' ID ',' IdList  */
#line 500 "main.y"
                                {(yyval.listPtr)=makeLnode((yyvsp[-2].String),ptrtype,(yyvsp[0].listPtr));}
#line 2121 "y.tab.c"
    break;

  case 61: /* IdList: ID  */
#line 501 "main.y"
                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),valtype,NULL);}
#line 2127 "y.tab.c"
    break;

  case 62: /* IdList: '*' ID  */
#line 502 "main.y"
                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),ptrtype,NULL);}
#line 2133 "y.tab.c"
    break;

  case 63: /* Body: begin Slist ReturnStmt ';' end  */
#line 506 "main.y"
                                                {(yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tCONNECT,(yyvsp[-3].nodePtr),(yyvsp[-2].nodePtr),NULL);}
#line 2139 "y.tab.c"
    break;

  case 64: /* Body: begin ReturnStmt ';' end  */
#line 507 "main.y"
                                                {(yyval.nodePtr)=(yyvsp[-2].nodePtr);}
#line 2145 "y.tab.c"
    break;

  case 65: /* Slist: Slist Stmt  */
#line 509 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tCONNECT,(yyvsp[-1].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2151 "y.tab.c"
    break;

  case 66: /* Slist: Stmt  */
#line 510 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 2157 "y.tab.c"
    break;

  case 67: /* Stmt: InputStmt ';'  */
#line 512 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 2163 "y.tab.c"
    break;

  case 68: /* Stmt: OutputStmt ';'  */
#line 513 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 2169 "y.tab.c"
    break;

  case 69: /* Stmt: Expr ';'  */
#line 514 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 2175 "y.tab.c"
    break;

  case 70: /* Stmt: AssgStmt ';'  */
#line 515 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 2181 "y.tab.c"
    break;

  case 71: /* Stmt: ReturnStmt ';'  */
#line 516 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 2187 "y.tab.c"
    break;

  case 72: /* Stmt: Ifstmt  */
#line 517 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 2193 "y.tab.c"
    break;

  case 73: /* Stmt: LoopStmt  */
#line 518 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 2199 "y.tab.c"
    break;

  case 74: /* Stmt: BREAK ';'  */
#line 519 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tBREAK,NULL,NULL,NULL);}
#line 2205 "y.tab.c"
    break;

  case 75: /* Stmt: CONTINUE ';'  */
#line 520 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tCONTINUE,NULL,NULL,NULL);}
#line 2211 "y.tab.c"
    break;

  case 76: /* ReturnStmt: RETURN Expr  */
#line 522 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tRETURN,(yyvsp[0].nodePtr),(yyvsp[0].nodePtr),(yyvsp[0].nodePtr));}
#line 2217 "y.tab.c"
    break;

  case 77: /* ReturnStmt: RETURN  */
#line 523 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tRETURN,NULL,NULL,NULL);}
#line 2223 "y.tab.c"
    break;

  case 78: /* LoopStmt: WHILE '(' Expr ')' '{' Slist '}'  */
#line 525 "main.y"
                                                    {if(isBoolean((yyvsp[-4].nodePtr),(yyvsp[-4].nodePtr))) (yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tWHILE,(yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr),(yyvsp[-4].nodePtr));}
#line 2229 "y.tab.c"
    break;

  case 79: /* LoopStmt: DO '{' Slist '}' WHILE '(' Expr ')'  */
#line 526 "main.y"
                                                                {if(isBoolean((yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr))) (yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tDOWHILE,(yyvsp[-5].nodePtr),(yyvsp[-5].nodePtr),(yyvsp[-1].nodePtr));}
#line 2235 "y.tab.c"
    break;

  case 80: /* LoopStmt: REPEAT '{' Slist '}' UNTIL '(' Expr ')'  */
#line 527 "main.y"
                                                                    {if(isBoolean((yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr))) (yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tREPEATUNTIL,(yyvsp[-5].nodePtr),(yyvsp[-5].nodePtr),(yyvsp[-1].nodePtr));}
#line 2241 "y.tab.c"
    break;

  case 81: /* Ifstmt: IF '(' Expr ')' '{' Slist '}' Else '{' Slist '}'  */
#line 529 "main.y"
                                                             {if(isBoolean((yyvsp[-8].nodePtr),(yyvsp[-8].nodePtr))) (yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tIF,(yyvsp[-5].nodePtr),(yyvsp[-1].nodePtr),(yyvsp[-8].nodePtr));}
#line 2247 "y.tab.c"
    break;

  case 82: /* Ifstmt: IF '(' Expr ')' '{' Slist '}'  */
#line 530 "main.y"
                                                    {if(isBoolean((yyvsp[-4].nodePtr),(yyvsp[-4].nodePtr))) (yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tIF,(yyvsp[-1].nodePtr),NULL,(yyvsp[-4].nodePtr));}
#line 2253 "y.tab.c"
    break;

  case 83: /* InputStmt: READ '(' ID ')'  */
#line 532 "main.y"
                                    { //////ADJUST FOR VAR
                                    Gsymbol* Gptr=lookUpG((yyvsp[-1].String));
                                    Lsymbol* Lptr=lookUpL((yyvsp[-1].String));
                                    if(Gptr==NULL && Lptr==NULL) yyerror("undeclared Variable");
                                    node* temp=makeNode(0,NULL,Gptr,Lptr,tVAR,NULL,NULL,NULL);
                                    (yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tREAD,temp,temp,NULL);
                                    }
#line 2265 "y.tab.c"
    break;

  case 84: /* OutputStmt: WRITE '(' Expr ')'  */
#line 540 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tWRITE,(yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr),NULL);}
#line 2271 "y.tab.c"
    break;

  case 85: /* AssgStmt: Var '=' Expr  */
#line 542 "main.y"
                                    {
                                    // printf("types: %s\n",$1->right->type->name);
                                    // printf("types: %s\n",$3->type->name);
                                    if((yyvsp[-2].nodePtr)->right->type!=(yyvsp[0].nodePtr)->type) yyerror("assignment type mismatch");
                                    (yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tASSIGN,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);
                                    }
#line 2282 "y.tab.c"
    break;

  case 86: /* AssgStmt: '*' Var '=' Expr  */
#line 548 "main.y"
                                    {
                                    if((yyvsp[-2].nodePtr)->right->type!=POINTERTYPE) yyerror("pointer assignment type mismatch");
                                    if((yyvsp[-2].nodePtr)->right->ptrType!=(yyvsp[0].nodePtr)->type) yyerror("Pointer type mismatch");
                                    node* ptr=makeNode(0,NULL,NULL,NULL,tGETADDRATVAL,(yyvsp[-2].nodePtr),NULL,NULL);
                                    (yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tASSIGN,ptr,(yyvsp[0].nodePtr),NULL);
                                    }
#line 2293 "y.tab.c"
    break;

  case 87: /* AssgStmt: ID Array '=' Expr  */
#line 554 "main.y"
                                    {
                                        Gsymbol* ptr=lookUpG((yyvsp[-3].String)); // no need to look at local variable as array is only declared in global
                                        if(!ptr) yyerror("variable undeclared");
                                        if(ptr->type!=ARRAYTYPE) yyerror("array access forbidden for variable");
                                        if(ptr->ptrType!=(yyvsp[0].nodePtr)->type) yyerror("assignment type mismatch");
                                        node* var=NULL;
                                        var=makeNode(0,ptr->ptrType,ptr,NULL,tARRADDR,(yyvsp[-2].nodePtr),(yyvsp[-2].nodePtr),(yyvsp[-2].nodePtr));
                                        // if(ptr->type==intarrtype) var=makeNode(0,inttype,ptr,NULL,tARRVAL,$2,$2,$2);
                                        // else if(ptr->type==strarrtype) var=makeNode(0,strtype,ptr,NULL,tARRVAL,$2,$2,$2);
                                        // if(var->type!=$4->type) yyerror("type mismatch");
                                        (yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tASSIGN,var,(yyvsp[0].nodePtr),(yyvsp[0].nodePtr));
                                    }
#line 2310 "y.tab.c"
    break;

  case 88: /* Array: '[' Expr ']' Array  */
#line 567 "main.y"
                                       {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[-2].nodePtr))){
                                            (yyvsp[-2].nodePtr)->left=(yyvsp[0].nodePtr);
                                            (yyval.nodePtr)=(yyvsp[-2].nodePtr);
                                        }
                                      }
#line 2320 "y.tab.c"
    break;

  case 89: /* Array: '[' Expr ']'  */
#line 572 "main.y"
                                       {if(isArithmetic((yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr))) (yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 2326 "y.tab.c"
    break;

  case 90: /* Expr: Expr '+' Expr  */
#line 575 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,INTTYPE,NULL,NULL,tADD,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2332 "y.tab.c"
    break;

  case 91: /* Expr: Expr '-' Expr  */
#line 576 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,INTTYPE,NULL,NULL,tSUB,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2338 "y.tab.c"
    break;

  case 92: /* Expr: Expr '*' Expr  */
#line 577 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,INTTYPE,NULL,NULL,tMUL,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2344 "y.tab.c"
    break;

  case 93: /* Expr: Expr '/' Expr  */
#line 578 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,INTTYPE,NULL,NULL,tDIV,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2350 "y.tab.c"
    break;

  case 94: /* Expr: Expr '%' Expr  */
#line 579 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,INTTYPE,NULL,NULL,tMOD,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2356 "y.tab.c"
    break;

  case 95: /* Expr: Expr '>' Expr  */
#line 580 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,BOOLTYPE,NULL,NULL,tGT,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2362 "y.tab.c"
    break;

  case 96: /* Expr: Expr '<' Expr  */
#line 581 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,BOOLTYPE,NULL,NULL,tLT,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2368 "y.tab.c"
    break;

  case 97: /* Expr: Expr GE Expr  */
#line 582 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,BOOLTYPE,NULL,NULL,tGE,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2374 "y.tab.c"
    break;

  case 98: /* Expr: Expr LE Expr  */
#line 583 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,BOOLTYPE,NULL,NULL,tLE,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2380 "y.tab.c"
    break;

  case 99: /* Expr: Expr EQ Expr  */
#line 584 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,BOOLTYPE,NULL,NULL,tEQ,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2386 "y.tab.c"
    break;

  case 100: /* Expr: Expr NEQ Expr  */
#line 585 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,BOOLTYPE,NULL,NULL,tNEQ,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2392 "y.tab.c"
    break;

  case 101: /* Expr: Expr AND Expr  */
#line 586 "main.y"
                                    {if(isBoolean((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,BOOLTYPE,NULL,NULL,tAND,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2398 "y.tab.c"
    break;

  case 102: /* Expr: Expr OR Expr  */
#line 587 "main.y"
                                    {if(isBoolean((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,BOOLTYPE,NULL,NULL,tOR,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2404 "y.tab.c"
    break;

  case 103: /* Expr: '(' Expr ')'  */
#line 588 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 2410 "y.tab.c"
    break;

  case 104: /* Expr: ID '(' ArgList ')'  */
#line 589 "main.y"
                                     {
                                        Gsymbol* fg=lookUpG((yyvsp[-3].String));
                                        if(!fg) yyerror("function not defined");
                                        node* ptr=(yyvsp[-1].nodePtr);
                                        Lsymbol* ld=fg->paramlist;
                                        for(;ptr && ld;ld=ld->next,ptr=ptr->center){
                                            if(ptr->type!=ld->type) {
                                                // printf("%s, %s %s\n",ptr->type->name,ld->name,ld->type->name);
                                                yyerror("type mismatch");
                                            }
                                        }
                                        if(ptr) yyerror("error in argument list");
                                        if(ld && ld->binding<0) yyerror("error in argument list");
                                        (yyval.nodePtr)=makeNode(0,fg->type,fg,NULL,tFUNCTCALL,(yyvsp[-1].nodePtr),NULL,NULL); //left contains argument list for function call
                                    }
#line 2430 "y.tab.c"
    break;

  case 105: /* Expr: ID '(' ')'  */
#line 604 "main.y"
                                    {
                                        Gsymbol* fg=lookUpG((yyvsp[-2].String));
                                        if(!fg) yyerror("function not defined");
                                        Lsymbol* ld=fg->paramlist;
                                        if(ld && ld->binding<0) yyerror("error in argument list");
                                        (yyval.nodePtr)=makeNode(0,fg->type,fg,NULL,tFUNCTCALL,NULL,NULL,NULL); //left contains argument list for function call
                                    }
#line 2442 "y.tab.c"
    break;

  case 106: /* Expr: NUM  */
#line 611 "main.y"
                                    {(yyval.nodePtr)=makeNode((yyvsp[0].Int),INTTYPE,NULL,NULL,tCONST,NULL,NULL,NULL);}
#line 2448 "y.tab.c"
    break;

  case 107: /* Expr: '-' NUM  */
#line 612 "main.y"
                                    {(yyval.nodePtr)=makeNode(-1*(yyvsp[0].Int),INTTYPE,NULL,NULL,tCONST,NULL,NULL,NULL);}
#line 2454 "y.tab.c"
    break;

  case 108: /* Expr: LITERAL  */
#line 613 "main.y"
                                    {
                                    //  printf("STARTED parsing literal");
                                     (yyval.nodePtr)=makeNode(0,STRINGTYPE,NULL,NULL,tLITERAL,NULL,NULL,NULL);
                                     (yyval.nodePtr)->literal=(yyvsp[0].String);
                                    //  printf("FINISHED parsing literal");
                                    }
#line 2465 "y.tab.c"
    break;

  case 109: /* Expr: Var  */
#line 619 "main.y"
                                    {
                                    (yyval.nodePtr)=makeNode(0,(yyvsp[0].nodePtr)->right->type,NULL,NULL,tGETVAL,(yyvsp[0].nodePtr),NULL,NULL);
                                    (yyval.nodePtr)->ptrType=(yyvsp[0].nodePtr)->right->ptrType;
                                    }
#line 2474 "y.tab.c"
    break;

  case 110: /* Expr: Var ARROW ID '(' ArgList ')'  */
#line 623 "main.y"
                                            {
                                                if((yyvsp[-5].nodePtr)->right->type!=POINTERTYPE) yyerror("pointer access from static type");
                                                Methodlist* method=LookUpMethod((yyvsp[-5].nodePtr)->right->ptrType,(yyvsp[-3].String),(yyvsp[-1].nodePtr)); //remember we only care about flabel
                                                // printf("%s\n",$1->right->ptrType->name);
                                                if(method==NULL) yyerror("No such method in class or any of its descendents");
                                                // $1->center=$5; // adding address of obj to arglist, to accomodate for "this"
                                                node* arg=makeNode(0,POINTERTYPE,NULL,NULL,tGETADDRATVAL,(yyvsp[-5].nodePtr),NULL,NULL);
                                                arg->ptrType=(yyvsp[-5].nodePtr)->right->type;
                                                arg->center=(yyvsp[-1].nodePtr);
                                                node* arguments=arg;
                                                Lsymbol* param=method->paramList;
                                                for(;arg && param;arg=arg->center,param=param->next){
                                                    // debug(3);
                                                    // printf("%s %s\n",arg->type->name,param->name);
                                                    if(arg->type!=param->type){
                                                        yyerror("argument type mismatch with parameters");
                                                    }
                                                }
                                                if(arg) yyerror("error in argument list");
                                                if(param && param->binding<0) yyerror("error in argument list");
                                                // debug(3);
                                                // for(node* temp=arguments;temp;temp=temp->center) printf("arguments\n");
                                                (yyval.nodePtr)=makeNode(method->funcPosition,method->type,NULL,NULL,tMETHODCALL,arguments,NULL,NULL); // left contains arg list
                                                // debug(0);
                                            }
#line 2504 "y.tab.c"
    break;

  case 111: /* Expr: Var ARROW ID '(' ')'  */
#line 648 "main.y"
                                   {
                                                if((yyvsp[-4].nodePtr)->right->type!=POINTERTYPE) yyerror("pointer access from static type");
                                                Methodlist* method=LookUpMethod((yyvsp[-4].nodePtr)->right->ptrType,(yyvsp[-2].String),NULL); //remember we only care about flabel
                                                // printf("%s\n",$1->right->ptrType->name);
                                                if(method==NULL) yyerror("No such method in class or any of its descendents");
                                                
                                                (yyvsp[-4].nodePtr)->center=NULL; // adding address of obj to arglist, to accomodate for "this"
                                                node* arg=makeNode(0,POINTERTYPE,NULL,NULL,tGETADDRATVAL,(yyvsp[-4].nodePtr),NULL,NULL);
                                                arg->ptrType=(yyvsp[-4].nodePtr)->right->type;
                                                node* arguments=arg;
                                                Lsymbol* param=method->paramList;
                                                for(;arg && param;arg=arg->center,param=param->next){
                                                    // debug(3);
                                                    // printf("%s %s\n",arg->type->name,param->name);
                                                    if(arg->type!=param->type){
                                                        yyerror("argument type mismatch with parameters");
                                                    }
                                                }
                                                if(arg) yyerror("error in argument list");
                                                if(param && param->binding<0) yyerror("error in argument list");
                                                // debug(3);
                                                (yyval.nodePtr)=makeNode(method->funcPosition,method->type,NULL,NULL,tMETHODCALL,arguments,NULL,NULL); // left contains arg list
                                                // val contains methodNo. in the class heirarchy
                                                // debug(0);
                                            }
#line 2534 "y.tab.c"
    break;

  case 112: /* Expr: '&' Var  */
#line 694 "main.y"
                                    {
                                    (yyval.nodePtr)=(yyvsp[0].nodePtr);
                                    }
#line 2542 "y.tab.c"
    break;

  case 113: /* Expr: '*' Var  */
#line 697 "main.y"
                                    {
                                    if((yyvsp[0].nodePtr)->right->type!=POINTERTYPE) yyerror("not pointer variable");
                                    (yyval.nodePtr)=makeNode(0,(yyvsp[0].nodePtr)->right->ptrType,NULL,NULL,tGETADDRATVAL,(yyvsp[0].nodePtr),NULL,NULL);
                                    (yyval.nodePtr)=makeNode(0,(yyvsp[0].nodePtr)->right->ptrType,NULL,NULL,tGETVAL,(yyval.nodePtr),NULL,NULL);
            /////////////////////////////////////
                                    // Gsymbol* Gptr=lookUpG($2);
                                    // Lsymbol* Lptr=lookUpL($2);
                                    // if(Gptr==NULL && Lptr==NULL) yyerror("undeclared variable");
                                    // node* var=makeNode(0,(Lptr?Lptr->type:Gptr->type),Gptr,Lptr,tVAR,NULL,NULL,NULL); 
                                    // if(Lptr && Lptr->type==intptrtype)$$=makeNode(0,inttype,NULL,NULL,tVALUEAT,var,var,var);
                                    // else if(Lptr && Lptr->type==strptrtype) $$=makeNode(0,strtype,NULL,NULL,tVALUEAT,var,var,var);
                                    // else if(Gptr->type==intptrtype)$$=makeNode(0,inttype,NULL,NULL,tVALUEAT,var,var,var);
                                    // else if(Gptr->type==strptrtype) $$=makeNode(0,strtype,NULL,NULL,tVALUEAT,var,var,var);
                                    }
#line 2561 "y.tab.c"
    break;

  case 114: /* Expr: ID Array  */
#line 711 "main.y"
                                {
                                    Gsymbol* ptr=lookUpG((yyvsp[-1].String));
                                    if(!ptr) yyerror("variable undeclared");
                                    if(ptr->type!=ARRAYTYPE) yyerror("type mismatch");
                                    (yyval.nodePtr)=makeNode(0,ptr->ptrType,ptr,NULL,tARRVAL,(yyvsp[0].nodePtr),(yyvsp[0].nodePtr),(yyvsp[0].nodePtr));
                                }
#line 2572 "y.tab.c"
    break;

  case 115: /* Expr: MALLOC '(' VarType ')'  */
#line 717 "main.y"
                                    {
                                        (yyval.nodePtr)=makeNode(0,POINTERTYPE,NULL,NULL,tMALLOC,NULL,NULL,NULL);
                                        (yyval.nodePtr)->ptrType=(yyvsp[-1].typePtr);
                                    }
#line 2581 "y.tab.c"
    break;

  case 116: /* Expr: NEW '(' VarType ')'  */
#line 721 "main.y"
                                 {
                                        (yyval.nodePtr)=makeNode(0,POINTERTYPE,NULL,NULL,tNEW,NULL,NULL,NULL);
                                        if((yyvsp[-1].typePtr)->classIndex<0) yyerror("cannot create new object of type\n");
                                        (yyval.nodePtr)->ptrType=(yyvsp[-1].typePtr);
                                    }
#line 2591 "y.tab.c"
    break;

  case 117: /* Expr: Null  */
#line 726 "main.y"
                                {
                                    (yyval.nodePtr)=makeNode(0,POINTERTYPE,NULL,NULL,tNULL,NULL,NULL,NULL);
                                }
#line 2599 "y.tab.c"
    break;

  case 118: /* Var: Var '.' ID  */
#line 730 "main.y"
                            {
                                // printf("##\n");
                                if((yyvsp[-2].nodePtr)->right->type==POINTERTYPE) yyerror("Static access from pointer variable");  
                                // printf("##\n");
                                Fieldlist* field=LookupField((yyvsp[-2].nodePtr)->right->type,(yyvsp[0].String)); 
                                // printf("##\n");
                                if(field==NULL) yyerror("NO such field");  
                                // printf("##\n");
                                node* var=makeNode(field->fieldIndex,field->type,NULL,NULL,tCONST,NULL,NULL,NULL); 
                                // printf("##\n");
                                var->ptrType=field->ptrType; 
                                // printf("##\n");
                                (yyval.nodePtr)=makeNode(0,POINTERTYPE,NULL,NULL,tRECURSADDR,(yyvsp[-2].nodePtr),var,NULL) ;                   
                            }
#line 2618 "y.tab.c"
    break;

  case 119: /* Var: Var ARROW ID  */
#line 744 "main.y"
                           {
                                // printf("##\n");
                                if((yyvsp[-2].nodePtr)->right->type!=POINTERTYPE) yyerror("pointer access from static type");
                                // printf("##\n");
                                // printf("x->%s type: %s\n",$3,$1->right->type->name);
                                // printf("%s\n",$1->right->ptrType->name);
                                Fieldlist* field=LookupField((yyvsp[-2].nodePtr)->right->ptrType,(yyvsp[0].String));
                                if(field==NULL) yyerror("NO such field");
                                // printf("field name: %s\n",field->name);
                                node* var=makeNode(field->fieldIndex,field->type,NULL,NULL,tCONST,NULL,NULL,NULL);
                                var->ptrType=field->ptrType;
                                (yyval.nodePtr)=makeNode(0,POINTERTYPE,NULL,NULL,tRECURSADDRATVAL,(yyvsp[-2].nodePtr),var,NULL) ;
                            }
#line 2636 "y.tab.c"
    break;

  case 120: /* Var: ID  */
#line 757 "main.y"
                            {
                                // printf("From expr %s\n",$1);
                                Gsymbol* Gptr=lookUpG((yyvsp[0].String));
                                Lsymbol* Lptr=lookUpL((yyvsp[0].String));
                                if(Lptr==NULL && Gptr==NULL) yyerror("undelcared variable");
                                node* var=makeNode(0,(Lptr?Lptr->type:Gptr->type),Gptr,Lptr,tVAR,NULL,NULL,NULL);
                                var->ptrType=Lptr?Lptr->ptrType:Gptr->ptrType;
                                (yyval.nodePtr)=makeNode(0,POINTERTYPE,NULL,NULL,tADDRESSOF,var,var,NULL) ;
                                (yyval.nodePtr)->ptrType=Lptr?Lptr->type:Gptr->type;
                            }
#line 2651 "y.tab.c"
    break;

  case 121: /* ArgList: Expr ',' ArgList  */
#line 769 "main.y"
                            {   // argument list will be linked with center pointer
                                (yyvsp[-2].nodePtr)->center=(yyvsp[0].nodePtr);
                                (yyval.nodePtr)=(yyvsp[-2].nodePtr);
                            }
#line 2660 "y.tab.c"
    break;

  case 122: /* ArgList: Expr  */
#line 773 "main.y"
                            {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 2666 "y.tab.c"
    break;


#line 2670 "y.tab.c"

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

#line 776 "main.y"


int main(int argc, char **argv){
    FILE *fp=fopen(argv[1],"r");
    outFile=fopen("a.xsm","w");
    yyin=fp;
    SP=4096;
    installDefaultTypes();
    yyparse();
    Gsymbol* ptr=Ghead;
    /* if(!ptr) printf("What\n"); */
    /* for(;ptr;ptr=ptr->next)printf("%s ",ptr->name); */
    printf("parsing complete\n");

    space=0;
    /* printTree(root); */

    genHeader();
    installVirtualFunctionTable();
    prerequisites(); // set stack pointer to after declarations
    
    /* printf("Methods:\n"); */
    Typetable* class;
    for(class=Classes;class;class=class->next){
        Methodlist* ownMethod=class->vFunctPtr;
        for(;ownMethod;ownMethod=ownMethod->next){
            /* printf("method %s\n",ownMethod->name); */
            continueLabels=NULL;
            breakLabels=NULL;
            currFunction=NULL;
            currMethod=ownMethod;
            currReg=0;
            methodPreperation(ownMethod);
            genCode(ownMethod->fDefinition);
        }
    }
    printf("Method code gen complete\n");
    /* printf("functions\n"); */
    for(;functions;functions=functions->left){
        /* printf("#######\n"); */
        continueLabels=NULL;
        breakLabels=NULL;
        Lhead=functions->Lvar;
        currMethod=NULL;
        currFunction=functions->Gvar;
        currReg=0;
        functionPreperation(currFunction);
        /* printf("function preperation done %s\n",currFunction->name); */
        genCode(functions->right);
    }
    printf("function code gen completed\n");
    /* int reg=genCode(root); */
    printf("codeGen completed\n");
    genSegmenationFault();
    genErrorHandler();
    genExit();
    return 0;
}
// Type cannot be declared

void printTypes(){
    Typetable* ptr =Types;
    for(;ptr!=NULL;ptr=ptr->next){
        printf("\ntype: %s\n",ptr->name);
        Fieldlist * f=ptr->fields;
        for(;f!=NULL;f=f->next){
            printf("%s ",f->name);
        }
    }
}

//fsymbol

void yyerror(char* s){
    printf("******************* Compilation error ******************\n");
    printf("%s\n",s);
    printLineNo();
    printf("lexeme : %s\n",yytext);
    printf("********************************************************\n");
    exit(0);
}

void installVirtualFunctionTable(){
    vFunctTableStart=SP;
    int i;
    fprintf(outFile,"MOV R0, 0\n");
    for(i=0;i<classCount;i++){
        for(int j=0;j<8;j++) fprintf(outFile,"PUSH R0\n");
        SP+=8;
    }
    Typetable* class;
    for(class=Classes;class;class=class->next){
        fprintf(outFile,"MOV R0, %d\n",8*(class->classIndex));
        /* printf("class: %s\n",class->name); */
        Methodlist* parentMethod=NULL;
        if(class->parent)parentMethod=class->parent->vFunctPtr;
        /* printf("parent Methods: "); */
        for(;parentMethod;parentMethod=parentMethod->next){
            /* printf("%s(M%d) ",parentMethod->name,parentMethod->flabel); */
            fprintf(outFile,"MOV R1, R0\n");
            fprintf(outFile,"ADD R1, %d\n",parentMethod->funcPosition);
            fprintf(outFile,"ADD R1, %d\n",vFunctTableStart);
            fprintf(outFile,"BRKP\n");
            fprintf(outFile,"MOV [R1], M%d!\n",parentMethod->flabel);
        }
        /* printf("\n"); */
        Methodlist* ownMethod=class->vFunctPtr;
        /* printf("Own Methods: "); */
        for(;ownMethod;ownMethod=ownMethod->next){ // placed second bcz child may override parent method
            /* printf("%s(M%d) ",ownMethod->name,ownMethod->flabel); */
            fprintf(outFile,"MOV R1, R0\n");
            fprintf(outFile,"ADD R1, %d\n",ownMethod->funcPosition);
            fprintf(outFile,"ADD R1, %d\n",vFunctTableStart);
            fprintf(outFile,"BRKP\n");
            fprintf(outFile,"MOV [R1], M%d!\n",ownMethod->flabel);
        }
        /* printf("\n"); */
    }
}

void installDefaultTypes(){
    InstallType(strdup("void"),0,NULL);
    VOIDTYPE=Types;
    InstallType(strdup("int"),1,NULL);
    INTTYPE=Types;
    InstallType(strdup("string"),1,NULL);
    STRINGTYPE=Types;
    InstallType(strdup("pointer"),1,NULL);
    POINTERTYPE=Types;
    InstallType(strdup("array"),1,NULL);
    ARRAYTYPE=Types;
    InstallType(strdup("bool"),1,NULL);
    ARRAYTYPE=Types;
}

void functionPreperation(Gsymbol *funct){
    fprintf(outFile,"F%d:\n",funct->flabel);
    fprintf(outFile,"PUSH BP\n");
    fprintf(outFile,"MOV BP, SP\n");
    Lsymbol* lvar=funct->fsymbols;
    fprintf(outFile,"MOV R0,0\n");
    for(;lvar;lvar=lvar->next) fprintf(outFile,"PUSH R0\n");
    /* printf("okay function prepared\n"); */
}

void methodPreperation(Methodlist* method){
    fprintf(outFile,"M%d:\n",method->flabel);
    fprintf(outFile,"PUSH BP\n");
    fprintf(outFile,"MOV BP, SP\n");
    Lsymbol* lvar=method->fsymbols;
    fprintf(outFile,"MOV R0,0\n");
    for(;lvar;lvar=lvar->next) fprintf(outFile,"PUSH R0\n");
    /* printf("okay method prepared\n"); */
}

void installFunction(node* f){
    f->left=functions;
    functions=f;
}// left left chain of functions

void prerequisites(){
    fprintf(outFile,"MOV SP,%d\n",SP); // set stack pointer to after the declarations;
    fprintf(outFile,"MOV BP,%d\n",SP); // set base pointer to top of stack
    initializeHeapSet();
    fprintf(outFile,"MAIN:\n");
    fprintf(outFile,"CALL F0!\n");
    fprintf(outFile,"JMP EXITCODE!\n");
}

bool isArithmetic(node* left, node* right){
    if(left==NULL || right==NULL){
        yyerror("syntax error");
        exit(0);
    }
    if(left->type!=right->type){
        yyerror("type mismatch");
        exit(0);
    }
    return true;
}
bool isBoolean(node* left, node* right){
    if(left==NULL || right==NULL){
        yyerror("syntax error");
        exit(0);
    }
    if(left->type!= BOOLTYPE || right->type!=BOOLTYPE){
        yyerror("type mismatch");
        exit(0);
    }
    return true;
}
void debug(int i){
    if(i==0) printf("***************\n");
    else if(i==1) printf("###############\n");
    else if(i==2) printf("$$$$$$$$$$$$$$$\n");
    else if(i==3) printf("@@@@@@@@@@@@@@@\n");
    else if(i==4) printf("^^^^^^^^^^^^^^^\n");
}

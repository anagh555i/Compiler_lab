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
    void installFunction(node* f);
    void functionPreperation(Gsymbol *funct);
    bool isArithmetic(node* left, node* right);
    bool isBoolean(node* left, node* right);
    void prerequisites();
    void installDefaultTypes();
    void printTypes();

    node* root;          // AST root;
    Gsymbol* Ghead=NULL; // global symbol table head
    Lsymbol* Lhead=NULL; // global symbol table head
    Gsymbol* currFunction=NULL; // current function global symbol entry which is used in codeGen();
    Typetable* Types=NULL; // type table for the program;
    Fieldlist* Fields=NULL; // field list for the program;

    Typetable* POINTERTYPE=NULL;
    Typetable* VOIDTYPE=NULL;
    Typetable* INTTYPE=NULL;
    Typetable* STRINGTYPE=NULL;
    Typetable* ARRAYTYPE=NULL;
    Typetable* BOOLTYPE=NULL;

    FILE* outFile;
    int currReg;

    int space=0;
    int varBase=4096;
    int SP=4096;
    int label=0;
    int flabel=1;
    int WHILELABELS[]={-1,-1};// new list based while labels storage required
    Lnode* breakLabels=NULL;
    Lnode* continueLabels=NULL;
    node* functions=NULL;

#line 120 "y.tab.c"

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

#line 250 "y.tab.c"

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
  YYSYMBOL_MALLOC = 27,                    /* MALLOC  */
  YYSYMBOL_ARROW = 28,                     /* ARROW  */
  YYSYMBOL_Null = 29,                      /* Null  */
  YYSYMBOL_NUM = 30,                       /* NUM  */
  YYSYMBOL_ID = 31,                        /* ID  */
  YYSYMBOL_LITERAL = 32,                   /* LITERAL  */
  YYSYMBOL_MAIN = 33,                      /* MAIN  */
  YYSYMBOL_34_ = 34,                       /* '<'  */
  YYSYMBOL_35_ = 35,                       /* '>'  */
  YYSYMBOL_36_ = 36,                       /* '+'  */
  YYSYMBOL_37_ = 37,                       /* '-'  */
  YYSYMBOL_38_ = 38,                       /* '*'  */
  YYSYMBOL_39_ = 39,                       /* '/'  */
  YYSYMBOL_40_ = 40,                       /* '%'  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* '['  */
  YYSYMBOL_45_ = 45,                       /* ']'  */
  YYSYMBOL_46_ = 46,                       /* '('  */
  YYSYMBOL_47_ = 47,                       /* ')'  */
  YYSYMBOL_48_ = 48,                       /* ','  */
  YYSYMBOL_49_ = 49,                       /* '='  */
  YYSYMBOL_50_ = 50,                       /* '&'  */
  YYSYMBOL_51_ = 51,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_sourceCode = 53,                /* sourceCode  */
  YYSYMBOL_TypeDeclarations = 54,          /* TypeDeclarations  */
  YYSYMBOL_Typedefs = 55,                  /* Typedefs  */
  YYSYMBOL_Typedef = 56,                   /* Typedef  */
  YYSYMBOL_FieldList = 57,                 /* FieldList  */
  YYSYMBOL_Field = 58,                     /* Field  */
  YYSYMBOL_GDelcarations = 59,             /* GDelcarations  */
  YYSYMBOL_GDecList = 60,                  /* GDecList  */
  YYSYMBOL_ArrList = 61,                   /* ArrList  */
  YYSYMBOL_GDecl = 62,                     /* GDecl  */
  YYSYMBOL_VarList = 63,                   /* VarList  */
  YYSYMBOL_ParamList = 64,                 /* ParamList  */
  YYSYMBOL_Param = 65,                     /* Param  */
  YYSYMBOL_VarType = 66,                   /* VarType  */
  YYSYMBOL_FDefBlock = 67,                 /* FDefBlock  */
  YYSYMBOL_Fdef = 68,                      /* Fdef  */
  YYSYMBOL_MainBlock = 69,                 /* MainBlock  */
  YYSYMBOL_LdeclBlock = 70,                /* LdeclBlock  */
  YYSYMBOL_LDecList = 71,                  /* LDecList  */
  YYSYMBOL_LDecl = 72,                     /* LDecl  */
  YYSYMBOL_IdList = 73,                    /* IdList  */
  YYSYMBOL_Body = 74,                      /* Body  */
  YYSYMBOL_Slist = 75,                     /* Slist  */
  YYSYMBOL_Stmt = 76,                      /* Stmt  */
  YYSYMBOL_ReturnStmt = 77,                /* ReturnStmt  */
  YYSYMBOL_LoopStmt = 78,                  /* LoopStmt  */
  YYSYMBOL_Ifstmt = 79,                    /* Ifstmt  */
  YYSYMBOL_InputStmt = 80,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 81,                /* OutputStmt  */
  YYSYMBOL_AssgStmt = 82,                  /* AssgStmt  */
  YYSYMBOL_Array = 83,                     /* Array  */
  YYSYMBOL_Expr = 84,                      /* Expr  */
  YYSYMBOL_Var = 85,                       /* Var  */
  YYSYMBOL_ArgList = 86                    /* ArgList  */
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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   524

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  252

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


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
       2,     2,     2,     2,     2,     2,     2,    40,    50,     2,
      46,    47,    38,    36,    48,    37,    51,    39,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
      34,    49,    35,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   147,   147,   148,   151,   152,   154,   155,   157,   178,
     179,   181,   185,   192,   193,   195,   196,   198,   199,   201,
     219,   236,   244,   254,   255,   256,   257,   260,   261,   262,
     264,   270,   277,   282,   287,   288,   291,   316,   344,   358,
     359,   360,   362,   363,   365,   379,   380,   381,   382,   386,
     387,   389,   390,   392,   393,   394,   395,   396,   397,   398,
     399,   401,   402,   404,   405,   406,   408,   409,   411,   419,
     421,   427,   433,   446,   451,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     483,   490,   491,   492,   498,   502,   505,   518,   524,   528,
     532,   546,   559,   571,   575
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
  "RETURN", "TYPE", "ENDTYPE", "MALLOC", "ARROW", "Null", "NUM", "ID",
  "LITERAL", "MAIN", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'{'", "'}'", "';'", "'['", "']'", "'('", "')'", "','", "'='", "'&'",
  "'.'", "$accept", "sourceCode", "TypeDeclarations", "Typedefs",
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

#define YYPACT_NINF (-128)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,    49,    25,    20,  -128,    14,    92,  -128,  -128,    26,
      41,    28,  -128,  -128,  -128,  -128,  -128,    33,    79,   -20,
      63,   -12,    41,  -128,  -128,    23,    88,    28,  -128,  -128,
     161,   107,   113,   112,   116,   132,  -128,  -128,   146,   144,
    -128,  -128,   178,    79,    81,   163,   109,  -128,   177,    79,
     196,  -128,   200,   213,   219,   226,    82,   227,   242,  -128,
    -128,    79,    81,   235,   230,    79,  -128,   243,   245,    79,
    -128,   259,   246,   253,  -128,   269,   251,   254,  -128,  -128,
    -128,  -128,   262,    50,   303,   269,   266,  -128,  -128,    83,
     285,    79,   420,   267,   303,   269,   275,   286,   281,  -128,
    -128,   279,   288,   294,   295,   301,   283,   300,   310,   474,
     313,   327,   420,  -128,   316,  -128,  -128,   317,   325,   328,
     -22,  -128,   332,   303,    83,   322,  -128,   344,   474,   474,
     474,   420,  -128,  -128,   420,   330,  -128,  -128,    32,  -128,
     347,   327,   474,   327,   373,    -5,   474,   329,  -128,   -18,
    -128,   345,   383,  -128,  -128,  -128,   358,   474,   365,  -128,
     355,  -128,    83,   351,    97,   157,   176,   280,   360,   297,
      79,   452,  -128,  -128,    -5,   191,    -5,   474,   474,   474,
     474,   474,   474,   474,   474,   474,   474,   474,   474,   474,
     244,   474,   474,   400,  -128,  -128,   373,  -128,  -128,  -128,
    -128,  -128,   364,   374,   391,  -128,   394,   369,  -128,   142,
     370,  -128,   231,   438,   424,   134,    30,   384,   392,   433,
      87,    77,   103,   405,  -128,   313,   373,   373,  -128,   420,
     420,   403,   404,  -128,   474,  -128,  -128,   314,   331,   474,
     474,  -128,   432,  -128,   210,   225,   411,  -128,  -128,   420,
     348,  -128
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     5,     0,     0,     7,     1,     0,
       0,     0,     4,     6,    33,    14,    32,     0,    16,     0,
      33,     0,     0,    35,     3,     0,     0,    10,    13,    15,
      25,     0,     0,     0,     0,     0,    34,     2,     0,     0,
       8,     9,     0,    29,     0,     0,    26,    19,     0,    29,
       0,    11,     0,     0,     0,    28,     0,    25,     0,    23,
      20,    29,     0,     0,     0,    29,    12,    18,     0,    29,
      30,     0,    26,     0,    24,    41,     0,     0,    17,    21,
      27,    31,     0,     0,     0,    41,     0,    22,    40,     0,
       0,    43,     0,     0,     0,    41,    47,     0,     0,    39,
      42,     0,     0,     0,     0,     0,     0,     0,     0,    62,
     102,     0,     0,    52,     0,    58,    57,     0,     0,     0,
       0,    38,     0,     0,     0,    48,    44,     0,     0,     0,
       0,     0,    59,    60,     0,     0,    99,    91,   102,    93,
       0,     0,     0,     0,    61,    94,     0,     0,   102,     0,
      51,     0,    56,    53,    54,    55,     0,     0,     0,    36,
       0,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    97,    92,    96,     0,    95,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    56,    50,   101,    70,   100,    37,    46,
      68,    69,     0,     0,     0,    56,     0,     0,    90,   104,
       0,    88,    82,    83,    84,    85,    86,    87,    81,    80,
      75,    76,    77,    78,    79,    74,    72,    71,    49,     0,
       0,     0,     0,    98,     0,    89,    73,     0,     0,     0,
       0,   103,    67,    63,     0,     0,     0,    64,    65,     0,
       0,    66
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,  -128,  -128,   447,   427,  -128,  -128,   437,   389,
    -128,   -30,   -41,  -128,    -9,  -128,   435,   443,    16,   368,
    -128,  -119,   -78,  -127,  -109,   -62,  -128,  -128,  -128,  -128,
    -128,  -126,   -94,   -90,   232
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     6,     7,    26,    27,    10,    17,    45,
      18,    32,    54,    55,    56,    22,    23,    24,    84,    90,
      91,    98,    93,   112,   113,   168,   115,   116,   117,   118,
     119,   147,   209,   145,   210
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      19,    21,   120,   150,   167,   161,   156,   169,    64,    19,
     156,    30,   172,    21,    59,   144,   122,     1,    31,    34,
      73,   149,   120,   156,    77,     8,    35,   157,    80,   158,
     114,   192,    74,   158,   164,   165,   166,   177,   178,   179,
     180,   120,     9,   199,   120,   160,   158,    14,   175,    15,
     151,   174,   190,   176,    38,    11,    28,    16,   150,    25,
     150,    39,    20,   196,   183,   184,   185,   186,   187,   188,
     189,    14,    16,    88,    89,     4,   146,   120,   171,   120,
       5,    16,    89,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,    33,   226,   227,   236,
      14,    94,   237,   238,   177,   178,   179,   180,   181,   182,
      16,   123,    57,    70,    96,   187,   188,   189,    12,    58,
      71,    97,   250,     5,   186,   187,   188,   189,   150,   150,
      40,   183,   184,   185,   186,   187,   188,   189,    46,   120,
     120,   150,   188,   189,   201,   244,   245,   120,   120,   177,
     178,   179,   180,   181,   182,    61,    47,    62,    48,   120,
     120,   207,    49,    50,   177,   178,   179,   180,   181,   182,
     185,   186,   187,   188,   189,    52,   183,   184,   185,   186,
     187,   188,   189,   177,   178,   179,   180,   181,   182,    51,
     234,   183,   184,   185,   186,   187,   188,   189,   177,   178,
     179,   180,   181,   182,   202,    42,    60,    43,    53,    44,
     183,   184,   185,   186,   187,   188,   189,   177,   178,   179,
     180,   181,   182,   203,    63,   183,   184,   185,   186,   187,
     188,   189,   177,   178,   179,   180,   181,   182,   211,   178,
     179,   180,    65,    66,   183,   184,   185,   186,   187,   188,
     189,   177,   178,   179,   180,   181,   182,   247,    67,   183,
     184,   185,   186,   187,   188,   189,    68,   185,   186,   187,
     188,   189,   248,    72,    69,    44,    75,    76,   183,   184,
     185,   186,   187,   188,   189,   101,   102,    42,    79,   225,
      81,    83,    85,   103,    62,   104,   105,   106,   107,   108,
      82,    86,   101,   102,   109,    87,    92,    95,    99,   121,
     103,   110,   104,   105,   106,   107,   108,   125,   111,   101,
     102,   109,   204,   124,   126,   127,   132,   103,   110,   104,
     105,   106,   107,   108,   128,   111,   101,   102,   109,   206,
     129,   130,   131,   133,   103,   110,   104,   105,   106,   107,
     108,   134,   111,   101,   102,   109,   242,   146,   148,   152,
     153,   103,   110,   104,   105,   106,   107,   108,   154,   111,
     162,   155,   109,   243,   159,   163,   170,   173,   191,   110,
     177,   178,   179,   180,   181,   182,   111,   194,   193,   195,
     251,   177,   178,   179,   180,   181,   197,   198,   200,   177,
     178,   179,   180,   205,   228,   229,   231,   183,   184,   185,
     186,   187,   188,   189,   232,   230,   233,   235,   183,   184,
     185,   186,   187,   188,   189,   101,   102,   184,   185,   186,
     187,   188,   189,   103,   180,   104,   105,   106,   107,   108,
     177,   178,   179,   180,   109,   189,   246,   179,   180,   239,
     240,   110,   249,    13,    41,    29,    78,    36,   111,   100,
     185,   186,   187,   188,   189,    37,   241,     0,     0,   185,
     186,   187,   188,   189,   185,   186,   187,   188,   189,   135,
       0,   136,   137,   138,   139,     0,     0,     0,     0,   140,
     141,     0,     0,     0,     0,     0,     0,     0,   142,   208,
       0,   135,   143,   136,   137,   138,   139,     0,     0,     0,
       0,   140,   141,     0,     0,     0,     0,     0,     0,     0,
     142,     0,     0,     0,   143
};

static const yytype_int16 yycheck[] =
{
       9,    10,    92,   112,   131,   124,    28,   134,    49,    18,
      28,    31,   138,    22,    44,   109,    94,    25,    38,    31,
      61,   111,   112,    28,    65,     0,    38,    49,    69,    51,
      92,    49,    62,    51,   128,   129,   130,     7,     8,     9,
      10,   131,    22,   162,   134,   123,    51,    21,   142,    23,
     112,   141,   146,   143,    31,    41,    23,    31,   167,    31,
     169,    38,    21,   157,    34,    35,    36,    37,    38,    39,
      40,    21,    31,    23,    83,    26,    44,   167,    46,   169,
      31,    31,    91,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,    33,   191,   192,   225,
      21,    85,   229,   230,     7,     8,     9,    10,    11,    12,
      31,    95,    31,    31,    31,    38,    39,    40,    26,    38,
      38,    38,   249,    31,    37,    38,    39,    40,   237,   238,
      42,    34,    35,    36,    37,    38,    39,    40,    31,   229,
     230,   250,    39,    40,    47,   239,   240,   237,   238,     7,
       8,     9,    10,    11,    12,    46,    43,    48,    46,   249,
     250,   170,    46,    31,     7,     8,     9,    10,    11,    12,
      36,    37,    38,    39,    40,    31,    34,    35,    36,    37,
      38,    39,    40,     7,     8,     9,    10,    11,    12,    43,
      48,    34,    35,    36,    37,    38,    39,    40,     7,     8,
       9,    10,    11,    12,    47,    44,    43,    46,    30,    48,
      34,    35,    36,    37,    38,    39,    40,     7,     8,     9,
      10,    11,    12,    47,    47,    34,    35,    36,    37,    38,
      39,    40,     7,     8,     9,    10,    11,    12,    47,     8,
       9,    10,    46,    43,    34,    35,    36,    37,    38,    39,
      40,     7,     8,     9,    10,    11,    12,    47,    45,    34,
      35,    36,    37,    38,    39,    40,    47,    36,    37,    38,
      39,    40,    47,    31,    48,    48,    41,    47,    34,    35,
      36,    37,    38,    39,    40,     5,     6,    44,    43,    45,
      31,    22,    41,    13,    48,    15,    16,    17,    18,    19,
      47,    47,     5,     6,    24,    43,     3,    41,    23,    42,
      13,    31,    15,    16,    17,    18,    19,    31,    38,     5,
       6,    24,    42,    48,    43,    46,    43,    13,    31,    15,
      16,    17,    18,    19,    46,    38,     5,     6,    24,    42,
      46,    46,    41,    43,    13,    31,    15,    16,    17,    18,
      19,    41,    38,     5,     6,    24,    42,    44,    31,    43,
      43,    13,    31,    15,    16,    17,    18,    19,    43,    38,
      48,    43,    24,    42,    42,    31,    46,    30,    49,    31,
       7,     8,     9,    10,    11,    12,    38,     4,    43,    31,
      42,     7,     8,     9,    10,    11,    31,    42,    47,     7,
       8,     9,    10,    43,     4,    41,    15,    34,    35,    36,
      37,    38,    39,    40,    20,    41,    47,    47,    34,    35,
      36,    37,    38,    39,    40,     5,     6,    35,    36,    37,
      38,    39,    40,    13,    10,    15,    16,    17,    18,    19,
       7,     8,     9,    10,    24,    40,    14,     9,    10,    46,
      46,    31,    41,     6,    27,    18,    67,    22,    38,    91,
      36,    37,    38,    39,    40,    22,   234,    -1,    -1,    36,
      37,    38,    39,    40,    36,    37,    38,    39,    40,    27,
      -1,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,
      38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      -1,    27,    50,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    -1,    50
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    25,    53,    54,    26,    31,    55,    56,     0,    22,
      59,    41,    26,    56,    21,    23,    31,    60,    62,    66,
      21,    66,    67,    68,    69,    31,    57,    58,    23,    60,
      31,    38,    63,    33,    31,    38,    68,    69,    31,    38,
      42,    57,    44,    46,    48,    61,    31,    43,    46,    46,
      31,    43,    31,    30,    64,    65,    66,    31,    38,    63,
      43,    46,    48,    47,    64,    46,    43,    45,    47,    48,
      31,    38,    31,    64,    63,    41,    47,    64,    61,    43,
      64,    31,    47,    22,    70,    41,    47,    43,    23,    66,
      71,    72,     3,    74,    70,    41,    31,    38,    73,    23,
      71,     5,     6,    13,    15,    16,    17,    18,    19,    24,
      31,    38,    75,    76,    77,    78,    79,    80,    81,    82,
      85,    42,    74,    70,    48,    31,    43,    46,    46,    46,
      46,    41,    43,    43,    41,    27,    29,    30,    31,    32,
      37,    38,    46,    50,    84,    85,    44,    83,    31,    85,
      76,    77,    43,    43,    43,    43,    28,    49,    51,    42,
      74,    73,    48,    31,    84,    84,    84,    75,    77,    75,
      46,    46,    83,    30,    85,    84,    85,     7,     8,     9,
      10,    11,    12,    34,    35,    36,    37,    38,    39,    40,
      84,    49,    49,    43,     4,    31,    84,    31,    42,    73,
      47,    47,    47,    47,    42,    43,    42,    66,    47,    84,
      86,    47,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    45,    84,    84,     4,    41,
      41,    15,    20,    47,    48,    47,    83,    75,    75,    46,
      46,    86,    42,    42,    84,    84,    14,    47,    47,    41,
      75,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    53,    54,    54,    55,    55,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    62,    62,    63,    63,    63,    63,    64,    64,    64,
      65,    65,    66,    66,    67,    67,    68,    68,    69,    70,
      70,    70,    71,    71,    72,    73,    73,    73,    73,    74,
      74,    75,    75,    76,    76,    76,    76,    76,    76,    76,
      76,    77,    77,    78,    78,    78,    79,    79,    80,    81,
      82,    82,    82,    83,    83,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      85,    85,    85,    86,    86
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     3,     2,     2,     1,     4,     2,
       1,     3,     4,     3,     2,     2,     1,     4,     3,     3,
       4,     6,     7,     3,     4,     1,     2,     3,     1,     0,
       2,     3,     1,     1,     2,     1,     9,    10,     8,     3,
       2,     0,     2,     1,     3,     3,     4,     1,     2,     5,
       4,     2,     1,     2,     2,     2,     2,     1,     1,     2,
       2,     2,     1,     7,     8,     8,    11,     7,     4,     4,
       3,     4,     4,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       3,     1,     2,     1,     1,     2,     2,     2,     4,     1,
       3,     3,     1,     3,     1
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
  case 2: /* sourceCode: TypeDeclarations GDelcarations FDefBlock MainBlock  */
#line 147 "main.y"
                                                                       {}
#line 1529 "y.tab.c"
    break;

  case 3: /* sourceCode: TypeDeclarations GDelcarations MainBlock  */
#line 148 "main.y"
                                                             {}
#line 1535 "y.tab.c"
    break;

  case 4: /* TypeDeclarations: TYPE Typedefs ENDTYPE  */
#line 151 "main.y"
                                                {printTypes(); }
#line 1541 "y.tab.c"
    break;

  case 8: /* Typedef: ID '{' FieldList '}'  */
#line 157 "main.y"
                                                {   
                                                    if(lookUpType((yyvsp[-3].String))) yyerror("Type already defined");
                                                    InstallType((yyvsp[-3].String),0,NULL);
                                                    Fieldlist* ptr=(yyvsp[-1].fieldPtr);
                                                    int size=0;
                                                    for(;ptr;ptr=ptr->next){
                                                        Typetable *type=lookUpType(ptr->type->name);
                                                        printf("---- %s %s\n",ptr->name,ptr->type->name);
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
#line 1566 "y.tab.c"
    break;

  case 9: /* FieldList: Field FieldList  */
#line 178 "main.y"
                                                {(yyvsp[-1].fieldPtr)->next=(yyvsp[0].fieldPtr); (yyval.fieldPtr)=(yyvsp[-1].fieldPtr);}
#line 1572 "y.tab.c"
    break;

  case 10: /* FieldList: Field  */
#line 179 "main.y"
                                                {(yyval.fieldPtr)=(yyvsp[0].fieldPtr);}
#line 1578 "y.tab.c"
    break;

  case 11: /* Field: ID ID ';'  */
#line 181 "main.y"
                                                {
                                                    // don't do type checking yet, do it in Typedef
                                                    (yyval.fieldPtr)=makeField((yyvsp[-1].String),0,makeTypeNode((yyvsp[-2].String)),NULL);
                                                }
#line 1587 "y.tab.c"
    break;

  case 12: /* Field: ID '*' ID ';'  */
#line 185 "main.y"
                                                {
                                                    // don't do type checking yet, do it in Typedef
                                                    (yyval.fieldPtr)=makeField((yyvsp[-1].String),0,makeTypeNode(strdup("pointer")),NULL);
                                                    (yyval.fieldPtr)->ptrType=makeTypeNode((yyvsp[-3].String));
                                                }
#line 1597 "y.tab.c"
    break;

  case 13: /* GDelcarations: DECL GDecList ENDDECL  */
#line 192 "main.y"
                                                 {}
#line 1603 "y.tab.c"
    break;

  case 14: /* GDelcarations: DECL ENDDECL  */
#line 193 "main.y"
                                                {}
#line 1609 "y.tab.c"
    break;

  case 15: /* GDecList: GDecl GDecList  */
#line 195 "main.y"
                                                  {}
#line 1615 "y.tab.c"
    break;

  case 16: /* GDecList: GDecl  */
#line 196 "main.y"
                                                 {}
#line 1621 "y.tab.c"
    break;

  case 17: /* ArrList: '[' NUM ']' ArrList  */
#line 198 "main.y"
                                                {(yyval.listPtr)=makeLnode("",(yyvsp[-2].Int),(yyvsp[0].listPtr));}
#line 1627 "y.tab.c"
    break;

  case 18: /* ArrList: '[' NUM ']'  */
#line 199 "main.y"
                                                {(yyval.listPtr)=makeLnode("",(yyvsp[-1].Int),NULL);}
#line 1633 "y.tab.c"
    break;

  case 19: /* GDecl: VarType VarList ';'  */
#line 201 "main.y"
                                                    {
                                                  Lnode* ptr=(yyvsp[-1].listPtr);
                                                  if((yyvsp[-2].typePtr)->size<1) yyerror("Type cannot be declared");
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
#line 1656 "y.tab.c"
    break;

  case 20: /* GDecl: VarType ID ArrList ';'  */
#line 219 "main.y"
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
                                                    printf("SIZE OF ARRAY IS %d\n",size);
                                                    installG((yyvsp[-2].String),ARRAYTYPE,size,SP);
                                                    SP+=size;
                                                    // Gsymbol* g=lookUpG($2);
                                                    Ghead->dim=makeLnode("",dim,(yyvsp[-1].listPtr));
                                                    Ghead->ptrType=(yyvsp[-3].typePtr);
                                                }
#line 1678 "y.tab.c"
    break;

  case 21: /* GDecl: VarType ID '(' ParamList ')' ';'  */
#line 236 "main.y"
                                                           {
                                                            if(lookUpG((yyvsp[-4].String))) yyerror("variable already declared");
                                                            if((yyvsp[-5].typePtr)->size>1) yyerror("return type of size>1 not yet possible");
                                                            installG((yyvsp[-4].String),(yyvsp[-5].typePtr),0,0);
                                                            Ghead->flabel=flabel++; // assign label and mark variable as function 
                                                            Ghead->paramlist=Lhead;
                                                            Lhead=NULL; // clear Lhead for other parameters
                                                        }
#line 1691 "y.tab.c"
    break;

  case 22: /* GDecl: VarType '*' ID '(' ParamList ')' ';'  */
#line 244 "main.y"
                                                            {
                                                            if((yyvsp[-6].typePtr)->size<1) yyerror("pointer of Type cannot be declared");
                                                            if(lookUpG((yyvsp[-4].String))) yyerror("variable already declared");
                                                            installG((yyvsp[-4].String),POINTERTYPE,0,0);
                                                            Ghead->ptrType=(yyvsp[-6].typePtr);
                                                            Ghead->flabel=flabel++; // assign label and mark variable as function 
                                                            Ghead->paramlist=Lhead;
                                                            Lhead=NULL; // clear Lhead for other parameters
                                                        }
#line 1705 "y.tab.c"
    break;

  case 23: /* VarList: ID ',' VarList  */
#line 254 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[-2].String),valtype,(yyvsp[0].listPtr));}
#line 1711 "y.tab.c"
    break;

  case 24: /* VarList: '*' ID ',' VarList  */
#line 255 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[-2].String),ptrtype,(yyvsp[0].listPtr));}
#line 1717 "y.tab.c"
    break;

  case 25: /* VarList: ID  */
#line 256 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),valtype,NULL);}
#line 1723 "y.tab.c"
    break;

  case 26: /* VarList: '*' ID  */
#line 257 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),ptrtype,NULL);}
#line 1729 "y.tab.c"
    break;

  case 27: /* ParamList: Param ',' ParamList  */
#line 260 "main.y"
                                    {}
#line 1735 "y.tab.c"
    break;

  case 28: /* ParamList: Param  */
#line 261 "main.y"
                                    {}
#line 1741 "y.tab.c"
    break;

  case 29: /* ParamList: %empty  */
#line 262 "main.y"
                                    {}
#line 1747 "y.tab.c"
    break;

  case 30: /* Param: VarType ID  */
#line 264 "main.y"
                                    {   //printf("Type type=%d\n",$1);
                                        // if($1 != inttype && $1!=strtype && $1!=intptrtype && $1!=strptrtype) yyerror("forbidden type for paramteres");
                                        if((yyvsp[-1].typePtr)->size<1) yyerror("Type cannot be declared");
                                        if(lookUpL((yyvsp[0].String))) yyerror("duplicate parameter");
                                        installL((yyvsp[0].String),(yyvsp[-1].typePtr),NULL,-1); // add parameter to Lhead 
                                    }
#line 1758 "y.tab.c"
    break;

  case 31: /* Param: VarType '*' ID  */
#line 270 "main.y"
                                    {   //printf("Type type=%d\n",$1);
                                        if((yyvsp[-2].typePtr)->size<1) yyerror("Pointer Type cannot be declared");
                                        if(lookUpL((yyvsp[0].String))) yyerror("duplicate parameter");
                                        installL((yyvsp[0].String),POINTERTYPE,(yyvsp[-2].typePtr),-1); // add parameter to Lhead 
                                    }
#line 1768 "y.tab.c"
    break;

  case 32: /* VarType: ID  */
#line 277 "main.y"
                        {
                            Typetable* type=lookUpType((yyvsp[0].String));
                            if(type==NULL) yyerror("undefined type");
                            (yyval.typePtr)=type;
                        }
#line 1778 "y.tab.c"
    break;

  case 33: /* VarType: VOID  */
#line 282 "main.y"
                        {
                            (yyval.typePtr)=VOIDTYPE;
                        }
#line 1786 "y.tab.c"
    break;

  case 36: /* Fdef: VarType ID '(' ParamList ')' '{' LdeclBlock Body '}'  */
#line 291 "main.y"
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
#line 1816 "y.tab.c"
    break;

  case 37: /* Fdef: VarType '*' ID '(' ParamList ')' '{' LdeclBlock Body '}'  */
#line 316 "main.y"
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
#line 1847 "y.tab.c"
    break;

  case 38: /* MainBlock: VOID MAIN '(' ')' '{' LdeclBlock Body '}'  */
#line 344 "main.y"
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
#line 1865 "y.tab.c"
    break;

  case 44: /* LDecl: VarType IdList ';'  */
#line 365 "main.y"
                                   {
                                    Lnode* ptr=(yyvsp[-1].listPtr);
                                    if((yyvsp[-2].typePtr)->size<1) yyerror("Type cannot be declared");
                                    for(;ptr;ptr=ptr->next){
                                        if(lookUpL(ptr->s)) yyerror("variable already declared");
                                        if(ptr->num == valtype){
                                            installL(ptr->s,(yyvsp[-2].typePtr),NULL,-1);
                                        }
                                        else{
                                            installL(ptr->s,POINTERTYPE,(yyvsp[-2].typePtr),-1);
                                        }
                                    }
                                }
#line 1883 "y.tab.c"
    break;

  case 45: /* IdList: ID ',' IdList  */
#line 379 "main.y"
                                {(yyval.listPtr)=makeLnode((yyvsp[-2].String),valtype,(yyvsp[0].listPtr));}
#line 1889 "y.tab.c"
    break;

  case 46: /* IdList: '*' ID ',' IdList  */
#line 380 "main.y"
                                {(yyval.listPtr)=makeLnode((yyvsp[-2].String),ptrtype,(yyvsp[0].listPtr));}
#line 1895 "y.tab.c"
    break;

  case 47: /* IdList: ID  */
#line 381 "main.y"
                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),valtype,NULL);}
#line 1901 "y.tab.c"
    break;

  case 48: /* IdList: '*' ID  */
#line 382 "main.y"
                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),ptrtype,NULL);}
#line 1907 "y.tab.c"
    break;

  case 49: /* Body: begin Slist ReturnStmt ';' end  */
#line 386 "main.y"
                                                {(yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tCONNECT,(yyvsp[-3].nodePtr),(yyvsp[-2].nodePtr),NULL);}
#line 1913 "y.tab.c"
    break;

  case 50: /* Body: begin ReturnStmt ';' end  */
#line 387 "main.y"
                                                {(yyval.nodePtr)=(yyvsp[-2].nodePtr);}
#line 1919 "y.tab.c"
    break;

  case 51: /* Slist: Slist Stmt  */
#line 389 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tCONNECT,(yyvsp[-1].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1925 "y.tab.c"
    break;

  case 52: /* Slist: Stmt  */
#line 390 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 1931 "y.tab.c"
    break;

  case 53: /* Stmt: InputStmt ';'  */
#line 392 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1937 "y.tab.c"
    break;

  case 54: /* Stmt: OutputStmt ';'  */
#line 393 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1943 "y.tab.c"
    break;

  case 55: /* Stmt: AssgStmt ';'  */
#line 394 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1949 "y.tab.c"
    break;

  case 56: /* Stmt: ReturnStmt ';'  */
#line 395 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1955 "y.tab.c"
    break;

  case 57: /* Stmt: Ifstmt  */
#line 396 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 1961 "y.tab.c"
    break;

  case 58: /* Stmt: LoopStmt  */
#line 397 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 1967 "y.tab.c"
    break;

  case 59: /* Stmt: BREAK ';'  */
#line 398 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tBREAK,NULL,NULL,NULL);}
#line 1973 "y.tab.c"
    break;

  case 60: /* Stmt: CONTINUE ';'  */
#line 399 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tCONTINUE,NULL,NULL,NULL);}
#line 1979 "y.tab.c"
    break;

  case 61: /* ReturnStmt: RETURN Expr  */
#line 401 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tRETURN,(yyvsp[0].nodePtr),(yyvsp[0].nodePtr),(yyvsp[0].nodePtr));}
#line 1985 "y.tab.c"
    break;

  case 62: /* ReturnStmt: RETURN  */
#line 402 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tRETURN,NULL,NULL,NULL);}
#line 1991 "y.tab.c"
    break;

  case 63: /* LoopStmt: WHILE '(' Expr ')' '{' Slist '}'  */
#line 404 "main.y"
                                                    {if(isBoolean((yyvsp[-4].nodePtr),(yyvsp[-4].nodePtr))) (yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tWHILE,(yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr),(yyvsp[-4].nodePtr));}
#line 1997 "y.tab.c"
    break;

  case 64: /* LoopStmt: DO '{' Slist '}' WHILE '(' Expr ')'  */
#line 405 "main.y"
                                                                {if(isBoolean((yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr))) (yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tDOWHILE,(yyvsp[-5].nodePtr),(yyvsp[-5].nodePtr),(yyvsp[-1].nodePtr));}
#line 2003 "y.tab.c"
    break;

  case 65: /* LoopStmt: REPEAT '{' Slist '}' UNTIL '(' Expr ')'  */
#line 406 "main.y"
                                                                    {if(isBoolean((yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr))) (yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tREPEATUNTIL,(yyvsp[-5].nodePtr),(yyvsp[-5].nodePtr),(yyvsp[-1].nodePtr));}
#line 2009 "y.tab.c"
    break;

  case 66: /* Ifstmt: IF '(' Expr ')' '{' Slist '}' Else '{' Slist '}'  */
#line 408 "main.y"
                                                             {if(isBoolean((yyvsp[-8].nodePtr),(yyvsp[-8].nodePtr))) (yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tIF,(yyvsp[-5].nodePtr),(yyvsp[-1].nodePtr),(yyvsp[-8].nodePtr));}
#line 2015 "y.tab.c"
    break;

  case 67: /* Ifstmt: IF '(' Expr ')' '{' Slist '}'  */
#line 409 "main.y"
                                                    {if(isBoolean((yyvsp[-4].nodePtr),(yyvsp[-4].nodePtr))) (yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tIF,(yyvsp[-1].nodePtr),NULL,(yyvsp[-4].nodePtr));}
#line 2021 "y.tab.c"
    break;

  case 68: /* InputStmt: READ '(' ID ')'  */
#line 411 "main.y"
                                    { //////ADJUST FOR VAR
                                    Gsymbol* Gptr=lookUpG((yyvsp[-1].String));
                                    Lsymbol* Lptr=lookUpL((yyvsp[-1].String));
                                    if(Gptr==NULL && Lptr==NULL) yyerror("undeclared Variable");
                                    node* temp=makeNode(0,NULL,Gptr,Lptr,tVAR,NULL,NULL,NULL);
                                    (yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tREAD,temp,temp,NULL);
                                    }
#line 2033 "y.tab.c"
    break;

  case 69: /* OutputStmt: WRITE '(' Expr ')'  */
#line 419 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tWRITE,(yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr),NULL);}
#line 2039 "y.tab.c"
    break;

  case 70: /* AssgStmt: Var '=' Expr  */
#line 421 "main.y"
                                    {
                                    printf("types: %s\n",(yyvsp[-2].nodePtr)->right->type->name);
                                    printf("types: %s\n",(yyvsp[0].nodePtr)->type->name);
                                    if((yyvsp[-2].nodePtr)->right->type!=(yyvsp[0].nodePtr)->type) yyerror("assignment type mismatch");
                                    (yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tASSIGN,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);
                                    }
#line 2050 "y.tab.c"
    break;

  case 71: /* AssgStmt: '*' Var '=' Expr  */
#line 427 "main.y"
                                    {
                                    if((yyvsp[-2].nodePtr)->right->type!=POINTERTYPE) yyerror("pointer assignment type mismatch");
                                    if((yyvsp[-2].nodePtr)->right->ptrType!=(yyvsp[0].nodePtr)->type) yyerror("Pointer type mismatch");
                                    node* ptr=makeNode(0,NULL,NULL,NULL,tGETADDRATVAL,(yyvsp[-2].nodePtr),NULL,NULL);
                                    (yyval.nodePtr)=makeNode(0,NULL,NULL,NULL,tASSIGN,ptr,(yyvsp[0].nodePtr),NULL);
                                    }
#line 2061 "y.tab.c"
    break;

  case 72: /* AssgStmt: ID Array '=' Expr  */
#line 433 "main.y"
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
#line 2078 "y.tab.c"
    break;

  case 73: /* Array: '[' Expr ']' Array  */
#line 446 "main.y"
                                       {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[-2].nodePtr))){
                                            (yyvsp[-2].nodePtr)->left=(yyvsp[0].nodePtr);
                                            (yyval.nodePtr)=(yyvsp[-2].nodePtr);
                                        }
                                      }
#line 2088 "y.tab.c"
    break;

  case 74: /* Array: '[' Expr ']'  */
#line 451 "main.y"
                                       {if(isArithmetic((yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr))) (yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 2094 "y.tab.c"
    break;

  case 75: /* Expr: Expr '+' Expr  */
#line 454 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,INTTYPE,NULL,NULL,tADD,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2100 "y.tab.c"
    break;

  case 76: /* Expr: Expr '-' Expr  */
#line 455 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,INTTYPE,NULL,NULL,tSUB,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2106 "y.tab.c"
    break;

  case 77: /* Expr: Expr '*' Expr  */
#line 456 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,INTTYPE,NULL,NULL,tMUL,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2112 "y.tab.c"
    break;

  case 78: /* Expr: Expr '/' Expr  */
#line 457 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,INTTYPE,NULL,NULL,tDIV,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2118 "y.tab.c"
    break;

  case 79: /* Expr: Expr '%' Expr  */
#line 458 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,INTTYPE,NULL,NULL,tMOD,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2124 "y.tab.c"
    break;

  case 80: /* Expr: Expr '>' Expr  */
#line 459 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,BOOLTYPE,NULL,NULL,tGT,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2130 "y.tab.c"
    break;

  case 81: /* Expr: Expr '<' Expr  */
#line 460 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,BOOLTYPE,NULL,NULL,tLT,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2136 "y.tab.c"
    break;

  case 82: /* Expr: Expr GE Expr  */
#line 461 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,BOOLTYPE,NULL,NULL,tGE,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2142 "y.tab.c"
    break;

  case 83: /* Expr: Expr LE Expr  */
#line 462 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,BOOLTYPE,NULL,NULL,tLE,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2148 "y.tab.c"
    break;

  case 84: /* Expr: Expr EQ Expr  */
#line 463 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,BOOLTYPE,NULL,NULL,tEQ,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2154 "y.tab.c"
    break;

  case 85: /* Expr: Expr NEQ Expr  */
#line 464 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,BOOLTYPE,NULL,NULL,tNEQ,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2160 "y.tab.c"
    break;

  case 86: /* Expr: Expr AND Expr  */
#line 465 "main.y"
                                    {if(isBoolean((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,BOOLTYPE,NULL,NULL,tAND,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2166 "y.tab.c"
    break;

  case 87: /* Expr: Expr OR Expr  */
#line 466 "main.y"
                                    {if(isBoolean((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,BOOLTYPE,NULL,NULL,tOR,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 2172 "y.tab.c"
    break;

  case 88: /* Expr: '(' Expr ')'  */
#line 467 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 2178 "y.tab.c"
    break;

  case 89: /* Expr: ID '(' ArgList ')'  */
#line 468 "main.y"
                                     {
                                        Gsymbol* fg=lookUpG((yyvsp[-3].String));
                                        if(!fg) yyerror("function not defined");
                                        node* ptr=(yyvsp[-1].nodePtr);
                                        Lsymbol* ld=fg->paramlist;
                                        for(;ptr && ld;ld=ld->next,ptr=ptr->center){
                                            if(ptr->type!=ld->type) {
                                                printf("%s, %s %s\n",ptr->type->name,ld->name,ld->type->name);
                                                yyerror("type mismatch");
                                            }
                                        }
                                        if(ptr) yyerror("error in argument list");
                                        if(ld && ld->binding<0) yyerror("error in argument list");
                                        (yyval.nodePtr)=makeNode(0,fg->type,fg,NULL,tFUNCTCALL,(yyvsp[-1].nodePtr),NULL,NULL); //left contains argument list for function call
                                    }
#line 2198 "y.tab.c"
    break;

  case 90: /* Expr: ID '(' ')'  */
#line 483 "main.y"
                                    {
                                        Gsymbol* fg=lookUpG((yyvsp[-2].String));
                                        if(!fg) yyerror("function not defined");
                                        Lsymbol* ld=fg->paramlist;
                                        if(ld && ld->binding<0) yyerror("error in argument list");
                                        (yyval.nodePtr)=makeNode(0,fg->type,fg,NULL,tFUNCTCALL,NULL,NULL,NULL); //left contains argument list for function call
                                    }
#line 2210 "y.tab.c"
    break;

  case 91: /* Expr: NUM  */
#line 490 "main.y"
                                    {(yyval.nodePtr)=makeNode((yyvsp[0].Int),INTTYPE,NULL,NULL,tCONST,NULL,NULL,NULL);}
#line 2216 "y.tab.c"
    break;

  case 92: /* Expr: '-' NUM  */
#line 491 "main.y"
                                    {(yyval.nodePtr)=makeNode(-1*(yyvsp[0].Int),INTTYPE,NULL,NULL,tCONST,NULL,NULL,NULL);}
#line 2222 "y.tab.c"
    break;

  case 93: /* Expr: LITERAL  */
#line 492 "main.y"
                                    {
                                     printf("STARTED parsing literal");
                                     (yyval.nodePtr)=makeNode(0,STRINGTYPE,NULL,NULL,tLITERAL,NULL,NULL,NULL);
                                     (yyval.nodePtr)->literal=(yyvsp[0].String);
                                     printf("FINISHED parsing literal");
                                    }
#line 2233 "y.tab.c"
    break;

  case 94: /* Expr: Var  */
#line 498 "main.y"
                                    {
                                    (yyval.nodePtr)=makeNode(0,(yyvsp[0].nodePtr)->right->type,NULL,NULL,tGETVAL,(yyvsp[0].nodePtr),NULL,NULL);
                                    (yyval.nodePtr)->ptrType=(yyvsp[0].nodePtr)->right->ptrType;
                                    }
#line 2242 "y.tab.c"
    break;

  case 95: /* Expr: '&' Var  */
#line 502 "main.y"
                                    {
                                    (yyval.nodePtr)=(yyvsp[0].nodePtr);
                                    }
#line 2250 "y.tab.c"
    break;

  case 96: /* Expr: '*' Var  */
#line 505 "main.y"
                                    {
                                    if((yyvsp[0].nodePtr)->right->type!=POINTERTYPE) yyerror("not pointer variable");
                                    (yyval.nodePtr)=makeNode(0,(yyvsp[0].nodePtr)->right->ptrType,NULL,NULL,tVALUEAT,(yyvsp[0].nodePtr),NULL,NULL);
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
#line 2268 "y.tab.c"
    break;

  case 97: /* Expr: ID Array  */
#line 518 "main.y"
                                {
                                    Gsymbol* ptr=lookUpG((yyvsp[-1].String));
                                    if(!ptr) yyerror("variable undeclared");
                                    if(ptr->type!=ARRAYTYPE) yyerror("type mismatch");
                                    (yyval.nodePtr)=makeNode(0,ptr->ptrType,ptr,NULL,tARRVAL,(yyvsp[0].nodePtr),(yyvsp[0].nodePtr),(yyvsp[0].nodePtr));
                                }
#line 2279 "y.tab.c"
    break;

  case 98: /* Expr: MALLOC '(' VarType ')'  */
#line 524 "main.y"
                                    {
                                        (yyval.nodePtr)=makeNode(0,POINTERTYPE,NULL,NULL,tMALLOC,NULL,NULL,NULL);
                                        (yyval.nodePtr)->ptrType=(yyvsp[-1].typePtr);
                                    }
#line 2288 "y.tab.c"
    break;

  case 99: /* Expr: Null  */
#line 528 "main.y"
                                {
                                    (yyval.nodePtr)=makeNode(0,POINTERTYPE,NULL,NULL,tNULL,NULL,NULL,NULL);
                                }
#line 2296 "y.tab.c"
    break;

  case 100: /* Var: Var '.' ID  */
#line 532 "main.y"
                            {
                                printf("##\n");
                                if((yyvsp[-2].nodePtr)->right->type==POINTERTYPE) yyerror("Static access from pointer variable");  
                                printf("##\n");
                                Fieldlist* field=LookupField((yyvsp[-2].nodePtr)->right->type,(yyvsp[0].String)); 
                                printf("##\n");
                                if(field==NULL) yyerror("NO such field");  
                                printf("##\n");
                                node* var=makeNode(field->fieldIndex,field->type,NULL,NULL,tCONST,NULL,NULL,NULL); 
                                printf("##\n");
                                var->ptrType=field->ptrType; 
                                printf("##\n");
                                (yyval.nodePtr)=makeNode(0,POINTERTYPE,NULL,NULL,tRECURSADDR,(yyvsp[-2].nodePtr),var,NULL) ;                   
                            }
#line 2315 "y.tab.c"
    break;

  case 101: /* Var: Var ARROW ID  */
#line 546 "main.y"
                           {
                                printf("##\n");
                                if((yyvsp[-2].nodePtr)->right->type!=POINTERTYPE) yyerror("pointer access from static type");
                                printf("##\n");
                                printf("x->%s type: %s\n",(yyvsp[0].String),(yyvsp[-2].nodePtr)->right->type->name);
                                printf("%s\n",(yyvsp[-2].nodePtr)->right->ptrType->name);
                                Fieldlist* field=LookupField((yyvsp[-2].nodePtr)->right->ptrType,(yyvsp[0].String));
                                printf("field name: %s\n",field->name);
                                if(field==NULL) yyerror("NO such field");
                                node* var=makeNode(field->fieldIndex,field->type,NULL,NULL,tCONST,NULL,NULL,NULL);
                                var->ptrType=field->ptrType;
                                (yyval.nodePtr)=makeNode(0,POINTERTYPE,NULL,NULL,tRECURSADDRATVAL,(yyvsp[-2].nodePtr),var,NULL) ;
                            }
#line 2333 "y.tab.c"
    break;

  case 102: /* Var: ID  */
#line 559 "main.y"
                            {
                                printf("From expr %s\n",(yyvsp[0].String));
                                Gsymbol* Gptr=lookUpG((yyvsp[0].String));
                                Lsymbol* Lptr=lookUpL((yyvsp[0].String));
                                if(Lptr==NULL && Gptr==NULL) yyerror("undelcared variable");
                                node* var=makeNode(0,(Lptr?Lptr->type:Gptr->type),Gptr,Lptr,tVAR,NULL,NULL,NULL);
                                var->ptrType=Lptr?Lptr->ptrType:Gptr->ptrType;
                                (yyval.nodePtr)=makeNode(0,POINTERTYPE,NULL,NULL,tADDRESSOF,var,var,NULL) ;
                                (yyval.nodePtr)->ptrType=Lptr?Lptr->type:Gptr->type;
                            }
#line 2348 "y.tab.c"
    break;

  case 103: /* ArgList: Expr ',' ArgList  */
#line 571 "main.y"
                            {   // argument list will be linked with center pointer
                                (yyvsp[-2].nodePtr)->center=(yyvsp[0].nodePtr);
                                (yyval.nodePtr)=(yyvsp[-2].nodePtr);
                            }
#line 2357 "y.tab.c"
    break;

  case 104: /* ArgList: Expr  */
#line 575 "main.y"
                            {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 2363 "y.tab.c"
    break;


#line 2367 "y.tab.c"

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

#line 578 "main.y"


int main(){
    FILE *fp=fopen("ExtendedEuclidean.c","r");
    outFile=fopen("a.xsm","w");
    yyin=fp;
    SP=4096;
    installDefaultTypes();
    yyparse();
    Gsymbol* ptr=Ghead;
    if(!ptr) printf("What\n");
    for(;ptr;ptr=ptr->next)printf("%s ",ptr->name);
    printf("parsing complete\n");

    space=0;
    /* printTree(root); */

    genHeader();
    prerequisites(); // set stack pointer to after declarations
    
    printf("functions\n");
    for(;functions;functions=functions->left){
        printf("#######\n");
        continueLabels=NULL;
        breakLabels=NULL;
        Lhead=functions->Lvar;
        currFunction=functions->Gvar;
        currReg=0;
        functionPreperation(currFunction);
        /* printf("function preperation done %s\n",currFunction->name); */
        genCode(functions->right);
    }
    /* int reg=genCode(root); */
    printf("codeGen completed\n");
    genSegmenationFault();
    genErrorHandler();
    genExit();
    return 0;
}

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
    printf("********************************************************\n");
    exit(0);
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
    printf("okay function prepared\n");
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


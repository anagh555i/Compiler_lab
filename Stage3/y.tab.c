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
    // #include "lex.yy.h"

    extern FILE *yyin;
    extern void yyerror(char* s);
    extern int yylex();

    #define inttype 0
    #define booltype 1

    typedef struct node{
        int val;    //leaf node val
        int type;   // type of variable inttype or booltype
        char *varname;  // name of variable
        int nodeType; // leaf node info read/write/+/*/...
        struct node* left;
        struct node* right;
        struct node* center; // for storing if and while condition
    }node;

    int variables[26];
    int evalCB=0;
    node* root;

    node* makeNode(int val,int type,char varname,int nodeType,node* left,node* right,node* center);
    #define tCONNECT 0 //connector
    #define tCONST 1 //constant value
    #define tVAR 2 //variable
    #define tREAD 3   //read
    #define tWRITE 4 //write
    #define tADD 5 // +
    #define tSUB 6 // - 
    #define tMUL 7 // *
    #define tDIV 8 // /
    #define tASSIGN 9 // =
    #define tLT 10 // <
    #define tGT 11 // >
    #define tLE 12 // <=
    #define tGE 13 // >=
    #define tEQ 14 // ==
    #define tNEQ 15 // !=
    #define tAND 16 // AND
    #define tOR 17 // OR
    #define tIF 18 // IF node
    #define tWHILE 19 // WHILE node
    #define tDOWHILE 20 //DO WHILE node
    #define tREPEATUNTIL 21 //DO WHILE node
    #define tBREAK 22 // break
    #define tCONTINUE 23 // continue
    //makeNode(val,type,varname,nodeType,left,right,center);

    FILE* outFile;
    int currReg;

    int genCode(node* root);
    void genVarSpaceCode();
    void genHeader();
    int getReg();
    void freeReg();
    void handleWrite(int Wreg);
    void handleRead(node* root);
    int handleArithmetic(node* root);
    void handleAssignment(node* root);
    void genExit();
    void handleIfElse(node* root);
    int handleComparison(node* root);
    void handleWhile(node* root);
    void handleDoWhile(node* root);
    void handleRepeatUntil(node* root);

    bool isArithmetic(node* left, node* right);
    bool isBoolean(node* left, node* right);

    void printTree(node* root);
    int evaluator(node* root);

    int space=0;
    const int varBase=4096;
    int label=0;
    int WHILELABELS[]={-1,-1};

#line 156 "y.tab.c"

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
    then = 269,                    /* then  */
    Else = 270,                    /* Else  */
    ENDIF = 271,                   /* ENDIF  */
    WHILE = 272,                   /* WHILE  */
    DO = 273,                      /* DO  */
    ENDWHILE = 274,                /* ENDWHILE  */
    BREAK = 275,                   /* BREAK  */
    CONTINUE = 276,                /* CONTINUE  */
    REPEAT = 277,                  /* REPEAT  */
    UNTIL = 278,                   /* UNTIL  */
    NUM = 279,                     /* NUM  */
    ID = 280                       /* ID  */
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
#define then 269
#define Else 270
#define ENDIF 271
#define WHILE 272
#define DO 273
#define ENDWHILE 274
#define BREAK 275
#define CONTINUE 276
#define REPEAT 277
#define UNTIL 278
#define NUM 279
#define ID 280

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 87 "main.y"

    int Int;
    char Char;
    struct node* nodePtr;

#line 265 "y.tab.c"

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
  YYSYMBOL_then = 14,                      /* then  */
  YYSYMBOL_Else = 15,                      /* Else  */
  YYSYMBOL_ENDIF = 16,                     /* ENDIF  */
  YYSYMBOL_WHILE = 17,                     /* WHILE  */
  YYSYMBOL_DO = 18,                        /* DO  */
  YYSYMBOL_ENDWHILE = 19,                  /* ENDWHILE  */
  YYSYMBOL_BREAK = 20,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 21,                  /* CONTINUE  */
  YYSYMBOL_REPEAT = 22,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 23,                     /* UNTIL  */
  YYSYMBOL_NUM = 24,                       /* NUM  */
  YYSYMBOL_ID = 25,                        /* ID  */
  YYSYMBOL_26_ = 26,                       /* '<'  */
  YYSYMBOL_27_ = 27,                       /* '>'  */
  YYSYMBOL_28_ = 28,                       /* '+'  */
  YYSYMBOL_29_ = 29,                       /* '-'  */
  YYSYMBOL_30_ = 30,                       /* '*'  */
  YYSYMBOL_31_ = 31,                       /* '/'  */
  YYSYMBOL_32_ = 32,                       /* ';'  */
  YYSYMBOL_33_ = 33,                       /* '('  */
  YYSYMBOL_34_ = 34,                       /* ')'  */
  YYSYMBOL_35_ = 35,                       /* '='  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_Program = 37,                   /* Program  */
  YYSYMBOL_Slist = 38,                     /* Slist  */
  YYSYMBOL_Stmt = 39,                      /* Stmt  */
  YYSYMBOL_LoopStmt = 40,                  /* LoopStmt  */
  YYSYMBOL_Ifstmt = 41,                    /* Ifstmt  */
  YYSYMBOL_InputStmt = 42,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 43,                /* OutputStmt  */
  YYSYMBOL_AssgStmt = 44,                  /* AssgStmt  */
  YYSYMBOL_Expr = 45                       /* Expr  */
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
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   354

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  10
/* YYNRULES -- Number of rules.  */
#define YYNRULES  35
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  92

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


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
      33,    34,    30,    28,     2,    29,     2,    31,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    32,
      26,    35,    27,     2,     2,     2,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   143,   143,   144,   146,   147,   149,   150,   151,   152,
     153,   154,   155,   157,   158,   159,   161,   162,   164,   169,
     171,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190
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
  "WRITE", "GE", "LE", "EQ", "NEQ", "AND", "OR", "IF", "then", "Else",
  "ENDIF", "WHILE", "DO", "ENDWHILE", "BREAK", "CONTINUE", "REPEAT",
  "UNTIL", "NUM", "ID", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "';'",
  "'('", "')'", "'='", "$accept", "Program", "Slist", "Stmt", "LoopStmt",
  "Ifstmt", "InputStmt", "OutputStmt", "AssgStmt", "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-23)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   240,    14,   -23,   -11,    11,    12,    22,   323,   -17,
      24,   323,    28,   250,   -23,    25,    26,    32,    44,    45,
     -23,    53,   -16,   -16,   -16,   329,   -23,   -23,   274,   -16,
     -23,   -23,   -23,   -23,   -23,   -23,   -23,    46,   -23,   -23,
     -16,    39,    75,    84,    55,    56,   158,   -23,   112,   -16,
     -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,   -16,
     -16,   -23,    76,    79,   -16,   -16,   -23,    31,   221,    -5,
     -18,   189,   183,   194,   198,    23,   -10,    67,   -23,   323,
     323,   121,   149,   268,   295,    79,   -23,   323,   -23,   -23,
     305,   -23
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     3,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     0,     0,     0,     0,     0,
       1,     0,     0,     0,     0,     0,    11,    12,     0,     0,
       2,     4,    10,     9,     6,     7,     8,     0,    34,    35,
       0,     0,     0,     0,     0,     0,    20,    18,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,    33,    27,    28,    29,
      30,    31,    32,    26,    25,    21,    22,    23,    24,     0,
       0,     0,     0,     0,     0,    14,    15,     0,    17,    13,
       0,    16
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -23,   -23,    -8,    -9,   -23,   -23,   -23,   -23,   -23,   -22
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    13,    14,    15,    16,    17,    18,    19,    41
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      25,    42,    43,    28,    31,    52,     1,    46,    38,    39,
      57,    58,    59,    60,    20,    26,    31,    40,    48,    31,
      59,    60,    21,    57,    58,    59,    60,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    50,
      51,    52,    81,    82,    22,    23,    49,    50,    51,    52,
      53,    54,    58,    59,    60,    24,    27,    32,    33,    57,
      58,    59,    60,    29,    34,    55,    56,    57,    58,    59,
      60,    83,    84,    61,    31,    31,    35,    36,    37,    90,
      47,    31,    49,    50,    51,    52,    53,    54,    64,    65,
      79,    49,    50,    51,    52,    53,    54,    80,    60,     0,
       0,    55,    56,    57,    58,    59,    60,     0,     0,    62,
      55,    56,    57,    58,    59,    60,     0,     0,    63,    49,
      50,    51,    52,    53,    54,     0,     0,     0,    49,    50,
      51,    52,    53,    54,     0,     0,     0,     0,    55,    56,
      57,    58,    59,    60,     0,     0,    66,    55,    56,    57,
      58,    59,    60,     0,     0,    85,    49,    50,    51,    52,
      53,    54,     0,     0,     0,    49,    50,    51,    52,    53,
      54,     0,     0,     0,     0,    55,    56,    57,    58,    59,
      60,     0,     0,    86,    55,    56,    57,    58,    59,    60,
      49,    50,    51,    52,    53,     0,    49,    50,    51,    52,
       0,    49,    50,    51,    52,    49,    50,    51,    52,    55,
      56,    57,    58,    59,    60,    55,    56,    57,    58,    59,
      60,    56,    57,    58,    59,    60,    57,    58,    59,    60,
      51,    52,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     3,     4,     5,     0,     0,    57,
      58,    59,    60,     6,    30,     4,     5,     7,     8,     0,
       9,    10,    11,     6,     0,    12,     0,     7,     8,     0,
       9,    10,    11,     4,     5,    12,     0,     0,     0,     4,
       5,     6,     0,    87,    88,     7,     8,     6,     9,    10,
      11,     7,     8,    12,     9,    10,    11,    45,     0,    12,
       4,     5,     0,     0,     0,     0,     0,     0,     6,     0,
       4,     5,     7,     8,    89,     9,    10,    11,     6,     0,
      12,    91,     7,     8,     0,     9,    10,    11,     4,     5,
      12,     0,     0,     0,     4,     5,     6,     0,     0,     0,
       7,     8,     6,     9,    10,    11,    44,     8,    12,     9,
      10,    11,     0,     0,    12
};

static const yytype_int8 yycheck[] =
{
       8,    23,    24,    11,    13,    10,     3,    29,    24,    25,
      28,    29,    30,    31,     0,    32,    25,    33,    40,    28,
      30,    31,    33,    28,    29,    30,    31,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,     8,
       9,    10,    64,    65,    33,    33,     7,     8,     9,    10,
      11,    12,    29,    30,    31,    33,    32,    32,    32,    28,
      29,    30,    31,    35,    32,    26,    27,    28,    29,    30,
      31,    79,    80,    34,    83,    84,    32,    32,    25,    87,
      34,    90,     7,     8,     9,    10,    11,    12,    33,    33,
      14,     7,     8,     9,    10,    11,    12,    18,    31,    -1,
      -1,    26,    27,    28,    29,    30,    31,    -1,    -1,    34,
      26,    27,    28,    29,    30,    31,    -1,    -1,    34,     7,
       8,     9,    10,    11,    12,    -1,    -1,    -1,     7,     8,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    26,    27,
      28,    29,    30,    31,    -1,    -1,    34,    26,    27,    28,
      29,    30,    31,    -1,    -1,    34,     7,     8,     9,    10,
      11,    12,    -1,    -1,    -1,     7,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    -1,    -1,    34,    26,    27,    28,    29,    30,    31,
       7,     8,     9,    10,    11,    -1,     7,     8,     9,    10,
      -1,     7,     8,     9,    10,     7,     8,     9,    10,    26,
      27,    28,    29,    30,    31,    26,    27,    28,    29,    30,
      31,    27,    28,    29,    30,    31,    28,    29,    30,    31,
       9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     4,     5,     6,    -1,    -1,    28,
      29,    30,    31,    13,     4,     5,     6,    17,    18,    -1,
      20,    21,    22,    13,    -1,    25,    -1,    17,    18,    -1,
      20,    21,    22,     5,     6,    25,    -1,    -1,    -1,     5,
       6,    13,    -1,    15,    16,    17,    18,    13,    20,    21,
      22,    17,    18,    25,    20,    21,    22,    23,    -1,    25,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,
       5,     6,    17,    18,    19,    20,    21,    22,    13,    -1,
      25,    16,    17,    18,    -1,    20,    21,    22,     5,     6,
      25,    -1,    -1,    -1,     5,     6,    13,    -1,    -1,    -1,
      17,    18,    13,    20,    21,    22,    17,    18,    25,    20,
      21,    22,    -1,    -1,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    37,     4,     5,     6,    13,    17,    18,    20,
      21,    22,    25,    38,    39,    40,    41,    42,    43,    44,
       0,    33,    33,    33,    33,    38,    32,    32,    38,    35,
       4,    39,    32,    32,    32,    32,    32,    25,    24,    25,
      33,    45,    45,    45,    17,    23,    45,    34,    45,     7,
       8,     9,    10,    11,    12,    26,    27,    28,    29,    30,
      31,    34,    34,    34,    33,    33,    34,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    14,
      18,    45,    45,    38,    38,    34,    34,    15,    16,    19,
      38,    16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    37,    38,    38,    39,    39,    39,    39,
      39,    39,    39,    40,    40,    40,    41,    41,    42,    43,
      44,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     2,     1,     2,     2,     2,     2,
       2,     2,     2,     7,     6,     6,     9,     7,     4,     4,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1
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
  case 2: /* Program: begin Slist end  */
#line 143 "main.y"
                                    {root=(yyvsp[-1].nodePtr);}
#line 1388 "y.tab.c"
    break;

  case 3: /* Program: begin end  */
#line 144 "main.y"
                                    {root=NULL;}
#line 1394 "y.tab.c"
    break;

  case 4: /* Slist: Slist Stmt  */
#line 146 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,0,' ',tCONNECT,(yyvsp[-1].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1400 "y.tab.c"
    break;

  case 5: /* Slist: Stmt  */
#line 147 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 1406 "y.tab.c"
    break;

  case 6: /* Stmt: InputStmt ';'  */
#line 149 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1412 "y.tab.c"
    break;

  case 7: /* Stmt: OutputStmt ';'  */
#line 150 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1418 "y.tab.c"
    break;

  case 8: /* Stmt: AssgStmt ';'  */
#line 151 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1424 "y.tab.c"
    break;

  case 9: /* Stmt: Ifstmt ';'  */
#line 152 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1430 "y.tab.c"
    break;

  case 10: /* Stmt: LoopStmt ';'  */
#line 153 "main.y"
                                   {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1436 "y.tab.c"
    break;

  case 11: /* Stmt: BREAK ';'  */
#line 154 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,0,' ',tBREAK,NULL,NULL,NULL);}
#line 1442 "y.tab.c"
    break;

  case 12: /* Stmt: CONTINUE ';'  */
#line 155 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,0,' ',tCONTINUE,NULL,NULL,NULL);}
#line 1448 "y.tab.c"
    break;

  case 13: /* LoopStmt: WHILE '(' Expr ')' DO Slist ENDWHILE  */
#line 157 "main.y"
                                                        {if(isBoolean((yyvsp[-4].nodePtr),(yyvsp[-4].nodePtr))) (yyval.nodePtr)=makeNode(0,0,' ',tWHILE,(yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr),(yyvsp[-4].nodePtr));}
#line 1454 "y.tab.c"
    break;

  case 14: /* LoopStmt: DO Slist WHILE '(' Expr ')'  */
#line 158 "main.y"
                                                        {if(isBoolean((yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr))) (yyval.nodePtr)=makeNode(0,0,' ',tDOWHILE,(yyvsp[-4].nodePtr),(yyvsp[-4].nodePtr),(yyvsp[-1].nodePtr));}
#line 1460 "y.tab.c"
    break;

  case 15: /* LoopStmt: REPEAT Slist UNTIL '(' Expr ')'  */
#line 159 "main.y"
                                                            {if(isBoolean((yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr))) (yyval.nodePtr)=makeNode(0,0,' ',tREPEATUNTIL,(yyvsp[-4].nodePtr),(yyvsp[-4].nodePtr),(yyvsp[-1].nodePtr));}
#line 1466 "y.tab.c"
    break;

  case 16: /* Ifstmt: IF '(' Expr ')' then Slist Else Slist ENDIF  */
#line 161 "main.y"
                                                        {if(isBoolean((yyvsp[-6].nodePtr),(yyvsp[-6].nodePtr))) (yyval.nodePtr)=makeNode(0,0,' ',tIF,(yyvsp[-3].nodePtr),(yyvsp[-1].nodePtr),(yyvsp[-6].nodePtr));}
#line 1472 "y.tab.c"
    break;

  case 17: /* Ifstmt: IF '(' Expr ')' then Slist ENDIF  */
#line 162 "main.y"
                                                        {if(isBoolean((yyvsp[-4].nodePtr),(yyvsp[-4].nodePtr))) (yyval.nodePtr)=makeNode(0,0,' ',tIF,(yyvsp[-1].nodePtr),NULL,(yyvsp[-4].nodePtr));}
#line 1478 "y.tab.c"
    break;

  case 18: /* InputStmt: READ '(' ID ')'  */
#line 164 "main.y"
                                    {
                                    node* temp=makeNode(0,0,(yyvsp[-1].Char),tVAR,NULL,NULL,NULL);
                                    (yyval.nodePtr)=makeNode(0,0,' ',tREAD,temp,temp,NULL);
                                    }
#line 1487 "y.tab.c"
    break;

  case 19: /* OutputStmt: WRITE '(' Expr ')'  */
#line 169 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,0,' ',tWRITE,(yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr),NULL);}
#line 1493 "y.tab.c"
    break;

  case 20: /* AssgStmt: ID '=' Expr  */
#line 171 "main.y"
                                    {
                                    node* temp=makeNode(0,0,(yyvsp[-2].Char),tVAR,NULL,NULL,NULL);
                                    (yyval.nodePtr)=makeNode(0,0,' ',tASSIGN,temp,(yyvsp[0].nodePtr),NULL);
                                    }
#line 1502 "y.tab.c"
    break;

  case 21: /* Expr: Expr '+' Expr  */
#line 176 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,0,' ',tADD,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1508 "y.tab.c"
    break;

  case 22: /* Expr: Expr '-' Expr  */
#line 177 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,0,' ',tSUB,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1514 "y.tab.c"
    break;

  case 23: /* Expr: Expr '*' Expr  */
#line 178 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,0,' ',tMUL,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1520 "y.tab.c"
    break;

  case 24: /* Expr: Expr '/' Expr  */
#line 179 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,0,' ',tDIV,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1526 "y.tab.c"
    break;

  case 25: /* Expr: Expr '>' Expr  */
#line 180 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,1,' ',tGT,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1532 "y.tab.c"
    break;

  case 26: /* Expr: Expr '<' Expr  */
#line 181 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,1,' ',tLT,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1538 "y.tab.c"
    break;

  case 27: /* Expr: Expr GE Expr  */
#line 182 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,1,' ',tGE,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1544 "y.tab.c"
    break;

  case 28: /* Expr: Expr LE Expr  */
#line 183 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,1,' ',tLE,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1550 "y.tab.c"
    break;

  case 29: /* Expr: Expr EQ Expr  */
#line 184 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,1,' ',tEQ,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1556 "y.tab.c"
    break;

  case 30: /* Expr: Expr NEQ Expr  */
#line 185 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,1,' ',tNEQ,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1562 "y.tab.c"
    break;

  case 31: /* Expr: Expr AND Expr  */
#line 186 "main.y"
                                    {if(isBoolean((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,1,' ',tAND,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1568 "y.tab.c"
    break;

  case 32: /* Expr: Expr OR Expr  */
#line 187 "main.y"
                                    {if(isBoolean((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,1,' ',tOR,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1574 "y.tab.c"
    break;

  case 33: /* Expr: '(' Expr ')'  */
#line 188 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1580 "y.tab.c"
    break;

  case 34: /* Expr: NUM  */
#line 189 "main.y"
                                    {(yyval.nodePtr)=makeNode((yyvsp[0].Int),0,' ',tCONST,NULL,NULL,NULL);}
#line 1586 "y.tab.c"
    break;

  case 35: /* Expr: ID  */
#line 190 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,0,(yyvsp[0].Char),tVAR,NULL,NULL,NULL);}
#line 1592 "y.tab.c"
    break;


#line 1596 "y.tab.c"

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

#line 193 "main.y"


int main(){
    FILE *fp=fopen("input2.txt","r");
    yyin=fp;
    yyparse();

    /* for(int i=0;i<26;i++) variables[i]=0;
    evaluator(root);
    return 0; */

    outFile=fopen("a.xsm","w");
    printTree(root);
    currReg=0;

    genHeader();
    genVarSpaceCode();
    int reg=genCode(root);
    genExit();
}

void handleDoWhile(node* root){
    if(root==NULL || root->nodeType!=tDOWHILE) return;
    int L1=label++;
    int L2=label++;
    WHILELABELS[0]=L1; // for continue;
    WHILELABELS[1]=L2; // for break;
    genCode(root->left); // making sure it runs once, then the while loop itself
    fprintf(outFile,"L%d:\n",L1); 
    int reg=genCode(root->center);
    fprintf(outFile,"JZ R%d, L%d!\n",reg,L2);
    genCode(root->left);
    fprintf(outFile,"JMP L%d!\n",L1);
    fprintf(outFile,"L%d:\n",L2);
    WHILELABELS[0]=-1;
    WHILELABELS[1]=-1;
    freeReg();
}
void handleRepeatUntil(node* root){
    if(root==NULL || root->nodeType!=tREPEATUNTIL) return;
    int L1=label++;
    int L2=label++;
    WHILELABELS[0]=L1; // for continue;
    WHILELABELS[1]=L2; // for break;
    genCode(root->left); // making sure it runs once, then the while loop itself
    fprintf(outFile,"L%d:\n",L1); 
    int reg=genCode(root->center);
    fprintf(outFile,"JNZ R%d, L%d!\n",reg,L2); // jump if non zero
    genCode(root->left);
    fprintf(outFile,"JMP L%d!\n",L1);
    fprintf(outFile,"L%d:\n",L2);
    WHILELABELS[0]=-1;
    WHILELABELS[1]=-1;
    freeReg();
}
void handleWhile(node* root){
    if(root==NULL || root->nodeType!=tWHILE) return;
    int L1=label++;
    fprintf(outFile,"L%d:\n",L1); 
    int L2=label++;
    WHILELABELS[0]=L1; // for continue;
    WHILELABELS[1]=L2; // for break;
    int reg=genCode(root->center);
    fprintf(outFile,"JZ R%d, L%d!\n",reg,L2);
    genCode(root->left);
    fprintf(outFile,"JMP L%d!\n",L1);
    fprintf(outFile,"L%d:\n",L2);
    WHILELABELS[0]=-1;
    WHILELABELS[1]=-1;
    freeReg();
}

int handleComparison(node* root){
    if(root==NULL) return 100;
    int r1=genCode(root->left);
    int r2=genCode(root->right);
    switch(root->nodeType){
        case tLT:
            fprintf(outFile,"LT R%d, R%d\n",r1,r2);
        break;
        case tGT:
            fprintf(outFile,"GT R%d, R%d\n",r1,r2);
        break;
        case tEQ:
            fprintf(outFile,"EQ R%d, R%d\n",r1,r2);
        break;
        case tNEQ:
            fprintf(outFile,"NE R%d, R%d\n",r1,r2);
        break;
        case tGE:
            fprintf(outFile,"GE R%d, R%d\n",r1,r2);
        break;
        case tLE:
            fprintf(outFile,"LE R%d, R%d\n",r1,r2);
        break;
    }
    freeReg();
    return r1;

}

void handleIfElse(node* root){
    if(root==NULL || root->nodeType!=tIF) return;
    int reg=genCode(root->center); // value of if else condition stored in reg
    int L1=label++;
    fprintf(outFile,"JZ R%d, L%d!\n",reg,L1);
    genCode(root->left);
    if(root->right){
        int L2=label++;
        fprintf(outFile,"JMP L%d!\n",L2);
        fprintf(outFile,"L%d:\n",L1);
        genCode(root->right);
        fprintf(outFile,"L%d:\n",L2);
    }
    else fprintf(outFile,"L%d:\n",L1);
    freeReg();
}

bool isArithmetic(node* left, node* right){
    if(left==NULL || right==NULL){
        yyerror("syntax error");
        exit(0);
    }
    if(left->type!= inttype || right->type!=inttype){
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
    if(left->type!= booltype || right->type!=booltype){
        yyerror("type mismatch");
        exit(0);
    }
    return true;
}

int evaluator(node* root){
    if(root==NULL || evalCB==tBREAK || evalCB==tCONTINUE) return 0;
    int i,j;
    bool cond;
    switch(root->nodeType){
        case tCONNECT: //connector
            evaluator(root->left);
            evaluator(root->right);
        break;
        case tCONST: //constants
            return root->val;
        break;
        case tVAR: //Variable
            return variables[*(root->varname)-'a'];
        break;
        case tREAD: //Read
        printf("read\n");
            i=*(root->left->varname) - 'a';
            scanf("%d",&variables[i]);
            return 100;//junk value
        break;
        case tWRITE: //Write
        printf("write\n");
            i=evaluator(root->left);
            printf("%d\n",i);
        break;
        case tASSIGN: //=
        printf("=\n");
            i=*(root->left->varname) - 'a';
            variables[i]=evaluator(root->right);
            return 100;// junk
        break;
        case 5: //+
        printf("+\n");
            return evaluator(root->left) + evaluator(root->right);
        break;
        case 6: //-
        printf("-\n");
            return evaluator(root->left) - evaluator(root->right);
        break;
        case 7: //*
        printf("*\n");
            return evaluator(root->left) * evaluator(root->right);
        break;
        case 8: // /
        printf("/\n");
            return evaluator(root->left) / evaluator(root->right);
        break;
        case tLT:
            i=evaluator(root->left);
            j=evaluator(root->right);
            if(i<j) return 1;
            return 0;
        break;
        case tGT:
            i=evaluator(root->left);
            j=evaluator(root->right);
            if(i>j) return 1;
            return 0;
        break;
        case tEQ:
            i=evaluator(root->left);
            j=evaluator(root->right);
            if(i==j) return 1;
            return 0;
        break;
        case tNEQ:
            i=evaluator(root->left);
            j=evaluator(root->right);
            if(i!=j) return 1;
            return 0;
        break;
        case tGE:
            i=evaluator(root->left);
            j=evaluator(root->right);
            if(i>=j) return 1;
            return 0;
        break;
        case tLE:
            i=evaluator(root->left);
            j=evaluator(root->right);
            if(i<=j) return 1;
            return 0;
        break;
        case tIF:
            cond=evaluator(root->center);
            if(cond) evaluator(root->left);
            else evaluator(root->right);
        break;
        case tWHILE:
            while(evaluator(root->center)){
                evaluator(root->left);
                if(evalCB==tBREAK){
                    evalCB=0;
                    break;
                }
                evalCB=0;
            }
        break;
        case tDOWHILE:
            evaluator(root->left);
            if(evalCB==tBREAK){
                evalCB=0;
                return 0;
            }
            evalCB=0;
            while(evaluator(root->center)){
                evaluator(root->left);
                if(evalCB==tBREAK){
                    evalCB=0;
                    break;
                }
                evalCB=0;
            }
        break;
        case tREPEATUNTIL:
            evaluator(root->left);
            if(evalCB==tBREAK){
                evalCB=0;
                return 0;
            }
            evalCB=0;
            while(!evaluator(root->center)){
                evaluator(root->left);
                if(evalCB==tBREAK){
                    evalCB=0;
                    break;
                }
                evalCB=0;
            }
        break;
        case tBREAK:
            evalCB=tBREAK;
            return 0;
        break;
        case tCONTINUE:
            evalCB=tCONTINUE;
            return 0;
        break;
    }
    return 100;// junk
}
int genCode(node* root){
    int reg;
    switch(root->nodeType){
        case tCONNECT: //connector
            genCode(root->left);
            genCode(root->right);
        break;
        case tCONST: //constants
            reg=getReg();
            fprintf(outFile,"MOV R%d, %d\n",reg,root->val);
            return reg;
        break;
        case tVAR: //Variable
            reg=getReg();
            fprintf(outFile,"MOV R%d, [%d]\n",reg,varBase+(root->varname)[0]-'a');
            return reg;
        break;
        case tREAD: //Read
            handleRead(root);
        break;
        case tWRITE: //Write
            reg=genCode(root->left);
            handleWrite(reg);
            freeReg();
        break;
        case tASSIGN: //=
            handleAssignment(root);
        break;
        case tIF:
            handleIfElse(root);
        break;
        case tWHILE:
            handleWhile(root);
        break;
        case tDOWHILE:
            handleDoWhile(root);
        break;
        case tREPEATUNTIL:
            handleRepeatUntil(root);
        break;
        case tBREAK:
            if(WHILELABELS[1]!=-1) fprintf(outFile,"JMP L%d!\n",WHILELABELS[1]);
            else {
                yyerror("break outside looping statement\n");
                exit(0);
            }
        break;
        case tCONTINUE:
            if(WHILELABELS[0]!=-1) fprintf(outFile,"JMP L%d!\n",WHILELABELS[0]);
            else{
                yyerror("continue outside looping statement\n");
                exit(0);
            }
        break;
    }
    if(root->nodeType>4 && root->nodeType<9){ //+-*/
        return handleArithmetic(root);
    }
    else if(root->nodeType>9 && root->nodeType<16){
        return handleComparison(root);
    }
    return 100;// junk
}
void handleAssignment(node* root){
    char c=*(root->left->varname);
    int reg=genCode(root->right);
    fprintf(outFile,"MOV [%d], R%d\n",varBase+c-'a',reg);
    freeReg();
}
int handleArithmetic(node* root){
    int left=genCode(root->left);
    int right=genCode(root->right);
    char* op;
    switch(root->nodeType){
        case 5:
            op="ADD";
            break;
        case 6:
            op="SUB";
            break;
        case 7:
            op="MUL";
            break;
        case 8:
            op="DIV";
            break;
    }
    fprintf(outFile,"%s R%d, R%d\n",op,left,right);
    freeReg();
    return left;
}
void handleWrite(int Wreg){
    int reg=getReg();

    fprintf(outFile,"MOV R%d, \"Write\"\n",reg); //funct code
    fprintf(outFile,"PUSH R%d\n",reg);

    fprintf(outFile,"MOV R%d, -2\n",reg); //arg 1=-2 for write
    fprintf(outFile,"PUSH R%d\n",reg);

    fprintf(outFile,"PUSH R%d\n",Wreg); //arg2 data to be printed is in wReg

    fprintf(outFile,"PUSH R%d\n",reg);  //arg 3
    fprintf(outFile,"PUSH R%d\n",reg);  // space for return value

    fprintf(outFile,"CALL 0\n");

    fprintf(outFile,"POP R%d\n",reg);   // return value CAN BE USED LATER FOR ERROR DETECTION
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d\n",reg);
    freeReg();
}
void genVarSpaceCode(){
    fprintf(outFile,"MOV SP,4122\n"); //allocate space for 26 variables;
    //static allocation in stack itself
}
void genHeader(){
    fprintf(outFile,"0\n2056\n0\n0\n0\n0\n0\n0\nBRKP\n");
}
int getReg(){
    return currReg++;
}
void freeReg(){
    if(currReg>0) currReg--;
}
void handleRead(node* root){
    char c=*(root->left->varname);
    int reg=getReg();

    fprintf(outFile,"MOV R%d, \"Read\"\n",reg);
    fprintf(outFile,"PUSH R%d\n",reg);

    fprintf(outFile,"MOV R%d, -1\n",reg);
    fprintf(outFile,"PUSH R%d\n",reg);

    fprintf(outFile,"MOV R%d, %d\n",reg,varBase+c-'a');
    fprintf(outFile,"PUSH R%d\n",reg);
    
    fprintf(outFile,"PUSH R%d\n",reg);
    fprintf(outFile,"PUSH R%d\n",reg);

    fprintf(outFile,"CALL 0\n");
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d\n",reg);
    fprintf(outFile,"POP R%d\n",reg);
    freeReg();
}
void genExit(){
    fprintf(outFile,"MOV R0, \"Exit\"\n");
    fprintf(outFile,"PUSH R0\n");
    fprintf(outFile,"PUSH R0\n");
    fprintf(outFile,"PUSH R0\n");
    fprintf(outFile,"PUSH R0\n");
    fprintf(outFile,"CALL 0");
}

node* makeNode(int val,int type,char varname,int nodeType,node* left,node* right,node* center){
    node* ptr;
    ptr=(node*)malloc(sizeof(node));
    ptr->val=val;
    ptr->type=type;

    char * temp=(char*)malloc(sizeof(char)*2);
    temp[0]=varname;
    temp[1]='\0';
    ptr->varname=temp;

    ptr->nodeType=nodeType;
    ptr->left=left;
    ptr->right=right;
    ptr->center=center;
    return ptr;
}

void yyerror(char* s){
    printf("%s\n",s);
}

void printTree(node* root){
    if(root==NULL) return;
    for(int i=0;i<space;i++)printf("|");
    int temp=root->nodeType;
    space+=3;
    if(temp==0) printf("->$\n");
    else if(temp==1) printf("->%d\n",root->val);
    else if(temp==2) printf("->%s\n",root->varname);
    else if(temp==3) printf("->R\n");
    else if(temp==4) printf("->W\n");
    else if(temp==5) printf("->+\n");
    else if(temp==6) printf("->-\n");
    else if(temp==7) printf("->*\n");
    else if(temp==8) printf("->/\n");
    else if(temp==9) printf("->=\n");
    else if(temp==10) printf("->LT\n");
    else if(temp==11) printf("->GT\n");
    else if(temp==12) printf("->LE\n");
    else if(temp==13) printf("->GE\n");
    else if(temp==14) printf("->EQ\n");
    else if(temp==15) printf("->NEQ\n");
    else if(temp==16) printf("->AND\n");
    else if(temp==17) printf("->OR\n");
    else if(temp==18) {
        printf("->IF\n");
        printTree(root->center);
    }
    else if(temp==19){
        printf("->WHILE\n");
        printTree(root->center);
    }
    printTree(root->left);
    printTree(root->right);
    space-=3;
}

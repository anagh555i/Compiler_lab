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

    extern FILE *yyin;
    void yyerror(char* s);
    extern int yylex();
    void installFunction(node* f);
    bool isArithmetic(node* left, node* right);
    bool isBoolean(node* left, node* right);

    node* root;          // AST root;
    Gsymbol* Ghead=NULL; // global symbol table head
    Lsymbol* Lhead=NULL; // global symbol table head

    FILE* outFile;
    int currReg;

    int space=0;
    int varBase=4096;
    int SP=4096;
    int label=0;
    int flabel=0;
    int WHILELABELS[]={-1,-1};// new list based while labels storage required
    Lnode* breakLabels=NULL;
    Lnode* continueLabels=NULL;
    node* functions=NULL;

#line 104 "y.tab.c"

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
    INT = 276,                     /* INT  */
    STR = 277,                     /* STR  */
    VOID = 278,                    /* VOID  */
    DECL = 279,                    /* DECL  */
    ENDDECL = 280,                 /* ENDDECL  */
    RETURN = 281,                  /* RETURN  */
    NUM = 282,                     /* NUM  */
    ID = 283,                      /* ID  */
    LITERAL = 284,                 /* LITERAL  */
    MAIN = 285                     /* MAIN  */
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
#define INT 276
#define STR 277
#define VOID 278
#define DECL 279
#define ENDDECL 280
#define RETURN 281
#define NUM 282
#define ID 283
#define LITERAL 284
#define MAIN 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 35 "main.y"

    int Int;
    char Char;
    struct node* nodePtr;
    char* String;
    struct Lnode* listPtr;

#line 225 "y.tab.c"

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
  YYSYMBOL_INT = 21,                       /* INT  */
  YYSYMBOL_STR = 22,                       /* STR  */
  YYSYMBOL_VOID = 23,                      /* VOID  */
  YYSYMBOL_DECL = 24,                      /* DECL  */
  YYSYMBOL_ENDDECL = 25,                   /* ENDDECL  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_NUM = 27,                       /* NUM  */
  YYSYMBOL_ID = 28,                        /* ID  */
  YYSYMBOL_LITERAL = 29,                   /* LITERAL  */
  YYSYMBOL_MAIN = 30,                      /* MAIN  */
  YYSYMBOL_31_ = 31,                       /* '<'  */
  YYSYMBOL_32_ = 32,                       /* '>'  */
  YYSYMBOL_33_ = 33,                       /* '+'  */
  YYSYMBOL_34_ = 34,                       /* '-'  */
  YYSYMBOL_35_ = 35,                       /* '*'  */
  YYSYMBOL_36_ = 36,                       /* '/'  */
  YYSYMBOL_37_ = 37,                       /* '%'  */
  YYSYMBOL_38_ = 38,                       /* '['  */
  YYSYMBOL_39_ = 39,                       /* ']'  */
  YYSYMBOL_40_ = 40,                       /* ';'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* '{'  */
  YYSYMBOL_45_ = 45,                       /* '}'  */
  YYSYMBOL_46_ = 46,                       /* '='  */
  YYSYMBOL_47_ = 47,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_sourceCode = 49,                /* sourceCode  */
  YYSYMBOL_GDelcarations = 50,             /* GDelcarations  */
  YYSYMBOL_GDecList = 51,                  /* GDecList  */
  YYSYMBOL_ArrList = 52,                   /* ArrList  */
  YYSYMBOL_GDecl = 53,                     /* GDecl  */
  YYSYMBOL_VarList = 54,                   /* VarList  */
  YYSYMBOL_ParamList = 55,                 /* ParamList  */
  YYSYMBOL_Param = 56,                     /* Param  */
  YYSYMBOL_Type = 57,                      /* Type  */
  YYSYMBOL_FDefBlock = 58,                 /* FDefBlock  */
  YYSYMBOL_Fdef = 59,                      /* Fdef  */
  YYSYMBOL_MainBlock = 60,                 /* MainBlock  */
  YYSYMBOL_LdeclBlock = 61,                /* LdeclBlock  */
  YYSYMBOL_LDecList = 62,                  /* LDecList  */
  YYSYMBOL_LDecl = 63,                     /* LDecl  */
  YYSYMBOL_IdList = 64,                    /* IdList  */
  YYSYMBOL_Body = 65,                      /* Body  */
  YYSYMBOL_Slist = 66,                     /* Slist  */
  YYSYMBOL_Stmt = 67,                      /* Stmt  */
  YYSYMBOL_ReturnStmt = 68,                /* ReturnStmt  */
  YYSYMBOL_LoopStmt = 69,                  /* LoopStmt  */
  YYSYMBOL_Ifstmt = 70,                    /* Ifstmt  */
  YYSYMBOL_InputStmt = 71,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 72,                /* OutputStmt  */
  YYSYMBOL_AssgStmt = 73,                  /* AssgStmt  */
  YYSYMBOL_Array = 74,                     /* Array  */
  YYSYMBOL_Expr = 75,                      /* Expr  */
  YYSYMBOL_ArgList = 76                    /* ArgList  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   469

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  197

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   285


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
       2,     2,     2,     2,     2,     2,     2,    37,    47,     2,
      41,    42,    35,    33,    43,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      31,    46,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   118,   118,   121,   122,   124,   125,   127,   128,   130,
     147,   166,   174,   175,   176,   177,   180,   181,   182,   184,
     191,   192,   193,   196,   197,   200,   225,   239,   240,   242,
     243,   245,   253,   254,   258,   259,   261,   262,   264,   265,
     266,   267,   268,   269,   270,   271,   273,   274,   276,   277,
     278,   280,   281,   283,   291,   293,   300,   312,   322,   327,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   343,   344,   356,   363,   364,   370,   377,
     384,   394,   401,   405
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
  "DO", "BREAK", "CONTINUE", "REPEAT", "UNTIL", "INT", "STR", "VOID",
  "DECL", "ENDDECL", "RETURN", "NUM", "ID", "LITERAL", "MAIN", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'['", "']'", "';'", "'('",
  "')'", "','", "'{'", "'}'", "'='", "'&'", "$accept", "sourceCode",
  "GDelcarations", "GDecList", "ArrList", "GDecl", "VarList", "ParamList",
  "Param", "Type", "FDefBlock", "Fdef", "MainBlock", "LdeclBlock",
  "LDecList", "LDecl", "IdList", "Body", "Slist", "Stmt", "ReturnStmt",
  "LoopStmt", "Ifstmt", "InputStmt", "OutputStmt", "AssgStmt", "Array",
  "Expr", "ArgList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-98)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -21,   114,    22,   190,   -98,   -98,   -98,   -98,   129,   -98,
      35,   -98,    17,   215,   -98,   -98,   -98,   157,    36,    33,
      48,    61,   -98,   -98,    72,   190,    60,   -98,   -98,    37,
     190,    65,    76,    86,    87,   106,   -98,   -98,   113,   105,
     107,   120,   125,   190,   -98,   -98,   143,   145,   -98,   -98,
     -98,   147,   147,   138,   170,   170,   -98,   171,   153,   -98,
     395,   169,   173,   176,   162,   -98,   -98,   186,   194,   222,
     223,   211,   225,   226,   224,   422,   -19,   239,   395,   -98,
     235,   -98,   -98,   236,   237,   238,   -98,   -98,   171,   -98,
     251,   422,   422,   422,   395,   -98,   -98,   395,   -98,   159,
     -98,   252,   422,   260,   355,   422,   422,   243,   244,   -98,
     261,   287,   -98,   -98,   -98,   -98,   258,   197,   214,   250,
      62,   263,   103,   419,   -98,   -98,   262,   -98,   422,   422,
     422,   422,   422,   422,   422,   422,   422,   422,   422,   422,
     422,   346,   355,   422,   422,   307,   -98,   -98,   -98,   268,
     269,   299,   -98,   282,   -98,   355,   -25,   -98,   207,     3,
      59,    90,    -2,   362,   408,    77,   148,   217,    23,   278,
     -98,   285,   355,   355,   -98,   395,   395,   275,   283,   -98,
     422,   -98,   127,   151,   422,   422,   355,   311,   -98,   298,
     310,   284,   -98,   -98,   395,   175,   -98
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,    20,    21,    22,     4,     0,     6,
       0,     1,     0,     0,    24,     3,     5,    14,     0,     0,
       0,    22,    23,     2,     0,    18,     0,    15,     9,     0,
      18,     0,     0,     0,    17,     0,    10,    12,     0,     0,
       0,     8,     0,    18,    19,    13,     0,     0,     7,    11,
      16,     0,     0,     0,     0,     0,    28,     0,     0,    30,
       0,     0,     0,    33,     0,    27,    29,     0,     0,     0,
       0,     0,     0,     0,     0,    47,     0,     0,     0,    37,
       0,    43,    42,     0,     0,     0,    25,    26,     0,    31,
       0,     0,     0,     0,     0,    44,    45,     0,    76,    78,
      77,     0,     0,     0,    46,     0,     0,     0,     0,    36,
       0,    41,    38,    39,    40,    32,     0,     0,     0,     0,
       0,     0,     0,     0,    81,    80,     0,    79,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    55,     0,     0,    41,    35,    53,    54,     0,
       0,     0,    41,     0,    75,    83,     0,    73,    67,    68,
      69,    70,    71,    72,    66,    65,    60,    61,    62,    63,
      64,    59,    57,    56,    34,     0,     0,     0,     0,    74,
       0,    58,     0,     0,     0,     0,    82,    52,    48,     0,
       0,     0,    49,    50,     0,     0,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -98,   -98,   -98,   -98,   286,   318,   -98,   -15,   -98,    13,
     -98,   323,   -98,   296,   -98,   279,   271,   294,   -93,   -78,
     -35,   -98,   -98,   -98,   -98,   -98,   -97,   -82,   -98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     8,    26,     9,    19,    33,    34,    35,
      13,    14,    23,    54,    58,    59,    64,    61,    78,    79,
     121,    81,    82,    83,    84,    85,   107,   104,   156
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     109,   120,   124,     1,   122,   128,   129,   130,   131,   117,
     118,   119,   130,   131,    10,    39,    12,   179,   180,   105,
     126,    10,    11,   141,   142,    80,    12,   106,    50,   134,
     135,   136,   137,   138,   139,   140,   136,   137,   138,   139,
     140,   155,   109,   110,   109,    20,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   139,
     140,   172,   173,    17,    27,    37,    57,    67,    68,   131,
      18,    57,    38,    28,   181,    69,    29,    70,    71,    72,
      73,    74,   182,   183,   128,   129,   130,   131,    75,    30,
      76,    31,   136,   137,   138,   139,   140,    77,   186,    32,
      36,   195,   189,   190,   109,   109,    40,   151,    67,    68,
     136,   137,   138,   139,   140,    41,    69,   109,    70,    71,
      72,    73,    74,   136,   137,   138,   139,   140,    42,    75,
      43,    76,    67,    68,    44,     4,     5,     6,    77,     7,
      69,    45,    70,    71,    72,    73,    74,    46,   153,    47,
       4,     5,     6,    75,    15,    76,    67,    68,    24,     4,
       5,     6,    77,    56,    69,    49,    70,    71,    72,    73,
      74,    53,   187,    60,     4,     5,     6,    75,    65,    76,
      67,    68,   137,   138,   139,   140,    77,    51,    69,    52,
      70,    71,    72,    73,    74,    24,   188,   105,    25,    63,
     123,    75,    89,    76,   128,   129,   130,   131,   132,   133,
      77,     4,     5,     6,    86,   129,   130,   131,    87,    88,
     196,   128,   129,   130,   131,   132,   133,    90,   134,   135,
     136,   137,   138,   139,   140,    91,     4,     5,    21,   148,
     136,   137,   138,   139,   140,   134,   135,   136,   137,   138,
     139,   140,   138,   139,   140,    94,   149,   128,   129,   130,
     131,   132,   133,    92,    93,    95,    96,   108,    97,   128,
     129,   130,   131,   132,   133,   111,   112,   113,   114,   116,
     125,   134,   135,   136,   137,   138,   139,   140,   127,   143,
     144,   146,   150,   134,   135,   136,   137,   138,   139,   140,
     147,   145,   178,   152,   157,   128,   129,   130,   131,   132,
     133,   174,   175,   176,   177,   140,   184,   128,   129,   130,
     131,   132,   133,   105,   185,   191,    16,    48,   194,   134,
     135,   136,   137,   138,   139,   140,    22,    66,     0,     0,
     192,   134,   135,   136,   137,   138,   139,   140,    55,    62,
       0,     0,   193,   128,   129,   130,   131,   132,   133,   115,
       0,     0,   128,   129,   130,   131,   132,   133,     0,   128,
     129,   130,   131,   132,     0,     0,     0,   134,   135,   136,
     137,   138,   139,   140,     0,   171,   134,   135,   136,   137,
     138,   139,   140,   134,   135,   136,   137,   138,   139,   140,
      67,    68,     0,     0,     0,     0,     0,     0,    69,     0,
      70,    71,    72,    73,    74,   128,   129,   130,   131,     0,
       0,    75,     0,    76,     0,     0,     0,     0,     0,     0,
      77,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     135,   136,   137,   138,   139,   140,    98,    99,   100,    98,
      99,   100,     0,     0,   101,     0,     0,   101,     0,     0,
     102,   154,     0,   102,     0,     0,   103,     0,     0,   103
};

static const yytype_int16 yycheck[] =
{
      78,    94,    99,    24,    97,     7,     8,     9,    10,    91,
      92,    93,     9,    10,     1,    30,     3,    42,    43,    38,
     102,     8,     0,   105,   106,    60,    13,    46,    43,    31,
      32,    33,    34,    35,    36,    37,    33,    34,    35,    36,
      37,   123,   120,    78,   122,    28,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,    36,
      37,   143,   144,    28,    28,    28,    53,     5,     6,    10,
      35,    58,    35,    40,   171,    13,    43,    15,    16,    17,
      18,    19,   175,   176,     7,     8,     9,    10,    26,    41,
      28,    30,    33,    34,    35,    36,    37,    35,   180,    27,
      40,   194,   184,   185,   182,   183,    41,    45,     5,     6,
      33,    34,    35,    36,    37,    39,    13,   195,    15,    16,
      17,    18,    19,    33,    34,    35,    36,    37,    42,    26,
      43,    28,     5,     6,    28,    21,    22,    23,    35,    25,
      13,    28,    15,    16,    17,    18,    19,    42,    45,    42,
      21,    22,    23,    26,    25,    28,     5,     6,    38,    21,
      22,    23,    35,    25,    13,    40,    15,    16,    17,    18,
      19,    24,    45,     3,    21,    22,    23,    26,    25,    28,
       5,     6,    34,    35,    36,    37,    35,    44,    13,    44,
      15,    16,    17,    18,    19,    38,    45,    38,    41,    28,
      41,    26,    40,    28,     7,     8,     9,    10,    11,    12,
      35,    21,    22,    23,    45,     8,     9,    10,    45,    43,
      45,     7,     8,     9,    10,    11,    12,    41,    31,    32,
      33,    34,    35,    36,    37,    41,    21,    22,    23,    42,
      33,    34,    35,    36,    37,    31,    32,    33,    34,    35,
      36,    37,    35,    36,    37,    44,    42,     7,     8,     9,
      10,    11,    12,    41,    41,    40,    40,    28,    44,     7,
       8,     9,    10,    11,    12,    40,    40,    40,    40,    28,
      28,    31,    32,    33,    34,    35,    36,    37,    28,    46,
      46,     4,    42,    31,    32,    33,    34,    35,    36,    37,
      42,    40,    20,    40,    42,     7,     8,     9,    10,    11,
      12,     4,    44,    44,    15,    37,    41,     7,     8,     9,
      10,    11,    12,    38,    41,    14,     8,    41,    44,    31,
      32,    33,    34,    35,    36,    37,    13,    58,    -1,    -1,
      42,    31,    32,    33,    34,    35,    36,    37,    52,    55,
      -1,    -1,    42,     7,     8,     9,    10,    11,    12,    88,
      -1,    -1,     7,     8,     9,    10,    11,    12,    -1,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    -1,    39,    31,    32,    33,    34,
      35,    36,    37,    31,    32,    33,    34,    35,    36,    37,
       5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      15,    16,    17,    18,    19,     7,     8,     9,    10,    -1,
      -1,    26,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    35,    36,    37,    27,    28,    29,    27,
      28,    29,    -1,    -1,    35,    -1,    -1,    35,    -1,    -1,
      41,    42,    -1,    41,    -1,    -1,    47,    -1,    -1,    47
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    24,    49,    50,    21,    22,    23,    25,    51,    53,
      57,     0,    57,    58,    59,    25,    53,    28,    35,    54,
      28,    23,    59,    60,    38,    41,    52,    28,    40,    43,
      41,    30,    27,    55,    56,    57,    40,    28,    35,    55,
      41,    39,    42,    43,    28,    28,    42,    42,    52,    40,
      55,    44,    44,    24,    61,    61,    25,    57,    62,    63,
       3,    65,    65,    28,    64,    25,    63,     5,     6,    13,
      15,    16,    17,    18,    19,    26,    28,    35,    66,    67,
      68,    69,    70,    71,    72,    73,    45,    45,    43,    40,
      41,    41,    41,    41,    44,    40,    40,    44,    27,    28,
      29,    35,    41,    47,    75,    38,    46,    74,    28,    67,
      68,    40,    40,    40,    40,    64,    28,    75,    75,    75,
      66,    68,    66,    41,    74,    28,    75,    28,     7,     8,
       9,    10,    11,    12,    31,    32,    33,    34,    35,    36,
      37,    75,    75,    46,    46,    40,     4,    42,    42,    42,
      42,    45,    40,    45,    42,    75,    76,    42,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    39,    75,    75,     4,    44,    44,    15,    20,    42,
      43,    74,    66,    66,    41,    41,    75,    45,    45,    75,
      75,    14,    42,    42,    44,    66,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    52,    52,    53,
      53,    53,    54,    54,    54,    54,    55,    55,    55,    56,
      57,    57,    57,    58,    58,    59,    60,    61,    61,    62,
      62,    63,    64,    64,    65,    65,    66,    66,    67,    67,
      67,    67,    67,    67,    67,    67,    68,    68,    69,    69,
      69,    70,    70,    71,    72,    73,    73,    73,    74,    74,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    76,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     3,     2,     2,     1,     4,     3,     3,
       4,     6,     3,     4,     1,     2,     3,     1,     0,     2,
       1,     1,     1,     2,     1,     9,     8,     3,     2,     2,
       1,     3,     3,     1,     5,     4,     2,     1,     2,     2,
       2,     2,     1,     1,     2,     2,     2,     1,     7,     8,
       8,    11,     7,     4,     4,     3,     4,     4,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     3,     1,     1,     1,     2,
       2,     2,     3,     1
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
  case 2: /* sourceCode: GDelcarations FDefBlock MainBlock  */
#line 118 "main.y"
                                                          {root=(yyvsp[-1].nodePtr);}
#line 1455 "y.tab.c"
    break;

  case 3: /* GDelcarations: DECL GDecList ENDDECL  */
#line 121 "main.y"
                                                 {}
#line 1461 "y.tab.c"
    break;

  case 4: /* GDelcarations: DECL ENDDECL  */
#line 122 "main.y"
                                                {}
#line 1467 "y.tab.c"
    break;

  case 5: /* GDecList: GDecList GDecl  */
#line 124 "main.y"
                                                  {}
#line 1473 "y.tab.c"
    break;

  case 6: /* GDecList: GDecl  */
#line 125 "main.y"
                                                 {}
#line 1479 "y.tab.c"
    break;

  case 7: /* ArrList: '[' NUM ']' ArrList  */
#line 127 "main.y"
                                                {(yyval.listPtr)=makeLnode("",(yyvsp[-2].Int),(yyvsp[0].listPtr));}
#line 1485 "y.tab.c"
    break;

  case 8: /* ArrList: '[' NUM ']'  */
#line 128 "main.y"
                                                {(yyval.listPtr)=makeLnode("",(yyvsp[-1].Int),NULL);}
#line 1491 "y.tab.c"
    break;

  case 9: /* GDecl: Type VarList ';'  */
#line 130 "main.y"
                                                 {
                                                  Lnode* ptr=(yyvsp[-1].listPtr);
                                                  for(;ptr;ptr=ptr->next){
                                                    if(lookUpG(ptr->s)){
                                                        yyerror("Variable already Declared");
                                                        exit(0);
                                                    }
                                                    if(ptr->num==valtype) installG(ptr->s,(yyvsp[-2].Int),1,SP++);
                                                    else{
                                                        int type;
                                                        if((yyvsp[-2].Int)==inttype) type=intptrtype;
                                                        else if((yyvsp[-2].Int)==strtype) type=strptrtype;
                                                        else yyerror("forbidden type for pointer ");
                                                        installG(ptr->s,type,1,SP++);
                                                    }
                                                  }
                                                }
#line 1513 "y.tab.c"
    break;

  case 10: /* GDecl: Type ID ArrList ';'  */
#line 147 "main.y"
                                                 {
                                                    if(lookUpG((yyvsp[-2].String))) yyerror("variable already declared");
                                                    int dim=0;
                                                    int size=1;
                                                    Lnode* ptr=(yyvsp[-1].listPtr);
                                                    for(;ptr;ptr=ptr->next){
                                                        dim++;
                                                        size*=ptr->num;
                                                    }
                                                    printf("SIZE OF ARRAY IS %d\n",size);
                                                    int type;
                                                    if((yyvsp[-3].Int)==inttype) type=intarrtype;
                                                    else if((yyvsp[-3].Int)==strtype) type=strarrtype;
                                                    else yyerror("forbidden array type");
                                                    installG((yyvsp[-2].String),type,size,SP);
                                                    SP+=size;
                                                    Gsymbol* g=lookUpG((yyvsp[-2].String));
                                                    g->dim=makeLnode("",dim,(yyvsp[-1].listPtr));
                                                }
#line 1537 "y.tab.c"
    break;

  case 11: /* GDecl: Type ID '(' ParamList ')' ';'  */
#line 166 "main.y"
                                                        {
                                                            if(lookUpG((yyvsp[-4].String))) yyerror("variable already declared");
                                                            installG((yyvsp[-4].String),(yyvsp[-5].Int),0,0);
                                                            Ghead->flabel=flabel++; // assign label and mark variable as function 
                                                            Ghead->paramlist=Lhead;
                                                            Lhead=NULL; // clear Lhead for other parameters
                                                        }
#line 1549 "y.tab.c"
    break;

  case 12: /* VarList: VarList ',' ID  */
#line 174 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),valtype,(yyvsp[-2].listPtr));}
#line 1555 "y.tab.c"
    break;

  case 13: /* VarList: VarList ',' '*' ID  */
#line 175 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),ptrtype,(yyvsp[-3].listPtr));}
#line 1561 "y.tab.c"
    break;

  case 14: /* VarList: ID  */
#line 176 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),valtype,NULL);}
#line 1567 "y.tab.c"
    break;

  case 15: /* VarList: '*' ID  */
#line 177 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),ptrtype,NULL);}
#line 1573 "y.tab.c"
    break;

  case 16: /* ParamList: Param ',' ParamList  */
#line 180 "main.y"
                                    {}
#line 1579 "y.tab.c"
    break;

  case 17: /* ParamList: Param  */
#line 181 "main.y"
                                    {}
#line 1585 "y.tab.c"
    break;

  case 18: /* ParamList: %empty  */
#line 182 "main.y"
                                    {}
#line 1591 "y.tab.c"
    break;

  case 19: /* Param: Type ID  */
#line 184 "main.y"
                                    {
                                        if((yyvsp[-1].Int) != inttype || (yyvsp[-1].Int)!=strtype) yyerror("forbidden type for paramteres");
                                        if(lookUpL((yyvsp[0].String))) yyerror("duplicate parameter");
                                        installL((yyvsp[0].String),(yyvsp[-1].Int),-1); // add parameter to Lhead 
                                    }
#line 1601 "y.tab.c"
    break;

  case 20: /* Type: INT  */
#line 191 "main.y"
                    {(yyval.Int)=inttype;}
#line 1607 "y.tab.c"
    break;

  case 21: /* Type: STR  */
#line 192 "main.y"
                    {(yyval.Int)=strtype;}
#line 1613 "y.tab.c"
    break;

  case 22: /* Type: VOID  */
#line 193 "main.y"
                    {(yyval.Int)=voidtype;}
#line 1619 "y.tab.c"
    break;

  case 25: /* Fdef: Type ID '(' ParamList ')' '{' LdeclBlock Body '}'  */
#line 200 "main.y"
                                                                {/*iterate through paramlist and Lhead and check correctness and assign relative binding*/
                                                                    Gsymbol* funct=lookUpG((yyvsp[-7].String));
                                                                    if(!funct || funct->flabel==-1) yyerror("undeclared function");
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
                                                                    installFunction(makeNode(0,inttype,funct,funct->paramlist,tFUNCT,NULL,(yyvsp[-1].nodePtr),NULL)); //->right points to function definition and left to next function 
                                                                }
#line 1647 "y.tab.c"
    break;

  case 26: /* MainBlock: VOID MAIN '(' ')' '{' LdeclBlock Body '}'  */
#line 225 "main.y"
                                                            {
                                                                if(lookUpG((yyvsp[-6].String))) yyerror("only one main function allowed");
                                                                installG((yyvsp[-6].String),voidtype,0,0);
                                                                Ghead->flabel=flabel++; // assign label and mark variable as function 
                                                                Ghead->paramlist=Lhead;
                                                                Ghead->fsymbols=Lhead;
                                                                int offset=1;
                                                                for(;Lhead;Lhead=Lhead->next){
                                                                    Lhead->binding=offset++;
                                                                }
                                                                installFunction(makeNode(0,inttype,Ghead,Ghead->paramlist,tFUNCT,NULL,(yyvsp[-1].nodePtr),NULL));
                                                            }
#line 1664 "y.tab.c"
    break;

  case 31: /* LDecl: Type IdList ';'  */
#line 245 "main.y"
                                {
                                    Lnode* ptr=(yyvsp[-1].listPtr);
                                    for(;ptr;ptr=ptr->next){
                                        if(lookUpL(ptr->s)) yyerror("variable already declared");
                                        installL(ptr->s,(yyvsp[-2].Int),-1);
                                    }
                                }
#line 1676 "y.tab.c"
    break;

  case 32: /* IdList: ID ',' IdList  */
#line 253 "main.y"
                                {(yyval.listPtr)=makeLnode((yyvsp[-2].String),valtype,(yyvsp[0].listPtr));}
#line 1682 "y.tab.c"
    break;

  case 33: /* IdList: ID  */
#line 254 "main.y"
                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),valtype,NULL);}
#line 1688 "y.tab.c"
    break;

  case 34: /* Body: begin Slist ReturnStmt ';' end  */
#line 258 "main.y"
                                                {(yyval.nodePtr)=makeNode(0,0,NULL,NULL,tCONNECT,(yyvsp[-3].nodePtr),(yyvsp[-2].nodePtr),NULL);}
#line 1694 "y.tab.c"
    break;

  case 35: /* Body: begin ReturnStmt ';' end  */
#line 259 "main.y"
                                                {(yyval.nodePtr)=(yyvsp[-2].nodePtr);}
#line 1700 "y.tab.c"
    break;

  case 36: /* Slist: Slist Stmt  */
#line 261 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,0,NULL,NULL,tCONNECT,(yyvsp[-1].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1706 "y.tab.c"
    break;

  case 37: /* Slist: Stmt  */
#line 262 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 1712 "y.tab.c"
    break;

  case 38: /* Stmt: InputStmt ';'  */
#line 264 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1718 "y.tab.c"
    break;

  case 39: /* Stmt: OutputStmt ';'  */
#line 265 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1724 "y.tab.c"
    break;

  case 40: /* Stmt: AssgStmt ';'  */
#line 266 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1730 "y.tab.c"
    break;

  case 41: /* Stmt: ReturnStmt ';'  */
#line 267 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1736 "y.tab.c"
    break;

  case 42: /* Stmt: Ifstmt  */
#line 268 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 1742 "y.tab.c"
    break;

  case 43: /* Stmt: LoopStmt  */
#line 269 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 1748 "y.tab.c"
    break;

  case 44: /* Stmt: BREAK ';'  */
#line 270 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,0,NULL,NULL,tBREAK,NULL,NULL,NULL);}
#line 1754 "y.tab.c"
    break;

  case 45: /* Stmt: CONTINUE ';'  */
#line 271 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,0,NULL,NULL,tCONTINUE,NULL,NULL,NULL);}
#line 1760 "y.tab.c"
    break;

  case 46: /* ReturnStmt: RETURN Expr  */
#line 273 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,0,NULL,NULL,tRETURN,(yyvsp[0].nodePtr),(yyvsp[0].nodePtr),(yyvsp[0].nodePtr));}
#line 1766 "y.tab.c"
    break;

  case 47: /* ReturnStmt: RETURN  */
#line 274 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,0,NULL,NULL,tRETURN,NULL,NULL,NULL);}
#line 1772 "y.tab.c"
    break;

  case 48: /* LoopStmt: WHILE '(' Expr ')' '{' Slist '}'  */
#line 276 "main.y"
                                                    {if(isBoolean((yyvsp[-4].nodePtr),(yyvsp[-4].nodePtr))) (yyval.nodePtr)=makeNode(0,0,NULL,NULL,tWHILE,(yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr),(yyvsp[-4].nodePtr));}
#line 1778 "y.tab.c"
    break;

  case 49: /* LoopStmt: DO '{' Slist '}' WHILE '(' Expr ')'  */
#line 277 "main.y"
                                                                {if(isBoolean((yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr))) (yyval.nodePtr)=makeNode(0,0,NULL,NULL,tDOWHILE,(yyvsp[-5].nodePtr),(yyvsp[-5].nodePtr),(yyvsp[-1].nodePtr));}
#line 1784 "y.tab.c"
    break;

  case 50: /* LoopStmt: REPEAT '{' Slist '}' UNTIL '(' Expr ')'  */
#line 278 "main.y"
                                                                    {if(isBoolean((yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr))) (yyval.nodePtr)=makeNode(0,0,NULL,NULL,tREPEATUNTIL,(yyvsp[-5].nodePtr),(yyvsp[-5].nodePtr),(yyvsp[-1].nodePtr));}
#line 1790 "y.tab.c"
    break;

  case 51: /* Ifstmt: IF '(' Expr ')' '{' Slist '}' Else '{' Slist '}'  */
#line 280 "main.y"
                                                             {if(isBoolean((yyvsp[-8].nodePtr),(yyvsp[-8].nodePtr))) (yyval.nodePtr)=makeNode(0,0,NULL,NULL,tIF,(yyvsp[-5].nodePtr),(yyvsp[-1].nodePtr),(yyvsp[-8].nodePtr));}
#line 1796 "y.tab.c"
    break;

  case 52: /* Ifstmt: IF '(' Expr ')' '{' Slist '}'  */
#line 281 "main.y"
                                                    {if(isBoolean((yyvsp[-4].nodePtr),(yyvsp[-4].nodePtr))) (yyval.nodePtr)=makeNode(0,0,NULL,NULL,tIF,(yyvsp[-1].nodePtr),NULL,(yyvsp[-4].nodePtr));}
#line 1802 "y.tab.c"
    break;

  case 53: /* InputStmt: READ '(' ID ')'  */
#line 283 "main.y"
                                    {
                                    Gsymbol* Gptr=lookUpG((yyvsp[-1].String));
                                    Lsymbol* Lptr=lookUpL((yyvsp[-1].String));
                                    if(Gptr==NULL && Lptr==NULL) yyerror("undeclared Variable");
                                    node* temp=makeNode(0,0,Gptr,Lptr,tVAR,NULL,NULL,NULL);
                                    (yyval.nodePtr)=makeNode(0,0,NULL,NULL,tREAD,temp,temp,NULL);
                                    }
#line 1814 "y.tab.c"
    break;

  case 54: /* OutputStmt: WRITE '(' Expr ')'  */
#line 291 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,0,NULL,NULL,tWRITE,(yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr),NULL);}
#line 1820 "y.tab.c"
    break;

  case 55: /* AssgStmt: ID '=' Expr  */
#line 293 "main.y"
                                    {
                                    Gsymbol* Gptr=lookUpG((yyvsp[-2].String));
                                    Lsymbol* Lptr=lookUpL((yyvsp[-2].String));
                                    if(Gptr==NULL && Lptr==NULL) yyerror("undelcared variable");
                                    node* temp=makeNode(0,(Lptr?Lptr->type:Gptr->type),Gptr,Lptr,tVAR,NULL,NULL,NULL);
                                    (yyval.nodePtr)=makeNode(0,0,NULL,NULL,tASSIGN,temp,(yyvsp[0].nodePtr),NULL);
                                    }
#line 1832 "y.tab.c"
    break;

  case 56: /* AssgStmt: '*' ID '=' Expr  */
#line 300 "main.y"
                                    {
                                    Gsymbol* Gptr=lookUpG((yyvsp[-2].String));
                                    Lsymbol* Lptr=lookUpL((yyvsp[-2].String));
                                    if(Gptr==NULL && Lptr==NULL) yyerror("undelcared variable");
                                    node* var=makeNode(0,(Lptr?Lptr->type:Gptr->type),Gptr,Lptr,tVAR,NULL,NULL,NULL); 
                                    if(Lptr && Lptr->type==intptrtype)var=makeNode(0,inttype,NULL,NULL,tVALUEAT,var,var,var);
                                    else if(Lptr && Lptr->type==strptrtype) var=makeNode(0,strtype,NULL,NULL,tVALUEAT,var,var,var);
                                    else if(Gptr->type==intptrtype) var=makeNode(0,inttype,NULL,NULL,tVALUEAT,var,var,var);
                                    else if(Gptr->type==strptrtype) var=makeNode(0,strtype,NULL,NULL,tVALUEAT,var,var,var);
                                    else yyerror("type mismatch");
                                    (yyval.nodePtr)=makeNode(0,0,NULL,NULL,tASSIGN,var,(yyvsp[0].nodePtr),NULL);
                                    }
#line 1849 "y.tab.c"
    break;

  case 57: /* AssgStmt: ID Array '=' Expr  */
#line 312 "main.y"
                                  {
                                        Gsymbol* ptr=lookUpG((yyvsp[-3].String)); // no need to look at local variable as array is only declared in global
                                        if(!ptr) yyerror("variable undeclared");
                                        node* var=NULL;
                                        if(ptr->type==intarrtype) var=makeNode(0,inttype,ptr,NULL,tARRVAL,(yyvsp[-2].nodePtr),(yyvsp[-2].nodePtr),(yyvsp[-2].nodePtr));
                                        else if(ptr->type==strarrtype) var=makeNode(0,strtype,ptr,NULL,tARRVAL,(yyvsp[-2].nodePtr),(yyvsp[-2].nodePtr),(yyvsp[-2].nodePtr));
                                        if(var->type!=(yyvsp[0].nodePtr)->type) yyerror("type mismatch");
                                        (yyval.nodePtr)=makeNode(0,inttype,NULL,NULL,tASSIGN,var,(yyvsp[0].nodePtr),(yyvsp[0].nodePtr));
                                    }
#line 1863 "y.tab.c"
    break;

  case 58: /* Array: '[' Expr ']' Array  */
#line 322 "main.y"
                                       {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[-2].nodePtr))){
                                            (yyvsp[-2].nodePtr)->left=(yyvsp[0].nodePtr);
                                            (yyval.nodePtr)=(yyvsp[-2].nodePtr);
                                        }
                                      }
#line 1873 "y.tab.c"
    break;

  case 59: /* Array: '[' Expr ']'  */
#line 327 "main.y"
                                       {if(isArithmetic((yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr))) (yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1879 "y.tab.c"
    break;

  case 60: /* Expr: Expr '+' Expr  */
#line 330 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,inttype,NULL,NULL,tADD,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1885 "y.tab.c"
    break;

  case 61: /* Expr: Expr '-' Expr  */
#line 331 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,inttype,NULL,NULL,tSUB,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1891 "y.tab.c"
    break;

  case 62: /* Expr: Expr '*' Expr  */
#line 332 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,inttype,NULL,NULL,tMUL,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1897 "y.tab.c"
    break;

  case 63: /* Expr: Expr '/' Expr  */
#line 333 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,inttype,NULL,NULL,tDIV,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1903 "y.tab.c"
    break;

  case 64: /* Expr: Expr '%' Expr  */
#line 334 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,inttype,NULL,NULL,tMOD,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1909 "y.tab.c"
    break;

  case 65: /* Expr: Expr '>' Expr  */
#line 335 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,booltype,NULL,NULL,tGT,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1915 "y.tab.c"
    break;

  case 66: /* Expr: Expr '<' Expr  */
#line 336 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,booltype,NULL,NULL,tLT,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1921 "y.tab.c"
    break;

  case 67: /* Expr: Expr GE Expr  */
#line 337 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,booltype,NULL,NULL,tGE,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1927 "y.tab.c"
    break;

  case 68: /* Expr: Expr LE Expr  */
#line 338 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,booltype,NULL,NULL,tLE,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1933 "y.tab.c"
    break;

  case 69: /* Expr: Expr EQ Expr  */
#line 339 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,booltype,NULL,NULL,tEQ,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1939 "y.tab.c"
    break;

  case 70: /* Expr: Expr NEQ Expr  */
#line 340 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,booltype,NULL,NULL,tNEQ,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1945 "y.tab.c"
    break;

  case 71: /* Expr: Expr AND Expr  */
#line 341 "main.y"
                                    {if(isBoolean((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,booltype,NULL,NULL,tAND,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1951 "y.tab.c"
    break;

  case 72: /* Expr: Expr OR Expr  */
#line 342 "main.y"
                                    {if(isBoolean((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,booltype,NULL,NULL,tOR,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1957 "y.tab.c"
    break;

  case 73: /* Expr: '(' Expr ')'  */
#line 343 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1963 "y.tab.c"
    break;

  case 74: /* Expr: ID '(' ArgList ')'  */
#line 344 "main.y"
                                    {
                                        Gsymbol* fg=lookUpG((yyvsp[-3].String));
                                        if(!fg) yyerror("function not defined");
                                        node* ptr=(yyvsp[-1].nodePtr);
                                        Lsymbol* ld=fg->paramlist;
                                        for(;ptr && ld;ld=ld->next,ptr=ptr->center){
                                            if(ptr->type!=ld->type) yyerror("type mismatch");
                                        }
                                        if(ptr) yyerror("error in argument list");
                                        if(ld && ld->binding<0) yyerror("error in argument list");
                                        (yyval.nodePtr)=makeNode(0,fg->type,fg,NULL,tFUNCTCALL,(yyvsp[-1].nodePtr),NULL,NULL); //left contains argument list for function call
                                    }
#line 1980 "y.tab.c"
    break;

  case 75: /* Expr: ID '(' ')'  */
#line 356 "main.y"
                                    {
                                        Gsymbol* fg=lookUpG((yyvsp[-2].String));
                                        if(!fg) yyerror("function not defined");
                                        Lsymbol* ld=fg->paramlist;
                                        if(ld && ld->binding<0) yyerror("error in argument list");
                                        (yyval.nodePtr)=makeNode(0,fg->type,fg,NULL,tFUNCTCALL,NULL,NULL,NULL); //left contains argument list for function call
                                    }
#line 1992 "y.tab.c"
    break;

  case 76: /* Expr: NUM  */
#line 363 "main.y"
                                    {(yyval.nodePtr)=makeNode((yyvsp[0].Int),inttype,NULL,NULL,tCONST,NULL,NULL,NULL);}
#line 1998 "y.tab.c"
    break;

  case 77: /* Expr: LITERAL  */
#line 364 "main.y"
                                    {
                                     printf("STARTED parsing literal");
                                     (yyval.nodePtr)=makeNode(0,strtype,NULL,NULL,tLITERAL,NULL,NULL,NULL);
                                     (yyval.nodePtr)->literal=(yyvsp[0].String);
                                     printf("FINISHED parsing literal");
                                    }
#line 2009 "y.tab.c"
    break;

  case 78: /* Expr: ID  */
#line 370 "main.y"
                                    {
                                    printf("From expr %s\n",(yyvsp[0].String));
                                    Gsymbol* Gptr=lookUpG((yyvsp[0].String));
                                    Lsymbol* Lptr=lookUpL((yyvsp[0].String));
                                    if(Lptr==NULL && Gptr==NULL) yyerror("undelcared variable");
                                    (yyval.nodePtr)=makeNode(0,(Lptr?Lptr->type:Gptr->type),Gptr,Lptr,tVAR,NULL,NULL,NULL);
                                    }
#line 2021 "y.tab.c"
    break;

  case 79: /* Expr: '&' ID  */
#line 377 "main.y"
                                    {
                                    Gsymbol* Gptr=lookUpG((yyvsp[0].String));
                                    Lsymbol* Lptr=lookUpL((yyvsp[0].String));
                                    if(Lptr==NULL && Gptr==NULL) yyerror("undelcared variable");
                                    node* var=makeNode(0,(Lptr?Lptr->type:Gptr->type),Gptr,Lptr,tVAR,NULL,NULL,NULL);
                                    (yyval.nodePtr)=makeNode(0,inttype,NULL,NULL,tADDRESSOF,var,var,var) ; // i don't see the point of address type, now we can do &var+1 and all
                                    }
#line 2033 "y.tab.c"
    break;

  case 80: /* Expr: '*' ID  */
#line 384 "main.y"
                                    {
                                    Gsymbol* Gptr=lookUpG((yyvsp[0].String));
                                    Lsymbol* Lptr=lookUpL((yyvsp[0].String));
                                    if(Gptr==NULL && Lptr==NULL) yyerror("undeclared variable");
                                    node* var=makeNode(0,(Lptr?Lptr->type:Gptr->type),Gptr,Lptr,tVAR,NULL,NULL,NULL); 
                                    if(Lptr && Lptr->type==intptrtype)(yyval.nodePtr)=makeNode(0,inttype,NULL,NULL,tVALUEAT,var,var,var);
                                    else if(Lptr && Lptr->type==strptrtype) (yyval.nodePtr)=makeNode(0,strtype,NULL,NULL,tVALUEAT,var,var,var);
                                    else if(Gptr->type==intptrtype)(yyval.nodePtr)=makeNode(0,inttype,NULL,NULL,tVALUEAT,var,var,var);
                                    else if(Gptr->type==strptrtype) (yyval.nodePtr)=makeNode(0,strtype,NULL,NULL,tVALUEAT,var,var,var);
                                    }
#line 2048 "y.tab.c"
    break;

  case 81: /* Expr: ID Array  */
#line 394 "main.y"
                                {
                                    Gsymbol* ptr=lookUpG((yyvsp[-1].String));
                                    if(!ptr) yyerror("variable undeclared");
                                    if(ptr->type==intarrtype) (yyval.nodePtr)=makeNode(0,inttype,ptr,NULL,tARRVAL,(yyvsp[0].nodePtr),(yyvsp[0].nodePtr),(yyvsp[0].nodePtr));
                                    else if(ptr->type==strarrtype) (yyval.nodePtr)=makeNode(0,strtype,ptr,NULL,tARRVAL,(yyvsp[0].nodePtr),(yyvsp[0].nodePtr),(yyvsp[0].nodePtr));
                                }
#line 2059 "y.tab.c"
    break;

  case 82: /* ArgList: ArgList ',' Expr  */
#line 401 "main.y"
                            {   // argument list will be linked with center pointer
                                (yyvsp[-2].nodePtr)->center=(yyvsp[0].nodePtr);
                                (yyval.nodePtr)=(yyvsp[-2].nodePtr);
                            }
#line 2068 "y.tab.c"
    break;

  case 83: /* ArgList: Expr  */
#line 405 "main.y"
                            {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 2074 "y.tab.c"
    break;


#line 2078 "y.tab.c"

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

#line 408 "main.y"


int main(){
    FILE *fp=fopen("input.ac","r");
    yyin=fp;
    SP=4096;
    yyparse();
    Gsymbol* ptr=Ghead;
    if(!ptr) printf("What\n");
    for(;ptr;ptr=ptr->next)printf("%s ",ptr->name);
    printf("parsing complete\n");

    printf("functions\n");
    for(;functions;functions=functions->left){
        printf("%s ",functions->Gvar->name);
    }
    /* outFile=fopen("a.xsm","w");
    space=0;
    printTree(root);
    currReg=0;

    genHeader();
    genVarSpaceCode(); // set stack pointer to after declarations
    int reg=genCode(root);
    printf("codeGen completed\n");
    fprintf(outFile,"JMP EXITCODE!\n");
    genErrorHandler();
    genExit(); */ 
    return 0;
}

void yyerror(char* s){
    printf("%s\n",s);
    exit(0);
}

void installFunction(node* f){
    f->left=functions;
    functions=f;
}// left left chain of functions

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

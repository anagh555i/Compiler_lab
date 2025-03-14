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

    node* root;          // AST root;
    Gsymbol* Ghead=NULL; // global symbol table head
    //makeNode(val,type,varname,nodeType,left,right,center);

    FILE* outFile;
    int currReg;

    int space=0;
    int varBase=4096;
    int SP=4096;
    int label=0;
    int WHILELABELS[]={-1,-1};// new list based while labels storage required
    Lnode* breakLabels=NULL;
    Lnode* continueLabels=NULL;

#line 99 "y.tab.c"

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
    DECL = 278,                    /* DECL  */
    ENDDECL = 279,                 /* ENDDECL  */
    NUM = 280,                     /* NUM  */
    ID = 281,                      /* ID  */
    LITERAL = 282                  /* LITERAL  */
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
#define DECL 278
#define ENDDECL 279
#define NUM 280
#define ID 281
#define LITERAL 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 30 "main.y"

    int Int;
    char Char;
    struct node* nodePtr;
    char* String;
    struct Lnode* listPtr;

#line 214 "y.tab.c"

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
  YYSYMBOL_DECL = 23,                      /* DECL  */
  YYSYMBOL_ENDDECL = 24,                   /* ENDDECL  */
  YYSYMBOL_NUM = 25,                       /* NUM  */
  YYSYMBOL_ID = 26,                        /* ID  */
  YYSYMBOL_LITERAL = 27,                   /* LITERAL  */
  YYSYMBOL_28_ = 28,                       /* '<'  */
  YYSYMBOL_29_ = 29,                       /* '>'  */
  YYSYMBOL_30_ = 30,                       /* '+'  */
  YYSYMBOL_31_ = 31,                       /* '-'  */
  YYSYMBOL_32_ = 32,                       /* '*'  */
  YYSYMBOL_33_ = 33,                       /* '/'  */
  YYSYMBOL_34_ = 34,                       /* '%'  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_36_ = 36,                       /* '['  */
  YYSYMBOL_37_ = 37,                       /* ']'  */
  YYSYMBOL_38_ = 38,                       /* ','  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* '{'  */
  YYSYMBOL_42_ = 42,                       /* '}'  */
  YYSYMBOL_43_ = 43,                       /* '='  */
  YYSYMBOL_44_ = 44,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_sourceCode = 46,                /* sourceCode  */
  YYSYMBOL_Delcarations = 47,              /* Delcarations  */
  YYSYMBOL_DecList = 48,                   /* DecList  */
  YYSYMBOL_Decl = 49,                      /* Decl  */
  YYSYMBOL_ArrList = 50,                   /* ArrList  */
  YYSYMBOL_VarList = 51,                   /* VarList  */
  YYSYMBOL_Program = 52,                   /* Program  */
  YYSYMBOL_Slist = 53,                     /* Slist  */
  YYSYMBOL_Stmt = 54,                      /* Stmt  */
  YYSYMBOL_LoopStmt = 55,                  /* LoopStmt  */
  YYSYMBOL_Ifstmt = 56,                    /* Ifstmt  */
  YYSYMBOL_InputStmt = 57,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 58,                /* OutputStmt  */
  YYSYMBOL_AssgStmt = 59,                  /* AssgStmt  */
  YYSYMBOL_Array = 60,                     /* Array  */
  YYSYMBOL_Expr = 61                       /* Expr  */
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   438

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


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
       2,     2,     2,     2,     2,     2,     2,    34,    44,     2,
      39,    40,    32,    30,    38,    31,     2,    33,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      28,    43,    29,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    36,     2,    37,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    98,    98,   101,   102,   104,   105,   107,   119,   130,
     145,   161,   162,   164,   165,   166,   167,   172,   173,   175,
     176,   178,   179,   180,   181,   182,   183,   184,   186,   187,
     188,   190,   191,   193,   201,   203,   210,   220,   230,   235,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   248,   249,   250,   251,   252,   258,   264,   271,   279
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
  "DO", "BREAK", "CONTINUE", "REPEAT", "UNTIL", "INT", "STR", "DECL",
  "ENDDECL", "NUM", "ID", "LITERAL", "'<'", "'>'", "'+'", "'-'", "'*'",
  "'/'", "'%'", "';'", "'['", "']'", "','", "'('", "')'", "'{'", "'}'",
  "'='", "'&'", "$accept", "sourceCode", "Delcarations", "DecList", "Decl",
  "ArrList", "VarList", "Program", "Slist", "Stmt", "LoopStmt", "Ifstmt",
  "InputStmt", "OutputStmt", "AssgStmt", "Array", "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-66)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -9,    96,    35,    40,    -1,     0,   -66,   117,   -66,   -66,
     331,   -66,     9,    45,   -25,     9,    42,   -66,   -66,   -66,
      22,    43,    51,    58,    52,    46,    63,    61,   -27,    78,
     349,   -66,   -66,   -66,    75,    76,    80,    94,    98,   -66,
     -66,     1,   102,   -66,   116,    -3,    -3,    -3,   406,   -66,
     -66,   406,    -3,    -3,   101,   139,   -66,   -66,   -66,   -66,
     -66,   146,   -66,   -66,   178,   -66,   165,   -66,   170,   -66,
     181,    -3,   182,   156,   169,   203,     2,    57,   297,   362,
      -3,    -3,     9,   -66,   -66,   -66,   -66,   216,   -66,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,    -3,
      -3,    -3,   -66,   175,   179,   204,   201,   170,   362,   362,
     -66,   -66,   161,   208,    54,   127,   376,   369,   309,   121,
      34,   141,     4,   188,   -66,   406,   406,   190,   191,   -66,
      90,   108,    -3,    -3,   237,   -66,   250,   263,   211,   -66,
     -66,   406,   130,   -66
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     4,     0,     6,     1,
       0,     2,    15,     0,     0,    15,     0,     3,     5,    18,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    20,    25,    24,     0,     0,     0,     0,     0,    16,
       7,     0,     0,     8,     0,     0,     0,     0,     0,    26,
      27,     0,     0,     0,     0,     0,    17,    19,    21,    22,
      23,     0,     9,    13,     0,    10,     0,    54,    56,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
       0,     0,    12,    14,    33,    59,    58,     0,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    34,     0,     0,     0,     0,    39,    37,    36,
      11,    53,    47,    48,    49,    50,    51,    52,    46,    45,
      40,    41,    42,    43,    44,     0,     0,     0,     0,    38,
       0,     0,     0,     0,    32,    28,     0,     0,     0,    29,
      30,     0,     0,    31
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -66,   -66,   -66,   -66,   246,   -13,   249,   -66,   -47,   -30,
     -66,   -66,   -66,   -66,   -66,   -65,   -41
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     7,     8,    38,    14,    11,    30,    31,
      32,    33,    34,    35,    36,    54,    73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    76,    42,    85,    77,    74,    75,    20,    21,    52,
      40,    78,    79,    41,     1,    22,    53,    23,    24,    25,
      26,    27,    67,    68,    69,    12,    15,    63,    28,    70,
      87,    13,    13,    64,    29,     9,    71,   100,   101,   108,
     109,    72,   129,    10,   105,    37,    57,    57,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    44,    20,    21,    92,    98,    99,   100,   101,   110,
      22,    39,    23,    24,    25,    26,    27,    43,   130,   131,
      41,    49,    45,    28,    97,    98,    99,   100,   101,    29,
      46,   136,   137,    48,   142,    20,    21,    47,    50,   106,
      57,    57,    51,    22,    55,    23,    24,    25,    26,    27,
      58,    59,    57,    20,    21,    60,    28,     4,     5,    61,
       6,    22,    29,    23,    24,    25,    26,    27,    89,    90,
      91,    92,   134,    62,    28,    20,    21,    65,     4,     5,
      29,    17,    66,    22,    80,    23,    24,    25,    26,    27,
     135,    97,    98,    99,   100,   101,    28,    97,    98,    99,
     100,   101,    29,    89,    90,    91,    92,    93,    94,    90,
      91,    92,   143,    99,   100,   101,    89,    90,    91,    92,
      93,    94,    81,    82,    95,    96,    97,    98,    99,   100,
     101,    97,    98,    99,   100,   101,   102,    95,    96,    97,
      98,    99,   100,   101,    83,    84,    52,    86,    88,   103,
      89,    90,    91,    92,    93,    94,   125,    91,    92,   127,
     126,   128,   101,    89,    90,    91,    92,    93,    94,   132,
     133,    95,    96,    97,    98,    99,   100,   101,    97,    98,
      99,   100,   101,   104,    95,    96,    97,    98,    99,   100,
     101,   138,   141,    18,    16,     0,   111,    89,    90,    91,
      92,    93,    94,     0,     0,     0,     0,     0,     0,     0,
      89,    90,    91,    92,    93,    94,     0,     0,    95,    96,
      97,    98,    99,   100,   101,     0,     0,     0,     0,     0,
     139,    95,    96,    97,    98,    99,   100,   101,     0,     0,
       0,     0,     0,   140,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,    89,    90,    91,    92,
       0,     0,     0,     0,     0,    95,    96,    97,    98,    99,
     100,   101,     0,     0,   107,    19,    20,    21,    96,    97,
      98,    99,   100,   101,    22,     0,    23,    24,    25,    26,
      27,     0,     0,    56,    20,    21,     0,    28,     0,     0,
       0,     0,    22,    29,    23,    24,    25,    26,    27,    89,
      90,    91,    92,    93,    94,    28,    89,    90,    91,    92,
      93,    29,     0,    89,    90,    91,    92,     0,     0,     0,
      95,    96,    97,    98,    99,   100,   101,    95,    96,    97,
      98,    99,   100,   101,    95,    96,    97,    98,    99,   100,
     101,    20,    21,     0,     0,     0,     0,     0,     0,    22,
       0,    23,    24,    25,    26,    27,     0,     0,     0,     0,
       0,     0,    28,     0,     0,     0,     0,     0,    29
};

static const yytype_int16 yycheck[] =
{
      30,    48,    15,    68,    51,    46,    47,     5,     6,    36,
      35,    52,    53,    38,    23,    13,    43,    15,    16,    17,
      18,    19,    25,    26,    27,    26,    26,    26,    26,    32,
      71,    32,    32,    32,    32,     0,    39,    33,    34,    80,
      81,    44,   107,     3,    42,    36,    76,    77,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    39,     5,     6,    10,    31,    32,    33,    34,    82,
      13,    26,    15,    16,    17,    18,    19,    35,   125,   126,
      38,    35,    39,    26,    30,    31,    32,    33,    34,    32,
      39,   132,   133,    41,   141,     5,     6,    39,    35,    42,
     130,   131,    41,    13,    26,    15,    16,    17,    18,    19,
      35,    35,   142,     5,     6,    35,    26,    21,    22,    25,
      24,    13,    32,    15,    16,    17,    18,    19,     7,     8,
       9,    10,    42,    35,    26,     5,     6,    35,    21,    22,
      32,    24,    26,    13,    43,    15,    16,    17,    18,    19,
      42,    30,    31,    32,    33,    34,    26,    30,    31,    32,
      33,    34,    32,     7,     8,     9,    10,    11,    12,     8,
       9,    10,    42,    32,    33,    34,     7,     8,     9,    10,
      11,    12,    43,    37,    28,    29,    30,    31,    32,    33,
      34,    30,    31,    32,    33,    34,    40,    28,    29,    30,
      31,    32,    33,    34,    26,    40,    36,    26,    26,    40,
       7,     8,     9,    10,    11,    12,    41,     9,    10,    15,
      41,    20,    34,     7,     8,     9,    10,    11,    12,    39,
      39,    28,    29,    30,    31,    32,    33,    34,    30,    31,
      32,    33,    34,    40,    28,    29,    30,    31,    32,    33,
      34,    14,    41,     7,     5,    -1,    40,     7,     8,     9,
      10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       7,     8,     9,    10,    11,    12,    -1,    -1,    28,    29,
      30,    31,    32,    33,    34,    -1,    -1,    -1,    -1,    -1,
      40,    28,    29,    30,    31,    32,    33,    34,    -1,    -1,
      -1,    -1,    -1,    40,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,
      33,    34,    -1,    -1,    37,     4,     5,     6,    29,    30,
      31,    32,    33,    34,    13,    -1,    15,    16,    17,    18,
      19,    -1,    -1,     4,     5,     6,    -1,    26,    -1,    -1,
      -1,    -1,    13,    32,    15,    16,    17,    18,    19,     7,
       8,     9,    10,    11,    12,    26,     7,     8,     9,    10,
      11,    32,    -1,     7,     8,     9,    10,    -1,    -1,    -1,
      28,    29,    30,    31,    32,    33,    34,    28,    29,    30,
      31,    32,    33,    34,    28,    29,    30,    31,    32,    33,
      34,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    13,
      -1,    15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    23,    46,    47,    21,    22,    24,    48,    49,     0,
       3,    52,    26,    32,    51,    26,    51,    24,    49,     4,
       5,     6,    13,    15,    16,    17,    18,    19,    26,    32,
      53,    54,    55,    56,    57,    58,    59,    36,    50,    26,
      35,    38,    50,    35,    39,    39,    39,    39,    41,    35,
      35,    41,    36,    43,    60,    26,     4,    54,    35,    35,
      35,    25,    35,    26,    32,    35,    26,    25,    26,    27,
      32,    39,    44,    61,    61,    61,    53,    53,    61,    61,
      43,    43,    37,    26,    40,    60,    26,    61,    26,     7,
       8,     9,    10,    11,    12,    28,    29,    30,    31,    32,
      33,    34,    40,    40,    40,    42,    42,    37,    61,    61,
      50,    40,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    41,    41,    15,    20,    60,
      53,    53,    39,    39,    42,    42,    61,    61,    14,    40,
      40,    41,    53,    42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    49,    49,    49,
      49,    50,    50,    51,    51,    51,    51,    52,    52,    53,
      53,    54,    54,    54,    54,    54,    54,    54,    55,    55,
      55,    56,    56,    57,    58,    59,    59,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     2,     1,     3,     3,     4,
       4,     4,     3,     3,     4,     1,     2,     3,     2,     2,
       1,     2,     2,     2,     1,     1,     2,     2,     7,     8,
       8,    11,     7,     4,     4,     3,     4,     4,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     1,     2,     2,     2
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
  case 2: /* sourceCode: Delcarations Program  */
#line 98 "main.y"
                                                {root=(yyvsp[0].nodePtr);}
#line 1394 "y.tab.c"
    break;

  case 3: /* Delcarations: DECL DecList ENDDECL  */
#line 101 "main.y"
                                                {}
#line 1400 "y.tab.c"
    break;

  case 4: /* Delcarations: DECL ENDDECL  */
#line 102 "main.y"
                                                {}
#line 1406 "y.tab.c"
    break;

  case 5: /* DecList: DecList Decl  */
#line 104 "main.y"
                                                {}
#line 1412 "y.tab.c"
    break;

  case 6: /* DecList: Decl  */
#line 105 "main.y"
                                                {}
#line 1418 "y.tab.c"
    break;

  case 7: /* Decl: INT VarList ';'  */
#line 107 "main.y"
                                                {
                                                  Lnode* ptr=(yyvsp[-1].listPtr);
                                                  for(;ptr;ptr=ptr->next){
                                                        if(lookUp(ptr->s)){
                                                            yyerror("Variable already Declared");
                                                            exit(0);
                                                        }
                                                        if(ptr->num==valtype) install(ptr->s,inttype,1,SP++);
                                                        else install(ptr->s,intptrtype,1,SP++);
                                                        // install(char* name,int type, int size,int binding);
                                                  }
                                                }
#line 1435 "y.tab.c"
    break;

  case 8: /* Decl: STR VarList ';'  */
#line 119 "main.y"
                                                {
                                                  Lnode* ptr=(yyvsp[-1].listPtr);
                                                  for(;ptr;ptr=ptr->next){
                                                        if(lookUp(ptr->s)){
                                                        yyerror("Variable already Declared");
                                                        exit(0);
                                                        }
                                                        if(ptr->num==valtype) install(ptr->s,strtype,1,SP++);
                                                        else install(ptr->s,strptrtype,1,SP++);
                                                  }
                                                }
#line 1451 "y.tab.c"
    break;

  case 9: /* Decl: INT ID ArrList ';'  */
#line 130 "main.y"
                                                {
                                                    if(lookUp((yyvsp[-2].String))) yyerror("variable already declared");
                                                    int dim=0;
                                                    int size=1;
                                                    Lnode* ptr=(yyvsp[-1].listPtr);
                                                    for(;ptr;ptr=ptr->next){
                                                        dim++;
                                                        size*=ptr->num;
                                                    }
                                                    printf("SIZE OF ARRAY IS %d\n",size);
                                                    install((yyvsp[-2].String),intarrtype,size,SP);
                                                    SP+=size;
                                                    Gsymbol* g=lookUp((yyvsp[-2].String));
                                                    g->dim=makeLnode("",dim,(yyvsp[-1].listPtr));
                                                }
#line 1471 "y.tab.c"
    break;

  case 10: /* Decl: STR ID ArrList ';'  */
#line 145 "main.y"
                                                {
                                                    if(lookUp((yyvsp[-2].String))) yyerror("variable already declared");
                                                    int dim=0;
                                                    int size=1;
                                                    Lnode* ptr=(yyvsp[-1].listPtr);
                                                    for(;ptr;ptr=ptr->next){
                                                        dim++;
                                                        size*=ptr->num;
                                                    }
                                                    printf("SIZE OF ARRAY IS %d\n",size);
                                                    install((yyvsp[-2].String),strarrtype,size,SP);
                                                    SP+=size;
                                                    Gsymbol* g=lookUp((yyvsp[-2].String));
                                                    g->dim=makeLnode("",dim,(yyvsp[-1].listPtr));
                                                }
#line 1491 "y.tab.c"
    break;

  case 11: /* ArrList: '[' NUM ']' ArrList  */
#line 161 "main.y"
                                                {(yyval.listPtr)=makeLnode("",(yyvsp[-2].Int),(yyvsp[0].listPtr));}
#line 1497 "y.tab.c"
    break;

  case 12: /* ArrList: '[' NUM ']'  */
#line 162 "main.y"
                                                {(yyval.listPtr)=makeLnode("",(yyvsp[-1].Int),NULL);}
#line 1503 "y.tab.c"
    break;

  case 13: /* VarList: VarList ',' ID  */
#line 164 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),valtype,(yyvsp[-2].listPtr));}
#line 1509 "y.tab.c"
    break;

  case 14: /* VarList: VarList ',' '*' ID  */
#line 165 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),ptrtype,(yyvsp[-3].listPtr));}
#line 1515 "y.tab.c"
    break;

  case 15: /* VarList: ID  */
#line 166 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),valtype,NULL);}
#line 1521 "y.tab.c"
    break;

  case 16: /* VarList: '*' ID  */
#line 167 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),ptrtype,NULL);}
#line 1527 "y.tab.c"
    break;

  case 17: /* Program: begin Slist end  */
#line 172 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1533 "y.tab.c"
    break;

  case 18: /* Program: begin end  */
#line 173 "main.y"
                                    {(yyval.nodePtr)=NULL;}
#line 1539 "y.tab.c"
    break;

  case 19: /* Slist: Slist Stmt  */
#line 175 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,0,NULL,tCONNECT,(yyvsp[-1].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1545 "y.tab.c"
    break;

  case 20: /* Slist: Stmt  */
#line 176 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 1551 "y.tab.c"
    break;

  case 21: /* Stmt: InputStmt ';'  */
#line 178 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1557 "y.tab.c"
    break;

  case 22: /* Stmt: OutputStmt ';'  */
#line 179 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1563 "y.tab.c"
    break;

  case 23: /* Stmt: AssgStmt ';'  */
#line 180 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1569 "y.tab.c"
    break;

  case 24: /* Stmt: Ifstmt  */
#line 181 "main.y"
                                {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 1575 "y.tab.c"
    break;

  case 25: /* Stmt: LoopStmt  */
#line 182 "main.y"
                                {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 1581 "y.tab.c"
    break;

  case 26: /* Stmt: BREAK ';'  */
#line 183 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,0,NULL,tBREAK,NULL,NULL,NULL);}
#line 1587 "y.tab.c"
    break;

  case 27: /* Stmt: CONTINUE ';'  */
#line 184 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,0,NULL,tCONTINUE,NULL,NULL,NULL);}
#line 1593 "y.tab.c"
    break;

  case 28: /* LoopStmt: WHILE '(' Expr ')' '{' Slist '}'  */
#line 186 "main.y"
                                                    {if(isBoolean((yyvsp[-4].nodePtr),(yyvsp[-4].nodePtr))) (yyval.nodePtr)=makeNode(0,0,NULL,tWHILE,(yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr),(yyvsp[-4].nodePtr));}
#line 1599 "y.tab.c"
    break;

  case 29: /* LoopStmt: DO '{' Slist '}' WHILE '(' Expr ')'  */
#line 187 "main.y"
                                                                {if(isBoolean((yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr))) (yyval.nodePtr)=makeNode(0,0,NULL,tDOWHILE,(yyvsp[-5].nodePtr),(yyvsp[-5].nodePtr),(yyvsp[-1].nodePtr));}
#line 1605 "y.tab.c"
    break;

  case 30: /* LoopStmt: REPEAT '{' Slist '}' UNTIL '(' Expr ')'  */
#line 188 "main.y"
                                                                    {if(isBoolean((yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr))) (yyval.nodePtr)=makeNode(0,0,NULL,tREPEATUNTIL,(yyvsp[-5].nodePtr),(yyvsp[-5].nodePtr),(yyvsp[-1].nodePtr));}
#line 1611 "y.tab.c"
    break;

  case 31: /* Ifstmt: IF '(' Expr ')' '{' Slist '}' Else '{' Slist '}'  */
#line 190 "main.y"
                                                             {if(isBoolean((yyvsp[-8].nodePtr),(yyvsp[-8].nodePtr))) (yyval.nodePtr)=makeNode(0,0,NULL,tIF,(yyvsp[-5].nodePtr),(yyvsp[-1].nodePtr),(yyvsp[-8].nodePtr));}
#line 1617 "y.tab.c"
    break;

  case 32: /* Ifstmt: IF '(' Expr ')' '{' Slist '}'  */
#line 191 "main.y"
                                                    {if(isBoolean((yyvsp[-4].nodePtr),(yyvsp[-4].nodePtr))) (yyval.nodePtr)=makeNode(0,0,NULL,tIF,(yyvsp[-1].nodePtr),NULL,(yyvsp[-4].nodePtr));}
#line 1623 "y.tab.c"
    break;

  case 33: /* InputStmt: READ '(' ID ')'  */
#line 193 "main.y"
                                    {
                                    Gsymbol* ptr=lookUp((yyvsp[-1].String));
                                    node* temp=NULL;
                                    if(ptr) temp=makeNode(0,0,ptr,tVAR,NULL,NULL,NULL);
                                    else yyerror("Undeclared Variable");
                                    (yyval.nodePtr)=makeNode(0,0,NULL,tREAD,temp,temp,NULL);
                                    }
#line 1635 "y.tab.c"
    break;

  case 34: /* OutputStmt: WRITE '(' Expr ')'  */
#line 201 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,0,NULL,tWRITE,(yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr),NULL);}
#line 1641 "y.tab.c"
    break;

  case 35: /* AssgStmt: ID '=' Expr  */
#line 203 "main.y"
                                    {
                                    Gsymbol* ptr=lookUp((yyvsp[-2].String));
                                    node* temp=NULL;
                                    if(ptr) temp=makeNode(0,ptr->type,ptr,tVAR,NULL,NULL,NULL);
                                    else yyerror("Undeclared Variable");
                                    (yyval.nodePtr)=makeNode(0,0,NULL,tASSIGN,temp,(yyvsp[0].nodePtr),NULL);
                                    }
#line 1653 "y.tab.c"
    break;

  case 36: /* AssgStmt: '*' ID '=' Expr  */
#line 210 "main.y"
                                    {
                                    Gsymbol* ptr=lookUp((yyvsp[-2].String));
                                    node* var=NULL;
                                    if(ptr) var=makeNode(0,ptr->type,ptr,tVAR,NULL,NULL,NULL); 
                                    else yyerror("Undeclared Variable");
                                    if(ptr->type==intptrtype)var=makeNode(0,inttype,NULL,tVALUEAT,var,var,var);
                                    else if(ptr->type==strptrtype) var=makeNode(0,strtype,NULL,tVALUEAT,var,var,var);
                                    else yyerror("type mismatch");
                                    (yyval.nodePtr)=makeNode(0,0,NULL,tASSIGN,var,(yyvsp[0].nodePtr),NULL);
                                    }
#line 1668 "y.tab.c"
    break;

  case 37: /* AssgStmt: ID Array '=' Expr  */
#line 220 "main.y"
                                  {
                                        Gsymbol* ptr=lookUp((yyvsp[-3].String));
                                        if(!ptr) yyerror("variable undeclared");
                                        node* var=NULL;
                                        if(ptr->type==intarrtype) var=makeNode(0,inttype,ptr,tARRVAL,(yyvsp[-2].nodePtr),(yyvsp[-2].nodePtr),(yyvsp[-2].nodePtr));
                                        else if(ptr->type==strarrtype) var=makeNode(0,strtype,ptr,tARRVAL,(yyvsp[-2].nodePtr),(yyvsp[-2].nodePtr),(yyvsp[-2].nodePtr));
                                        if(var->type!=(yyvsp[0].nodePtr)->type) yyerror("type mismatch");
                                        (yyval.nodePtr)=makeNode(0,inttype,NULL,tASSIGN,var,(yyvsp[0].nodePtr),(yyvsp[0].nodePtr));
                                    }
#line 1682 "y.tab.c"
    break;

  case 38: /* Array: '[' Expr ']' Array  */
#line 230 "main.y"
                                       {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[-2].nodePtr))){
                                            (yyvsp[-2].nodePtr)->left=(yyvsp[0].nodePtr);
                                            (yyval.nodePtr)=(yyvsp[-2].nodePtr);
                                        }
                                      }
#line 1692 "y.tab.c"
    break;

  case 39: /* Array: '[' Expr ']'  */
#line 235 "main.y"
                                       {if(isArithmetic((yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr))) (yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1698 "y.tab.c"
    break;

  case 40: /* Expr: Expr '+' Expr  */
#line 237 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,inttype,NULL,tADD,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1704 "y.tab.c"
    break;

  case 41: /* Expr: Expr '-' Expr  */
#line 238 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,inttype,NULL,tSUB,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1710 "y.tab.c"
    break;

  case 42: /* Expr: Expr '*' Expr  */
#line 239 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,inttype,NULL,tMUL,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1716 "y.tab.c"
    break;

  case 43: /* Expr: Expr '/' Expr  */
#line 240 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,inttype,NULL,tDIV,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1722 "y.tab.c"
    break;

  case 44: /* Expr: Expr '%' Expr  */
#line 241 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,inttype,NULL,tMOD,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1728 "y.tab.c"
    break;

  case 45: /* Expr: Expr '>' Expr  */
#line 242 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,booltype,NULL,tGT,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1734 "y.tab.c"
    break;

  case 46: /* Expr: Expr '<' Expr  */
#line 243 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,booltype,NULL,tLT,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1740 "y.tab.c"
    break;

  case 47: /* Expr: Expr GE Expr  */
#line 244 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,booltype,NULL,tGE,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1746 "y.tab.c"
    break;

  case 48: /* Expr: Expr LE Expr  */
#line 245 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,booltype,NULL,tLE,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1752 "y.tab.c"
    break;

  case 49: /* Expr: Expr EQ Expr  */
#line 246 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,booltype,NULL,tEQ,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1758 "y.tab.c"
    break;

  case 50: /* Expr: Expr NEQ Expr  */
#line 247 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,booltype,NULL,tNEQ,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1764 "y.tab.c"
    break;

  case 51: /* Expr: Expr AND Expr  */
#line 248 "main.y"
                                    {if(isBoolean((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,booltype,NULL,tAND,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1770 "y.tab.c"
    break;

  case 52: /* Expr: Expr OR Expr  */
#line 249 "main.y"
                                    {if(isBoolean((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,booltype,NULL,tOR,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1776 "y.tab.c"
    break;

  case 53: /* Expr: '(' Expr ')'  */
#line 250 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1782 "y.tab.c"
    break;

  case 54: /* Expr: NUM  */
#line 251 "main.y"
                                    {(yyval.nodePtr)=makeNode((yyvsp[0].Int),inttype,NULL,tCONST,NULL,NULL,NULL);}
#line 1788 "y.tab.c"
    break;

  case 55: /* Expr: LITERAL  */
#line 252 "main.y"
                                    {
                                     printf("STARTED parsing literal");
                                     (yyval.nodePtr)=makeNode(0,strtype,NULL,tLITERAL,NULL,NULL,NULL);
                                     (yyval.nodePtr)->literal=(yyvsp[0].String);
                                     printf("FINISHED parsing literal");
                                    }
#line 1799 "y.tab.c"
    break;

  case 56: /* Expr: ID  */
#line 258 "main.y"
                                    {
                                    printf("From expr %s\n",(yyvsp[0].String));
                                    Gsymbol* ptr=lookUp((yyvsp[0].String));
                                    if(ptr)(yyval.nodePtr)=makeNode(0,ptr->type,ptr,tVAR,NULL,NULL,NULL);
                                    else yyerror("Undeclared Variable");
                                    }
#line 1810 "y.tab.c"
    break;

  case 57: /* Expr: '&' ID  */
#line 264 "main.y"
                                    {
                                    Gsymbol* ptr=lookUp((yyvsp[0].String));
                                    node* var=NULL;
                                    if(ptr) var=makeNode(0,ptr->type,ptr,tVAR,NULL,NULL,NULL); 
                                    else yyerror("Undeclared Variable"); 
                                    (yyval.nodePtr)=makeNode(0,inttype,NULL,tADDRESSOF,var,var,var) ; // i don't see the point of address type, now we can do &var+1 and all
                                    }
#line 1822 "y.tab.c"
    break;

  case 58: /* Expr: '*' ID  */
#line 271 "main.y"
                                    {
                                    Gsymbol* ptr=lookUp((yyvsp[0].String));
                                    node* var=NULL;
                                    if(ptr) var=makeNode(0,ptr->type,ptr,tVAR,NULL,NULL,NULL); 
                                    else yyerror("Undeclared Variable");
                                    if(ptr->type==intptrtype)(yyval.nodePtr)=makeNode(0,inttype,NULL,tVALUEAT,var,var,var);
                                    else if(ptr->type==strptrtype) (yyval.nodePtr)=makeNode(0,strtype,NULL,tVALUEAT,var,var,var);
                                    }
#line 1835 "y.tab.c"
    break;

  case 59: /* Expr: ID Array  */
#line 279 "main.y"
                                  {
                                        Gsymbol* ptr=lookUp((yyvsp[-1].String));
                                        if(!ptr) yyerror("variable undeclared");
                                        if(ptr->type==intarrtype) (yyval.nodePtr)=makeNode(0,inttype,ptr,tARRVAL,(yyvsp[0].nodePtr),(yyvsp[0].nodePtr),(yyvsp[0].nodePtr));
                                        else if(ptr->type==strarrtype) (yyval.nodePtr)=makeNode(0,strtype,ptr,tARRVAL,(yyvsp[0].nodePtr),(yyvsp[0].nodePtr),(yyvsp[0].nodePtr));
                                    }
#line 1846 "y.tab.c"
    break;


#line 1850 "y.tab.c"

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

#line 287 "main.y"


int main(){
    FILE *fp=fopen("bubblesort.ac","r");
    yyin=fp;
    SP=4096;
    yyparse();
    Gsymbol* ptr=Ghead;
    if(!ptr) printf("What\n");
    for(;ptr;ptr=ptr->next)printf("%s ",ptr->name);
    printf("parsing complete\n");
    outFile=fopen("a.xsm","w");
    space=0;
    /* printTree(root); */
    currReg=0;

    genHeader();
    genVarSpaceCode(); // set stack pointer to after declarations
    int reg=genCode(root);
    printf("codeGen completed\n");
    fprintf(outFile,"JMP EXITCODE!\n");
    genErrorHandler();
    genExit();
}

void yyerror(char* s){
    printf("%s\n",s);
    exit(0);
}

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
    #include "parser.h"

    extern FILE *yyin;
    void yyerror(char* s);
    extern int yylex();

    node* root;          // AST root;
    Gsymbol* Ghead=NULL; // global symbol tabel head
    //makeNode(val,type,varname,nodeType,left,right,center);

    FILE* outFile;
    int currReg;

    int space=0;
    int varBase=4096;
    int SP=4096;
    int label=0;
    int WHILELABELS[]={-1,-1};

#line 97 "y.tab.c"

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
    INT = 279,                     /* INT  */
    STR = 280,                     /* STR  */
    DECL = 281,                    /* DECL  */
    ENDDECL = 282,                 /* ENDDECL  */
    NUM = 283,                     /* NUM  */
    ID = 284                       /* ID  */
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
#define INT 279
#define STR 280
#define DECL 281
#define ENDDECL 282
#define NUM 283
#define ID 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 28 "main.y"

    int Int;
    char Char;
    struct node* nodePtr;
    char* String;
    struct Lnode* listPtr;

#line 216 "y.tab.c"

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
  YYSYMBOL_INT = 24,                       /* INT  */
  YYSYMBOL_STR = 25,                       /* STR  */
  YYSYMBOL_DECL = 26,                      /* DECL  */
  YYSYMBOL_ENDDECL = 27,                   /* ENDDECL  */
  YYSYMBOL_NUM = 28,                       /* NUM  */
  YYSYMBOL_ID = 29,                        /* ID  */
  YYSYMBOL_30_ = 30,                       /* '<'  */
  YYSYMBOL_31_ = 31,                       /* '>'  */
  YYSYMBOL_32_ = 32,                       /* '+'  */
  YYSYMBOL_33_ = 33,                       /* '-'  */
  YYSYMBOL_34_ = 34,                       /* '*'  */
  YYSYMBOL_35_ = 35,                       /* '/'  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* ','  */
  YYSYMBOL_38_ = 38,                       /* '('  */
  YYSYMBOL_39_ = 39,                       /* ')'  */
  YYSYMBOL_40_ = 40,                       /* '='  */
  YYSYMBOL_41_ = 41,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_sourceCode = 43,                /* sourceCode  */
  YYSYMBOL_Delcarations = 44,              /* Delcarations  */
  YYSYMBOL_DecList = 45,                   /* DecList  */
  YYSYMBOL_Decl = 46,                      /* Decl  */
  YYSYMBOL_VarList = 47,                   /* VarList  */
  YYSYMBOL_Program = 48,                   /* Program  */
  YYSYMBOL_Slist = 49,                     /* Slist  */
  YYSYMBOL_Stmt = 50,                      /* Stmt  */
  YYSYMBOL_LoopStmt = 51,                  /* LoopStmt  */
  YYSYMBOL_Ifstmt = 52,                    /* Ifstmt  */
  YYSYMBOL_InputStmt = 53,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 54,                /* OutputStmt  */
  YYSYMBOL_AssgStmt = 55,                  /* AssgStmt  */
  YYSYMBOL_Expr = 56                       /* Expr  */
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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   388

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  121

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


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
       2,     2,     2,     2,     2,     2,     2,     2,    41,     2,
      38,    39,    34,    32,    37,    33,     2,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
      30,    40,    31,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    96,    96,    99,   100,   102,   103,   105,   117,   129,
     130,   131,   132,   135,   136,   138,   139,   141,   142,   143,
     144,   145,   146,   147,   149,   150,   151,   153,   154,   156,
     164,   166,   175,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   204,   209
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
  "UNTIL", "INT", "STR", "DECL", "ENDDECL", "NUM", "ID", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "';'", "','", "'('", "')'", "'='", "'&'",
  "$accept", "sourceCode", "Delcarations", "DecList", "Decl", "VarList",
  "Program", "Slist", "Stmt", "LoopStmt", "Ifstmt", "InputStmt",
  "OutputStmt", "AssgStmt", "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-38)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -8,    44,    31,    30,   -19,   -19,   -38,    87,   -38,   -38,
       3,   -38,   -38,    10,   -35,    -1,   -38,   -38,   -38,    32,
      40,    41,    42,   289,    67,    77,   289,    81,    93,   207,
     -38,    99,   100,   109,   110,   118,   -38,   -38,   -17,   -38,
      94,   169,   169,   169,   308,   -38,   -38,   245,   169,   104,
     -38,   -38,   -38,   -38,   -38,   -38,   -38,   -38,   105,   116,
     -38,   -38,   127,   169,   128,    65,    98,   108,   126,   129,
     324,   169,   -38,   -38,   -38,   141,   -38,   169,   169,   169,
     169,   169,   169,   169,   169,   169,   169,   169,   169,   -38,
     152,   147,   169,   169,   324,   -38,    49,    92,    28,    -5,
     342,   336,   353,    57,    19,   -21,   133,   -38,   289,   289,
     151,   184,   227,   264,   147,   -38,   289,   -38,   -38,   283,
     -38
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     4,     0,     6,     1,
       0,     2,    11,     0,     0,     0,     3,     5,    14,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      16,     0,     0,     0,     0,     0,    12,     7,     0,     8,
       0,     0,     0,     0,     0,    22,    23,     0,     0,     0,
      13,    15,    21,    20,    17,    18,    19,     9,     0,     0,
      46,    47,     0,     0,     0,     0,     0,     0,     0,     0,
      31,     0,    10,    29,    49,     0,    48,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
       0,     0,     0,     0,    32,    45,    39,    40,    41,    42,
      43,    44,    38,    37,    33,    34,    35,    36,     0,     0,
       0,     0,     0,     0,    25,    26,     0,    28,    24,     0,
      27
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -38,   -38,   -38,   -38,   162,   165,   -38,   -23,   -25,   -38,
     -38,   -38,   -38,   -38,   -37
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     7,     8,    14,    11,    29,    30,    31,
      32,    33,    34,    35,    65
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      44,    37,    38,    47,    51,    66,    67,    18,    19,    20,
      12,    70,    57,    87,    88,    13,    21,    58,     1,    51,
      22,    23,    51,    24,    25,    26,    75,    85,    86,    87,
      88,     9,    27,    10,    94,    39,    38,    28,    80,    36,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,    86,    87,    88,   110,   111,    78,    79,    80,
      85,    86,    87,    88,    77,    78,    79,    80,     4,     5,
      40,     6,    77,    78,    79,    80,    81,    82,    41,    42,
      43,    85,    86,    87,    88,   112,   113,    51,    51,    85,
      86,    87,    88,   119,    51,    83,    84,    85,    86,    87,
      88,    79,    80,    45,    89,    77,    78,    79,    80,    81,
      82,     4,     5,    46,    16,    77,    78,    79,    80,    81,
      82,    48,    49,    59,    85,    86,    87,    88,    83,    84,
      85,    86,    87,    88,    72,    52,    53,    90,    83,    84,
      85,    86,    87,    88,    71,    54,    55,    91,    77,    78,
      79,    80,    81,    82,    56,    73,    74,    76,    77,    78,
      79,    80,    81,    82,    92,   109,   108,    93,    88,    17,
      15,    83,    84,    85,    86,    87,    88,     0,     0,     0,
      95,    83,    84,    85,    86,    87,    88,     0,     0,     0,
     114,    77,    78,    79,    80,    81,    82,    60,    61,     0,
       0,     0,     0,    62,     0,     0,     0,    63,     0,     0,
      64,    50,    19,    20,    83,    84,    85,    86,    87,    88,
      21,     0,     0,   115,    22,    23,     0,    24,    25,    26,
       0,     0,    19,    20,     0,     0,    27,     0,     0,     0,
      21,    28,   116,   117,    22,    23,     0,    24,    25,    26,
      19,    20,     0,     0,     0,     0,    27,     0,    21,     0,
       0,    28,    22,    23,     0,    24,    25,    26,    69,    19,
      20,     0,     0,     0,    27,     0,     0,    21,     0,    28,
       0,    22,    23,   118,    24,    25,    26,     0,    19,    20,
       0,     0,     0,    27,    19,    20,    21,     0,    28,   120,
      22,    23,    21,    24,    25,    26,    22,    23,     0,    24,
      25,    26,    27,    19,    20,     0,     0,    28,    27,     0,
       0,    21,     0,    28,     0,    68,    23,     0,    24,    25,
      26,    77,    78,    79,    80,    81,    82,    27,     0,     0,
       0,     0,    28,    77,    78,    79,    80,    81,     0,    77,
      78,    79,    80,     0,    83,    84,    85,    86,    87,    88,
      77,    78,    79,    80,     0,     0,    83,    84,    85,    86,
      87,    88,    83,    84,    85,    86,    87,    88,     0,     0,
       0,     0,     0,     0,    84,    85,    86,    87,    88
};

static const yytype_int8 yycheck[] =
{
      23,    36,    37,    26,    29,    42,    43,     4,     5,     6,
      29,    48,    29,    34,    35,    34,    13,    34,    26,    44,
      17,    18,    47,    20,    21,    22,    63,    32,    33,    34,
      35,     0,    29,     3,    71,    36,    37,    34,    10,    29,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    33,    34,    35,    92,    93,     8,     9,    10,
      32,    33,    34,    35,     7,     8,     9,    10,    24,    25,
      38,    27,     7,     8,     9,    10,    11,    12,    38,    38,
      38,    32,    33,    34,    35,   108,   109,   112,   113,    32,
      33,    34,    35,   116,   119,    30,    31,    32,    33,    34,
      35,     9,    10,    36,    39,     7,     8,     9,    10,    11,
      12,    24,    25,    36,    27,     7,     8,     9,    10,    11,
      12,    40,    29,    29,    32,    33,    34,    35,    30,    31,
      32,    33,    34,    35,    29,    36,    36,    39,    30,    31,
      32,    33,    34,    35,    40,    36,    36,    39,     7,     8,
       9,    10,    11,    12,    36,    39,    29,    29,     7,     8,
       9,    10,    11,    12,    38,    18,    14,    38,    35,     7,
       5,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      39,    30,    31,    32,    33,    34,    35,    -1,    -1,    -1,
      39,     7,     8,     9,    10,    11,    12,    28,    29,    -1,
      -1,    -1,    -1,    34,    -1,    -1,    -1,    38,    -1,    -1,
      41,     4,     5,     6,    30,    31,    32,    33,    34,    35,
      13,    -1,    -1,    39,    17,    18,    -1,    20,    21,    22,
      -1,    -1,     5,     6,    -1,    -1,    29,    -1,    -1,    -1,
      13,    34,    15,    16,    17,    18,    -1,    20,    21,    22,
       5,     6,    -1,    -1,    -1,    -1,    29,    -1,    13,    -1,
      -1,    34,    17,    18,    -1,    20,    21,    22,    23,     5,
       6,    -1,    -1,    -1,    29,    -1,    -1,    13,    -1,    34,
      -1,    17,    18,    19,    20,    21,    22,    -1,     5,     6,
      -1,    -1,    -1,    29,     5,     6,    13,    -1,    34,    16,
      17,    18,    13,    20,    21,    22,    17,    18,    -1,    20,
      21,    22,    29,     5,     6,    -1,    -1,    34,    29,    -1,
      -1,    13,    -1,    34,    -1,    17,    18,    -1,    20,    21,
      22,     7,     8,     9,    10,    11,    12,    29,    -1,    -1,
      -1,    -1,    34,     7,     8,     9,    10,    11,    -1,     7,
       8,     9,    10,    -1,    30,    31,    32,    33,    34,    35,
       7,     8,     9,    10,    -1,    -1,    30,    31,    32,    33,
      34,    35,    30,    31,    32,    33,    34,    35,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    26,    43,    44,    24,    25,    27,    45,    46,     0,
       3,    48,    29,    34,    47,    47,    27,    46,     4,     5,
       6,    13,    17,    18,    20,    21,    22,    29,    34,    49,
      50,    51,    52,    53,    54,    55,    29,    36,    37,    36,
      38,    38,    38,    38,    49,    36,    36,    49,    40,    29,
       4,    50,    36,    36,    36,    36,    36,    29,    34,    29,
      28,    29,    34,    38,    41,    56,    56,    56,    17,    23,
      56,    40,    29,    39,    29,    56,    29,     7,     8,     9,
      10,    11,    12,    30,    31,    32,    33,    34,    35,    39,
      39,    39,    38,    38,    56,    39,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    14,    18,
      56,    56,    49,    49,    39,    39,    15,    16,    19,    49,
      16
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    46,    46,    47,
      47,    47,    47,    48,    48,    49,    49,    50,    50,    50,
      50,    50,    50,    50,    51,    51,    51,    52,    52,    53,
      54,    55,    55,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     3,     2,     2,     1,     3,     3,     3,
       4,     1,     2,     3,     2,     2,     1,     2,     2,     2,
       2,     2,     2,     2,     7,     6,     6,     9,     7,     4,
       4,     3,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     2,     2
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
#line 96 "main.y"
                                                {root=makeNode(0,0,NULL,tCONNECT,(yyvsp[-1].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1372 "y.tab.c"
    break;

  case 3: /* Delcarations: DECL DecList ENDDECL  */
#line 99 "main.y"
                                                {(yyval.nodePtr)=NULL;}
#line 1378 "y.tab.c"
    break;

  case 4: /* Delcarations: DECL ENDDECL  */
#line 100 "main.y"
                                                {(yyval.nodePtr)=NULL;}
#line 1384 "y.tab.c"
    break;

  case 5: /* DecList: DecList Decl  */
#line 102 "main.y"
                                                {(yyval.nodePtr)=NULL;}
#line 1390 "y.tab.c"
    break;

  case 6: /* DecList: Decl  */
#line 103 "main.y"
                                                {(yyval.nodePtr)=NULL;}
#line 1396 "y.tab.c"
    break;

  case 7: /* Decl: INT VarList ';'  */
#line 105 "main.y"
                                                {
                                                  (yyval.nodePtr)=NULL;
                                                  Lnode* ptr1=(yyvsp[-1].listPtr);
                                                  for(;ptr1;ptr1=ptr1->next){
                                                        if(lookUp(ptr1->s)){
                                                        yyerror("Variable already Declared");
                                                        exit(0);
                                                        }
                                                        install(ptr1->s,ptr1->num?tdINTPTR:tdINT,1,SP++);
                                                  }
                                                  Gsymbol* ptr=Ghead;
                                                }
#line 1413 "y.tab.c"
    break;

  case 8: /* Decl: STR VarList ';'  */
#line 117 "main.y"
                                                {
                                                  (yyval.nodePtr)=NULL;
                                                  Lnode* ptr1=(yyvsp[-1].listPtr);
                                                  for(;ptr1;ptr1=ptr1->next){
                                                        if(lookUp(ptr1->s)){
                                                        yyerror("Variable already Declared");
                                                        exit(0);
                                                        }
                                                        install(ptr1->s,ptr1->num?tdSTRPTR:tdSTR,1,SP++);
                                                  }
                                                }
#line 1429 "y.tab.c"
    break;

  case 9: /* VarList: VarList ',' ID  */
#line 129 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),0,(yyvsp[-2].listPtr));}
#line 1435 "y.tab.c"
    break;

  case 10: /* VarList: VarList ',' '*' ID  */
#line 130 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),1,(yyvsp[-3].listPtr));}
#line 1441 "y.tab.c"
    break;

  case 11: /* VarList: ID  */
#line 131 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),0,NULL);}
#line 1447 "y.tab.c"
    break;

  case 12: /* VarList: '*' ID  */
#line 132 "main.y"
                                                {(yyval.listPtr)=makeLnode((yyvsp[0].String),1,NULL);}
#line 1453 "y.tab.c"
    break;

  case 13: /* Program: begin Slist end  */
#line 135 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1459 "y.tab.c"
    break;

  case 14: /* Program: begin end  */
#line 136 "main.y"
                                    {(yyval.nodePtr)=NULL;}
#line 1465 "y.tab.c"
    break;

  case 15: /* Slist: Slist Stmt  */
#line 138 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,0,NULL,tCONNECT,(yyvsp[-1].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1471 "y.tab.c"
    break;

  case 16: /* Slist: Stmt  */
#line 139 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[0].nodePtr);}
#line 1477 "y.tab.c"
    break;

  case 17: /* Stmt: InputStmt ';'  */
#line 141 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1483 "y.tab.c"
    break;

  case 18: /* Stmt: OutputStmt ';'  */
#line 142 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1489 "y.tab.c"
    break;

  case 19: /* Stmt: AssgStmt ';'  */
#line 143 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1495 "y.tab.c"
    break;

  case 20: /* Stmt: Ifstmt ';'  */
#line 144 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1501 "y.tab.c"
    break;

  case 21: /* Stmt: LoopStmt ';'  */
#line 145 "main.y"
                                   {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1507 "y.tab.c"
    break;

  case 22: /* Stmt: BREAK ';'  */
#line 146 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,0,NULL,tBREAK,NULL,NULL,NULL);}
#line 1513 "y.tab.c"
    break;

  case 23: /* Stmt: CONTINUE ';'  */
#line 147 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,0,NULL,tCONTINUE,NULL,NULL,NULL);}
#line 1519 "y.tab.c"
    break;

  case 24: /* LoopStmt: WHILE '(' Expr ')' DO Slist ENDWHILE  */
#line 149 "main.y"
                                                        {if(isBoolean((yyvsp[-4].nodePtr),(yyvsp[-4].nodePtr))) (yyval.nodePtr)=makeNode(0,0,NULL,tWHILE,(yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr),(yyvsp[-4].nodePtr));}
#line 1525 "y.tab.c"
    break;

  case 25: /* LoopStmt: DO Slist WHILE '(' Expr ')'  */
#line 150 "main.y"
                                                        {if(isBoolean((yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr))) (yyval.nodePtr)=makeNode(0,0,NULL,tDOWHILE,(yyvsp[-4].nodePtr),(yyvsp[-4].nodePtr),(yyvsp[-1].nodePtr));}
#line 1531 "y.tab.c"
    break;

  case 26: /* LoopStmt: REPEAT Slist UNTIL '(' Expr ')'  */
#line 151 "main.y"
                                                            {if(isBoolean((yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr))) (yyval.nodePtr)=makeNode(0,0,NULL,tREPEATUNTIL,(yyvsp[-4].nodePtr),(yyvsp[-4].nodePtr),(yyvsp[-1].nodePtr));}
#line 1537 "y.tab.c"
    break;

  case 27: /* Ifstmt: IF '(' Expr ')' then Slist Else Slist ENDIF  */
#line 153 "main.y"
                                                        {if(isBoolean((yyvsp[-6].nodePtr),(yyvsp[-6].nodePtr))) (yyval.nodePtr)=makeNode(0,0,NULL,tIF,(yyvsp[-3].nodePtr),(yyvsp[-1].nodePtr),(yyvsp[-6].nodePtr));}
#line 1543 "y.tab.c"
    break;

  case 28: /* Ifstmt: IF '(' Expr ')' then Slist ENDIF  */
#line 154 "main.y"
                                                        {if(isBoolean((yyvsp[-4].nodePtr),(yyvsp[-4].nodePtr))) (yyval.nodePtr)=makeNode(0,0,NULL,tIF,(yyvsp[-1].nodePtr),NULL,(yyvsp[-4].nodePtr));}
#line 1549 "y.tab.c"
    break;

  case 29: /* InputStmt: READ '(' ID ')'  */
#line 156 "main.y"
                                    {
                                    Gsymbol* ptr=lookUp((yyvsp[-1].String));
                                    node* temp=NULL;
                                    if(ptr) temp=makeNode(0,0,ptr,tVAR,NULL,NULL,NULL);
                                    else yyerror("Undeclared Variable");
                                    (yyval.nodePtr)=makeNode(0,0,NULL,tREAD,temp,temp,NULL);
                                    }
#line 1561 "y.tab.c"
    break;

  case 30: /* OutputStmt: WRITE '(' Expr ')'  */
#line 164 "main.y"
                                    {(yyval.nodePtr)=makeNode(0,0,NULL,tWRITE,(yyvsp[-1].nodePtr),(yyvsp[-1].nodePtr),NULL);}
#line 1567 "y.tab.c"
    break;

  case 31: /* AssgStmt: ID '=' Expr  */
#line 166 "main.y"
                                    {
                                    Gsymbol* ptr=lookUp((yyvsp[-2].String));
                                    node* temp=NULL;
                                    if(ptr) temp=makeNode(0,0,ptr,tVAR,NULL,NULL,NULL);
                                    else yyerror("Undeclared Variable");
                                    if((ptr->type==tdINT || ptr->type==tdSTR) && (yyvsp[0].nodePtr)->type==Addresstype) yyerror("Assignment of Pointer type to variable error");
                                    if((ptr->type==tdINTPTR || ptr->type==tdSTRPTR) && (yyvsp[0].nodePtr)->type!=Addresstype) yyerror("Assignment expected address type");
                                    (yyval.nodePtr)=makeNode(0,0,NULL,tASSIGN,temp,(yyvsp[0].nodePtr),NULL);
                                    }
#line 1581 "y.tab.c"
    break;

  case 32: /* AssgStmt: '*' ID '=' Expr  */
#line 175 "main.y"
                                       {
                                    Gsymbol* ptr=lookUp((yyvsp[-2].String));
                                    node* temp=NULL;
                                    printf("%s\n",ptr->name);
                                    if(ptr) temp=makeNode(0,0,ptr,tPTR,NULL,NULL,NULL);
                                    else yyerror("Undeclared Variable");
                                    (yyval.nodePtr)=makeNode(0,0,NULL,tASSIGN,temp,(yyvsp[0].nodePtr),NULL);
                                    }
#line 1594 "y.tab.c"
    break;

  case 33: /* Expr: Expr '+' Expr  */
#line 184 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,0,NULL,tADD,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1600 "y.tab.c"
    break;

  case 34: /* Expr: Expr '-' Expr  */
#line 185 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,0,NULL,tSUB,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1606 "y.tab.c"
    break;

  case 35: /* Expr: Expr '*' Expr  */
#line 186 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,0,NULL,tMUL,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1612 "y.tab.c"
    break;

  case 36: /* Expr: Expr '/' Expr  */
#line 187 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,0,NULL,tDIV,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1618 "y.tab.c"
    break;

  case 37: /* Expr: Expr '>' Expr  */
#line 188 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,1,NULL,tGT,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1624 "y.tab.c"
    break;

  case 38: /* Expr: Expr '<' Expr  */
#line 189 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,1,NULL,tLT,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1630 "y.tab.c"
    break;

  case 39: /* Expr: Expr GE Expr  */
#line 190 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,1,NULL,tGE,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1636 "y.tab.c"
    break;

  case 40: /* Expr: Expr LE Expr  */
#line 191 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,1,NULL,tLE,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1642 "y.tab.c"
    break;

  case 41: /* Expr: Expr EQ Expr  */
#line 192 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,1,NULL,tEQ,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1648 "y.tab.c"
    break;

  case 42: /* Expr: Expr NEQ Expr  */
#line 193 "main.y"
                                    {if(isArithmetic((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,1,NULL,tNEQ,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1654 "y.tab.c"
    break;

  case 43: /* Expr: Expr AND Expr  */
#line 194 "main.y"
                                    {if(isBoolean((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,1,NULL,tAND,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1660 "y.tab.c"
    break;

  case 44: /* Expr: Expr OR Expr  */
#line 195 "main.y"
                                    {if(isBoolean((yyvsp[-2].nodePtr),(yyvsp[0].nodePtr))) (yyval.nodePtr)=makeNode(0,1,NULL,tOR,(yyvsp[-2].nodePtr),(yyvsp[0].nodePtr),NULL);}
#line 1666 "y.tab.c"
    break;

  case 45: /* Expr: '(' Expr ')'  */
#line 196 "main.y"
                                    {(yyval.nodePtr)=(yyvsp[-1].nodePtr);}
#line 1672 "y.tab.c"
    break;

  case 46: /* Expr: NUM  */
#line 197 "main.y"
                                    {(yyval.nodePtr)=makeNode((yyvsp[0].Int),0,NULL,tCONST,NULL,NULL,NULL);}
#line 1678 "y.tab.c"
    break;

  case 47: /* Expr: ID  */
#line 198 "main.y"
                                    {
                                    printf("From expr %s\n",(yyvsp[0].String));
                                    Gsymbol* ptr=lookUp((yyvsp[0].String));
                                    if(ptr)(yyval.nodePtr)=makeNode(0,0,ptr,tVAR,NULL,NULL,NULL);
                                    else yyerror("Undeclared Variable");
                                    }
#line 1689 "y.tab.c"
    break;

  case 48: /* Expr: '&' ID  */
#line 204 "main.y"
                                    {
                                    Gsymbol* ptr=lookUp((yyvsp[0].String));
                                    if(ptr) (yyval.nodePtr)=makeNode(0,Addresstype,ptr,tVAR,NULL,NULL,NULL); 
                                    else yyerror("Undeclared Variable");  
                                    }
#line 1699 "y.tab.c"
    break;

  case 49: /* Expr: '*' ID  */
#line 209 "main.y"
                                    {
                                    Gsymbol* ptr=lookUp((yyvsp[0].String));
                                    if(ptr) (yyval.nodePtr)=makeNode(0,0,ptr,tPTR,NULL,NULL,NULL); 
                                    else yyerror("Undeclared Variable");  
                                    }
#line 1709 "y.tab.c"
    break;


#line 1713 "y.tab.c"

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

#line 216 "main.y"


int main(){
    FILE *fp=fopen("input2.txt","r");
    yyin=fp;
    SP=4096;
    yyparse();
    printf("parsing complete\n");
    outFile=fopen("a.xsm","w");
    space=0;
    printTree(root);
    currReg=0;

    genHeader();
    genVarSpaceCode(); // being used for setting stack pointer to 4096;
    int reg=genCode(root);
    genExit();
}

void yyerror(char* s){
    printf("%s\n",s);
    exit(0);
}

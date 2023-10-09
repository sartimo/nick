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
#line 25 "oil.y"


#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ick_bool.h"

/* Define strdup if it isn't available */
#ifndef HAVE_STRDUP
char* strdup(const char* s)
{
  char* t=malloc(strlen(s)+1);
  if(t) strcpy(t,s);
  return t;
}
#endif

/*
#define YYDEBUG 1
int yydebug=1;
*/

/* Each semantic value represents either a constraint on a node that needs to
   be true for the optimization template to match, or part of the replacement
   for the optimization template. */
struct ickstype
{
  unsigned depth;     /* The number of child nodes this is from the root */
  unsigned long path; /* Bits from the end of this number represent the
			 sequence of lvals (=0) or rvals (=1) this is from the
			 root; depth bits from the end are relevant, and the
			 bit nearest the root is least significant */
  const char* condition; /* Points to a constant string; the condition to generate
			 on that node. Could also point to something the lexer
			 mallocs, but then the lexer has to keep track of being
			 able to free it again. If this is NULL, it means that
			 there isn't a condition other than maybe mustbemesh */
  const char* nodetypename; /* The name of the type of node this condition matches,
		         or NULL for a LEXERLEAF */
  bool usec;        /* Whether to append the value of c to the condition */
  bool mustbemesh;  /* Must this node be a mesh or mesh32? */
  bool cxneeded;    /* True means calculate c and x for the node and the
			 condition is on those; false means append 'condition'
			 to the node itself to form the condition and c and x
			 aren't needed */
  bool width32;     /* Generate a 32-bit node? */
  bool ublo;        /* Is this a UBLO (if set, generate conditions
			 to check width)? */
  unsigned long c;    /* The value to append to the condition */
  int replnum;        /* Number of this group for replacements */
  struct ickstype *n1;/* n1 and n2 are pointers to other conditions that */
  struct ickstype *n2;/* also have to be satisified */
};

#define YYSTYPE YYSTYPE

#define MAXOPTNAMELEN 64
char optname[MAXOPTNAMELEN]="undefined";
int optnumber = 0;

typedef struct ickstype *YYSTYPE;

void splitend(void);
void splitstart(void);

void treedepthup(YYSTYPE, bool);
void treefree(YYSTYPE);
void gennodepath(unsigned, unsigned long);
bool treeshapecond(YYSTYPE, bool);
YYSTYPE treenscheck(YYSTYPE, YYSTYPE, int);
void treecxcond(YYSTYPE);
void treerepcount(YYSTYPE, int*);
void treerepgen(YYSTYPE, YYSTYPE*, int*);

int countgetchar(void);
int countungetc(int, FILE*);
int cgccol;
int cgcrow;

/* #defines for chaining together template expressions; here, s is the type
   of expression (e.g. select, bitwise and, unary and) that's chaining the
   expressions together and n is the nonterminal that's the rval */
#define BINARYEXPR(s,m,l,r,w) do{ \
                          m=malloc(sizeof(struct ickstype)); \
                          m->n1=l; \
                          m->n2=r; \
                          m->usec=0; \
			  m->condition="->opcode==" s; \
                          m->nodetypename=s; \
                          m->mustbemesh=0; \
                          m->cxneeded=0; \
			  m->depth=0; \
			  m->path=0; \
                          m->replnum=0; \
                          m->width32=w; \
                          m->ublo=0; \
			  treedepthup(m->n1,0); \
			  treedepthup(m->n2,1); \
                          } while(0)

#define UNARYEXPR(s,m,r,w,u) do{ \
                          m=malloc(sizeof(struct ickstype)); \
                          m->n1=0; \
                          m->n2=r; \
                          m->usec=0; \
			  m->condition="->opcode==" s; \
                          m->nodetypename=s; \
                          m->mustbemesh=0; \
                          m->cxneeded=0; \
			  m->depth=0; \
			  m->path=0; \
                          m->replnum=0; \
                          m->width32=w; \
                          m->ublo=u; \
			  treedepthup(m->n2,1); \
                        } while(0)

/* Error handling and lexing */
int yylex(void);
int yyerror(char const *);

/* Split the output file */
#define SPLITMAX 20
int splitcount=SPLITMAX;
int filenumber=0;
bool inloop=0;

#line 201 "oil-oil.c"

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
    LEXERLEAF = 258                /* LEXERLEAF  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define LEXERLEAF 258

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_LEXERLEAF = 3,                  /* LEXERLEAF  */
  YYSYMBOL_4_ = 4,                         /* '-'  */
  YYSYMBOL_5_ = 5,                         /* '>'  */
  YYSYMBOL_6_ = 6,                         /* '<'  */
  YYSYMBOL_7_ = 7,                         /* '('  */
  YYSYMBOL_8_ = 8,                         /* ')'  */
  YYSYMBOL_9_ = 9,                         /* '"'  */
  YYSYMBOL_10_ = 10,                       /* '\''  */
  YYSYMBOL_11_ = 11,                       /* '$'  */
  YYSYMBOL_12_ = 12,                       /* '~'  */
  YYSYMBOL_13_1_ = 13,                     /* '1'  */
  YYSYMBOL_14_6_ = 14,                     /* '6'  */
  YYSYMBOL_15_3_ = 15,                     /* '3'  */
  YYSYMBOL_16_2_ = 16,                     /* '2'  */
  YYSYMBOL_17_ = 17,                       /* '&'  */
  YYSYMBOL_18_V_ = 18,                     /* 'V'  */
  YYSYMBOL_19_ = 19,                       /* '?'  */
  YYSYMBOL_20_ = 20,                       /* '^'  */
  YYSYMBOL_21_ = 21,                       /* '@'  */
  YYSYMBOL_22_4_ = 22,                     /* '4'  */
  YYSYMBOL_23_5_ = 23,                     /* '5'  */
  YYSYMBOL_24_ = 24,                       /* '|'  */
  YYSYMBOL_25_ = 25,                       /* '+'  */
  YYSYMBOL_26_ = 26,                       /* '*'  */
  YYSYMBOL_27_ = 27,                       /* '/'  */
  YYSYMBOL_28_ = 28,                       /* '%'  */
  YYSYMBOL_29_ = 29,                       /* '!'  */
  YYSYMBOL_30_ = 30,                       /* '='  */
  YYSYMBOL_YYACCEPT = 31,                  /* $accept  */
  YYSYMBOL_input = 32,                     /* input  */
  YYSYMBOL_optimization = 33,              /* optimization  */
  YYSYMBOL_template = 34,                  /* template  */
  YYSYMBOL_expr3 = 35,                     /* expr3  */
  YYSYMBOL_expr = 36,                      /* expr  */
  YYSYMBOL_expr2 = 37,                     /* expr2  */
  YYSYMBOL_replacement = 38                /* replacement  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   345

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  31
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  244

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   258


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
       2,     2,     2,    29,     9,     2,    11,    28,    17,    10,
       7,     8,    26,    25,     2,     4,     2,    27,     2,    13,
      16,    15,    22,    23,    14,     2,     2,     2,     2,     2,
       6,    30,     5,    19,    21,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    18,     2,     2,     2,
       2,     2,     2,     2,    20,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    24,     2,    12,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     3
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   186,   186,   186,   188,   249,   261,   263,   265,   266,
     267,   269,   270,   272,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,   283,   284,   285,   286,   287,   288,
     289,   290,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   310,   311,   312,   313,   314,   315,   316,   317,   318,
     319,   320,   321,   322,   323,   324,   325,   326,   327,   328,
     329,   330,   331,   332,   333,   334,   335,   336,   337,   338,
     339,   340,   341,   342,   343,   344,   345,   346,   347,   349
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
  "\"end of file\"", "error", "\"invalid token\"", "LEXERLEAF", "'-'",
  "'>'", "'<'", "'('", "')'", "'\"'", "'\\''", "'$'", "'~'", "'1'", "'6'",
  "'3'", "'2'", "'&'", "'V'", "'?'", "'^'", "'@'", "'4'", "'5'", "'|'",
  "'+'", "'*'", "'/'", "'%'", "'!'", "'='", "$accept", "input",
  "optimization", "template", "expr3", "expr", "expr2", "replacement", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-20)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -20,    10,   -20,   -20,     1,   210,   210,   210,   -20,     3,
     -20,    17,   -20,   -10,    -2,    29,    63,   120,   192,    89,
     -20,    83,    31,    34,    46,    67,    65,    68,    74,    72,
      77,    87,    81,   101,   102,   105,   106,   115,    25,   125,
     134,   141,   116,   118,   -20,   188,    70,   162,    15,   231,
      54,   240,    -1,   249,   258,   267,   276,    51,   109,   -20,
     -20,   -20,   107,   -20,    15,    15,    15,    15,    15,    15,
      15,    15,    15,    15,    15,   152,   132,    15,   153,   139,
     156,   157,   160,   163,    15,    15,   164,   167,   -20,   285,
     166,   168,   -20,   294,   173,   172,   -20,   -20,   175,   174,
     -20,   178,   180,   303,   -20,   190,   186,   -20,   202,   205,
     312,   -20,   204,   207,   -20,   211,   208,   -20,   212,   216,
     -20,   219,   220,   -20,   321,   330,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,    15,
      15,   -20,    15,    15,    15,    15,    15,    15,   -20,   -20,
      15,    15,   221,   226,   -20,    15,    15,   223,   229,   -20,
      15,    15,    15,    15,    15,    15,   234,   235,   -20,    15,
      15,    15,    15,   243,   238,   -20,    15,    15,    15,    15,
      15,    15,    15,    15,   246,   247,   -20,   252,   253,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
      15,    15,   -20,   -20,    15,    15,   -20,   -20,   -20,   -20,
     -20,   -20,    15,    15,   -20,   -20,   -20,   -20,    15,    15,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,    15,    15,
      15,    15,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,   -20
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     1,     6,     0,     0,     0,     0,     3,     0,
       7,     0,    12,     0,     0,     0,     0,     0,     0,     0,
      11,    88,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     8,
       9,    10,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,     0,    59,     0,     0,     0,    62,    13,     0,     0,
      14,     0,     0,     0,    35,     0,     0,    41,     0,     0,
       0,    38,     0,     0,    44,     0,     0,    50,     0,     0,
      53,     0,     0,    56,     0,     0,    89,     4,    65,    66,
      17,    18,    19,    20,    21,    22,    23,    24,    25,     0,
       0,    30,     0,     0,     0,     0,     0,     0,    86,    87,
       0,     0,     0,     0,    79,     0,     0,     0,     0,    82,
       0,     0,     0,     0,     0,     0,     0,     0,    73,     0,
       0,     0,     0,     0,     0,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    67,     0,     0,    70,
      27,    32,    26,    31,    28,    33,    29,    34,    48,    49,
       0,     0,    60,    61,     0,     0,    63,    64,    15,    16,
      36,    37,     0,     0,    42,    43,    39,    40,     0,     0,
      45,    46,    51,    52,    54,    55,    57,    58,     0,     0,
       0,     0,    80,    81,    83,    84,    74,    75,    77,    78,
      68,    69,    71,    72
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -20,   -20,   -20,   -20,     0,   -19,    53,   -20
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     8,     9,    20,    21,    22,   127
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      44,    10,    12,    27,    11,    28,     5,    25,     6,     7,
       2,    29,   108,    30,   109,     3,     4,     5,    12,     6,
       7,    26,     5,   110,     6,     7,    88,    92,    96,    97,
     100,   104,   107,   111,   114,   117,   120,   123,    75,    59,
      76,    77,    31,    60,    32,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,    61,    12,   141,    23,
      24,     5,   126,     6,     7,   148,   149,   101,    63,   102,
     154,   103,    62,    12,   159,    89,    33,     5,    34,     6,
       7,   124,    64,    90,   168,    91,    66,    45,    46,    47,
      65,   175,    12,    67,    48,    49,     5,    69,     6,     7,
      50,    68,    42,    51,    43,   186,   189,    52,    53,    54,
      55,    56,    57,    58,     5,    70,     6,     7,    71,    72,
     190,   191,    73,   192,   193,   194,   195,   196,   197,    74,
      84,   198,   199,    35,    85,    36,   202,   203,    78,   125,
      79,   206,   207,   208,   209,   210,   211,    80,   140,    81,
     214,   215,   216,   217,    82,   143,    83,   220,   221,   222,
     223,   224,   225,   226,   227,    12,   139,   142,    93,     5,
     144,     6,     7,   145,   146,    94,     0,    95,   150,   147,
     155,   232,   233,   151,   156,   234,   235,   160,   161,   162,
     163,    12,   164,   236,   237,     5,   165,     6,     7,   238,
     239,    86,   170,    87,   169,    37,     0,    38,    39,   240,
     241,   242,   243,    12,    40,    41,   171,     5,   176,     6,
       7,   172,    13,   177,   179,   178,   180,    14,    15,    16,
      17,    18,   181,   182,    12,   200,   183,   204,     5,    19,
       6,     7,   201,    12,    98,   205,    99,     5,   212,     6,
       7,   213,    12,   105,   219,   106,     5,   218,     6,     7,
     228,    12,   112,   229,   113,     5,   230,     6,     7,   231,
      12,   115,     0,   116,     5,     0,     6,     7,     0,    12,
     118,     0,   119,     5,     0,     6,     7,     0,    12,   121,
       0,   122,     5,     0,     6,     7,     0,    12,   152,     0,
     153,     5,     0,     6,     7,     0,    12,   157,     0,   158,
       5,     0,     6,     7,     0,    12,   166,     0,   167,     5,
       0,     6,     7,     0,    12,   173,     0,   174,     5,     0,
       6,     7,     0,    12,   184,     0,   185,     5,     0,     6,
       7,     0,     0,   187,     0,   188
};

static const yytype_int16 yycheck[] =
{
      19,     1,     3,    13,     3,    15,     7,     4,     9,    10,
       0,    13,    13,    15,    15,     5,     6,     7,     3,     9,
      10,     4,     7,    24,     9,    10,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    13,     8,
      15,    16,    13,     9,    15,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    10,     3,    77,     6,
       7,     7,    62,     9,    10,    84,    85,    13,     3,    15,
      89,    17,     5,     3,    93,     5,    13,     7,    15,     9,
      10,    30,    14,    13,   103,    15,    14,     4,     5,     6,
      16,   110,     3,    16,    11,    12,     7,    16,     9,    10,
      17,    14,    13,    20,    15,   124,   125,    24,    25,    26,
      27,    28,    29,    30,     7,    14,     9,    10,    16,    14,
     139,   140,    16,   142,   143,   144,   145,   146,   147,    14,
      14,   150,   151,    13,    16,    15,   155,   156,    13,    30,
      15,   160,   161,   162,   163,   164,   165,    13,    16,    15,
     169,   170,   171,   172,    13,    16,    15,   176,   177,   178,
     179,   180,   181,   182,   183,     3,    14,    14,     6,     7,
      14,     9,    10,    16,    14,    13,    -1,    15,    14,    16,
      14,   200,   201,    16,    16,   204,   205,    14,    16,    14,
      16,     3,    14,   212,   213,     7,    16,     9,    10,   218,
     219,    13,    16,    15,    14,    13,    -1,    15,    16,   228,
     229,   230,   231,     3,    22,    23,    14,     7,    14,     9,
      10,    16,    12,    16,    16,    14,    14,    17,    18,    19,
      20,    21,    16,    14,     3,    14,    16,    14,     7,    29,
       9,    10,    16,     3,    13,    16,    15,     7,    14,     9,
      10,    16,     3,    13,    16,    15,     7,    14,     9,    10,
      14,     3,    13,    16,    15,     7,    14,     9,    10,    16,
       3,    13,    -1,    15,     7,    -1,     9,    10,    -1,     3,
      13,    -1,    15,     7,    -1,     9,    10,    -1,     3,    13,
      -1,    15,     7,    -1,     9,    10,    -1,     3,    13,    -1,
      15,     7,    -1,     9,    10,    -1,     3,    13,    -1,    15,
       7,    -1,     9,    10,    -1,     3,    13,    -1,    15,     7,
      -1,     9,    10,    -1,     3,    13,    -1,    15,     7,    -1,
       9,    10,    -1,     3,    13,    -1,    15,     7,    -1,     9,
      10,    -1,    -1,    13,    -1,    15
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,     0,     5,     6,     7,     9,    10,    33,    34,
      35,     3,     3,    12,    17,    18,    19,    20,    21,    29,
      35,    36,    37,    37,    37,     4,     4,    13,    15,    13,
      15,    13,    15,    13,    15,    13,    15,    13,    15,    16,
      22,    23,    13,    15,    36,     4,     5,     6,    11,    12,
      17,    20,    24,    25,    26,    27,    28,    29,    30,     8,
       9,    10,     5,     3,    14,    16,    14,    16,    14,    16,
      14,    16,    14,    16,    14,    13,    15,    16,    13,    15,
      13,    15,    13,    15,    14,    16,    13,    15,    36,     5,
      13,    15,    36,     6,    13,    15,    36,    36,    13,    15,
      36,    13,    15,    17,    36,    13,    15,    36,    13,    15,
      24,    36,    13,    15,    36,    13,    15,    36,    13,    15,
      36,    13,    15,    36,    30,    30,    35,    38,    36,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    14,
      16,    36,    14,    16,    14,    16,    14,    16,    36,    36,
      14,    16,    13,    15,    36,    14,    16,    13,    15,    36,
      14,    16,    14,    16,    14,    16,    13,    15,    36,    14,
      16,    14,    16,    13,    15,    36,    14,    16,    14,    16,
      14,    16,    14,    16,    13,    15,    36,    13,    15,    36,
      36,    36,    36,    36,    36,    36,    36,    36,    36,    36,
      14,    16,    36,    36,    14,    16,    36,    36,    36,    36,
      36,    36,    14,    16,    36,    36,    36,    36,    14,    16,
      36,    36,    36,    36,    36,    36,    36,    36,    14,    16,
      14,    16,    36,    36,    36,    36,    36,    36,    36,    36,
      36,    36,    36,    36
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    31,    32,    32,    33,    33,    33,    34,    35,    35,
      35,    36,    36,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    38
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     4,     4,     1,     1,     3,     3,
       3,     1,     1,     3,     3,     5,     5,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     5,     5,     5,     5,
       4,     5,     5,     5,     5,     3,     5,     5,     3,     5,
       5,     3,     5,     5,     3,     5,     5,     3,     5,     5,
       3,     5,     5,     3,     5,     5,     3,     5,     5,     3,
       5,     5,     3,     5,     5,     4,     4,     4,     6,     6,
       4,     6,     6,     4,     6,     6,     4,     6,     6,     4,
       6,     6,     4,     6,     6,     2,     4,     4,     1,     1
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
  case 4: /* optimization: template '-' '>' replacement  */
#line 189 "oil.y"
{
  static YYSTYPE tempmem[10];
  static int replcount[10];
  /* Handle splitting the file. */
  if(splitcount) splitcount--;
  if(!splitcount && !inloop)
  {
    splitcount=SPLITMAX;
    splitend();
    ++filenumber;
    splitstart();
  }
  /* This is where we actually generate the optimizer code. */
  /* Tree-shape and is-constant conditions */
  printf("  checknodeactbits(np);\n");
  if(treeshapecond(yyvsp[-3],1)) printf("  if(1"); printf(")\n  do\n  {\n");
  /* Nodesame and cxdata conditions */
  {
    int i=10;
    YYSTYPE temp;
    while(--i)
    {
      temp=treenscheck(yyvsp[-3],0,i);
      if(temp)
      {
	printf("    x%d=np",i);
	gennodepath(temp->depth,temp->path);
	printf("->constant; c%d=np",i);
	gennodepath(temp->depth,temp->path);
	printf("->optdata;\n");
      }
      tempmem[i]=temp;
      replcount[i]=0; /* we need to zero this somewhere, may as well be here */
    }
    treecxcond(yyvsp[-3]);
  }
  /* If we reach this point in the generated code, we have an optimizer
     template match. */
  printf("    OPTING(%s_%d);\n",optname,++optnumber);

  /* We now need to replace np with its replacement. This is done by creating
     a new nodetree, copying across tempmem'd nodes where necessary, and then
     substituting one for the other. (This is an inefficient but general way
     to do this.) One special case is needed; because pointers into the root
     node need to continue pointing there, the temporary node tp is copied
     member-for-member and then freed again. The root width can change (this
     is a deviation from previous code), in order to prevent a bug where the
     new root happens to be a unary. (This means we can get a 16-bit unary
     applied to 32-bit data; but the optimiser is meant to ensure that this is
     not problematic.) */
  printf("    tp=newnode();\n");
  treerepcount(yyvsp[0],replcount);
  treerepgen(yyvsp[0],tempmem,replcount);
  printf("    nodefree(np->lval); nodefree(np->rval);\n");
  printf("    *np=*tp; free(tp);\n");
  printf("  } while(0);\n\n");
  /* Free the template and replacement now they're finished being used. */
  treefree(yyvsp[-3]);
  treefree(yyvsp[0]);
}
#line 1481 "oil-oil.c"
    break;

  case 5: /* optimization: '<' LEXERLEAF '-' LEXERLEAF  */
#line 250 "oil.y"
{
  if(!yyvsp[-2]->mustbemesh||!yyvsp[0]->mustbemesh)
  {
    yyerror("syntax error in <#..#()->()> construct");
    free(yyvsp[-2]); free(yyvsp[0]);
    YYERROR;
  }
  printf("  r=%luLU; while(r<=%luLU) {\n",yyvsp[-2]->c,yyvsp[0]->c);
  free(yyvsp[-2]); free(yyvsp[0]);
  inloop=1;
}
#line 1497 "oil-oil.c"
    break;

  case 6: /* optimization: '>'  */
#line 261 "oil.y"
           {printf("  r++;\n  }\n"); inloop=0;}
#line 1503 "oil-oil.c"
    break;

  case 8: /* expr3: '(' expr2 ')'  */
#line 265 "oil.y"
                     {yyval=yyvsp[-1];}
#line 1509 "oil-oil.c"
    break;

  case 9: /* expr3: '"' expr2 '"'  */
#line 266 "oil.y"
                     {yyval=yyvsp[-1];}
#line 1515 "oil-oil.c"
    break;

  case 10: /* expr3: '\'' expr2 '\''  */
#line 267 "oil.y"
                       {yyval=yyvsp[-1];}
#line 1521 "oil-oil.c"
    break;

  case 13: /* expr2: expr '$' expr  */
#line 272 "oil.y"
                     {BINARYEXPR("MINGLE",yyval,yyvsp[-2],yyvsp[0],1);}
#line 1527 "oil-oil.c"
    break;

  case 14: /* expr2: expr '~' expr  */
#line 273 "oil.y"
                     {BINARYEXPR("SELECT",yyval,yyvsp[-2],yyvsp[0],1);}
#line 1533 "oil-oil.c"
    break;

  case 15: /* expr2: expr '~' '1' '6' expr  */
#line 274 "oil.y"
                             {BINARYEXPR("SELECT",yyval,yyvsp[-4],yyvsp[0],0);}
#line 1539 "oil-oil.c"
    break;

  case 16: /* expr2: expr '~' '3' '2' expr  */
#line 275 "oil.y"
                             {BINARYEXPR("SELECT",yyval,yyvsp[-4],yyvsp[0],1);}
#line 1545 "oil-oil.c"
    break;

  case 17: /* expr2: '&' '1' '6' expr  */
#line 276 "oil.y"
                        {UNARYEXPR("AND",yyval,yyvsp[0],0,1);}
#line 1551 "oil-oil.c"
    break;

  case 18: /* expr2: '&' '3' '2' expr  */
#line 277 "oil.y"
                        {UNARYEXPR("AND",yyval,yyvsp[0],1,1);}
#line 1557 "oil-oil.c"
    break;

  case 19: /* expr2: 'V' '1' '6' expr  */
#line 278 "oil.y"
                        {UNARYEXPR("OR",yyval,yyvsp[0],0,1);}
#line 1563 "oil-oil.c"
    break;

  case 20: /* expr2: 'V' '3' '2' expr  */
#line 279 "oil.y"
                        {UNARYEXPR("OR",yyval,yyvsp[0],1,1);}
#line 1569 "oil-oil.c"
    break;

  case 21: /* expr2: '?' '1' '6' expr  */
#line 280 "oil.y"
                        {UNARYEXPR("XOR",yyval,yyvsp[0],0,1);}
#line 1575 "oil-oil.c"
    break;

  case 22: /* expr2: '?' '3' '2' expr  */
#line 281 "oil.y"
                        {UNARYEXPR("XOR",yyval,yyvsp[0],1,1);}
#line 1581 "oil-oil.c"
    break;

  case 23: /* expr2: '^' '1' '6' expr  */
#line 282 "oil.y"
                        {UNARYEXPR("FIN",yyval,yyvsp[0],0,1);}
#line 1587 "oil-oil.c"
    break;

  case 24: /* expr2: '^' '3' '2' expr  */
#line 283 "oil.y"
                        {UNARYEXPR("FIN",yyval,yyvsp[0],1,1);}
#line 1593 "oil-oil.c"
    break;

  case 25: /* expr2: '@' '1' '6' expr  */
#line 284 "oil.y"
                        {UNARYEXPR("WHIRL",yyval,yyvsp[0],0,1);}
#line 1599 "oil-oil.c"
    break;

  case 26: /* expr2: '@' '2' '1' '6' expr  */
#line 285 "oil.y"
                            {UNARYEXPR("WHIRL2",yyval,yyvsp[0],0,1);}
#line 1605 "oil-oil.c"
    break;

  case 27: /* expr2: '@' '3' '1' '6' expr  */
#line 286 "oil.y"
                            {UNARYEXPR("WHIRL3",yyval,yyvsp[0],0,1);}
#line 1611 "oil-oil.c"
    break;

  case 28: /* expr2: '@' '4' '1' '6' expr  */
#line 287 "oil.y"
                            {UNARYEXPR("WHIRL4",yyval,yyvsp[0],0,1);}
#line 1617 "oil-oil.c"
    break;

  case 29: /* expr2: '@' '5' '1' '6' expr  */
#line 288 "oil.y"
                            {UNARYEXPR("WHIRL5",yyval,yyvsp[0],0,1);}
#line 1623 "oil-oil.c"
    break;

  case 30: /* expr2: '@' '3' '2' expr  */
#line 289 "oil.y"
                        {UNARYEXPR("WHIRL",yyval,yyvsp[0],1,1);}
#line 1629 "oil-oil.c"
    break;

  case 31: /* expr2: '@' '2' '3' '2' expr  */
#line 290 "oil.y"
                            {UNARYEXPR("WHIRL2",yyval,yyvsp[0],1,1);}
#line 1635 "oil-oil.c"
    break;

  case 32: /* expr2: '@' '3' '3' '2' expr  */
#line 291 "oil.y"
                            {UNARYEXPR("WHIRL3",yyval,yyvsp[0],1,1);}
#line 1641 "oil-oil.c"
    break;

  case 33: /* expr2: '@' '4' '3' '2' expr  */
#line 292 "oil.y"
                            {UNARYEXPR("WHIRL4",yyval,yyvsp[0],1,1);}
#line 1647 "oil-oil.c"
    break;

  case 34: /* expr2: '@' '5' '3' '2' expr  */
#line 293 "oil.y"
                            {UNARYEXPR("WHIRL5",yyval,yyvsp[0],1,1);}
#line 1653 "oil-oil.c"
    break;

  case 35: /* expr2: expr '&' expr  */
#line 294 "oil.y"
                     {BINARYEXPR("C_AND",yyval,yyvsp[-2],yyvsp[0],1);}
#line 1659 "oil-oil.c"
    break;

  case 36: /* expr2: expr '&' '1' '6' expr  */
#line 295 "oil.y"
                             {BINARYEXPR("C_AND",yyval,yyvsp[-4],yyvsp[0],0);}
#line 1665 "oil-oil.c"
    break;

  case 37: /* expr2: expr '&' '3' '2' expr  */
#line 296 "oil.y"
                             {BINARYEXPR("C_AND",yyval,yyvsp[-4],yyvsp[0],1);}
#line 1671 "oil-oil.c"
    break;

  case 38: /* expr2: expr '|' expr  */
#line 297 "oil.y"
                     {BINARYEXPR("C_OR",yyval,yyvsp[-2],yyvsp[0],1);}
#line 1677 "oil-oil.c"
    break;

  case 39: /* expr2: expr '|' '1' '6' expr  */
#line 298 "oil.y"
                             {BINARYEXPR("C_OR",yyval,yyvsp[-4],yyvsp[0],0);}
#line 1683 "oil-oil.c"
    break;

  case 40: /* expr2: expr '|' '3' '2' expr  */
#line 299 "oil.y"
                             {BINARYEXPR("C_OR",yyval,yyvsp[-4],yyvsp[0],1);}
#line 1689 "oil-oil.c"
    break;

  case 41: /* expr2: expr '^' expr  */
#line 300 "oil.y"
                     {BINARYEXPR("C_XOR",yyval,yyvsp[-2],yyvsp[0],1);}
#line 1695 "oil-oil.c"
    break;

  case 42: /* expr2: expr '^' '1' '6' expr  */
#line 301 "oil.y"
                             {BINARYEXPR("C_XOR",yyval,yyvsp[-4],yyvsp[0],0);}
#line 1701 "oil-oil.c"
    break;

  case 43: /* expr2: expr '^' '3' '2' expr  */
#line 302 "oil.y"
                             {BINARYEXPR("C_XOR",yyval,yyvsp[-4],yyvsp[0],1);}
#line 1707 "oil-oil.c"
    break;

  case 44: /* expr2: expr '+' expr  */
#line 303 "oil.y"
                     {BINARYEXPR("C_PLUS",yyval,yyvsp[-2],yyvsp[0],1);}
#line 1713 "oil-oil.c"
    break;

  case 45: /* expr2: expr '+' '1' '6' expr  */
#line 304 "oil.y"
                             {BINARYEXPR("C_PLUS",yyval,yyvsp[-4],yyvsp[0],0);}
#line 1719 "oil-oil.c"
    break;

  case 46: /* expr2: expr '+' '3' '2' expr  */
#line 305 "oil.y"
                             {BINARYEXPR("C_PLUS",yyval,yyvsp[-4],yyvsp[0],1);}
#line 1725 "oil-oil.c"
    break;

  case 47: /* expr2: expr '-' expr  */
#line 306 "oil.y"
                     {BINARYEXPR("C_MINUS",yyval,yyvsp[-2],yyvsp[0],1);}
#line 1731 "oil-oil.c"
    break;

  case 48: /* expr2: expr '-' '1' '6' expr  */
#line 307 "oil.y"
                             {BINARYEXPR("C_MINUS",yyval,yyvsp[-4],yyvsp[0],0);}
#line 1737 "oil-oil.c"
    break;

  case 49: /* expr2: expr '-' '3' '2' expr  */
#line 308 "oil.y"
                             {BINARYEXPR("C_MINUS",yyval,yyvsp[-4],yyvsp[0],1);}
#line 1743 "oil-oil.c"
    break;

  case 50: /* expr2: expr '*' expr  */
#line 309 "oil.y"
                     {BINARYEXPR("C_TIMES",yyval,yyvsp[-2],yyvsp[0],1);}
#line 1749 "oil-oil.c"
    break;

  case 51: /* expr2: expr '*' '1' '6' expr  */
#line 310 "oil.y"
                             {BINARYEXPR("C_TIMES",yyval,yyvsp[-4],yyvsp[0],0);}
#line 1755 "oil-oil.c"
    break;

  case 52: /* expr2: expr '*' '3' '2' expr  */
#line 311 "oil.y"
                             {BINARYEXPR("C_TIMES",yyval,yyvsp[-4],yyvsp[0],1);}
#line 1761 "oil-oil.c"
    break;

  case 53: /* expr2: expr '/' expr  */
#line 312 "oil.y"
                     {BINARYEXPR("C_DIVIDEBY",yyval,yyvsp[-2],yyvsp[0],1);}
#line 1767 "oil-oil.c"
    break;

  case 54: /* expr2: expr '/' '1' '6' expr  */
#line 313 "oil.y"
                             {BINARYEXPR("C_DIVIDEBY",yyval,yyvsp[-4],yyvsp[0],0);}
#line 1773 "oil-oil.c"
    break;

  case 55: /* expr2: expr '/' '3' '2' expr  */
#line 314 "oil.y"
                             {BINARYEXPR("C_DIVIDEBY",yyval,yyvsp[-4],yyvsp[0],1);}
#line 1779 "oil-oil.c"
    break;

  case 56: /* expr2: expr '%' expr  */
#line 315 "oil.y"
                     {BINARYEXPR("C_MODULUS",yyval,yyvsp[-2],yyvsp[0],1);}
#line 1785 "oil-oil.c"
    break;

  case 57: /* expr2: expr '%' '1' '6' expr  */
#line 316 "oil.y"
                             {BINARYEXPR("C_MODULUS",yyval,yyvsp[-4],yyvsp[0],0);}
#line 1791 "oil-oil.c"
    break;

  case 58: /* expr2: expr '%' '3' '2' expr  */
#line 317 "oil.y"
                             {BINARYEXPR("C_MODULUS",yyval,yyvsp[-4],yyvsp[0],1);}
#line 1797 "oil-oil.c"
    break;

  case 59: /* expr2: expr '>' expr  */
#line 318 "oil.y"
                     {BINARYEXPR("C_GREATER",yyval,yyvsp[-2],yyvsp[0],1);}
#line 1803 "oil-oil.c"
    break;

  case 60: /* expr2: expr '>' '1' '6' expr  */
#line 319 "oil.y"
                             {BINARYEXPR("C_GREATER",yyval,yyvsp[-4],yyvsp[0],0);}
#line 1809 "oil-oil.c"
    break;

  case 61: /* expr2: expr '>' '3' '2' expr  */
#line 320 "oil.y"
                             {BINARYEXPR("C_GREATER",yyval,yyvsp[-4],yyvsp[0],1);}
#line 1815 "oil-oil.c"
    break;

  case 62: /* expr2: expr '<' expr  */
#line 321 "oil.y"
                     {BINARYEXPR("C_LESS",yyval,yyvsp[-2],yyvsp[0],1);}
#line 1821 "oil-oil.c"
    break;

  case 63: /* expr2: expr '<' '1' '6' expr  */
#line 322 "oil.y"
                             {BINARYEXPR("C_LESS",yyval,yyvsp[-4],yyvsp[0],0);}
#line 1827 "oil-oil.c"
    break;

  case 64: /* expr2: expr '<' '3' '2' expr  */
#line 323 "oil.y"
                             {BINARYEXPR("C_LESS",yyval,yyvsp[-4],yyvsp[0],1);}
#line 1833 "oil-oil.c"
    break;

  case 65: /* expr2: '~' '1' '6' expr  */
#line 324 "oil.y"
                        {UNARYEXPR("C_NOT",yyval,yyvsp[0],0,1);}
#line 1839 "oil-oil.c"
    break;

  case 66: /* expr2: '~' '3' '2' expr  */
#line 325 "oil.y"
                        {UNARYEXPR("C_NOT",yyval,yyvsp[0],1,1);}
#line 1845 "oil-oil.c"
    break;

  case 67: /* expr2: expr '!' '=' expr  */
#line 326 "oil.y"
                         {BINARYEXPR("C_NOTEQUAL",yyval,yyvsp[-3],yyvsp[0],0);}
#line 1851 "oil-oil.c"
    break;

  case 68: /* expr2: expr '!' '=' '1' '6' expr  */
#line 327 "oil.y"
                                 {BINARYEXPR("C_NOTEQUAL",yyval,yyvsp[-5],yyvsp[0],0);}
#line 1857 "oil-oil.c"
    break;

  case 69: /* expr2: expr '!' '=' '3' '2' expr  */
#line 328 "oil.y"
                                 {BINARYEXPR("C_NOTEQUAL",yyval,yyvsp[-5],yyvsp[0],1);}
#line 1863 "oil-oil.c"
    break;

  case 70: /* expr2: expr '=' '=' expr  */
#line 329 "oil.y"
                         {BINARYEXPR("C_ISEQUAL",yyval,yyvsp[-3],yyvsp[0],0);}
#line 1869 "oil-oil.c"
    break;

  case 71: /* expr2: expr '=' '=' '1' '6' expr  */
#line 330 "oil.y"
                                 {BINARYEXPR("C_ISEQUAL",yyval,yyvsp[-5],yyvsp[0],0);}
#line 1875 "oil-oil.c"
    break;

  case 72: /* expr2: expr '=' '=' '3' '2' expr  */
#line 331 "oil.y"
                                 {BINARYEXPR("C_ISEQUAL",yyval,yyvsp[-5],yyvsp[0],1);}
#line 1881 "oil-oil.c"
    break;

  case 73: /* expr2: expr '&' '&' expr  */
#line 332 "oil.y"
                         {BINARYEXPR("C_LOGICALAND",yyval,yyvsp[-3],yyvsp[0],0);}
#line 1887 "oil-oil.c"
    break;

  case 74: /* expr2: expr '&' '&' '1' '6' expr  */
#line 333 "oil.y"
                                 {BINARYEXPR("C_LOGICALAND",yyval,yyvsp[-5],yyvsp[0],0);}
#line 1893 "oil-oil.c"
    break;

  case 75: /* expr2: expr '&' '&' '3' '2' expr  */
#line 334 "oil.y"
                                 {BINARYEXPR("C_LOGICALAND",yyval,yyvsp[-5],yyvsp[0],1);}
#line 1899 "oil-oil.c"
    break;

  case 76: /* expr2: expr '|' '|' expr  */
#line 335 "oil.y"
                         {BINARYEXPR("C_LOGICALOR",yyval,yyvsp[-3],yyvsp[0],0);}
#line 1905 "oil-oil.c"
    break;

  case 77: /* expr2: expr '|' '|' '1' '6' expr  */
#line 336 "oil.y"
                                 {BINARYEXPR("C_LOGICALOR",yyval,yyvsp[-5],yyvsp[0],0);}
#line 1911 "oil-oil.c"
    break;

  case 78: /* expr2: expr '|' '|' '3' '2' expr  */
#line 337 "oil.y"
                                 {BINARYEXPR("C_LOGICALOR",yyval,yyvsp[-5],yyvsp[0],1);}
#line 1917 "oil-oil.c"
    break;

  case 79: /* expr2: expr '>' '>' expr  */
#line 338 "oil.y"
                         {BINARYEXPR("C_RSHIFTBY",yyval,yyvsp[-3],yyvsp[0],1);}
#line 1923 "oil-oil.c"
    break;

  case 80: /* expr2: expr '>' '>' '1' '6' expr  */
#line 339 "oil.y"
                                 {BINARYEXPR("C_RSHIFTBY",yyval,yyvsp[-5],yyvsp[0],0);}
#line 1929 "oil-oil.c"
    break;

  case 81: /* expr2: expr '>' '>' '3' '2' expr  */
#line 340 "oil.y"
                                 {BINARYEXPR("C_RSHIFTBY",yyval,yyvsp[-5],yyvsp[0],1);}
#line 1935 "oil-oil.c"
    break;

  case 82: /* expr2: expr '<' '<' expr  */
#line 341 "oil.y"
                         {BINARYEXPR("C_LSHIFTBY",yyval,yyvsp[-3],yyvsp[0],1);}
#line 1941 "oil-oil.c"
    break;

  case 83: /* expr2: expr '<' '<' '1' '6' expr  */
#line 342 "oil.y"
                                 {BINARYEXPR("C_LSHIFTBY",yyval,yyvsp[-5],yyvsp[0],0);}
#line 1947 "oil-oil.c"
    break;

  case 84: /* expr2: expr '<' '<' '3' '2' expr  */
#line 343 "oil.y"
                                 {BINARYEXPR("C_LSHIFTBY",yyval,yyvsp[-5],yyvsp[0],1);}
#line 1953 "oil-oil.c"
    break;

  case 85: /* expr2: '!' expr  */
#line 344 "oil.y"
                {UNARYEXPR("C_LOGICALNOT",yyval,yyvsp[0],0,0);}
#line 1959 "oil-oil.c"
    break;

  case 86: /* expr2: '!' '1' '6' expr  */
#line 345 "oil.y"
                        {UNARYEXPR("C_LOGICALNOT",yyval,yyvsp[0],0,0);}
#line 1965 "oil-oil.c"
    break;

  case 87: /* expr2: '!' '3' '2' expr  */
#line 346 "oil.y"
                        {UNARYEXPR("C_LOGICALNOT",yyval,yyvsp[0],1,0);}
#line 1971 "oil-oil.c"
    break;


#line 1975 "oil-oil.c"

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

#line 351 "oil.y"


#define MAXTOFREE 1000

char* tofree[MAXTOFREE]={0};
int tfi=0;

int yylex(void)
{
  int c;
  unsigned long acc;

  /* Whitespace is completely insignificant here, even inside && and other
     two-character operators. Just to be different, though, it /is/ significant
     inside constructs like .1 and #{1}2; in such cases, it isn't allowed. */
  c=countgetchar();
  while(isspace(c)) c=countgetchar();
  while(c==';'||c=='[')
  {
    /* Comments go from a semicolon/hybrid to the end of the line. */
    if(c==';')
    {
      c=countgetchar();
      while(c!='\n') c=countgetchar();
      while(isspace(c)) c=countgetchar();
    }
    /* Square brackets set the name for optimizations. */
    if(c=='[')
    {
      int i=0;
      c=countgetchar();
      while(c!=']')
      {
	optname[i++]=c;
	c=countgetchar();
	if(i==MAXOPTNAMELEN-1) {i=0; yyerror("optimization name too long");}
      }
      optnumber=0;
      optname[i]=0;
      c=countgetchar();
      while(isspace(c)) c=countgetchar();
    }
  }
  if(c==EOF) return 0;
  switch(c)
  {
  case '#':
    c=countgetchar();
    if(c!='{')
    {
      acc=0;
      while(isdigit(c))
      {
	acc*=10;
	acc+=(c-'0');
	c=countgetchar();
      }
      yylval=malloc(sizeof(struct ickstype));
      yylval->depth=0;
      yylval->path=0;
      yylval->condition="->constant==";
      yylval->nodetypename=0;
      yylval->usec=1;
      yylval->mustbemesh=1;
      yylval->cxneeded=0;
      yylval->c=acc;
      yylval->replnum=0;
      yylval->n1=0;
      yylval->n2=0;
      yylval->ublo=0;
      yylval->width32=1; /* generate MESH32 not MESH; we can still AND16 it,
			    etc., if necessary */
      countungetc(c, stdin);
      return LEXERLEAF;
    }
    countungetc(c, stdin);
    c='#';
    /* fall through */
  case '_':
  case ':':
  case '.':
    yylval=malloc(sizeof(struct ickstype));
    yylval->depth=0;
    yylval->path=0;
    yylval->condition=0; /* _ or # */
    yylval->width32=1; /* should never matter, but you never
			  know... */
    yylval->ublo=0;
    if(c==':') yylval->condition="->width==32";
    if(c=='.') {yylval->condition="->width==16"; yylval->width32=0;}
    yylval->nodetypename=0;
    yylval->usec=0;
    yylval->mustbemesh=c=='#';
    yylval->cxneeded=0;
    c=countgetchar();
    if(c=='{')
    {
      /* Create a new node to hold the c/x condition */
      yylval->n1=malloc(sizeof(struct ickstype));
      yylval->n1->depth=0;
      yylval->n1->path=0;
      {
	static char buf[512];
	int bi=0;
	c=countgetchar();
	while(c!='}')
	{
	  buf[bi++]=c;
	  if(bi==511) {yyerror("{quoted} string too long"); bi=0;}
	  c=countgetchar();
	}
	buf[bi]=0;
	yylval->n1->condition=tofree[tfi++]=strdup(buf);
	if(tfi==MAXTOFREE) {yyerror("Too many {quoted} strings"); tfi--;}
	c=countgetchar();
      }
      yylval->n1->nodetypename=0;
      yylval->n1->usec=0;
      yylval->n1->mustbemesh=0;
      yylval->n1->cxneeded=1;
      yylval->n1->n1=0;
      yylval->n1->n2=0;
      yylval->n1->width32=yylval->width32;
      yylval->n1->ublo=0;
    }
    else yylval->n1=0;
    yylval->replnum=0;
    if(yylval->n1) yylval->n1->replnum=c-'0'; else yylval->replnum=c-'0';
    yylval->n2=0;
    return LEXERLEAF;
  default:
    return c;
  }
}

void treedepthup(YYSTYPE v, bool i)
{
  if(!v) return;
  treedepthup(v->n1,i);
  treedepthup(v->n2,i);
  v->depth++;
  v->path<<=1;
  v->path|=i;
  if(v->depth>30) yyerror("Nesting too deep in template or replacement\n");
}

void treefree(YYSTYPE v)
{
  if(!v) return;
  treefree(v->n1);
  treefree(v->n2);
  free(v);
}

void gennodepath(unsigned depth, unsigned long path)
{
  while(depth--)
  {
    if(path&1) printf("->rval"); else printf("->lval");
    path>>=1;
  }
}

bool treeshapecond(YYSTYPE v, bool firstopt)
{
  if(!v) return firstopt;
  /* To prevent possibly dereferencing a null pointer, check the root ick_first */
  if(v->mustbemesh) /* it's a must-be-constant constraint */
  {
    printf(firstopt?"  if((np":" &&\n     (np");
    gennodepath(v->depth,v->path);
    printf("->opcode==MESH || np");
    gennodepath(v->depth,v->path);
    printf("->opcode==MESH32)");
    firstopt=0;
  }
  if(v->condition&&!v->cxneeded) /* it's a tree-shape constraint */
  {
    printf(firstopt?"  if(np":" &&\n     np");
    gennodepath(v->depth,v->path);
    printf("%s",v->condition);
    if(v->usec) printf("%luLU",v->c);
    firstopt=0;
  }
  if(v->ublo) /* generate a width check */
  {
    printf(firstopt?"  if(np":" &&\n     np");
    gennodepath(v->depth,v->path);
    printf("->width==%d",v->width32?32:16);
    firstopt=0;
  }
  firstopt=treeshapecond(v->n1,firstopt);
  return treeshapecond(v->n2,firstopt);
}

YYSTYPE treenscheck(YYSTYPE v, YYSTYPE prev, int replnum)
{
  if(!v) return prev;
  prev=treenscheck(v->n1,prev,replnum);
  prev=treenscheck(v->n2,prev,replnum);
  if(v->replnum!=replnum) return prev;
  if(prev)
  {
    printf("    if(!nodessame(np");
    gennodepath(prev->depth,prev->path);
    printf(",np");
    gennodepath(v->depth,v->path);
    printf(")) break;\n");
  }
  return v;
}

void treecxcond(YYSTYPE v)
{
  if(!v) return;
  if(v->cxneeded&&strcmp(v->condition,"1"))
  {
    if(v->replnum)
      printf("    x=x%d; c=c%d; ",v->replnum,v->replnum);
    else
    {
      printf("    x=np");
      gennodepath(v->depth,v->path);
      printf("->constant;\n    c=np");
      gennodepath(v->depth,v->path);
      printf("->optdata;\n    ");
    }
    printf("if(!(%s)) break;\n",v->condition);
  }
  treecxcond(v->n1);
  treecxcond(v->n2);
}

void treerepcount(YYSTYPE v, int* rc)
{
  if(!v) return;
  if(!(v->nodetypename)&&v->replnum&&!(v->cxneeded)) rc[v->replnum]++;
  treerepcount(v->n1, rc);
  treerepcount(v->n2, rc);
}

void treerepgen(YYSTYPE v, YYSTYPE* refs, int* rc)
{
  if(!v) return;
  /* We absolutely have to generate the root node ick_first here, because otherwise
     the nodes in question won't exist. */
  if(v->nodetypename) /* Generate an intermediate node */
  {
    printf("    MAYBENEWNODE(tp");
    gennodepath(v->depth,v->path);
    printf(");\n    tp");
    gennodepath(v->depth,v->path);
    printf("->opcode=%s;\n    tp",v->nodetypename);
    gennodepath(v->depth,v->path);
    printf("->width=%d;\n",v->width32?32:16);
    /* optdata will be filled in by checknodeactbits before the ick_next idiom is
       tested; constant is irrelevant, lval and rval are NULL at present and
       will be filled in by later recursions of this function, and I seriously
       hope that nextslat is never filled in by an optimizer idiom. */
  }
  else if(v->replnum&&!(v->cxneeded))
  {
    /* Copy a node from the template. The node ought not to be allocated at
       this point, so we can safely just ick_assign to it with a new malloced
       node. */
    if(refs[v->replnum])
    {
      if(rc[v->replnum]>1||!refs[v->replnum]->depth)
      {
	/* The node actually has to be copied, either because another copy is
	   needed or because it's np itself that's being copied over. */
	rc[v->replnum]--;
	printf("    tp");
	gennodepath(v->depth,v->path);
	printf("=nodecopy(np");
	gennodepath(refs[v->replnum]->depth,refs[v->replnum]->path);
	printf(");\n");
      }
      else
      {
	/* This can be optimized slightly by moving rather than copying,
	   zeroing backlinks so that the node won't be freed. */
	rc[v->replnum]--;
	printf("    tp");
	gennodepath(v->depth,v->path);
	printf("=np");
	gennodepath(refs[v->replnum]->depth,refs[v->replnum]->path);
	printf(";\n    np");
	gennodepath(refs[v->replnum]->depth,refs[v->replnum]->path);
	printf("=0;\n");
      }
    }
    else yyerror("Replacement isn't in the template");
  }
  else if(v->cxneeded)
  {
    /* Generate a constant node based on an expression (#{expr}0). */
    printf("    MAYBENEWNODE(tp");
    gennodepath(v->depth,v->path);
    printf(");\n    tp");
    gennodepath(v->depth,v->path);
    printf("->opcode=MESH32;\n    tp");
    gennodepath(v->depth,v->path);
    printf("->width=32;\n    tp");
    gennodepath(v->depth,v->path);
    printf("->constant=(%s);\n",v->condition);
  }
  else if(v->mustbemesh&&!v->n1)
  {
    /* Generate a constant node based on a constant (#65535). */
    printf("    MAYBENEWNODE(tp");
    gennodepath(v->depth,v->path);
    printf(");\n    tp");
    gennodepath(v->depth,v->path);
    printf("->opcode=MESH32;\n    tp");
    gennodepath(v->depth,v->path);
    printf("->width=32;\n    tp");
    gennodepath(v->depth,v->path);
    printf("->constant=(%luLU);\n",v->c);
  }
  else if(v->mustbemesh&&v->n1)
    /* let this node's n1 handle it */ ;
  else
    yyerror("can't figure out how to generate a replacement node\n");
  treerepgen(v->n1,refs,rc);
  treerepgen(v->n2,refs,rc);
}

int yyerror(char const *s)
{
  fprintf(stderr,"Error at (%d:%d): \"%s\"\n",cgcrow,cgccol,s);
  return 0; /* this return value is ignored anyway */
}

static int cgcpushback=0;

int countgetchar(void)
{
  int c=getchar();
  if(cgcpushback) {cgcpushback=0; return c;}
  cgccol++;
  if(c=='\n') {cgccol=0; cgcrow++;}
  return c;
}

int countungetc(int c, FILE* f)
{
  ungetc(c,f);
  cgcpushback=1;
  return c;
}

void splitstart(void)
{
  static char fname[]="oilout00.c";
  FILE *dummy;     /* GCC 4 un-suppressable warning suck */
  if(filenumber>255)
  {
    filenumber=255;
    fprintf(stdout,"Input file too long.\n");
  }
  sprintf(fname,"oilout%02x.c",filenumber);
  dummy = freopen(fname,"w",stdout);
  puts("/* Automatically generated output, edit source and recompile to "
       "change */");
  printf("#include \"oil.h\"\n"
	 "int optimize_pass1_%x(node *np)\n"
	 "{"
	 "  int opted=0;\n"
	 "  unsigned long c,c1,c2,c3,c4,c5,c6,c7,c8,c9;\n"
	 "  unsigned long x,x1,x2,x3,x4,x5,x6,x7,x8,x9,r;\n"
	 "  int tempw;\n"
	 "  node *tp;\n", filenumber);
}

void splitend(void)
{
  /* Disabling warnings about unused variables. gcc will optimize this right
     out, and in any case the raise(SIGSEGV) will be unreachable (but will
     cause a pretty recognizable error because it'll be caught by the handler
     for SIGSEGV and output an internal error, with an obvious debug backtrace
     if -U is used). */
  printf("  c=c1=c2=c3=c4=c5=c6=c7=c8=c9=0;\n"
	 "  x=x1=x2=x3=x4=x5=x6=x7=x8=x9=r=0;\n"
	 "  if(c+c1+c2+c3+c4+c5+c6+c7+c8+c9+r+\n"
	 "     x+x1+x2+x3+x4+x5+x6+x7+x8+x9) raise(SIGSEGV);\n");
  printf("  return opted;\n}\n");
  /* do not close stdout; freopen implicitly closes it anyway, and explicitly
     closing it breaks on DOS */
}

int main(void)
{
  int e,i;
  FILE *dummy;    /* GCC 4 un-suppressible warnings suck */
  /*
    "  if(!np) return 0;\n"
    "  if(np->lval) opted|=optimize_pass1(np->lval);\n"
    "  if(np->rval) opted|=optimize_pass1(np->rval);\n"
  */
  splitstart();
  cgccol=0;
  cgcrow=1;
  e=yyparse();
  while(tfi--) free(tofree[tfi]);
  splitend();
  dummy = freopen("oilout-m.c","w",stdout);
  puts("/* Automatically generated output, edit source and recompile to "
       "change */");
  puts("#include \"config.h\"");
  puts("#include \"ick.h\"");
  i=filenumber+1;
  while(i--) printf("extern int optimize_pass1_%x(node*);\n",i);
  puts("int optimize_pass1(node* np)\n"
       "{\n"
       "  int opted=0;\n"
       "  if(!np) return 0;\n"
       "  if(np->lval) opted|=optimize_pass1(np->lval);\n"
       "  if(np->rval) opted|=optimize_pass1(np->rval);");
  i=filenumber+1;
  while(i--) printf("  opted|=optimize_pass1_%x(np);\n",i);
  puts("  return opted;\n"
       "}");
  return e;
}

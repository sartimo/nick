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
#line 30 "parser.y"

#include "config.h"
#include <stdio.h>
#include <stdlib.h>
#include "sizes.h"
#include "ick.h"
#include "feh.h"
#include "ick_lose.h"

extern int yyerror(const char*);

/* Intervene our ick_first-stage lexer. */
extern int lexer(void);
#define yylex() lexer()

static node *rlist;	/* pointer to current right-hand node list */
/*static node *llist;*/	/* pointer to current left-hand node list */
static node *np;	/* variable for building node lists */

extern int stbeginline;	/* line number of last seen preamble */
static int thisline;	/* line number of beginning of current statement */

extern int mark112;    /* AIS: Mark the tuple for W112 when it's created. */
static int lineuid=65537; /* AIS: a line number not used anywhere else */
static int cacsofar=0; /* AIS: Number of args in a CREATE statement */

static tuple *splat(int);

static tuple *prevtuple = NULL;

#define GETLINENO					\
    {if (stbeginline < 0) thisline = -stbeginline;	\
     else {thisline = stbeginline; stbeginline = 0;}}

#define ACTION(x, nt, nn)	\
    {x = newtuple(); x->type = nt; x->ick_lineno = thisline; x->u.node = nn;}
#define TARGET(x, nt, nn)	\
    {x = newtuple(); x->type = nt; x->ick_lineno = thisline; x->u.target = nn;}
#define ACTARGET(x, nt, nn, nn2)\
    {x = newtuple(); x->type = nt; x->ick_lineno = thisline;\
      x->u.node = nn; x->u.target = nn2;}
/* AIS : The macro above was added for ABSTAIN expr FROM. */
#define NEWFANGLED mark112 = 1; /* AIS: Added the mention of mark112 */ \
      if (ick_traditional) ick_lose(IE111,iyylineno,(char*)NULL); else

#define DESTACKSE1 sparkearsstack[sparkearslev--/32] >>= 1
#define DESTACKSPARKEARS DESTACKSE1; DESTACKSE1


#line 121 "parser.c"

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
    UNKNOWN = 258,                 /* UNKNOWN  */
    GETS = 259,                    /* GETS  */
    RESIZE = 260,                  /* RESIZE  */
    NEXT = 261,                    /* NEXT  */
    GO_AHEAD = 262,                /* GO_AHEAD  */
    GO_BACK = 263,                 /* GO_BACK  */
    FORGET = 264,                  /* FORGET  */
    RESUME = 265,                  /* RESUME  */
    STASH = 266,                   /* STASH  */
    RETRIEVE = 267,                /* RETRIEVE  */
    IGNORE = 268,                  /* IGNORE  */
    REMEMBER = 269,                /* REMEMBER  */
    ABSTAIN = 270,                 /* ABSTAIN  */
    REINSTATE = 271,               /* REINSTATE  */
    DISABLE = 272,                 /* DISABLE  */
    ENABLE = 273,                  /* ENABLE  */
    MANYFROM = 274,                /* MANYFROM  */
    GIVE_UP = 275,                 /* GIVE_UP  */
    READ_OUT = 276,                /* READ_OUT  */
    WRITE_IN = 277,                /* WRITE_IN  */
    PIN = 278,                     /* PIN  */
    COME_FROM = 279,               /* COME_FROM  */
    NEXTFROMLABEL = 280,           /* NEXTFROMLABEL  */
    NEXTFROMEXPR = 281,            /* NEXTFROMEXPR  */
    NEXTFROMGERUND = 282,          /* NEXTFROMGERUND  */
    COMPUCOME = 283,               /* COMPUCOME  */
    GERUCOME = 284,                /* GERUCOME  */
    PREPROC = 285,                 /* PREPROC  */
    WHILE = 286,                   /* WHILE  */
    TRY_AGAIN = 287,               /* TRY_AGAIN  */
    CREATE = 288,                  /* CREATE  */
    COMPUCREATE = 289,             /* COMPUCREATE  */
    FROM = 290,                    /* FROM  */
    MAYBE = 291,                   /* MAYBE  */
    DO = 292,                      /* DO  */
    PLEASE = 293,                  /* PLEASE  */
    NOT = 294,                     /* NOT  */
    ONCE = 295,                    /* ONCE  */
    AGAIN = 296,                   /* AGAIN  */
    MESH = 297,                    /* MESH  */
    NOSPOT = 298,                  /* NOSPOT  */
    ick_ONESPOT = 299,             /* ick_ONESPOT  */
    ick_TWOSPOT = 300,             /* ick_TWOSPOT  */
    ick_TAIL = 301,                /* ick_TAIL  */
    ick_HYBRID = 302,              /* ick_HYBRID  */
    MINGLE = 303,                  /* MINGLE  */
    SELECT = 304,                  /* SELECT  */
    UNKNOWNOP = 305,               /* UNKNOWNOP  */
    SUB = 306,                     /* SUB  */
    BY = 307,                      /* BY  */
    SLAT = 308,                    /* SLAT  */
    BACKSLAT = 309,                /* BACKSLAT  */
    NUMBER = 310,                  /* NUMBER  */
    UNARY = 311,                   /* UNARY  */
    OHOHSEVEN = 312,               /* OHOHSEVEN  */
    GERUND = 313,                  /* GERUND  */
    LABEL = 314,                   /* LABEL  */
    BADCHAR = 315,                 /* BADCHAR  */
    INTERSECTION = 316,            /* INTERSECTION  */
    SPLATTERED = 317,              /* SPLATTERED  */
    MESH32 = 318,                  /* MESH32  */
    C_AND = 319,                   /* C_AND  */
    C_OR = 320,                    /* C_OR  */
    C_XOR = 321,                   /* C_XOR  */
    C_NOT = 322,                   /* C_NOT  */
    C_LOGICALNOT = 323,            /* C_LOGICALNOT  */
    C_LSHIFTBY = 324,              /* C_LSHIFTBY  */
    C_RSHIFTBY = 325,              /* C_RSHIFTBY  */
    C_NOTEQUAL = 326,              /* C_NOTEQUAL  */
    C_A = 327,                     /* C_A  */
    C_PLUS = 328,                  /* C_PLUS  */
    C_MINUS = 329,                 /* C_MINUS  */
    C_TIMES = 330,                 /* C_TIMES  */
    C_DIVIDEBY = 331,              /* C_DIVIDEBY  */
    C_MODULUS = 332,               /* C_MODULUS  */
    C_GREATER = 333,               /* C_GREATER  */
    C_LESS = 334,                  /* C_LESS  */
    C_ISEQUAL = 335,               /* C_ISEQUAL  */
    C_LOGICALAND = 336,            /* C_LOGICALAND  */
    C_LOGICALOR = 337,             /* C_LOGICALOR  */
    AND = 338,                     /* AND  */
    OR = 339,                      /* OR  */
    XOR = 340,                     /* XOR  */
    FIN = 341,                     /* FIN  */
    WHIRL = 342,                   /* WHIRL  */
    WHIRL2 = 343,                  /* WHIRL2  */
    WHIRL3 = 344,                  /* WHIRL3  */
    WHIRL4 = 345,                  /* WHIRL4  */
    WHIRL5 = 346,                  /* WHIRL5  */
    REV_AND = 347,                 /* REV_AND  */
    REV_OR = 348,                  /* REV_OR  */
    REV_XOR = 349,                 /* REV_XOR  */
    REV_FIN = 350,                 /* REV_FIN  */
    REV_WHIRL = 351,               /* REV_WHIRL  */
    REV_WHIRL2 = 352,              /* REV_WHIRL2  */
    REV_WHIRL3 = 353,              /* REV_WHIRL3  */
    REV_WHIRL4 = 354,              /* REV_WHIRL4  */
    REV_WHIRL5 = 355,              /* REV_WHIRL5  */
    UNKNOWNID = 356,               /* UNKNOWNID  */
    US_ID = 357,                   /* US_ID  */
    US_SCALAR = 358,               /* US_SCALAR  */
    US_ARRVAR = 359,               /* US_ARRVAR  */
    US_ELEM = 360,                 /* US_ELEM  */
    US_EXPR = 361,                 /* US_EXPR  */
    OPENEARS = 362,                /* OPENEARS  */
    OPENSPARK = 363,               /* OPENSPARK  */
    CLOSEEARS = 364,               /* CLOSEEARS  */
    CLOSESPARK = 365,              /* CLOSESPARK  */
    HIGHPREC = 366,                /* HIGHPREC  */
    UNARYPREC = 367,               /* UNARYPREC  */
    LOWPREC = 368                  /* LOWPREC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define UNKNOWN 258
#define GETS 259
#define RESIZE 260
#define NEXT 261
#define GO_AHEAD 262
#define GO_BACK 263
#define FORGET 264
#define RESUME 265
#define STASH 266
#define RETRIEVE 267
#define IGNORE 268
#define REMEMBER 269
#define ABSTAIN 270
#define REINSTATE 271
#define DISABLE 272
#define ENABLE 273
#define MANYFROM 274
#define GIVE_UP 275
#define READ_OUT 276
#define WRITE_IN 277
#define PIN 278
#define COME_FROM 279
#define NEXTFROMLABEL 280
#define NEXTFROMEXPR 281
#define NEXTFROMGERUND 282
#define COMPUCOME 283
#define GERUCOME 284
#define PREPROC 285
#define WHILE 286
#define TRY_AGAIN 287
#define CREATE 288
#define COMPUCREATE 289
#define FROM 290
#define MAYBE 291
#define DO 292
#define PLEASE 293
#define NOT 294
#define ONCE 295
#define AGAIN 296
#define MESH 297
#define NOSPOT 298
#define ick_ONESPOT 299
#define ick_TWOSPOT 300
#define ick_TAIL 301
#define ick_HYBRID 302
#define MINGLE 303
#define SELECT 304
#define UNKNOWNOP 305
#define SUB 306
#define BY 307
#define SLAT 308
#define BACKSLAT 309
#define NUMBER 310
#define UNARY 311
#define OHOHSEVEN 312
#define GERUND 313
#define LABEL 314
#define BADCHAR 315
#define INTERSECTION 316
#define SPLATTERED 317
#define MESH32 318
#define C_AND 319
#define C_OR 320
#define C_XOR 321
#define C_NOT 322
#define C_LOGICALNOT 323
#define C_LSHIFTBY 324
#define C_RSHIFTBY 325
#define C_NOTEQUAL 326
#define C_A 327
#define C_PLUS 328
#define C_MINUS 329
#define C_TIMES 330
#define C_DIVIDEBY 331
#define C_MODULUS 332
#define C_GREATER 333
#define C_LESS 334
#define C_ISEQUAL 335
#define C_LOGICALAND 336
#define C_LOGICALOR 337
#define AND 338
#define OR 339
#define XOR 340
#define FIN 341
#define WHIRL 342
#define WHIRL2 343
#define WHIRL3 344
#define WHIRL4 345
#define WHIRL5 346
#define REV_AND 347
#define REV_OR 348
#define REV_XOR 349
#define REV_FIN 350
#define REV_WHIRL 351
#define REV_WHIRL2 352
#define REV_WHIRL3 353
#define REV_WHIRL4 354
#define REV_WHIRL5 355
#define UNKNOWNID 356
#define US_ID 357
#define US_SCALAR 358
#define US_ARRVAR 359
#define US_ELEM 360
#define US_EXPR 361
#define OPENEARS 362
#define OPENSPARK 363
#define CLOSEEARS 364
#define CLOSESPARK 365
#define HIGHPREC 366
#define UNARYPREC 367
#define LOWPREC 368

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 83 "parser.y"

    int		numval;		/* a numeric value */
    tuple	*tuple;		/* a code tuple */
    node	*node;		/* an expression-tree node */

#line 406 "parser.c"

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
  YYSYMBOL_UNKNOWN = 3,                    /* UNKNOWN  */
  YYSYMBOL_GETS = 4,                       /* GETS  */
  YYSYMBOL_RESIZE = 5,                     /* RESIZE  */
  YYSYMBOL_NEXT = 6,                       /* NEXT  */
  YYSYMBOL_GO_AHEAD = 7,                   /* GO_AHEAD  */
  YYSYMBOL_GO_BACK = 8,                    /* GO_BACK  */
  YYSYMBOL_FORGET = 9,                     /* FORGET  */
  YYSYMBOL_RESUME = 10,                    /* RESUME  */
  YYSYMBOL_STASH = 11,                     /* STASH  */
  YYSYMBOL_RETRIEVE = 12,                  /* RETRIEVE  */
  YYSYMBOL_IGNORE = 13,                    /* IGNORE  */
  YYSYMBOL_REMEMBER = 14,                  /* REMEMBER  */
  YYSYMBOL_ABSTAIN = 15,                   /* ABSTAIN  */
  YYSYMBOL_REINSTATE = 16,                 /* REINSTATE  */
  YYSYMBOL_DISABLE = 17,                   /* DISABLE  */
  YYSYMBOL_ENABLE = 18,                    /* ENABLE  */
  YYSYMBOL_MANYFROM = 19,                  /* MANYFROM  */
  YYSYMBOL_GIVE_UP = 20,                   /* GIVE_UP  */
  YYSYMBOL_READ_OUT = 21,                  /* READ_OUT  */
  YYSYMBOL_WRITE_IN = 22,                  /* WRITE_IN  */
  YYSYMBOL_PIN = 23,                       /* PIN  */
  YYSYMBOL_COME_FROM = 24,                 /* COME_FROM  */
  YYSYMBOL_NEXTFROMLABEL = 25,             /* NEXTFROMLABEL  */
  YYSYMBOL_NEXTFROMEXPR = 26,              /* NEXTFROMEXPR  */
  YYSYMBOL_NEXTFROMGERUND = 27,            /* NEXTFROMGERUND  */
  YYSYMBOL_COMPUCOME = 28,                 /* COMPUCOME  */
  YYSYMBOL_GERUCOME = 29,                  /* GERUCOME  */
  YYSYMBOL_PREPROC = 30,                   /* PREPROC  */
  YYSYMBOL_WHILE = 31,                     /* WHILE  */
  YYSYMBOL_TRY_AGAIN = 32,                 /* TRY_AGAIN  */
  YYSYMBOL_CREATE = 33,                    /* CREATE  */
  YYSYMBOL_COMPUCREATE = 34,               /* COMPUCREATE  */
  YYSYMBOL_FROM = 35,                      /* FROM  */
  YYSYMBOL_MAYBE = 36,                     /* MAYBE  */
  YYSYMBOL_DO = 37,                        /* DO  */
  YYSYMBOL_PLEASE = 38,                    /* PLEASE  */
  YYSYMBOL_NOT = 39,                       /* NOT  */
  YYSYMBOL_ONCE = 40,                      /* ONCE  */
  YYSYMBOL_AGAIN = 41,                     /* AGAIN  */
  YYSYMBOL_MESH = 42,                      /* MESH  */
  YYSYMBOL_NOSPOT = 43,                    /* NOSPOT  */
  YYSYMBOL_ick_ONESPOT = 44,               /* ick_ONESPOT  */
  YYSYMBOL_ick_TWOSPOT = 45,               /* ick_TWOSPOT  */
  YYSYMBOL_ick_TAIL = 46,                  /* ick_TAIL  */
  YYSYMBOL_ick_HYBRID = 47,                /* ick_HYBRID  */
  YYSYMBOL_MINGLE = 48,                    /* MINGLE  */
  YYSYMBOL_SELECT = 49,                    /* SELECT  */
  YYSYMBOL_UNKNOWNOP = 50,                 /* UNKNOWNOP  */
  YYSYMBOL_SUB = 51,                       /* SUB  */
  YYSYMBOL_BY = 52,                        /* BY  */
  YYSYMBOL_SLAT = 53,                      /* SLAT  */
  YYSYMBOL_BACKSLAT = 54,                  /* BACKSLAT  */
  YYSYMBOL_NUMBER = 55,                    /* NUMBER  */
  YYSYMBOL_UNARY = 56,                     /* UNARY  */
  YYSYMBOL_OHOHSEVEN = 57,                 /* OHOHSEVEN  */
  YYSYMBOL_GERUND = 58,                    /* GERUND  */
  YYSYMBOL_LABEL = 59,                     /* LABEL  */
  YYSYMBOL_BADCHAR = 60,                   /* BADCHAR  */
  YYSYMBOL_INTERSECTION = 61,              /* INTERSECTION  */
  YYSYMBOL_SPLATTERED = 62,                /* SPLATTERED  */
  YYSYMBOL_MESH32 = 63,                    /* MESH32  */
  YYSYMBOL_C_AND = 64,                     /* C_AND  */
  YYSYMBOL_C_OR = 65,                      /* C_OR  */
  YYSYMBOL_C_XOR = 66,                     /* C_XOR  */
  YYSYMBOL_C_NOT = 67,                     /* C_NOT  */
  YYSYMBOL_C_LOGICALNOT = 68,              /* C_LOGICALNOT  */
  YYSYMBOL_C_LSHIFTBY = 69,                /* C_LSHIFTBY  */
  YYSYMBOL_C_RSHIFTBY = 70,                /* C_RSHIFTBY  */
  YYSYMBOL_C_NOTEQUAL = 71,                /* C_NOTEQUAL  */
  YYSYMBOL_C_A = 72,                       /* C_A  */
  YYSYMBOL_C_PLUS = 73,                    /* C_PLUS  */
  YYSYMBOL_C_MINUS = 74,                   /* C_MINUS  */
  YYSYMBOL_C_TIMES = 75,                   /* C_TIMES  */
  YYSYMBOL_C_DIVIDEBY = 76,                /* C_DIVIDEBY  */
  YYSYMBOL_C_MODULUS = 77,                 /* C_MODULUS  */
  YYSYMBOL_C_GREATER = 78,                 /* C_GREATER  */
  YYSYMBOL_C_LESS = 79,                    /* C_LESS  */
  YYSYMBOL_C_ISEQUAL = 80,                 /* C_ISEQUAL  */
  YYSYMBOL_C_LOGICALAND = 81,              /* C_LOGICALAND  */
  YYSYMBOL_C_LOGICALOR = 82,               /* C_LOGICALOR  */
  YYSYMBOL_AND = 83,                       /* AND  */
  YYSYMBOL_OR = 84,                        /* OR  */
  YYSYMBOL_XOR = 85,                       /* XOR  */
  YYSYMBOL_FIN = 86,                       /* FIN  */
  YYSYMBOL_WHIRL = 87,                     /* WHIRL  */
  YYSYMBOL_WHIRL2 = 88,                    /* WHIRL2  */
  YYSYMBOL_WHIRL3 = 89,                    /* WHIRL3  */
  YYSYMBOL_WHIRL4 = 90,                    /* WHIRL4  */
  YYSYMBOL_WHIRL5 = 91,                    /* WHIRL5  */
  YYSYMBOL_REV_AND = 92,                   /* REV_AND  */
  YYSYMBOL_REV_OR = 93,                    /* REV_OR  */
  YYSYMBOL_REV_XOR = 94,                   /* REV_XOR  */
  YYSYMBOL_REV_FIN = 95,                   /* REV_FIN  */
  YYSYMBOL_REV_WHIRL = 96,                 /* REV_WHIRL  */
  YYSYMBOL_REV_WHIRL2 = 97,                /* REV_WHIRL2  */
  YYSYMBOL_REV_WHIRL3 = 98,                /* REV_WHIRL3  */
  YYSYMBOL_REV_WHIRL4 = 99,                /* REV_WHIRL4  */
  YYSYMBOL_REV_WHIRL5 = 100,               /* REV_WHIRL5  */
  YYSYMBOL_UNKNOWNID = 101,                /* UNKNOWNID  */
  YYSYMBOL_US_ID = 102,                    /* US_ID  */
  YYSYMBOL_US_SCALAR = 103,                /* US_SCALAR  */
  YYSYMBOL_US_ARRVAR = 104,                /* US_ARRVAR  */
  YYSYMBOL_US_ELEM = 105,                  /* US_ELEM  */
  YYSYMBOL_US_EXPR = 106,                  /* US_EXPR  */
  YYSYMBOL_OPENEARS = 107,                 /* OPENEARS  */
  YYSYMBOL_OPENSPARK = 108,                /* OPENSPARK  */
  YYSYMBOL_CLOSEEARS = 109,                /* CLOSEEARS  */
  YYSYMBOL_CLOSESPARK = 110,               /* CLOSESPARK  */
  YYSYMBOL_HIGHPREC = 111,                 /* HIGHPREC  */
  YYSYMBOL_UNARYPREC = 112,                /* UNARYPREC  */
  YYSYMBOL_LOWPREC = 113,                  /* LOWPREC  */
  YYSYMBOL_YYACCEPT = 114,                 /* $accept  */
  YYSYMBOL_program = 115,                  /* program  */
  YYSYMBOL_command = 116,                  /* command  */
  YYSYMBOL_mtperform = 117,                /* mtperform  */
  YYSYMBOL_preproc = 118,                  /* preproc  */
  YYSYMBOL_please = 119,                   /* please  */
  YYSYMBOL_perform = 120,                  /* perform  */
  YYSYMBOL_unknownstatement = 121,         /* unknownstatement  */
  YYSYMBOL_unknownsif = 122,               /* unknownsif  */
  YYSYMBOL_unknownsin = 123,               /* unknownsin  */
  YYSYMBOL_unknownatom = 124,              /* unknownatom  */
  YYSYMBOL_unknownaid = 125,               /* unknownaid  */
  YYSYMBOL_gerunds = 126,                  /* gerunds  */
  YYSYMBOL_variable = 127,                 /* variable  */
  YYSYMBOL_lvalue = 128,                   /* lvalue  */
  YYSYMBOL_scalar2s = 129,                 /* scalar2s  */
  YYSYMBOL_scalar = 130,                   /* scalar  */
  YYSYMBOL_ick_array = 131,                /* ick_array  */
  YYSYMBOL_oparray = 132,                  /* oparray  */
  YYSYMBOL_constant = 133,                 /* constant  */
  YYSYMBOL_varlist = 134,                  /* varlist  */
  YYSYMBOL_initem = 135,                   /* initem  */
  YYSYMBOL_inlist = 136,                   /* inlist  */
  YYSYMBOL_outitem = 137,                  /* outitem  */
  YYSYMBOL_outlist = 138,                  /* outlist  */
  YYSYMBOL_byexpr = 139,                   /* byexpr  */
  YYSYMBOL_subscr = 140,                   /* subscr  */
  YYSYMBOL_subscr1 = 141,                  /* subscr1  */
  YYSYMBOL_sublist = 142,                  /* sublist  */
  YYSYMBOL_sublist1 = 143,                 /* sublist1  */
  YYSYMBOL_osubscr = 144,                  /* osubscr  */
  YYSYMBOL_osubscr1 = 145,                 /* osubscr1  */
  YYSYMBOL_unop = 146,                     /* unop  */
  YYSYMBOL_expr = 147,                     /* expr  */
  YYSYMBOL_notanlvalue = 148,              /* notanlvalue  */
  YYSYMBOL_limexpr = 149,                  /* limexpr  */
  YYSYMBOL_preftype = 150,                 /* preftype  */
  YYSYMBOL_lunambig = 151,                 /* lunambig  */
  YYSYMBOL_limunambig = 152,               /* limunambig  */
  YYSYMBOL_nlunambig = 153,                /* nlunambig  */
  YYSYMBOL_unambig = 154,                  /* unambig  */
  YYSYMBOL_eitherspark = 155,              /* eitherspark  */
  YYSYMBOL_eitherears = 156                /* eitherears  */
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
#define YYLAST   663

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  114
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  145
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  230

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   368


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   168,   168,   169,   181,   183,   185,   187,   189,   204,
     206,   209,   226,   227,   266,   267,   268,   269,   273,   274,
     275,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   289,   291,   292,   293,   294,   295,   296,   297,   298,
     299,   300,   301,   304,   307,   309,   312,   315,   316,   319,
     321,   325,   327,   328,   333,   334,   336,   339,   340,   342,
     343,   348,   355,   362,   369,   372,   376,   378,   387,   387,
     389,   389,   391,   397,   403,   411,   417,   427,   435,   446,
     461,   462,   468,   468,   468,   469,   470,   475,   475,   475,
     475,   476,   477,   483,   484,   488,   489,   491,   493,   494,
     496,   497,   498,   502,   503,   506,   511,   516,   519,   520,
     521,   532,   537,   538,   542,   543,   544,   545,   546,   556,
     564,   565,   566,   567,   577,   582,   583,   587,   587,   587,
     592,   594,   616,   623,   632,   633,   636,   637,   640,   641,
     651,   652,   656,   657,   660,   661
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
  "\"end of file\"", "error", "\"invalid token\"", "UNKNOWN", "GETS",
  "RESIZE", "NEXT", "GO_AHEAD", "GO_BACK", "FORGET", "RESUME", "STASH",
  "RETRIEVE", "IGNORE", "REMEMBER", "ABSTAIN", "REINSTATE", "DISABLE",
  "ENABLE", "MANYFROM", "GIVE_UP", "READ_OUT", "WRITE_IN", "PIN",
  "COME_FROM", "NEXTFROMLABEL", "NEXTFROMEXPR", "NEXTFROMGERUND",
  "COMPUCOME", "GERUCOME", "PREPROC", "WHILE", "TRY_AGAIN", "CREATE",
  "COMPUCREATE", "FROM", "MAYBE", "DO", "PLEASE", "NOT", "ONCE", "AGAIN",
  "MESH", "NOSPOT", "ick_ONESPOT", "ick_TWOSPOT", "ick_TAIL", "ick_HYBRID",
  "MINGLE", "SELECT", "UNKNOWNOP", "SUB", "BY", "SLAT", "BACKSLAT",
  "NUMBER", "UNARY", "OHOHSEVEN", "GERUND", "LABEL", "BADCHAR",
  "INTERSECTION", "SPLATTERED", "MESH32", "C_AND", "C_OR", "C_XOR",
  "C_NOT", "C_LOGICALNOT", "C_LSHIFTBY", "C_RSHIFTBY", "C_NOTEQUAL", "C_A",
  "C_PLUS", "C_MINUS", "C_TIMES", "C_DIVIDEBY", "C_MODULUS", "C_GREATER",
  "C_LESS", "C_ISEQUAL", "C_LOGICALAND", "C_LOGICALOR", "AND", "OR", "XOR",
  "FIN", "WHIRL", "WHIRL2", "WHIRL3", "WHIRL4", "WHIRL5", "REV_AND",
  "REV_OR", "REV_XOR", "REV_FIN", "REV_WHIRL", "REV_WHIRL2", "REV_WHIRL3",
  "REV_WHIRL4", "REV_WHIRL5", "UNKNOWNID", "US_ID", "US_SCALAR",
  "US_ARRVAR", "US_ELEM", "US_EXPR", "OPENEARS", "OPENSPARK", "CLOSEEARS",
  "CLOSESPARK", "HIGHPREC", "UNARYPREC", "LOWPREC", "$accept", "program",
  "command", "mtperform", "preproc", "please", "perform",
  "unknownstatement", "unknownsif", "unknownsin", "unknownatom",
  "unknownaid", "gerunds", "variable", "lvalue", "scalar2s", "scalar",
  "ick_array", "oparray", "constant", "varlist", "initem", "inlist",
  "outitem", "outlist", "byexpr", "subscr", "subscr1", "sublist",
  "sublist1", "osubscr", "osubscr1", "unop", "expr", "notanlvalue",
  "limexpr", "preftype", "lunambig", "limunambig", "nlunambig", "unambig",
  "eitherspark", "eitherears", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-140)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-142)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -140,   129,  -140,  -140,   -31,   -25,     6,  -140,   290,  -140,
    -140,   362,  -140,  -140,  -140,   438,   438,   248,   248,   248,
     248,   152,   102,  -140,   283,   248,   -27,  -140,  -140,   457,
     457,  -140,   451,   438,   -34,   -32,   -29,    84,   128,   -17,
     432,    24,  -140,  -140,  -140,  -140,  -140,  -140,  -140,   149,
       5,   -51,   478,  -140,  -140,    48,   203,     9,    14,  -140,
      66,  -140,  -140,  -140,    69,    33,     8,  -140,  -140,    74,
     547,   553,   432,  -140,   -17,    41,    49,  -140,  -140,  -140,
    -140,    94,  -140,   -32,   -29,    43,    53,  -140,  -140,  -140,
      52,    52,    52,    52,   147,    83,  -140,  -140,    55,   -34,
    -140,    49,  -140,    59,  -140,  -140,  -140,    49,    67,  -140,
    -140,    77,  -140,    55,  -140,    55,  -140,  -140,   -51,   -15,
      49,  -140,  -140,  -140,   -51,    94,  -140,  -140,  -140,  -140,
      89,  -140,    91,  -140,   193,  -140,  -140,  -140,  -140,   432,
    -140,  -140,   438,   438,   438,   438,   438,   438,    95,   438,
     438,   438,   438,    71,  -140,  -140,    26,   226,   438,    60,
    -140,  -140,   438,   438,   438,   438,   248,  -140,    55,   162,
      99,   283,   248,  -140,  -140,   472,   438,  -140,  -140,  -140,
    -140,  -140,  -140,   100,   111,   125,  -140,  -140,  -140,  -140,
     171,  -140,  -140,  -140,  -140,  -140,  -140,  -140,    75,   438,
    -140,   438,   438,   438,    72,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,    55,  -140,  -140,  -140,   -51,   438,   438,   438,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     8,    16,    14,     0,     3,     0,    17,
      15,     0,    53,    38,    39,     0,     0,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,    41,    44,     0,
       0,    40,     0,     0,   127,   128,   129,     0,     0,     0,
       0,     0,    52,    65,   144,   142,   145,   143,     4,     9,
      12,    51,    56,    54,    59,     0,    62,    64,     0,   130,
      61,    95,   115,   103,    63,     0,   138,   140,   114,     0,
       0,     0,     0,     6,     0,   137,     0,   112,   113,    22,
     136,   107,    23,     0,     0,     0,     0,    80,    68,    69,
      24,    25,    26,    27,     0,     0,    66,    32,    33,     0,
      87,    90,    89,    92,    35,    88,    82,    84,    86,    34,
      83,     0,    36,    45,    46,    42,    43,   106,    47,    62,
      64,    61,    49,    63,     0,   107,    79,    73,    74,    75,
       0,    76,     0,   137,   139,     5,    21,    10,    11,     0,
      60,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   137,   125,   126,     0,   120,     0,     0,
       7,   141,     0,     0,     0,     0,     0,    28,    29,     0,
       0,     0,     0,    72,    48,    57,    50,    77,    78,    13,
      18,   119,    19,    94,     0,     0,   100,    96,    97,   101,
     102,   104,   105,    20,   131,   117,   116,   118,     0,     0,
     134,     0,     0,     0,     0,   135,   111,   109,   108,   110,
      81,    30,    31,    67,    91,    85,    58,     0,     0,     0,
      98,    99,   132,   124,   122,   121,   123,   133,    93,   102
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,  -140,    -5,  -140,   185,    64,   -28,  -140,  -140,
     157,   -46,   -10,    46,  -140,  -140,    -8,    29,   -63,   -23,
      57,  -140,    42,  -140,    54,    19,   101,   -41,  -139,  -131,
     218,   -39,   -40,    81,   -30,   178,  -140,    63,   164,  -140,
      47,  -140,  -140
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     7,    48,    49,     8,    50,    51,   174,    52,
      53,    54,    98,    87,    55,   112,    75,    76,    58,    59,
      90,   108,   109,   103,   104,   182,    77,    61,   187,   188,
      78,    63,   122,   183,    64,   156,    65,    80,    67,    68,
      81,    70,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,   102,   123,    56,   118,   140,    73,   191,     9,    88,
      88,    88,    88,   144,    10,   192,   100,   106,   111,   113,
     115,   126,   123,   127,   119,    34,   128,    35,    36,   151,
     136,   133,    56,  -137,  -137,   135,   139,    57,   143,    74,
      57,   165,     4,     5,   119,  -137,    89,    89,    89,    89,
      43,   220,   142,   101,   107,    69,  -136,  -136,    69,   221,
     145,   120,   153,   153,    56,   146,   133,   160,  -136,    57,
     -71,    66,   140,   147,    66,    91,    92,    93,   175,    69,
     125,   120,   185,   185,   168,   176,   134,    69,   192,   148,
      44,    45,    46,    47,   162,    66,    79,    82,   129,    69,
     145,    57,    95,    66,   186,   186,   189,   189,   131,    60,
     114,   116,    60,   166,   124,    66,   170,   203,   169,    69,
     171,   161,   149,   150,   199,   105,   110,   185,   172,     2,
       3,    56,   173,   121,   117,    66,   200,   133,   133,   129,
     130,    60,   163,   164,   177,   123,   178,   216,   102,   186,
     194,   189,   217,   121,   117,   185,   185,   213,    88,   212,
      96,    97,   218,   100,   106,     4,     5,   119,    57,   205,
     140,   154,   154,    60,   184,   184,   219,   186,   186,   189,
     189,   227,   133,   131,   132,   222,    69,    94,     6,   137,
     138,    11,   190,   190,    34,    89,    35,    36,    37,    38,
     101,   107,    66,   179,   120,    96,   167,   -70,    74,   141,
     133,   133,   210,    34,   215,    35,    36,    37,    38,   184,
      96,   211,    69,   180,   181,   214,    62,    74,   193,    62,
     195,   196,   197,   198,   157,   157,   228,   190,    66,   204,
      60,  -141,  -141,   206,   207,   208,   209,   184,   184,   159,
      62,  -137,  -137,  -141,     0,     0,   143,   209,    62,    44,
      45,    46,    47,  -137,     0,   229,   229,     0,     0,     0,
      62,     0,   105,   110,   201,   202,   121,     0,    44,    45,
     223,     0,   224,   225,   226,     0,   117,     0,   155,   155,
      62,    12,    83,    84,    85,    86,     0,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,     0,     0,     0,
      23,    24,    25,    26,    27,    28,    29,     0,    30,     0,
       0,     0,    31,    32,    33,    99,     0,    83,    84,    85,
      86,     0,    34,     0,    35,    36,    37,    38,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    40,     0,    41,
      42,     0,     0,     0,     0,     0,     0,    62,     0,     0,
       0,     0,     0,    12,     0,     0,     0,     0,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     0,
       0,     0,    23,    24,    25,    26,    27,    28,    29,     0,
      30,    43,     0,    62,    31,    32,    33,    44,    45,    46,
      47,     0,     0,     0,    34,     0,    35,    36,    37,    38,
       0,     0,     0,     0,     0,     0,     0,     0,    39,    72,
       0,    41,    42,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    12,     0,     0,     0,     0,     0,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,     0,
       0,     0,    23,    24,    25,    26,    27,    28,    29,     0,
      30,     0,     0,    43,    31,    32,    33,     0,     0,    44,
      45,    46,    47,     0,    34,     0,    35,    36,    37,    38,
      34,     0,    35,    36,    37,    38,     0,     0,    39,     0,
       0,    41,    42,    34,    74,    35,    36,    37,    38,    34,
       0,    35,    36,    37,    38,     0,     0,    39,     0,     0,
       0,   117,     0,    74,    34,    96,    35,    36,    37,    38,
      34,     0,    35,    36,    37,    38,     0,     0,    39,     0,
       0,     0,     0,    43,    39,     0,     0,     0,     0,    44,
      45,    46,    47,     0,     0,    44,    45,    46,    47,     0,
       0,     0,    43,     0,     0,     0,     0,     0,    44,    45,
      46,    47,     0,     0,    44,    45,    46,    47,     0,     0,
       0,     0,     0,    43,     0,     0,     0,     0,     0,    44,
      45,    46,    47,     0,     0,    44,    45,    46,    47,    34,
       0,    35,    36,    37,    38,    34,     0,    35,    36,    37,
      38,     0,     0,   152,     0,     0,     0,     0,     0,   158,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    45,    46,    47,     0,     0,
      44,    45,    46,    47
};

static const yytype_int16 yycheck[] =
{
       8,    24,    32,    11,    32,    51,    11,   146,    39,    17,
      18,    19,    20,     4,    39,   146,    24,    25,    45,    29,
      30,    55,    52,    55,    32,    42,    55,    44,    45,    69,
       6,    39,    40,    48,    49,    40,    31,     8,    53,    56,
      11,    81,    36,    37,    52,    60,    17,    18,    19,    20,
     101,   190,     4,    24,    25,     8,    48,    49,    11,   190,
      51,    32,    70,    71,    72,    51,    74,    72,    60,    40,
       4,     8,   118,     4,    11,    18,    19,    20,   124,    32,
      33,    52,   145,   146,    94,   125,    39,    40,   219,    56,
     107,   108,   109,   110,    53,    32,    15,    16,    55,    52,
      51,    72,    21,    40,   145,   146,   145,   146,    55,     8,
      29,    30,    11,    61,    33,    52,    61,   157,    35,    72,
      61,    74,    48,    49,    53,    24,    25,   190,    61,     0,
       1,   139,    55,    32,    60,    72,   110,   145,   146,    55,
      56,    40,    48,    49,    55,   175,    55,   175,   171,   190,
      55,   190,    52,    52,    60,   218,   219,    58,   166,   169,
      58,    59,    51,   171,   172,    36,    37,   175,   139,   109,
     216,    70,    71,    72,   145,   146,    51,   218,   219,   218,
     219,   109,   190,    55,    56,   110,   139,    35,    59,    40,
      41,     6,   145,   146,    42,   166,    44,    45,    46,    47,
     171,   172,   139,   139,   175,    58,    59,     4,    56,    52,
     218,   219,   166,    42,   172,    44,    45,    46,    47,   190,
      58,    59,   175,   142,   143,   171,     8,    56,   147,    11,
     149,   150,   151,   152,    70,    71,   217,   190,   175,   158,
     139,    48,    49,   162,   163,   164,   165,   218,   219,    71,
      32,    48,    49,    60,    -1,    -1,    53,   176,    40,   107,
     108,   109,   110,    60,    -1,   218,   219,    -1,    -1,    -1,
      52,    -1,   171,   172,    48,    49,   175,    -1,   107,   108,
     199,    -1,   201,   202,   203,    -1,    60,    -1,    70,    71,
      72,     1,    44,    45,    46,    47,    -1,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    25,    26,    -1,    28,    -1,
      -1,    -1,    32,    33,    34,    42,    -1,    44,    45,    46,
      47,    -1,    42,    -1,    44,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    -1,    59,
      60,    -1,    -1,    -1,    -1,    -1,    -1,   139,    -1,    -1,
      -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,   101,    -1,   175,    32,    33,    34,   107,   108,   109,
     110,    -1,    -1,    -1,    42,    -1,    44,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      -1,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    25,    26,    -1,
      28,    -1,    -1,   101,    32,    33,    34,    -1,    -1,   107,
     108,   109,   110,    -1,    42,    -1,    44,    45,    46,    47,
      42,    -1,    44,    45,    46,    47,    -1,    -1,    56,    -1,
      -1,    59,    60,    42,    56,    44,    45,    46,    47,    42,
      -1,    44,    45,    46,    47,    -1,    -1,    56,    -1,    -1,
      -1,    60,    -1,    56,    42,    58,    44,    45,    46,    47,
      42,    -1,    44,    45,    46,    47,    -1,    -1,    56,    -1,
      -1,    -1,    -1,   101,    56,    -1,    -1,    -1,    -1,   107,
     108,   109,   110,    -1,    -1,   107,   108,   109,   110,    -1,
      -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,   107,   108,
     109,   110,    -1,    -1,   107,   108,   109,   110,    -1,    -1,
      -1,    -1,    -1,   101,    -1,    -1,    -1,    -1,    -1,   107,
     108,   109,   110,    -1,    -1,   107,   108,   109,   110,    42,
      -1,    44,    45,    46,    47,    42,    -1,    44,    45,    46,
      47,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   107,   108,   109,   110,    -1,    -1,
     107,   108,   109,   110
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   115,     0,     1,    36,    37,    59,   116,   119,    39,
      39,   119,     1,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    20,    21,    22,    23,    24,    25,    26,
      28,    32,    33,    34,    42,    44,    45,    46,    47,    56,
      57,    59,    60,   101,   107,   108,   109,   110,   117,   118,
     120,   121,   123,   124,   125,   128,   130,   131,   132,   133,
     140,   141,   144,   145,   148,   150,   151,   152,   153,   154,
     155,   156,    57,   117,    56,   130,   131,   140,   144,   147,
     151,   154,   147,    44,    45,    46,    47,   127,   130,   131,
     134,   134,   134,   134,    35,   147,    58,    59,   126,    42,
     130,   131,   133,   137,   138,   140,   130,   131,   135,   136,
     140,    45,   129,   126,   147,   126,   147,    60,   121,   130,
     131,   140,   146,   148,   147,   154,    55,    55,    55,    55,
      56,    55,    56,   130,   154,   117,     6,    40,    41,    31,
     125,   124,     4,    53,     4,    51,    51,     4,    56,    48,
      49,   146,    56,   130,   140,   144,   149,   152,    56,   149,
     117,   154,    53,    48,    49,   146,    61,    59,   126,    35,
      61,    61,    61,    55,   122,   125,   146,    55,    55,   120,
     147,   147,   139,   147,   131,   132,   141,   142,   143,   145,
     154,   142,   143,   147,    55,   147,   147,   147,   147,    53,
     110,    48,    49,   146,   147,   109,   147,   147,   147,   147,
     127,    59,   126,    58,   138,   136,   121,    52,    51,    51,
     142,   143,   110,   147,   147,   147,   147,   109,   139,   154
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,   114,   115,   115,   116,   116,   116,   116,   116,   117,
     117,   117,   118,   118,   119,   119,   119,   119,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   121,   121,   121,   122,   122,   123,
     123,   124,   124,   124,   124,   125,   126,   126,   127,   127,
     128,   128,   129,   130,   130,   131,   131,   132,   132,   133,
     134,   134,   135,   135,   135,   136,   136,   137,   137,   137,
     137,   138,   138,   139,   139,   140,   140,   141,   142,   142,
     143,   143,   143,   144,   144,   145,   146,   147,   147,   147,
     147,   147,   147,   147,   148,   148,   148,   148,   148,   148,
     149,   149,   149,   149,   149,   149,   149,   150,   150,   150,
     151,   151,   151,   151,   151,   151,   152,   152,   153,   153,
     154,   154,   155,   155,   156,   156
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     2,     3,     3,     4,     1,     1,
       2,     2,     1,     3,     1,     2,     1,     2,     3,     3,
       3,     2,     2,     2,     2,     2,     2,     2,     3,     3,
       4,     4,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     2,     2,     1,     2,     2,     2,     3,     2,
       3,     1,     1,     1,     1,     2,     1,     1,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     3,     3,     2,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     3,     1,     3,     1,     1,     3,     3,     2,     2,
       1,     1,     1,     1,     3,     3,     1,     1,     3,     3,
       3,     3,     1,     1,     1,     1,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     3,     4,     4,     3,     3,     1,     1,     1,     2,
       1,     2,     1,     1,     1,     1
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
  case 4: /* command: please mtperform  */
#line 182 "parser.y"
                {(yyvsp[0].tuple)->label = 0; (yyvsp[0].tuple)->exechance = (yyvsp[-1].numval) * 100;}
#line 1811 "parser.c"
    break;

  case 5: /* command: please OHOHSEVEN mtperform  */
#line 184 "parser.y"
                {(yyvsp[0].tuple)->label = 0; (yyvsp[0].tuple)->exechance = (yyvsp[-2].numval) * (yyvsp[-1].numval);}
#line 1817 "parser.c"
    break;

  case 6: /* command: LABEL please mtperform  */
#line 186 "parser.y"
                {checklabel((yyvsp[-2].numval)); (yyvsp[0].tuple)->label = (yyvsp[-2].numval); (yyvsp[0].tuple)->exechance = (yyvsp[-1].numval) * 100;}
#line 1823 "parser.c"
    break;

  case 7: /* command: LABEL please OHOHSEVEN mtperform  */
#line 188 "parser.y"
                {checklabel((yyvsp[-3].numval)); (yyvsp[0].tuple)->label = (yyvsp[-3].numval); (yyvsp[0].tuple)->exechance = (yyvsp[-2].numval) * (yyvsp[-1].numval);}
#line 1829 "parser.c"
    break;

  case 8: /* command: error  */
#line 190 "parser.y"
                {/* AIS: catch errors which occur after the end of a statement
		    (highly likely when comments are being written, as the
		    start of them will be parsed as an UNKNOWN) */
		  yyerrok; yyclearin; cacsofar=0;
		  if(prevtuple) {prevtuple->type=SPLATTERED; splat(0);}
		  else splat(1); /* this is the first statement */
		}
#line 1841 "parser.c"
    break;

  case 9: /* mtperform: preproc  */
#line 205 "parser.y"
                {(yyvsp[0].tuple)->onceagainflag = onceagain_NORMAL; prevtuple = (yyval.tuple) = (yyvsp[0].tuple);}
#line 1847 "parser.c"
    break;

  case 10: /* mtperform: preproc ONCE  */
#line 207 "parser.y"
                {NEWFANGLED {(yyvsp[-1].tuple)->onceagainflag = onceagain_ONCE;
			     prevtuple = (yyval.tuple) = (yyvsp[-1].tuple);}}
#line 1854 "parser.c"
    break;

  case 11: /* mtperform: preproc AGAIN  */
#line 210 "parser.y"
                {NEWFANGLED {(yyvsp[-1].tuple)->onceagainflag = onceagain_AGAIN;
			     prevtuple = (yyval.tuple) = (yyvsp[-1].tuple);}}
#line 1861 "parser.c"
    break;

  case 12: /* preproc: perform  */
#line 226 "parser.y"
                  {(yyval.tuple) = (yyvsp[0].tuple);}
#line 1867 "parser.c"
    break;

  case 13: /* preproc: perform WHILE perform  */
#line 228 "parser.y"
{
  if(!multithread) ick_lose(IE405, iyylineno, (char*)NULL);
  NEWFANGLED{
  /*	(x)  DO a WHILE b
    is equivalent to
    #11 (l0) DO REINSTATE (l3) <weave on>
    #10 (l1) DO COME FROM (l2) AGAIN
     #9	     DO b
     #8	     DO COME FROM (l0)
     #7	     DO NOTHING
     #6	     DO NOTHING
     #5 (l2) DO NOTHING
     #4	     DO GIVE UP
     #3	     DO COME FROM (l0)
     #2 (x)  DO a
     #1 (l3) DON'T ABSTAIN FROM (l1) AGAIN <weave off> */
  tuple* temptuple;
  TARGET(temptuple, COME_FROM, lineuid+2);
  temptuple->label=lineuid+1; temptuple->preproc=1; /* #10 */
  TARGET(temptuple, COME_FROM, lineuid+0); temptuple->preproc=1; /* #8 */
  ACTION(temptuple, PREPROC, 0); temptuple->preproc=1; /* #7 */
  ACTION(temptuple, PREPROC, 0); temptuple->preproc=1; /* #6 */
  ACTION(temptuple, PREPROC, 0);
  temptuple->label=lineuid+2; temptuple->preproc=1; /* #5 */
  ACTION(temptuple, GIVE_UP, 0); temptuple->preproc=1; /* #4 */
  TARGET(temptuple, COME_FROM, lineuid+0); temptuple->preproc=1; /* #3 */
  TARGET(temptuple, REINSTATE, lineuid+3); temptuple->setweave=1;
  temptuple->label=lineuid+0; temptuple->preproc=1; /* #11 */
  TARGET(temptuple, ABSTAIN, lineuid+1); temptuple->label=lineuid+3; /* #1 */
  temptuple->preproc=1; temptuple->setweave=-1; temptuple->exechance=-100; 
  politesse += 3; /* Keep the politeness checker happy */
  ppinit(11); tupleswap(10,9); tupleswap(11,2); lineuid+=4; /* #2, #9 */
  tuples[ick_lineno-10].onceagainflag=onceagain_AGAIN;
  tuples[ick_lineno-1].onceagainflag=onceagain_AGAIN;
  (yyval.tuple)=&(tuples[ick_lineno-2]);
}}
#line 1908 "parser.c"
    break;

  case 14: /* please: DO  */
#line 266 "parser.y"
                                {GETLINENO; (yyval.numval) = 1;}
#line 1914 "parser.c"
    break;

  case 15: /* please: DO NOT  */
#line 267 "parser.y"
                                {GETLINENO; (yyval.numval) = -1;}
#line 1920 "parser.c"
    break;

  case 16: /* please: MAYBE  */
#line 268 "parser.y"
                                {NEWFANGLED {GETLINENO; (yyval.numval) = 101;}}
#line 1926 "parser.c"
    break;

  case 17: /* please: MAYBE NOT  */
#line 269 "parser.y"
                                {NEWFANGLED {GETLINENO; (yyval.numval) = -101;}}
#line 1932 "parser.c"
    break;

  case 18: /* perform: lvalue GETS expr  */
#line 273 "parser.y"
                                {ACTION((yyval.tuple), GETS,      cons(GETS,(yyvsp[-2].node),(yyvsp[0].node)));}
#line 1938 "parser.c"
    break;

  case 19: /* perform: ick_array GETS byexpr  */
#line 274 "parser.y"
                                        {ACTION((yyval.tuple), RESIZE,    cons(RESIZE,(yyvsp[-2].node),(yyvsp[0].node)));}
#line 1944 "parser.c"
    break;

  case 20: /* perform: notanlvalue GETS expr  */
#line 276 "parser.y"
          {/* AIS: This is for variableconstants, and an error otherwise.*/
	   if(variableconstants) ACTION((yyval.tuple), GETS, cons(GETS,(yyvsp[-2].node),(yyvsp[0].node)))
	     else {yyerrok; yyclearin; (yyval.tuple)=splat(1);}}
#line 1952 "parser.c"
    break;

  case 21: /* perform: LABEL NEXT  */
#line 279 "parser.y"
                                {TARGET((yyval.tuple), NEXT,      (yyvsp[-1].numval));}
#line 1958 "parser.c"
    break;

  case 22: /* perform: FORGET expr  */
#line 280 "parser.y"
                                {ACTION((yyval.tuple), FORGET,    (yyvsp[0].node));}
#line 1964 "parser.c"
    break;

  case 23: /* perform: RESUME expr  */
#line 281 "parser.y"
                                {ACTION((yyval.tuple), RESUME,    (yyvsp[0].node));}
#line 1970 "parser.c"
    break;

  case 24: /* perform: STASH varlist  */
#line 282 "parser.y"
                                {ACTION((yyval.tuple), STASH,     rlist);}
#line 1976 "parser.c"
    break;

  case 25: /* perform: RETRIEVE varlist  */
#line 283 "parser.y"
                                {ACTION((yyval.tuple), RETRIEVE,  rlist);}
#line 1982 "parser.c"
    break;

  case 26: /* perform: IGNORE varlist  */
#line 284 "parser.y"
                                {ACTION((yyval.tuple), IGNORE,    rlist);}
#line 1988 "parser.c"
    break;

  case 27: /* perform: REMEMBER varlist  */
#line 285 "parser.y"
                                {ACTION((yyval.tuple), REMEMBER,  rlist);}
#line 1994 "parser.c"
    break;

  case 28: /* perform: ABSTAIN FROM LABEL  */
#line 286 "parser.y"
                                {stbeginline=0; TARGET((yyval.tuple), ABSTAIN,   (yyvsp[0].numval));}
#line 2000 "parser.c"
    break;

  case 29: /* perform: ABSTAIN FROM gerunds  */
#line 287 "parser.y"
                                        {ACTION((yyval.tuple), DISABLE,   rlist);}
#line 2006 "parser.c"
    break;

  case 30: /* perform: ABSTAIN expr FROM LABEL  */
#line 288 "parser.y"
                                     {/* AIS */ NEWFANGLED {stbeginline=0; ACTARGET((yyval.tuple), FROM, (yyvsp[-2].node), (yyvsp[0].numval));}}
#line 2012 "parser.c"
    break;

  case 31: /* perform: ABSTAIN expr FROM gerunds  */
#line 289 "parser.y"
                                       {/* AIS */ NEWFANGLED {(yyval.tuple) = newtuple(); (yyval.tuple)->type = MANYFROM; (yyval.tuple)->ick_lineno = thisline; \
	  {node* tempnode=newnode(); (yyval.tuple)->u.node = tempnode; tempnode->lval=(yyvsp[-2].node); tempnode->rval=rlist; tempnode->opcode=MANYFROM;}}}
#line 2019 "parser.c"
    break;

  case 32: /* perform: REINSTATE LABEL  */
#line 291 "parser.y"
                                {stbeginline=0; TARGET((yyval.tuple), REINSTATE, (yyvsp[0].numval));}
#line 2025 "parser.c"
    break;

  case 33: /* perform: REINSTATE gerunds  */
#line 292 "parser.y"
                                {ACTION((yyval.tuple), ENABLE,    rlist);}
#line 2031 "parser.c"
    break;

  case 34: /* perform: WRITE_IN inlist  */
#line 293 "parser.y"
                                {ACTION((yyval.tuple), WRITE_IN,  (yyvsp[0].node));}
#line 2037 "parser.c"
    break;

  case 35: /* perform: READ_OUT outlist  */
#line 294 "parser.y"
                                {ACTION((yyval.tuple), READ_OUT,  (yyvsp[0].node));}
#line 2043 "parser.c"
    break;

  case 36: /* perform: PIN scalar2s  */
#line 295 "parser.y"
                                {ACTION((yyval.tuple), PIN,       (yyvsp[0].node));}
#line 2049 "parser.c"
    break;

  case 37: /* perform: GIVE_UP  */
#line 296 "parser.y"
                                {ACTION((yyval.tuple), GIVE_UP,   0);}
#line 2055 "parser.c"
    break;

  case 38: /* perform: GO_AHEAD  */
#line 297 "parser.y"
                                {/* AIS */ NEWFANGLED {ACTION((yyval.tuple), GO_AHEAD,  0);}}
#line 2061 "parser.c"
    break;

  case 39: /* perform: GO_BACK  */
#line 298 "parser.y"
                                {/* AIS */ NEWFANGLED {ACTION((yyval.tuple), GO_BACK,   0);}}
#line 2067 "parser.c"
    break;

  case 40: /* perform: TRY_AGAIN  */
#line 299 "parser.y"
                                {/* AIS */ NEWFANGLED {ACTION((yyval.tuple),TRY_AGAIN,0);}}
#line 2073 "parser.c"
    break;

  case 41: /* perform: COME_FROM  */
#line 300 "parser.y"
                                {/* AIS: Modified */ NEWFANGLED {TARGET((yyval.tuple),COME_FROM,(yyvsp[0].numval));}}
#line 2079 "parser.c"
    break;

  case 42: /* perform: COMPUCOME gerunds  */
#line 301 "parser.y"
                                {/* AIS: COME FROM gerund */
				 NEWFANGLED{ACTION((yyval.tuple),GERUCOME,rlist);
				 compucomesused=1; gerucomesused=1;}}
#line 2087 "parser.c"
    break;

  case 43: /* perform: COMPUCOME expr  */
#line 304 "parser.y"
                                {/* AIS */NEWFANGLED {ACTION((yyval.tuple),COMPUCOME,(yyvsp[0].node));
				 compucomesused=1;}}
#line 2094 "parser.c"
    break;

  case 44: /* perform: NEXTFROMLABEL  */
#line 307 "parser.y"
                                {NEWFANGLED {TARGET((yyval.tuple),NEXTFROMLABEL,(yyvsp[0].numval));}
				 nextfromsused=1;}
#line 2101 "parser.c"
    break;

  case 45: /* perform: NEXTFROMEXPR gerunds  */
#line 309 "parser.y"
                                 {NEWFANGLED{ACTION((yyval.tuple),NEXTFROMGERUND,rlist);
				 compucomesused=1; gerucomesused=1;}
				 nextfromsused=1;}
#line 2109 "parser.c"
    break;

  case 46: /* perform: NEXTFROMEXPR expr  */
#line 312 "parser.y"
                                {NEWFANGLED {ACTION((yyval.tuple),NEXTFROMEXPR,(yyvsp[0].node));
				 compucomesused=1; nextfromsused=1;}}
#line 2116 "parser.c"
    break;

  case 47: /* perform: CREATE unknownstatement  */
#line 315 "parser.y"
                                     {NEWFANGLED{ACTARGET((yyval.tuple),CREATE,(yyvsp[0].node),(yyvsp[-1].numval)); cacsofar=0;}}
#line 2122 "parser.c"
    break;

  case 48: /* perform: COMPUCREATE expr unknownsif  */
#line 316 "parser.y"
                                         {NEWFANGLED{ACTION((yyval.tuple),COMPUCREATE,
					     cons(INTERSECTION,(yyvsp[-1].node),(yyvsp[0].node))); cacsofar=0;}}
#line 2129 "parser.c"
    break;

  case 49: /* perform: CREATE unop  */
#line 319 "parser.y"
                                {NEWFANGLED{ACTARGET((yyval.tuple),CREATE,(yyvsp[0].node),(yyvsp[-1].numval));
                                 cacsofar=0;}}
#line 2136 "parser.c"
    break;

  case 50: /* perform: COMPUCREATE unambig unop  */
#line 322 "parser.y"
                                {NEWFANGLED{ACTION((yyval.tuple),COMPUCREATE,
				 cons(INTERSECTION,(yyvsp[-1].node),(yyvsp[0].node))); cacsofar=0;}}
#line 2143 "parser.c"
    break;

  case 51: /* perform: unknownstatement  */
#line 325 "parser.y"
                                {NEWFANGLED {ACTION((yyval.tuple),UNKNOWN,(yyvsp[0].node)); cacsofar=0;}}
#line 2149 "parser.c"
    break;

  case 52: /* perform: BADCHAR  */
#line 327 "parser.y"
                                {yyclearin; yyerrok; (yyval.tuple) = splat(1); cacsofar=0;}
#line 2155 "parser.c"
    break;

  case 53: /* perform: error  */
#line 328 "parser.y"
                                {yyclearin; yyerrok; (yyval.tuple) = splat(1); cacsofar=0;}
#line 2161 "parser.c"
    break;

  case 54: /* unknownstatement: unknownatom  */
#line 333 "parser.y"
                               {(yyval.node) = (yyvsp[0].node); intern(ick_TWOSPOT,cacsofar+++1601);}
#line 2167 "parser.c"
    break;

  case 55: /* unknownstatement: unknownsin unknownatom  */
#line 334 "parser.y"
                                          {(yyval.node)=cons(INTERSECTION,(yyvsp[-1].node),(yyvsp[0].node));
					   intern(ick_TWOSPOT,cacsofar+++1601);}
#line 2174 "parser.c"
    break;

  case 56: /* unknownstatement: unknownsin  */
#line 336 "parser.y"
                              {(yyval.node) = (yyvsp[0].node);}
#line 2180 "parser.c"
    break;

  case 57: /* unknownsif: unknownaid  */
#line 339 "parser.y"
                              {(yyval.node) = (yyvsp[0].node);}
#line 2186 "parser.c"
    break;

  case 58: /* unknownsif: unknownaid unknownstatement  */
#line 340 "parser.y"
                                               {(yyval.node)=cons(INTERSECTION,(yyvsp[-1].node),(yyvsp[0].node));}
#line 2192 "parser.c"
    break;

  case 59: /* unknownsin: unknownaid  */
#line 342 "parser.y"
                              {(yyval.node) = (yyvsp[0].node);}
#line 2198 "parser.c"
    break;

  case 60: /* unknownsin: unknownstatement unknownaid  */
#line 343 "parser.y"
                                               {(yyval.node)=cons(INTERSECTION,(yyvsp[-1].node),(yyvsp[0].node));}
#line 2204 "parser.c"
    break;

  case 61: /* unknownatom: subscr  */
#line 348 "parser.y"
                                {(yyval.node)=cons(US_ELEM,0,(yyvsp[0].node));
				   if(createsused){
				     opoverused=1; if(!firstslat)
				       firstslat=(yyvsp[0].node); else
				       prevslat->nextslat=(yyvsp[0].node);
				     prevslat=(yyvsp[0].node);
				     (yyvsp[0].node)->nextslat=0;}}
#line 2216 "parser.c"
    break;

  case 62: /* unknownatom: scalar  */
#line 355 "parser.y"
                                {(yyval.node)=cons(US_SCALAR,0,(yyvsp[0].node));
				   if(createsused){
				     opoverused=1; if(!firstslat)
				       firstslat=(yyvsp[0].node); else
				       prevslat->nextslat=(yyvsp[0].node);
				     prevslat=(yyvsp[0].node);
				     (yyvsp[0].node)->nextslat=0;}}
#line 2228 "parser.c"
    break;

  case 63: /* unknownatom: notanlvalue  */
#line 362 "parser.y"
                                {(yyval.node)=cons(US_EXPR,0,(yyvsp[0].node));
				   if(createsused){
				     opoverused=1; if(!firstslat)
				       firstslat=(yyvsp[0].node); else
				       prevslat->nextslat=(yyvsp[0].node);
				     prevslat=(yyvsp[0].node);
				     (yyvsp[0].node)->nextslat=0;}}
#line 2240 "parser.c"
    break;

  case 64: /* unknownatom: ick_array  */
#line 369 "parser.y"
                                {(yyval.node)=cons(US_ARRVAR,0,(yyvsp[0].node));}
#line 2246 "parser.c"
    break;

  case 65: /* unknownaid: UNKNOWNID  */
#line 372 "parser.y"
                                {(yyval.node)=newnode(); (yyval.node)->opcode=US_ID; (yyval.node)->constant=(yyvsp[0].numval);}
#line 2252 "parser.c"
    break;

  case 66: /* gerunds: GERUND  */
#line 377 "parser.y"
                {rlist = np = newnode(); np->constant = (yyvsp[0].numval);}
#line 2258 "parser.c"
    break;

  case 67: /* gerunds: gerunds INTERSECTION GERUND  */
#line 379 "parser.y"
                {
		    np->rval = newnode();
		    np = np->rval;
		    np->constant = (yyvsp[0].numval);
		}
#line 2268 "parser.c"
    break;

  case 72: /* scalar2s: ick_TWOSPOT NUMBER  */
#line 392 "parser.y"
                {
		  (yyval.node) = newnode();
		  (yyval.node)->opcode = ick_TWOSPOT;
		  (yyval.node)->constant = intern(ick_TWOSPOT, (yyvsp[0].numval));
		}
#line 2278 "parser.c"
    break;

  case 73: /* scalar: ick_ONESPOT NUMBER  */
#line 398 "parser.y"
                {
		    (yyval.node) = newnode();
		    (yyval.node)->opcode = ick_ONESPOT;
		    (yyval.node)->constant = intern(ick_ONESPOT, (yyvsp[0].numval));
		}
#line 2288 "parser.c"
    break;

  case 74: /* scalar: ick_TWOSPOT NUMBER  */
#line 404 "parser.y"
                {
		    (yyval.node) = newnode();
		    (yyval.node)->opcode = ick_TWOSPOT;
		    (yyval.node)->constant = intern(ick_TWOSPOT, (yyvsp[0].numval));
		}
#line 2298 "parser.c"
    break;

  case 75: /* ick_array: ick_TAIL NUMBER  */
#line 412 "parser.y"
                {
		    (yyval.node) = newnode();
		    (yyval.node)->opcode = ick_TAIL;
		    (yyval.node)->constant = intern(ick_TAIL, (yyvsp[0].numval));
		}
#line 2308 "parser.c"
    break;

  case 76: /* ick_array: ick_HYBRID NUMBER  */
#line 418 "parser.y"
                {
		    (yyval.node) = newnode();
		    (yyval.node)->opcode = ick_HYBRID;
		    (yyval.node)->constant = intern(ick_HYBRID, (yyvsp[0].numval));
		}
#line 2318 "parser.c"
    break;

  case 77: /* oparray: ick_TAIL UNARY NUMBER  */
#line 428 "parser.y"
                {
		    (yyval.node) = newnode();
		    (yyval.node)->opcode = (yyvsp[-1].numval);
		    (yyval.node)->rval = newnode();
		    (yyval.node)->rval->opcode = ick_TAIL;
		    (yyval.node)->rval->constant = intern(ick_TAIL, (yyvsp[0].numval));
		}
#line 2330 "parser.c"
    break;

  case 78: /* oparray: ick_HYBRID UNARY NUMBER  */
#line 436 "parser.y"
                {
		    (yyval.node) = newnode();
		    (yyval.node)->opcode = (yyvsp[-1].numval);
		    (yyval.node)->rval = newnode();
		    (yyval.node)->rval->opcode = ick_HYBRID;
		    (yyval.node)->rval->constant = intern(ick_HYBRID, (yyvsp[0].numval));
		}
#line 2342 "parser.c"
    break;

  case 79: /* constant: MESH NUMBER  */
#line 447 "parser.y"
                {
		    /* enforce the 16-bit constant constraint */
		    if ((unsigned int)(yyvsp[0].numval) > ick_Max_small)
			ick_lose(IE017, iyylineno, (char *)NULL);
		    (yyval.node) = newnode();
		    (yyval.node)->opcode = MESH;
		    if(variableconstants) /* AIS */
		      (yyval.node)->constant = intern(MESH, (yyvsp[0].numval));
		    else
		      (yyval.node)->constant = (yyvsp[0].numval);
		}
#line 2358 "parser.c"
    break;

  case 80: /* varlist: variable  */
#line 461 "parser.y"
                                                {rlist = np = (yyvsp[0].node);}
#line 2364 "parser.c"
    break;

  case 81: /* varlist: varlist INTERSECTION variable  */
#line 462 "parser.y"
                                                {np = np->rval = (yyvsp[0].node);
							/* newnode(); */ }
#line 2371 "parser.c"
    break;

  case 85: /* inlist: initem INTERSECTION inlist  */
#line 469 "parser.y"
                                                {(yyval.node)=cons(INTERSECTION,(yyvsp[-2].node),(yyvsp[0].node));}
#line 2377 "parser.c"
    break;

  case 86: /* inlist: initem  */
#line 470 "parser.y"
                                                {(yyval.node)=cons(INTERSECTION,(yyvsp[0].node),0);}
#line 2383 "parser.c"
    break;

  case 91: /* outlist: outitem INTERSECTION outlist  */
#line 476 "parser.y"
                                                {(yyval.node)=cons(INTERSECTION,(yyvsp[-2].node),(yyvsp[0].node));}
#line 2389 "parser.c"
    break;

  case 92: /* outlist: outitem  */
#line 477 "parser.y"
                                                {(yyval.node)=cons(INTERSECTION,(yyvsp[0].node),0);}
#line 2395 "parser.c"
    break;

  case 93: /* byexpr: expr BY byexpr  */
#line 483 "parser.y"
                                        {(yyval.node) = cons(BY, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2401 "parser.c"
    break;

  case 94: /* byexpr: expr  */
#line 484 "parser.y"
                                        {(yyval.node) = cons(BY, (yyvsp[0].node), 0);}
#line 2407 "parser.c"
    break;

  case 95: /* subscr: subscr1  */
#line 488 "parser.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 2413 "parser.c"
    break;

  case 96: /* subscr: ick_array SUB sublist  */
#line 489 "parser.y"
                                                {(yyval.node) = cons(SUB, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2419 "parser.c"
    break;

  case 97: /* subscr1: ick_array SUB sublist1  */
#line 491 "parser.y"
                                                {(yyval.node) = cons(SUB, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2425 "parser.c"
    break;

  case 98: /* sublist: unambig sublist  */
#line 493 "parser.y"
                                        {(yyval.node) = cons(INTERSECTION, (yyvsp[-1].node), (yyvsp[0].node));}
#line 2431 "parser.c"
    break;

  case 99: /* sublist: unambig sublist1  */
#line 494 "parser.y"
                                        {(yyval.node) = cons(INTERSECTION, (yyvsp[-1].node), (yyvsp[0].node));}
#line 2437 "parser.c"
    break;

  case 100: /* sublist1: subscr1  */
#line 496 "parser.y"
                                        {(yyval.node) = cons(INTERSECTION, (yyvsp[0].node), 0);}
#line 2443 "parser.c"
    break;

  case 101: /* sublist1: osubscr1  */
#line 497 "parser.y"
                                        {(yyval.node) = cons(INTERSECTION, (yyvsp[0].node), 0);}
#line 2449 "parser.c"
    break;

  case 102: /* sublist1: unambig  */
#line 498 "parser.y"
                                        {(yyval.node) = cons(INTERSECTION, (yyvsp[0].node), 0);}
#line 2455 "parser.c"
    break;

  case 103: /* osubscr: osubscr1  */
#line 502 "parser.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 2461 "parser.c"
    break;

  case 104: /* osubscr: oparray SUB sublist  */
#line 504 "parser.y"
                {(yyval.node) = (yyvsp[-2].node); (yyval.node)->rval = cons(SUB, (yyval.node)->rval, (yyvsp[0].node));}
#line 2467 "parser.c"
    break;

  case 105: /* osubscr1: oparray SUB sublist1  */
#line 507 "parser.y"
                {(yyval.node) = (yyvsp[-2].node); (yyval.node)->rval = cons(SUB, (yyval.node)->rval, (yyvsp[0].node));}
#line 2473 "parser.c"
    break;

  case 106: /* unop: BADCHAR  */
#line 511 "parser.y"
                                        {(yyval.node) = newnode(); (yyval.node)->opcode = BADCHAR;
					 (yyval.node)->constant = (yyvsp[0].numval);}
#line 2480 "parser.c"
    break;

  case 107: /* expr: unambig  */
#line 516 "parser.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 2486 "parser.c"
    break;

  case 108: /* expr: unambig SELECT expr  */
#line 519 "parser.y"
                                        {(yyval.node) = cons(SELECT, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2492 "parser.c"
    break;

  case 109: /* expr: unambig MINGLE expr  */
#line 520 "parser.y"
                                        {(yyval.node) = cons(MINGLE, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2498 "parser.c"
    break;

  case 110: /* expr: unambig unop expr  */
#line 521 "parser.y"
                                        {(yyval.node) = cons(UNKNOWNOP, (yyvsp[-1].node),
					 cons(INTERSECTION, (yyvsp[-2].node), (yyvsp[0].node)));
   					 if(useickec && createsused) {
					  if(!firstslat) firstslat=(yyvsp[-2].node);
                                          else prevslat->nextslat=(yyvsp[-2].node);
				     	  (yyvsp[-2].node)->nextslat=(yyvsp[0].node); prevslat=(yyvsp[0].node);
					  (yyvsp[0].node)->nextslat=0; opoverused=1;
  					  intern(ick_TWOSPOT, 1601);
					  intern(ick_TWOSPOT, 1602);
					  intern(ick_TWOSPOT, 1603);}}
#line 2513 "parser.c"
    break;

  case 111: /* expr: scalar SLAT expr  */
#line 532 "parser.y"
                                        {NEWFANGLED{(yyval.node) = cons(SLAT, (yyvsp[-2].node), (yyvsp[0].node));
					 opoverused=1; if(!firstslat)
					 firstslat=(yyvsp[0].node); else
					 prevslat->nextslat=(yyvsp[0].node); prevslat=(yyvsp[0].node);
					 (yyvsp[0].node)->nextslat=0;}}
#line 2523 "parser.c"
    break;

  case 112: /* expr: subscr  */
#line 537 "parser.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 2529 "parser.c"
    break;

  case 113: /* expr: osubscr  */
#line 538 "parser.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 2535 "parser.c"
    break;

  case 114: /* notanlvalue: nlunambig  */
#line 542 "parser.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 2541 "parser.c"
    break;

  case 115: /* notanlvalue: osubscr  */
#line 543 "parser.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 2547 "parser.c"
    break;

  case 116: /* notanlvalue: unambig SELECT expr  */
#line 544 "parser.y"
                                        {(yyval.node) = cons(SELECT, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2553 "parser.c"
    break;

  case 117: /* notanlvalue: unambig MINGLE expr  */
#line 545 "parser.y"
                                        {(yyval.node) = cons(MINGLE, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2559 "parser.c"
    break;

  case 118: /* notanlvalue: unambig unop expr  */
#line 546 "parser.y"
                                        {(yyval.node) = cons(UNKNOWNOP, (yyvsp[-1].node),
					 cons(INTERSECTION, (yyvsp[-2].node), (yyvsp[0].node)));
   					 if(useickec && createsused) {
					  if(!firstslat) firstslat=(yyvsp[-2].node);
                                          else prevslat->nextslat=(yyvsp[-2].node);
				     	  (yyvsp[-2].node)->nextslat=(yyvsp[0].node); prevslat=(yyvsp[0].node);
					  (yyvsp[0].node)->nextslat=0; opoverused=1;
  					  intern(ick_TWOSPOT, 1601);
					  intern(ick_TWOSPOT, 1602);
					  intern(ick_TWOSPOT, 1603);}}
#line 2574 "parser.c"
    break;

  case 119: /* notanlvalue: scalar SLAT expr  */
#line 556 "parser.y"
                                        {NEWFANGLED{(yyval.node) = cons(SLAT, (yyvsp[-2].node), (yyvsp[0].node));
					 opoverused=1; if(!firstslat)
					 firstslat=(yyvsp[0].node); else
					 prevslat->nextslat=(yyvsp[0].node); prevslat=(yyvsp[0].node);
					 (yyvsp[0].node)->nextslat=0;}}
#line 2584 "parser.c"
    break;

  case 120: /* limexpr: limunambig  */
#line 564 "parser.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 2590 "parser.c"
    break;

  case 121: /* limexpr: limunambig SELECT expr  */
#line 565 "parser.y"
                                        {(yyval.node) = cons(SELECT, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2596 "parser.c"
    break;

  case 122: /* limexpr: limunambig MINGLE expr  */
#line 566 "parser.y"
                                        {(yyval.node) = cons(MINGLE, (yyvsp[-2].node), (yyvsp[0].node));}
#line 2602 "parser.c"
    break;

  case 123: /* limexpr: limunambig unop expr  */
#line 567 "parser.y"
                                        {(yyval.node) = cons(UNKNOWNOP, (yyvsp[-1].node),
					 cons(INTERSECTION, (yyvsp[-2].node), (yyvsp[0].node)));
   					 if(useickec && createsused) {
					  if(!firstslat) firstslat=(yyvsp[-2].node);
                                          else prevslat->nextslat=(yyvsp[-2].node);
				     	  (yyvsp[-2].node)->nextslat=(yyvsp[0].node); prevslat=(yyvsp[0].node);
					  (yyvsp[0].node)->nextslat=0; opoverused=1;
  					  intern(ick_TWOSPOT, 1601);
					  intern(ick_TWOSPOT, 1602);
					  intern(ick_TWOSPOT, 1603);}}
#line 2617 "parser.c"
    break;

  case 124: /* limexpr: scalar SLAT expr  */
#line 577 "parser.y"
                                        {NEWFANGLED{(yyval.node) = cons(SLAT, (yyvsp[-2].node), (yyvsp[0].node));
					 opoverused=1; if(!firstslat)
					 firstslat=(yyvsp[0].node); else
					 prevslat->nextslat=(yyvsp[0].node); prevslat=(yyvsp[0].node);
					 (yyvsp[0].node)->nextslat=0;}}
#line 2627 "parser.c"
    break;

  case 125: /* limexpr: subscr  */
#line 582 "parser.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 2633 "parser.c"
    break;

  case 126: /* limexpr: osubscr  */
#line 583 "parser.y"
                                        {(yyval.node) = (yyvsp[0].node);}
#line 2639 "parser.c"
    break;

  case 127: /* preftype: MESH  */
#line 587 "parser.y"
                 {(yyval.numval)=MESH; }
#line 2645 "parser.c"
    break;

  case 128: /* preftype: ick_ONESPOT  */
#line 587 "parser.y"
                                           {(yyval.numval)=ick_ONESPOT;}
#line 2651 "parser.c"
    break;

  case 129: /* preftype: ick_TWOSPOT  */
#line 587 "parser.y"
                                                                           {(yyval.numval)=ick_TWOSPOT;}
#line 2657 "parser.c"
    break;

  case 130: /* lunambig: constant  */
#line 592 "parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2663 "parser.c"
    break;

  case 131: /* lunambig: preftype UNARY NUMBER  */
#line 595 "parser.y"
                {
		    (yyval.node) = newnode();
		    (yyval.node)->opcode = (yyvsp[-1].numval);
		    (yyval.node)->rval = newnode();
		    (yyval.node)->rval->opcode = (yyvsp[-2].numval);
		    if((yyvsp[-2].numval) == MESH) {
		      /* enforce the 16-bit constant constraint */
		      if ((unsigned int)(yyvsp[0].numval) > ick_Max_small)
			ick_lose(IE017, iyylineno, (char *)NULL);
		      if(variableconstants) /* AIS, patched by JH */
			(yyval.node)->rval->constant = intern(MESH, (yyvsp[0].numval));
		      else
			(yyval.node)->rval->constant = (yyvsp[0].numval);
		    }
		    else {
		      (yyval.node)->rval->constant = intern((yyvsp[-2].numval), (yyvsp[0].numval));
		    }
		}
#line 2686 "parser.c"
    break;

  case 132: /* lunambig: eitherspark UNARY expr CLOSESPARK  */
#line 617 "parser.y"
                {
		    (yyval.node) = newnode();
		    (yyval.node)->opcode = (yyvsp[-2].numval);
		    (yyval.node)->rval = (yyvsp[-1].node);
		    DESTACKSPARKEARS;
		}
#line 2697 "parser.c"
    break;

  case 133: /* lunambig: eitherears UNARY expr CLOSEEARS  */
#line 624 "parser.y"
                {
		    (yyval.node) = newnode();
		    (yyval.node)->opcode = (yyvsp[-2].numval);
		    (yyval.node)->rval = (yyvsp[-1].node);
		    DESTACKSPARKEARS;
		}
#line 2708 "parser.c"
    break;

  case 134: /* lunambig: eitherspark limexpr CLOSESPARK  */
#line 632 "parser.y"
                                                {(yyval.node) = (yyvsp[-1].node); DESTACKSPARKEARS;}
#line 2714 "parser.c"
    break;

  case 135: /* lunambig: eitherears limexpr CLOSEEARS  */
#line 633 "parser.y"
                                                {(yyval.node) = (yyvsp[-1].node); DESTACKSPARKEARS;}
#line 2720 "parser.c"
    break;

  case 136: /* limunambig: lunambig  */
#line 636 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 2726 "parser.c"
    break;

  case 137: /* limunambig: scalar  */
#line 637 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 2732 "parser.c"
    break;

  case 138: /* nlunambig: lunambig  */
#line 640 "parser.y"
                       {(yyval.node) = (yyvsp[0].node);}
#line 2738 "parser.c"
    break;

  case 139: /* nlunambig: UNARY unambig  */
#line 642 "parser.y"
             {(yyval.node)=newnode(); (yyval.node)->opcode = (yyvsp[-1].numval); (yyval.node)->rval = (yyvsp[0].node);}
#line 2744 "parser.c"
    break;

  case 140: /* unambig: limunambig  */
#line 651 "parser.y"
                        {(yyval.node) = (yyvsp[0].node);}
#line 2750 "parser.c"
    break;

  case 141: /* unambig: UNARY unambig  */
#line 653 "parser.y"
             {(yyval.node)=newnode(); (yyval.node)->opcode = (yyvsp[-1].numval); (yyval.node)->rval = (yyvsp[0].node);}
#line 2756 "parser.c"
    break;


#line 2760 "parser.c"

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

#line 664 "parser.y"


static tuple *splat(int gentuple)
/* try to recover from an invalid statement. */
{
    tuple *sp;
    int tok, i;
    extern bool re_send_token;

    /*
     * The idea
     * here is to skip to the ick_next DO, PLEASE or label, then unget that token.
     * which we can do with a tricky flag on the lexer (re_send_token).
     */

    if(re_send_token == true) /* By AIS */
    {
      /* We're still cleaning up from the previous error. */
      return prevtuple;
    }

    /*	fprintf(stderr,"attempting to splat at line %d....\n",iyylineno); */
    /* AIS: Set the flag to true the first time round, false for subsequent
       iterations. That way, if the error was triggered on a DO or label,
       we use that token as the start of the next statement. */
    for(i = 0,re_send_token = true;;i++,re_send_token = false) {
	tok = lexer();
	if (!tok)
	{
	    re_send_token = true;
	    tok = ' ';		/* scanner must not see a NUL */
	    break;
	}
	else if (tok == DO || tok == PLEASE || tok == LABEL
		 /* AIS */ || tok == MAYBE) {
	    re_send_token = true;
	    break;
	}
    }
    /*
	fprintf(stderr,"found %d on line %d after %d other tokens.\n",
		tok,iyylineno,i);
     */

    /* generate a placeholder tuple for the text line */
    if(gentuple /* AIS */) {TARGET(sp, SPLATTERED, 0); prevtuple=sp;}
    else sp=NULL;

    return(sp);
}

/* parser.y ends here */

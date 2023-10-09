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

#ifndef YY_YY_PARSER_H_INCLUDED
# define YY_YY_PARSER_H_INCLUDED
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

#line 299 "parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_H_INCLUDED  */

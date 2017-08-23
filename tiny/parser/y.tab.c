/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "code.y"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <DLists.h>
#include <Tokenizer.h>
#include <Trees.h>

extern TREENODE *root;
typedef struct {
    DNODE mynode;
    TREENODE *nodeptr;
} T_NODE;

#line 16 "code.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
   TOKEN_INFO info;
   DLIST dlist;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 47 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define STRING 257
#define END 258
#define LGE 259
#define TO 260
#define VAR 261
#define IDENTIFIER 262
#define CHR 263
#define POOL 264
#define IF 265
#define FUNCTION 266
#define MUL 267
#define READ 268
#define REPEAT 269
#define RANGE 270
#define RETURN 271
#define ELSE 272
#define UEQ 273
#define UNTIL 274
#define SWAP 275
#define THEN 276
#define FOR 277
#define OF 278
#define CHARACTER 279
#define MOD 280
#define CASE 281
#define WHILE 282
#define OUTPUT 283
#define EXIT 284
#define PROCEDURE 285
#define CONST 286
#define PRED 287
#define NOT 288
#define DO 289
#define BEGINX 290
#define ORD 291
#define INTEGER_NUM 292
#define AND 293
#define EOFX 294
#define LTE 295
#define LOOP 296
#define SUCC 297
#define TYPE 298
#define OR 299
#define OTHERWISE 300
#define ASSIGNMENT 301
#define PROGRAM 302
#define DOWNTO 303
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,   18,   18,   11,   11,   35,   35,   31,    6,    6,
   23,   23,    5,    5,    1,   37,   37,   30,   30,   22,
   26,   26,   40,   33,   33,   14,   14,   13,   13,   13,
    4,    4,   29,   21,   21,   24,   24,   24,   24,   24,
   24,   24,   24,   24,   24,   24,   24,   24,   24,   24,
   24,   24,   24,   24,   32,   32,    3,    3,   34,   34,
   17,   17,    2,    2,   20,   20,   10,   19,    8,   39,
   39,   28,   28,    9,   36,   36,   36,   36,   36,   36,
   36,   25,   25,   25,   25,    7,    7,    7,    7,    7,
   12,   12,   12,   12,   16,   16,   38,   38,   38,   38,
   38,   38,   38,   38,   38,   38,   38,   38,   15,   15,
   27,
};
static const YYINT yylen[] = {                            2,
   10,    2,    0,    0,    3,    3,    3,    2,    2,    3,
    2,    0,    0,    3,    3,    2,    0,    0,    3,    1,
    3,    3,    1,    0,    2,   12,   10,    2,    2,    0,
    2,    3,    2,    2,    3,    2,    4,    4,    2,    8,
    8,    3,    3,    3,    6,    4,    4,    1,    3,    1,
    1,    2,    4,    0,    2,    3,    2,    3,    3,    3,
    1,    3,    2,    3,    2,    3,    1,    0,    3,    0,
    2,    3,    3,    3,    1,    3,    3,    3,    3,    3,
    3,    1,    3,    3,    3,    1,    3,    3,    3,    3,
    1,    2,    2,    2,    1,    3,    1,    3,    3,    1,
    1,    1,    1,    4,    4,    4,    4,    3,    2,    3,
    1,
};
static const YYINT yydefred[] = {                         0,
    0,    0,  111,    0,    0,    0,    0,    0,   11,    0,
    0,    0,    0,    0,    2,    0,    0,    0,    0,   14,
  102,    0,  101,    0,    0,    0,  100,  103,    0,    0,
    0,    0,    0,   86,   91,    0,    0,   15,    0,    0,
    0,    0,   20,    0,   16,    0,    0,    0,   23,    0,
    0,    0,   94,    0,    0,    0,   93,   92,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    7,    6,    5,    0,    0,    0,
    0,    0,   25,    0,    0,    0,    0,    0,    0,  108,
   90,   89,   87,   88,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   98,   99,    0,   96,    8,    0,   19,
   21,   22,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   50,    0,   33,    0,    0,   48,   51,
    0,    0,  107,  105,  106,  104,  109,    0,    9,    0,
   29,   28,    0,    0,    0,    0,    0,    0,   39,    0,
   52,   67,    0,    0,    0,    0,   36,    0,   34,    0,
    0,    0,    1,  110,   10,    0,   31,    0,    0,    0,
   44,    0,    0,    0,    0,    0,    0,    0,   43,    0,
   65,    0,   35,   42,   49,   32,    0,    0,    0,   55,
    0,   59,   60,   53,    0,   61,    0,   37,    0,    0,
   38,    0,    0,   47,   57,    0,   66,    0,    0,    0,
   56,    0,    0,    0,   63,    0,    0,    0,    0,   58,
    0,    0,   45,    0,    0,    0,   69,   73,   64,   62,
   74,   72,    0,    0,    0,    0,   71,    0,   27,   41,
   40,    0,   26,
};
static const YYINT yydgoto[] = {                          2,
    8,  198,  179,  142,    9,  108,   33,  199,  200,  151,
   15,   34,  114,   48,  105,   35,  201,   12,  152,  157,
  126,   42,    7,  127,   36,   43,   37,  202,  129,   45,
   76,  171,   49,  149,   17,  130,   19,   39,  227,   50,
};
static const YYINT yysindex[] = {                      -264,
 -215,    0,    0,   -4, -207, -215, -234,   26,    0,   36,
 -215, -159, -215,  237,    0,   48,   54, -215, -233,    0,
    0,   81,    0,   96,  237,  101,    0,    0,  102,  237,
  237,  237,   -8,    0,    0,  139,  103,    0, -117,  -32,
 -215,   92,    0,   45,    0, -215, -215, -233,    0, -137,
  237,  237,    0,  237,  237,  116,    0,    0,  237,  237,
  237,  237,  237,  237,  237,  237,  237,  237,  237,  237,
  237,  403,  198, -215,    0,    0,    0, -215, -215, -215,
  118,  118,    0,  134, -215,  119,  120,  121,  122,    0,
    0,    0,    0,    0,  -34,  -34,  -34,   -8,  -34,  -34,
  -34,   -8,   -8,    0,    0,    5,    0,    0,    7,    0,
    0,    0,  -28,  106,  100,  237,  125,  134,  126, -215,
  237,  237,  127,    0,  134,    0,  -45,  -35,    0,    0,
 -222,  123,    0,    0,    0,    0,    0,  237,    0, -215,
    0,    0,  -18, -215, -207, -108,  237,  -47,    0,  237,
    0,    0, -126, -102, -111,  237,    0,  -24,    0,  134,
  237,  198,    0,    0,    0, -215,    0,  124, -234,  134,
    0,   50,  237,  134,  140,  198,  -16,  134,    0,   85,
    0,  134,    0,    0,    0,    0, -207, -159,  -92,    0,
  237,    0,    0,    0, -238,    0,  134,    0,  -73,  129,
    0,  130,  -42,    0,    0,  237,    0, -234, -137,  134,
    0,  198,  198,  131,    0,  134,  -16,  198,  134,    0,
 -159, -215,    0, -101,  -98,  131,    0,    0,    0,    0,
    0,    0, -137,  133,  134,  134,    0, -215,    0,    0,
    0,  135,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0, -180, -171, -174,    0,    0,    0,
 -173, -235, -171,    0,    0,    0,    0, -170,  -97,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   39,    0,    0,  285,  -41,    0,   15,    0,
 -173,    0,    0,    0,    0,    0,    0,  -97,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -170,    0,    0,
  137,  138,    0,  -44,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  309,  333,  395,   63,  443,  452,
  471,   87,  111,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -30,  -52,    0,
    0,    0,    0,    0,  -19,    0,    0,  208,    0,    0,
  390,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -229,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -44,
    0,    0,    0,    0,    0,    0,    0,    0, -224,  -15,
    0,    0,    0,  -30,    0,    0,    0,  -15,    0,    0,
    0,  -19,    0,    0,    0,    0, -229,  -94,  -49,    0,
    0,    0,    0,    0,    0,    0,  -44,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -224,    0,  -15,
    0,    0,    0,  -60,    0,  143,    0,    0,  143,    0,
  -94,    0,    0,    0,    0,  -60,    0,    0,    0,    0,
    0,    0,    0,    0,  -15,  -15,    0,    0,    0,    0,
    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,  -14,   -2,   41,  192,   68,   74,    0,    0,    0,
  170,   11,  142,    0,   78,  148,   19, -141,    0,   79,
  104,  -88, -119,  613,   70,  176,  733,    0,  -23,  182,
    0,   95,  235,  128,    0,  748, -158,  402,   64,    0,
};
#define YYTABLESIZE 971
static const YYINT yytable[] = {                         97,
   97,   97,   97,   97,   72,   97,   68,   74,   70,   46,
   71,  174,  141,  160,   54,  219,   97,   97,   97,   97,
   97,  212,  167,   30,  143,  169,   85,  188,   54,  209,
   17,   12,   46,   61,  182,   53,    3,    1,   62,   54,
  166,   57,   58,   54,   73,  137,    3,  139,  138,   17,
  140,   47,  162,    5,   17,   95,   95,   95,   95,   95,
   12,   95,  233,   11,  213,    3,  221,  208,   12,   91,
   92,   93,   94,   95,   95,   95,   95,  143,    6,   82,
   12,   82,   82,   82,   13,   12,    3,    4,   80,   13,
  190,    3,    4,  191,   13,   18,   14,   82,   82,   82,
   82,   18,   79,   85,   12,   85,   85,   85,   40,   12,
    3,    4,   41,   13,   18,    3,    4,   12,   13,   18,
   51,   85,   85,   85,   85,  205,   13,   83,  206,   83,
   83,   83,   95,   96,   97,   52,   99,  100,  101,   98,
   54,   55,   72,  102,  103,   83,   83,   83,   83,   73,
   78,   84,   84,   84,   84,   84,   90,  113,  145,  133,
  134,  135,  136,  144,  147,  150,  156,  170,  163,   84,
   84,   84,   84,   30,  176,  177,   31,  178,   32,  210,
  194,   70,  187,   71,  215,  222,  216,  235,  217,  226,
  236,  239,   24,  243,   30,   17,   30,   70,   68,   67,
   69,   54,  229,  220,   20,   68,  186,  165,   46,  238,
   77,   68,  159,   54,   46,  164,   97,   97,   97,   68,
  107,   68,   97,  115,   46,   97,  173,  218,   97,    3,
   97,   97,   97,    3,   97,  230,   97,   30,   97,  181,
   21,  196,   54,   54,   54,    3,   22,   97,   54,   97,
   97,   97,   97,   97,   97,  112,   54,   97,   54,  110,
  207,   97,   23,  183,   66,  161,   97,   97,   97,   97,
   24,   59,   95,   95,   26,   27,   30,   28,   95,   31,
   29,   32,   83,  197,   60,  211,   95,   95,   95,  237,
   95,    0,   95,    0,   95,    0,   82,   82,    0,    0,
    0,  193,   82,   95,    0,    0,    0,   95,    0,   95,
   82,   82,   82,   95,   82,    0,   82,    0,    0,    0,
   85,   85,    0,    0,    0,   75,   85,   82,   75,    0,
    0,    0,    0,   82,   85,   85,   85,   82,   85,    0,
   85,    0,    0,   75,   83,   83,    0,    0,    0,   79,
   83,   85,   79,    0,    0,    0,    0,   85,   83,   83,
   83,   85,   83,    0,   83,    0,    0,   79,   84,   84,
    0,    0,    0,   78,   84,   83,   78,    0,    0,    0,
    0,   83,   84,   84,   84,   83,   84,    0,   84,    0,
   21,   78,    0,    0,    0,    3,   22,   63,  116,   84,
    0,  117,  118,    0,  119,   84,    0,    0,    0,   84,
  120,   64,   23,    0,  121,  122,  123,  124,    0,    0,
   24,   25,    0,   84,   26,   27,    0,   28,    0,  125,
   29,   95,   95,   65,   95,   76,   95,   66,   76,    0,
    0,    0,   30,  104,    0,   31,    0,   32,   95,   95,
   95,   95,    0,   76,   21,    0,    0,    0,    0,    3,
   22,    0,    0,    0,    0,   97,   97,    0,    0,    0,
    0,   97,    0,    0,   97,    0,   23,    0,    0,   97,
   97,   97,   97,   77,   24,  131,   77,   97,   26,   27,
    0,   28,   80,   21,   29,   80,    0,    0,    3,   22,
   97,   77,   97,    0,    0,    0,   97,    0,    0,    0,
   80,   81,    0,    0,   81,   23,    0,    0,    0,  131,
    0,    0,    0,   24,   25,    0,  131,   26,   27,   81,
   28,    0,    0,   29,    0,    0,    0,    0,    0,    0,
    0,    0,   75,    0,    0,    0,    0,    0,   75,    0,
    0,    0,    0,    0,    0,    0,   75,    0,   75,    0,
   75,  131,   75,  185,    0,    0,   79,    0,    0,    0,
    0,  131,   79,   75,    0,  131,    0,  195,  203,  131,
   79,    0,   79,  131,   79,    0,   79,    0,    0,    0,
   78,    0,    0,    0,    0,    0,   78,   79,  131,    0,
    0,    0,    0,    0,   78,    0,   78,    0,   78,    0,
   78,  131,    0,  224,  225,    0,    0,  131,  203,  231,
  131,   78,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  131,  131,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   95,   95,    0,
    0,    0,   76,   95,    0,    0,    0,    0,   76,   21,
    0,   95,   95,   95,    3,   22,   76,    0,   76,   95,
   76,    0,   76,    0,    0,    0,    0,    0,    0,    0,
    0,   23,   95,   76,   95,    0,    0,    0,   95,   24,
   25,    0,    0,   26,   27,    0,   28,    0,    0,   29,
   77,    0,    0,    0,    0,    0,   77,    0,    0,   80,
    0,    0,    0,    0,   77,   80,   77,    0,   77,    0,
   77,    0,    0,   80,    0,   80,    0,   80,   81,   80,
  148,   77,    0,    4,   81,    0,    0,  158,   10,    0,
   80,    0,   81,   16,   81,   10,   81,    0,   81,    0,
   44,    0,    0,    0,    0,    0,    0,    0,    0,   81,
    0,   38,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   75,   16,    0,    0,    0,   56,   81,   82,
    0,    0,  189,    0,    0,    0,  148,    0,    0,    0,
  204,    0,    0,    0,  158,    0,    0,    0,   86,   87,
    0,   88,   89,    0,    0,    0,  109,    0,    0,  214,
   44,  111,   44,    0,    0,    0,  128,  132,    0,  106,
    0,    0,  223,    0,    0,    0,    0,    0,  228,    0,
    0,  232,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   44,    0,  240,  241,    0,
  128,    0,  153,    0,    0,    0,    0,  128,    0,    0,
    0,    0,    0,  146,    0,    0,    0,    0,  154,  155,
    0,    0,  109,    0,    0,    0,  168,    0,    0,    0,
    0,    0,    0,    0,    0,  106,    0,    0,    0,    0,
    0,    0,  128,    0,  172,    0,    0,  175,   44,    0,
    0,    0,  128,  180,    0,    0,  128,    0,  184,    0,
  128,    0,    0,    0,  128,    0,    0,    0,    0,    0,
  192,    0,    0,    0,    0,    0,    0,    0,    0,  128,
    0,    0,    0,    0,    0,    0,    0,    0,  172,    0,
    0,    0,  128,    0,    0,    0,    0,    0,  128,    0,
    0,  128,    0,  180,  234,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  128,  128,    0,
  242,
};
static const YYINT yycheck[] = {                         41,
   42,   43,   44,   45,   40,   47,   59,   40,   43,   59,
   45,   59,   41,   59,   59,   58,   58,   59,   60,   61,
   62,  260,   41,   40,  113,  145,   50,  169,   59,  188,
  266,  261,  266,   42,   59,   25,  261,  302,   47,   59,
   59,   31,   32,   59,  267,   41,  262,   41,   44,  285,
   44,  285,  275,   58,  290,   41,   42,   43,   44,   45,
  290,   47,  221,  298,  303,  290,  208,  187,  298,   59,
   60,   61,   62,   59,   60,   61,   62,  166,  286,   41,
  261,   43,   44,   45,   59,  266,  261,  261,   44,  261,
   41,  266,  266,   44,  266,  266,   61,   59,   60,   61,
   62,  261,   58,   41,  285,   43,   44,   45,   61,  290,
  285,  285,   59,  285,  285,  290,  290,  298,  290,  290,
   40,   59,   60,   61,   62,   41,  298,   41,   44,   43,
   44,   45,   63,   64,   65,   40,   67,   68,   69,   66,
   40,   40,   40,   70,   71,   59,   60,   61,   62,  267,
   59,   41,  290,   43,   44,   45,   41,   40,   59,   41,
   41,   41,   41,   58,   40,   40,   40,  276,   46,   59,
   60,   61,   62,   40,  301,  278,   43,  289,   45,  272,
   41,   43,   59,   45,  258,  209,   58,  289,   59,   59,
  289,   59,  290,   59,   58,  290,   59,  258,   60,   61,
   62,   59,  217,  206,   13,  258,  166,  140,  258,  233,
   41,  264,  258,  258,  264,  138,  258,  259,  260,  272,
   73,  274,  264,   82,  274,  267,  274,  270,  270,  262,
  272,  273,  274,  262,  276,  217,  278,   40,  280,  264,
  257,  258,  258,  274,  264,  262,  263,  289,  264,   42,
   43,  293,   45,  295,   47,   80,  272,  299,  274,   78,
  182,  303,  279,  160,  299,  301,   59,   60,   61,   62,
  287,  280,  258,  259,  291,  292,   40,  294,  264,   43,
  297,   45,   48,  300,  293,  191,  272,  273,  274,  226,
  276,   -1,  278,   -1,  280,   -1,  258,  259,   -1,   -1,
   -1,  174,  264,  289,   -1,   -1,   -1,  293,   -1,  295,
  272,  273,  274,  299,  276,   -1,  278,   -1,   -1,   -1,
  258,  259,   -1,   -1,   -1,   41,  264,  289,   44,   -1,
   -1,   -1,   -1,  295,  272,  273,  274,  299,  276,   -1,
  278,   -1,   -1,   59,  258,  259,   -1,   -1,   -1,   41,
  264,  289,   44,   -1,   -1,   -1,   -1,  295,  272,  273,
  274,  299,  276,   -1,  278,   -1,   -1,   59,  258,  259,
   -1,   -1,   -1,   41,  264,  289,   44,   -1,   -1,   -1,
   -1,  295,  272,  273,  274,  299,  276,   -1,  278,   -1,
  257,   59,   -1,   -1,   -1,  262,  263,  259,  265,  289,
   -1,  268,  269,   -1,  271,  295,   -1,   -1,   -1,  299,
  277,  273,  279,   -1,  281,  282,  283,  284,   -1,   -1,
  287,  288,   -1,  290,  291,  292,   -1,  294,   -1,  296,
  297,   42,   43,  295,   45,   41,   47,  299,   44,   -1,
   -1,   -1,   40,   41,   -1,   43,   -1,   45,   59,   60,
   61,   62,   -1,   59,  257,   -1,   -1,   -1,   -1,  262,
  263,   -1,   -1,   -1,   -1,  258,  259,   -1,   -1,   -1,
   -1,  264,   -1,   -1,  267,   -1,  279,   -1,   -1,  272,
  273,  274,  275,   41,  287,   84,   44,  280,  291,  292,
   -1,  294,   41,  257,  297,   44,   -1,   -1,  262,  263,
  293,   59,  295,   -1,   -1,   -1,  299,   -1,   -1,   -1,
   59,   41,   -1,   -1,   44,  279,   -1,   -1,   -1,  118,
   -1,   -1,   -1,  287,  288,   -1,  125,  291,  292,   59,
  294,   -1,   -1,  297,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  258,   -1,   -1,   -1,   -1,   -1,  264,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  272,   -1,  274,   -1,
  276,  160,  278,  162,   -1,   -1,  258,   -1,   -1,   -1,
   -1,  170,  264,  289,   -1,  174,   -1,  176,  177,  178,
  272,   -1,  274,  182,  276,   -1,  278,   -1,   -1,   -1,
  258,   -1,   -1,   -1,   -1,   -1,  264,  289,  197,   -1,
   -1,   -1,   -1,   -1,  272,   -1,  274,   -1,  276,   -1,
  278,  210,   -1,  212,  213,   -1,   -1,  216,  217,  218,
  219,  289,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  235,  236,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  258,  259,   -1,
   -1,   -1,  258,  264,   -1,   -1,   -1,   -1,  264,  257,
   -1,  272,  273,  274,  262,  263,  272,   -1,  274,  280,
  276,   -1,  278,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  279,  293,  289,  295,   -1,   -1,   -1,  299,  287,
  288,   -1,   -1,  291,  292,   -1,  294,   -1,   -1,  297,
  258,   -1,   -1,   -1,   -1,   -1,  264,   -1,   -1,  258,
   -1,   -1,   -1,   -1,  272,  264,  274,   -1,  276,   -1,
  278,   -1,   -1,  272,   -1,  274,   -1,  276,  258,  278,
  118,  289,   -1,    1,  264,   -1,   -1,  125,    6,   -1,
  289,   -1,  272,   11,  274,   13,  276,   -1,  278,   -1,
   18,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  289,
   -1,   14,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   40,   41,   -1,   -1,   -1,   30,   46,   47,
   -1,   -1,  170,   -1,   -1,   -1,  174,   -1,   -1,   -1,
  178,   -1,   -1,   -1,  182,   -1,   -1,   -1,   51,   52,
   -1,   54,   55,   -1,   -1,   -1,   74,   -1,   -1,  197,
   78,   79,   80,   -1,   -1,   -1,   84,   85,   -1,   72,
   -1,   -1,  210,   -1,   -1,   -1,   -1,   -1,  216,   -1,
   -1,  219,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  113,   -1,  235,  236,   -1,
  118,   -1,  120,   -1,   -1,   -1,   -1,  125,   -1,   -1,
   -1,   -1,   -1,  116,   -1,   -1,   -1,   -1,  121,  122,
   -1,   -1,  140,   -1,   -1,   -1,  144,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  138,   -1,   -1,   -1,   -1,
   -1,   -1,  160,   -1,  147,   -1,   -1,  150,  166,   -1,
   -1,   -1,  170,  156,   -1,   -1,  174,   -1,  161,   -1,
  178,   -1,   -1,   -1,  182,   -1,   -1,   -1,   -1,   -1,
  173,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  197,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  191,   -1,
   -1,   -1,  210,   -1,   -1,   -1,   -1,   -1,  216,   -1,
   -1,  219,   -1,  206,  222,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  235,  236,   -1,
  238,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 303
#define YYUNDFTOKEN 346
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,0,0,0,0,0,0,0,0,0,
"':'","';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"STRING","END","LGE","TO","VAR","IDENTIFIER","CHR","POOL",
"IF","FUNCTION","MUL","READ","REPEAT","RANGE","RETURN","ELSE","UEQ","UNTIL",
"SWAP","THEN","FOR","OF","CHARACTER","MOD","CASE","WHILE","OUTPUT","EXIT",
"PROCEDURE","CONST","PRED","NOT","DO","BEGINX","ORD","INTEGER_NUM","AND","EOFX",
"LTE","LOOP","SUCC","TYPE","OR","OTHERWISE","ASSIGNMENT","PROGRAM","DOWNTO",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : Tiny",
"Tiny : PROGRAM Name ':' Consts Types Dclns SubProgs Body Name '.'",
"Types : TYPE Types_1",
"Types :",
"Types_1 :",
"Types_1 : Type ';' Types_1",
"Type : Name '=' Lit",
"Type : Name '=' Name",
"Lit : '(' Lit_1",
"Lit_1 : Name ')'",
"Lit_1 : Name ',' Lit_1",
"Consts : CONST Consts_1",
"Consts :",
"Consts_1 :",
"Consts_1 : Const ';' Consts_1",
"Const : Name '=' Expression",
"Dclns : VAR Dclns_1",
"Dclns :",
"Dclns_1 :",
"Dclns_1 : Dcln ';' Dclns_1",
"Dcln : Dcln_1",
"Dcln_1 : Name ':' Name",
"Dcln_1 : Name ',' Dcln_1",
"SubProgs : SubProgs_1",
"SubProgs_1 :",
"SubProgs_1 : Function SubProgs_1",
"Function : FUNCTION Name Params ':' Name ';' Consts Types Dclns Body Name ';'",
"Function : PROCEDURE Name Params ';' Consts Types Dclns Body Name ';'",
"Params : '(' Params_1",
"Params : '(' ')'",
"Params :",
"Params_1 : Dcln ')'",
"Params_1 : Dcln ';' Params_1",
"Body : BEGINX Body_1",
"Body_1 : Statement END",
"Body_1 : Statement ';' Body_1",
"Statement : LOOP Statement_1",
"Statement : CASE Expression OF Statement_1_1",
"Statement : CASE Expression OF Statement_1_1_1",
"Statement : REPEAT Statement_1_1_1_1",
"Statement : FOR Name ASSIGNMENT Primary DOWNTO Primary DO Statement",
"Statement : FOR Name ASSIGNMENT Primary TO Primary DO Statement",
"Statement : Name ASSIGNMENT Expression",
"Statement : OUTPUT '(' Statement_1_1_1_1_1",
"Statement : READ '(' Statement_1_1_1_1_1_1",
"Statement : IF Expression THEN Statement ELSE Statement",
"Statement : IF Expression THEN Statement",
"Statement : WHILE Expression DO Statement",
"Statement : Body",
"Statement : Primary SWAP Primary",
"Statement : EXIT",
"Statement : Expression",
"Statement : RETURN MissValue",
"Statement : RETURN '(' Expression ')'",
"Statement :",
"Statement_1_1_1_1_1_1 : Expression ')'",
"Statement_1_1_1_1_1_1 : Expression ',' Statement_1_1_1_1_1_1",
"Statement_1_1_1_1_1 : Expression ')'",
"Statement_1_1_1_1_1 : Expression ',' Statement_1_1_1_1_1",
"Statement_1_1_1_1 : Statement UNTIL Expression",
"Statement_1_1_1_1 : Statement ';' Statement_1_1_1_1",
"Statement_1_1_1 : END",
"Statement_1_1_1 : CASE_CLAUSE ';' Statement_1_1_1",
"Statement_1_1 : OTHER END",
"Statement_1_1 : CASE_CLAUSE ';' Statement_1_1",
"Statement_1 : Statement POOL",
"Statement_1 : Statement ';' Statement_1",
"MissValue : TheValue",
"TheValue :",
"OTHER : OTHERWISE Statement OTHER_1",
"OTHER_1 :",
"OTHER_1 : ';' OTHER_1",
"CASE_CLAUSE : Primary ':' Statement",
"CASE_CLAUSE : SCOPE ':' Statement",
"SCOPE : Primary RANGE Primary",
"Expression : Term",
"Expression : Term LTE Term",
"Expression : Term '=' Term",
"Expression : Term UEQ Term",
"Expression : Term LGE Term",
"Expression : Term '<' Term",
"Expression : Term '>' Term",
"Term : Adv",
"Term : Term '+' Adv",
"Term : Term '-' Adv",
"Term : Term OR Adv",
"Adv : Extra",
"Adv : Adv '*' Extra",
"Adv : Adv '/' Extra",
"Adv : Adv AND Extra",
"Adv : Adv MOD Extra",
"Extra : EXPI",
"Extra : '-' Extra",
"Extra : '+' Extra",
"Extra : NOT Extra",
"EXPI : Primary",
"EXPI : Primary MUL EXPI",
"Primary : Name",
"Primary : Name '(' ')'",
"Primary : Name '(' Primary_1",
"Primary : INTEGER_NUM",
"Primary : CHARACTER",
"Primary : STRING",
"Primary : EOFX",
"Primary : SUCC '(' Expression ')'",
"Primary : PRED '(' Expression ')'",
"Primary : ORD '(' Expression ')'",
"Primary : CHR '(' Expression ')'",
"Primary : '(' Expression ')'",
"Primary_1 : Expression ')'",
"Primary_1 : Expression ',' Primary_1",
"Name : IDENTIFIER",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 111 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-9].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-9].info.string,
		                                TREETAG_LINE,yystack.l_mark[-9].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-9].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-8].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-8].dlist));

		while (DCount(&yystack.l_mark[-6].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-6].dlist));

		while (DCount(&yystack.l_mark[-5].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-5].dlist));

		while (DCount(&yystack.l_mark[-4].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-4].dlist));

		while (DCount(&yystack.l_mark[-3].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-3].dlist));

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[-1].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-1].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"program",
		                                TREETAG_LINE,yystack.l_mark[-9].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-9].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		t->mynode = *(DHead(&r));
		root = t->nodeptr;

             }
break;
case 2:
#line 168 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"types",
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 3:
#line 204 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"types",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 4:
#line 226 "code.y"
	{
		DLIST r;

		InitDList(&r);

		yyval.dlist = r;

             }
break;
case 5:
#line 235 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 6:
#line 252 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"type",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 7:
#line 278 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"type",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 8:
#line 306 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"lit",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 9:
#line 331 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-1].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-1].dlist));

		yyval.dlist = r;

             }
break;
case 10:
#line 343 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 11:
#line 360 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"consts",
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 12:
#line 396 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"consts",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 13:
#line 418 "code.y"
	{
		DLIST r;

		InitDList(&r);

		yyval.dlist = r;

             }
break;
case 14:
#line 427 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 15:
#line 444 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"const",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 16:
#line 472 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"dclns",
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 17:
#line 508 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"dclns",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 18:
#line 530 "code.y"
	{
		DLIST r;

		InitDList(&r);

		yyval.dlist = r;

             }
break;
case 19:
#line 539 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 20:
#line 556 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"var",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 21:
#line 581 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 22:
#line 596 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 23:
#line 613 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"subprogs",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 24:
#line 638 "code.y"
	{
		DLIST r;

		InitDList(&r);

		yyval.dlist = r;

             }
break;
case 25:
#line 647 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-1].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-1].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 26:
#line 664 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-11].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-11].info.string,
		                                TREETAG_LINE,yystack.l_mark[-11].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-11].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-10].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-10].dlist));

		while (DCount(&yystack.l_mark[-9].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-9].dlist));

		while (DCount(&yystack.l_mark[-7].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-7].dlist));

		while (DCount(&yystack.l_mark[-5].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-5].dlist));

		while (DCount(&yystack.l_mark[-4].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-4].dlist));

		while (DCount(&yystack.l_mark[-3].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-3].dlist));

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[-1].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-1].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"function",
		                                TREETAG_LINE,yystack.l_mark[-11].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-11].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 27:
#line 721 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-9].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-9].info.string,
		                                TREETAG_LINE,yystack.l_mark[-9].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-9].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-8].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-8].dlist));

		while (DCount(&yystack.l_mark[-7].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-7].dlist));

		while (DCount(&yystack.l_mark[-5].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-5].dlist));

		while (DCount(&yystack.l_mark[-4].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-4].dlist));

		while (DCount(&yystack.l_mark[-3].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-3].dlist));

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[-1].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-1].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"procedure",
		                                TREETAG_LINE,yystack.l_mark[-9].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-9].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 28:
#line 777 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"params",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 29:
#line 800 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"params",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 30:
#line 820 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"params",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 31:
#line 842 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-1].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-1].dlist));

		yyval.dlist = r;

             }
break;
case 32:
#line 854 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 33:
#line 871 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"block",
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 34:
#line 909 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-1].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-1].dlist));

		if (yystack.l_mark[0].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[0].info.string,
		                                TREETAG_LINE,yystack.l_mark[0].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[0].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		yyval.dlist = r;

             }
break;
case 35:
#line 932 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 36:
#line 949 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"loop",
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 37:
#line 985 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-3].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-3].info.string,
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"case",
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 38:
#line 1035 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-3].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-3].info.string,
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"case",
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 39:
#line 1085 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"repeat",
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 40:
#line 1121 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-7].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-7].info.string,
		                                TREETAG_LINE,yystack.l_mark[-7].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-7].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-6].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-6].dlist));

		if (yystack.l_mark[-5].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-5].info.string,
		                                TREETAG_LINE,yystack.l_mark[-5].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-5].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-4].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-4].dlist));

		if (yystack.l_mark[-3].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-3].info.string,
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"downto",
		                                TREETAG_LINE,yystack.l_mark[-7].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-7].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 41:
#line 1199 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-7].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-7].info.string,
		                                TREETAG_LINE,yystack.l_mark[-7].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-7].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-6].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-6].dlist));

		if (yystack.l_mark[-5].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-5].info.string,
		                                TREETAG_LINE,yystack.l_mark[-5].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-5].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-4].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-4].dlist));

		if (yystack.l_mark[-3].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-3].info.string,
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"upto",
		                                TREETAG_LINE,yystack.l_mark[-7].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-7].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 42:
#line 1277 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"assign",
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 43:
#line 1316 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-2].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-2].info.string,
		                                TREETAG_LINE,yystack.l_mark[-2].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-2].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"output",
		                                TREETAG_LINE,yystack.l_mark[-2].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-2].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 44:
#line 1352 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-2].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-2].info.string,
		                                TREETAG_LINE,yystack.l_mark[-2].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-2].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"read",
		                                TREETAG_LINE,yystack.l_mark[-2].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-2].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 45:
#line 1388 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-5].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-5].info.string,
		                                TREETAG_LINE,yystack.l_mark[-5].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-5].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-4].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-4].dlist));

		if (yystack.l_mark[-3].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-3].info.string,
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"if",
		                                TREETAG_LINE,yystack.l_mark[-5].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-5].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 46:
#line 1452 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-3].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-3].info.string,
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"if",
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 47:
#line 1502 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-3].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-3].info.string,
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"while",
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 48:
#line 1552 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 49:
#line 1564 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"swap",
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 50:
#line 1603 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[0].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[0].info.string,
		                                TREETAG_LINE,yystack.l_mark[0].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[0].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"exit",
		                                TREETAG_LINE,yystack.l_mark[0].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[0].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 51:
#line 1636 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 52:
#line 1648 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"return",
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 53:
#line 1684 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-3].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-3].info.string,
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-1].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-1].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"return",
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 54:
#line 1720 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<null>",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 55:
#line 1742 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-1].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-1].dlist));

		yyval.dlist = r;

             }
break;
case 56:
#line 1754 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 57:
#line 1771 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-1].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-1].dlist));

		yyval.dlist = r;

             }
break;
case 58:
#line 1783 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 59:
#line 1800 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 60:
#line 1826 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 61:
#line 1843 "code.y"
	{
		DLIST r;

		InitDList(&r);

		if (yystack.l_mark[0].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[0].info.string,
		                                TREETAG_LINE,yystack.l_mark[0].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[0].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		yyval.dlist = r;

             }
break;
case 62:
#line 1863 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 63:
#line 1880 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-1].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-1].dlist));

		if (yystack.l_mark[0].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[0].info.string,
		                                TREETAG_LINE,yystack.l_mark[0].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[0].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		yyval.dlist = r;

             }
break;
case 64:
#line 1903 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 65:
#line 1920 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-1].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-1].dlist));

		if (yystack.l_mark[0].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[0].info.string,
		                                TREETAG_LINE,yystack.l_mark[0].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[0].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		yyval.dlist = r;

             }
break;
case 66:
#line 1943 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 67:
#line 1960 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<identifier>",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 68:
#line 1985 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"Prime",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 69:
#line 2007 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-2].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-2].info.string,
		                                TREETAG_LINE,yystack.l_mark[-2].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-2].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-1].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-1].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"otherwise",
		                                TREETAG_LINE,yystack.l_mark[-2].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-2].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 70:
#line 2048 "code.y"
	{
		DLIST r;

		InitDList(&r);

		yyval.dlist = r;

             }
break;
case 71:
#line 2057 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 72:
#line 2071 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"case_clause",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 73:
#line 2097 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"case_clause",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 74:
#line 2125 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"..",
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 75:
#line 2166 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 76:
#line 2178 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<=",
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 77:
#line 2217 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"=",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 78:
#line 2243 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<>",
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 79:
#line 2282 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,">=",
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 80:
#line 2321 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 81:
#line 2347 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,">",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 82:
#line 2375 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 83:
#line 2387 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"+",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 84:
#line 2413 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"-",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 85:
#line 2439 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"or",
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 86:
#line 2480 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 87:
#line 2492 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"*",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 88:
#line 2518 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"/",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 89:
#line 2544 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"and",
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 90:
#line 2583 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"mod",
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 91:
#line 2624 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 92:
#line 2636 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"-",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 93:
#line 2659 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"+",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 94:
#line 2682 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"not",
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 95:
#line 2720 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 96:
#line 2732 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		if (yystack.l_mark[-1].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-1].info.string,
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"**",
		                                TREETAG_LINE,yystack.l_mark[-1].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-1].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 97:
#line 2773 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 98:
#line 2785 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"call",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 99:
#line 2808 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"call",
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 100:
#line 2834 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[0].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[0].info.string,
		                                TREETAG_LINE,yystack.l_mark[0].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[0].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<integer>",
		                                TREETAG_LINE,yystack.l_mark[0].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[0].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 101:
#line 2867 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[0].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[0].info.string,
		                                TREETAG_LINE,yystack.l_mark[0].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[0].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<char>",
		                                TREETAG_LINE,yystack.l_mark[0].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[0].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 102:
#line 2900 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[0].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[0].info.string,
		                                TREETAG_LINE,yystack.l_mark[0].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[0].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<string>",
		                                TREETAG_LINE,yystack.l_mark[0].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[0].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 103:
#line 2933 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[0].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[0].info.string,
		                                TREETAG_LINE,yystack.l_mark[0].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[0].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"eof",
		                                TREETAG_LINE,yystack.l_mark[0].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[0].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 104:
#line 2966 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-3].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-3].info.string,
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-1].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-1].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"succ",
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 105:
#line 3002 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-3].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-3].info.string,
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-1].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-1].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"pred",
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 106:
#line 3038 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-3].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-3].info.string,
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-1].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-1].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"ord",
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 107:
#line 3074 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[-3].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[-3].info.string,
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&yystack.l_mark[-1].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-1].dlist));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"chr",
		                                TREETAG_LINE,yystack.l_mark[-3].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[-3].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
case 108:
#line 3110 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-1].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-1].dlist));

		yyval.dlist = r;

             }
break;
case 109:
#line 3124 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-1].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-1].dlist));

		yyval.dlist = r;

             }
break;
case 110:
#line 3136 "code.y"
	{
		DLIST r;

		InitDList(&r);

		while (DCount(&yystack.l_mark[-2].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[-2].dlist));

		while (DCount(&yystack.l_mark[0].dlist) > 0)
		    DAddTail(&r,DRemHead(&yystack.l_mark[0].dlist));

		yyval.dlist = r;

             }
break;
case 111:
#line 3153 "code.y"
	{
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if (yystack.l_mark[0].info.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,yystack.l_mark[0].info.string,
		                                TREETAG_LINE,yystack.l_mark[0].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[0].info.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<identifier>",
		                                TREETAG_LINE,yystack.l_mark[0].info.line,
		                                TREETAG_COLUMN,yystack.l_mark[0].info.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		yyval.dlist = r;

             }
break;
#line 4044 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}

/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140422

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "Parser.y"
#include <stdio.h>
#include <assert.h>
#include "Tokenizer.h"
#include "Trees.h"
#include "Nonterminals.h"


extern TREENODE *root;
#define YYDEBUG 1
#line 12 "Parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
   TOKEN_INFO info;
   TREENODE *nodeptr;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 43 "y.tab.c"

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

#define MARK 257
#define NODE 258
#define OR 259
#define LIST 260
#define ACTION 261
#define IDENTIFIER 262
#define LITERAL 263
#define STRING 264
#define LIT 265
#define PIPE 266
#define STAR 267
#define PLUS 268
#define QUESTION 269
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    2,    3,    3,    3,    4,    4,    5,
    5,    6,    6,    6,    6,    7,    7,    7,    7,    8,
    8,    9,    9,    9,   10,   10,   11,   11,   12,   12,
   13,   13,   13,   13,
};
static const YYINT yylen[] = {                            2,
    3,    0,    2,    2,    1,    2,    3,    1,    1,    1,
    2,    4,    6,    5,    7,    2,    4,    3,    5,    0,
    1,    1,    2,    3,    1,    2,    1,    2,    1,    3,
    1,    1,    1,    2,
};
static const YYINT yydefred[] = {                         2,
    0,    0,    0,    0,    3,    0,    0,   10,    8,    9,
    0,    5,    0,   11,    0,    6,    0,    0,   29,    0,
    0,    0,   25,    0,    7,    0,    0,    0,    0,   12,
    0,    0,   26,    0,   32,   31,   33,   28,   30,    0,
    0,    0,   14,    0,   34,    0,   13,    0,    0,   17,
   15,    0,   19,
};
static const YYINT yydgoto[] = {                          1,
    2,    5,   11,   19,    7,    8,   31,   20,   21,   22,
   23,   24,   38,
};
static const YYINT yysindex[] = {                         0,
    0, -229, -256, -225,    0, -235, -256,    0,    0,    0,
  -21,    0,  -38,    0, -225,    0,  -23,  -38,    0,  -56,
 -240,  -23,    0, -226,    0,  -23,  -31,  -38, -231,    0,
  -51,  -23,    0,  -23,    0,    0,    0,    0,    0, -222,
  -48,  -38,    0,  -23,    0, -218,    0,  -45, -214,    0,
    0, -216,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,   49,    0,    0,    0,
 -213,    0,  -55,    0,    0,    0,    0,    0,    0,    0,
  -52,  -32,    0,  -40,    0,  -29,    0,  -55,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -44,
    0,  -55,    0,  -28,    0,    0,    0,    0,  -43,    0,
    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,   21,    0,   43,   10,   -7,   34,  -12,
   -4,   19,    0,
};
#define YYTABLESIZE 242
static const YYINT yytable[] = {                         27,
   27,   18,   30,   20,   26,    6,   21,   43,   22,   39,
   47,   23,   24,   51,   16,   18,   18,   33,   27,   44,
   40,   33,   15,   13,   12,   32,   22,    3,    4,   23,
   24,   16,   41,   34,   49,   25,    9,   10,   46,   33,
   35,   36,   37,    4,    4,   50,   52,   53,    1,   14,
   48,   27,   45,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   28,   20,   29,   20,   21,   42,   21,    0,
   28,    0,    0,   42,   16,   18,    0,    0,   27,    0,
   27,   27,   27,    9,   10,   27,   22,   17,   22,   23,
   24,   23,   24,   22,   32,    0,   23,   24,    9,   10,
    9,   10,
};
static const YYINT yycheck[] = {                         40,
   41,   40,   59,   59,   17,  262,   59,   59,   41,   41,
   59,   41,   41,   59,   59,   59,   40,   22,   59,   32,
   28,   26,   44,  259,    4,  266,   59,  257,  258,   59,
   59,   11,  264,  260,   42,   15,  262,  263,  261,   44,
  267,  268,  269,  257,  258,  264,  261,  264,    0,    7,
   41,   18,   34,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  259,  259,  261,  261,  259,  259,  261,   -1,
  259,   -1,   -1,  259,  259,  259,   -1,   -1,  259,   -1,
  261,  262,  263,  262,  263,  266,  259,  266,  261,  259,
  259,  261,  261,  266,  266,   -1,  266,  266,  262,  263,
  262,  263,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 269
#define YYUNDFTOKEN 285
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'",0,0,"','",0,0,0,0,0,0,0,0,0,0,0,0,0,0,"';'",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"MARK","NODE",
"OR","LIST","ACTION","IDENTIFIER","LITERAL","STRING","LIT","PIPE","STAR","PLUS",
"QUESTION",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : spec",
"spec : defs MARK rules",
"defs :",
"defs : defs def",
"def : NODE nlist",
"nlist : yid",
"nlist : nlist yid",
"nlist : nlist ',' yid",
"yid : IDENTIFIER",
"yid : LITERAL",
"rules : rule",
"rules : rules rule",
"rule : IDENTIFIER OR rbody ';'",
"rule : IDENTIFIER OR rbody ACTION STRING ';'",
"rule : IDENTIFIER OR rbody or ';'",
"rule : IDENTIFIER OR rbody ACTION STRING or ';'",
"or : OR rbody",
"or : OR rbody ACTION STRING",
"or : or OR rbody",
"or : or OR rbody ACTION STRING",
"rbody :",
"rbody : rexp",
"rexp : term",
"rexp : PIPE term",
"rexp : rexp PIPE term",
"term : fact",
"term : term fact",
"fact : prim",
"fact : prim rop",
"prim : yid",
"prim : '(' rexp ')'",
"rop : PLUS",
"rop : STAR",
"rop : QUESTION",
"rop : LIST prim",

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
#line 26 "Parser.y"
	{
	      TREENODE *t;
	      t = AllocTreeNode(TREETAG_TOKEN,t_spec,
				TREETAG_STRING,"spec",
				TREETAG_DONE);

	      AddChildren(t,yystack.l_mark[-2].nodeptr,yystack.l_mark[0].nodeptr,NULL);
	      root = t;
          }
break;
case 2:
#line 38 "Parser.y"
	{
	      TREENODE *t;
	      t = AllocTreeNode(TREETAG_TOKEN,t_defs,
				TREETAG_STRING,"defs",
				TREETAG_DONE);

	      yyval.nodeptr = t;
          }
break;
case 3:
#line 47 "Parser.y"
	{
	      AddChild(yystack.l_mark[-1].nodeptr,yystack.l_mark[0].nodeptr);
	      yyval.nodeptr = yystack.l_mark[-1].nodeptr;
          }
break;
case 4:
#line 54 "Parser.y"
	{
	      yyval.nodeptr = yystack.l_mark[0].nodeptr;
          }
break;
case 5:
#line 60 "Parser.y"
	{
	      TREENODE *t;
	      t = AllocTreeNode(TREETAG_TOKEN,t_def,
				TREETAG_STRING,"def",
				TREETAG_DONE);

	      AddChild(t,yystack.l_mark[0].nodeptr);
	      yyval.nodeptr = t;
          }
break;
case 6:
#line 70 "Parser.y"
	{
	      AddChild(yystack.l_mark[-1].nodeptr,yystack.l_mark[0].nodeptr);
	      yyval.nodeptr = yystack.l_mark[-1].nodeptr;
          }
break;
case 7:
#line 75 "Parser.y"
	{
	      AddChild(yystack.l_mark[-2].nodeptr,yystack.l_mark[0].nodeptr);
	      yyval.nodeptr = yystack.l_mark[-2].nodeptr;
          }
break;
case 8:
#line 82 "Parser.y"
	{
	      TREENODE *t;
	      t = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[0].info.token,
				TREETAG_STRING,yystack.l_mark[0].info.string,
				TREETAG_LINE,yystack.l_mark[0].info.line,
				TREETAG_COLUMN,yystack.l_mark[0].info.column,
				TREETAG_DONE);

	      yyval.nodeptr = t; 
          }
break;
case 9:
#line 93 "Parser.y"
	{
	      TREENODE *t;
	      t = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[0].info.token,
				TREETAG_STRING,yystack.l_mark[0].info.string,
				TREETAG_LINE,yystack.l_mark[0].info.line,
				TREETAG_COLUMN,yystack.l_mark[0].info.column,
				TREETAG_DONE);

	      yyval.nodeptr = t;
          }
break;
case 10:
#line 108 "Parser.y"
	{
	      TREENODE *t;
	      t = AllocTreeNode(TREETAG_TOKEN,t_rules,
				TREETAG_STRING,"rules",
				TREETAG_DONE);

	      AddChild(t,yystack.l_mark[0].nodeptr);
	      yyval.nodeptr = t;
          }
break;
case 11:
#line 118 "Parser.y"
	{
	      AddChild(yystack.l_mark[-1].nodeptr,yystack.l_mark[0].nodeptr);
	      yyval.nodeptr = yystack.l_mark[-1].nodeptr;
          }
break;
case 12:
#line 125 "Parser.y"
	{
	      TREENODE *rule, *id, *or;
	      rule = AllocTreeNode(TREETAG_TOKEN,t_rule,
				   TREETAG_STRING,"rule",
				   TREETAG_DONE);

	      id = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-3].info.token,
				 TREETAG_STRING,yystack.l_mark[-3].info.string,
				 TREETAG_LINE,yystack.l_mark[-3].info.line,
				 TREETAG_COLUMN,yystack.l_mark[-3].info.column,
				 TREETAG_DONE);

	      or = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-2].info.token,
				 TREETAG_STRING,yystack.l_mark[-2].info.string,
				 TREETAG_LINE,yystack.l_mark[-2].info.line,
				 TREETAG_COLUMN,yystack.l_mark[-2].info.column,
				 TREETAG_DONE);

	      AddChild(or,yystack.l_mark[-1].nodeptr);
	      AddChildren(rule,id,or,NULL);
	      yyval.nodeptr = rule;
          }
break;
case 13:
#line 148 "Parser.y"
	{
	      TREENODE *rule, *id, *action, *string, *or;
	      rule = AllocTreeNode(TREETAG_TOKEN,t_rule,
				   TREETAG_STRING,"rule",
				   TREETAG_DONE);

	      id = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-5].info.token,
				 TREETAG_STRING,yystack.l_mark[-5].info.string,
				 TREETAG_LINE,yystack.l_mark[-5].info.line,
				 TREETAG_COLUMN,yystack.l_mark[-5].info.column,
				 TREETAG_DONE);

	      or = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-4].info.token,
				 TREETAG_STRING,yystack.l_mark[-4].info.string,
				 TREETAG_LINE,yystack.l_mark[-4].info.line,
				 TREETAG_COLUMN,yystack.l_mark[-4].info.column,
				 TREETAG_DONE);

	      action = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-2].info.token,
				     TREETAG_STRING,yystack.l_mark[-2].info.string,
				     TREETAG_LINE,yystack.l_mark[-2].info.line,
				     TREETAG_COLUMN,yystack.l_mark[-2].info.column,
				     TREETAG_DONE);

	      string = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-1].info.token,
				     TREETAG_STRING,yystack.l_mark[-1].info.string,
				     TREETAG_LINE,yystack.l_mark[-1].info.line,
				     TREETAG_COLUMN,yystack.l_mark[-1].info.column,
				     TREETAG_DONE);

	      AddChildren(or,yystack.l_mark[-3].nodeptr,action,string,NULL);
	      AddChildren(rule,id,or,NULL);
	      yyval.nodeptr = rule;
          }
break;
case 14:
#line 183 "Parser.y"
	{
	      TREENODE *rule, *id, *or, *t;
	      rule = AllocTreeNode(TREETAG_TOKEN,t_rule,
				   TREETAG_STRING,"rule",
				   TREETAG_DONE);

	      id = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-4].info.token,
				 TREETAG_STRING,yystack.l_mark[-4].info.string,
				 TREETAG_LINE,yystack.l_mark[-4].info.line,
				 TREETAG_COLUMN,yystack.l_mark[-4].info.column,
				 TREETAG_DONE);

	      or = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-3].info.token,
				 TREETAG_STRING,yystack.l_mark[-3].info.string,
				 TREETAG_LINE,yystack.l_mark[-3].info.line,
				 TREETAG_COLUMN,yystack.l_mark[-3].info.column,
				 TREETAG_DONE);

	      AddChild(or,yystack.l_mark[-2].nodeptr);
	      AddChildren(rule,id,or,yystack.l_mark[-1].nodeptr,NULL);
	      Lift(yystack.l_mark[-1].nodeptr);
	      /* FreeTreenodeTree($4); */
	      yyval.nodeptr = rule;
	  }
break;
case 15:
#line 208 "Parser.y"
	{
	      TREENODE *rule, *id, *or, *action, *string, *t;
	      rule = AllocTreeNode(TREETAG_TOKEN,t_rule,
				   TREETAG_STRING,"rule",
				   TREETAG_DONE);

	      id = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-6].info.token,
				 TREETAG_STRING,yystack.l_mark[-6].info.string,
				 TREETAG_LINE,yystack.l_mark[-6].info.line,
				 TREETAG_COLUMN,yystack.l_mark[-6].info.column,
				 TREETAG_DONE);

	      or = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-5].info.token,
				 TREETAG_STRING,yystack.l_mark[-5].info.string,
				 TREETAG_LINE,yystack.l_mark[-5].info.line,
				 TREETAG_COLUMN,yystack.l_mark[-5].info.column,
				 TREETAG_DONE);

	      action = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-3].info.token,
				     TREETAG_STRING,yystack.l_mark[-3].info.string,
				     TREETAG_LINE,yystack.l_mark[-3].info.line,
				     TREETAG_COLUMN,yystack.l_mark[-3].info.column,
				     TREETAG_DONE);

	      string = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-2].info.token,
				     TREETAG_STRING,yystack.l_mark[-2].info.string,
				     TREETAG_LINE,yystack.l_mark[-2].info.line,
				     TREETAG_COLUMN,yystack.l_mark[-2].info.column,
				     TREETAG_DONE);

	      AddChildren(or,yystack.l_mark[-4].nodeptr,action,string,NULL);
	      AddChildren(rule,id,or,yystack.l_mark[-1].nodeptr,NULL);
	      Lift(yystack.l_mark[-1].nodeptr);
	      /* FreeTreenodeTree($6); */
	      yyval.nodeptr = rule;
	  }
break;
case 16:
#line 247 "Parser.y"
	{
	      TREENODE *dummy, *or;
	      dummy = AllocTreeNode(TREETAG_STRING,"dummy",
				    TREETAG_DONE);
	      
	      or = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-1].info.token,
				 TREETAG_STRING,yystack.l_mark[-1].info.string,
				 TREETAG_LINE,yystack.l_mark[-1].info.line,
				 TREETAG_COLUMN,yystack.l_mark[-1].info.column,
				 TREETAG_DONE);


	      AddChild(or,yystack.l_mark[0].nodeptr);
	      AddChild(dummy,or);
	      yyval.nodeptr = dummy;
          }
break;
case 17:
#line 264 "Parser.y"
	{
              TREENODE *dummy, *or, *action, *string;
	      dummy = AllocTreeNode(TREETAG_STRING,"dummy",
				    TREETAG_DONE);

	      or = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-3].info.token,
				 TREETAG_STRING,yystack.l_mark[-3].info.string,
				 TREETAG_LINE,yystack.l_mark[-3].info.line,
				 TREETAG_COLUMN,yystack.l_mark[-3].info.column,
				 TREETAG_DONE);
				 
	      action = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-1].info.token,
				     TREETAG_STRING,yystack.l_mark[-1].info.string,
				     TREETAG_LINE,yystack.l_mark[-1].info.line,
				     TREETAG_COLUMN,yystack.l_mark[-1].info.column,
				     TREETAG_DONE);

	      string = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[0].info.token,
				     TREETAG_STRING,yystack.l_mark[0].info.string,
				     TREETAG_LINE,yystack.l_mark[0].info.line,
				     TREETAG_COLUMN,yystack.l_mark[0].info.column,
				     TREETAG_DONE);

	      AddChildren(or,yystack.l_mark[-2].nodeptr,action,string,NULL);
	      AddChild(dummy,or);
	      yyval.nodeptr = dummy;
	  }
break;
case 18:
#line 292 "Parser.y"
	{
	      TREENODE *or;

	      or = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-1].info.token,
				 TREETAG_STRING,yystack.l_mark[-1].info.string,
				 TREETAG_LINE,yystack.l_mark[-1].info.line,
				 TREETAG_COLUMN,yystack.l_mark[-1].info.column,
				 TREETAG_DONE);
	      
	      AddChild(or,yystack.l_mark[0].nodeptr);
	      AddChild(yystack.l_mark[-2].nodeptr,or);
	      yyval.nodeptr = yystack.l_mark[-2].nodeptr;
	  }
break;
case 19:
#line 306 "Parser.y"
	{
	      TREENODE *or, *action, *string;

	      or = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-3].info.token,
				 TREETAG_STRING,yystack.l_mark[-3].info.string,
				 TREETAG_LINE,yystack.l_mark[-3].info.line,
				 TREETAG_COLUMN,yystack.l_mark[-3].info.column,
				 TREETAG_DONE);

	      action = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-1].info.token,
				     TREETAG_STRING,yystack.l_mark[-1].info.string,
				     TREETAG_LINE,yystack.l_mark[-1].info.line,
				     TREETAG_COLUMN,yystack.l_mark[-1].info.column,
				     TREETAG_DONE);

	      string = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[0].info.token,
				     TREETAG_STRING,yystack.l_mark[0].info.string,
				     TREETAG_LINE,yystack.l_mark[0].info.line,
				     TREETAG_COLUMN,yystack.l_mark[0].info.column,
				     TREETAG_DONE);

	      AddChildren(or,yystack.l_mark[-2].nodeptr,action,string,NULL);
	      AddChild(yystack.l_mark[-4].nodeptr,or);
	      yyval.nodeptr = yystack.l_mark[-4].nodeptr;
	  }
break;
case 20:
#line 334 "Parser.y"
	{
	      TREENODE *t;
	      t = AllocTreeNode(TREETAG_TOKEN,t_empty,
				TREETAG_STRING,"empty",
				TREETAG_DONE);

	      yyval.nodeptr = t;
          }
break;
case 21:
#line 343 "Parser.y"
	{
	      yyval.nodeptr = yystack.l_mark[0].nodeptr;
          }
break;
case 22:
#line 350 "Parser.y"
	{
	      yyval.nodeptr = yystack.l_mark[0].nodeptr;
          }
break;
case 23:
#line 354 "Parser.y"
	{
	      TREENODE *t;
	      t = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-1].info.token,
				TREETAG_STRING,yystack.l_mark[-1].info.string,
				TREETAG_LINE,yystack.l_mark[-1].info.line,
				TREETAG_COLUMN,yystack.l_mark[-1].info.column,
				TREETAG_DONE);
	      AddChild(t,yystack.l_mark[0].nodeptr);
	      yyval.nodeptr = t;
          }
break;
case 24:
#line 365 "Parser.y"
	{
	      TREENODE *t;
	      t = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-1].info.token,
				TREETAG_STRING,yystack.l_mark[-1].info.string,
				TREETAG_LINE,yystack.l_mark[-1].info.line,
				TREETAG_COLUMN,yystack.l_mark[-1].info.column,
				TREETAG_DONE);
	      AddChildren(t,yystack.l_mark[-2].nodeptr,yystack.l_mark[0].nodeptr,NULL);
	      yyval.nodeptr = t;
          }
break;
case 25:
#line 378 "Parser.y"
	{
	      yyval.nodeptr = yystack.l_mark[0].nodeptr;
          }
break;
case 26:
#line 382 "Parser.y"
	{
	      TREENODE *t;
	      t = AllocTreeNode(TREETAG_TOKEN,t_catenate,
				TREETAG_STRING,"catenate",
				TREETAG_DONE);
	      AddChildren(t,yystack.l_mark[-1].nodeptr,yystack.l_mark[0].nodeptr,NULL);
	      yyval.nodeptr = t;
          }
break;
case 27:
#line 393 "Parser.y"
	{
	      yyval.nodeptr = yystack.l_mark[0].nodeptr;
          }
break;
case 28:
#line 397 "Parser.y"
	{
	      AddChild(yystack.l_mark[0].nodeptr,yystack.l_mark[-1].nodeptr);
	      yyval.nodeptr = yystack.l_mark[0].nodeptr;
          }
break;
case 29:
#line 405 "Parser.y"
	{
	      yyval.nodeptr = yystack.l_mark[0].nodeptr;
          }
break;
case 30:
#line 409 "Parser.y"
	{
	      yyval.nodeptr = yystack.l_mark[-1].nodeptr;
          }
break;
case 31:
#line 415 "Parser.y"
	{
	      TREENODE *t;
	      t = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[0].info.token,
				TREETAG_STRING,yystack.l_mark[0].info.string,
				TREETAG_LINE,yystack.l_mark[0].info.line,
				TREETAG_COLUMN,yystack.l_mark[0].info.column,
				TREETAG_DONE);
	      yyval.nodeptr = t;
          }
break;
case 32:
#line 425 "Parser.y"
	{
	      TREENODE *t;
	      t = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[0].info.token,
				TREETAG_STRING,yystack.l_mark[0].info.string,
				TREETAG_LINE,yystack.l_mark[0].info.line,
				TREETAG_COLUMN,yystack.l_mark[0].info.column,
				TREETAG_DONE);
	      yyval.nodeptr = t;
          }
break;
case 33:
#line 435 "Parser.y"
	{
	      TREENODE *t;
	      t = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[0].info.token,
				TREETAG_STRING,yystack.l_mark[0].info.string,
				TREETAG_LINE,yystack.l_mark[0].info.line,
				TREETAG_COLUMN,yystack.l_mark[0].info.column,
				TREETAG_DONE);
	      yyval.nodeptr = t;
          }
break;
case 34:
#line 445 "Parser.y"
	{
	      TREENODE *t;
	      t = AllocTreeNode(TREETAG_TOKEN,yystack.l_mark[-1].info.token,
				TREETAG_STRING,yystack.l_mark[-1].info.string,
				TREETAG_LINE,yystack.l_mark[-1].info.line,
				TREETAG_COLUMN,yystack.l_mark[-1].info.column,
				TREETAG_DONE);
	      AddChild(t,yystack.l_mark[0].nodeptr);
	      yyval.nodeptr = t;
          }
break;
#line 952 "y.tab.c"
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

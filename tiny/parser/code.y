%{
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

%}
%union {
   TOKEN_INFO info;
   DLIST dlist;
}
%token <info>  STRING
%token <info>  END
%token <info>  LGE
%token <info>  TO
%token <info>  VAR
%token <info>  IDENTIFIER
%token <info>  CHR
%token <info>  POOL
%token <info>  IF
%token <info>  FUNCTION
%token <info>  MUL
%token <info>  READ
%token <info>  REPEAT
%token <info>  RANGE
%token <info>  RETURN
%token <info>  ELSE
%token <info>  UEQ
%token <info>  UNTIL
%token <info>  SWAP
%token <info>  THEN
%token <info>  FOR
%token <info>  OF
%token <info>  CHARACTER
%token <info>  MOD
%token <info>  CASE
%token <info>  WHILE
%token <info>  OUTPUT
%token <info>  EXIT
%token <info>  PROCEDURE
%token <info>  CONST
%token <info>  PRED
%token <info>  NOT
%token <info>  DO
%token <info>  BEGINX
%token <info>  ORD
%token <info>  INTEGER_NUM
%token <info>  AND
%token <info>  EOFX
%token <info>  LTE
%token <info>  LOOP
%token <info>  SUCC
%token <info>  TYPE
%token <info>  OR
%token <info>  OTHERWISE
%token <info>  ASSIGNMENT
%token <info>  PROGRAM
%token <info>  DOWNTO
%type <dlist> Const
%type <dlist> Statement_1_1
%type <dlist> Statement_1_1_1_1_1
%type <dlist> Params_1
%type <dlist> Consts_1
%type <dlist> Lit_1
%type <dlist> Adv
%type <dlist> OTHER
%type <dlist> SCOPE
%type <dlist> MissValue
%type <dlist> Types_1
%type <dlist> Extra
%type <dlist> Params
%type <dlist> Function
%type <dlist> Primary_1
%type <dlist> EXPI
%type <dlist> Statement_1_1_1
%type <dlist> Types
%type <dlist> Tiny
%type <dlist> TheValue
%type <dlist> Statement_1
%type <dlist> Body_1
%type <dlist> Dcln
%type <dlist> Consts
%type <dlist> Statement
%type <dlist> Term
%type <dlist> Dcln_1
%type <dlist> Name
%type <dlist> CASE_CLAUSE
%type <dlist> Body
%type <dlist> Dclns_1
%type <dlist> Lit
%type <dlist> Statement_1_1_1_1_1_1
%type <dlist> SubProgs_1
%type <dlist> Statement_1_1_1_1
%type <dlist> Type
%type <dlist> Expression
%type <dlist> Dclns
%type <dlist> Primary
%type <dlist> OTHER_1
%type <dlist> SubProgs
%%

Tiny     : PROGRAM  Name     ':'      Consts   Types    Dclns    SubProgs Body     Name     '.'      
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		while (DCount(&$4) > 0)
		    DAddTail(&r,DRemHead(&$4));

		while (DCount(&$5) > 0)
		    DAddTail(&r,DRemHead(&$5));

		while (DCount(&$6) > 0)
		    DAddTail(&r,DRemHead(&$6));

		while (DCount(&$7) > 0)
		    DAddTail(&r,DRemHead(&$7));

		while (DCount(&$8) > 0)
		    DAddTail(&r,DRemHead(&$8));

		while (DCount(&$9) > 0)
		    DAddTail(&r,DRemHead(&$9));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"program",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
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
         ;

Types    : TYPE     Types_1  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"types",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | 
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
		$$ = r;

             }
         ;

Types_1  : 
             {
		DLIST r;

		InitDList(&r);

		$$ = r;

             }
         | Type     ';'      Types_1  
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		$$ = r;

             }
         ;

Type     : Name     '='      Lit      
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

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
		$$ = r;

             }
         | Name     '='      Name     
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

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
		$$ = r;

             }
         ;

Lit      : '('      Lit_1    
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

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
		$$ = r;

             }
         ;

Lit_1    : Name     ')'      
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | Name     ','      Lit_1    
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		$$ = r;

             }
         ;

Consts   : CONST    Consts_1 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"consts",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | 
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
		$$ = r;

             }
         ;

Consts_1 : 
             {
		DLIST r;

		InitDList(&r);

		$$ = r;

             }
         | Const    ';'      Consts_1 
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		$$ = r;

             }
         ;

Const    : Name     '='      Expression 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

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
		$$ = r;

             }
         ;

Dclns    : VAR      Dclns_1  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"dclns",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | 
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
		$$ = r;

             }
         ;

Dclns_1  : 
             {
		DLIST r;

		InitDList(&r);

		$$ = r;

             }
         | Dcln     ';'      Dclns_1  
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		$$ = r;

             }
         ;

Dcln     : Dcln_1   
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

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
		$$ = r;

             }
         ;

Dcln_1   : Name     ':'      Name     
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		$$ = r;

             }
         | Name     ','      Dcln_1   
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		$$ = r;

             }
         ;

SubProgs : SubProgs_1 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

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
		$$ = r;

             }
         ;

SubProgs_1 : 
             {
		DLIST r;

		InitDList(&r);

		$$ = r;

             }
         | Function SubProgs_1 
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		$$ = r;

             }
         ;

Function : FUNCTION Name     Params   ':'      Name     ';'      Consts   Types    Dclns    Body     Name     ';'      
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		while (DCount(&$5) > 0)
		    DAddTail(&r,DRemHead(&$5));

		while (DCount(&$7) > 0)
		    DAddTail(&r,DRemHead(&$7));

		while (DCount(&$8) > 0)
		    DAddTail(&r,DRemHead(&$8));

		while (DCount(&$9) > 0)
		    DAddTail(&r,DRemHead(&$9));

		while (DCount(&$10) > 0)
		    DAddTail(&r,DRemHead(&$10));

		while (DCount(&$11) > 0)
		    DAddTail(&r,DRemHead(&$11));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"function",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | PROCEDURE Name     Params   ';'      Consts   Types    Dclns    Body     Name     ';'      
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		while (DCount(&$5) > 0)
		    DAddTail(&r,DRemHead(&$5));

		while (DCount(&$6) > 0)
		    DAddTail(&r,DRemHead(&$6));

		while (DCount(&$7) > 0)
		    DAddTail(&r,DRemHead(&$7));

		while (DCount(&$8) > 0)
		    DAddTail(&r,DRemHead(&$8));

		while (DCount(&$9) > 0)
		    DAddTail(&r,DRemHead(&$9));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"procedure",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;

Params   : '('      Params_1 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

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
		$$ = r;

             }
         | '('      ')'      
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
		$$ = r;

             }
         | 
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
		$$ = r;

             }
         ;

Params_1 : Dcln     ')'      
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | Dcln     ';'      Params_1 
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		$$ = r;

             }
         ;

Body     : BEGINX   Body_1   
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"block",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;

Body_1   : Statement END      
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		$$ = r;

             }
         | Statement ';'      Body_1   
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		$$ = r;

             }
         ;

Statement : LOOP     Statement_1 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"loop",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | CASE     Expression OF       Statement_1_1 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		if ($3.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$3.string,
		                                TREETAG_LINE,$3.line,
		                                TREETAG_COLUMN,$3.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$4) > 0)
		    DAddTail(&r,DRemHead(&$4));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"case",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | CASE     Expression OF       Statement_1_1_1 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		if ($3.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$3.string,
		                                TREETAG_LINE,$3.line,
		                                TREETAG_COLUMN,$3.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$4) > 0)
		    DAddTail(&r,DRemHead(&$4));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"case",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | REPEAT   Statement_1_1_1_1 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"repeat",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | FOR      Name     ASSIGNMENT Primary  DOWNTO   Primary  DO       Statement 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		if ($3.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$3.string,
		                                TREETAG_LINE,$3.line,
		                                TREETAG_COLUMN,$3.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$4) > 0)
		    DAddTail(&r,DRemHead(&$4));

		if ($5.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$5.string,
		                                TREETAG_LINE,$5.line,
		                                TREETAG_COLUMN,$5.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$6) > 0)
		    DAddTail(&r,DRemHead(&$6));

		if ($7.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$7.string,
		                                TREETAG_LINE,$7.line,
		                                TREETAG_COLUMN,$7.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$8) > 0)
		    DAddTail(&r,DRemHead(&$8));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"downto",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | FOR      Name     ASSIGNMENT Primary  TO       Primary  DO       Statement 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		if ($3.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$3.string,
		                                TREETAG_LINE,$3.line,
		                                TREETAG_COLUMN,$3.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$4) > 0)
		    DAddTail(&r,DRemHead(&$4));

		if ($5.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$5.string,
		                                TREETAG_LINE,$5.line,
		                                TREETAG_COLUMN,$5.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$6) > 0)
		    DAddTail(&r,DRemHead(&$6));

		if ($7.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$7.string,
		                                TREETAG_LINE,$7.line,
		                                TREETAG_COLUMN,$7.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$8) > 0)
		    DAddTail(&r,DRemHead(&$8));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"upto",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | Name     ASSIGNMENT Expression 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"assign",
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | OUTPUT   '('      Statement_1_1_1_1_1 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"output",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | READ     '('      Statement_1_1_1_1_1_1 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"read",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | IF       Expression THEN     Statement ELSE     Statement 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		if ($3.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$3.string,
		                                TREETAG_LINE,$3.line,
		                                TREETAG_COLUMN,$3.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$4) > 0)
		    DAddTail(&r,DRemHead(&$4));

		if ($5.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$5.string,
		                                TREETAG_LINE,$5.line,
		                                TREETAG_COLUMN,$5.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$6) > 0)
		    DAddTail(&r,DRemHead(&$6));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"if",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | IF       Expression THEN     Statement 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		if ($3.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$3.string,
		                                TREETAG_LINE,$3.line,
		                                TREETAG_COLUMN,$3.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$4) > 0)
		    DAddTail(&r,DRemHead(&$4));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"if",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | WHILE    Expression DO       Statement 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		if ($3.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$3.string,
		                                TREETAG_LINE,$3.line,
		                                TREETAG_COLUMN,$3.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$4) > 0)
		    DAddTail(&r,DRemHead(&$4));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"while",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | Body     
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | Primary  SWAP     Primary  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"swap",
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | EXIT     
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"exit",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | Expression 
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | RETURN   MissValue 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"return",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | RETURN   '('      Expression ')'      
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"return",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | 
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
		$$ = r;

             }
         ;

Statement_1_1_1_1_1_1 : Expression ')'      
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | Expression ','      Statement_1_1_1_1_1_1 
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		$$ = r;

             }
         ;

Statement_1_1_1_1_1 : Expression ')'      
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | Expression ','      Statement_1_1_1_1_1 
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		$$ = r;

             }
         ;

Statement_1_1_1_1 : Statement UNTIL    Expression 
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		$$ = r;

             }
         | Statement ';'      Statement_1_1_1_1 
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		$$ = r;

             }
         ;

Statement_1_1_1 : END      
             {
		DLIST r;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		$$ = r;

             }
         | CASE_CLAUSE ';'      Statement_1_1_1 
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		$$ = r;

             }
         ;

Statement_1_1 : OTHER    END      
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		$$ = r;

             }
         | CASE_CLAUSE ';'      Statement_1_1 
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		$$ = r;

             }
         ;

Statement_1 : Statement POOL     
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		$$ = r;

             }
         | Statement ';'      Statement_1 
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		$$ = r;

             }
         ;

MissValue : TheValue 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

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
		$$ = r;

             }
         ;

TheValue : 
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
		$$ = r;

             }
         ;

OTHER    : OTHERWISE Statement OTHER_1  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"otherwise",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;

OTHER_1  : 
             {
		DLIST r;

		InitDList(&r);

		$$ = r;

             }
         | ';'      OTHER_1  
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		$$ = r;

             }
         ;

CASE_CLAUSE : Primary  ':'      Statement 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

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
		$$ = r;

             }
         | SCOPE    ':'      Statement 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

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
		$$ = r;

             }
         ;

SCOPE    : Primary  RANGE    Primary  
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"..",
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;

Expression : Term     
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | Term     LTE      Term     
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<=",
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | Term     '='      Term     
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

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
		$$ = r;

             }
         | Term     UEQ      Term     
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<>",
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | Term     LGE      Term     
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,">=",
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | Term     '<'      Term     
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

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
		$$ = r;

             }
         | Term     '>'      Term     
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

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
		$$ = r;

             }
         ;

Term     : Adv      
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | Term     '+'      Adv      
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

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
		$$ = r;

             }
         | Term     '-'      Adv      
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

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
		$$ = r;

             }
         | Term     OR       Adv      
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"or",
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;

Adv      : Extra    
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | Adv      '*'      Extra    
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

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
		$$ = r;

             }
         | Adv      '/'      Extra    
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

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
		$$ = r;

             }
         | Adv      AND      Extra    
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"and",
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | Adv      MOD      Extra    
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"mod",
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;

Extra    : EXPI     
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | '-'      Extra    
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

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
		$$ = r;

             }
         | '+'      Extra    
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

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
		$$ = r;

             }
         | NOT      Extra    
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"not",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;

EXPI     : Primary  
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | Primary  MUL      EXPI     
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		if ($2.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$2.string,
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"**",
		                                TREETAG_LINE,$2.line,
		                                TREETAG_COLUMN,$2.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;

Primary  : Name     
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | Name     '('      ')'      
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

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
		$$ = r;

             }
         | Name     '('      Primary_1 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

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
		$$ = r;

             }
         | INTEGER_NUM 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<integer>",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | CHARACTER 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<char>",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | STRING   
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<string>",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | EOFX     
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"eof",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | SUCC     '('      Expression ')'      
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"succ",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | PRED     '('      Expression ')'      
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"pred",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | ORD      '('      Expression ')'      
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"ord",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | CHR      '('      Expression ')'      
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"chr",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         | '('      Expression ')'      
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$2) > 0)
		    DAddTail(&r,DRemHead(&$2));

		$$ = r;

             }
         ;

Primary_1 : Expression ')'      
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		$$ = r;

             }
         | Expression ','      Primary_1 
             {
		DLIST r;

		InitDList(&r);

		while (DCount(&$1) > 0)
		    DAddTail(&r,DRemHead(&$1));

		while (DCount(&$3) > 0)
		    DAddTail(&r,DRemHead(&$3));

		$$ = r;

             }
         ;

Name     : IDENTIFIER 
             {
		DLIST r;
		T_NODE *t;

		InitDList(&r);

		if ($1.makenode) {
		    T_NODE *t2;
		    t2 = (T_NODE *)malloc(sizeof(T_NODE));
		    assert(t2);
		    t2->nodeptr = AllocTreeNode(TREETAG_STRING,$1.string,
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                                TREETAG_DONE);
		    DAddTail(&r,&t2->mynode);
		}

		t = (T_NODE *)malloc(sizeof(T_NODE));
		assert(t);
		t->nodeptr = AllocTreeNode(TREETAG_STRING,"<identifier>",
		                                TREETAG_LINE,$1.line,
		                                TREETAG_COLUMN,$1.column,
		                           TREETAG_DONE);
		while (DCount(&r) > 0) {
		    T_NODE *t3 = DRemHead(&r);
		    AddChild(t->nodeptr,t3->nodeptr);
		    free(t3);
		}
		DAddTail(&r,&t->mynode);
		$$ = r;

             }
         ;


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
extern YYSTYPE yylval;

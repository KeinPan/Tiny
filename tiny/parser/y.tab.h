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
extern YYSTYPE yylval;

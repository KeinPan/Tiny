/*******************************************************************
          Copyright (C) 1986 by Manuel E. Bermudez
          Translated to C - 1991
********************************************************************/

#include <stdio.h>
#include <header/CommandLine.h>
#include <header/Open_File.h>
#include <header/Table.h>
#include <header/Text.h>
#include <header/Error.h>
#include <header/String_Input.h>
#include <header/Tree.h>
#include <header/Code.h>
#include <header/CodeGenerator.h>  
#define LeftMode 0
#define RightMode 1

    /*  ABSTRACT MACHINE OPERATIONS  */
#define    NOP          1   /* 'NOP'       */
#define    HALTOP       2   /* 'HALT'      */      
#define    LITOP        3   /* 'LIT'       */
#define    LLVOP        4   /* 'LLV'       */
#define    LGVOP        5   /* 'LGV'       */
#define    SLVOP        6   /* 'SLV'       */
#define    SGVOP        7   /* 'SGV'       */
#define    LLAOP        8   /* 'LLA'       */
#define    LGAOP        9   /* 'LGA'       */
#define    UOPOP       10   /* 'UOP'       */
#define    BOPOP       11   /* 'BOP'       */     
#define    POPOP       12   /* 'POP'       */  
#define    DUPOP       13   /* 'DUP'       */
#define    SWAPOP      14   /* 'SWAP'      */
#define    CALLOP      15   /* 'CALL'      */
#define    RTNOP       16   /* 'RTN'       */
#define    GOTOOP      17   /* 'GOTO'      */
#define    CONDOP      18   /* 'COND'      */
#define    CODEOP      19   /* 'CODE'      */
#define    SOSOP       20   /* 'SOS'       */
#define    LIMITOP     21   /* 'LIMIT'     */

    /* ABSTRACT MACHINE OPERANDS */

         /* UNARY OPERANDS */
#define    UNOT        22   /* 'UNOT'     */
#define    UNEG        23   /* 'UNEG'     */
#define    USUCC       24   /* 'USUCC'    */
#define    UPRED       25   /* 'UPRED'    */
         /* BINARY OPERANDS */
#define    BAND        26   /* 'BAND'     */
#define    BOR         27   /* 'BOR'      */
#define    BPLUS       28   /* 'BPLUS'    */
#define    BMINUS      29   /* 'BMINUS'   */
#define    BMULT       30   /* 'BMULT'    */
#define    BDIV        31   /* 'BDIV'     */
#define    BEXP        32   /* 'BEXP'     */
#define    BMOD        33   /* 'BMOD'     */
#define    BEQ         34   /* 'BEQ'      */
#define    BNE         35   /* 'BNE'      */
#define    BLE         36   /* 'BLE'      */
#define    BGE         37   /* 'BGE'      */
#define    BLT         38   /* 'BLT'      */
#define    BGT         39   /* 'BGT'      */
         /* OS SERVICE CALL OPERANDS */
#define    TRACEX      40   /* 'TRACEX'   */
#define    DUMPMEM     41   /* 'DUMPMEM'  */
#define    OSINPUT     42   /* 'INPUT'    */
#define    OSINPUTC    43   /* 'INPUT'    */
#define    OSOUTPUT    44   /* 'OUTPUT'   */
#define    OSOUTPUTC   45   /* 'OUTPUT'   */
#define    OSOUTPUTL   46   /* 'OUTPUTL'  */
#define    OSEOF       47   /* 'EOF'      */

         /* TREE NODE NAMES */
#define    ProgramNode  48   /* 'program'  */
#define    TypesNode    49   /* 'types'    */
#define    TypeNode     50   /* 'type'     */
#define    DclnsNode    51   /* 'dclns'    */
#define    DclnNode     52   /* 'dcln'     */
#define    IntegerTNode 53   /* 'integer'  */
#define    BooleanTNode 54   /* 'boolean'  */
#define    BlockNode    55   /* 'block'    */
#define    AssignNode   56   /* 'assign'   */
#define    OutputNode   57   /* 'output'   */ 
#define    IfNode       58   /* 'if'       */
#define    WhileNode    59   /* 'while'    */
#define    NullNode     60   /* '<null>'   */
#define    LENode       61   /* '<='       */
#define    PlusNode     62   /* '+'        */
#define    MinusNode    63   /* '-'        */
#define    ReadNode     64   /* 'read'     */
#define    IntegerNode  65   /* '<integer>'*/
#define    IdentifierNode 66 /* '<identifier>'*/

#define    EQUALNode      67 /* '='        */
#define    UNEQUALNode    68 /* '<>'       */
#define    BENode         69 /* '>='       */
#define    LTNode         70 /* '<'        */
#define    BGNode         71 /* '>'        */
#define    ORNode         72 /* 'or'       */
#define    MULTIPLYNode   73 /* '*'        */
#define    DEVIDENode     74 /* '/'        */
#define    ANDNode        75 /* 'and'      */
#define    MODNode        76 /* 'mod'      */
#define    NOTNode        77 /* 'not'      */
#define    EXPNode        78 /* 'exp'      */
#define    TRUENode       79 /* 'true'     */
#define    FALSENode      80 /* 'false'    */
#define    EOFNode        81 /* 'eof'      */

#define    SWAPNode       82 /* 'swap'     */
#define    EXITNode       83 /* 'exit'     */
#define    UPTONode       84 /* 'upto'     */
#define    DOWNTONode     85 /* 'downto'   */
#define    REPEATNode     86 /* 'repeat'   */
#define    LOOPNode       87 /* 'loop'     */
#define    CASENode       88 /* 'case'     */
#define    CASECLAUSENode 89 /* 'clause'   */
#define    RANGENode      90 /* '..'       */
#define    OTHERWISENode  91 /* 'otherwise'*/
#define    CharTNode      92 /* 'char'     */
#define    CharNode       93 /* '<char>'   */
#define    ConstsNode     94 /* 'consts'   */
#define    ConstNode      95 /* 'const'    */
#define    LitNode        96 /* 'lit'      */
#define    SuccNode       97 /* 'succ'     */
#define    PredNode       98 /* 'pred'     */
#define    OrdNode        99 /* 'ord'      */
#define    ChrNode       100 /* 'chr'      */


#define    NumberOfNodes  100 /* '<identifier>'*/
typedef int Mode;

FILE *CodeFile;
char *CodeFileName;
Clabel HaltLabel;

char *mach_op[] = 
    {"NOP","HALT","LIT","LLV","LGV","SLV","SGV","LLA","LGA",
     "UOP","BOP","POP","DUP","SWAP","CALL","RTN","GOTO","COND",
     "CODE","SOS","LIMIT","UNOT","UNEG","USUCC","UPRED","BAND",
     "BOR","BPLUS","BMINUS","BMULT","BDIV","BEXP","BMOD","BEQ",
     "BNE","BLE","BGE","BLT","BGT","TRACEX","DUMPMEM","INPUT",
     "INPUTC","OUTPUT","OUTPUTC","OUTPUTL","EOF"};

/****************************************************************** 
   add new node names to the end of the array, keeping in strict order
   as defined above, then adjust the j loop control variable in
   InitializeNodeNames(). 
*******************************************************************/
char *node_name[] =
    {"program","types","type","dclns","var","integer",
     "boolean","block","assign","output","if","while",
     "<null>","<=","+","-","read","<integer>","<identifier>",
     "=", "<>",">=", "<", ">", "or", "*", "/", "and", "mod",
     "not", "**", "true", "false", "eof","swap","exit", 
     "upto", "downto", "repeat", "loop", "case","case_clause",
     "..", "otherwise", "char", "<char>", "consts", "const", "lit",
     "succ", "pred", "ord", "chr"};

int _Mode, value, address;
int ExType = 0;

void CodeGenerate(int argc, char *argv[])
{
   int NumberTrees;

   InitializeCodeGenerator(argc,argv);
   Tree_File = Open_File("_TREE", "r"); 
   NumberTrees = Read_Trees();
   fclose (Tree_File);                     

   HaltLabel = ProcessNode (RootOfTree(1), NoLabel);
   CodeGen0 (HALTOP, HaltLabel); 

   CodeFile = Open_File (CodeFileName, "w");
   DumpCode (CodeFile);
   fclose(CodeFile); 

   if (TraceSpecified)
      fclose (TraceFile);

/****************************************************************** 
  enable this code to write out the tree after the code generator
  has run.  It will show the new decorations made with MakeAddress().
*******************************************************************/


   Tree_File = fopen("_TREE", "w");  
   Write_Trees();
   fclose (Tree_File);                   
}


void InitializeCodeGenerator(int argc,char *argv[])
{
   InitializeMachineOperations();
   InitializeNodeNames();
   FrameSize = 0;
   CurrentProcLevel = 0;
   LabelCount = 0;
   CodeFileName = System_Argument("-code", "_CODE", argc, argv); 
}


void InitializeMachineOperations(void)
{
   int i,j;

   for (i=0, j=1; i < 47; i++, j++)
      String_Array_To_String_Constant (mach_op[i],j);
}



void InitializeNodeNames(void)
{
   int i,j;

   for (i=0, j=48; j <= NumberOfNodes; i++, j++)
      String_Array_To_String_Constant (node_name[i],j);
}



String MakeStringOf(int Number)
{
   Stack Temp;

   Temp = AllocateStack (50);
   ResetBufferInTextTable();
   if (Number == 0)
      AdvanceOnCharacter ('0');
   else
   {
      while (Number > 0)
      {
         Push (Temp,(Number % 10) + 48);
         Number /= 10;
      }

      while ( !(IsEmpty (Temp)))
         AdvanceOnCharacter ((char)(Pop(Temp)));
   }   
   return (ConvertStringInBuffer()); 
}  



void Reference(TreeNode T, Mode M, Clabel L)
{
   int Addr,OFFSET;
   String  Op;
   TreeNode temp1, temp2;

   Addr = Decoration(Decoration(T));
   OFFSET = FrameDisplacement (Addr) ;
   switch (M)
   {
      case LeftMode  :  DecrementFrameSize();
                        if (ProcLevel (Addr) == 0) 
                           Op = SGVOP;
                        else
                           Op = SLVOP;
                        /* we deal with the limit here*/
			/* T is the <id> Node */
			temp1 = Decoration(Child(Decoration(T), 1));     /* the var*/
			temp2 = Decoration(Decoration(Child(temp1,NKids(temp1)))); /*the type*/
			if((Rank(temp2) == 2) && (NodeName(Child(temp2,2)) == LitNode))  /*this is an enum*/
			{
			  CodeGen1 (LITOP, MakeStringOf(0) , NoLabel); /*L*/
			  CodeGen1 (LITOP, MakeStringOf(Rank(Child(temp2,2))-1) , NoLabel); /*U*/
			  CodeGen0 (LIMITOP, NoLabel);
			}
	                break;
      case RightMode :  IncrementFrameSize();
                        if (ProcLevel (Addr) == 0) 
                           Op = LGVOP;
          	        else
                           Op = LLVOP;
                        break;
   }
   CodeGen1 (Op,MakeStringOf(OFFSET),L);
}



int NKids (TreeNode T)
{
   return (Rank(T));
}

/*input is a const node, and return the value of this const var*/
int FindValue(TreeNode T)
{
  switch(NodeName(Child(T,2)))
         {
            case IntegerNode: value = NodeName (Child(Child(T,2), 1)); break;
            case CharNode:    value = MakeStringOf(Character(NodeName(Child(Child(T,2),1)), 2)); break;
            case IdentifierNode: 
              value = Decoration(Decoration(Child(T,2)));
              break;
            default:;
          }
 
  return value;     
}

/* find type of a const*/
int FindType(TreeNode T)
{
  int type_const = 0;
  switch(NodeName(Child(T,2)))
         {
            case IntegerNode: type_const = IntegerTNode; break;
            case CharNode:    type_const = CharTNode; break;
            case IdentifierNode: 
              type_const = FindType(Decoration(Child(Decoration(Child(T,2)),1)));        
              break;
            default:;
          }
  return type_const;     
}


void Expression (TreeNode T, Clabel CurrLabel)
{
   int Kid;
   Clabel Label1;
   TreeNode temp;   

   if (TraceSpecified)
   {
      fprintf (TraceFile, "<<< CODE GENERATOR >>> Processing Node ");
      Write_String (TraceFile, NodeName (T) );
      fprintf (TraceFile, " , Label is  ");
      Write_String (TraceFile, CurrLabel);
      fprintf (TraceFile, "\n");
   }

   switch (NodeName(T))
   {
      case LENode :
         Expression ( Child(T,1) , CurrLabel);
         Expression ( Child(T,2) , NoLabel);
         CodeGen1 (BOPOP, BLE, NoLabel);
         DecrementFrameSize();
	 ExType = 2;
         break;

      case EQUALNode :
         Expression ( Child(T,1) , CurrLabel);
         Expression ( Child(T,2) , NoLabel);
         CodeGen1 (BOPOP, BEQ, NoLabel);
         DecrementFrameSize();
	 ExType = 2;
         break;

      case UNEQUALNode :
         Expression ( Child(T,1) , CurrLabel);
         Expression ( Child(T,2) , NoLabel);
         CodeGen1 (BOPOP, BNE, NoLabel);
         DecrementFrameSize();
	 ExType = 2;
         break;

      case BENode :
         Expression ( Child(T,1) , CurrLabel);
         Expression ( Child(T,2) , NoLabel);
         CodeGen1 (BOPOP, BGE, NoLabel);
         DecrementFrameSize();
	 ExType = 2;
         break;

      case LTNode :
         Expression ( Child(T,1) , CurrLabel);
         Expression ( Child(T,2) , NoLabel);
         CodeGen1 (BOPOP, BLT, NoLabel);
         DecrementFrameSize();
	 ExType = 2;
         break;

      case BGNode :
         Expression ( Child(T,1) , CurrLabel);
         Expression ( Child(T,2) , NoLabel);
         CodeGen1 (BOPOP, BGT, NoLabel);
         DecrementFrameSize();
	 ExType = 2;
         break;

      case ORNode :
         Expression ( Child(T,1) , CurrLabel);
         Expression ( Child(T,2) , NoLabel);
         CodeGen1 (BOPOP, BOR, NoLabel);
         DecrementFrameSize();
	 ExType = 2;
         break;

     case ANDNode :
         Expression ( Child(T,1) , CurrLabel);
         Expression ( Child(T,2) , NoLabel);
         CodeGen1 (BOPOP, BAND, NoLabel);
         DecrementFrameSize();
	 ExType = 2;
         break;

     case MODNode :
         Expression ( Child(T,1) , CurrLabel);
         Expression ( Child(T,2) , NoLabel);
         CodeGen1 (BOPOP, BMOD, NoLabel);
         DecrementFrameSize();
	 ExType = 0;
         break;

      case PlusNode :
         Expression ( Child(T,1) , CurrLabel);
         if (Rank(T) == 2)
         {
            Expression ( Child(T,2) , NoLabel);
            CodeGen1 (BOPOP, BPLUS, NoLabel);
            DecrementFrameSize();
         }
         else
            ;
         break;
         
      case MinusNode :
         Expression ( Child(T,1) , CurrLabel);
         if (Rank(T) == 2)
         {
            Expression ( Child(T,2) , NoLabel);
            CodeGen1 (BOPOP, BMINUS, NoLabel);
            DecrementFrameSize();
         }
         else
            CodeGen1 (UOPOP, UNEG, NoLabel);
         break;

      case MULTIPLYNode :
         Expression ( Child(T,1) , CurrLabel);
         Expression ( Child(T,2) , NoLabel);
         CodeGen1 (BOPOP, BMULT, NoLabel);
         DecrementFrameSize();
	 ExType = 0;
         break;

      case DEVIDENode :
         Expression ( Child(T,1) , CurrLabel);
         Expression ( Child(T,2) , NoLabel);
         CodeGen1 (BOPOP, BDIV, NoLabel);
         DecrementFrameSize();
	 ExType = 0;
         break;

      case EXPNode :
         Expression ( Child(T,1) , CurrLabel);
         Expression ( Child(T,2) , NoLabel);
         CodeGen1 (BOPOP, BEXP, NoLabel);
         DecrementFrameSize();
	 ExType = 0;
         break;

      case NOTNode :
         Expression ( Child(T,1) , CurrLabel);
         CodeGen1 (UOPOP, UNOT, NoLabel);
	 ExType = 2;
         break;

      case TRUENode:
         CodeGen1 (LITOP, MakeStringOf(1) , CurrLabel);
         IncrementFrameSize();
         break;
        
      case FALSENode:
         CodeGen1 (LITOP, MakeStringOf(0) , CurrLabel);
         IncrementFrameSize();
         break;

      case IntegerNode :
         CodeGen1 (LITOP, NodeName (Child(T,1)), CurrLabel);
         IncrementFrameSize();
	 ExType = 0;
         break;

      case CharNode :
         CodeGen1 (LITOP, MakeStringOf(Character(NodeName(Child(T,1)), 2)), CurrLabel);
         IncrementFrameSize();
	 ExType = 1;
         break;

      case EOFNode :
         CodeGen1 (SOSOP, OSEOF, CurrLabel);
         IncrementFrameSize();
         break;

      case SuccNode:
	 Expression ( Child(T,1) , CurrLabel);
	 CodeGen1 (LITOP, MakeStringOf(1) , NoLabel);
	 CodeGen1 (BOPOP, BPLUS, NoLabel);
         DecrementFrameSize();
	 break;

      case PredNode:
	 Expression ( Child(T,1) , CurrLabel);
	 CodeGen1 (LITOP, MakeStringOf(1) , NoLabel);
	 CodeGen1 (BOPOP, BMINUS, NoLabel);
         DecrementFrameSize();
	 break;

      case OrdNode:
	 Expression ( Child(T,1) , CurrLabel);
	 switch(ExType)
	 {
	   case 0:				
		break;/*finally we get an int inside*/
	   case 1:
		CodeGen1 (LITOP, MakeStringOf(48) , NoLabel);
	 	CodeGen1 (BOPOP, BMINUS, NoLabel);
		break;/*finally we get a char inside*/
	   case 2:
		break;/*finally we get an enum inside*/
	   default: ;
	 }
	 ExType = 0;
	 break;
   
      case ChrNode:
	 Expression ( Child(T,1) , CurrLabel);
	 CodeGen1 (LITOP, MakeStringOf(48) , NoLabel);
	 CodeGen1 (BOPOP, BPLUS, NoLabel);
	 ExType = 1;
         DecrementFrameSize();
	 break;

/* Use a global var Extype to store the type right now*/
      case IdentifierNode :
         _Mode = NodeName(Decoration(Child(Decoration(T),1)));
         switch(_Mode){
          case LitNode: /*mode is lit which means a litconst*/
	     ExType = 2; /* an enum*/
             CodeGen1 (LITOP, Decoration(Decoration(T)), CurrLabel);
             IncrementFrameSize();
	     break;
           case ConstNode: /*mode is const*/
             switch(FindType(Decoration(Child(Decoration(T),1))))
	     {
		case IntegerTNode:  ExType = 0;  break;
		case CharTNode:     ExType = 1;  break;
	     }
             CodeGen1 (LITOP, Decoration(Decoration(T)), CurrLabel);
             IncrementFrameSize();
             break;
           case DclnNode: /*mode is var, whether a normal var or enum*/
	     temp = Decoration(Child(Decoration(Child(Decoration(T),1)),NKids(Decoration(Child(Decoration(T),1))))); /* the <id> of type*/
             switch(NodeName(Child(temp,1)))
	     {
		case IntegerTNode:  ExType = 0; break;
		case CharTNode:     ExType = 1; break;
		default :           ExType = 2; 
	     }
             Reference (T,RightMode,CurrLabel);   
             break;           
         }
         break;


      default :
         ReportTreeErrorAt(T);
         printf ("<<< CODE GENERATOR >>> : UNKNOWN NODE NAME ");
         Write_String (stdout,NodeName(T));
         printf ("\n");

   } /* end switch */
} /* end Expression */



Clabel ProcessNode (TreeNode T, Clabel CurrLabel)
{
   int Kid, Num, VarType;
   Clabel Label1, Label2, Label3;
   TreeNode tempNode,tempNode2;
   
   if (TraceSpecified)
   {
      fprintf (TraceFile, "<<< CODE GENERATOR >>> Processing Node ");
      Write_String (TraceFile, NodeName (T) );
      fprintf (TraceFile, " , Label is  ");
      Write_String (TraceFile, CurrLabel);
      fprintf (TraceFile, "\n");
   }

   switch (NodeName(T))
   {
      case ProgramNode :
         CurrLabel = ProcessNode (Child(T,3),CurrLabel);  /*const node*/
         CurrLabel = ProcessNode (Child(T,4),CurrLabel);  /*2nd types node*/
         CurrLabel = ProcessNode (Child(T,NKids(T)-2),CurrLabel);
         CurrLabel = ProcessNode (Child(T,NKids(T)-1),NoLabel);
         return (CurrLabel);

      case TypesNode :
         for (Kid = 1; Kid <= NKids(T); Kid++)
            CurrLabel = ProcessNode (Child(T,Kid), CurrLabel);
         return (CurrLabel);

      case TypeNode :
 	 if ((Rank(T) == 2)&&(NodeName(Child(T,2)) == LitNode))
	 {
          for (Kid = 1; Kid <= NKids(Child(T,2)); Kid++)
	    {
	      Decorate ( Child(Child(T,2),Kid), MakeStringOf((Kid-1)));     
	    }
	 }  
         return (CurrLabel);

      
      case ConstsNode :
         for (Kid = 1; Kid <= NKids(T); Kid++)
            CurrLabel = ProcessNode (Child(T,Kid), CurrLabel);
         if (NKids(T) > 0)
            return (NoLabel);
         else
            return (CurrLabel);  

      case ConstNode : 
         CodeGen1 (LITOP,MakeStringOf(0),CurrLabel);
         Decorate ( Child(T,1), FindValue(T));
         IncrementFrameSize();
         return (NoLabel);                 

      
      case DclnsNode :
         for (Kid = 1; Kid <= NKids(T); Kid++)
            CurrLabel = ProcessNode (Child(T,Kid), CurrLabel);
         if (NKids(T) > 0)
            return (NoLabel);
         else
            return (CurrLabel);

      case DclnNode : /*represents for 'var' node*/
         _Mode = NodeName(Decoration(Child(Child(T,1),1)));
         for (Kid = 1; Kid < NKids(T); Kid++)
         {
            if (Kid != 1)
               CodeGen1 (LITOP,MakeStringOf(0),NoLabel);
            else
               CodeGen1 (LITOP,MakeStringOf(0),CurrLabel);
           switch(_Mode){
             case DclnNode:
               Num = MakeAddress();
               Decorate ( Child(T,Kid), Num);
               IncrementFrameSize();
             }
         }
         return (NoLabel);                 

      case BlockNode :
         for (Kid = 1; Kid <= NKids(T); Kid++)
            CurrLabel = ProcessNode (Child(T,Kid), CurrLabel);
         return (CurrLabel); 


      case AssignNode :
         Expression (Child(T,2), CurrLabel);
         Reference (Child(T,1), LeftMode, NoLabel);
         return (NoLabel);

      case ReadNode :
	tempNode = Decoration(Child(Decoration(Child(T,1)),1)); /* the 'var' node*/
	VarType  = Decoration(Child(tempNode,NKids(tempNode))) ; /* the <id> node under type node*/
	if(NodeName(Child(VarType,1)) == IntegerTNode)
	        CodeGen1 (SOSOP, OSINPUT, CurrLabel);
	else
		CodeGen1 (SOSOP, OSINPUTC, CurrLabel);
        IncrementFrameSize();
	Reference (Child(T,1), LeftMode, NoLabel);
	/* for the other kids*/  
	for (Kid = 2; Kid <= NKids(T); Kid++)
         {
            tempNode = Decoration(Child(Decoration(Child(T,Kid)),1)); /* the 'var' node*/
	    VarType  = Decoration(Child(tempNode,NKids(tempNode))) ; /* the <id> node under type node*/
	    if(NodeName(Child(VarType,1)) == IntegerTNode)
	        CodeGen1 (SOSOP, OSINPUT, CurrLabel);
	    else
		CodeGen1 (SOSOP, OSINPUTC, CurrLabel);
            IncrementFrameSize();
	    Reference (Child(T,Kid), LeftMode, NoLabel);
         }      
      return (NoLabel);

      case OutputNode :
	 Expression (Child(T,1), CurrLabel);
         if(ExType == 0) 
         {
           CodeGen1 (SOSOP, OSOUTPUT, NoLabel);
           DecrementFrameSize();
         }
         else if(ExType == 1)
         {
           CodeGen1 (SOSOP, OSOUTPUTC, NoLabel);
           DecrementFrameSize();
         }
	 else { ;} /* for enum*/
	/* for the other kids*/  
         for (Kid = 2; Kid <= NKids(T); Kid++)
         {
            Expression (Child(T,Kid), NoLabel);
	    if(ExType == 0) 
            {
             CodeGen1 (SOSOP, OSOUTPUT, NoLabel);
             DecrementFrameSize();
            }
            else if(ExType == 1)
            {
             CodeGen1 (SOSOP, OSOUTPUTC, NoLabel);
             DecrementFrameSize();
            }
	    else { ;} /* for enum*/
         }
         CodeGen1 (SOSOP, OSOUTPUTL, NoLabel);
         return (NoLabel);


      case IfNode :
         Expression (Child(T,1), CurrLabel);
         Label1 = MakeLabel();
         Label2 = MakeLabel();
         Label3 = MakeLabel();
         CodeGen2 (CONDOP,Label1,Label2, NoLabel);
         DecrementFrameSize();
         CodeGen1 (GOTOOP, Label3, ProcessNode (Child(T,2), Label1) );
         if (Rank(T) == 3)
            CodeGen0 (NOP, ProcessNode (Child(T,3),Label2));
         else
            CodeGen0 (NOP, Label2);
         return (Label3);                


      case WhileNode :
         if (CurrLabel == NoLabel) 
            Label1 = MakeLabel();
         else 
            Label1 = CurrLabel;
         Label2 = MakeLabel();
         Label3 = MakeLabel();
         Expression (Child(T,1), Label1);
         CodeGen2 (CONDOP, Label2, Label3, NoLabel);
         DecrementFrameSize();
         CodeGen1 (GOTOOP, Label1, ProcessNode (Child(T,2), Label2) );
         return (Label3);

       case SWAPNode:
	 Expression (Child(T,1), CurrLabel);
         Expression (Child(T,2), NoLabel);
         Reference (Child(T,1), LeftMode, NoLabel);
         Reference (Child(T,2), LeftMode, NoLabel);
         return (NoLabel);

       case REPEATNode:
         if (CurrLabel == NoLabel) 
            Label1 = MakeLabel();
         else 
            Label1 = CurrLabel;
         Label2 = MakeLabel();
         
         for (Kid = 1; Kid < NKids(T); Kid++)
         {
            if (Kid != 1)
               CurrLabel = ProcessNode (Child(T,Kid), CurrLabel);
            else
               CurrLabel = ProcessNode (Child(T,Kid), Label1);
         }
         Expression (Child(T,NKids(T)), CurrLabel);
         CodeGen2 (CONDOP, Label2, Label1, NoLabel);
         DecrementFrameSize();
         return (Label2);   
 
       case LOOPNode:
         if (CurrLabel == NoLabel) 
            Label2 = MakeLabel();
         else 
            Label2 = CurrLabel;

         Label1 = MakeLabel();
         Decorate(T,Label1);

         for (Kid = 1; Kid < NKids(T); Kid++)
         {
            if (Kid != 1)
               CurrLabel = ProcessNode (Child(T,Kid), CurrLabel);
            else
               CurrLabel = ProcessNode (Child(T,Kid), Label2);
         }
         CodeGen1 (GOTOOP, Label2, ProcessNode (Child(T,NKids(T)), CurrLabel) );         
         return (Label1); 

       case EXITNode:
         Label1 = Decoration(Decoration(T));
         CodeGen1 (GOTOOP, Label1, CurrLabel);         
         return(NoLabel);         

       case UPTONode:
         Expression (Child(T,3), CurrLabel);
         Expression (Child(T,2), NoLabel);
         Reference (Child(T,1), LeftMode, NoLabel);
	 
         Label1 = MakeLabel();
         Label2 = MakeLabel();
         Label3 = MakeLabel();

         CodeGen0 (DUPOP, Label1);
         Reference (Child(T,1), RightMode,NoLabel);
         CodeGen1 (BOPOP, BGE, NoLabel);
         CodeGen2 (CONDOP,Label2,Label3, NoLabel);
         DecrementFrameSize();

         Reference (Child(T,1), RightMode, ProcessNode (Child(T,4), Label2));
         CodeGen1 (UOPOP, USUCC, NoLabel);
         Reference (Child(T,1), LeftMode, NoLabel);
         CodeGen1 (GOTOOP, Label1, NoLabel);         

         CodeGen1 (POPOP, MakeStringOf(1) , Label3);
         CodeGen1 (LITOP, MakeStringOf(0) , NoLabel);
	 Reference (Child(T,1), LeftMode, NoLabel);
         
         return(NoLabel);         

       case DOWNTONode:
         Expression (Child(T,3), CurrLabel);
         Expression (Child(T,2), NoLabel);
         Reference (Child(T,1), LeftMode, NoLabel);
	 
         Label1 = MakeLabel();
         Label2 = MakeLabel();
         Label3 = MakeLabel();

         CodeGen0 (DUPOP, Label1);
         Reference (Child(T,1), RightMode,NoLabel);
         CodeGen1 (BOPOP, BLE, NoLabel);
         CodeGen2 (CONDOP,Label2,Label3, NoLabel);
         DecrementFrameSize();

         Reference (Child(T,1), RightMode,ProcessNode (Child(T,4), Label2));
         CodeGen1 (UOPOP, UPRED, NoLabel);
         Reference (Child(T,1), LeftMode, NoLabel);
         CodeGen1 (GOTOOP, Label1, NoLabel);         

         CodeGen1 (POPOP, MakeStringOf(1) , Label3);
         CodeGen1 (LITOP, MakeStringOf(0) , NoLabel);
	 Reference (Child(T,1), LeftMode, NoLabel);
         
       return(NoLabel);

       case CASENode:
         Expression (Child(T,1), CurrLabel);
         CurrLabel = NoLabel;        
         Label3 = MakeLabel();
         for (Kid = 2; Kid < NKids(T); Kid++)
         {
         	if(NodeName(Child(Child(T,Kid),1)) == RANGENode) 
           	{
                CodeGen0 (DUPOP, CurrLabel);
                CodeGen0 (DUPOP, NoLabel);
                Expression (Child(Child(Child(T,Kid),1),1), NoLabel);
                CodeGen1 (BOPOP, BGE, NoLabel);
                CodeGen0 (SWAPOP,NoLabel);
                Expression (Child(Child(Child(T,Kid),1),2), NoLabel);
                CodeGen1 (BOPOP, BLE, NoLabel);
                CodeGen1 (BOPOP, BAND,NoLabel);

                Label1 = MakeLabel();
                Label2 = MakeLabel();

                CodeGen2 (CONDOP,Label1,Label2, NoLabel);
                DecrementFrameSize();
                CodeGen1 (POPOP, MakeStringOf(1) , Label1);
               
                CodeGen1 (GOTOOP, Label3, ProcessNode(Child(Child(T,Kid),2),NoLabel));         
                CurrLabel = Label2;
           	}
           	else
           	{
                CodeGen0 (DUPOP, CurrLabel);
                Expression (Child(Child(T,Kid),1), NoLabel);
                CodeGen1 (BOPOP, BEQ, NoLabel);
                
                Label1 = MakeLabel();
                Label2 = MakeLabel();

                CodeGen2 (CONDOP,Label1,Label2, NoLabel);
                DecrementFrameSize();
                CodeGen1 (POPOP, MakeStringOf(1) , Label1);

                CodeGen1 (GOTOOP, Label3, ProcessNode(Child(Child(T,Kid),2),NoLabel));         
                CurrLabel = Label2;
           	}
         }
	 

         if(CASECLAUSENode == NodeName(Child(T,NKids(T))))
         {
          
           if(NodeName(Child(Child(T,Kid),1)) == RANGENode) 
           {
                CodeGen0 (DUPOP, CurrLabel);
                CodeGen0 (DUPOP, NoLabel);
                Expression (Child(Child(Child(T,Kid),1),1), NoLabel);
                CodeGen1 (BOPOP, BGE, NoLabel);
                CodeGen0 (SWAPOP,NoLabel);
                Expression (Child(Child(Child(T,Kid),1),2), NoLabel);
                CodeGen1 (BOPOP, BLE, NoLabel);
                CodeGen1 (BOPOP, BAND,NoLabel);

                Label1 = MakeLabel();
                Label2 = MakeLabel();

                CodeGen2 (CONDOP,Label1,Label2, NoLabel);
                DecrementFrameSize();
                CodeGen1 (POPOP, MakeStringOf(1) , Label1);

                CodeGen1 (GOTOOP, Label3, ProcessNode(Child(Child(T,Kid),2),NoLabel));         
                CurrLabel = Label2;
           }
           else
           {
                CodeGen0 (DUPOP, CurrLabel);
                Expression (Child(Child(T,Kid),1), NoLabel);
                CodeGen1 (BOPOP, BEQ, NoLabel);
                
                Label1 = MakeLabel();
                Label2 = MakeLabel();

                CodeGen2 (CONDOP,Label1,Label2, NoLabel);
                DecrementFrameSize();
                CodeGen1 (POPOP, MakeStringOf(1) , Label1);

                CodeGen1 (GOTOOP, Label3, ProcessNode(Child(Child(T,Kid),2),NoLabel));                         
                CurrLabel = Label2;
           }
           CodeGen1 (POPOP, MakeStringOf(1) , CurrLabel);
           return(Label3);
         }

         else
         {
           CodeGen1 (POPOP, MakeStringOf(1) , CurrLabel);
           CodeGen1 (GOTOOP, Label3,ProcessNode(Child(Child(T,Kid),1),NoLabel));
           return(Label3);
         }

       case NullNode : return(CurrLabel);

 
      default :
              ReportTreeErrorAt(T);
              printf ("<<< CODE GENERATOR >>> : UNKNOWN NODE NAME ");
              Write_String (stdout,NodeName(T));
              printf ("\n");

   } /* end switch */
}   /* end ProcessNode */

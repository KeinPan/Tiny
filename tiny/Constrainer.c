/****************************************************************
              Copyright (C) 1986 by Manuel E. Bermudez
              Translated to C - 1991
*****************************************************************/

#include <stdio.h>
#include <header/Open_File.h>
#include <header/CommandLine.h>
#include <header/Table.h>
#include <header/Text.h>
#include <header/Error.h>
#include <header/String_Input.h> 
#include <header/Tree.h>
#include <header/Dcln.h>
#include <header/Constrainer.h>

#define ProgramNode    1
#define TypesNode      2
#define TypeNode       3
#define DclnsNode      4
#define DclnNode       5
#define IntegerTNode   6
#define BooleanTNode   7
#define BlockNode      8
#define AssignNode     9
#define OutputNode     10
#define IfNode         11
#define WhileNode      12
#define NullNode       13
#define LENode         14
#define PlusNode       15
#define MinusNode      16
#define ReadNode       17
#define IntegerNode    18
#define IdentifierNode 19

#define EQUALNode      20
#define UNEQUALNode    21
#define BENode         22
#define LTNode         23
#define BGNode         24
#define ORNode         25
#define MULTIPLYNode   26
#define DEVIDENode     27
#define ANDNode        28
#define MODNode        29
#define NOTNode        30
#define EXPNode        31
#define TRUENode       32
#define FALSENode      33
#define EOFNode        34

#define SWAPNode       35
#define EXITNode       36
#define UPTONode       37
#define DOWNTONode     38
#define REPEATNode     39
#define LOOPNode       40
#define CASENode       41
#define CASECLAUSENode 42
#define RANGENode      43
#define OTHERWISENode  44
#define LOOP_CTXT      45 
#define FOR_CTXT       46
#define CharTNode      47 
#define CharNode       48
#define ConstsNode     49
#define ConstNode      50
#define LitNode        51
#define SuccNode       52
#define PredNode       53
#define OrdNode        54
#define ChrNode        55
#define StringNode     56
#define SUBPROG_CTXT   57
#define SubprogsNode   58
#define FunctionNode   59
#define ProcedureNode  60
#define ParamsNode     61
#define ReturnNode     62
#define CallNode       63


#define NumberOfNodes  63


typedef TreeNode UserType;

/****************************************************************
 Add new node names to the end of the array, keeping in strict
  order with the define statements above, then adjust the i loop
  control variable in InitializeConstrainer().
*****************************************************************/
char *node[] = { "program", "types", "type", "dclns",
                 "var", "integer", "boolean", "block",
                 "assign", "output", "if", "while", 
                 "<null>", "<=", "+", "-", "read",
                 "<integer>", "<identifier>" , "=", "<>",
                 ">=", "<", ">", "or", "*", "/", "and", "mod",
                 "not", "**", "true", "false", "eof", "swap",
		 "exit", "upto", "downto", "repeat", "loop", "case",
		 "case_clause", "..", "otherwise","<loop_ctxt>",
                 "<for_ctxt>", "char", "<char>", "consts", "const",
                 "lit", "succ", "pred", "ord", "chr", "<string>",
		 "<subprog_contxt>", "subprogs", "function", "procedure",
		 "params", "return", "call"
                };



UserType TypeInteger, TypeBoolean, TypeChar,Type;
boolean TraceSpecified;
FILE *TraceFile;
char *TraceFileName;
int NumberTreesRead, index, Mode,CaseExp;
int DeathFlag = 0;

void Constrain(void)    
{
   int i;
   InitializeDeclarationTable();
   Tree_File = Open_File("_TREE", "r"); 
   NumberTreesRead = Read_Trees();
   fclose (Tree_File);                     

   AddIntrinsics();


#if 0
   printf("CURRENT TREE\n");
   for (i=1;i<=SizeOf(Tree);i++)
      printf("%2d: %d\n",i,Element(Tree,i));
#endif

   ProcessNode(RootOfTree(1)); 

    
   Tree_File = fopen("_TREE", "w");  
   Write_Trees();
   fclose (Tree_File);                   

   if (TraceSpecified)
      fclose(TraceFile);    

/* If DeathFlag is 1, it means we triggered a fatal error in the execution procedure. We delete the tree and prevent tiny from entering CG*/
   if (DeathFlag == 1)
   {
      remove("_TREE");
      printf("Thus:\n");
      printf("Constrainer Failed..\n");
      printf("We Removed the Tree File\n");
      printf("\n");
   }
}


void InitializeConstrainer (int argc, char *argv[])
{          
   int i, j;

   InitializeTextModule();
   InitializeTreeModule();

   for (i=0, j=1; i<NumberOfNodes; i++, j++)
      String_Array_To_String_Constant (node[i], j); 
 
   index = System_Flag ("-trace", argc, argv);
 
   if (index)                                       
   {
      TraceSpecified = true; 
      TraceFileName = System_Argument ("-trace", "_TRACE", argc, argv);
      TraceFile = Open_File(TraceFileName, "w");
   }
   else
      TraceSpecified = false;          
}                        


void AddIntrinsics (void)
{
   TreeNode TempTree;

   AddTree (TypesNode, RootOfTree(1), 2);

   TempTree = Child (RootOfTree(1), 2); /*types node*/
   AddTree (TypeNode, TempTree, 1);

   TempTree = Child (RootOfTree(1), 2);
   AddTree (TypeNode, TempTree, 1);

   TempTree = Child (RootOfTree(1), 2);
   AddTree (TypeNode, TempTree, 1);

/* boolean part below*/
   TempTree = Child (Child (RootOfTree(1), 2), 1); /*the 1st type node which represents the boolean*/
   AddTree (LitNode, TempTree, 1);

   TempTree = Child (Child (RootOfTree(1), 2), 1); 
   AddTree (IdentifierNode, TempTree, 1);

   TempTree = Child(Child (Child (RootOfTree(1), 2), 1),2); /*the lit node*/
   AddTree (IdentifierNode, TempTree, 1);
   TempTree = Child(Child (Child (RootOfTree(1), 2), 1),2); /*the lit node*/
   AddTree (IdentifierNode, TempTree, 1);

   TempTree = Child(Child(Child (Child (RootOfTree(1), 2), 1),2),1); /*the 1st <id> node*/
   AddTree (FALSENode, TempTree, 1);
   TempTree = Child(Child(Child (Child (RootOfTree(1), 2), 1),2),2); /*the 1st <id> node*/
   AddTree (TRUENode, TempTree, 1);
/* boolean part above*/

   TempTree = Child (Child (RootOfTree(1), 2), 2);
   AddTree (IdentifierNode, TempTree, 1);

   TempTree = Child (Child (RootOfTree(1), 2), 3);
   AddTree (IdentifierNode, TempTree, 1);

   TempTree = Child (Child (Child (RootOfTree(1), 2), 1), 1);
   AddTree (BooleanTNode, TempTree, 1);
 
   TempTree = Child (Child (Child (RootOfTree(1), 2), 2), 1);
   AddTree (IntegerTNode, TempTree, 1);

   TempTree = Child (Child (Child (RootOfTree(1), 2), 3), 1);
   AddTree (CharTNode, TempTree, 1);

   /*now modify the boolean*/
 
   /*move from typesnode here*/
   TypeBoolean = Child(Child (RootOfTree(1), 2),1);
   TypeInteger = Child(Child (RootOfTree(1), 2),2);
   TypeChar    = Child(Child (RootOfTree(1), 2),3);

}


 
void ErrorHeader (TreeNode T)
{ 
   printf ("<<< CONSTRAINER ERROR >>> AT ");
   Write_String (stdout,SourceLocation(T));
   printf (" : ");
   printf ("\n");
}


int NKids (TreeNode T)
{
   return (Rank(T));
}



UserType Expression (TreeNode T)
{
   UserType Type1, Type2,i,j; /* i, j is for compare*/
   TreeNode Declaration, Temp1, Temp2;
   int NodeCount,CountNum,Kid,TempMode;

   if (TraceSpecified)
   {
      fprintf (TraceFile, "<<< CONSTRAINER >>> : Expn Processor Node ");
      Write_String (TraceFile, NodeName(T));
      fprintf (TraceFile, "\n");
   }
     
   switch (NodeName(T))
   {
      case EQUALNode :
      case UNEQUALNode :        
      case BENode :    
      case LTNode :    
      case BGNode :    
      case LENode :    
         Type1 = Expression (Child(T,1));
         Type2 = Expression (Child(T,2));

         if (Type1 != Type2)
         {
            ErrorHeader(Child(T,1));
            printf ("ARGUMENTS OF ASSOCIATION OPERATOR NOT COMPATIBLE\n");
            printf ("\n");
         }
         return (TypeBoolean);

      case MULTIPLYNode :
      case DEVIDENode :
      case MODNode :                
      case EXPNode :        
      case PlusNode :
      case MinusNode : 
         Type1 = Expression (Child(T,1));

         if (Rank(T) == 2)
            Type2 = Expression (Child(T,2));
         else  
            Type2 = TypeInteger;

         if (Type1 != TypeInteger || Type2 != TypeInteger)
         {
            ErrorHeader(Child(T,1));
            printf ("ARGUMENTS OF '+', '-', '*', '/', mod ");
            printf ("MUST BE TYPE INTEGER\n");
            printf ("\n");
         }
         return (TypeInteger);

      case ANDNode :        
      case ORNode :
      case NOTNode : 
         Type1 = Expression (Child(T,1));

         if (Rank(T) == 2)
            Type2 = Expression (Child(T,2));
         else  
            Type2 = TypeBoolean;

         if (Type1 != TypeBoolean || Type2 != TypeBoolean)
         {
            ErrorHeader(Child(T,1));
            printf ("ARGUMENTS OF 'and', 'or', 'not' ");
            printf ("MUST BE TYPE BOOLEAN\n");
            printf ("\n");
         }
         return (TypeBoolean);

      case IntegerNode : 
         return (TypeInteger);

      case CharNode : 
         return (TypeChar);

      case EOFNode:
      case TRUENode :
      case FALSENode: 
         return (TypeBoolean);

      case SuccNode:
	Type1 = Expression(Child(T,1));
        if( (Type1 != TypeInteger)&&(Type1 != TypeChar) )
        {
          if ((Rank(Type1) != 2)||(NodeName(Child(Type1,2)) != LitNode )) 
          {
	    ErrorHeader(T);
            printf ("TYPE FOR SUCC() NOT COMPATIBLE\n");
            printf ("\n");
	  }
        }
        return(Type1);

       case PredNode:
	Type1 = Expression(Child(T,1));
        if( (Type1 != TypeInteger)&&(Type1 != TypeChar) )
        {
          if ((Rank(Type1) != 2)||(NodeName(Child(Type1,2)) != LitNode )) 
          {
	    ErrorHeader(T);
            printf ("TYPE FOR PRED() NOT COMPATIBLE\n");
            printf ("\n");
	  }
        }
        return(Type1);

      case OrdNode:
	Type1 = Expression(Child(T,1));
        if( (Type1 != TypeInteger)&&(Type1 != TypeChar) )
        {
          if ((Rank(Type1) != 2)||(NodeName(Child(Type1,2)) != LitNode )) /* not even an enum*/
          {
	    ErrorHeader(T);
            printf ("TYPE FOR ORD() NOT COMPATIBLE\n");
            printf ("\n");
	  }
        }
        return(TypeInteger);

      case ChrNode:
	Type1 = Expression(Child(T,1));
        if(Type1 != TypeInteger)
        {
	    ErrorHeader(T);
            printf ("TYPE FOR CHR() NOT COMPATIBLE\n");
            printf ("\n");
	    /*DeathFlag = 1;*/ /* Don't enter CG*/
        }
        return(TypeChar);

      case StringNode:
	 
	return(TypeChar);

      case IdentifierNode :
         Declaration = Lookup (NodeName(Child(T,1)), T);
         if (Declaration != NullDeclaration)
         {
            Decorate (T, Declaration);
            Type = Decoration(Declaration);
            Mode = NodeName(Decoration(Child(Declaration,1)));
            return (Type);
         }
         else
            return (TypeInteger);


      case CallNode:
	 Type1 = Expression(Child(T,1));
	 NodeCount = 1;  /* For type compare*/
         i = j = 1;
	 TempMode = Mode;
         if((Mode != FunctionNode)&&(Mode != ProcedureNode))
	 {
           ErrorHeader(T);
           printf ("MODE HERE SHOULD BE FUNCTION OR PROCEDURE\n");
           printf ("\n");
	   return(Type1);
         }
	 Temp1 = Decoration(Child(T,1));
	 Temp1 = Child(Decoration(Child(Temp1,1)),2); /* The params Node*/
	 /*count the elements*/
	 CountNum = 0;
	 for (Kid = 1; Kid <= Rank(Temp1); Kid++)
           CountNum += (Rank(Child(Temp1,Kid))-1);
         if(CountNum != (Rank(T)-1))
	 {
           ErrorHeader(T);
           printf ("NUMBER OF PARAMETERS INCOMPATIBLE\n");
           printf ("\n");
 	   return(Type1);
         }
	/* expression and types*/ 
	for(Kid =2; Kid <= Rank(T); Kid++)
	{
	  if( j >= NKids(Child(Temp1,i)))  /* j represent the order of node under var of params*/
	  {
	    i ++;
            j = 1;
	  }
	  if( Expression(Child(T,Kid)) != Decoration(Child(Child(Temp1,i),1)))
	  {
           ErrorHeader(T);
           printf ("PARAMS TYPE INCOMPATIBLE\n");
           printf ("\n");
          }
	  j++;
	}
	Mode = TempMode;
	 return(Type1);
	

      default :
         ErrorHeader(T);
         printf ( "UNKNOWN NODE NAME ");
         Write_String (stdout,NodeName(T));
         printf ("\n");

   }  /* end switch */
}  /* end Expression */




void ProcessNode (TreeNode T) 
{
   int Kid, N;
   String Name1, Name2;
   TreeNode Type1, Type2, Type3;
   TreeNode Declaration, Temp1, Temp2;
   if (TraceSpecified)
   {
      fprintf (TraceFile,
               "<<< CONSTRAINER >>> : Stmt Processor Node ");
      Write_String (TraceFile, NodeName(T));
      fprintf (TraceFile, "\n");
   }

   switch (NodeName(T))
   {
      case ProgramNode : 
         OpenScope();
         DTEnter(LOOP_CTXT,T,T);
         DTEnter(FOR_CTXT,T,T);
         DTEnter(SUBPROG_CTXT,T,T); /*CTXT FOR SUBPROGS*/
         Name1 = NodeName(Child(Child(T,1),1));
         Name2 = NodeName(Child(Child(T,NKids(T)),1));

         if (Name1 != Name2)
         {
           ErrorHeader(T);
           printf ("PROGRAM NAMES DO NOT MATCH\n");
           printf ("\n");
         }

         for (Kid = 2; Kid <= NKids(T)-1; Kid++)
            ProcessNode (Child(T,Kid));
         CloseScope();
         break;

      case SubprogsNode:
	 for (Kid = 1; Kid <= NKids(T); Kid++)
            ProcessNode (Child(T,Kid));  /* process all functions*/
	 break;
	
       case ProcedureNode:
	 if(NodeName(Child(Child(T,1),1)) != NodeName(Child(Child(T,NKids(T)),1)))  /*name for subprog*/
     	 {
           ErrorHeader(T);
           printf ("PROCEDURE NAMES DO NOT MATCH\n");
           printf ("\n");
         }
         DTEnter (NodeName(Child(Child(T,1),1)), Child(T,1), T);         
	 OpenScope();
	 DTEnter(SUBPROG_CTXT,T,T); 
	 /*
	 Temp1 = Lookup(NodeName(Child(Child(T,3),1)),T);
	 Decorate(Child(T,1),Decoration(Temp1));
	 */
	 Decorate(Child(Child(T,1),1),T);
         ProcessNode (Child(T,2));  /* process nodes  2 4 5 6 7 for a function*/
	 for (Kid = 3; Kid <= NKids(T)-1; Kid++)
           ProcessNode (Child(T,Kid));  
	 CloseScope();
	 break;

      case FunctionNode:
	 if(NodeName(Child(Child(T,1),1)) != NodeName(Child(Child(T,NKids(T)),1)))  /*name for subprog*/
     	 {
           ErrorHeader(T);
           printf ("SUBPROGRAM NAMES DO NOT MATCH\n");
           printf ("\n");
         }
         DTEnter (NodeName(Child(Child(T,1),1)), Child(T,1), T);         
	 OpenScope();
	 DTEnter(SUBPROG_CTXT,T,T); 
	 Temp1 = Lookup(NodeName(Child(Child(T,3),1)),T);
	 Decorate(Child(T,1),Decoration(Temp1));
	 Decorate(Child(Child(T,1),1),T);
         ProcessNode (Child(T,2));  /* process nodes  2 4 5 6 7 for a function*/
	 for (Kid = 4; Kid <= NKids(T)-1; Kid++)
           ProcessNode (Child(T,Kid));  
	 CloseScope();
	 break;

      case ParamsNode:
	  for (Kid = 1; Kid <= NKids(T); Kid++)
            ProcessNode (Child(T,Kid));  /* process all vars*/
	 break;

      case ReturnNode:
         if(Rank(T) != 0)
	{
	 Type1 = Expression(Child(T,1));
	 Temp1 = Lookup(SUBPROG_CTXT,T);
	 if(NodeName(Temp1) != FunctionNode)
 	 {
           ErrorHeader(T);
           printf ("RETURN MUST EXIST INSIDE A FUNCTION!\n");
           printf ("\n");		
	 }
         if(Decoration(Child(Temp1, 1)) != Type1)
	 {
           ErrorHeader(T);
           printf ("WRONG RETURN TYPE\n");
           printf ("\n");		
	 }
	}
	 break;

      case ConstsNode :  
         for (Kid = 1; Kid <= NKids(T); Kid++)
            ProcessNode (Child(T,Kid));
         break;

      case ConstNode:
	 Temp1 = Child(Child(T,2),1);
         if((NodeName(Temp1) == IntegerTNode)||(NodeName(Temp1) == CharTNode)||(NodeName(Temp1) == BooleanTNode))
	 {
           ErrorHeader(T);
           printf ("Constants can't be assigned a type\n");
           printf ("\n");		
	  /* DeathFlag = 1;*/
	 }
/*         DTEnter (NodeName(Child(Child(T,1),1)), Child(T,1), T);         */
         switch(NodeName(Child(T,2))){
           case IntegerNode:    Type1 = Child(Child (RootOfTree(1), 2), 2);break;
           case CharNode:       Type1 = Child(Child (RootOfTree(1), 2), 3);break;
           case IdentifierNode:  /*type2 is the dcln, and type1 is the type*/
             Name1 = NodeName (Child(Child(T, 2),1)); 
             Type2 = Lookup (Name1,T); 
             Decorate(Child(T,2),Type2); 
             Type1 = Decoration(Type2);
             break;
           default:             Type1 = Child(Child (RootOfTree(1), 2), 1);
         }
         Decorate (Child(T,1), Type1);
         Decorate (Child(Child(T,1),1), T);
	 DTEnter (NodeName(Child(Child(T,1),1)), Child(T,1), T);         
         break;
 
      case TypesNode :  
         for (Kid = 1; Kid <= NKids(T); Kid++)
            ProcessNode (Child(T,Kid));
         break;


      case TypeNode :
         if(Rank(T) == 1)
	 {
           DTEnter (NodeName(Child(Child(T,1),1)), Child(T,1), T);         
           Decorate (Child(T,1), T);
           Decorate (Child(Child(T,1),1), T);
	 }
         else if(NodeName(Child(T,2)) == LitNode)
         {
           DTEnter (NodeName(Child(Child(T,1),1)), Child(T,1), T);         
           Decorate (Child(T,1), T);
           Decorate (Child(Child(T,1),1), T);  /*left child*/
           
           for (Kid = 1; Kid <= NKids(Child(T,2)); Kid++)
           {
             DTEnter (NodeName(Child(Child(Child(T,2),Kid),1)), Child(Child(T,2),Kid), T);         
             Decorate (Child(Child(T,2),Kid), T);
             Decorate (Child(Child(Child(T,2),Kid),1), Child(T,2));  /*right child*/
           }
         }
         else if(NodeName(Child(T,2)) == IdentifierNode)    
         {
           OpenScope();
           DTEnter (NodeName(Child(Child(T,1),1)), Child(T,1), T);         
	   Decorate (Child(Child(T,1),1), T);
           Name1 = NodeName (Child(Child(T, NKids(T)),1));
           Type1 = Lookup (Name1,T);  /*the identifier node*/
           Type2 = Decoration(Child(Type1,1));  /*the type node*/
           while ((Rank(Type2) == 2)&&(NodeName(Child(Type2,2)) == IdentifierNode))
	   {
	     Type1 = Child(Decoration(Type1),1);
             Type2 = Decoration(Child(Type2,1));
	   }
           Decorate (Child(T,1), Type2);
           Decorate (Child(T,2), Type1);
	 }
         break;


      case DclnsNode :
         for (Kid = 1; Kid <= NKids(T); Kid++)
            ProcessNode (Child(T,Kid));
         break;


      case DclnNode :
	 Name1 = NodeName (Child(Child(T, NKids(T)),1));
         Type1 = Lookup (Name1,T);  /*the identifier node*/
 	 /*we need to deal with swapped type*/
	 if((Rank(Decoration(Child(Type1,1))) == 2 ) && (NodeName(Child(Decoration(Child(Type1,1)),2)) == IdentifierNode ))
	 {
	   Type1 = Child(Decoration(Type1),1);
	 }
         Type2 = Decoration(Child(Type1,1));  /*the type node*/
         for (Kid  = 1; Kid < NKids(T); Kid++)
         {
            DTEnter (NodeName(Child(Child(T,Kid),1)), Child(T,Kid), T);
            Decorate (Child(T,Kid), Type2);
            Decorate (Child(Child(T,Kid),1), T); 
         }
         Decorate (Child(T,NKids(T)), Type1);
         break;


      case BlockNode :
         for (Kid = 1; Kid <= NKids(T); Kid++)
            ProcessNode (Child(T,Kid));
	 for (Kid = 1; Kid <= NKids(T); Kid++)
	 {
	   if( NodeName(Child(T,Kid)) == CallNode)
	   {
	     if (FunctionNode == NodeName(Decoration(Child(Decoration(Child(Child(T,Kid),1)),1))))
	     {
	       ErrorHeader(T);
               printf ("FUNCTION CALLED AS PROCEDURE\n");
               printf ("\n");	
	     }
	   }
	 }
         break;


      case AssignNode :
         Type1 = Expression (Child(T,1));
         /*if ((Mode != DclnNode)&&(Mode != FunctionNode))*/
	 if (Mode != DclnNode)
         {
	   if (Mode == FunctionNode)
	   {
	     Temp1 = Lookup(SUBPROG_CTXT,T);
	     if(NodeName(Temp1) != FunctionNode)
 	     {
               ErrorHeader(T);
               printf ("CAN'T ASSIGN TO THIS TYPE\n");
               printf ("\n");		
	     }
	   }
	   else
	   { 
            ErrorHeader(T);
            printf ("CAN'T ASSIGN TO THIS TYPE\n");
            printf ("\n");
	   }
         }
         Type2 = Expression (Child(T,2));
         if ((Mode != DclnNode)&&(Mode != ConstNode)&&(Mode != LitNode)&&(Mode != FunctionNode))
         {
            ErrorHeader(T);
            printf ("IT'S NOT A CONST,VAR OR FUNCTION\n");
            printf ("\n");
         }

         if (NodeName(Type2) == IdentifierNode)
           { Type2 = Decoration(Type2); }
         if (Type1 != Type2)
         {
            ErrorHeader(T);
            printf ("ASSIGNMENT TYPES DO NOT MATCH\n");
            printf ("\n");
         }
         Temp1 = Lookup(FOR_CTXT,T);
         while(NodeName(Temp1) != ProgramNode)
          {
            if(NodeName(Child(Child(Temp1,1),1)) == NodeName(Child(Child(T,1),1)))
            {
              ErrorHeader(T);
              printf ("ASSIGNMENT TO THE LOOP VARIABLE!!\n");
              printf ("\n");
            }
            Temp1 = Decoration(Temp1);     
          }
         break;

      case ReadNode :
 	for (Kid = 1; Kid <= NKids(T); Kid++)
        {
           Type1 = Expression (Child(T,Kid));
	   if ((Type1 != TypeInteger)&&(Type1 != TypeChar))
           {
              ErrorHeader(T);
              printf ("INPUT EXPRESSION TYPE ERROR\n");
              printf ("\n");
           }

	Temp1 = Lookup(FOR_CTXT,T);
         while(NodeName(Temp1) != ProgramNode)
          {
            if(NodeName(Child(Child(Temp1,1),1)) == NodeName(Child(Child(T,Kid),1)))
            {
              ErrorHeader(T);
              printf ("CAN'T READ FOR LOOP VARIABLE!!\n");
              printf ("\n");
            }
            Temp1 = Decoration(Temp1);     
          }
        }
	break;

      case OutputNode :
         for (Kid = 1; Kid <= NKids(T); Kid++)
         {
           Type1 = Expression (Child(T,Kid));
           if (NodeName(Type1) == IdentifierNode)
           { 
             Type1 = Decoration(Type1); 
           }

	/*deal with the enum*/
	   if ((Rank(Type1) == 2)&&(NodeName(Child(Type1,2)) == LitNode))
           { 
	      ErrorHeader(T);
              printf ("OUTPUT EXPRESSION TYPE ERROR\n");
              printf ("\n");
             Type1 = TypeInteger; 
           }

           if ((Type1 != TypeInteger)&&(Type1 != TypeChar))
           {
              ErrorHeader(T);
              printf ("OUTPUT EXPRESSION TYPE ERROR\n");
              printf ("\n");
           }
         }
         break;


      case IfNode :
         if (Expression (Child(T,1)) != TypeBoolean)
         {
            ErrorHeader(T);
            printf ("CONTROL EXPRESSION OF 'IF' STMT");
            printf (" IS NOT TYPE BOOLEAN\n");
            printf ("\n");
         } 

         ProcessNode (Child(T,2));
         if (Rank(T) == 3)
            ProcessNode (Child(T,3));
         break;


      case WhileNode :
         if (Expression (Child(T,1)) != TypeBoolean)
         {
            ErrorHeader(T);
            printf ("WHILE EXPRESSION NOT OF TYPE BOOLEAN\n");
            printf ("\n");
         }
         ProcessNode (Child(T,2));
         break;

      case SWAPNode:
         Type1 = Expression (Child(T,1));
	 if(Mode == ConstNode)
         {
            ErrorHeader(T);
            printf ("SWAP WITH A CONST!!\n");
            printf ("\n");
         }

         Type2 = Expression (Child(T,2));
	 if(Mode == ConstNode)
         {
            ErrorHeader(T);
            printf ("SWAP WITH A CONST!!\n");
            printf ("\n");
         }

         if(NodeName(Child(T,1)) != IdentifierNode || NodeName(Child(T,2)) != IdentifierNode)
         {
            ErrorHeader(T);
            printf ("SWAP WITH AN INT!!\n");
            printf ("\n");
         }

         if (Type1 != Type2)
         {
            ErrorHeader(T);
            printf ("ARGUMENTS OF SWAP OPERATOR NOT COMPATIBLE \n");
            printf ("\n");
         }
         Temp1 = Lookup(FOR_CTXT,T);
         while(NodeName(Temp1) != ProgramNode)
          {
            if(NodeName(Child(Child(Temp1,1),1)) == NodeName(Child(Child(T,1),1)))
            {
              ErrorHeader(T);
              printf ("SWAP WITH THE LOOP VARIABLE!!\n");
              printf ("\n");
            }
            if(NodeName(Child(Child(Temp1,1),1)) == NodeName(Child(Child(T,2),1)))
            {
              ErrorHeader(T);
              printf ("SWAP WITH THE LOOP VARIABLE!!\n");
              printf ("\n");
            }
            Temp1 = Decoration(Temp1);     
          }
         break;

      case REPEATNode:

          if(Expression(Child(T,NKids(T))) != TypeBoolean)
          {
            ErrorHeader(T);
            printf ("REPEAT EXPRESSION NOT OF TYPE BOOLEAN\n");
            printf ("\n");
          }
          for (Kid = 1; Kid < NKids(T); Kid++)
            ProcessNode (Child(T,Kid));
         break;
         
      case CASENode:
           Type1 = Expression (Child(T,1));
           if ((Type1 != TypeInteger)&&(Type1 != TypeChar))
            {
               if ((Rank(Type1) != 2)||(NodeName(Child(Type1,2)) != LitNode )) 
               {  
		 ErrorHeader(T);
                 printf ("CASE CLAUSE TYPE NOT COMPATIBLE\n");
                 printf ("\n");
	       }
            }
	 CaseExp = Type1; /* use this to record the type of expression*/
         for (Kid = 2; Kid <= NKids(T); Kid++)
            ProcessNode (Child(T,Kid));
         break;

      case CASECLAUSENode:
          if(NKids(Child(T,1)) == 2)  /* ".." Node*/
             {
               Type1 = Expression(Child(Child(T,1),1)); 
	       /* Case Label can only be Const or Lit*/
	       if(NodeName(Child(Child(T,1),1)) == IdentifierNode)
	       {
		  if(Mode == DclnNode)
	          {
		    ErrorHeader(T);
		    printf ("CASE LABEL CAN ONLY BE CONST/LIT\n");
		    printf ("\n");
	          }
	       }
	       /* Case Label can only be Const or Lit*/
	       Type2 = Expression(Child(Child(T,1),2)); 
	       if(NodeName(Child(Child(T,1),2)) == IdentifierNode)
	       {
		  if(Mode == DclnNode)
	          {
		    ErrorHeader(T);
		    printf ("CASE LABEL CAN ONLY BE CONST/LIT\n");
		    printf ("\n");
	          }
	       }
          
	       if((Type1 != CaseExp)||(Type2 != CaseExp))
	  	{
		  ErrorHeader(T);
                  printf ("TYPE MISMATCH IN CASE STATEMENT\n");
                  printf ("\n");
		}
	       if(Type1 != Type2)
	        {
		  ErrorHeader(T);
                  printf ("RANGE OPERATOR HAS DIFFERENT TYPES\n");
                  printf ("\n");
	        }

               if(((Type1 != TypeInteger)&&(Type1 != TypeChar)) || ((Type2 != TypeInteger)&&(Type2 != TypeChar)) )
                {
                  if (((Rank(Type1) != 2)||(NodeName(Child(Type1,2))!=LitNode ))||((Rank(Type2) != 2)||(NodeName(Child(Type2,2)) != LitNode )) )
                  {
		    ErrorHeader(T);
                    printf ("CASE CLAUSE TYPE  NOT  COMPATIBLE\n");
                    printf ("\n");
		  }
                }
          }
          else 	/*single var*/
             Type1 = Expression(Child(T,1));

	     /* Case Label can only be Const or Lit*/
	     if(NodeName(Child(T,1)) == IdentifierNode)
	     {
		if(Mode == DclnNode)
	        {
		  ErrorHeader(T);
		  printf ("CASE LABEL CAN ONLY BE CONST/LIT\n");
		  printf ("\n");
	        }
	     }

	     /* Case Label should be the same type as Expression*/
	     if(Type1 != CaseExp)
	     {
		  ErrorHeader(T);
                  printf ("TYPE MISMATCH IN CASE STATEMENT\n");
                  printf ("\n");
	     }

             if( (Type1 != TypeInteger)&&(Type1 != TypeChar) )
               {
                 if ((Rank(Type1) != 2)||(NodeName(Child(Type1,2)) != LitNode )) 
                 {
		  ErrorHeader(T);
                  printf ("CASE CLAUSE TYPE NOT COMPATIBLE\n");
                  printf ("\n");
		 }
               }
         ProcessNode (Child(T,2));
         break;

      case OTHERWISENode:
         ProcessNode (Child(T,1));
         break;

      case LOOPNode:
         OpenScope();
         DTEnter(LOOP_CTXT,T,T);
         for (Kid = 1; Kid <= NKids(T); Kid++)
            ProcessNode (Child(T,Kid));
         CloseScope();
         if(Decoration(T) == 0) printf ("WARNING:NO EXIT FOR THE LOOP\n");
         break;

      case EXITNode:
         Temp1 = Lookup(LOOP_CTXT,T);
         if(NodeName(Temp1) != LOOPNode) {
                  ErrorHeader(T);
                  printf ("CAN'T EXIT FROM A STATEMENT OTHER THAN LOOP STATEMENT\n");
                  printf ("\n");
               }
          Decorate(T,Temp1); 
          Decorate(Temp1,T);          
          break;

      case DOWNTONode:	
      case UPTONode:
          Temp1 = Lookup(FOR_CTXT,T);
          Decorate(T,Temp1);
          OpenScope();
          DTEnter(FOR_CTXT,T,T);
          DTEnter(LOOP_CTXT,T,T);

          Type1 = Expression(Child(T,1));
          Type2 = Expression(Child(T,2));
          if(Type1 != Type2)
               {
                  ErrorHeader(T);
                  printf ("FOR LOOP VARIABLE DOSEN'T MATCH START VALUE\n");
                  printf ("\n");
               }
          Type2 = Expression(Child(T,3));
          if(Type1 != Type2)
               {
                  ErrorHeader(T);
                  printf ("FOR LOOP VARIABLE DOSEN'T MATCH START VALUE\n");
                  printf ("\n");
               }

          for (Kid = 4; Kid <= NKids(T); Kid++)
            ProcessNode (Child(T,Kid));
           
          while(NodeName(Temp1) != ProgramNode)
          {
            if(NodeName(Child(Child(Temp1,1),1)) == NodeName(Child(Child(T,1),1)))
            {
              ErrorHeader(T);
              printf ("LOOP VARIABLE MUST BE DIFFERENT\n");
              printf ("\n");
	    }  
            Temp1 = Decoration(Temp1);     
          }
          CloseScope();
          break;

    
      case CallNode:
         Expression(T);
	 break;

      case NullNode : 
         break;

      default :
         ErrorHeader(T);
         printf ("UNKNOWN NODE NAME ");
         Write_String (stdout,NodeName(T));
         printf ("\n");

   }  /* end switch */
}  /* end ProcessNode */

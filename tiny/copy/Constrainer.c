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

#define NumberOfNodes  46


typedef TreeNode UserType;

/****************************************************************
 Add new node names to the end of the array, keeping in strict
  order with the define statements above, then adjust the i loop
  control variable in InitializeConstrainer().
*****************************************************************/
char *node[] = { "program", "types", "type", "dclns",
                 "dcln", "integer", "boolean", "block",
                 "assign", "output", "if", "while", 
                 "<null>", "<=", "+", "-", "read",
                 "<integer>", "<identifier>" , "=", "<>",
                 ">=", "<", ">", "or", "*", "/", "and", "mod",
                 "not", "**", "true", "false", "eof", "swap",
		 "exit", "upto", "downto", "repeat", "loop", "case",
		 "case_clause", "..", "otherwise","<loop_ctxt>",
                 "<for_ctxt>"
                };


UserType TypeInteger, TypeBoolean;
boolean TraceSpecified;
FILE *TraceFile;
char *TraceFileName;
int NumberTreesRead, index;


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

   TempTree = Child (RootOfTree(1), 2);
   AddTree (TypeNode, TempTree, 1);

   TempTree = Child (RootOfTree(1), 2);
   AddTree (TypeNode, TempTree, 1);

   TempTree = Child (Child (RootOfTree(1), 2), 1);
   AddTree (BooleanTNode, TempTree, 1);
 
   TempTree = Child (Child (RootOfTree(1), 2), 2);
   AddTree (IntegerTNode, TempTree, 1);
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
   UserType Type1, Type2;
   TreeNode Declaration, Temp1, Temp2;
   int NodeCount;

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
            printf ("ARGUMENTS OF ASSOCIATION OPERATOR MUST BE TYPE INTEGER\n");
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

      case ReadNode :
         return (TypeInteger);


      case IntegerNode : 
         return (TypeInteger);

      case EOFNode:
      case TRUENode :
      case FALSENode: 
         return (TypeBoolean);

      case IdentifierNode :
         Declaration = Lookup (NodeName(Child(T,1)), T);
         if (Declaration != NullDeclaration)
         {
            Decorate (T, Declaration);　　　　　　　　　　/* decorate means make a point it to b, while decoration will return the one he points*/
            return (Decoration(Declaration));　　
         }
         else
            return (TypeInteger);

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


      case TypesNode :  
         for (Kid = 1; Kid <= NKids(T); Kid++)
            ProcessNode (Child(T,Kid));
         TypeBoolean = Child(T,1);
         TypeInteger = Child(T,2);
         break;


      case TypeNode :
         DTEnter (NodeName(Child(T,1)),T,T);
         break;


      case DclnsNode :
         for (Kid = 1; Kid <= NKids(T); Kid++)
            ProcessNode (Child(T,Kid));
         break;


      case DclnNode :

	 Name1 = NodeName (Child(T, NKids(T)));

         Type1 = Lookup (Name1,T);

         for (Kid  = 1; Kid < NKids(T); Kid++)
         {
            DTEnter (NodeName(Child(Child(T,Kid),1)), Child(T,Kid), T);
            Decorate (Child(T,Kid), Type1);

         }
         break;


      case BlockNode :
         for (Kid = 1; Kid <= NKids(T); Kid++)
            ProcessNode (Child(T,Kid));
         break;


      case AssignNode :
         Type1 = Expression (Child(T,1));
         Type2 = Expression (Child(T,2));

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


      case OutputNode :
         for (Kid = 1; Kid <= NKids(T); Kid++)
            if (Expression (Child(T,Kid)) != TypeInteger)
            {
               ErrorHeader(T);
               printf ("OUTPUT EXPRESSION MUST BE TYPE INTEGER\n");
               printf ("\n");
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
         Type2 = Expression (Child(T,2));

         if(NodeName(Child(T,1)) != IdentifierNode || NodeName(Child(T,2)) != IdentifierNode)
         {
            ErrorHeader(T);
            printf ("SWAP WITH AN INT!!\n");
            printf ("\n");
         }

         if (Type1 != Type2)
         {
            ErrorHeader(T);
            printf ("ARGUMENTS OF SWAP OPERATOR MUST BE THE SAME TYPE \n");
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
           if (Expression (Child(T,1)) != TypeInteger)
            {
               ErrorHeader(T);
               printf ("CASE CLAUSE TYPE NOT COMPATIBLE\n");
               printf ("\n");
            }
         for (Kid = 2; Kid <= NKids(T); Kid++)
            ProcessNode (Child(T,Kid));
         break;

      case CASECLAUSENode:
          if(NKids(Child(T,1)) == 2)
             {
               Type1 = Expression(Child(Child(T,1),1)); 
	       Type2 = Expression(Child(Child(T,1),2)); 
               if(Type1 != TypeInteger || Type2 != TypeInteger )
               {
                  ErrorHeader(T);
                  printf ("CASE CLAUSE TYPE NOT  COMPATIBLE\n");
                  printf ("\n");
               }
             }
          else 
             Type1 = Expression(Child(T,1));
             if(Type1 != TypeInteger)
               {
                  ErrorHeader(T);
                  printf ("CASE CLAUSE TYPE NOT COMPATIBLE\n");
                  printf ("\n");
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
          Decorate(T,Temp1);　　　　　　/*for loop value i check*/
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

    
       

      case NullNode : 
         break;

      default :
         ErrorHeader(T);
         printf ("UNKNOWN NODE NAME ");
         Write_String (stdout,NodeName(T));
         printf ("\n");

   }  /* end switch */
}  /* end ProcessNode */

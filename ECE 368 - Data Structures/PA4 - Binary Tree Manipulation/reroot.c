# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# include "reroot.h"

void Pre_Order_Print (Node *head)
{
  if (head == NULL)
    return;
  
  if (head -> width == 0)
  {
    printf ("%c", head -> cutline);
  }
  
  else 
  {
    printf ("(%le,%le)",head -> width, head -> height);
  }
  Pre_Order_Print (head -> Left);
  Pre_Order_Print (head -> Right);
}

void In_Order_Print (Node *head)
{
    if (head == NULL)
    return;
  
  In_Order_Print  (head -> Left);
  if (head -> width == 0)
  {
    printf ("%c", head -> cutline);
  }
  
  else 
  {
    printf ("(%le,%le)",head -> width, head -> height);
  }
  In_Order_Print  (head -> Right);
}

void Post_Order_Print (Node *head)
{
    if (head == NULL)
    return;
    
  Post_Order_Print (head -> Left);
  Post_Order_Print (head -> Right);
    
  if (head -> width == 0)
  {
    printf ("%c", head -> cutline);
  }
  
  else 
  {
    printf ("(%le,%le)",head -> width, head -> height);
  }
}
  

Stack *Initial_Stack (Stack *Top)
{
  Top = malloc(sizeof(Stack));
  Top -> next = NULL;
  Top -> Info = NULL;
  
  return Top;
}

Node *Create_node (char cutline, double width, double height)
{
  Node *New_Node = malloc (sizeof(Node));
  
  New_Node -> cutline = cutline;
  New_Node -> width = width;
  New_Node -> height = height;
  New_Node -> x_cor = 0;
  New_Node -> y_cor = 0;
// printf ("\n New Node Width:%le \n New Node Height: %le", New_Node -> width, New_Node -> height);
  New_Node -> Left = NULL;
  New_Node -> Right = NULL;
//   printf("\niiiiiii:  %d, %c\n",New_Node->thisnode,New_Node->cutline);
  
  return New_Node;
}



Stack *Push (Stack *Top, Node * temp)
{
//   printf ("\n \nTemp Info: %le:", temp -> width); 
  if (Top -> Info == NULL)
  {
    Top -> Info = temp;
//     printf ("\n \nTop Info: %le:", Top -> Info -> width);
    return Top;
  }
  
  else
  {
//     printf ("\n \n Push_Elsestatement_width %le", Top -> Info -> width);
    Stack *New_Stack; 
    New_Stack = Initial_Stack (New_Stack);
    New_Stack -> Info = temp;
    New_Stack -> next = Top;
//     printf ("\n \n Push_New_Stack_width: %le, next too: %le", New_Stack -> Info -> width, New_Stack -> next -> Info -> width);
    
    return New_Stack; 
  }
}
  
Stack *Pop(Stack *Top)
{
  Stack *Temp = Top -> next;
//     printf ("\n \n Get_Info: %le", Get_Info -> width);
//     printf ("\n \n Temp traverse");
    if (Temp == NULL)
    {
      Stack *New_Temp;
      New_Temp = Initial_Stack (New_Temp);
      return New_Temp;
    }
    
//     stack_traverse(Temp);
    
    return Temp;

}

Node *LoadFile(char *Filename)
{ 
//   printf ("\n%s" , Filename);
  FILE *fptr;
  fptr = fopen (Filename, "r");
  char ch;
  double width;
  double height;

  Stack *Top = NULL;
  Top = Initial_Stack(Top);
  Node *Next_Node = NULL; 
//   printf ("\nNext Nodde");
 
  while (!feof(fptr))
  { 
    ch = fgetc (fptr);
//     printf ("\n%c", ch);
    
    if (ch == '(')
    {
      fscanf(fptr, "%le", &width);
//       printf ("\n%le", width);
      ch = fgetc (fptr);
      fscanf(fptr, "%le", &height);
//       printf (" %le", height);
      ch = fgetc (fptr);
      Next_Node = Create_node ('-', width, height);
      Top = Push (Top, Next_Node);
//       stack_traverse(Top);
//       printf ("\n");
    }
        
    
    if (ch == 'V')
    { 
      Next_Node = Create_node ('V', 0, 0);
      Next_Node -> Right = Top -> Info;
      Top = Pop (Top);
//       printf ("\n1. V stack traverse");
//       stack_traverse(Top);
//       printf ("\nRight_Load width: %le ", Next_Node -> Right -> width);
      Next_Node -> Left = Top -> Info;
      Top = Pop (Top);
//       printf ("\n2. V stack traverse");
//       stack_traverse(Top);
//       printf ("\nLeft_Load width: %le ", Next_Node -> Left -> width);
      Top = Push (Top, Next_Node);
      
//       printf ("\n3. Push stack traverse");
//       stack_traverse(Top);
      
//       printf ("\n");
      
    }
    
    if (ch == 'H')
    {
      Next_Node = Create_node ('H', 0, 0);
      Next_Node -> Right = Top -> Info;
      Top = Pop (Top);
//       printf ("\n1. H stack traverse");
//       stack_traverse(Top);

//       printf ("\nRight_Load width: %le ", Next_Node -> Right -> width);
      Next_Node -> Left = Top -> Info;
      Top = Pop (Top);

//       printf ("\n2. H stack traverse");
//       stack_traverse(Top);
//       printf ("\nLeft_Load width: %le ", Next_Node -> Left -> width);
      
      Top = Push (Top, Next_Node);
//       stack_traverse(Top);
      printf ("\n");
        
    }
  }
  return Next_Node;

}

void Pack_Rectangles(Node *Head)
{
  if (Head == NULL)
    return;
  
  Pack_Rectangles (Head -> Left);
  Pack_Rectangles (Head -> Right);
  if (Head -> cutline == 'V')
  {
    if (Head -> Left -> height > Head -> Right -> height)
      Head -> height = Head -> Left -> height;
    else
      Head -> height = Head -> Right -> height;
    
    Head -> width = Head -> Left -> width + Head -> Right -> width;
  }

  if (Head -> cutline == 'H')
  {
    if (Head -> Left -> width > Head -> Right -> width)
      Head -> width = Head -> Left -> width;
    else
      Head -> width = Head -> Right -> width;
    
    Head -> height = Head -> Left -> height + Head -> Right -> height;
  }
  return;
}

void Print_Coordinate (Node *head)
{
  if (head -> Left == NULL)
  {
    printf("\nX-coordinate: %le\nY-coordinate: %le\n", head->x_cor, head->y_cor);
    return;
  }
  Print_Coordinate (head -> Left);
  
}

void Coordinate (Node *Head)
{
  if (Head == NULL)
    return;
  
  if (Head -> cutline == 'H')
  {
    Head -> Left -> y_cor += Head -> Right -> height;
    Head -> Left -> x_cor = Head -> x_cor;    
    
    Head -> Right -> x_cor = Head -> x_cor;
    Head -> Right -> y_cor = Head -> y_cor;
  }
  
  if (Head -> cutline == 'V')
  {
    Head -> Right -> x_cor += Head -> Left -> width;
    Head -> Right -> y_cor = Head -> y_cor; 
    
    Head -> Left -> x_cor = Head -> x_cor;
    Head -> Left -> y_cor = Head -> y_cor;
  }
  
  Coordinate (Head -> Left);
  Coordinate (Head -> Right);
  
  return;
}

// Node* Left_rotate (Node *head)
// {
//  Node *New_Head = head -> Right;
//  Node *Temp_Ptr = New_Head -> Left;
//  New_Head -> Left = head; 
//  head -> Right = Temp_Ptr;
//  
//  return New_Head;
// }
// 
// Node* Right_rotate (Node *head)
// {
//  Node *New_Head = head -> Left;
//  Node *Temp_Ptr = New_Head -> Right;
//  New_Head -> Right = head; 
//  head -> Left = Temp_Ptr;
//  
//  return New_Head;
// }

// void update_area_right (Node *head, Node *Temp, Node* Temp_Dir, double *area, double *best_width, double *best_height)
// {
//   double pack_height;
//   double pack_width;
//   double total_area;
//   if (head -> Right -> cutline == 'V')
//      {
//        pack_width = Temp -> width + Temp_Dir -> width;
//        if (Temp -> height > Temp_Dir -> height)
//        {
// 	 pack_height = Temp -> height;
//        }
//        else 
//        {
// 	 pack_height = Temp_Dir -> height;
//        }
//        total_area = pack_height * pack_width;
//        if (total_area < *area)
//        {
// 	 *area = total_area;
// 	 *best_height = pack_height;
// 	 *best_width = pack_width;
//        }
//        
//       }
//       
//      if (head -> Right -> cutline == 'H')
//      {
//        pack_height = Temp -> height + Temp_Dir -> height;
//        if (Temp -> width > Temp_Dir -> width)
//        {
// 	 pack_width = Temp -> width;
//        }
//        else 
//        {
// 	 pack_width = Temp_Dir -> width;
//        }
//        total_area = pack_height * pack_width;
//        if (total_area < *area)
//        {
// 	 *area = total_area;
// 	 *best_height = pack_height;
// 	 *best_width = pack_width;
//        }
//        
//       }
// }

// void update_area_left (Node *head, Node *Temp, Node* Temp_Dir, double *area, double *best_width, double *best_height)
// {
//   double pack_height;
//   double pack_width;
//   double total_area;
//   if (head -> Left -> cutline == 'V')
//      {
//        pack_width = Temp -> width + Temp_Dir -> width;
//        if (Temp -> height > Temp_Dir -> height)
//        {
// 	 pack_height = Temp -> height;
//        }
//        else 
//        {
// 	 pack_height = Temp_Dir -> height;
//        }
//        total_area = pack_height * pack_width;
//        if (total_area < *area)
//        {
// 	 *area = total_area;
// 	 *best_height = pack_height;
// 	 *best_width = pack_width;
//        }
//        
//       }
//       
//      if (head -> Left -> cutline == 'H')
//      {
//        pack_height = Temp -> height + Temp_Dir -> height;
//        if (Temp -> width > Temp_Dir -> width)
//        {
// 	 pack_width = Temp -> width;
//        }
//        else 
//        {
// 	 pack_width = Temp_Dir -> width;
//        }
//        total_area = pack_height * pack_width;
//        if (total_area < *area)
//        {
// 	 *area = total_area;
// 	 *best_height = pack_height;
// 	 *best_width = pack_width;
//        }
//        
//       }
// }

void reroot(Node *head, Node *Edge, double *area, double *best_height, double *best_width, double height, double width)
{
  double total_height;
  double total_width;
  double total_area;
  
  Node *Temp = malloc(sizeof(Node));
  Node *Left = malloc(sizeof(Node));
  Temp = head; 
  Temp -> Right = Edge -> Right;
  Left = Edge -> Left; 
  Pack_Rectangles (Temp);
  Pack_Rectangles (Left);
  if (Edge -> cutline == 'V')
  {
    total_width = width + Left -> width;
    
    if (height > Left -> height)
    {
      total_height = height;
    }
    else
    {
      total_height = Left -> height;
    }
    
    total_area = total_width * total_height; 
    if (total_area < *area)
    {
      *best_width = total_width;
      *best_height = total_height;
    }
  }
  
  if (Edge -> cutline == 'H')
  {
    total_height = height + Left -> height;
    
    if (width > Left -> width)
    {
      total_width = width;
    }
    else
    {
      total_width = Left -> width;
    }
    total_area = total_width * total_height; 
    if (total_area < *area)
    {
      *best_width = total_width;
      *best_height = total_height;
    }
  }    
  height = Temp -> height;
  width = Temp -> width;
//   if (Edge -> Left == 'V' || Edge -> Left == 'H')
//   {
//     reroot(head-> Right, Edge -> Left, area, best_height, best_width, height, width);
//   }
  
}



void SaveFile (Node *head, FILE *fptr)
{
  if (head == NULL)
    return;
  
  SaveFile (head -> Left, fptr);
  SaveFile (head -> Right, fptr);
  if (head -> cutline != 'V' && head -> cutline != 'H')
  {
    fprintf (fptr, "%le %le %le %le\n", head -> width, head -> height, head -> x_cor, head -> y_cor);
  }
}


int main(int argc, char **argv)
{
//   printf("saadasdasdas");
     double area;
     double best_height;
     double best_width;
     clock_t start_t, end_t;
     double total_t;
//      double height = 0;
//      double width = 0;
     
     Node *head = LoadFile(argv[1]);
     printf ("Preorder: "); 
     Pre_Order_Print (head);
     printf ("\nInorder: ");
     In_Order_Print (head);
     printf ("\nPostorder: ");
     Post_Order_Print (head);
     printf ("\n");
     start_t = clock();
     Pack_Rectangles(head);
     end_t = clock();
     total_t = (double)(end_t - start_t);
     
     
     
     printf ("\nWidth: %le\nHeight: %le\n", head -> width, head -> height);
     printf("\nElapsed Time: %le\n", total_t);
     area = head -> width * head -> height;
     best_height = head -> height;
     best_width = head -> width;
     
    /* while(head->Left != NULL)
     {
       head = head->Left;
     }*/
     
    
     
     Coordinate (head);
     Print_Coordinate (head);
     
     clock_t start_t_r, end_t_r;
     double total_t_r;
     start_t_r = clock();
//      reroot(head, head -> Right, &area, &best_height, &best_width, height, width);
//      reroot(head, head -> Left, &area, &best_height, &best_width, height, width);
     end_t_r = clock();
     total_t_r = (double)(end_t_r - start_t_r);
     printf ("\nBest width: %le\nBest height: %le\n", best_width, best_height);
     printf("\nElapsed Time for re-rooting: %le\n", total_t_r);
     FILE *fptr;
     fptr = fopen (argv[2],"w");
     SaveFile (head, fptr);
     fclose(fptr);
//   printf ("\nInorder: ");
//   printf ("\nPost Order: ");
     return (0);
}
    
      
        
    
    


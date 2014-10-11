#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include "packing.h"

Node *Create_node (int thisnode, int parnode, int lcnode, int rcnode, char cutline, double width, double height)
{
  Node *New_Node = malloc (sizeof(Node));
  New_Node -> thisnode = thisnode;
  New_Node -> parnode = parnode; 
  New_Node -> lcnode = lcnode;
  New_Node -> rcnode = rcnode;
  New_Node -> cutline = cutline;
  New_Node -> width = width;
  New_Node -> height = height;
  New_Node -> x_cor = 0;
  New_Node -> y_cor = 0;
  New_Node -> Left = NULL;
  New_Node -> Right = NULL;
//   printf("\niiiiiii:  %d, %c\n",New_Node->thisnode,New_Node->cutline);
  return New_Node;
}
  

Node *LoadFile (char *Filename,int* no_rect)
{
  
  FILE *ptr = fopen (Filename,"r");
  
  //int no_rect;
  int no_node;
  int i;
  int thisnode = 0;
  int parnode = 0;
  int lcnode = 0;
  int rcnode = 0;
  char cutline=0;
  double width;
  double height;
  char str1, str2;
  fscanf (ptr,"%d ", no_rect);
//   printf("\nhere\n");
  fscanf (ptr, "%d", &no_node);
 
  Node **Bin_Tree;
  Node *Head = malloc(sizeof(Node));
  Bin_Tree = malloc (sizeof(Node) * no_node);
  for (i=0; i < no_node; i++)
  {
    fscanf (ptr, "%d %d %d %d %c", &thisnode, &parnode, &lcnode, &rcnode, &cutline);
    //printf("\nrrrrrrrrrrrrrrrrrrrrr=%c\n",cutline);
//     printf("\n%d\n",parnode);
    if(lcnode == -1 && rcnode == -1)
    {
      fscanf (ptr, "%le %le", &width, &height);
      Bin_Tree [i] = Create_node (thisnode, parnode, lcnode, rcnode, cutline, width, height);
    }
    else
    {
      Bin_Tree [i] = Create_node (thisnode, parnode, lcnode, rcnode, cutline, 0, 0);
      fscanf (ptr, "%s %s", &str1, &str2);
    }
  }
  
  
 
  for (i=0; i < no_node; i++)
  {
    if ((Bin_Tree[i] -> lcnode) != -1)
    {
      //printf("\nhhhhhhhhhhhh %d\n ",Bin_Tree[i] -> parnode);
      Bin_Tree [i] -> Left = malloc(sizeof(Node));
      Bin_Tree [i] -> Left = Bin_Tree [(Bin_Tree[i] -> lcnode) -1];
     // printf("\nhhhhhhhhhhhh %d\n ",Bin_Tree[i] -> Left -> thisnode);
      Bin_Tree [i] -> Right = malloc(sizeof(Node));
      Bin_Tree [i] -> Right = Bin_Tree [(Bin_Tree[i] -> rcnode) -1];
    }
    if (Bin_Tree [i] -> parnode == -1)
    {
       Head= Bin_Tree [i];
    }
  }
  
  fclose (ptr); 
//   printf("\nhead here:%d\n",Head->thisnode);
  return Head;
  //return *Bin_Tree;
}

void Pack_Rectangles(Node *Head)
{
  if (Head == NULL)
    return;
  
  Pack_Rectangles (Head -> Left);
  Pack_Rectangles (Head -> Right);
  if (strcmp(&Head -> cutline,"V") == 0)
  {
    if (Head -> Left -> height > Head -> Right -> height)
      Head -> height = Head -> Left -> height;
    else
      Head -> height = Head -> Right -> height;
    
    Head -> width = Head -> Left -> width + Head -> Right -> width;
  }

  if (strcmp(&Head -> cutline,"H") == 0)
  {
    if (Head -> Left -> width > Head -> Right -> width)
      Head -> width = Head -> Left -> width;
    else
      Head -> width = Head -> Right -> width;
    
    Head -> height = Head -> Left -> height + Head -> Right -> height;
  }
  
}

void Coordinate (Node *Head)
{
  if (Head == NULL)
    return;
  
  if (strcmp(&Head -> cutline,"H") == 0)
  {
    Head -> Right -> x_cor = Head -> x_cor;
    Head -> Right -> y_cor = Head -> y_cor;
    
    Head -> Left -> y_cor += Head -> Right -> height;
  }
  
  if (strcmp(&Head -> cutline,"V") == 0)
  {
    Head -> Left -> x_cor = Head -> x_cor;
    Head -> Left -> y_cor = Head -> y_cor;
    
    Head -> Right -> x_cor += Head -> Left -> width;
  }
  Coordinate (Head -> Left);
  Coordinate (Head -> Right);
  
}
    

void PreOrder_Print (Node *Head)
{ 
  if (Head == NULL)
    return;
  
  printf ("%d ", Head -> thisnode);  
  PreOrder_Print (Head -> Left);
  PreOrder_Print (Head -> Right); 
}
      
void InOrder_Print (Node *Head)
{ 
  if (Head == NULL)
    return;
  
  InOrder_Print (Head -> Left);
  printf ("%d ", Head -> thisnode);
  InOrder_Print (Head -> Right); 
}
  
void PostOrder_Print (Node *Head)
{ 
  if (Head == NULL)
    return;
  
  PostOrder_Print (Head -> Left);
  PostOrder_Print (Head -> Right);
  printf ("%d ", Head -> thisnode);
}

void Higest_Node(Node* head, int rects)
{
  if (head == NULL)
    return;
  
//   if (head -> thisnode == rects)
  if (head -> Left == NULL) 
  {
//     printf ("\nXgugjffe: %d", head -> thisnode);
    printf ("\nX-coordinate: %le", head -> x_cor);
    
    printf ("\nY-coordinate: %le\n", head -> y_cor);
   
  
  }
  
  Higest_Node (head -> Left, rects);
//   Higest_Node (head -> Right, rects);
  return;
}

void Node_Destroy (Node *Head)
{
  if (Head == NULL)
    return;
  
  Node_Destroy (Head -> Left);
  Node_Destroy (Head -> Right);
  free(Head);
}
  
  
// void SaveFile (Node *head, char *Filename, int rects)
// {
//   FILE *ptr = fopen(Filename, "w");
//    
//   fprintf (ptr, "\n%d\n", rects);
//    
//   int i = 0;
//   Node *Node_Return = malloc(sizeof(Node));
//   for (i = 1; i <= rects; i++)
//   {
//      
//     Node_Return = Recurse (head, i);
//     printf("\n rrrrrrrrrrrr:%d\n", Node_Return -> thisnode);
//     
//     fprintf (ptr, "\n%d %le %le %le %le", Node_Return -> thisnode, Node_Return -> width, Node_Return -> height, Node_Return -> x_cor, Node_Return -> y_cor);
//   }    
//   fclose(ptr);
// }
// 
// Node *Recurse (Node *Head, int i)
// {
//   //Node*temp_node=malloc(sizeof(Node));
//   if (Head == NULL)
//     return NULL;
//   
//     if (Head -> thisnode == i)
//   { 
//      return Head;
//   }
//   Head = Recurse (Head -> Left, i);
//   Head = Recurse (Head -> Right, i);
// }

int main(int argc, char **argv)
{
  int rects=0;
  Node *head = LoadFile(argv[1],&rects);
//   printf("\nhead :%d\n",head->thisnode);
  printf ("Preorder: ");
  PreOrder_Print (head);
  printf ("\nInorder: ");
  InOrder_Print (head);
  printf ("\nPostorder: ");
  PostOrder_Print (head);
  printf ("\n");
  
  clock_t start_t, end_t;
  double total_t;
//   printf("ghjgsdjgfsja:%d",rects);
  start_t = clock();
  Pack_Rectangles(head);
  end_t = clock();
  Coordinate (head);
  printf ("\nWidth: %le", head -> width);
  printf ("\nHeight: %le\n", head -> height);
  Higest_Node(head, rects);
//   SaveFile (head, argv[2], rects);
 // Highest_node(head);
//   FILE *ptr = NULL;
//   ptr = fopen (Filename,"r");
//   fscanf (ptr, "%d", &no_rect);
//   
  total_t = (double)(end_t - start_t);
  
//   SaveFile (head, argv[1], argv[2]);
  printf ("\nElapsed Time: %le\n", total_t);
  Node_Destroy (head);
  
  return (0);
  
}

// void SaveFile (Node *Head, char *Filename_i, char *Filename_o)
// {
//   int no_rect;
//   int i;
//   FILE *fptr;
//   FILE *ptr;
//   fptr = fopen(Filename_i, "r");
//   fscanf (fptr, "%d", &no_rect);
//   
//   ptr = fopen(Filename_o, "w");
//   fprintf(ptr, "%d\n", no_rect);
//   
//   fclose(fptr);
//   fclose(ptr);
// }
  
  
  
  
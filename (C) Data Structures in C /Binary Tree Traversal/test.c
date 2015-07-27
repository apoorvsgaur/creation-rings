#include <stdio.h>
#include <stdlib.h>


struct node
{
  int thisnode;
  int parnode;
  int lcnode;
  int rcnode;
  char cutline;
  double width;
  double height;
  struct Node *Left;
  struct Node *Right;
} Node;

Node * Create_node (int thisnode, int parnode, int lcnode, int rcnode, char cutline, double width, double height)
{
  Node *New_Node = malloc (Sizeof(Node));
  
  New_Node -> thisnode = thisnode;
  New_Node -> parnode = parnode; 
  New_Node -> lcnode = lcnode;
  New_Node -> rcnode = rcnode;
  New_Node -> cutline = cutline;
  New_Node -> width = width;
  New_Node -> height = height;
  New_Node -> Left = NULL;
  New_Node -> Right = NULL;
  
  return New_Node;
}
  

Node * LoadFile (char *Filename)
{
  FILE *ptr = NULL;
  ptr = fopen (Filename,"r");
  int no_rect;
  int no_node;
  int i;
  int thisnode;
  int parnode;
  int lcnode;
  int rcnode;
  char cutline;
  double width;
  double height;
  fscanf (fptr, "%d", no_rect);
  fscanf (fptr, "%d", no_node);
  
  Node *Bin_Tree;
  Node *Head;
  Bin_Tree = malloc (Sizeof(Node) * no_node);
  for (i=1; i <= no_node; i++)
  {
    fscanf (fptr, "%d %d %d %d %c %le %le", thisnode, parnode, lcnode, rcnode, cutline, width, height);
    Bin_Tree [i] = Create_node (thisnode, parnode, lcnode, rcnode, cutline, width, height);
  }
  
  for (i=1; i <= no_node; i++)
  {
    if (Bin_Tree [i] -> lcnode != -1)
    {
      Bin_Tree [i] -> Left = Bin_Tree [lcnode];
      Bin_Tree [i] -> Right = Bin_Tree [rcnode];
    }
    
    if (Bin_Tree [i] -> parnode == -1);
      Head = Bin_Tree [i];
  }
  return Head;
}

int main()
{
  Node *Head;
  Head = LoadFile ("r6_flr.txt");
  return(0);
}
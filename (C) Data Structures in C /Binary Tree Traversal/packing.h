#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int thisnode;
  int parnode;
  int lcnode;
  int rcnode;
  char cutline;
  double width;
  double height;
  double x_cor;
  double y_cor;
  struct node *Left;
  struct node *Right;
} Node;


Node *Create_node (int thisnode, int parnode, int lcnode, int rcnode, char cutline, double width, double height);
Node *LoadFile (char *Filename,int*);
void Pack_Rectangles(Node *Head);
void Coordinate (Node *Head);
void PreOrder_Print (Node *Head);
void InOrder_Print (Node *Head);
void PostOrder_Print (Node *Head);
void Higest_Node(Node* head, int rects);
void Node_Destroy (Node *Head);
// void SaveFile (Node *head, char *Filename, int rects);
// Node *Recurse (Node *Head, int i);





  
  
  
  
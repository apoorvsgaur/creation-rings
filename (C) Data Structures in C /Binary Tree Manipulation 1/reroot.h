#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  char cutline;
  double width;
  double height;
  double x_cor;
  double y_cor;
  struct node *Left;
  struct node *Right;
} Node;

typedef struct stack
{
  struct stack *next;
  Node * Info;
} Stack; 

void Pre_Order_Print (Node *head);
void In_Order_Print (Node *head);
void Post_Order_Print (Node *head);
Stack *Initial_Stack (Stack *Top);
Node *Create_node (char cutline, double width, double height);
Stack *Push (Stack *Top, Node * temp);
Stack *Pop(Stack *Top);
Node *LoadFile(char *Filename);
void Pack_Rectangles(Node *Head);
void Print_Coordinate (Node *head);
void Coordinate (Node *Head);
void SaveFile (Node *head, FILE *fptr);
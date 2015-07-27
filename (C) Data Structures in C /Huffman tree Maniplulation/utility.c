#include <stdio.h>
#include <stdlib.h>
#include "pa09.h"


HuffNode *Huffman_Tree_create (int value)
{
  HuffNode *New_Node = malloc (sizeof(HuffNode));
  
  New_Node -> value = value;
  New_Node -> left = NULL;
  New_Node -> right = NULL;
  
  return New_Node;
}

void HuffNode_destroy (HuffNode *tree)
{
 if (tree == NULL)
 {
  return;
 }
 
 HuffNode_destroy (tree -> left);
 HuffNode_destroy (tree -> right);
 free (tree);
}

void Huff_postOrderPrint(FILE *output_file, HuffNode *tree)
{
    if (tree == NULL) 
    {
       return;
    }

    fprintf(output_file, "Left\n");
    
    Huff_postOrderPrint(output_file, tree->left);
    fprintf(output_file, "Back\n");

    fprintf(output_file, "Right\n");
    Huff_postOrderPrint(output_file, tree->right);
    fprintf(output_file, "Back\n");
 
    if (tree->left == NULL && tree->right == NULL) 
    {
      fprintf(output_file, "Leaf: %c\n", tree->value);
    }
   return;
}

Stack * Stack_push(Stack * st, HuffNode * t)
{
  Stack * Topnode = malloc(sizeof(Stack));
  Topnode -> node = t; // data
  Topnode -> next = st;
  
  return Topnode;
}

Stack *Stack_pop(Stack * st)
{
  if (st == NULL)
  {
    return NULL;
  }
  
  Stack * b = st -> next;
  free (st); // release StackNode, not TreeNode
  return b;
}

HuffNode *Huffman_Tree_char (FILE *build)
{

  Stack *Stack_values = NULL;
  unsigned char command = fgetc(build);
  
  if (build == NULL)
  {
    return NULL;
  }
  
  do 
  {
    if (command == '1')
    {
      unsigned char val;
      val = fgetc (build);
      
      HuffNode * Tree_Node = Huffman_Tree_create(val);
      Stack_values = Stack_push(Stack_values, Tree_Node);
    }

    if (command == '0')
    {
      HuffNode *NextNode = Stack_values -> node;
      Stack_values = Stack_pop(Stack_values);
      
      if (Stack_values == NULL)
      {
	return NextNode;
      }
      
      else
      {
        HuffNode * Stack_Next = Stack_values -> node;
	
        Stack_values = Stack_pop(Stack_values);
	
        HuffNode * NewNode = malloc(sizeof(HuffNode));
	
        NewNode -> value = ' '; // doesn't matter
        NewNode -> right = NextNode;
        NewNode -> left = Stack_Next;
	
        Stack_values = Stack_push(Stack_values, NewNode);
      }
    }
    command = fgetc (build);
   } while (Stack_values != NULL);
   
  return NULL;
}

HuffNode *Huffman_Tree_bit_to_byte (FILE *build)
{
  unsigned char ch = fgetc (build);
  int cmdloc = 1;
  int ct = 0;
  unsigned char command;
  unsigned char buffer;
  unsigned char buffer_temp;
  unsigned char value;
  unsigned char masks[] = { 0X80, 0X40, 0X20, 0X10, 0X08, 0X04, 0X02, 0X01};
  Stack *st = NULL;
  
  while(1)
  {
   command = (ch & masks[ct]);
   if (command != 0) // command is 1
   {
      buffer = fgetc(build);
      value = ch << cmdloc;
      buffer_temp = buffer >> (8 - cmdloc);
      value = value | buffer_temp;
      
      HuffNode *New_Node = Huffman_Tree_create (value);
      st = Stack_push(st, New_Node);
      ch = buffer; 
      
   }
   
    else
    {
      HuffNode * NextNode = st -> node;
      st = Stack_pop(st);
      
      if (st == NULL)
      {
	return NextNode;
      }
      
      else
      {
        HuffNode * Stack_Next = st -> node;
	
        st = Stack_pop(st);
	
        HuffNode * NewNode = malloc(sizeof(HuffNode));
	
        NewNode -> value = ' '; // doesn't matter
        NewNode -> right = NextNode;
        NewNode -> left = Stack_Next;
	
        st = Stack_push(st, NewNode);
      }
    }
   
    if (cmdloc == 8)
    {
     ch = fgetc (build);
     cmdloc = 1;
     ct = 0;
    }
   
    else
    {
      cmdloc++;
      ct++;
    }
   
  }
  return NULL;
  
}

























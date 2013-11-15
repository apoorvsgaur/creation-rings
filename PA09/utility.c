#include "pa09.h"
#include <stdio.h>
#include <stdlib.h>

HuffNode *Huffman_Tree_create (int value)
{
  HuffNode *New_Node = malloc (sizeof(HuffNode));
  
  New_Node -> value = value;
  New_Node -> left = NULL;
  New_Node -> right = NULL;
  
  return New_Node;
  
}

void *Huff_postOrderPrint(FILE *output_file, HuffNode *tree)
{
    // Base case: empty subtree
    if (tree == NULL) 
    {
      return NULL;
    }

    // Recursive case: post-order traversal

    // Visit left
    fprintf(output_file, "Left\n");
    Huff_postOrderPrint (output_file, tree->left);
	fprintf(output_file, "Back\n");
    // Visit right
    fprintf(output_file, "Right\n");
    Huff_postOrderPrint(output_file, tree->right);
	fprintf(output_file, "Back\n");
    // Visit node itself (only if leaf)
    if (tree->left == NULL && tree->right == NULL) 
    {
      fprintf(output_file, "Leaf: %c\n", tree->value);
    }
    
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

Stack *Huffman_Tree_build (FILE *build)
{
  FILE *build_file = fopen (build, "r");
  unsigned char ch = fgetc(build_file);
  
  unsigned char masks[] = 
  { 0X80, 0X40, 0X20, 0X10,
    0X08, 0X04, 0X02, 0X01
  };
  
  Stack *Stack_values;
  
  do 
  {
    unsigned char command = (ch & masks[cmdloc]);
    
    if (command == 1)
    {
      int val;
      fseek(build_file, 1, SEEK_SET);
      val = fgetc (build_file);
      
      HuffNode * Tree_Node = Huffman_Tree_create(val);
      Stack_values = Stack_push(Stack_values, Tree_Node);
    }

    if (command == 0)
    {
      HuffNode * NextNode = Stack_values -> next;
      Stack_values = Stack_pop(Stack_values);
      
      if (Stack_values == NULL)
      {
	return NextNode;
      }
      
      else
      {
        HuffNode * NextNode = Stack_values -> next;
	
        Stack_values = Stack_pop(Stack_values);
	
        HuffNode * NewNode = malloc(sizeof(HuffNode));
	
        NewNode -> value = ' '; // doesn't matter
        NewNode -> right = NextNode;
        NewNode -> left = ;
	
        Stack_values = Stack_push(Stack_values, NewNode);
      }
    }
    
  } while (ch != EOF)
  
}

#include "pa10.h"
#include "tree.h"
#include "tree.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

/**
 * Returns a pointer to a new empty stack.
 */
Stack * Stack_create()
{
  Stack *New_Stack = malloc(sizeof(Stack));
  New_Stack -> list = NULL;
  
  return New_Stack;
}

/**
 * Frees all memory associated with the stack. 
 * Don't forget that you _must_ free the entire contained linked-list.
 * Also, you must safely to _nothing_ if stack == NULL. 
 */
void Stack_destroy_helper (ListNode *link);

void Stack_destroy(Stack *stack)
{
  if (stack == NULL)
  {
    return;
  }
  
  Stack_destroy_helper (stack -> list);

  free (stack);
}

void Stack_destroy_helper (ListNode *link)
{
  if (link == NULL)
  {
    return;
  }
  
  Stack_destroy_helper(link -> next);
  free(link);
}

/**
 * Returns TRUE (something other than zero) if the stack is empty.
 */

int Stack_isEmpty(Stack * stack)
{
  if (stack == NULL)
  {
    return 1;
  }
  
  return FALSE;
}

/**
 * Pop the front 'value' from the stack.
 *
 * More precisely, this function must do two things:
 * (1) Return the value of the head node of the stack's list
 * (2) Remove the head node of the stack's list, freeing it.
 */
int Stack_pop(Stack * stack)
{
  int val;
  if ((stack -> list) == NULL)
  {
    return 0;
  }
  
  ListNode *temp = stack -> list -> next;
  
  val = (stack -> list) -> value;
  free (stack -> list);
  stack -> list = temp;
  return val;
}

/**
 * Push an 'value' onto the front of the stack.
 *
 * More precisely, this function must:
 * (1) Create a new ListNode with 'value' for it's value.
 * (2) Push that new ListNode onto the front of the stack's list.
 */
void Stack_push(Stack * stack, int value)
{  
  ListNode *temp = stack -> list;
  ListNode *NewNode = malloc(sizeof(ListNode));
  NewNode -> value = value;
  NewNode -> next = temp;
  stack -> list = NewNode;  
}

/**
 * Sort 'array' of length 'len' using Donald Knuth's "StackSort"
 *
 * To do this, you must implement the following pseudo-code:
 * (1) Maintain a 'write_index'. This is where you'll write values to
 *     as you sort them. It starts off as zero.
 * (2) Initialize an empty stack
 * (3) For each input value 'x':
 *     (3.a) While the stack is nonempty and 'x' is larger than the 
 *           front 'value' on the stack, pop 'value' and:
 *           (3.a.i) Write 'value' to array[write_index], and 
 *                   increment write_index.
 *     (3.b) Push x onto the stack.
 * (4) While the stack is nonempty, pop the front 'value' and follow
 *     step (3.a.i).
 *
 * The output should be a sorted array if, and only if, the array
 * is stack-sortable. You can find files full of stack-sortable and
 * stack-unsortable arrays in the 'expected' folder.
 */

void stackSort(int * array, int len)
{
  int i = isStackSortable(array, len);
  
  if (i == FALSE)
  {
    return;
  }
  
  else 
  {
    int write_index = 0;
    int loop;
    Stack * stack = Stack_create();
    int value;
  
    for (loop = 0; loop < len; loop++)
    {
	  while ((stack -> list) != NULL && (array[loop] > (stack -> list -> value)))
	  { 
	    value = Stack_pop(stack);
            array[write_index] = value;
            write_index ++;
          }
          Stack_push(stack, array[loop]);
	
    }
  
    while ((stack -> list) != NULL)
    {
      value = Stack_pop(stack);
      array[write_index] = value;
      write_index++;
    }
    
    
  }
}

/**
 * Return TRUE (1) if the 'array' of length 'len' is stack-sortable.
 *
 * To do this you must:
 * (1) If 'len' is less than 3, return TRUE.
 * (2) Find the maximum value in 'array'.
 * (3) Partition array into two parts: left of max, and right of max.
 * (4) The maximum value in left must be smaller than the minimum
 *     value in right. (Otherwise return FALSE.)
 * (5) Return TRUE if both left and right are stack-sortable.
 *
 * The 'expected' directory contains files for all sortable and 
 * unsortable sequences of length len. You must return TRUE for every
 * sequence in the sortable files, and you must return FALSE for every
 * sequence in the unsortable files.
 */

int get_Max_loc(int * array, int len);
int get_Min_loc(int * array, int start, int len);

int isStackSortable(int * array, int len)
{
  if (array == NULL)
  {
    return 0;
  }
  
  if (len < 3)
  {
    return TRUE;
  }
  
  int left_max_loc;
  int right_min;
  
  int loc = get_Max_loc(array, len);
  if (loc == 0 || loc == len - 1)
  {
    return TRUE;
  }
  
  left_max_loc = get_Max_loc(array, loc);
  int max_left = array[left_max_loc];
  
  right_min = get_Min_loc(array, loc + 1, len);
  
  if (max_left < right_min)
  {
    return TRUE;
  }  
  
  return FALSE;
}

int get_Max_loc(int * array, int len)
{
  int loc = 0;
  int  max = array [0];
  int i;
  for (i = 1; i < len; i++)
  {
    if (array[i] > max)
    {
      max = array[i];
      loc = i;
    }
  }
  return loc;
}

int get_Min_loc(int * array, int start, int len)
{
  int  min = array [start];
  int i;
  for (i = (start + 1); i < len; i++)
  {
    if (array[i] < min)
    {
      min = array[i];
    }
  }
  return min;
}

/**
 * Generates (and prints) all the unique binary tree shapes of size k
 *
 * To do this, you must:
 * (1) Create an array with the elements [1..k] inclusive.
 * (2) Find all the permutations of this array.
 * (3) In the base-case of your permute function, you must test if the
 *     permutation is "stack-sortable"
 * (4) If the permutation is "stack-sortable", then build a binary
 *     tree, and print it using the "Tree_printShape(...)" function.
 *
 * Your genShapes() function must NOT produce duplicate tree shapes.
 * The correct outputs for sizes [1..9] are in the 'expected' 
 * directory.
 */
void permuteHelper (int * charset , int len, int ind, int *count);
void swap (int * a , int * b );

void genShapes(int k)
{
  int i;
  int *array = malloc(sizeof(int) * k);
  int count = 0;
  
  for(i = 0; i <= k; i++)
  {
    array[i] = i;
  }
  
  permuteHelper (array, k, 0, &count);
}

void swap ( int * a , int * b )
{
  int t = * a ;
  * a = * b;
  * b = t;
}

void permuteHelper (int * charset , int len, int ind, int *count)
{
  
  if ( ind == len )
  {   
      int j;
      for (j = 0; j < len; j++)
      {
	printf ("%d", charset[j]);
      }
	printf ("\n");
      int i = isStackSortable(charset, len);
      printf ("%d\n\n", i);
      if (i == TRUE)
      {
	TreeNode *Tree;
        Tree = Tree_build(charset, len);
        Tree_printShape(Tree);
        Tree_destroy(Tree);
      }   
  }
  
  else 
  {
    int pos ;
    for ( pos = ind; pos < len; pos ++)
    {
      swap (& charset [pos] , & charset [ind]);
      permuteHelper ( charset , len , ind + 1, count);
      swap (& charset [pos] , & charset [ind]); 
    }
  }
  
}

  
  
  






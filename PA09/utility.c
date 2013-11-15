
Huffman *Huffman_Tree_create (FILE *fptr)
{
  
}

void *Huff_postOrderPrint(FILE *output_file, HuffNode *tree)
{
    // Base case: empty subtree
    if (tree == NULL) 
    {
      return;
    }

    // Recursive case: post-order traversal

    // Visit left
    fprintf(output_file, "Left\n");
    Huff_postOrderPrint(tree->left);
	fprintf(output_file, "Back\n");
    // Visit right
    fprintf(output_file, "Right\n");
    Huff_postOrderPrint(tree->right);
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
  if (command == 1)
  {
    read one more byte and store it in val;
    TreeNode * t = Huffman_Tree_create(val);
    st = Stack_push(st, t);
  }

  if (command == 0)
  {
    TreeNode * A = st -> tn;
    st = Stack_pop(st);
    if (st == NULL)
      {
	done = 1;
	A is the root;
      }
    else
      {
	TreeNode * B = st -> tn;
	st = Stack_pop(st);
	TreeNode * par = malloc(sizeof(TreeNode));
	par -> value = ' '; // doesn't matter
	par -> right = A;
	par -> left = B;
	st = Stack_push(st, par);
      }
  }
}

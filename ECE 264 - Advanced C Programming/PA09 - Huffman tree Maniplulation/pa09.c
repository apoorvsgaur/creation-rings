#include <stdio.h>
#include <stdlib.h>
#include "pa09.h"

int main ( int argc , char ** argv )
{ 
  if (argc != 3)
    {
      printf("usage: ./pa04 <input file> <output file>\n");
      return EXIT_FAILURE;
    }
  
  FILE * fptr = NULL;
  fptr = fopen(argv[1], "r");

  
  if (fptr == NULL)
  {
    printf("File error!\n");
    return EXIT_FAILURE;
  }
  
  int char_check = 1;
    
  if(strstr(argv[1], "bit"))
  {
    char_check = 0;
  }
      
  HuffNode *tree = NULL;
  if (char_check == 1)
  {
    tree = Huffman_Tree_char (fptr);
  }
   
  else
  {
    tree = Huffman_Tree_bit_to_byte(fptr);
  }
  
  fclose (fptr); 
    
  FILE * output_file = NULL;
  output_file = fopen(argv[2], "w");
  
  if (output_file == NULL)
  {
    printf("output file error\n");
    return EXIT_FAILURE;
  }
    
  Huff_postOrderPrint(output_file, tree);
  
  fclose (output_file);
  HuffNode_destroy (tree); 
  return EXIT_SUCCESS;
}
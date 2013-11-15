#include <stdio.h>
#include <stdlib.h>
#include "pa09.h"

int main ( int argc , char ** argv )
{ 
  printf ("1");printf ("1");
  int i; //indexprintf ("1");printf ("1");

  //check argumentsprintf ("1");
  if (argc != 3)
    {
      printf("usage: ./pa04 <input file> <output file>\n");
      return EXIT_FAILURE;
    }
  
  //initializing input file
  FILE * fptr = NULL;
  fptr = fopen(argv[1], "r");
  
  if (fptr == NULL)
  {
    printf("File error!\n");
    return EXIT_FAILURE;
  }
  
  else
  {
    HuffNode *Huffman_Tree = Huffman_Tree_build (fptr);
    
    fclose (fptr); 
    
    FILE * output_file = NULL;
    output_file = fopen(argv[2], "w");
  
    if (output_file == NULL)
    {
      printf("output file error\n");
      return EXIT_FAILURE;
    }
    
    else 
    {
      Huff_postOrderPrint(output_file, HuffNode *tree);
    }
    fclose (output_file);
   }
   
}
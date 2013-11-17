#include <stdio.h>
#include <string.h>
#ifndef PA09_H
#define PA09_H


typedef struct _huffnode {
    int value; 
    struct _huffnode * left;
    struct _huffnode * right;
} HuffNode;

typedef struct _stack {
    struct _stack * next;
    HuffNode * node;
} Stack;

HuffNode *Huffman_Tree_create (int value);

void Huff_postOrderPrint(FILE *output_file, HuffNode *tree);

Stack *Stack_push(Stack*, HuffNode*);

Stack *Stack_pop(Stack* );

HuffNode *Huffman_Tree_char (FILE *);

HuffNode *Huffman_Tree_bit_to_byte (FILE *build);

void HuffNode_destroy (HuffNode* );

#endif


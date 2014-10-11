#include <stdlib.h>
#include <stdio.h>

typedef struct _node
{
  int weight;
  int current;
} River;

River createnode(int weight)
{
  River *NewNode = malloc(sizeof(River));
  NewNode -> weight = weight;
  NewNode -> current = 0;
  
  return *NewNode;
}
void delete(River *node);

int main(int argc, char **argv)
{
  FILE *fptr;
  fptr = fopen (argv[1], "r");
  int no_lines;
  int weight;
  fscanf (fptr, "%d", &no_lines);
  
  River Matrix[2*no_lines+1][2*no_lines-1];
  int i;
  int j; 
  int counter = 0;
  for (i = 0; i < (2*no_lines); i = i + 2)
  {
    Matrix[i][0] = createnode (0);
//      printf("\ni: %d, Matrix[i][j].weight: %d", i, Matrix[i][0].weight);
  }
  
  for(i = 0; i<(2*no_lines)-1; i = i + 2)
  { 
    for (j = 2; j<(2*no_lines)+1; j = j + 2) 
    {
      Matrix [i][j] = createnode(1);
//         printf("\ni: %d, j: %d, Matrix[i][j].weight: %d\n", i, j, Matrix[i][j].weight);
    }
  }
  
  int store_weights [no_lines*(no_lines-1)];
  while (!feof(fptr))
  {
    weight = (int)fgetc(fptr);
    if (weight == 48 || weight == 49)
    {
      store_weights[counter] = weight - 48;
      counter++;
    }
  }
  int start_count = 0;
  for (i = 1; i < (2*no_lines)-1; i = i+2)
  {
    for(j = 1; j < (2*no_lines); j = j+2)
    {
      Matrix[i][j] = createnode(!store_weights[start_count]);
//        printf("\n%d%d", i,j);
//        printf("\nMatrix i,j: %d", Matrix[i][j].weight);
//        printf(" %d\n",store_weights[start_count]);
      start_count++;
    }
  }
  
//      for(i=0;i<(2*no_lines)-1;i=i+2)
//      {
//        if ((Matrix[i][2*no_lines].weight) == 0)
//        {
// 	 Matrix[i][2*no_lines].weight = 1;
//        }
//        printf("\nWeight: %d", Matrix[i][2*no_lines].weight);
//      }
    
  
  for(j = 1; j < (2*no_lines)+1;j++)
  {
    if (j%2 == 1)
    {
      for (i = 1; i < (2*no_lines)-1; i = i + 2)
      {
// 	printf("\ni: %d j: %d\n", i,j);
// 	printf("\n1. Before current: %d", Matrix[i][j].current);
// 	printf("\n1. Before weight: %d", Matrix[i][j].weight);
	Matrix[i][j].current = (Matrix[i-1][j-1].current<Matrix[i+1][j-1].current)?(Matrix[i][j].weight+Matrix[i-1][j-1].current):(Matrix[i+1][j-1].current+Matrix[i][j].weight);
//         printf("\n1. Matrix updated current: %d\n", Matrix[i][j].current); 
      }
    }
    
    else
    {
      for (i = 0; i < (2*no_lines)-1; i = i + 2)
      {
	if (i == 0)
	{
// 	  printf("\ni: %d j: %d\n", i,j);
// 	  printf("\n2. Before current: %d", Matrix[i][j].current);
// 	  printf("\n2. Before weight: %d", Matrix[i][j].weight);
	  Matrix[i][j].current = Matrix[i][j].weight + Matrix[i+1][j-1].current;
/*	  printf("\n2. Matrix updated current: %d\n", Matrix[i][j].current);*/ 
	}
		
 	else if (i == (2*no_lines-2))
	{
// 	  printf("\ni: %d j: %d\n", i,j);
// 	  printf("\n3. Before current: %d", Matrix[i][j].current);
// 	  printf("\n3. Before weight: %d", Matrix[i][j].weight);
	  Matrix[i][j].current = Matrix[i][j].weight + Matrix[i-1][j-1].current;
/*	  printf("\n3. Matrix updated current: %d\n", Matrix[i][j].current);*/ 
        }
        else
	{
// 	  printf("\ni: %d j: %d\n", i,j);
// 	  printf("\n4. Before current: %d", Matrix[i][j].current);
// 	  printf("\n4. Before weight: %d", Matrix[i][j].weight);
//           printf("\nAccess nodes i: %d, j: %d, Matrix[i][j].weight: %d\n", i, j, Matrix[i][j].weight);
	  Matrix[i][j].current = (Matrix[i-1][j-1].current<Matrix[i+1][j-1].current)?(Matrix[i][j].weight+Matrix[i-1][j-1].current):(Matrix[i+1][j-1].current+Matrix[i][j].weight);
/*	  printf("\n4. Matrix updated current: %d\n", Matrix[i][j].current);*/ 
	}
  
       }
    }
  }
  
  int min = Matrix[0][2*no_lines].current;
//   printf("Matrix value: %d\n", min);
  for(i=2; i < (2*no_lines)-1; i = i + 2)
  { 
//     printf("Matrix value: %d\n", Matrix[i][2*no_lines].current);
    if (Matrix[i][2*no_lines].current < min)
    {
      if(Matrix[i][2*no_lines].weight!=0)
      {
	min = Matrix[i][2*no_lines].current;
      }
    }
  }
  
  printf("\nMinimum number of turns: %d\n", min);
    
// int counter = 0;
// int i = 0;
// for (i = 0; i <2*n - 1; i ++)
// {
//   
//   if(counter%2) == 1
//     
//     free(Matrix[i][counter/i]);
//   counter++;
// }
  return(0);
}




// 
//JUST IN CASE MAIN
//fptr = fopen (argv[1], "r");
//   int no_lines;
//   fscanf (fptr, "%d", &no_lines);
//   int thisnode;
//   int weight;
//   Graph *graph = createGraph (no_lines);
//   for (thisnode = 1; thisnode <= (no_lines*no_lines); thisnode++)
//   {
//      weight = (int)fgetc(fptr)-48;
//      if (weight == 10)
//      { 
//        weight = (int)fgetc(fptr);
//     }
//     if ((thisnode % no_lines) == 1)
//     {
//       if ((thisnode - no_lines) < 1)
//       {
// 	addEdge(graph, thisnode, thisnode + 1, weight);
//         addEdge(graph, thisnode, thisnode + no_lines, weight);
//       }
//       else if ((thisnode + no_lines) > (no_lines*no_lines))
//       {
// 	addEdge(graph, thisnode, thisnode + 1, weight); 
// 	addEdge(graph, thisnode, thisnode - no_lines, weight);
//       }
//       else
//       {
// 	addEdge(graph, thisnode, thisnode + 1, weight);
// 	addEdge(graph, thisnode, thisnode - no_lines, weight);
//         addEdge(graph, thisnode, thisnode + no_lines, weight);
//       }
//     }
//     
//     else if ((thisnode % no_lines) == 0)
//     {
//       if (thisnode == no_lines)
//       {
// 	addEdge(graph, thisnode, thisnode - 1, weight);
//         addEdge(graph, thisnode, thisnode + no_lines, weight);
//       }
//       else if (thisnode == (no_lines*no_lines))
//       {
// 	addEdge(graph, thisnode, thisnode - 1, weight); 
// 	addEdge(graph, thisnode, thisnode - no_lines, weight);
//       }
//       else
//       {
// 	addEdge(graph, thisnode, thisnode - 1, weight);
// 	addEdge(graph, thisnode, thisnode - no_lines, weight);
//         addEdge(graph, thisnode, thisnode + no_lines, weight);
//       }
//     }
//     
//     else
//     {
//       if ((thisnode - no_lines) < 0)
//       {
// 	addEdge(graph, thisnode, thisnode - 1, weight);
// 	addEdge(graph, thisnode, thisnode + 1, weight);
//         addEdge(graph, thisnode, thisnode + no_lines, weight);
//       }
//     
//       else if ((thisnode + no_lines) > (no_lines * no_lines))
//       {
// 	addEdge(graph, thisnode, thisnode - 1, weight);
// 	addEdge(graph, thisnode, thisnode + 1, weight);
//         addEdge(graph, thisnode, thisnode - no_lines, weight);
//       }    
//       
//       else
//       {
//         addEdge(graph, thisnode, thisnode - 1, weight);
// 	addEdge(graph, thisnode, thisnode + 1, weight);
//         addEdge(graph, thisnode, thisnode - no_lines, weight);
//         addEdge(graph, thisnode, thisnode + no_lines, weight);
//       }
//      }
//     }
//       printGraph(graph, no_lines);
//     return(0);

//void printGraph(Graph* graph, int no_lines)
// {
//     int v;
//     for (v = 1; v <= (no_lines*no_lines); ++v)
//     {
//         AdjListNode* pCrawl = graph->array[v].head;
//         printf("\n Adjacency list of vertex %d\n head ", v);
//         while (pCrawl)
//         {
//             printf("-> %d", pCrawl->thisnode);
// // 	    printf("\n-> %d", pCrawl->weight_up);
// // 	    printf("\n-> %d", pCrawl->weight_down);
//             pCrawl = pCrawl->next;
//         }
//         printf("\n");
//     }
// }

// //void addEdge(Graph *graph, int src, int dest, int weight)
// //{
//     // Add an edge from src to dest.  A new node is added to the adjacency
//     // list of src.  The node is added at the begining
//     AdjListNode *newNode = newAdjListNode(dest, 10000, weight);
//     newNode->next = graph->array[src].head;
//     graph->array[src].head = newNode;
//  
//     // Since graph is undirected, add an edge from dest to src also
// //     newNode = newAdjListNode(src, weight, 10000);
// //     newNode->next = graph->array[dest].head;
// //     graph->array[dest].head = newNode;
// }
// struct _adjListNode
// // {
// //   int weight_up;
// //   int weight_down;
// //   int x_cor;
// //   int y_cor;
// //   int no_rotate;  
// //   AdjListNode* next;
// // } AdjListNode;
// 
// AdjListNode* newAdjListNode(int dest, int weight_up, int weight_down)
// {
//     AdjListNode *newNode = malloc(sizeof(AdjListNode));
//     newNode->thisnode = dest;
//     if (weight_up == 0 || weight_up == 1)
//     {
//       newNode -> weight_up = weight_up;
//       printf("\n%d", dest);
//       printf("\n%d", weight_up);
//     }
//     
//     if (weight_down == 0 || weight_down == 1)
//     {
//       newNode -> weight_down = weight_down;
//       printf("\n%d", dest);
//       printf("\n%d", weight_down);
//     }
//     
//     newNode -> no_rotate = 10000;
//     newNode -> next = NULL;
//     return newNode;
// }
// typedef struct adjListNode
// {
//   int thisnode;
//   int weight_up;
//   int weight_down;
//   int no_rotate;  
//   struct adjListNode* next;
//   
// } AdjListNode;
// 
// typedef struct _adjList
// {
//   AdjListNode *head;  
// } AdjList;
//  
// typedef struct _graPH
// {
//    AdjList* array;
// } Graph;
// 
// 
// void printGraph(Graph* graph, int no_lines);
// void addEdge(Graph *graph, int src, int dest, int weight);
// AdjListNode *newAdjListNode(int dest, int weight_up, int weight_down);
// void addEdge(Graph *graph, int src, int dest, int weight);
// Graph *createGraph(int V);
// 
// // Load_File(char *Filename)
// // {
// //   FILE *fptr;
// //   fptr = fopen (Filename, "r");
// //   
// //   
// // }
// 
// Graph *createGraph(int V)
// {
//     Graph *graph =  malloc(sizeof(Graph));
//     graph->array = malloc(V * V * sizeof(AdjList));
//     int i;
//     for (i = 1; i <= (V*V); ++i)
//        graph->array[i].head = NULL;
//      
//     return graph;
// }
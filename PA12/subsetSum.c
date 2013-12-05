#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include "pa12.h"

#define SUCCESS 0
#define FAILURE -1


typedef struct{

}Task;

/*
* Write a parallel C program that returns the answer for the following problem:
* Given a nonempty set S, with elements {a1, a2, a3, ...}, and a integer N, 
* find the number of nonempty subsets of S, such that the sum of all elements 
* in this subset equals to N.
*
* Arguments:
*	intset - pointer to an array of a integer set
*	length - size (length) of the integer set
*	N - target sum value
*	numThread - number of threads 
* Return value:
*	numOfSolutions - Number of nonempty subsets in which the subsetSum value 
*	matches with N. This variable should be protected as the critical 
*	sections by using mutex objects.
*
* Hint: The total number of possible subsets is (2^(length)-1). You may use
* 	math library function 'pow()' to assign the index for each thread.
* 	pthread.h and math.h are already included in this file.
*/
int subsetSum(int * intset, int length, int N, int numThread)
{ 
  pthread_t sub_set; 
  int j = 0;
  int *set_of_sets = gensets (intset, length); 
  
  for (i = 0; i < numThread; i++)
  {
    pthread_create (&sub_set, NULL, subset_bring, (void *)
  }
}

int generate_powerset(int* arr, int size, int *temparr, int level, int start)
{
	int i, j = 0;
	int *sets;
	for(i=start; i<size; i++)
	{
	  temparr[level] = arr[i];
	  
	  int sets[j] = malloc(sizeof(int) * level);
	  set [j] = temparr;
	  j++;
	  
	  if( i < size-1)
	  {
	    generate_powerset(arr, size, temparr, level+1, i+1);
	  }
	}
	return sets;
}

int gensets(int *intset, int length)
{
	int temparr[length] = {0};
	int *set_gen;
	set_gen = generate_powerset(intset, length, temparr, 0, 0);
	return set_gen;
}

void subset_bring ()
{
  int i;
  int sum = 0;
  int counter;
  int lock;
  
  for (i = 0; i < length; i++)
  {
    sum = sum + array[i];
  }
  
  if (sum == N)
  {
    pthread_mutex_lock(&lock);
    counter++;
    pthread_mutex_unlock(&lock);
  }
}
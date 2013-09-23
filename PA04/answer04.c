/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * Hint: 
 * You can write additonal functions.
 * You can test your functions with your own input file.
 * See details in README or typing command ./pa04 in terminal after make.
 * See output format examples in any of the files in directory expected.
 * 
 * You may create additional arrays if needed.  The maximum size
 * needed is specified by MAXLENGTH in pa04.h.
 */

#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>



/*
 * =================================================================
 * This function prints all partitions of a positive integer value
 * For example, if the value is 3:
 *
 * partitionAll 3
 * = 1 + 1 + 1
 * = 1 + 2
 * = 2 + 1
 * = 3
 */



void partition (int value, int *arr, int ind);
void printarr (int *arr, int index);

void partitionAll(int value)
{  
   printf("partitionAll %d\n", value);
   int *arr = malloc (sizeof(int) * value);
   partition (value, arr, 0);
   free(arr);
}

void partition (int value, int *arr, int ind)
{  
   int num;
   if (value == 0)
   {
     printarr (arr, ind);    
   }
    
   for (num = 1; num <= value; num++)
   { 
      arr[ind] = num; 
      partition (value - num, arr, ind + 1);
   }
}

void printarr (int *arr, int index)
{ 
   int i;
   printf("= ");
   for (i = 0; i < index - 1; i++)
   {  
       printf ("%d + ", arr[i]);
   }
   printf("%d\n", arr[index - 1]);
}
     
/*
 * =================================================================
 * This function prints the partitions that use increasing values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 3 + 2 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */

void partitionInc (int value, int *arr, int ind);

void partitionIncreasing(int value)
{ 
  printf("partitionIncreasing %d\n", value);
  int *arr = malloc (sizeof(int) * value);
  partitionInc (value, arr, 0);
  free(arr);
}

void partitionInc (int value, int *arr, int ind)
{  
   int num;
   if (value == 0)
   {	 
       printarr (arr, ind);
   }
   
    
   for (num = 1; num <= value; num++)
   {
     if (arr[ind-1] < num) 
     { 
       arr[ind] = num; 
       partitionInc (value - num, arr, ind + 1);
     }
   }
}

/*
 * =================================================================
 * This function prints the partitions that use Decreasing values.
 *
 * For example, if value is 5
 * 3 + 2 and
 * 4 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */

void partitionDec (int value, int *arr, int ind);
void partitionDecreasing(int value)
{
  printf("partitionDecreasing %d\n", value);
  int *arr = malloc (sizeof(int) * value);
  partitionDec (value, arr, 0);
  free(arr);

}

void partitionDec (int value, int *arr, int ind)
{  
   int num;
   if (value == 0)
   {	 
     int i;
     printf("= ");
     for (i = (ind - 1); i > 0; i--)
     {  
       printf ("%d + ", arr[i]);
     }
     printf("%d\n", arr[0]);
   }
   
    
   for (num = value; num > 0; num--)
   { 
     if (num > arr[ind-1]) 
     { 
       arr[ind] = num; 
       partitionDec (value - num, arr, ind + 1);
     }
   }
}

/*
 * =================================================================
 * This function prints odd number only partitions of a positive integer value
 * For example, if value is 5
 * 1 + 1 + 1 + 1 + 1 and
 * 1 + 3 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 1 + 2 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partitionOddnum (int value, int *arr, int ind);
void partitionOdd(int value)
{
  printf("partitionOdd %d\n", value);
  int *arr = malloc (sizeof(int) * value);
  partitionOddnum (value, arr, 0);
  free(arr);
}

void partitionOddnum (int value, int *arr, int ind)
{  
   int num;
   if (value == 0)
   {	 
       printarr (arr, ind);
   }
       
   for (num = 1; num <= value; num = num + 2)
   { 
        arr[ind] = num; 
        partitionOddnum (value - num, arr, ind + 1);
   }
}

/*
 * =================================================================
 * This function prints even number only partitions of a positive integer value
 * For example, if value is 8
 * 2 + 2 + 2 + 2and
 * 2 + 4 + 2 are valid partitions
 *
 * 8 is a valid partition
 *
 * 2 + 1 + 1 + 2 + 2and
 * 2 + 1 + 2 + 3and
 * 5 + 3 are invalid partitions.
 *
 * if the value is 5, there will be no result generated
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partitionEvennum (int value, int *arr, int ind);
void partitionEven(int value)
{
  printf("partitionEven %d\n", value);
  int *arr = malloc (sizeof(int) * value);
  partitionEvennum (value, arr, 0);
  free(arr);
}

void partitionEvennum (int value, int *arr, int ind)
{  
   int num;
   if (value == 0)
   {	 
       printarr (arr, ind);
   }
       
   for (num = 2; num <= value; num = num + 2)
   { 
        arr[ind] = num; 
        partitionEvennum (value - num, arr, ind + 1);
   }
}

/*
 * =================================================================
 * This function prints alternate ood and even number partitions of a positive integer value. Each partition starts from and odd number, even number, ood number again, even number again...etc.
 *
 * For example, if value is 6
 * 1 + 2 + 1 + 2 and
 * 3 + 2 + 1 are valid partitions
 *
 * 6 is not a valid partition
 *
 * 2 + 1 + 1 + 2 and
 * 2 + 1 + 3and
 * 5 + 1 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partitionOandE (int value, int *arr, int ind);
void partitionOddAndEven(int value)
{
  printf("partitionOddAndEven %d\n", value);
  int *arr = malloc (sizeof(int) * value);
  partitionOandE (value, arr, 0);
  free(arr);
  
}

void partitionOandE (int value, int *arr, int ind)
{  
   int num;
   if (value == 0)
   {	 
       printarr (arr, ind);
   }
       
   for (num = 1; num <= value; num++)
   {    
     if ((((arr[ind-1] % 2 == 0) && (num % 2 !=0))) || ((arr[ind-1] % 2 != 0) && (num % 2 ==0)))  
     {
	arr[ind] = num; 
        partitionOandE (value - num, arr, ind + 1);
     }
   }
}

/*
 * =================================================================
 * This function prints prime number only partitions of a positive integer value
 * For example, if value is 6
 * 2 + 2 + 2 and
 * 3 + 3 are valid partitions
 *
 * 6 is not a valid partition
 * 
 * 2 + 4 and
 * 1 + 5 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


 void partitionPrimech (int value, int *arr, int ind);
void partitionPrime(int value)
{
  printf("partitionPrime %d\n", value);
  int *arr = malloc (sizeof(int) * value);
  partitionPrimech (value, arr, 0);
  free(arr);
}
 void partitionPrimech (int value, int *arr, int ind)
{  
   int num;
   if (value == 0)
   {	 
       printarr (arr, ind);
   }
       
   for (num = 1; num <= value; num++)
   { 
     int i;
     int checkprime = 0;
     for (i = 1; i <= num; i++)
     { 
       if (num % i == 0)
       { 
	 checkprime++;
       }
     }
     
     if (checkprime == 2)  
     {  
	arr[ind] = num; 
        partitionPrimech (value - num, arr, ind + 1);
     }
   }
}

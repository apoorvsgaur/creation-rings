# include <stdio.h>
# include <stdlib.h> 
//# include "sorting_main.c"

long *LoadFile(char *Filename, int *Size)
{
  FILE *ptr = NULL;
  ptr = fopen (Filename,"r");
  
  if (ptr == NULL)
  { 
    printf ("Cannot open file.");
  }
  
  fscanf (ptr, "%d", Size);
 
  long *Array = malloc(sizeof(long)*(*Size));
  int i = 0;
  for (i = 0; i < *Size; i++)
  {
    fscanf (ptr, "%ld", &Array[i]);
  }
  
  fclose (ptr);
  
  return Array;
}

int SaveFile(char *Filename, long *Array, int Size)
{
  FILE *fptr;
  fptr = fopen(Filename, "w");
  int i;
  int count = 0;
  
  for (i = 0; i < Size; i++)
  {
    fprintf(fptr, "%ld\n", Array[i]);
    count++;
  }
  fclose (fptr);
  
  return count;
}

void Shell_Insertion_Sort (long *Array, int Size, double *N_Comp, double *N_Move)
{
  int p = 1;
  int q = 0;
  *N_Move = 0;
  *N_Comp = 0;
  long temp_r;
  
  while (p < Size)
  {
    p = p * 3;
    q = q + 1;
  }
  
  p = p / 3;
  q = q - 1;
  
  while (q >= 0)
  {
    int j;
    for (j = p; j < Size; j++)
    { 
      int i;
      temp_r = Array[j];
      i = j;
      (*N_Move)++;
      while (i >= p && Array [i-p] > temp_r) 
      {
	(*N_Comp)++;
	Array[i] = Array [i-p];
	i = i - p;
      }
      (*N_Comp)++;
      Array[i] = temp_r;
      
     }
     
     p = p / 3;
     q = q - 1;
  }
}

void Shell_Selection_Sort (long *Array, int Size, double *N_Comp, double *N_Move)
{
  int p = 1;
  int q = 0;
  *N_Move = 0;
  *N_Comp = 0;
  
  while (p < Size)
  {
    p = p * 3;
    q = q + 1;
  }
  
  
  while (q >= 0)
  {
    int i,j;
    int iMin;
    
    
    for (j = 0; j < Size-1; j++)
     {
       iMin = j;
       
       for (i = j + p; i< Size; i = i + p)
       {
	 (*N_Move)++;
	 if (Array[i] < Array[iMin])
	 {
	   iMin = i;
	 }
       }
    
       if (iMin != j)
       {
	 long temp_r;
	 temp_r = Array [j];
	 Array [j] = Array [iMin];
	 Array [iMin] = temp_r;
	 *N_Comp = *N_Comp + 3;
       }
    }
       
       p = p / 3;
       q = q - 1;
   }
}


int Print_Seq(char *Filename, int Size)
{
  FILE *fptr;
  fptr = fopen(Filename, "w");
  int p = 1;
  int q = 0;
  int count = 0;
  while (p < Size)
  {
    p = p * 3;
    q = q + 1;
  }
  
  p = p / 3;
  q = q - 1;
  
  while (q >= 0)
  {
    p = p / 3;
    count++;
    fprintf(fptr, "%d\n", p);
    q = q - 1;
  }
  return count;
}
  
  

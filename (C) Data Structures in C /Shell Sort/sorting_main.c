# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
//# include "sorting.c"

long *LoadFile(char *Filename, int *Size);
int SaveFile(char *Filename, long *Array, int Size);
void Shell_Insertion_Sort (long *Array, int Size, double *N_Comp, double *N_Move);
void Shell_Selection_Sort (long *Array, int Size, double *N_Comp, double *N_Move);
int Print_Seq(char *Filename, int Size);

int main(int argc, char *argv[])
{
  double N_Move = 0;
  double N_Comp = 0;
  int Size = 0;
  clock_t start_t, end_t; 
  double total_t;
  clock_t start_i, end_i; 
  double total_i;
  
  start_i = clock();
  long *Array = LoadFile(argv[2], &Size);
  end_i = clock();
  total_i = (double)end_i - start_i;
  
  if(strcmp(argv[1],"i")== 0)
  {
    start_t = clock();
    Shell_Insertion_Sort (Array, Size, &N_Comp, &N_Move);
    end_t = clock();
    total_t = (double)end_t - start_t;
    
    clock_t start_o, end_o; 
    double total_o;
    
    start_o = clock();
    SaveFile(argv[4], Array, Size);
    end_o = clock();
    total_o = (double)end_o - start_o;
    
     printf ("Number of comparisons: %le \n Number of moves: %le \n I/O time: %le \n Sorting time: %le \n", N_Comp, N_Move, total_i + total_o, total_t);
     Print_Seq(argv[3],Size);
     free (Array);
  }
  
  else
  {
    start_t = clock();
    Shell_Selection_Sort (Array, Size, &N_Comp, &N_Move);
    end_t = clock();
    total_t = (double)end_t - start_t;
    
    clock_t start_o, end_o, total_o;
    start_o = clock();
    SaveFile(argv[4], Array, Size);
    end_o = clock();
    
    total_o = (double)end_o - start_o;
     printf ("Number of comparisons: %le \n Number of moves: %le \n I/O time: %le \n Sorting time: %le \n", N_Comp, N_Move, total_i + total_o, total_t);
     Print_Seq(argv[3],Size);
     free (Array);
  }
  return 0;
}
    
  
  
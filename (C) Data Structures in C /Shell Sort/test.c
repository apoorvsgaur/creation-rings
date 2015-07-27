# include <stdio.h>
# include <stdlib.h> 

int Print_Seq(char *Filename, int Size)
{
  FILE *fptr;
  fptr = fopen(Filename, "r");
  int p = 1;
  int q = 0;
  int count = 0;
  long temp_r;
  
  while (p < Size)
  {
    p = p * 3;
    q = q + 1;
  }
  
  p = p / 3;
  q = q - 1;
  
  while (q >= 0 && p > 0)
  {
    p = p / 3;
    count++;
    printf ("%d\n", p);
    fprintf(fptr, "%d\n", p);
    q = q - 1;
  }
  return count;
}

int main ()
{ 
  int i;
  int Size = 1000;
  i = Print_Seq ("s10.txt", Size);
  return (0);
}

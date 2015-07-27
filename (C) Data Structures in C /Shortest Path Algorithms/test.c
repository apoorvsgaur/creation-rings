#include <stdio.h>
#include <stdlib.h>

void check_input(char *Filename)
{
  FILE *fptr;
  int no_lines;
  int weight;
  fptr = fopen (Filename, "r");
  fscanf (fptr, "%d", &no_lines);
  while (!feof(fptr))
  {
    weight = (int)fgetc(fptr);
    if (weight == 10)
    {
      weight = (int)fgetc(fptr);
    }
    printf("%d\n", weight - 48);
  }
}

int main(int argc, char **argv)
{
  check_input(argv[1]);
  return (0);
}
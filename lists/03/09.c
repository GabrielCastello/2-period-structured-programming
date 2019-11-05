/* 9) Faça um algoritmo para gerar uma matriz 10 x 10 aleatoriamente com números de
0 até 39, com exceção dos elementos da diagonal principal, que devem ser gerados
aleatoriamente com números de 1 até 50. A matriz gerada deve ser armazenada no
arquivo "Matriz10x10.txt". */

#include <stdio.h>

int genRandon(int startNumber, int endNumber)
{
  return rand() % endNumber + startNumber;
}

int main()
{
  srand(time(NULL));
  FILE *outputFile;
  int size = 10, matrix[size][size];

  outputFile = fopen("09Matrix10x10.txt", "w");

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (i == j)
        matrix[i][j] = genRandon(1, 50);
      else
        matrix[i][j] = genRandon(0, 39);
    }
  }

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
      fprintf(outputFile, " %i ", matrix[i][j]);
    fprintf(outputFile, "\n");
  }

  printf("\n\n");
  return 0;
}
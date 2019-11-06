/*
8) Faça um algoritmo para calcular e imprimir a matriz transposta de uma matriz 7 x 3
gerada aleatoriamente com números de 1 até 25. A matriz que irá receber o resultado da
transposta deve ser criada na função main. Utilize três procedimentos: um para a
geração da matriz, outro para calcular a transposta e um terceiro para imprimir a matriz
transposta.
*/

#include <stdio.h>

void fillMatrixRandomically(int matrix[10][10], int length1, int length2)
{
  for (int i = 0; i < length1; i++)
    for (int j = 0; j < length2; j++)
      matrix[i][j] = genRandon(1, 25);
}

void transposeMatrix(int matrix[10][10], int transpostMatrix[10][10], int length1, int length2)
{
  for (int i = 0; i < length1; i++)
    for (int j = 0; j < length2; j++)
    {
      printf("\nMatrix[%i][%i]: %i", i, j, matrix[i][j]);
      transpostMatrix[j][i] = matrix[i][j];
      printf("\ntranspostMatrix[%i][%i]: %i", i, j, matrix[i][j]);
    }
}

void printMatrix(int matrix[10][10], int length1, int length2, int isTranpost)
{
  if (!isTranpost)
  {
    for (int i = 0; i < length1; i++)
    {
      printf("\n ");
      for (int j = 0; j < length2; j++)
      {
        // printf("\nValor da matriz na posição[%i][%i]: %i", i, j, matrix[i][j]);
        printf(" %i ", matrix[i][j]);
      }
      printf("\n ");
    }
  }
  else
  {
    for (int i = 0; i < length2; i++)
    {
      printf("\n ");
      for (int j = 0; j < length1; j++)
      {
        // printf("\nValor da matriz na posição[%i][%i]: %i", i, j, matrix[i][j]);
        printf(" %i ", matrix[i][j]);
      }
      printf("\n ");
    }
    /* code */
  }
}

int genRandon(int startNumber, int endNumber)
{
  return rand() % endNumber + startNumber;
}

int main()
{
  srand(time(NULL));

  int length1 = 7, length2 = 3;
  int matrix[10][10], transpostMatrix[10][10];

  fillMatrixRandomically(matrix, length1, length2);
  transposeMatrix(matrix, transpostMatrix, length1, length2);

  printf("\nSrc. Matrix: ");
  printMatrix(matrix, length1, length2, 0);
  printf("\nTranspost Matrix: ");
  printMatrix(transpostMatrix, length1, length2, 1);

  printf("\n\n");

  return 0;
}
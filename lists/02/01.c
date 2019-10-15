/* 1) Faça um algoritmo para ler pelo teclado uma matriz 4 x 3 com valores reais e
imprimir o maior elemento da matriz e a sua localização (linha e coluna). Utilize dois
procedimentos: um para a leitura da matriz e outro para imprimir as informações.
 */

#include <stdio.h>

void fillMatrix(float matrix[4][3], int length1, int length2)
{
  for (int i = 0; i < length1; i++)
    for (int j = 0; j < length2; j++)
    {
      printf("\nInforme um valor para a matriz na posição[%i][%i]: ", i, j);
      scanf("%f", &matrix[i][j]);
    }
}

void printMatrix(float matrix[4][3], int length1, int length2)
{
  for (int i = 0; i < length1; i++)
    for (int j = 0; j < length2; j++)
    {
      printf("\nValor da matriz na posição[%i][%i]: %f", i, j, matrix[i][j]);
    }
}

int main()
{
  int length1 = 4, length2 = 3;
  float matrix[length1][length2];

  fillMatrix(matrix, length1, length2);
  printMatrix(matrix, length1, length2);

  printf("\n\n");

  return 0;
}

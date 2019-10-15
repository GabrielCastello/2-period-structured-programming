/* 
5) Faça um algoritmo para ler pelo teclado duas matrizes de reais 3 × 4 e imprimir a
subtração dessas matrizes. A matriz que irá receber a subtração das outras duas deve ser
criada na função main. Utilize três procedimentos: um para a leitura das matrizes, outro
para calcular a subtração e um terceiro para imprimir a matriz com o resultado da
subtração.
*/

#include <stdio.h>

void fillMatrix(int matrixN, float matrix[5][3], int length1, int length2)
{
  for (int i = 0; i < length1; i++)
    for (int j = 0; j < length2; j++)
    {
      printf("\nInforme um valor para a matriz%i na posição[%i][%i]: ", matrixN, i, j);
      scanf("%f", &matrix[i][j]);
    }
}

void subMatrix(float matrix1[5][3], float matrix2[5][3], float subtractedMatrix[5][3], int length1, int length2)
{
  for (int i = 0; i < length1; i++)
  {
    for (int j = 0; j < length2; j++)
    {
      subtractedMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
    }
  }
}

void printMatrix(float matrix[4][3], int length1, int length2)
{
  for (int i = 0; i < length1; i++)
    for (int j = 0; j < length2; j++)
    {
      printf("\nValor da matriz somada na posição[%i][%i]: %f", i, j, matrix[i][j]);
    }
}

int main()
{
  int length1 = 5, length2 = 3;
  float matrix1[length1][length2], matrix2[length1][length2], subtractedMatrix[length1][length2];

  fillMatrix(1, matrix1, length1, length2);
  fillMatrix(2, matrix2, length1, length2);

  subMatrix(matrix1, matrix2, subtractedMatrix, length1, length2);

  printf("\nMatriz somada: ");
  printMatrix(subtractedMatrix, length1, length2);
  printf("\n\n");

  return 0;
}

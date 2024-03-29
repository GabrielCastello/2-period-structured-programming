/* 4) Faça um algoritmo para ler pelo teclado duas matrizes de reais 5 × 3 e imprimir a
soma dessas matrizes. A matriz que irá receber a soma das outras duas deve ser criada
na função main. Utilize três procedimentos: um para a leitura das matrizes, outro para
calcular a soma e um terceiro para imprimir a matriz com o resultado da soma.
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

void sumMatrix(float matrix1[5][3], float matrix2[5][3], float summedMatrix[5][3], int length1, int length2)
{
  for (int i = 0; i < length1; i++)
  {
    for (int j = 0; j < length2; j++)
    {
      summedMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
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
  float matrix1[length1][length2], matrix2[length1][length2], summedMatrix[length1][length2];

  fillMatrix(1, matrix1, length1, length2);
  fillMatrix(2, matrix2, length1, length2);

  sumMatrix(matrix1, matrix2, summedMatrix, length1, length2);

  printf("\nMatriz somada: ");
  printMatrix(summedMatrix, length1, length2);
  printf("\n\n");

  return 0;
}

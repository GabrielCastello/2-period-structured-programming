/* 2) Faça um algoritmo para ler pelo teclado uma matriz 3 x 5 com valores reais e
imprimir quantos valores maiores do que 20 ela possui. Utilize um procedimento para a
leitura da matriz e uma função para fazer o cálculo. A impressão da informação
(quantos valores maiores do que 20) deve ser na função main.
 */

#include <stdio.h>

void fillMatrix(float matrix[3][5], int length1, int length2)
{
  for (int i = 0; i < length1; i++)
    for (int j = 0; j < length2; j++)
    {
      printf("\nInforme um valor para a matriz na posição[%i][%i]: ", i, j);
      scanf("%f", &matrix[i][j]);
    }
}

int calculateGt20(float matrix[3][5], int length1, int length2)
{
  int counter = 0;
  for (int i = 0; i < length1; i++)
    for (int j = 0; j < length2; j++)
      if (matrix[i][j] > 20)
        counter += 1;
  return counter;
}

int main()
{
  int length1 = 3, length2 = 5;
  float matrix[length1][length2];

  fillMatrix(matrix, length1, length2);

  printf("\nQuantidade de valores maiores que 20: %i", calculateGt20(matrix, length1, length2));

  printf("\n\n");

  return 0;
}

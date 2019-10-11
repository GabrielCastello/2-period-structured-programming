/* 3) Faça um algoritmo para ler pelo teclado uma matriz 4 x 4 com valores inteiros e
também um número inteiro x. Ao final, o algoritmo tem que imprimir se o número x
pertence ou não à matriz. O número x tem que ser lido na função main. Utilize um
procedimento para a leitura da matriz e uma função para realizar a busca. A impressão
da informação (se x está presente ou não na matriz) deve ser na função main.
 */

#include <stdio.h>

void fillMatrix(int matrix[4][4], int length1, int length2)
{
  for (int i = 0; i < length1; i++)
    for (int j = 0; j < length2; j++)
    {
      printf("\nInforme um valor para a matriz na posição[%i][%i]: ", i, j);
      scanf("%i", &matrix[i][j]);
    }
}

int look4x(int matrix[4][4], int length1, int length2, int x)
{
  int result = 0;
  for (int i = 0; i < length1; i++)
    for (int j = 0; j < length2; j++)
      if (matrix[i][j] == x)
        result = 1;
  return result;
}

int main()
{
  int length1 = 4, length2 = 4;
  int matrix[length1][length2], x;

  fillMatrix(matrix, length1, length2);

  printf("\nInforme um valor para X: ");
  scanf("%i", &x);

  printf("\nValor %i está presente na matriz ?", x);
  look4x(matrix, length1, length2, x) == 1 ? printf("\nSim") : printf("\nNão");

  printf("\n\n");

  return 0;
}

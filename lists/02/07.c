/* 
7) Faça um algoritmo para verificar se uma matriz quadrada 6 x 6 gerada aleatoriamente
com números de 1 até 50 é simétrica. Utilize um procedimento para a geração da
matriz e uma função para a verificação. De acordo com o retorno da função deve-se
imprimir na função main: MATRIZ SIMETRICA ou MATRIZ NAO SIMETRICA.
*/

#include <stdio.h>

void fillMatrixRandomically(float matrix[6][6], int length1, int length2)
{
  for (int i = 0; i < length1; i++)
    for (int j = 0; j < length2; j++)
      matrix[i][j] = genRandon(1, 50);
}

int isSymetrical(float matrix[6][6], int length1, int length2)
{
  int result = 1;
  for (int i = 0; i < length1; i++)
    for (int j = 0; j < length2; j++)
      if (matrix[i][j] != matrix[j][i])
        result = 0;

  return result;
}

int genRandon(int startNumber, int endNumber)
{
  return rand() % endNumber + startNumber;
}

int main()
{
  srand(time(NULL));

  int length1 = 6, length2 = 6;
  float matrix[length1][length2];

  fillMatrixRandomically(matrix, length1, length2);
  isSymetrical(matrix, length1, length2) == 1 ? printf("\nMATRIZ SIMETRICA") : printf("\nMATRIZ NAO SIMETRICA");

  printf("\n\n");

  return 0;
}
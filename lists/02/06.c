/* 
6) Faça um algoritmo para imprimir o resultado da multiplicação de um número lido
pelo teclado (lido na função main) por uma matriz de inteiros 2 × 8 gerada
aleatoriamente com números de 0 até 29. A matriz que irá receber o resultado da
multiplicação do número pela matriz deve ser criada na função main. Utilize três
procedimentos: um para a geração da matriz, outro para calcular a multiplicação e um
terceiro para imprimir a matriz com o resultado da multiplicação.
*/

#include <stdio.h>

void fillMatrixRandomically(float matrix[2][8], int length1, int length2)
{
  for (int i = 0; i < length1; i++)
    for (int j = 0; j < length2; j++)
      matrix[i][j] = genRandon(0, 29);
}

void multiplyMatrix(int multiplier, float matrix[2][8], float multipliedMatrix[2][8], int length1, int length2)
{
  for (int i = 0; i < length1; i++)
    for (int j = 0; j < length2; j++)
      multipliedMatrix[i][j] = matrix[i][j] * multiplier;
}

void printMatrix(float matrix[2][8], int length1, int length2)
{
  for (int i = 0; i < length1; i++)
    for (int j = 0; j < length2; j++)
      printf("\nValor da matriz multiplicada na posição[%i][%i]: %f", i, j, matrix[i][j]);
}

int genRandon(int startNumber, int endNumber)
{
  return rand() % endNumber + startNumber;
}

int main()
{
  srand(time(NULL));

  int length1 = 2, length2 = 8, multiplier;
  float matrix[length1][length2], multipliedMatrix[length1][length2];

  printf("\nInforme o multiplicador: ");
  scanf("%i", &multiplier);

  fillMatrixRandomically(matrix, length1, length2);

  multiplyMatrix(multiplier, matrix, multipliedMatrix, length1, length2);

  printf("\nMatriz multiplicada: ");
  printMatrix(multipliedMatrix, length1, length2);
  printf("\n\n");

  return 0;
}
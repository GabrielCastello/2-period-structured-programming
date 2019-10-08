/* 21) Faça um algoritmo que preencha o vetor A com 20 números inteiros gerados aleatoriamente de 0 até 10.
Em seguida, preencha o vetor B onde cada elemento Bi receba o fatorial do elemento Ai , com 0 ≤ i ≤ 19. Crie
e utilize dois procedimentos: um para preencher o vetor A e outro para preencher o vetor B . Crie e utilize
também uma função para calcular o fatorial de um número.
 */

#include <stdio.h>

int genRandon(int startNumber, int endNumber)
{
  return rand() % endNumber + startNumber;
}

void fillArrayRandomically(int *array, int qty)
{
  for (int i = 0; i < qty; i++)
  {
    array[i] = genRandon(0, 10);
  }
};

void fillArrayFactorial(int *srcArray, int *array, int qty)
{
  for (int i = 0; i < qty; i++)
  {
    array[i] = factorial(srcArray[i]);
  }
};

int factorial(int n)
{
  int fat;
  for (fat = 1; n > 1; n = n - 1)
    fat = fat * n;
  return fat;
}

void printArray(int *array, int qty, char *text)
{
  for (int i = 0; i < qty; i++)
  {
    printf("\n%s[%i]: %i", text, i, array[i]);
  }
}

int main()
{
  srand(time(NULL));
  int qty = 20, arrayA[qty], arrayB[qty];
  char arrayATitle[] = "ArrayA", arrayBTitle[] = "ArrayA";

  fillArrayRandomically(arrayA, qty);
  fillArrayFactorial(arrayA, arrayB, qty);

  printf("\n");
  printArray(arrayA, qty, arrayATitle);
  printf("\n");
  printArray(arrayB, qty, arrayBTitle);

  printf("\n\n");
  return 0;
}
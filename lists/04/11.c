/* 11) Considere um vetor com 20 números inteiros gerados aleatoriamente de 1 até 30.
Faça um algoritmo para imprimir este vetor em ordem não-crescente utilizado o
algoritmo InsertionSort. Utilize três procedimentos: um para preencher o vetor, outro
para ordenar o vetor e um terceiro para imprimir o vetor antes e depois da ordenação. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Data
{
  int numbers[20];
};

int genRandomNumber(int startNumber, int endNumber)
{
  return rand() % endNumber + startNumber;
}

void setArrayData(int arr[], size_t len)
{
  for (int i = 0; i < len; i++)
    arr[i] = genRandomNumber(1, 30);
}

void insertionSort(int arr[], size_t len)
{
  int value, j;
  for (int i = 1; i < len; i++)
  {
    value = arr[i];
    for (j = i - 1; (j >= 0) && (value < arr[j]); j--)
    {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = value;
  }
}

void printNumbers(int arr[], size_t len)
{
  for (int i = 0; i < len; i++)
    printf("%i ", arr[i]);
}

int main()
{
  srand(time(NULL));

  struct Data numbers;

  setArrayData(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));
  printf("\nAntes da ordenação: ");
  printNumbers(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));
  printf("\n");
  insertionSort(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));
  printf("\nDepois da ordenação: ");
  printNumbers(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));

  printf("\n\n");
  return 0;
}
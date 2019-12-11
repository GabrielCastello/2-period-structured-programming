/* 8) Considere um vetor com 15 números inteiros lidos pelo teclado. Faça um algoritmo
para imprimir este vetor em ordem não-decrescente utilizado o algoritmo SelectionSort.
Utilize três procedimentos: um para preencher o vetor, outro para ordenar o vetor e um
terceiro para imprimir o vetor antes e depois da ordenação. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Data
{
  int numbers[15];
};

void setArrayData(int arr[], size_t len)
{
  for (int i = 0; i < len; i++)
  {
    if (i != 0)
      printf("\n-----------------------------------\n");
    printf("Digite o %iº número: ", i + 1);
    scanf("%i", &arr[i]);
  }
}

void selectionSort(int arr[], size_t len)
{
  int indexMin;
  for (int i = 0; i < len - 1; i++)
  {
    indexMin = i;
    for (int j = i + 1; j < len; j++)
      if (arr[j] < arr[indexMin])
        indexMin = j;

    if (indexMin != i)
    {
      int swap = arr[indexMin];
      arr[indexMin] = arr[i];
      arr[i] = swap;
    }
  }
}

void printNumbers(int arr[], size_t len)
{
  for (int i = 0; i < len; i++)
    printf("%i ", arr[i]);
}

int main()
{
  struct Data numbers;

  setArrayData(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));
  printf("\nAntes da ordenação: ");
  printNumbers(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));
  printf("\n");
  selectionSort(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));
  printf("\nDepois da ordenação: ");
  printNumbers(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));

  printf("\n\n");
  return 0;
}
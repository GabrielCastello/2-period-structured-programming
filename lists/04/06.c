/* 6) Considere um vetor com 15 números inteiros lidos pelo teclado. Faça um algoritmo
para imprimir este vetor em ordem não-decrescente utilizado o algoritmo BubbleSort.
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

void bubbleSort(int arr[], size_t len)
{
  int swap;
  for (int i = 0; i < len; i++)
    for (int j = 0; j < len - 1; j++)
      if (arr[j] > arr[j + 1])
      {
        swap = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = swap;
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
  bubbleSort(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));
  printf("\nDepois da ordenação: ");
  printNumbers(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));

  printf("\n\n");
  return 0;
}
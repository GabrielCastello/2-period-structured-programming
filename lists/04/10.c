/* 10) Considere um vetor com 15 números inteiros lidos pelo teclado. Faça um algoritmo
para imprimir este vetor em ordem não-decrescente utilizado o algoritmo
InsertionSort. Utilize três procedimentos: um para preencher o vetor, outro para
ordenar o vetor e um terceiro para imprimir o vetor antes e depois da ordenação. */

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
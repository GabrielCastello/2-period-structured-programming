/* 7) Considere um vetor com 20 números inteiros gerados aleatoriamente de 1 até 30.
Faça um algoritmo para imprimir este vetor em ordem não-crescente utilizado o
algoritmo BubbleSort. Utilize três procedimentos: um para preencher o vetor, outro
para ordenar o vetor e um terceiro para imprimir o vetor antes e depois da ordenação. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

void bubbleSort(int arr[], size_t len)
{
  int swap, counter = 1;
  for (int i = 0; i < len; i++)
  {
    printf("\n%i", counter++);
    for (int j = 0; j < len - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = swap;
      }
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

  srand(time(NULL));

  setArrayData(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));
  printf("\nAntes da ordenação: ");
  printNumbers(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));
  bubbleSort(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));
  printf("\nDepois da ordenação: ");
  printNumbers(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));

  printf("\n\n");
  return 0;
}
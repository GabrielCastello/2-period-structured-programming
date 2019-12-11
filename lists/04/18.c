/* 18) Considere um vetor com 20 números inteiros gerados aleatoriamente de 1 até 50.
Faça um algoritmo recursivo para calcular a soma dos elementos deste vetor. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Data
{
  int numbers[5];
};

int genRandomNumber(int startNumber, int endNumber)
{
  return rand() % endNumber + startNumber;
}

void setArrayData(int arr[], size_t len)
{
  for (int i = 0; i < len; i++)
    arr[i] = genRandomNumber(1, 5);
}

void printNumbers(int arr[], size_t len)
{
  for (int i = 0; i < len; i++)
    printf("%i ", arr[i]);
}

int calculateSum(int arr[], int i, int len)
{
  if (i >= len)
    return 0;
  else
  {
    return (arr[i] + calculateSum(arr, i + 1, len));
  }
}

int main()
{

  struct Data numbers;

  int sum, n;
  srand(time(NULL));

  setArrayData(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));
  printNumbers(numbers.numbers, sizeof(numbers.numbers) / sizeof(*numbers.numbers));

  sum = calculateSum(numbers.numbers, 0, sizeof(numbers.numbers) / sizeof(*numbers.numbers));
  printf("Sum of array elements: %d", sum);

  printf("\n\n");
  return 0;
}
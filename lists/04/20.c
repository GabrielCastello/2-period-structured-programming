/* 20) Considere um vetor com 20 números inteiros gerados aleatoriamente de 1 até 40.
Faça um algoritmo recursivo para imprimir o maior valor deste vetor. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Data
{
  int n;
};

int genRandomNumber(int startNumber, int endNumber)
{
  return rand() % endNumber + startNumber;
}

void setArrayData(int arr[], size_t len)
{
  for (int i = 0; i < len; i++)
    arr[i] = genRandomNumber(1, 40);
}

void printNumbers(int arr[], size_t len)
{
  for (int i = 0; i < len; i++)
    printf("%i ", arr[i]);
}

void printGreatestNumber(int arr[], size_t len, int i, int greaterN)
{
  printf("\ni: %i", i);
  int greater;
  printf("\ngreater: %i", greater);
  if (i > len)
  {
    printf("\ni>=len");
    return 0;
  }
  else
  {
    printf("\ni<len");
    if (i == 0)
    {
      printf("\ni == 0 ");
      greater = arr[i];
      i++;
      printGreatestNumber(arr, len, i, greater);
    }
    else
    {
      if (i == len)
      {
        printf("\ni == len - 1");
        printf("\nO maior valor é o %i.", greater);
      }
      else
      {
        if (arr[i] > greater)
        {
          printf("\narr[i] > greater");
          greater = arr[i];
        }
        i++;
        printGreatestNumber(arr, len, i, greater);
      }
    }
  }
}

int main()
{
  srand(time(NULL));

  struct Data randomNumbers[20];

  setArrayData(randomNumbers, sizeof(randomNumbers) / sizeof(*randomNumbers));

  printNumbers(randomNumbers, sizeof(randomNumbers) / sizeof(*randomNumbers));

  printGreatestNumber(randomNumbers, sizeof(randomNumbers) / sizeof(*randomNumbers), 0, 0);

  printf("\n\n");
  return 0;
}
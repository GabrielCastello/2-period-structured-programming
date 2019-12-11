/* 19) Na Série de Fibonacci os dois primeiros elementos são conhecidos (1 e 1), sendo
que os demais são gerados a partir da soma dos dois anteriores. 
Por exemplo, os dez primeiros elementos da Série são: 1, 1, 2, 3, 5, 8, 13, 21, 34, 55.
Faça um algoritmo recursivo para imprimir o elemento da posição n (n ≥ 1) dessa Série. 
Exemplos: se o usuário digitar n = 1 (ou seja, a primeira posição), deve ser impresso o número 1. 
Se o usuário digitar n = 6 (ou seja, a sexta posição), deve ser impresso o número 8. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Data
{
  int n;
};

void fillFibonacci(int arr[], int len, int i, int first, int second)
{
  if (i >= len)
    return 0;
  else
  {
    if (i < 2)
    {
      if (i == 0)
      {
        arr[i] = first;
        i++;
        fillFibonacci(arr, len, i, first, second);
      }
      if (i == 1)
      {
        arr[i] = second;
        i++;
        fillFibonacci(arr, len, i, first, second);
      }
    }
    else
    {
      arr[i] = arr[i - 1] + arr[i - 2];
      i++;
      fillFibonacci(arr, len, i, first, second);
    }
  }
}

void printFibonacci(int arr[], size_t len)
{
  for (int i = 0; i < len; i++)
    printf("%i ", arr[i]);
}

void printSelectedPosition(int arr[], size_t len)
{
  int validation = 0, n;
  do
  {
    printf("\nDigite a posição da série a ser impressa: ");
    scanf("%i", &n);
    for (int i = 0; i < len; i++)
      if (i + 1 == n)
      {
        printf("Valor da série fibonacci na posição %i: %i", n, arr[i]);
        validation = 1;
      }
    if (validation == 0)
      printf("\nA posição informada não existe na série de fibonacci, informe um valor entre 1 e %i.", len);
  } while (validation == 0);
}

int main()
{
  struct Data fibonacciSeries[10];
  int first = 1, second = 1;

  fillFibonacci(fibonacciSeries, sizeof(fibonacciSeries) / sizeof(*fibonacciSeries), 0, first, second);
  printf("\n");
  printFibonacci(fibonacciSeries, sizeof(fibonacciSeries) / sizeof(*fibonacciSeries));
  printSelectedPosition(fibonacciSeries, sizeof(fibonacciSeries) / sizeof(*fibonacciSeries));

  printf("\n\n");
  return 0;
}
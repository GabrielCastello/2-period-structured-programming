/* 16) Considere um número inteiro n (n ≥ 0) lido pelo teclado. Faça um algoritmo
recursivo para calcular o fatorial de n. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

float calculateFactorial(int n)
{
  if (n == 0)
    return 1;
  else
    return (n * calculateFactorial(n - 1));
}

int main()
{

  int n;
  float result;

  printf("\nInforme um número para calcular seu fatorial: ");
  scanf("%i", &n);

  if (n < 0)
    printf("Fatorial de um número negativo não está definido.\n");
  else
  {
    result = calculateFactorial(n);
    printf("%i! = %f\n", n, result);
  }
  printf("\n\n");
  return 0;
}
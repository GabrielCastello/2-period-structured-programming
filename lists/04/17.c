/* 17) Considere dois números inteiros a e b (b ≥ 0) lidos pelo teclado. Faça um algoritmo
recursivo para calcular o valor de a elevado a b. */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

float calculatePower(int a, int powerRaised)
{
  if (powerRaised == 0)
    return 1;
  else
    return (a * calculatePower(a, powerRaised - 1));
}

int main()
{

  int base, powerRaised;
  float result;

  printf("\nInforme o valor de a: ");
  scanf("%i", &base);
  printf("Informe o valor de b: ");
  scanf("%i", &powerRaised);

  if (powerRaised < 0)
    printf("Elevar a um número negativo não está definido.\n");
  else
  {
    result = calculatePower(base, powerRaised);
    printf("%i^%i = %f\n", base, powerRaised, result);
  }
  printf("\n\n");
  return 0;
}
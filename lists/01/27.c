/* 27) Considere um vetor com 50 números inteiros lidos pelo teclado. Faça um algoritmo que imprima o segundo
maior número presente no vetor. Crie e utilize dois procedimentos: uma para preencher o vetor e outro para
imprimir o segundo maior número.
Obs. 1: Não é permitido utilizar qualquer estrutura de dados auxiliar.
Obs. 2: Não é permitido ordenar o vetor.
 */

#include <stdio.h>
#include <limits.h>

void fillArray(int *numbers, int qty)
{
  for (int i = 0; i < qty; i++)
  {
    printf("\nInforme um número inteiro para a posição %i: ", i);
    scanf("%i", &numbers[i]);
  }
};

void printSecondGreater(int *array, int qty)
{
  int greater, secondGreater;
  greater = secondGreater = INT_MIN;
  for (int i = 0; i < qty; i++)
  {
    if (array[i] > greater)
    {
      secondGreater = greater;
      greater = array[i];
    }
    else if (array[i] > secondGreater && array[i] != greater)
      secondGreater = array[i];
  }
  if (secondGreater == INT_MIN)
    printf("\nNão existe um segundo maior número no array informado.");
  else
    printf("\nO segundo maior número é: %i", secondGreater);
}

int main()
{

  int qty = 10, numbers[qty];

  fillArray(numbers, qty);

  printSecondGreater(numbers, qty);

  printf("\n\n");

  return 0;
}
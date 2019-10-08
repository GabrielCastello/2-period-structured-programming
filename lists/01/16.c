/* 16) Faça um algoritmo para ler (pelo teclado) os 30 elementos de um vetor do tipo inteiro e vericar se o mesmo
está em ordem não-crescente. Crie e utilize um procedimento para preencher o vetor e uma função paravericação. A impressão da informação (se o vetor está ou não em ordem não-crescente) deve ser na função
main.
 */

#include <stdio.h>

void fillArray(int *numbers, int qty)
{
  for (int i = 0; i < qty; i++)
  {
    printf("\nInforme um número inteiro para a posição %i:", i);
    scanf("%i", &numbers[i]);
  }
};

int checkAscOrder(int *numbers, int qty)
{
  int result = 1;
  for (int i = 0; i < qty; i++)
  {
    if (i != 0)
    {
      if (!(numbers[i] > numbers[i - 1]))
        return result = 0;
    }
  }
  return result == 1 ? 1 : 0;
};

int main()
{

  int qty = 30, numbers[qty], x;

  fillArray(numbers, qty);

  checkAscOrder(numbers, qty) == 1 ? printf("\nO array está em ordem crescente!") : printf("\nO array não está em ordem crescente!");

  printf("\n\n");

  return 0;
}
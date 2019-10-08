/* 25) Considere um vetor com 100 números lidos pelo teclado. Faça um algoritmo que imprima todos os números
que aparecem somente uma vez no vetor. Crie e utilize dois procedimentos: uma para preencher o vetor e
outro para imprimir o que se pede. Exemplo com um vetor de 10 números:
Vetor: {3, 1, 9, 8, 3, 10, 1, 5, 9, 1}
Números que aparecem somente uma vez: 8, 10, 5
Obs.: Não é permitido utilizar qualquer estrutura de dados auxiliar.
 */

#include <stdio.h>

void fillArray(int *numbers, int qty)
{
  for (int i = 0; i < qty; i++)
  {
    printf("\nInforme um número inteiro para a posição %i: ", i);
    scanf("%i", &numbers[i]);
  }
};

void printUniq(int *array, int qty)
{
  int result = 1;
  for (int i = 0; i < qty; i++)
  {
    int valueQty = 0;
    for (int j = 0; j < qty; j++)
    {
      if (array[i] == array[j])
      {
        valueQty += 1;
      }
    }
    if (valueQty <= 1)
      printf("%i ", array[i]);
  }
};

int main()
{

  int qty = 100, numbers[qty];

  fillArray(numbers, qty);
  printUniq(numbers, qty);

  printf("\n\n");

  return 0;
}
/* 20) Faça um algoritmo que leia pelo teclado os 20 números do vetor A e construa um vetor B com os mesmos
números de A, sendo que estes deverão estar invertidos. Ou seja, o primeiro número de A passa a ser o último
de B , o segundo de A passa a ser o penúltimo de B e assim por diante. Crie e utilize dois procedimentos:
um para ler o vetor A e outro para preencher o vetor B . */

#include <stdio.h>

void fillArray(int *array, int qty)
{
  for (int i = 0; i < qty; i++)
  {
    printf("\nInforme um número inteiro para a posição %i:", i);
    scanf("%i", &array[i]);
  }
};

void invertArray(int *array, int *invertArray, int qty)
{
  for (int i = qty; i > 0; i--)
  {
    invertArray[i] = array[qty - i];
  }
}

int main()
{
  int qty = 20, array[qty], invertedArray[qty];

  fillArray(array, qty);

  invertArray(array, invertedArray, qty);

  for (int i = 0; i < qty; i++)
  {
    printf("\nArray: %i", array[i]);
  }

  printf("\n");

  for (int i = 0; i < qty; i++)
  {
    printf("\nInverted Array: %i", invertedArray[i]);
  }

  printf("\n\n");

  return 0;
}
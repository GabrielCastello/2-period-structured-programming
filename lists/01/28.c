/* 
Considere o vetor V com 50 números inteiros gerados aleatoriamente de 1 a 100. Faça um algoritmo que
modique V de modo que:
49
X
Vi =
 Vj , 0 ≤ i ≤ 49
j=0,
i6=j
Crie e utilize três procedimentos: um para preencher o vetor, outro para modicá-lo e o terceiro para
realizar a impressão do vetor antes e depois da modicação.
Obs.: Não é permitido utilizar qualquer estrutura de dados auxiliar.

 */

#include <stdio.h>

int genRandom(int startNumber, int endNumber)
{
  return rand() % endNumber + startNumber;
}

void fillArrayRandomically(int *array, int qty)
{
  for (int i = 0; i < qty; i++)
  {
    array[i] = genRandom(0, 100);
  }
};

void printArray(int *array, int qty)
{
  for (int i = 0; i < qty; i++)
  {
    printf("\n%i", array[i]);
  }
}

void modify(int *array, int qty)
{
  for (int i = 0; i < qty; i++)
  {
    for (int j = 0; j < qty; j++)
    {
      if (i != j)
      {
        array[i] += array[j];
      }
    }
  }
}

int main()
{
  int qty = 50, array[qty];

  fillArrayRandomically(array, qty);

  modify(array, qty);
  printArray(array, qty);

  printf("\n\n");
  return 0;
}
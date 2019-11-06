/* 
 Considere o vetor V com n números inteiros lidos pelo teclado, sendo n = 30. Faça um algoritmo para ler
pelo teclado na função main o número inteiro k (1 ≤ k ≤ 4) e imprimir o que se pede na expressão abaixo:
i+(k−1)
M ax
 X
 Vj
0≤i≤n−k
 j=i
Crie e utilize um procedimento para ler o vetor e uma função para retornar o que se pede. A impressão
desta informação deve ser realizada na função main.
Obs.: Não é permitido utilizar qualquer estrutura de dados auxiliar.

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

void printArray(int *array, int qty)
{
  for (int i = 0; i < qty; i++)
  {
    printf("\n%i", array[i]);
  }
}

int boringMath(int *array, int qty, int k)
{
  int sum = 0, greaterSum = 0;

  for (int i = 0; i <= qty - k; i++)
  {
    for (int j = i; j <= i + (k - 1); j++)
    {
      sum += array[j];
    }

    if (i == 0)
    {
      greaterSum = sum;
      sum = 0;
    }

    if (sum > greaterSum)
    {
      greaterSum = sum;
      sum = 0;
    }
  }

  return greaterSum;
}

int main()
{
  int qty = 3, array[qty], k;

  do
  {
    printf("\nInforme um valor para k entre 1 e 4: ");
    scanf("%i", &k);
  } while (!(k >= 1 && k <= 4));
  fillArray(array, qty);

  printf("\nboringMath result: %i", boringMath(array, qty, k));

  printf("\n\n");
  return 0;
}
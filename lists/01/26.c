/* 26) Considere um vetor com 100 números lidos pelo teclado. Faça um algoritmo para ler pelo teclado (na função
main ) um número inteiro n (1 ≤ n ≤ 100) e imprimir todos os números que aparecem no vetor exatamente n
vezes. Caso nenhum número apareça exatamente n vezes no vetor, esta informação deve ser impressa. Crie e
utilize dois procedimentos: uma para preencher o vetor e outro para imprimir o que se pede. Exemplo com
um vetor de 10 números e n = 2:
Vetor: {3, 1, 9, 8, 3, 10, 1, 5, 9, 1}
Números que aparecem exatamente 2 vezes: 3, 9
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

void printUniq(int *array, int qty, int n)
{
  int result = 1, newArrayQty = 0;
  for (int i = 0; i < qty; i++)
  {
    int valueQty = 0;
    for (int j = 0; j < qty; j++)
    {
      if (array[i] == array[j])
        valueQty += 1;
    }
    if (valueQty == n)
      newArrayQty += 1;
  }
  int newArray[newArrayQty], newCounter = 0;
  for (int i = 0; i < qty; i++)
  {
    int valueQty = 0;
    for (int j = 0; j < qty; j++)
    {
      if (array[i] == array[j])
        valueQty += 1;
    }
    if (valueQty == n)
    {
      newArray[newCounter] = array[i];
      newCounter += 1;
    }
  }

  for (int i = 0; i < newArrayQty; i++)
  {
    for (int j = i + 1; j < newArrayQty; j++)
    {
      if (newArray[i] == newArray[j])
      {
        for (int k = j; k < newArrayQty; k++)
        {
          newArray[k] = newArray[k + 1];
        }
        newArrayQty--;
        j--;
      }
    }
  }

  if (newArrayQty > 0)
  {
    for (int i = 0; i < newArrayQty; i++)
    {
      printf("%i ", newArray[i]);
    }
  }
  else
  {
    printf("\nNenhum número digitado %ix foi encontrado.", n);
  }
};

int main()
{

  int qty = 100, numbers[qty], n = 0;

  fillArray(numbers, qty);

  do
  {
    printf("\nInforme um valor entre 1 e 100 para n, onde n é quantidade de vezes que um número se repete no array: ");
    scanf("%i", &n);
  } while (!(n >= 1 && n <= 100));

  printUniq(numbers, qty, n);

  printf("\n\n");

  return 0;
}
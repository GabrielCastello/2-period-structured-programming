/* 1) Faça um algoritmo para verificar se um número real lido pelo teclado encontra-se ou não em um vetor com
30 números reais (também lido pelo teclado). Crie e utilize um procedimento para preencher o vetor e uma
função para verificar se o número pertence ou não ao vetor. A impressão desta informação (se o número
pertence ou não ao vetor) deve ser na função main.
*/
#include <stdio.h>

void fillNumbers(int *numbers, int qty)
{
  for (int i = 0; i < qty; i++)
  {
    printf("\nInforme um número inteiro para a posição %i:", i);
    scanf("%i", &numbers[i]);
  }
};

int compareNumber(int *numbers, int x, int qty)
{
  int result = 0;
  for (int i = 0; i < qty; i++)
  {
    if (numbers[i] == x)
      result = 1;
  }
  return result == 1 ? 1 : 0;
};

int main()
{

  int qty = 30, numbers[qty], x;

  fillNumbers(numbers, qty);

  printf("\nInforme o número inteiro X: ");
  scanf("%i", &x);

  compareNumber(numbers, x, qty) == 1 ? printf("\nO número %i pertence ao array informado anteriormente!", x) : printf("\nO número %i não pertence ao array informado anteriormente!", x);

  printf("\n\n");

  return 0;
}
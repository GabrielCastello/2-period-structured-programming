/* 22) Considere um vetor (lido pelo teclado) com 20 números ordenados de maneira não-decrescente. Faça um
algoritmo para ler cinco números (um de cada vez) e, a cada leitura, inserir o número no vetor, mantendo o
mesmo ordenado. Crie e utilize três procedimentos: um para preencher o vetor com os 20 números; outro
para ler os cinco números, inseri-los no vetor e organizar o mesmo; e o último para imprimir o vetor após a
organização.
Obs. 1: O procedimento para preencher o vetor pelo teclado só pode permitir inserir o número no vetor
se o mesmo continuar em ordem não-decrescente. Ou seja, enquanto o número digitado não mantiver o vetor
ordenado, o usuário deve digitar um novo número;
Obs. 2: Não é permitido utilizar qualquer estrutura de dados auxiliar.
Obs. 3: Não é permitido utilizar qualquer algoritmo de ordenação. */

#include <stdio.h>

void fillArray(int *numbers, int qty)
{
  for (int i = 0; i < qty - 5; i++)
  {
    int input, validation;
    do
    {
      printf("\nInforme um número inteiro para a posição %i:", i);
      scanf("%i", &input);
      validation = validate(numbers[i - 1], input);
    } while (i != 0 ? validation : 0);
    numbers[i] = input;
  }
};

int validate(int a, int b)
{
  printf("\nA: %i", a);
  printf("\nB: %i", b);
  return a > b;
}

void printArray(int *array, int qty, char *text)
{
  for (int i = 0; i < qty; i++)
  {
    printf("\n%s[%i]: %i", text, i, array[i]);
  }
}

int main()
{
  int qty = 10, arrayA[qty], arrayB[qty];
  char arrayATitle[] = "ArrayA", arrayBTitle[] = "ArrayA";

  fillArray(arrayA, qty);

  printf("\n");
  printArray(arrayA, qty, arrayATitle);

  printf("\n\n");
  return 0;
}

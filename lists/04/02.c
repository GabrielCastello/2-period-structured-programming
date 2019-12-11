/* 2) Considerando a struct do exercício anterior, faça um algoritmo que preencha os
dados da conta bancária de 20 clientes e depois imprima quantos deles têm saldo
bancário de no máximo 3 salários mínimos, onde o salário mínimo é igual a R$ 880,00.
Utilize um procedimento para preencher os dados dos clientes e uma função para
retornar (para a função main) a quantidade de clientes. */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

struct Data
{
  int accountNumber;
  char name[100];
  float accountBalance;
};

void fillClientData(struct Data clients[], size_t len)
{
  for (int i = 0; i < len; i++)
  {
    if (i != 0)
      printf("\nProxima conta:\n");
    printf("Informe o número da conta: ");
    scanf("%i", &clients[i].accountNumber);

    printf("Informe o nome: ");
    scanf(" %[^\n]s", clients[i].name);

    printf("Informe o saldo da conta: ");
    scanf("%f", &clients[i].accountBalance);
  }
}

int countClients(struct Data clients[], size_t len, float minWage)
{
  int counter = 0;
  for (int i = 0; i < len; i++)
    if (clients[i].accountBalance <= 3 * minWage)
      counter++;
  return counter;
}

int main()
{
  int counter = 0;
  float minWage = 880.00;
  struct Data clients[20];

  fillClientData(clients, sizeof(clients) / sizeof(*clients));
  counter = countClients(clients, sizeof(clients) / sizeof(*clients), minWage);
  if (counter != 0)
    printf("\n%i clientes com saldo bancário de no máximo 3 salários mínimos.", counter);
  else
    printf("\nNenhum cliente com saldo bancário de no máximo 3 salários mínimos.");

  printf("\n\n");
  return 0;
}
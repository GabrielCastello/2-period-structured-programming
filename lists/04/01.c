/* 1) Considere uma struct que armazena os seguintes dados de uma conta bancária:
número da conta, o primeiro nome do cliente e saldo. Faça um algoritmo que preencha
os dados da conta bancária de 20 clientes e depois imprima quantos deles têm saldo
bancário maior do que R$ 1.000,00. */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

struct dados
{
  int accountNumber;
  char name[100];
  float accountBalance;
};

int main()
{
  int clientQty = 20, validation = 0;
  struct dados clients[clientQty];

  for (int i = 0; i < clientQty; i++)
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

  printf("\nClientes com saldo bancário maior do que R$ 1.000,00: ");
  for (int i = 0; i < clientQty; i++)
  {
    if (clients[i].accountBalance > 1000)
    {
      validation = 1;
      printf("\nNome: %s | Saldo: %4.2f.", clients[i].name, clients[i].accountBalance);
    }
  }
  if (validation == 0)
    printf("\nNenhum cliente com saldo bancário maior do que R$ 1.000,00.");

  printf("\n\n");

  return 0;
}
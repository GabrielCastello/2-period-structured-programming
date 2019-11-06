/* 
21) Faça um algoritmo que leia o nome completo (com no máximo 20 letrasconsiderando espaços) de 50 pessoas. 
Após a leitura de todos os nomes, o algoritmo
deve imprimir os mesmos em ordem inversa de entrada. Crie e utilize dois
procedimentos: um para ler os nomes e outro para imprimir os mesmos em ordem
inversa de entrada.
*/

#include <stdio.h>
#include <string.h>

void fillNames(char names[2][21], int rows)
{
  for (int i = 0; i < rows; i++)
  {
    scanf(" %20[^\n]s", names[i]);
  }
}

void printInvertedNames(char names[2][21], int rows, int columns)
{
  for (int i = rows - 1; i >= 0; i--)
  {
    printf("%s\n", names[i]);
  }
}

int main()
{
  int rows = 2, columns = 20;
  char names[2][21];

  fillNames(names, rows);

  printf("\n\n");

  printInvertedNames(names, rows, columns);

  printf("\n\n");

  return 0;
}
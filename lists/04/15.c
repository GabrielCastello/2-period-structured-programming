/* 15) Considere uma struct que armazena o primeiro nome, a idade, o salário e o cargo de
10 funcionários de uma empresa. Faça um algoritmo que imprima os funcionários em
ordem não-decrescente pela idade utilizando o algoritmo SelectionSort. Utilize três
procedimentos: um para preencher os dados dos funcionários, outro para realizar a
ordenação e um terceiro para imprimir os dados depois da ordenação. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct EmployeeInfo
{
  char firstName[50], occupation[50];
  int age;
  float wage;
};

void setArrayData(struct EmployeeInfo arr[], size_t len)
{
  for (int i = 0; i < len; i++)
  {
    if (i != 0)
      printf("\n-----------------------------------\n");

    printf("Informe o primeiro nome: ");
    scanf(" %[^\n]s", arr[i].firstName);

    printf("Informe a idade: ");
    scanf("%i", &arr[i].age);

    printf("Informe o salário: ");
    scanf("%f", &arr[i].wage);

    printf("Informe o cargo: ");
    scanf(" %[^\n]s", &arr[i].occupation);
  }
}

void selectionSort(struct EmployeeInfo arr[], size_t len)
{
  int indexMin;
  for (int i = 0; i < len - 1; i++)
  {
    indexMin = i;
    for (int j = i + 1; j < len; j++)
      if (arr[j].age < arr[indexMin].age)
        indexMin = j;

    if (indexMin != i)
    {
      int swap = arr[indexMin].age;
      arr[indexMin].age = arr[i].age;
      arr[i].age = swap;
    }
  }
}

void printData(struct EmployeeInfo arr[], size_t len)
{
  for (int i = 0; i < len; i++)
  {
    if (i != 0)
      printf("\n-----------------------------------\n");

    printf("Nome: %s\n", arr[i].firstName);
    printf("Idade: %i\n", arr[i].age);
    printf("Salário: %4.2f\n", arr[i].wage);
    printf("Cargo: %s\n", arr[i].occupation);
  }
}

int main()
{
  struct EmployeeInfo employees[3];

  setArrayData(employees, sizeof(employees) / sizeof(*employees));
  printf("\nAntes da ordenação: ");
  printData(employees, sizeof(employees) / sizeof(*employees));
  printf("\n");
  selectionSort(employees, sizeof(employees) / sizeof(*employees));
  printf("\nDepois da ordenação: ");
  printData(employees, sizeof(employees) / sizeof(*employees));

  printf("\n\n");
  return 0;
}
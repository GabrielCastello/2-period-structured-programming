/* 14) Considere um arquivo chamado "Pessoas.txt" que armazena em cada linha o nome
de uma pessoa e o seu ano de nascimento. Faça um algoritmo para ler esse arquivo e
criar dois outros arquivos: um chamado "Maiores.txt", que contém em cada linha o
nome e a idade das pessoas maiores de idade (idade ≥ 18 anos) e outro chamado
"Menores.txt", que contém em cada linha o nome e a idade das pessoas menores de
idade (idade < 18 anos).*/

#include <stdio.h>
#include <string.h>

int main()
{

  FILE *inputFile, *minorsFile, *greatersFile;

  inputFile = fopen("14Pessoas.txt", "r");

  if (inputFile == NULL)
  {
    printf("\nFalha na abertura do arquivo\n\n");
    return 1;
  }

  char name[100];
  minorsFile = fopen("14Menores.txt", "w");
  greatersFile = fopen("14Maiores.txt", "w");
  while (!feof(inputFile))
  {
    int age;
    fscanf(inputFile, "%s %i", name, &age);
    printf("\n%s %i", name, age);
    fprintf(age >= 18 ? greatersFile : minorsFile, "%s %i\n", name, age);
  }

  printf("\n\n");
  return 0;
}
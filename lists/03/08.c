/* 8) Considere um arquivo de entrada chamado "Cidades.txt" que armazena (em cada
linha) o nome de uma cidade (sem espaços) e o seu número de habitantes. Faça um
algoritmo que leia o arquivo de entrada e gere um arquivo chamado "Saida.txt"
contendo o nome da cidade mais populosa seguida do seu número de habitantes.
*/

#include <stdio.h>
#include <string.h>

int main()
{

  FILE *inputFile, *outputFile;

  inputFile = fopen("08Cidades.txt", "r");

  if (inputFile == NULL)
  {
    printf("\nFalha na abertura do arquivo\n\n");
    return 1;
  }

  outputFile = fopen("08Saida.txt", "w");

  char city[100], auxCity[100];
  int population = 0, auxPop;
  while (!feof(inputFile))
  {
    fscanf(inputFile, "%s %i", auxCity, &auxPop);
    if (auxPop > population)
    {
      population = auxPop;
      strcpy(city, auxCity);
    }
  }

  fprintf(outputFile, "%s %i", city, population);

  printf("\n\n");
  return 0;
}
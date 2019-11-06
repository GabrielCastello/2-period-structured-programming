/* 13) Considere um arquivo chamado "Cidades.txt" que armazena em cada linha o nome
de uma cidade e o seu número de habitantes. 
Faça um algoritmo para ler esse arquivo e criar um arquivo chamado "Populacao.txt" contendo o nome da cidade mais populosa
seguida pelo seu número de habitantes.
- Obs.: A função strcpy(str1,str2) da biblioteca string.h copia uma string para outra.
Ela copia a string str2 para a string str1.
 */

#include <stdio.h>
#include <string.h>

int main()
{

  FILE *inputFile, *outputFile;

  inputFile = fopen("13Cidades.txt", "r");

  if (inputFile == NULL)
  {
    printf("\nFalha na abertura do arquivo\n\n");
    return 1;
  }

  outputFile = fopen("13Populacao.txt", "w");

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
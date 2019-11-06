/* 15) Faça um algoritmo para imprimir o número de palavras (de no máximo 20
caracteres) presentes no arquivo "Texto.txt". Considere que o arquivo não possui
qualquer número, somente palavras.*/

#include <stdio.h>
#include <string.h>

int main()
{

  FILE *inputFile;

  inputFile = fopen("15Texto.txt", "r");

  if (inputFile == NULL)
  {
    printf("\nFalha na abertura do arquivo\n\n");
    return 1;
  }

  int wordsCounter = 0;
  while (!feof(inputFile))
  {
    char name[100];
    fscanf(inputFile, "%s", name);
    if (strlen(name) <= 20)
      wordsCounter++;
  }
  printf("\nTotal de palavras com no máximo 20 caracteres: %i", wordsCounter);
  printf("\n\n");
  return 0;
}
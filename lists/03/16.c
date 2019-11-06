/* 16) Considere um arquivo chamado "Palavras.txt" que armazena em cada linha uma
palavra de no máximo 15 caracteres. Faça um algoritmo para ler pelo teclado uma
palavra (também de no máximo 15 caracteres) e imprimir o número de vezes que essa
palavra aparece no arquivo.
- Obs.: Utilize a função strcmp(str1,str2) da biblioteca string.h para comparar as
palavras. Esta função retorna 0 (zero) se str1 é igual a str2. */

#include <stdio.h>
#include <string.h>

int main()
{

  FILE *inputFile = fopen("16Palavras.txt", "r");

  if (inputFile == NULL)
  {
    printf("\nFalha na abertura do arquivo\n\n");
    return 1;
  }

  char inputWord[16], validationWord[100];
  int counter = 0;

  do
  {
    printf("Informe uma palavra (de no máximo 15 caracteres): ");
    scanf(" %[^\n]s", &validationWord);
  } while (strlen(validationWord) > 15);
  strcpy(inputWord, validationWord);

  while (!feof(inputFile))
  {
    char fileWord[100];
    fscanf(inputFile, "%s", fileWord);
    if (strcmp(inputWord, fileWord) == 0)
      counter++;
  }

  counter != 0 ? printf("\nA palavra %s aparece %ix no arquivo.", inputWord, counter) : printf("\nA palavra %s não aparece no arquivo.", inputWord);

  printf("\n\n");
  return 0;
}
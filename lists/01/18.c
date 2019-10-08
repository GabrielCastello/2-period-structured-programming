/* 18) Faça um algoritmo que leia duas frases (de no máximo 20 caracteres cada uma) e imprima se as frases
possuem o mesmo comprimento, bem como se são iguais ou diferentes no conteúdo. Exemplo:
Frase 1: Brasil Hexa 2010
Frase 2: Brasil! Hexa 2010!
Resultado: As duas frases são de tamanhos diferentes. As duas frases possuem conteúdo distintos.
Obs.: Considere que as frases não iniciam e nem terminam com espaço, bem como só existe um único espaço
entre as palavras das frases.
 */

#include <stdio.h>
#include <string.h>

void printSmallerStr(char *string1, char *string2)
{
  int str1Length = strlen(string1);
  int str2Length = strlen(string2);

  if (str2Length == str1Length)
  {
    int stringCmp;
    stringCmp = strcmp(string1, string2);

    if (stringCmp == 0)
      printf("\nAs duas frases são do mesmo tamanho. As duas frases possuem o mesmo conteúdo.\nPrimeira string: %s \nSegunda string: %s", string1, string2);
    else
      printf("\nAs duas frases são do mesmo tamanho. As duas frases possuem conteúdo distintos.\nPrimeira string: %s \nSegunda string: %s", string1, string2);
  }
  else
  {
    int stringCmp;
    stringCmp = strcmp(string1, string2);

    if (stringCmp == 0)
      printf("\nAs duas frases são de tamanhos diferentes. As duas frases possuem o mesmo conteúdo.\nPrimeira string: %s \nSegunda string: %s", string1, string2);
    else
      printf("\nAs duas frases são de tamanhos diferentes. As duas frases possuem conteúdo distintos.\nPrimeira string: %s \nSegunda string: %s", string1, string2);
  }
}

int verifyLength(char *str)
{
  int length = strlen(str);
  return length <= 20 ? 1 : 0;
}

void fillWord(char *word, int length, char *text)
{
  char verify[200] = {'\0'};
  do
  {
    printf("\nDigite a %s: ", text);
    scanf(" %[^\n]s", verify);
  } while (verifyLength(verify) != 1);
  strcpy(word, verify);
}

int main()
{
  int length = 21;
  char phrase1[length], text1[] = "primeira frase", phrase2[length], text2[] = "segunda frase";

  fillWord(phrase1, length, text1);
  fillWord(phrase2, length, text2);

  printf("\n\n");

  printSmallerStr(phrase1, phrase2);

  printf("\n\n");

  return 0;
}
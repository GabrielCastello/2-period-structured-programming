/* 23) Faça um algoritmo para ler duas palavras (com no máximo 10 caracteres cada uma) e imprimir as mesmas
em ordem alfabética. Crie e utilize dois procedimentos: um para ler as palavras e outro para imprimir o que
se pede.
Obs.: Considere que o usuário digitará somente letras minúsculas.
 */

#include <stdio.h>
#include <string.h>

void printAlphabetically(char *word1, char *word2)
{
  if (strcmp(word1, word2) < 0)
  {
    printf("\n%s", word1);
    printf("\n%s", word2);
  }
  else
  {
    printf("\n%s", word2);
    printf("\n%s", word1);
  }
}

int verifyLength(char *str)
{
  int length = strlen(str);
  return length <= 20 ? 1 : 0;
}

void readWord(char *word, int length, char *text)
{
  char verify[200] = {'\0'};
  do
  {
    printf("\nDigite %s palavra com no máximo 10 caracteres: ", text);
    scanf(" %[^\n]s", verify);
  } while (verifyLength(verify) != 1);
  strcpy(word, verify);
}

int main()
{
  int length = 11;
  char word1[length], word2[length], text1[] = "a primeira", text2[] = "a segunda";
  readWord(word1, length, text1);
  readWord(word2, length, text2);

  printAlphabetically(word1, word2);

  printf("\n\n");

  return 0;
}

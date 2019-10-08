/* 17) Faça um algoritmo para ler duas palavras (com no máximo 10 caracteres cada uma) e imprimir a menor
delas ou se elas têm o mesmo tamanho. Crie e utilize dois procedimentos: um para ler as palavras e outro
para imprimir o que se pede.
Obs.: Considere que o usuário digitará somente letras minúsculas.
 */

#include <stdio.h>
#include <string.h>

void printSmallerStr(char *string1, char *string2)
{
  int str1Length = strlen(string1);
  int str2Length = strlen(string2);

  if (str1Length < str2Length)
    printf("\nA menor string é: %s", string1);

  if (str2Length < str1Length)
    printf("\nA menor string é: %s", string2);

  if (str2Length == str1Length)
    printf("\nAs palavras tem o mesmo tamanho.\nPrimeira string: %s \nSegunda string: %s", string1, string2);
}

int verifyLength(char *str)
{
  int length = strlen(str);
  return length <= 10 ? 1 : 0;
}

void fillWord(char *word, int length, char *text)
{
  char verify[200] = {'\0'};
  do
  {
    printf("\nDigite a %s: ", text);
    scanf(" %s", verify);
  } while (verifyLength(verify) != 1);
  strcpy(word, verify);
}

int main()
{
  int length = 11;
  char word1[length], text1[] = "primeira palavra", word2[length], text2[] = "segunda palavra";

  fillWord(word1, length, text1);
  fillWord(word2, length, text2);

  printf("\n\n");

  printSmallerStr(word1, word2);

  printf("\n\n");

  return 0;
}
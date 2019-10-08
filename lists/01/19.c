/*  Faça um algoritmo para ler uma palavra pelo teclado (com no máximo 15 caracteres) e vericar se ela é
Palíndrome ou não, sem utilizar qualquer estrutura de dados auxiliar. Crie e utilize um procedimento
para ler a palavra e uma função para fazer a vericação. A impressão da mensagem (se a palavra é ou não
Palíndrome) deve ser na função main.
Obs. 1: Uma palavra Palíndrome é aquela que lida de frente para trás e de trás para frente tem a mesma
sequência de caracteres. Exemplos: arara, ovo, asa, radar, matam, etc;
Obs. 2: Lembre-se que o usuário pode digitar letras maiúsculas e minúsculas.
 */

#include <stdio.h>
#include <string.h>

char *strrev(char *str)
{
  if (!str || !*str)
    return str;

  int i = strlen(str) - 1, j = 0;

  char ch;
  while (i > j)
  {
    ch = str[i];
    str[i] = str[j];
    str[j] = ch;
    i--;
    j++;
  }
  return str;
}

int isPalindrome(char *string)
{
  char reverseString[16];
  int verifier = 0;

  strcpy(reverseString, string);

  strrev(reverseString);

  verifier = strcmp(string, reverseString);
  return verifier == 0 ? 1 : 0;
}

int verifyLength(char *str)
{
  int length = strlen(str);
  return length <= 15 ? 1 : 0;
}

void fillWord(char *word, int length, char *text)
{
  char verify[200] = {'\0'};
  do
  {
    printf("\nDigite %s: ", text);
    scanf(" %[^\n]s", verify);
  } while (verifyLength(verify) != 1);
  strcpy(word, verify);
}

int main()
{
  int length = 16;
  char word1[length], text1[] = "uma palavra com no máximo 15 caracteres";

  fillWord(word1, length, text1);

  isPalindrome(word1) ? printf("\nA palavra %s é palindrome!", word1) : printf("\nA palavra %s não é palindrome!", word1);

  printf("\n\n");

  return 0;
}

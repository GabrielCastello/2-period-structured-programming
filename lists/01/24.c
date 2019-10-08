/* 24) Faça um algoritmo que leia uma palavra (com no máximo 15 caracteres) e depois embaralhe os caracteres
da mesma, fazendo a sua impressão ao final. Por exemplo: recebendo a palavra python, pode ser retornado
npthyo, ophtyn ou qualquer outra combinação possível, de forma aleatória. Crie e utilize dois procedimentos:
um para ler a palavra e outro para embaralhar e imprimir a mesma ao final.
Obs. 1: Não é permitido utilizar qualquer estrutura de dados auxiliar.
Obs. 2: Considere que o usuário digitará somente letras minúsculas.
 */

#include <stdio.h>
#include <string.h>

int genRandon(int startNumber, int endNumber)
{
  return rand() % endNumber + startNumber;
}

void shuffleWord(char *word)
{
  int arrayLength = strlen(word);
  char aux;
  for (int i = 0; i < arrayLength; i++)
  {
    int position1 = genRandon(0, arrayLength - 1);
    int position2 = genRandon(0, arrayLength - 1);
    aux = word[position1];
    word[position1] = word[position2];
    word[position2] = aux;
  }

  printf("\nShuffled Word: %s", word);
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
    printf("\nDigite uma %s: ", text);
    scanf(" %[^\n]s", verify);
  } while (verifyLength(verify) != 1);
  strcpy(word, verify);
}

int main()
{
  srand(time(NULL));
  int length = 16;
  char word[length], text[] = "palavra com no máximo 15 caracteres";
  readWord(word, length, text);
  shuffleWord(word);

  printf("\n\n");

  return 0;
}

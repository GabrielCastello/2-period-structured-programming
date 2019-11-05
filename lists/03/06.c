/* 6) Faça um algoritmo para ler 10 números inteiros a partir de um arquivo chamado
"Numeros.txt" e depois imprima-os na tela em ordem crescente.
- Obs.: Para facilitar, leia os números do arquivo, armazene-os em um vetor e depois
ordene este vetor. Seu algoritmo deve ter um procedimento para ordenar o vetor e outro
para imprimir o vetor antes e depois da ordenação.
*/

#include <stdio.h>

void printArray(int *array, int arraySize)
{
  for (int i = 0; i < arraySize; i++)
    printf("%i\n", array[i]);
}

void sortArray(int *array, int arraySize)
{
  for (int i = 0; i < arraySize; i++)
    for (int j = i + 1; j < arraySize; j++)
    {
      if (array[i] > array[j])
      {
        int aux = array[i];
        array[i] = array[j];
        array[j] = aux;
      }
    }
}

int main()
{

  FILE *inputFile;

  inputFile = fopen("06Numeros.txt", "r");

  if (inputFile == NULL)
  {
    printf("\nFalha na abertura do arquivo\n\n");
    return 1;
  }

  int array[10], i = 0;

  while (!feof(inputFile))
  {
    fscanf(inputFile, "%i", &array[i]);
    i++;
  }

  printf("\n\n");
  printArray(array, i);
  printf("\n");
  sortArray(array, i);
  printf("\n");
  printArray(array, i);

  printf("\n\n");

  return 0;
}
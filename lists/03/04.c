/* 4) Considere um arquivo chamado "Matriz4x4.txt" que armazena uma matriz
quadrada de ordem 4 com números inteiros. Faça um algoritmo para ler esta matriz do
arquivo e criar outro arquivo chamado "Transposta.txt" que conterá a matriz transposta
da matriz lida.
 */

#include <stdio.h>

int main()
{

  FILE *inputFile, *outputFile;

  inputFile = fopen("04Matriz4x4.txt", "r");

  if (inputFile == NULL)
  {
    printf("\nFalha na abertura do arquivo\n\n");
    return 1;
  }

  outputFile = fopen("04Transposta.txt", "w");

  int srcMatrix[4][4], i = 0;
  while (!feof(inputFile))
  {
    fscanf(inputFile, "%i %i %i %i", &srcMatrix[i][0], &srcMatrix[i][1], &srcMatrix[i][2], &srcMatrix[i][3]);
    i++;
  }
  int srcMatrixSize = i;
  for (int i = 0; i < srcMatrixSize; i++)
    fprintf(outputFile, "%i %i %i %i\n", srcMatrix[0][i], srcMatrix[1][i], srcMatrix[2][i], srcMatrix[3][i]);

  printf("\n\n");

  return 0;
}
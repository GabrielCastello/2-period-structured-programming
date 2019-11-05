/* 10) Considere um arquivo chamado "Matriz4x5.txt" que armazena uma matriz de
tamanho 4 x 5 de números inteiros. Faça um algoritmo para ler essa matriz do arquivo,
trocar a primeira linha com a quarta e imprimir a nova matriz no arquivo chamado
"MatrizAlterada.txt". A matriz que receberá os valores lidos do arquivo deve ser
criada na função main( ) e não deve ser utilizada uma matriz auxiliar para realizar troca das linhas.
Utilize três procedimentos: um para ler a matriz do arquivo de entrada, outro para
realizar a troca das linhas e um terceiro para imprimir no arquivo de saída a matriz
alterada.*/

#include <stdio.h>

void readFile(int *inputFile, int srcMatrix[4][5], int rows, int columns)
{
  while (!feof(inputFile))
  {
    int number;
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < columns; j++)
        fscanf(inputFile, "%i", &srcMatrix[i][j]);
      printf("\n");
    }
  }
  fclose(inputFile);
}

void changeLines(int srcMatrix[4][5], int rows, int columns)
{
  int aux;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
    {
      if (i == 0)
      {
        int aux = srcMatrix[3][j];
        srcMatrix[3][j] = srcMatrix[i][j];
        srcMatrix[i][j] = aux;
      }
    }
}

void writeFile(int *outputFile, int srcMatrix[4][5], int rows, int columns)
{
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
      fprintf(outputFile, "%i ", srcMatrix[i][j]);
    fprintf(outputFile, "\n");
  }
}

int main()
{

  FILE *inputFile, *outputFile;

  inputFile = fopen("10Matriz4x5.txt", "r");
  outputFile = fopen("10MatrizAlterada.txt", "w");

  int rows = 4, columns = 5, srcMatrix[rows][columns];

  readFile(inputFile, srcMatrix, rows, columns);
  changeLines(srcMatrix, rows, columns);
  writeFile(outputFile, srcMatrix, rows, columns);

  printf("\n\n");
  return 0;
}
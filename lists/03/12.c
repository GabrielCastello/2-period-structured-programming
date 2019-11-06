/* 12) Considere um arquivo chamado "Matriz5x6.txt" que armazena uma matriz de
tamanho 5 x 6 de números inteiros. Faça um algoritmo para ler essa matriz do arquivo,
realizar a soma dos elementos da segunda, quarta e sexta colunas e imprimir o resultado
da soma no arquivo chamado "Soma.txt". A matriz que receberá os valores lidos do
arquivo deve ser criada na função main( ).
Utilize uma função para realizar o cálculo da soma (retornando esse valor parafunção main( )) 
e dois procedimentos: um para ler a matriz do arquivo de entradaoutro para imprimir no arquivo de saída o resultado da soma.*/

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

int sumColumns(int srcMatrix[4][5], int rows, int columns)
{
  int sum = 0;
  for (int i = 0; i < rows; i++)
    for (int j = 0; j < columns; j++)
      if (j == 1 || j == 3 || j == 5)
        sum += srcMatrix[i][j];
  return sum;
}

void writeSumToFile(int *outputFile, int sum)
{
  fprintf(outputFile, "Soma: %i", sum);
}

int main()
{
  FILE *inputFile, *outputFile;

  inputFile = fopen("12Matriz5x6.txt", "r");
  outputFile = fopen("12Soma.txt", "w");

  int rows = 5, columns = 6, srcMatrix[rows][columns];
  readFile(inputFile, srcMatrix, rows, columns);
  writeSumToFile(outputFile, sumColumns(srcMatrix, rows, columns));

  printf("\n\n");
  return 0;
}
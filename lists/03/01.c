/* 1) Faça um algoritmo que leia de um arquivo chamado "Turma.txt" o nome dos alunos
de uma turma e as suas três notas. Seu algoritmo deve ter como saída um arquivo
chamado "MediasAlunos.txt" que contém os nomes dos alunos e suas respectivas
médias (com duas casas decimais).
 */

#include <stdio.h>

int main()
{

  FILE *inputFile, *outputFile;

  inputFile = fopen("01Turma.txt", "r");

  if (inputFile == NULL)
  {
    printf("\nFalha na abertura do arquivo\n\n");
    return 1;
  }

  char name[100];
  float grade1, grade2, grade3;
  outputFile = fopen("01MediasAlunos.txt", "w");
  while (!feof(inputFile))
  {
    float mean;
    fscanf(inputFile, "%s %f %f %f", name, &grade1, &grade2, &grade3);
    printf("\n\n%s %2.2f %2.2f %2.2f", name, grade1, grade2, grade3);
    mean = (grade1 + grade2 + grade3) / 3;
    printf("\nMédia: %2.2f", mean);
    fprintf(outputFile, "%s %2.2f\n", name, mean);
  }

  fclose(inputFile);
  fclose(outputFile);

  printf("\n\n");

  return 0;
}
/* 3) Faça um algoritmo que leia de um arquivo chamado "Medias.txt" o nome dos alunos
e as suas respectivas médias. Seu algoritmo deve ter como saída um arquivo chamado
"Aprovados.txt", que contém os nomes dos alunos com média igual ou superior a 7.0, e
outro arquivo chamado "Reprovados.txt", que contém os nomes dos alunos com média
inferior a 7.0.
*/
#include <stdio.h>

int main()
{

  FILE *inputFile, *approvedFile, *reprovedFile;

  inputFile = fopen("03Medias.txt", "r");

  if (inputFile == NULL)
  {
    printf("\nFalha na abertura do arquivo\n\n");
    return 1;
  }

  char name[100];
  float grade1, grade2, grade3;
  approvedFile = fopen("03Approved.txt", "w");
  reprovedFile = fopen("03Reproved.txt", "w");
  while (!feof(inputFile))
  {
    float mean;
    fscanf(inputFile, "%s %f", name, &mean);
    printf("\n%s %1.1f", name, mean);
    fprintf(mean >= 7.0 ? approvedFile : reprovedFile, "%s %1.1f\n", name, mean);
  }

  printf("\n\n");

  return 0;
}

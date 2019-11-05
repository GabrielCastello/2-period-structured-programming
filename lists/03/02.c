/* 2) Suponha que cada aluno faça três provas, como mostra cada linha do arquivo
"Notas.txt". Faça um algoritmo para gerar o arquivo "Situacao.txt", onde cada linha
contenha a média final do aluno e sua situação: “A” – Aprovado (média igual ou
superior a 5.0) ou “R” – Reprovado (média inferior a 5.0). */

#include <stdio.h>

int main()
{

  FILE *inputFile, *outputFile;

  inputFile = fopen("02Notas.txt", "r");

  if (inputFile == NULL)
  {
    printf("\nFalha na abertura do arquivo\n\n");
    return 1;
  }

  float grade1, grade2, grade3;
  outputFile = fopen("02Situação.txt", "w");
  while (!feof(inputFile))
  {

    fscanf(inputFile, "%f %f %f", &grade1, &grade2, &grade3);
    // printf("\n\n %2.2f %2.2f %2.2f", grade1, grade2, grade3);
    float mean = (grade1 + grade2 + grade3) / 3;
    char situation = mean >= 5.0 ? 'A' : 'R';
    // printf("\nMédia: %c %2.2f", situation, mean);
    fprintf(outputFile, "\n %2.2f %c\n", mean, situation);
  }

  printf("\n\n");

  return 0;
}
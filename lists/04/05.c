/* 5) Considerando a struct do exercício anterior, faça um algoritmo que preencha os
dados de 30 alunos, sendo que a nota da P3 será calculada pelo algoritmo como a média
das outras duas notas, e depois imprima as três notas de um aluno cujo nome será
informado pelo teclado na função main. Caso a turma tenha mais de um aluno com o
mesmo nome, imprima as três notas de todos eles. Utilize dois procedimentos: um para
preencher os dados dos alunos e outro para imprimir as informações solicitadas. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct Student
{
  int id;
  char firstName[20];
  float p1Grade, p2Grade, p3Grade;
};

void setStudents(struct Student students[], size_t len)
{
  for (int i = 0; i < len; i++)
  {
    if (i != 0)
      printf("\n-----------------------------------\n");
    printf("Aluno %i\n", i + 1);
    printf("Informe a matrícula:");
    scanf("%i", &students[i].id);

    printf("Informe o primeiro nome:");
    scanf(" %[^\n]s", students[i].firstName);

    printf("Informe a nota da P1:");
    scanf("%f", &students[i].p1Grade);

    printf("Informe a nota da P2:");
    scanf("%f", &students[i].p2Grade);

    students[i].p3Grade = (students[i].p1Grade + students[i].p2Grade) / 2;
  }
}

void showStudentGrades(struct Student students[], size_t len, char inputName[])
{
  int counter = 0;
  printf("\nNotas de alunos com o nome '%s':", inputName);
  for (int i = 0; i < len; i++)
    if (strcmp(students[i].firstName, inputName) == 0)
    {
      printf("\nMatrícula: %i || P1: %1.2f | P2: %1.2f | P3: %1.2f", students[i].id, students[i].p1Grade, students[i].p2Grade, students[i].p3Grade);
      counter++;
    }
  if (counter == 0)
    printf("\nNenhum aluno com o nome '%s' foi localizado.", inputName);
}

int main()
{
  struct Student students[20];
  char inputName[20];

  setStudents(students, sizeof(students) / sizeof(*students));

  printf("\n-----------------------------------\n");
  printf("\nInforme o nome do aluno a ser filtrado: ");
  scanf(" %[^\n]s", inputName);

  showStudentGrades(students, sizeof(students) / sizeof(*students), inputName);

  printf("\n\n");
  return 0;
}

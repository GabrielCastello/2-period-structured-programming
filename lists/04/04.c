/* 4) Considere uma struct que armazena os seguintes dados de um aluno: matrícula,
primeiro nome, nota da P1, nota da P2 e nota da P3. Faça um algoritmo que preencha os
dados de 30 alunos, sendo que a nota da P3 será calculada pelo algoritmo como a média
das outras duas notas. O algoritmo também tem que imprimir a quantidade de alunos
Aprovados e Reprovados, considerando a média para aprovação maior ou igual a 6,0.
Utilize dois procedimentos: um para preencher os dados dos alunos e outro para
imprimir as informações solicitadas. */

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

void calculateGradeResult(struct Student students[], size_t len, float gradePoint)
{
  int counter = 0;
  printf("\nAlunos Aprovados: ");
  for (int i = 0; i < len; i++)
    if (students[i].p3Grade >= gradePoint)
    {
      printf("\nNome: %s || Nota: %1.2f", students[i].firstName, students[i].p3Grade);
      counter++;
    }
  printf("\nTotal de alunos aprovados: %i!", counter);
  counter = 0;
  printf("\n\nAlunos Reprovados: ");
  for (int i = 0; i < len; i++)
    if (students[i].p3Grade < gradePoint)
    {
      printf("\nNome: %s || Nota: %1.2f", students[i].firstName, students[i].p3Grade);
      counter++;
    }
  printf("\nTotal de alunos reprovados: %i!", counter);
}

int main()
{
  float gradePoint = 6.0;
  struct Student students[20];

  setStudents(students, sizeof(students) / sizeof(*students));

  calculateGradeResult(students, sizeof(students) / sizeof(*students), gradePoint);

  printf("\n\n");
  return 0;
}

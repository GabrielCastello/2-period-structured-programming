/* 3) Considere uma struct que armazena as coordenadas x e y de um ponto no R2. Faça
um algoritmo que leia as coordenadas de dois pontos e imprima a distância entre eles.
Utilize um procedimento para ler as coordenadas dos pontos e uma função para
retornar (para a função main) a distância entre eles. */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

struct Coordinate
{
  double x, y;
};

double sqr(double number)
{
  return number * number;
}

double sqroot(double number)
{
  double root = number / 3;
  int i;
  if (number <= 0)
    return 0;
  for (i = 0; i < 32; i++)
    root = (root + number / root) / 2;
  return root;
}

void fillCoordinates(struct Coordinate coordinates[], size_t len)
{
  for (int i = 0; i < len; i++)
  {
    printf("Coordenada %i:\n", i + 1);
    printf("Informe valor de x: ");
    scanf("%lf", &coordinates[i].x);

    printf("Informe o valor de y: ");
    scanf("%lf", &coordinates[i].y);
  }
}

int calculateDistance(struct Coordinate coordinates[], size_t len)
{
  double xA = coordinates[0].x,
         xB = coordinates[1].x,
         yA = coordinates[0].y,
         yB = coordinates[1].y;

  return sqroot((sqr(xB - xA)) + (sqr(yB - yA)));
}

int main()
{
  struct Coordinate coordinates[2];

  fillCoordinates(coordinates, sizeof(coordinates) / sizeof(*coordinates));
  double distance = calculateDistance(coordinates, sizeof(coordinates) / sizeof(*coordinates));

  printf("\nDistancia entres os pontos (%.1lf,%.1lf), (%.1lf,%.1lf): %.1lf", coordinates[0].x, coordinates[0].y, coordinates[1].x, coordinates[1].y, distance);

  printf("\n\n");
  return 0;
}
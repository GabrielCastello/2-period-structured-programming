/* 5) Considere um arquivo chamado "Distancias.txt" que armazena (em cada linha)nome de uma cidade (sem espaços) e a distância (em km) entre a mesma e Campos dos
Goytacazes. Imagine que um usuário deseja saber quantos litros de combustível e quanto custaria abastecer tais litros para ele chegar a cada uma das cidades partindo de
Campos. Faça um algoritmo para ler (pelo teclado) o consumo do veículo do usuário
(em km/l), o valor do litro de combustível e depois gerar um arquivo chamado
"Gastos.txt" informando (em cada linha) o nome da cidade, quantos litros serão
necessários para a viagem e o valor para abastecer tais litros.
 */

// Input form User -> Km/l Liter Price
// Input from File -> City Distance
// Output to File -> City Liters Cost

#include <stdio.h>

int main()
{

  FILE *inputFile, *outputFile;

  inputFile = fopen("05Distancias.txt", "r");

  if (inputFile == NULL)
  {
    printf("\nFalha na abertura do arquivo\n\n");
    return 1;
  }

  float kilometersPerLiter, literPrice;

  printf("Informe o consumo do veículo (em km/l): ");
  scanf("%f", &kilometersPerLiter);
  printf("\nInforme o valor do litro de combustível: ");
  scanf("%f", &literPrice);

  outputFile = fopen("05Gastos.txt", "w");

  while (!feof(inputFile))
  {
    char city[100];
    float distance;
    fscanf(inputFile, "%s %f", city, &distance);

    float liters = distance / kilometersPerLiter, cost = liters * literPrice;

    fprintf(outputFile, "%s %2.2f %2.2F\n", city, liters, cost);
  }

  printf("\n\n");
  return 0;
}
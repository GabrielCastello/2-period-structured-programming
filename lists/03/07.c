/* 7) Considere um arquivo chamado "Distancias.txt" que armazena (em cada linha) o
nome de uma cidade (sem espaços) e a distância (em km) entre a mesma e Campos dos
Goytacazes. Imagine que um usuário deseja saber quantos litros de combustível e
quanto custaria abastecer tais litros para ele chegar a uma das cidades partindo de
Campos. Assim, faça um algoritmo para ler (pelo teclado) a cidade de destino, o
consumo do veículo do usuário (em km/l), o valor do litro de combustível e depois gerar
um arquivo chamado "Gastos.txt" informando o nome da cidade de destino, quantos
litros serão necessários para a viagem e o valor para abastecer tais litros.
- Obs.: Utilize a função strcmp(str1,str2) da biblioteca string.h para comparar os
nomes das cidades. Esta função retorna 0 (zero) se str1 é igual a str2.
*/

#include <stdio.h>
#include <string.h>

int main()
{

  FILE *inputFile, *outputFile;

  inputFile = fopen("07Distancias.txt", "r");

  if (inputFile == NULL)
  {
    printf("\nFalha na abertura do arquivo\n\n");
    return 1;
  }

  char inputCity[100];
  float kilometersPerLiter, literPrice;

  printf("Informe a cidade de destino: ");
  scanf("%[^\n]s", &inputCity);

  printf("Informe o consumo do veículo (em km/l): ");
  scanf("%f", &kilometersPerLiter);
  printf("\nInforme o valor do litro de combustível: ");
  scanf("%f", &literPrice);

  outputFile = fopen("07Gastos.txt", "w");

  int cityisValid = 0;
  while (!feof(inputFile))
  {
    char city[100];
    float distance;
    fscanf(inputFile, "%s %f", city, &distance);
    if (strcmp(inputCity, city) == 0)
    {
      cityisValid = 1;
      float liters = distance / kilometersPerLiter, cost = liters * literPrice;
      fprintf(outputFile, "%s %2.1fLitros R$%2.2F\n", city, liters, cost);
    }
  }

  if (cityisValid == 0)
  {
    printf("\nNão foi possível localizar a cidade informada.");
  };

  printf("\n\n");
  return 0;
}
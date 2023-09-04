#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define PRICE_PER_KM_ABOVE_LIMIT 5

int calculateSpeedAboveLimit(int maxRoadSpeed, int driverSpeed)
{
  return driverSpeed - maxRoadSpeed;
}

float calculateTicketValue(int maxRoadSpeed, int driverSpeed)
{
  int speedDifference = calculateSpeedAboveLimit(maxRoadSpeed, driverSpeed);
  float totalTicketValue = 0;
  if (speedDifference > 0)
  {
    totalTicketValue = speedDifference * PRICE_PER_KM_ABOVE_LIMIT;
  }
  return totalTicketValue;
}

void printResult(float totalTicketValue)
{
  if (totalTicketValue > 0)
  {
    printf("O valor total que deve ser pago é de: R$ %.2f\n", totalTicketValue);
  }
  else
  {
    printf("O motorista estava dentro do limite de velocidade\n");
  }
}

int main()
{
  int maxRoadSpeed, driverSpeed;
  float totalTicketValue;
  setlocale(LC_ALL, "Portuguese");

  printf("Digite a velocidade máxima da via: \n");
  scanf("%i", &maxRoadSpeed);
  printf("Digite a velocidade do motorista: \n");
  scanf("%i", &driverSpeed);

  totalTicketValue = calculateTicketValue(maxRoadSpeed, driverSpeed);
  printResult(totalTicketValue);
}
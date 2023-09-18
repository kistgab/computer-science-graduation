#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>

#define NUMBER_TO_STOP_LOOP 0
#define START_NUMBER_FIRST_INTERVAL 10
#define END_NUMBER_FIRST_INTERVAL 20
#define START_NUMBER_SECOND_INTERVAL 1
#define END_NUMBER_SECOND_INTERVAL 10

void printResults(int totalSumBetweenFirstInterval, float averageSecondInterval, int lowestInputedValue)
{
  printf("Soma total do intervalo 10(inc) a 20(inc): %i \n", totalSumBetweenFirstInterval);
  printf("Média do intervalo de 1(inc) a 10 (exc): %.2f \n", averageSecondInterval);
  printf("Valor mais baixo: %i \n", lowestInputedValue);
}

void readUserInput(int *inputtedNumber)
{
  printf("Caso deseje parar digite 0 \n");
  printf("Digite um número inteiro: \n");
  scanf("%i", inputtedNumber);
}

int main()
{
  int userInputNumber, totalSumBetweenFirstInterval = 0, totalSumBetweenSecondInterval = 0, totalNumbersBetweenSecondInterval = 0, lowestInputedValue = INT_MAX;
  float averageSecondInterval;
  setlocale(LC_ALL, "Portuguese");

  readUserInput(&userInputNumber);
  while (userInputNumber != NUMBER_TO_STOP_LOOP)
  {
    if (userInputNumber < lowestInputedValue)
    {
      lowestInputedValue = userInputNumber;
    }
    if (userInputNumber >= START_NUMBER_FIRST_INTERVAL &&
        userInputNumber <= END_NUMBER_FIRST_INTERVAL)
    {
      totalSumBetweenFirstInterval += userInputNumber;
      totalNumbersBetweenSecondInterval++;
    }
    else if (userInputNumber >= START_NUMBER_SECOND_INTERVAL && userInputNumber < END_NUMBER_SECOND_INTERVAL)
    {
      totalSumBetweenFirstInterval += userInputNumber;
    }
    readUserInput(&userInputNumber);
  }
  averageSecondInterval = totalSumBetweenSecondInterval / totalNumbersBetweenSecondInterval;

  printResults(totalSumBetweenFirstInterval, averageSecondInterval, lowestInputedValue);
}

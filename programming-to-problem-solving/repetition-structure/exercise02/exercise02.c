#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <limits.h>

#define MAXIMUM_NUMBER_TO_SUM 100

void printResults(int totalSum)
{
  printf("A soma final de valores menores que %i foi de: %i \n", MAXIMUM_NUMBER_TO_SUM, totalSum);
}

void readUserInput(int *inputtedNumber)
{
  printf("Caso deseje parar digite um número negativo \n");
  printf("Digite um número inteiro: \n");
  scanf("%i", inputtedNumber);
}

int main()
{
  int userInputNumber, sumOfValuesAboveThanMaximumNumberToSum;
  setlocale(LC_ALL, "Portuguese");

  readUserInput(&userInputNumber);
  while (userInputNumber >= 0)
  {
    if (userInputNumber < MAXIMUM_NUMBER_TO_SUM)
    {
      sumOfValuesAboveThanMaximumNumberToSum += userInputNumber;
    }
    printf("A soma atual dos valores menores que %i é de: %i \n", MAXIMUM_NUMBER_TO_SUM, sumOfValuesAboveThanMaximumNumberToSum);
    readUserInput(&userInputNumber);
  }
  printResults(sumOfValuesAboveThanMaximumNumberToSum);
}

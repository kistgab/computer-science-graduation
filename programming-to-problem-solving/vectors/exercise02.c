// Faça um programa que preencha um vetor com 20 valores
// inteiros, calcule e mostre a soma dos elementos pares.
#include <stdio.h>
#include <time.h>

int isOddNumber(int number)
{
  if (number % 2 == 0)
  {
    return 1;
  }
  return 0;
}

int main()
{
  const int QUANTITY_OF_INPUTS = 10;
  int integerNumbers[QUANTITY_OF_INPUTS], highestValue = 0, lowestValue = __INT_MAX__, sumOfAllValues = 0, quantityOfValuesHigherThanTheAverageValue = 0;
  float averageValue = 0;

  printf("Digite %i valores: \n", QUANTITY_OF_INPUTS);
  for (int i = 0; i < QUANTITY_OF_INPUTS; i++)
  {
    printf("Posicao %i: \n", i);
    scanf("%i", &integerNumbers[i]);
    sumOfAllValues += integerNumbers[i];
    if (integerNumbers[i] < lowestValue)
    {
      lowestValue = integerNumbers[i];
    }
    else if (integerNumbers[i] > highestValue)
    {
      highestValue = integerNumbers[i];
    }
  }
  averageValue = (highestValue + lowestValue) / 2;

  for (int i = 0; i < QUANTITY_OF_INPUTS; i++)
  {
    if (integerNumbers[i] > averageValue)
    {
      quantityOfValuesHigherThanTheAverageValue++;
    }
  }

  printf("Maior valor digitado: %i\n", highestValue);
  printf("Menor valor digitado: %i\n", lowestValue);
  printf("Quantidade de valores maiores do que a média do maior e menor: %i\n", quantityOfValuesHigherThanTheAverageValue);
}
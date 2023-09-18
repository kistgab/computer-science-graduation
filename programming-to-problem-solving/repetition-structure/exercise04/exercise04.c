#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#define NUMBER_TO_STOP_LOOP 0

void printResults(float averageSecondInterval)
{
  printf("Média dos valores pares: %.2f \n", averageSecondInterval);
}

void readUserInput(int *inputtedNumber)
{
  printf("Caso deseje parar digite 0 \n");
  printf("Digite um número inteiro: \n");
  scanf("%i", inputtedNumber);
}

bool isOddNumber(int number)
{
  return number % 2 == 0;
}

int main()
{
  int userInputNumber, totalSumOfOddNumbers = 0, quantityOddNumbers = 0;
  float averageOfOddNumbers;
  setlocale(LC_ALL, "Portuguese");

  readUserInput(&userInputNumber);
  while (userInputNumber != NUMBER_TO_STOP_LOOP)
  {
    if (isOddNumber(userInputNumber))
    {
      quantityOddNumbers++;
      totalSumOfOddNumbers += userInputNumber;
    }
    readUserInput(&userInputNumber);
  }
  averageOfOddNumbers = totalSumOfOddNumbers / quantityOddNumbers;

  printResults(averageOfOddNumbers);
}

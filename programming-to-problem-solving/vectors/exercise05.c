// 5 – Dado um vetor V de 100 elementos inteiros faça um
// programa que crie outro vetor W contendo os valores de V que
// pertençam ao intervalo [10, 40], ou seja, 10 (inclusive) a 40
// (inclusive).

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isNumberInTheInterval(int number, int firstIntervalNumber, int lastIntervalNumber)
{
  if (number >= firstIntervalNumber && number <= lastIntervalNumber)
  {
    return 1;
  }
  return 0;
}

int main()
{
  const int FIRST_INTERVAL_VALUE_TO_COPY = 10;
  const int LAST_INTERVAL_VALUE_TO_COPY = 40;
  const int ARRAY_SIZE = 100;
  int quantityOfNumbersInTheInterval = 0;
  int numbersArray[ARRAY_SIZE];
  int arrayWithNumbersInTheInterval[ARRAY_SIZE];

  srand(time(NULL));
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    numbersArray[i] = rand() % 101;
  }

  quantityOfNumbersInTheInterval = 0; // Inicialize aqui

  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    if (isNumberInTheInterval(numbersArray[i], FIRST_INTERVAL_VALUE_TO_COPY, LAST_INTERVAL_VALUE_TO_COPY))
    {
      arrayWithNumbersInTheInterval[quantityOfNumbersInTheInterval] = numbersArray[i];
      quantityOfNumbersInTheInterval++;
    }
  }

  printf("Array gerado:\n");
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    printf("%i | ", numbersArray[i]);
  }

  printf("\nArray com números entre %i e %i:\n", FIRST_INTERVAL_VALUE_TO_COPY, LAST_INTERVAL_VALUE_TO_COPY);
  for (int i = 0; i < quantityOfNumbersInTheInterval; i++)
  {
    printf("%i | ", arrayWithNumbersInTheInterval[i]);
  }
}
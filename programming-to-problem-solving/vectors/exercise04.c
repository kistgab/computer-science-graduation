// 4 – Faça um programa que preencha um vetor com 10 elementos
// reais e inverta a posição destes elementos, de tal modo que o
// primeiro elemento venha a ser o último depois da inversão.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(float array[], int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    printf("%f | ", array[i]);
  }
}

int main()
{
  const int ARRAY_SIZE = 10;
  const float MAX_GENERATED_FLOAT_NUMBER = 100.0;
  const float MIN_GENERATED_FLOAT_NUMBER = 0.0;
  float numbersArray[ARRAY_SIZE], invertedNumbersArray[ARRAY_SIZE];

  srand(time(NULL));
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    float randomFloat = MIN_GENERATED_FLOAT_NUMBER + ((float)rand() / RAND_MAX) * (MAX_GENERATED_FLOAT_NUMBER - MIN_GENERATED_FLOAT_NUMBER);
    numbersArray[i] = randomFloat;
  }
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    invertedNumbersArray[i] = numbersArray[ARRAY_SIZE - 1 - i];
  }

  printf("\nArray inicial: ");
  printArray(numbersArray, ARRAY_SIZE);
  printf("\nArray final: ");
  printArray(invertedNumbersArray, ARRAY_SIZE);
}
// 6 – Faça um programa que leia um vetor de 15 posições de
// números reais e divida os seus elementos pela média dos
// elementos do vetor. Altere o próprio vetor e mostre-os após os
// cálculos

#include <stdlib.h>

void printArray(float array[], int arraySize)
{
  for (int i = 0; i < arraySize; i++)
  {
    printf("%.2f ", array[i]);
  }
}

int main()
{
  const int ARRAY_SIZE = 5;
  float numbersArray[ARRAY_SIZE];
  float sum = 0;

  printf("Digite %i numeros reais:\n", ARRAY_SIZE);
  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    scanf("%f", &numbersArray[i]);
    sum += numbersArray[i];
  }
  float average = sum / ARRAY_SIZE;

  for (int i = 0; i < ARRAY_SIZE; i++)
  {
    numbersArray[i] /= average;
  }

  printf("Vetor após os cálculos:\n");
  printArray(numbersArray, ARRAY_SIZE);
}

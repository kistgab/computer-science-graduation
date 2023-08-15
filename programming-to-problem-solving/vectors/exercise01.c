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
  int integerNumbers[5], sumOfOddNumbers = 0;
  int arrayLength = sizeof(integerNumbers) / sizeof(integerNumbers[1]);

  srand(time(NULL));
  printf("Vetor: ");
  for (int i = 0; i < arrayLength; i++)
  {
    integerNumbers[i] = rand() % 100;
    if (isOddNumber(integerNumbers[i]))
    {
      sumOfOddNumbers += integerNumbers[i];
    }
    printf("%i,", integerNumbers[i]);
  }
  printf("\nA soma de todos os elementos pares é de: %i", sumOfOddNumbers);
}
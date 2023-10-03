#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <limits.h>

#define MATRIX_ORDER_LINES 2
#define MATRIX_ORDER_COLUMNS 4

void countAndPrintMatixValuesInIntervalPerLine(int matrix[][MATRIX_ORDER_COLUMNS], int intervalStart, int intervalEnd)
{
  for (int i = 0; i < MATRIX_ORDER_LINES; i++)
  {
    int totalElementsInInterval = 0;
    for (int j = 0; j < MATRIX_ORDER_COLUMNS; j++)
    {
      if (matrix[i][j] > intervalStart && matrix[i][j] < intervalEnd)
      {
        totalElementsInInterval++;
      }
    }
    printf("Linha: %i", i);
    printf("O total de elementos no intervalo de %i a %i é de: %i \n", intervalStart, intervalEnd, totalElementsInInterval);
  }
}

int sumAllEvenNumbersInMatrix(int matrix[][MATRIX_ORDER_COLUMNS])
{
  int evenNumbersSum = 0;
  for (int i = 0; i < MATRIX_ORDER_LINES; i++)
  {
    for (int j = 0; j < MATRIX_ORDER_COLUMNS; j++)
    {
      if (matrix[i][j] % 2 == 0)
      {
        evenNumbersSum += matrix[i][j];
      }
    }
  }
  return evenNumbersSum;
}

int main()
{
  int matrix[MATRIX_ORDER_LINES][MATRIX_ORDER_COLUMNS], evenNumbersSum;
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));

  for (int i = 0; i < MATRIX_ORDER_LINES; i++)
  {
    for (int j = 0; j < MATRIX_ORDER_COLUMNS; j++)
    {
      matrix[i][j] = rand() % 30 + 1;
      printf("%d\t", matrix[i][j]);
    }
    printf("\n");
  }
  countAndPrintMatixValuesInIntervalPerLine(matrix, 12, 20);
  evenNumbersSum = sumAllEvenNumbersInMatrix(matrix);
  printf("A soma de todos os números pares é: %i", evenNumbersSum);
}
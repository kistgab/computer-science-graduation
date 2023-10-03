#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <limits.h>

#define MATRIX_ORDER 2

int getHighestMatrixValue(int matrix[MATRIX_ORDER][MATRIX_ORDER])
{
  int highestValue = INT_MIN;
  for (int i = 0; i < MATRIX_ORDER; i++)
  {
    for (int j = 0; j < MATRIX_ORDER; j++)
    {
      if (matrix[i][j] > highestValue)
      {
        highestValue = matrix[i][j];
      }
    }
  }
  return highestValue;
}

void calculateAndPrintMatixMultipliedForItsHigherValue(int matrix[MATRIX_ORDER][MATRIX_ORDER])
{
  int highestValue = getHighestMatrixValue(matrix);
  for (int i = 0; i < MATRIX_ORDER; i++)
  {
    for (int j = 0; j < MATRIX_ORDER; j++)
    {
      printf("%.2f\t", (float)matrix[i][j] * highestValue);
    }
    printf("\n");
  }
}

int main()
{
  int matrix[MATRIX_ORDER][MATRIX_ORDER];
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));

  for (int i = 0; i < MATRIX_ORDER; i++)
  {
    for (int j = 0; j < MATRIX_ORDER; j++)
    {
      matrix[i][j] = rand() % 10 + 1;
      printf("%d\t", matrix[i][j]);
    }
    printf("\n");
  }
  calculateAndPrintMatixMultipliedForItsHigherValue(matrix);
}
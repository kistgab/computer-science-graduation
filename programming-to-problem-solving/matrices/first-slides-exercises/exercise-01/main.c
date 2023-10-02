#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define MATRIX_ORDER 5

float calculteSumOfSecondaryDiagonal(float matrix[MATRIX_ORDER][MATRIX_ORDER])
{
  float secondaryDiagonalSum = 0;
  for (int i = 0; i < MATRIX_ORDER; i++)
  {
    for (int j = 0; j < MATRIX_ORDER; j++)
    {
      if (i + j == MATRIX_ORDER - 1)
      {
        secondaryDiagonalSum += matrix[i][j];
      }
    }
  }
  return secondaryDiagonalSum;
}

int main()
{
  float matrix[MATRIX_ORDER][MATRIX_ORDER];
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));

  for (int i = 0; i < MATRIX_ORDER; i++)
  {
    for (int j = 0; j < MATRIX_ORDER; j++)
    {
      matrix[i][j] = 10 + ((float)rand() / RAND_MAX) * (100 - 10);
      printf("%.2f\t", matrix[i][j]);
    }
    printf("\n");
  }

  float secondaryDiagonalSum = calculteSumOfSecondaryDiagonal(matrix);

  printf("A soma da diagonal secundaria é : %.2f", secondaryDiagonalSum);
}
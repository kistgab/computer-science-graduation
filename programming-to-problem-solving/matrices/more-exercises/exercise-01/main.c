#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#define ROW_QUANTITY 4
#define COLUMN_QUANTITY 7
#define HIGHEST_RANDOM_NUMBER 200

int main()
{
  float matrix[ROW_QUANTITY][COLUMN_QUANTITY];
  float lowestValue = __FLT_MAX__;
  float highestValueInLine = __FLT_MIN__;
  int lineWithLowestValue = 0;
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));
  for (int i = 0; i < ROW_QUANTITY; i++)
  {
    for (int j = 0; j < COLUMN_QUANTITY; j++)
    {
      matrix[i][j] = (float)rand() / RAND_MAX * (HIGHEST_RANDOM_NUMBER);
      printf("%.2f    |", matrix[i][j]);
      if (matrix[i][j] < lowestValue)
      {
        lineWithLowestValue = i;
        lowestValue = matrix[i][j];
      }
    }
    printf("\n");
  }

  for (int j = 0; j < COLUMN_QUANTITY; j++)
  {
    if (matrix[lineWithLowestValue][j] > highestValueInLine)
    {
      highestValueInLine = matrix[lineWithLowestValue][j];
    }
  }

  printf("Min: %.2f  - Max: %.2f", lowestValue, highestValueInLine);
}
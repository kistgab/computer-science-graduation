#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#define ROW_QUANTITY 4
#define COLUMN_QUANTITY 4

void fillMatrix(int matrix[][COLUMN_QUANTITY])
{
  for (int i = 0; i < ROW_QUANTITY; i++)
  {
    for (int j = 0; j < COLUMN_QUANTITY; j++)
    {
      matrix[i][j] = (int)rand() % 100;
    }
  }
}

void printMatrix(int matrix[][COLUMN_QUANTITY])
{
  printf("\n------------------------MATRIZ------------------------\n");
  for (int i = 0; i < ROW_QUANTITY; i++)
  {
    for (int j = 0; j < COLUMN_QUANTITY; j++)
    {
      printf("%d    ", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n------------------------------------------------------\n");
}

int getFirstLineSum(int matrix[][COLUMN_QUANTITY])
{
  int firstLineSum = 0;
  for (int j = 0; j < COLUMN_QUANTITY; j++)
  {
    firstLineSum += matrix[0][j];
  }
  return firstLineSum;
}

bool doesAllLinesHaveSameSum(int matrix[][COLUMN_QUANTITY])
{
  int firstLineSum = getFirstLineSum(matrix);
  for (int i = 0; i < ROW_QUANTITY; i++)
  {
    int currentLineSum = 0;
    for (int j = 0; j < COLUMN_QUANTITY; j++)
    {
      currentLineSum += matrix[i][j];
    }
    if (currentLineSum != firstLineSum)
    {
      return false;
    }
  }
  return true;
}

bool doesAllColumnsHaveSameSum(int matrix[][COLUMN_QUANTITY])
{
  int firstLineSum = getFirstLineSum(matrix);
  for (int j = 0; j < ROW_QUANTITY; j++)
  {
    int currentColumnSum = 0;
    for (int i = 0; i < COLUMN_QUANTITY; i++)
    {
      currentColumnSum += matrix[i][j];
    }
    if (currentColumnSum != firstLineSum)
    {
      return false;
    }
  }
  return true;
}

bool doesMainDiagonalHaveSameSum(int matrix[][COLUMN_QUANTITY])
{
  int mainDiagonalSum = 0;
  for (int i = 0; i < ROW_QUANTITY; i++)
  {
    for (int j = 0; j < COLUMN_QUANTITY; j++)
    {
      if (i == j)
      {
        mainDiagonalSum += matrix[i][j];
      }
    }
  }
  bool hasSameSumOfLines = mainDiagonalSum == getFirstLineSum(matrix);
  return hasSameSumOfLines;
}

bool doesSecondaryDiagonalHaveSameSum(int matrix[][COLUMN_QUANTITY])
{
  int secondaryDiagonalSum = 0;
  for (int i = 0; i < ROW_QUANTITY; i++)
  {
    for (int j = 0; j < COLUMN_QUANTITY; j++)
    {
      bool isIndexOfSecondaryDiagonal = (i + j) == (COLUMN_QUANTITY - 1);
      if (i == j)
      {
        secondaryDiagonalSum += matrix[i][j];
      }
    }
  }
  bool hasSameSumOfLines = secondaryDiagonalSum == getFirstLineSum(matrix);
  return hasSameSumOfLines;
}

bool isMagicSquare(int matrix[][COLUMN_QUANTITY])
{
  bool linesHaveSameSum = doesAllLinesHaveSameSum(matrix);
  bool columnsHaveSameSum = doesAllColumnsHaveSameSum(matrix);
  bool mainDiagonalHaveSameSum = doesMainDiagonalHaveSameSum(matrix);
  bool secondaryDiagonalHaveSameSum = doesSecondaryDiagonalHaveSameSum(matrix);
  bool isMagicSquare = linesHaveSameSum && columnsHaveSameSum && mainDiagonalHaveSameSum && secondaryDiagonalHaveSameSum;
  return isMagicSquare;
}

void printIfIsMagicSquare(int matrix[][COLUMN_QUANTITY])
{
  if (isMagicSquare(matrix))
  {
    printf("É um quadrado mágico\n");
    return;
  };
  printf("Não é um quadrado mágico\n");
}

int main()
{
  int randomMatrix[ROW_QUANTITY][COLUMN_QUANTITY];

  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));

  printf("\n\n\n******* MATRIZ QUADRADA RANDÔMICA *******\n");
  fillMatrix(randomMatrix);
  printMatrix(randomMatrix);
  printIfIsMagicSquare(randomMatrix);

  int magicSquare[ROW_QUANTITY][COLUMN_QUANTITY] = {
      {16, 2, 3, 13},
      {5, 11, 10, 8},
      {9, 7, 6, 12},
      {4, 14, 15, 1}};
  printf("\n\n\n******* MATRIZ QUADRADO MÁGICO *******\n");
  printMatrix(magicSquare);
  printIfIsMagicSquare(magicSquare);
}
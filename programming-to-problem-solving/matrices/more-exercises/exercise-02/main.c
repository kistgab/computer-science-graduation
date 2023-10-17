#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#define ROW_QUANTITY 5
#define COLUMN_QUANTITY 7

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
      printf("%d    |", matrix[i][j]);
    }
    printf("\n");
  }
  printf("\n------------------------------------------------------\n");
}

bool isLowestValueInRow(int matrix[][COLUMN_QUANTITY], int row, int currentColumn)
{
  int valueToCheck = matrix[row][currentColumn];
  for (int j = 0; j < COLUMN_QUANTITY; j++)
  {
    if (valueToCheck > matrix[row][j])
    {
      return false;
    }
  }
  return true;
}

bool isHighestValueInColumn(int matrix[][COLUMN_QUANTITY], int column, int currentRow)
{
  int valueToCheck = matrix[currentRow][column];
  for (int i = 0; i < ROW_QUANTITY; i++)
  {
    if (valueToCheck < matrix[i][column])
    {
      return false;
    }
  }
  return true;
}

typedef struct saddlePointLocation
{
  int row;
  int column;
} saddlePointLocation;

void printsaddlePointAndLocation(int matrix[][COLUMN_QUANTITY])
{
  bool hasThesaddlePoint = false;
  int saddlePointValue = NULL;
  saddlePointLocation saddlePointLocation;
  saddlePointLocation.column = NULL;
  saddlePointLocation.row = NULL;
  for (int i = 0; i < ROW_QUANTITY; i++)
  {
    for (int j = 0; j < COLUMN_QUANTITY; j++)
    {
      bool isLowestInTheRow = isLowestValueInRow(matrix, i, j);
      bool isHighestInTheColumn = isHighestValueInColumn(matrix, j, i);
      hasThesaddlePoint = isHighestInTheColumn && isLowestInTheRow;
      if (hasThesaddlePoint)
      {
        saddlePointValue = matrix[i][j];
        saddlePointLocation.row = i;
        saddlePointLocation.column = j;
        break;
      }
    }
    if (hasThesaddlePoint)
    {
      break;
    }
  }
  if (!hasThesaddlePoint)
  {
    printf("O ponto de sela da matriz não existe!\n");
    return;
  }
  printf("O ponto de sela da matriz esta localizado na linha %d e na coluna %d com o valor %d \n", saddlePointLocation.row, saddlePointLocation.column, saddlePointValue);
}

int main()
{
  int matrix[ROW_QUANTITY][COLUMN_QUANTITY];
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));

  fillMatrix(matrix);
  printMatrix(matrix);
  printsaddlePointAndLocation(matrix);
}
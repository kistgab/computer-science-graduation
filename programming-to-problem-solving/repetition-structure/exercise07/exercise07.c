#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>

#define START_HEIGHT_INTERVAL 1.6
#define END_HEIGHT_INTERVAL 1.75

#include <stdio.h>

void printResults(int quantityOfStudents, double averageHeight, int quantityOfStudentsBetweenInterval)
{
  if (quantityOfStudents > 0)
  {
    printf("Média das alturas: %.2lf metros\n", averageHeight);
    printf("Quantidade de alunos com altura entre %.2fm e %.2fm: %d\n", START_HEIGHT_INTERVAL, END_HEIGHT_INTERVAL, quantityOfStudentsBetweenInterval);
  }
  else
  {
    printf("Nenhum dado de altura foi inserido.\n");
  }
}

void readStudentHeight(float *studentHeight)
{
  printf("Digite a altura do aluno (em metros) ou digite 0 para encerrar:\n");
  scanf("%f", studentHeight);
}

bool isHeightInInterval(float height)
{
  return height > START_HEIGHT_INTERVAL && height < END_HEIGHT_INTERVAL;
}

int main()
{
  int quantityOfStudents = 0;
  float studentHeight, heightsSum = 0;
  int quantityOfStudentsBetweenInterval = 0;
  readStudentHeight(&studentHeight);
  while (studentHeight != 0)
  {
    quantityOfStudents++;
    heightsSum += studentHeight;
    if (isHeightInInterval(studentHeight))
    {
      quantityOfStudentsBetweenInterval++;
    }
    readStudentHeight(&studentHeight);
  }
  double averageHeight = heightsSum / quantityOfStudents;
  printResults(quantityOfStudents, averageHeight, quantityOfStudentsBetweenInterval);
}

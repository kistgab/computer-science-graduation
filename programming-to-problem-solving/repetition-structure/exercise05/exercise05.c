#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>

#define NUMBER_TO_STOP_LOOP 0

void printMultiplicationTable(int numberToCalculate)
{
  printf("Taboada do %i \n", numberToCalculate);
  for (int i = 1; i <= 10; i++)
  {
    int multiplicationResult = numberToCalculate * i;
    printf("%i x %i = %i \n", numberToCalculate, i, multiplicationResult);
  }
}

void readUserInput(int *inputtedNumber)
{
  printf("Digite um número inteiro para calcular a taboada: \n");
  scanf("%i", inputtedNumber);
}

void readIfHasToContinue(char *charVariable)
{
  printf("Caso deseje parar digite 'N', para continuar 'S' \n");
  scanf("%s", charVariable);
}

int main()
{
  int userInputNumber;
  char continueMultiplicationTable;
  setlocale(LC_ALL, "Portuguese");

  do
  {
    readUserInput(&userInputNumber);
    printMultiplicationTable(userInputNumber);
    readIfHasToContinue(&continueMultiplicationTable);
  } while (toupper(continueMultiplicationTable) == toupper('S'));
}

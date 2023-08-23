#include <stdio.h>
#include <stdlib.h>

#define SUM_CODE 1
#define SUBTRACTION_CODE 2
#define DIVISION_CODE 3
#define MULTIPLICATION_CODE 4

void printCalculatorMenu()
{
  printf("-----------------------------\n");
  printf("Menu:\n");
  printf("Cód. Nome \n");
  printf("%i  Soma\n", SUM_CODE);
  printf("%i  Subtração\n", SUBTRACTION_CODE);
  printf("%i  Divisão\n", DIVISION_CODE);
  printf("%i  Multiplicação\n", MULTIPLICATION_CODE);
  printf("----------------------------- \n");
}

double calculateOperation(int selectedOperationCode, float firstValue, float secondValue)
{
  switch (selectedOperationCode)
  {
  case SUM_CODE:
    return firstValue + secondValue;
    break;
  case SUBTRACTION_CODE:
    return firstValue - secondValue;
    break;
  case DIVISION_CODE:
    return firstValue / secondValue;
    break;
  case MULTIPLICATION_CODE:
    return firstValue * secondValue;
    break;
  default:
    return 0;
    break;
  }
}

int main()
{
  int selectedOperationCode;
  double firstValue, secondValue;
  printCalculatorMenu();
  printf("Digite o codigo da operação que deseja: \n");
  scanf("%i", &selectedOperationCode);
  printf("Digite o primeiro valor:\n");
  scanf("%lf", &firstValue);
  printf("Digite o segundo valor:\n");
  scanf("%lf", &secondValue);

  double operationResult = calculateOperation(selectedOperationCode, firstValue, secondValue);
  printf("O resultado é: %.2lf", operationResult);
}
// In the last math class, Rafael, Beto and Carlos learned some new math functions. Each one of them liked one particular function, and they decided to compete to see which function had the higher outcome.

// The function that Rafael chose is r(x, y) = (3x)² + y².

// Beto chose the function b(x, y) = 2(x²) + (5y)².

// Carlos, however, chose the function c(x, y) = -100x + y³.

// Given the values of x and y, say who chose the function with higher outcome.

// Input
// The first line of input contains an integer N that determines the number of test cases. Each test case consists of two integers x and y (1 ≤ x, y ≤ 100), indicating the variables to input in the function.

// Output
// For each test case print one line, containing one sentence, indicating who won the contest. For example, if Rafael wins the contest, print “Rafael ganhou”. Assume that there will be no ties.

#include <stdio.h>
#include <math.h>

float getRafaelsFunctionResult(int x, int y)
{
  float functionResult = pow((3 * x), 2) + pow(y, 2);
  return functionResult;
}

float getBetosFunctionResult(int x, int y)
{
  float functionResult = 2 * pow(x, 2) + pow(5 * y, 2);
  return functionResult;
}

float getCarlosFunctionResult(int x, int y)
{
  float functionResult = (-100 * x) + pow(y, 3);
  return functionResult;
}

void printWinner(int x, int y)
{
  const float carlosResult = getCarlosFunctionResult(x, y);
  const float rafaelResult = getRafaelsFunctionResult(x, y);
  const float betoResult = getBetosFunctionResult(x, y);

  if (carlosResult > rafaelResult && carlosResult > betoResult)
  {
    printf("Carlos ganhou\n");
  }
  else if (rafaelResult > carlosResult && rafaelResult > betoResult)
  {
    printf("Rafael ganhou\n");
  }
  else if (betoResult > carlosResult && betoResult > rafaelResult)
  {
    printf("Beto ganhou\n");
  }
  else
  {
    printf("Empate");
  }
}

int main()
{
  int quantityTestCases;
  int userInputX = 0, userInputY = 0;

  // printf("Digite o número de casos de testes\n");
  scanf("%i", &quantityTestCases);

  if (quantityTestCases <= 0)
  {
    // printf("Valor inválido, aplicação finalizando...\n");
    return 0;
  }

  for (int i = 0; i < quantityTestCases; i++)
  {
    // printf("Digite o valor de X:\n");

    scanf("%i", &userInputX);
    // printf("Digite o valor de Y:\n");

    scanf("%i", &userInputY);
    printWinner(userInputX, userInputY);
  }
}
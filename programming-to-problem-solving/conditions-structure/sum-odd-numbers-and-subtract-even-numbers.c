// 3. Escreva um programa que leia dois números inteiros e apresente a sua soma se ambos forem pares, e o seu produto se um ou ambos forem ímpares.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

bool isOddNumber(int number)
{
  bool isOdd = number % 2 == 0;
  return isOdd;
}

int calculate(int firstNumber, int secondNumber)
{
  bool isFirstNumberOdd = isOddNumber(firstNumber);
  bool isSecondNumberOdd = isOddNumber(secondNumber);
  if (isFirstNumberOdd && isSecondNumberOdd)
  {
    return firstNumber + secondNumber;
  }
  if (!isFirstNumberOdd && !isSecondNumberOdd)
  {
    return firstNumber - secondNumber;
  }
  printf("Os números não se encaixam nas condições!\n");
  printf("Eles devem ser ambos apenas pares ou ambos apenas ímpares\n");
  exit(0);
}

int main()
{
  int inputFirstNumber, inputSecondNumber, calulationResult;
  setlocale(LC_ALL, "Portuguese");
  printf("Digite um número: \n");
  scanf("%i", &inputFirstNumber);
  scanf("%i", &inputSecondNumber);
  calulationResult = calculate(inputFirstNumber, inputSecondNumber);

  printf("O resultado da operação é: %i", calulationResult);
}
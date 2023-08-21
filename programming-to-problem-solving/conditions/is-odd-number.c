// 2. Escreva um programa que determine se um número, fornecido pelo usuário é par ou ímpar.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

bool isOddNumber(int number)
{
  bool isOdd = number % 2 == 0;
  return isOdd;
}
int main()
{
  int inputNumber;

  setlocale(LC_ALL, "Portuguese");
  printf("Digite um número: \n");
  scanf("%i", &inputNumber);
  if (isOddNumber(inputNumber))
  {
    printf("É par\n");
  }
  else
  {
    printf("É ímpar\n");
  }
}
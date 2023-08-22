// 1. Ler um valor e escrever se é positivo, negativo ou zero.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void printNumberStatus(int number)
{
  if (number > 0)
  {
    printf("Positivo!");
  }
  else if (number < 0)
  {
    printf("Negativo!");
  }
  else
  {
    printf("Zero!");
  }
}

int main()
{
  int number;

  setlocale(LC_ALL, "Portuguese");
  printf("Digite um número para ver se ele é positivo, negativo ou zero:\n");
  scanf("%i", &number);
  printNumberStatus(number);
}
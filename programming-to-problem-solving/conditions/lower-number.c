// 1. Ler dois números inteiros e determinar o maior e o menor deles.

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int firstNumber, secondNumber;
  printf("Escreva o primeiro número:\n");
  scanf("%i", &firstNumber);
  printf("Escreva o segundo número:\n");
  scanf("%i", &secondNumber);

  if (firstNumber > secondNumber)
  {
    printf("O primeiro é o maior número\n");
  }
  else if (secondNumber > firstNumber)
  {
    printf("O segundo é o maior número\n");
  }
  else
  {
    printf("Os dois números são iguais\n");
  }
}
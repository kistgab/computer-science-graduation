// 3 – Crie um programa para ler 30 números reais e armazene-os
// em um vetor. Em seguida mostre apenas os valores das posições
// pares do vetor

#include <stdio.h>
#include <time.h>

int isOddNumber(int number)
{
  if (number == 0)
  {
    return 0;
  }
  if (number % 2 == 0)
  {
    return 1;
  }
  return 0;
}

int main()
{
  const int QUANTITY_OF_INPUTS = 5;
  float numbersArray[QUANTITY_OF_INPUTS];

  printf("Digite %i valores reais: \n", QUANTITY_OF_INPUTS);
  for (int i = 0; i < QUANTITY_OF_INPUTS; i++)
  {
    printf("Posicao %i: \n", i);
    scanf("%f", &numbersArray[i]);
  }
  for (int i = 0; i < QUANTITY_OF_INPUTS; i++)
  {
    if (isOddNumber(i))
    {
      printf("Valor da posição %i: %.2f\n", i, numbersArray[i]);
    }
  }
}
// 2. Faça um programa que receba quatro notas, calcule e mostre a média aritmética das notas e a
// mensagem de aprovado ou reprovado, considerando para aprovação média 7.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define QUANTITY_OF_GRADES 4

int main()
{
  int sumOfGrades, grade;
  float averageGrade;

  setlocale(LC_ALL, "Portuguese");
  for (int i = 0; i < QUANTITY_OF_GRADES; i++)
  {
    printf("Digite a %i° nota:\n", i + 1);
    scanf("%i", &grade);
    sumOfGrades += grade;
  }
  averageGrade = sumOfGrades / (float)QUANTITY_OF_GRADES;
  printf("Média final: %.2f \n", averageGrade);
  if (averageGrade >= 7)
  {
    printf("Aprovado!");
  }
  else
  {
    printf("Reprovado");
  }
}
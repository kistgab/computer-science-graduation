#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define BONUS_MULTIPLIER_BETWEEN_40_AND_60_HOURS 0.5
#define BONUS_MULTIPLIER_MORE_THAN_60_HOURS 1

float calculateBonusHours(int workedHours)
{
  if (workedHours >= 40)
  {
    return workedHours * BONUS_MULTIPLIER_BETWEEN_40_AND_60_HOURS;
  }
  if (workedHours > 60)
  {
    return workedHours * BONUS_MULTIPLIER_MORE_THAN_60_HOURS;
  }
  return 0;
}

float calculateWeekSalaryInHours(int workedHours)
{
  float bonusHours = calculateBonusHours(workedHours);
  return workedHours + bonusHours;
}

int main()
{
  int workedHoursOnWeek;
  float employeeSalaryInHours;

  setlocale(LC_ALL, "Portuguese");

  printf("Digite a quantidade de horas trabalhadas na semana: \n");
  scanf("%i", &workedHoursOnWeek);
  employeeSalaryInHours = calculateWeekSalaryInHours(workedHoursOnWeek);
  printf("Seu salário será equivalente ao valor de %.2f horas trabalhadas por conta do bonus da empresa \n", employeeSalaryInHours);
}
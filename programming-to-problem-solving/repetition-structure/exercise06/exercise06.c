#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>

#define DISCOUNT_PER_DEPENDENT 0.05
#define ISENT_OF_TAX_FEE 0
#define BETWEEN_2_AND_3_SALARIES_FEE 0.05
#define BETWEEN_3_AND_5_SALARIES_FEE 0.10
#define BETWEEN_5_AND_7_SALARIES_FEE 0.15
#define ABOVE_7_SALARIES_FEE 0.20
#define MINIMUM_SALARY 1320

float getDiscountFromDependents(int quantityOfDependents)
{
  return quantityOfDependents * DISCOUNT_PER_DEPENDENT;
}

float getTaxFee(float monthlyIncome)
{
  float monthlyIncomeInMinimumSalaries = monthlyIncome / MINIMUM_SALARY;
  if (monthlyIncomeInMinimumSalaries < 2)
  {
    return ISENT_OF_TAX_FEE;
  }
  if (monthlyIncomeInMinimumSalaries < 3)
  {
    return BETWEEN_2_AND_3_SALARIES_FEE;
  }
  if (monthlyIncomeInMinimumSalaries < 5)
  {
    return BETWEEN_3_AND_5_SALARIES_FEE;
  }
  if (monthlyIncomeInMinimumSalaries < 7)
  {
    return BETWEEN_5_AND_7_SALARIES_FEE;
  }
  return ABOVE_7_SALARIES_FEE;
}

float getTaxValue(float salary)
{
  float totalTaxToPay = salary * getTaxFee(salary);
  return totalTaxToPay;
}

float getDiscountByDependents(int quantityOfDependents)
{
  float totalDiscount = (MINIMUM_SALARY * getDiscountFromDependents(quantityOfDependents));
  return totalDiscount;
}

float getTotalTaxValue(float salary, int quantityOfDependents)
{
  float dependentsDiscount = getDiscountByDependents(quantityOfDependents);
  float salaryWithDependentsDiscount = salary - dependentsDiscount;
  float taxToPay = getTaxValue(salaryWithDependentsDiscount);
  return taxToPay;
}

float getFinalSalary(float salary, int quantityOfDependents)
{
  float totalTaxToPay = getTotalTaxValue(salary, quantityOfDependents);
  float finalSalary = salary - totalTaxToPay;
  return finalSalary;
}

void printNewSalary(float monthlyIncome, int quantityOfDependents)
{
  float salaryAfterDiscounts = getFinalSalary(monthlyIncome, quantityOfDependents);
  float totalPaidTax = getTotalTaxValue(monthlyIncome, quantityOfDependents);
  printf("Salário final após descontos é de: %.2f \n", salaryAfterDiscounts);
  printf("Total de imposto pago foi de: %.2f \n", totalPaidTax);
}

void readUserInput(int *userCpf, int *quantityOfDependents, float *monthlyIncome)
{
  printf("\n\n***DADOS DO FUNCIONÁRIO***: \n");
  printf("Digite o CPF (Ou 0 para parar): \n");
  scanf("%i", userCpf);
  if (*userCpf == 0)
  {
    return;
  }
  printf("Digite a quantidade de dependentes: \n");
  scanf("%i", quantityOfDependents);
  printf("Digite a renda mensal: \n");
  scanf("%f", monthlyIncome);
  printf("**************************\n");
}

void readIfHasToContinue(char *charVariable)
{
  printf("Caso deseje parar digite 'N', para continuar 'S' \n");
  scanf("%s", charVariable);
}

int main()
{
  int userCpf = 0, quantityOfDependents = 0;
  float monthlyIncome;
  setlocale(LC_ALL, "Portuguese");
  do
  {
    readUserInput(&userCpf, &quantityOfDependents, &monthlyIncome);
    if (userCpf != 0)
    {
      printNewSalary(monthlyIncome, quantityOfDependents);
    }
  } while (userCpf != 0);
}

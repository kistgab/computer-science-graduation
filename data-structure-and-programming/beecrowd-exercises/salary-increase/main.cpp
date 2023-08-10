// The company ABC decided to give a salary increase to its employees, according to the following table:

// Salary	Readjustment Rate
// 0 - 400.00 is 15%
// 400.01 - 800.00 is 12%
// 800.01 - 1200.00 is 10%
// 1200.01 - 2000.00 is 7%
// Above 2000.00 is 4%

// Read the employee's salary, calculate and print the new employee's salary, as well the money earned and the increase percentual obtained by the employee, with corresponding messages in Portuguese, as the below example.
// Input
// The input contains only a floating-point number, with 2 digits after the decimal point.

// Output
// Print 3 messages followed by the corresponding numbers (see example) informing the new salary, the among of money earned (both must be shown with 2 decimal places) and the percentual obtained by the employee. Note:
// Novo salario:  means "New Salary"
// Reajuste ganho: means "Money earned"
// Em percentual: means "In percentage"

#include <stdio.h>
#include <math.h>

float getSalaryReadjustmentRate(float salary)
{
  if (salary <= 400.0f)
  {
    return 0.15f;
  }
  else if (salary <= 800.0f)
  {
    return 0.12f;
  }
  else if (salary <= 1200.0f)
  {
    return 0.10f;
  }
  else if (salary <= 2000.0f)
  {
    return 0.07f;
  }
  else
  {
    return 0.04f;
  }
};

float calculateNewSalary(float salary, float readjustmentRate)
{
  float newSalary = salary + (salary * readjustmentRate);
  return newSalary;
}

void printFinalResult(float newSalary, float salaryAdjustmentDifference, int readjustmentInPercentual)
{
  printf("Novo salario: %.2f\n", newSalary);
  printf("Reajuste ganho: %.2f\n", salaryAdjustmentDifference);
  printf("Em percentual: %i %\n", readjustmentInPercentual);
}

int getRoundedIntegerNumberFromFloat(float number)
{
  return (int)round(number * 100);
}

void handleSalary(float salary)
{
  float salaryAdjustmentDifference, newSalary, readjustmentRate;
  int readjustmentInPercentual;
  readjustmentRate = getSalaryReadjustmentRate(salary);
  newSalary = calculateNewSalary(salary, readjustmentRate);
  salaryAdjustmentDifference = newSalary - salary;
  readjustmentInPercentual = getRoundedIntegerNumberFromFloat(readjustmentRate);
  printFinalResult(newSalary, salaryAdjustmentDifference, readjustmentInPercentual);
}

int main()
{
  float userSalary;
  scanf("%f", &userSalary);
  handleSalary(userSalary);
}
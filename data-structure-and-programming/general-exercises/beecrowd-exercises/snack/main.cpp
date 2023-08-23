// Using the following table, write a program that reads a code and the amount of an item. After, print the value to pay. This is a very simple program with the only intention of practice of selection commands.

// Input
// The input file contains two integer numbers X and Y. X is the product code and Y is the quantity of this item according to the above table.

// Output
// The output must be a message "Total: R$ " followed by the total value to be paid, with 2 digits after the decimal point.

#include <stdio.h>

float getSnackPrice(int snackCode)
{
  switch (snackCode)
  {
  case 1:
    return 4.00f;
    break;
  case 2:
    return 4.50f;
    break;
  case 3:
    return 5.00f;
    break;
  case 4:
    return 2.00f;
    break;
  case 5:
    return 1.50f;
    break;
  default:
    return 0.0f;
    break;
  }
}

float getTotalShopCartPrice(int snackCode, int snackQuantity)
{
  return getSnackPrice(snackCode) * snackQuantity;
}

int main()
{
  int selectedSnackCode, selectedSnackQuantity;
  float selectedSnackPrice = 0.0f, totalPrice = 0.0;

  scanf("%i %i", &selectedSnackCode, &selectedSnackQuantity);
  totalPrice = getTotalShopCartPrice(selectedSnackCode, selectedSnackQuantity);
  printf("Total: R$ %.2f\n", totalPrice);
}
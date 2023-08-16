// 1. O cardápio de uma lanchonete é o seguinte:
// Especificação Preço unitário

// 100 Cachorro quente R$3,50
// 101 Bauru simples R$4,00
// 102 Bauru c/ovo R$4,50
// 103 Hamburger R$4,00
// 104 Cheeseburger R$3,00

// Escrever um algoritmo que leia o código do item pedido, a quantidade e calcule o valor a ser pago
// por aquele lanche.

#include <stdio.h>
#include <stdlib.h>

#define HOT_DOG_CODE 100
#define SIMPLE_BAURU_CODE 101
#define BAURU_WITH_EGGS_CODE 102
#define BURGUER_CODE 103
#define CHEESEBURGUER_CODE 104

#define HOT_DOG_PRICE 3.5
#define SIMPLE_BAURU_PRICE 4.0
#define BAURU_WITH_EGGS_PRICE 4.5
#define BURGUER_PRICE 4.0
#define CHEESEBURGUER_PRICE 3.0

#define HOT_DOG_NAME "Cachorro quente"
#define SIMPLE_BAURU_NAME "Bauru simples"
#define BAURU_WITH_EGGS_NAME "Bauru c/ovo"
#define BURGUER_NAME "Hamburguer"
#define CHEESEBURGUER_NAME "Cheeseburguer"

void printSnacksMenu()
{
  printf("-----------------------------\n");
  printf("Menu:\n");
  printf("Cód. Nome               Preço\n");
  printf("%i   %s   R$%.2f \n", HOT_DOG_CODE, HOT_DOG_NAME, HOT_DOG_PRICE);
  printf("%i   %s     R$%.2f \n", SIMPLE_BAURU_CODE, SIMPLE_BAURU_NAME, SIMPLE_BAURU_PRICE);
  printf("%i   %s       R$%.2f \n", BAURU_WITH_EGGS_CODE, BAURU_WITH_EGGS_NAME, BAURU_WITH_EGGS_PRICE);
  printf("%i   %s        R$%.2f \n", BURGUER_CODE, BURGUER_NAME, BURGUER_PRICE);
  printf("%i   %s     R$%.2f \n", CHEESEBURGUER_CODE, CHEESEBURGUER_NAME, CHEESEBURGUER_PRICE);
  printf("----------------------------- \n");
}

float getSnackPrice(int snackCode)
{
  switch (snackCode)
  {
  case HOT_DOG_CODE:
    return HOT_DOG_PRICE;
    break;
  case SIMPLE_BAURU_CODE:
    return SIMPLE_BAURU_PRICE;
    break;
  case BAURU_WITH_EGGS_CODE:
    return BAURU_WITH_EGGS_PRICE;
    break;
  case BURGUER_CODE:
    return BURGUER_PRICE;
    break;
  case CHEESEBURGUER_CODE:
    return CHEESEBURGUER_PRICE;
    break;
  default:
    return 0;
    break;
  }
}

float calculateOrderPrice(int snackCode, int snackQuantity)
{
  printf("%i\n", snackCode);
  float orderTotalPrice = getSnackPrice(snackCode) * snackQuantity;
  return orderTotalPrice;
}

int main()
{
  int selectedSnackCode, selectedSnackQuantity;
  printSnacksMenu();
  printf("Digite o codigo do produto que deseja: \n");
  scanf("%i", &selectedSnackCode);
  printf("Digite quantas unidades do produto deseja:\n");
  scanf("%i", &selectedSnackQuantity);

  float totalOrderPrice = calculateOrderPrice(selectedSnackCode, selectedSnackQuantity);
  printf("O total do pedido é de: R$ %.2f", totalOrderPrice);
}
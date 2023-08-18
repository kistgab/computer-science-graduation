#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define LIST_SIZE 10
#define FIRST_ARRAY_POSITION 0
#define LAST_ARRAY_POSITION (LIST_SIZE - 1)

#define INSERT_IN_BEGIN_CODE 1
#define INSERT_IN_MIDDLE_CODE 2
#define INSERT_IN_END_CODE 3

struct account
{
  int id;
  float balance;
};

void printMenu()
{
  printf("%i. INSERIR NO INICIO \n", INSERT_IN_BEGIN_CODE);
  printf("%i. INSERIR NO MEIO \n", INSERT_IN_MIDDLE_CODE);
  printf("%i. INSERIR NO FIM \n", INSERT_IN_END_CODE);
}

int main()
{
  int firstListPosition = -1, lastListPosition = 0;
  int success, selectedInsertModeCode, userAccountId;
  float userAccountBalance;
  struct account linearList[LIST_SIZE] = {};
  struct account contentToInsertInList;

  setlocale(LC_ALL, "Portuguese");

  printMenu();
  scanf("%i", &selectedInsertModeCode);

  printf("Digite o número da conta \n");
  scanf("%i", &userAccountId);
  printf("Digite o saldo inicial \n");
  scanf("%f", &userAccountBalance);

  contentToInsertInList.balance = userAccountBalance;
  contentToInsertInList.id = userAccountId;

  switch (selectedInsertModeCode)
  {
  case INSERT_IN_BEGIN_CODE:
    if (FIRST_ARRAY_POSITION == firstListPosition && LAST_ARRAY_POSITION == lastListPosition)
    {
      printf("Impossível realizar inserção");
      success = 0;
    }
    else if (firstListPosition == -1)
    {
      firstListPosition = 0;
      lastListPosition = 0;
    }
    else if (firstListPosition > FIRST_ARRAY_POSITION)
    {
      firstListPosition--;
    }
    else
    {
      for (int i = lastListPosition; i >= firstListPosition; i--)
      {
        linearList[i + 1] = linearList[i];
      }
      lastListPosition = lastListPosition + 1;
    }
    linearList[firstListPosition] = contentToInsertInList;
    lastListPosition++;
    success = 1;
    break;
  case INSERT_IN_MIDDLE_CODE:
    break;
  case INSERT_IN_END_CODE:
    if (FIRST_ARRAY_POSITION == firstListPosition && LAST_ARRAY_POSITION == lastListPosition)
    {
      printf("Impossível realizar inserção");
      success = 0;
    }
    else if (firstListPosition == -1)
    {
      firstListPosition = 0;
      lastListPosition = 0;
    }
    else if (firstListPosition > FIRST_ARRAY_POSITION)
    {
      firstListPosition--;
    }
    else
    {
      for (int i = firstListPosition; i <= lastListPosition; i--)
      {
        linearList[i - 1] = linearList[i];
      }
      lastListPosition = lastListPosition - 1;
    }
    linearList[firstListPosition] = contentToInsertInList;
    success = 1;
    break;
  default:
    printf("Código inválido! \n");
    break;
  };

  for (int i = 0; i <= lastListPosition; i++)
  {
    if (linearList[i].id)
    {
      printf("Posição %d - \n", i);
      printf("    AccountId: %d \n", linearList[i].id);
    }
  }
}
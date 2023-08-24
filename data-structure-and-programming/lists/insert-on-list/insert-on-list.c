#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#define LIST_SIZE 3
#define FIRST_ARRAY_POSITION 0
#define LAST_ARRAY_POSITION (LIST_SIZE - 1)

#define INSERT_IN_BEGIN_CODE 1
#define INSERT_IN_MIDDLE_CODE 2
#define INSERT_IN_END_CODE 3
#define END_PROGRAM_CODE 4

struct Account
{
  int id;
  float balance;
};

void printMenu()
{
  printf("%i. INSERIR NO INICIO \n", INSERT_IN_BEGIN_CODE);
  printf("%i. INSERIR NO MEIO \n", INSERT_IN_MIDDLE_CODE);
  printf("%i. INSERIR NO FIM \n", INSERT_IN_END_CODE);
  printf("%i. FINALIZAR \n", END_PROGRAM_CODE);
}

struct Account readAccountData()
{
  struct Account userAccount;
  int userAccountId;
  float userAccountBalance;

  printf("Digite o número da conta \n");
  scanf("%i", &userAccountId);
  printf("Digite o saldo inicial \n");
  scanf("%f", &userAccountBalance);
  userAccount.balance = userAccountBalance;
  userAccount.id = userAccountId;

  return userAccount;
}

bool insertInBeggining(struct Account linearList[], int *firstListPosition, int *lastListPosition)
{
  struct Account userAccount;
  userAccount = readAccountData();
  if (FIRST_ARRAY_POSITION == *firstListPosition && LAST_ARRAY_POSITION == *lastListPosition)
  {
    return false;
  }
  else if (*firstListPosition == -1)
  {
    *firstListPosition = 0;
    *lastListPosition = 0;
  }
  else if (*firstListPosition > FIRST_ARRAY_POSITION)
  {
    (*firstListPosition)--;
  }
  else
  {
    for (int i = *lastListPosition; i >= *firstListPosition; i--)
    {
      linearList[i + 1] = linearList[i];
    }
    (*lastListPosition)++;
  }
  linearList[*firstListPosition] = userAccount;
  return true;
}

bool insertInMiddle(struct Account linearList[], int *firstListPosition, int *lastListPosition)
{
  struct Account userAccount;
  int positionToInsert;
  printf("Digite a posição para inserir: \n");
  scanf("%i", &positionToInsert);
  if (positionToInsert > *lastListPosition || positionToInsert < *firstListPosition)
  {
    return false;
  }

  if (FIRST_ARRAY_POSITION == *firstListPosition && LAST_ARRAY_POSITION == *lastListPosition)
  {
    return false;
  }
  else if (*firstListPosition == -1)
  {
    *firstListPosition = 0;
    *lastListPosition = 0;
  }
  else if (*lastListPosition != LAST_ARRAY_POSITION)
  {
    for (int i = *lastListPosition; i <= *firstListPosition + positionToInsert; i--)
    {
      linearList[i + 1] = linearList[i];
      (*lastListPosition)++;
    }
  }
  else
  {
    for (int i = *firstListPosition; i <= *firstListPosition + positionToInsert - 1; i++)
    {
      linearList[i - 1] = linearList[i];
      (*firstListPosition)--;
    }
  }
  linearList[*firstListPosition + positionToInsert] = readAccountData();
  return true;
}

bool insertInEnd(struct Account linearList[], int *firstListPosition, int *lastListPosition)
{
  struct Account userAccount;
  userAccount = readAccountData();
  if (FIRST_ARRAY_POSITION == *firstListPosition && LAST_ARRAY_POSITION == *lastListPosition)
  {
    return false;
  }
  else if (*firstListPosition == -1)
  {
    *firstListPosition = 0;
    *lastListPosition = 0;
  }
  else if (*lastListPosition < LAST_ARRAY_POSITION)
  {
    (*lastListPosition)++;
  }
  else
  {
    for (int i = *firstListPosition; i <= *lastListPosition; i++)
    {
      linearList[i - 1] = linearList[i];
    }
    (*firstListPosition)--;
  }
  linearList[*lastListPosition] = userAccount;
  return true;
}

int main()
{
  int firstListPosition = -1, lastListPosition = 0;
  int selectedInsertModeCode;
  struct Account linearList[LIST_SIZE] = {};
  bool success;

  setlocale(LC_ALL, "Portuguese");

  printMenu();
  scanf("%i", &selectedInsertModeCode);
  while (selectedInsertModeCode != END_PROGRAM_CODE)
  {
    switch (selectedInsertModeCode)
    {
    case INSERT_IN_BEGIN_CODE:
      success = insertInBeggining(linearList, &firstListPosition, &lastListPosition);
      break;
    case INSERT_IN_MIDDLE_CODE:
      success = insertInMiddle(linearList, &firstListPosition, &lastListPosition);
      break;
    case INSERT_IN_END_CODE:
      success = insertInEnd(linearList, &firstListPosition, &lastListPosition);
      break;
    default:
    {
      printf("Código inválido! \n");
      break;
    }
    };
    if (success)
    {
      for (int i = 0; i <= lastListPosition; i++)
      {
        printf("Posição %d - \n     AccountId: %d \n\n", i, linearList[i].id);
      }
    }
    else
    {
      system("shutdown");
      printf("********************************\n");
      printf("* Impossível realizar inserção *\n");
      printf("* Lista permanece igual!       *\n");
      printf("********************************\n");
    }

    printMenu();
    scanf("%i", &selectedInsertModeCode);
  }
}
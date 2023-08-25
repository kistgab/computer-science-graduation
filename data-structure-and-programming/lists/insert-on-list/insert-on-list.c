#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#define LIST_SIZE 3
#define FIRST_ARRAY_POSITION 0
#define LAST_ARRAY_POSITION (LIST_SIZE - 1)

#define INSERT_IN_BEGIN_CODE 1
#define INSERT_IN_POSITION_CODE 2
#define INSERT_IN_END_CODE 3
#define REMOVE_IN_POSITION_CODE 4
#define END_PROGRAM_CODE 10

struct Account
{
  int id;
  float balance;
};

void printMenu()
{
  printf("%i. INSERIR NO INICIO \n", INSERT_IN_BEGIN_CODE);
  printf("%i. INSERIR NA POSIÇÃO \n", INSERT_IN_POSITION_CODE);
  printf("%i. INSERIR NO FIM \n", INSERT_IN_END_CODE);
  printf("%i. REMOVER NA POSIÇÃO \n", REMOVE_IN_POSITION_CODE);
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

bool insertInPosition(struct Account linearList[], int *firstListPosition, int *lastListPosition)
{
  int positionToInsert = 0;
  printf("Digite a posição para inserir: \n");
  scanf("%i", &positionToInsert);
  if ((FIRST_ARRAY_POSITION == *firstListPosition && LAST_ARRAY_POSITION == *lastListPosition))
  {
    return false;
  }
  if (positionToInsert > *lastListPosition - *firstListPosition + 1)
  {
    return false;
  }
  if (positionToInsert < 0)
  {
    return false;
  }
  if (*firstListPosition == -1 && positionToInsert != FIRST_ARRAY_POSITION)
  {
    return false;
  }
  if (*firstListPosition == -1)
  {
    *firstListPosition = 0;
    *lastListPosition = 0;
  }
  else if (*lastListPosition != LAST_ARRAY_POSITION)
  {
    for (int i = (*lastListPosition); i >= ((*firstListPosition) + positionToInsert); i--)
    {
      linearList[i + 1] = linearList[i];
    }
    (*lastListPosition)++;
  }
  else
  {
    for (int i = *firstListPosition; i <= *firstListPosition + positionToInsert - 1; i++)
    {
      linearList[i - 1] = linearList[i];
    }
    (*firstListPosition)--;
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

bool removeInPosition(struct Account linearList[], int *firstListPosition, int *lastListPosition)
{
  int positionToRemove, firstPositionToStartDeslocating;
  printf("Digite a posição para remover: \n");
  scanf("%i", &positionToRemove);

  if (positionToRemove < FIRST_ARRAY_POSITION || positionToRemove > *lastListPosition - *firstListPosition)
  {
    return false;
  }

  firstPositionToStartDeslocating = *firstListPosition + positionToRemove;
  for (int i = firstPositionToStartDeslocating; i < *lastListPosition; i++)
  {
    int positionAfterCurrentIndex = i + 1;
    linearList[i] = linearList[positionAfterCurrentIndex];
  }
  (*lastListPosition)--;
  if (*lastListPosition == *firstListPosition - 1)
  {
    *firstListPosition = 0;
    *lastListPosition = 0;
  }
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
    case INSERT_IN_POSITION_CODE:
      success = insertInPosition(linearList, &firstListPosition, &lastListPosition);
      break;
    case INSERT_IN_END_CODE:
      success = insertInEnd(linearList, &firstListPosition, &lastListPosition);
      break;
    case REMOVE_IN_POSITION_CODE:
      success = removeInPosition(linearList, &firstListPosition, &lastListPosition);
      break;
    default:
      printf("Código inválido! \n");
      break;
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
      printf("********************************\n");
      printf("* Impossível realizar inserção *\n");
      printf("* Lista permanece igual!       *\n");
      printf("********************************\n");
    }

    printMenu();
    scanf("%i", &selectedInsertModeCode);
  }
}
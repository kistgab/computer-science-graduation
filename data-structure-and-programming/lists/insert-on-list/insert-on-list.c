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
#define LIST_SIZE_CODE 5
#define PRINT_LIST_CODE 6
#define ACCESS_LIST_NODE_CODE 7
#define GET_POSITION_BY_VALUE_CODE 8
#define END_PROGRAM_CODE 10

struct Account
{
  int id;
  float balance;
};

void printMenu()
{
  printf("%i. Inserir no inicio \n", INSERT_IN_BEGIN_CODE);
  printf("%i. Inserir na posição \n", INSERT_IN_POSITION_CODE);
  printf("%i. Inserir no fim \n", INSERT_IN_END_CODE);
  printf("%i. Remover na posição \n", REMOVE_IN_POSITION_CODE);
  printf("%i. Mostrar tamanho da lista \n", LIST_SIZE_CODE);
  printf("%i. Mostrar conteúdo da lista \n", PRINT_LIST_CODE);
  printf("%i. Mostrar conteúdo do Nodo lista \n", ACCESS_LIST_NODE_CODE);
  printf("%i. Retornar posição da lista do valor digitado \n", GET_POSITION_BY_VALUE_CODE);
  printf("%i. Finalizar aplicação \n", END_PROGRAM_CODE);
}

void printErrorMenu()
{
  printf("********************************\n");
  printf("* Impossível realizar operação *\n");
  printf("* Lista permaneceu igual!       *\n");
  printf("********************************\n");
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
  for (int i = firstPositionToStartDeslocating; i <= *lastListPosition; i++)
  {
    int positionAfterCurrentIndex = i + 1;
    linearList[i] = linearList[positionAfterCurrentIndex];
  }
  (*lastListPosition)--;
  if (*lastListPosition == *firstListPosition - 1)
  {
    *firstListPosition = -1;
    *lastListPosition = -1;
  }
  return true;
}

bool printListSize(int *firstListPosition, int *lastListPosition)
{
  int listSize;
  if (*firstListPosition == -1)
  {
    listSize = 0;
  }
  else if (*firstListPosition == 0 && *lastListPosition == 0)
  {
    listSize = 1;
  }
  else
  {
    listSize = *lastListPosition - (*firstListPosition) + 1;
  }
  printf("O tamanho da lista é de: %i nodos\n\n\n", listSize);
  return true;
}

void printListIfCondition(bool shouldPrintList, struct Account linearList[], int *lastListPosition)
{
  if (!shouldPrintList)
  {
    return;
  }
  if (*lastListPosition == -1)
  {
    printf("Lista vazia! \n\n");
    return;
  }
  printf("\n****** CONTEÚDO DA LISTA ****** \n");
  for (int i = 0; i <= *lastListPosition; i++)
  {
    printf("Posição %d - \n     AccountId: %d - R$ %.2f \n\n", i, linearList[i].id, linearList[i].balance);
  }
  printf("******                   ****** \n\n\n");
}

bool printNodeContent(struct Account linearList[], int *firstListPosition, int *lastListPosition)
{
  int nodePosition;
  struct Account nodeContent;
  printf("Digite a posição do Nodo que você quer ler: \n");
  scanf("%i", &nodePosition);

  if (nodePosition < 0)
  {
    return false;
  }
  if (nodePosition > *lastListPosition - *firstListPosition)
  {
    return false;
  }
  if (*firstListPosition == -1)
  {
    return false;
  }
  nodeContent = linearList[*firstListPosition + nodePosition];
  printf("Posição %d - \n     AccountId: %d - R$ %.2f \n\n", nodePosition, nodeContent.id, nodeContent.balance);
  return true;
}

bool getPositionByValue(struct Account linearList[], int *firstListPosition, int *lastListPosition)
{
  int accountIdToSearchFor, foundPosition = -1;
  printf("Digite o Id da conta que você procura: \n");
  scanf("%i", &accountIdToSearchFor);

  for (int i = *firstListPosition; i <= *lastListPosition; i++)
  {
    if (accountIdToSearchFor == linearList[i].id)
    {
      foundPosition = i;
      break;
    }
  }
  if (foundPosition != -1)
  {
    printf("\n\n********* POSIÇÃO ENCONTRADA *********\n");
    printf("A posição com esse Id de conta é: %i\n", foundPosition);
    printf("********* *********\n");
    return true;
  }
  return false;
}

int main()
{
  int firstListPosition = -1, lastListPosition = -1;
  int selectedInsertModeCode;
  struct Account linearList[LIST_SIZE] = {};
  bool success;

  setlocale(LC_ALL, "Portuguese");
  while (selectedInsertModeCode != END_PROGRAM_CODE)
  {
    printMenu();
    scanf("%i", &selectedInsertModeCode);
    switch (selectedInsertModeCode)
    {
    case INSERT_IN_BEGIN_CODE:
      success = insertInBeggining(linearList, &firstListPosition, &lastListPosition);
      printListIfCondition(success, linearList, &lastListPosition);
      break;
    case INSERT_IN_POSITION_CODE:
      success = insertInPosition(linearList, &firstListPosition, &lastListPosition);
      printListIfCondition(success, linearList, &lastListPosition);
      break;
    case INSERT_IN_END_CODE:
      success = insertInEnd(linearList, &firstListPosition, &lastListPosition);
      printListIfCondition(success, linearList, &lastListPosition);
      break;
    case REMOVE_IN_POSITION_CODE:
      success = removeInPosition(linearList, &firstListPosition, &lastListPosition);
      printListIfCondition(success, linearList, &lastListPosition);
      break;
    case LIST_SIZE_CODE:
      success = printListSize(&firstListPosition, &lastListPosition);
      break;
    case PRINT_LIST_CODE:
      printListIfCondition(true, linearList, &lastListPosition);
      success = true;
      break;
    case ACCESS_LIST_NODE_CODE:
      success = printNodeContent(linearList, &firstListPosition, &lastListPosition);
      break;
    case GET_POSITION_BY_VALUE_CODE:
      success = getPositionByValue(linearList, &firstListPosition, &lastListPosition);
      break;
    default:
      printf("Código inválido! \n\n");
      break;
    };

    if (!success)
    {
      printErrorMenu();
    }
  }
}
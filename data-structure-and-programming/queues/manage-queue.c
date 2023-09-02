#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

typedef struct book
{
  int id;
  int releasedAtYear;
  char publisher[128];
  char name[128];
} Book;

#define ARRAY_SIZE 3
#define LOWEST_QUEUE_LIMIT 0
#define HIGHEST_QUEUE_LIMIT ARRAY_SIZE - 1

#define INSERT_OPTION_CODE 1
#define DELETE_OPTION_CODE 2
#define PRINT_LAST_OPTION_CODE 3
#define EXIT_OPTION_CODE 10

void printOptionsMenu()
{
  printf("************* MENU - FILA ****************\n");
  printf("* %i Inserir                             *\n", INSERT_OPTION_CODE);
  printf("* %i Remover                             *\n", DELETE_OPTION_CODE);
  printf("* %i Verificar conteúdo do primeiro nodo *\n", PRINT_LAST_OPTION_CODE);
  printf("* %i Finalizar aplicação                 *\n", EXIT_OPTION_CODE);
  printf("******************************************\n");
}

void printBookData(Book book)
{
  printf("Livro: \n");
  printf("  Código: %i\n", book.id);
  printf("  Nome: %s\n", book.name);
  printf("  Editora: %s\n", book.publisher);
  printf("  Ano de lançamento: %i\n", book.releasedAtYear);
  printf("\n\n");
}

void initializeQueue(int *firstPosition, int *lastPosition)
{
  *firstPosition = LOWEST_QUEUE_LIMIT - 1;
  *lastPosition = LOWEST_QUEUE_LIMIT - 1;
}

Book readBookData()
{
  Book book;

  printf("\n");
  printf("Informar dados da pessoa:\n");
  printf("Digite o código do livro:\n");
  scanf("%i", &book.id);
  printf("Digite o nome do livro:\n");
  scanf("%s", &book.name);
  printf("Digite o nome da editora:\n");
  scanf("%s", &book.publisher);
  printf("Digite o ano de lançamento:\n");
  scanf("%f", &book.releasedAtYear);
  return book;
}

bool insertInQueue(Book queue[], int *firstQueuePosition, int *lastQueuePosition)
{
  if ((*lastQueuePosition == *firstQueuePosition - 1) && *firstQueuePosition == LOWEST_QUEUE_LIMIT)
  {
    return false;
  }
  if (*lastQueuePosition == HIGHEST_QUEUE_LIMIT)
  {
    return false;
  }
  if (*firstQueuePosition == LOWEST_QUEUE_LIMIT - 1)
  {
    *firstQueuePosition = LOWEST_QUEUE_LIMIT;
    *lastQueuePosition = LOWEST_QUEUE_LIMIT;
  }
  else if (*lastQueuePosition == HIGHEST_QUEUE_LIMIT)
  {
    *lastQueuePosition = LOWEST_QUEUE_LIMIT;
  }
  else
  {
    (*lastQueuePosition)++;
  }
  queue[*lastQueuePosition] = readBookData();
  return true;
}

bool removeFromQueue(Book queue[], int *firstQueuePosition, int *lastQueuePosition)
{
  if (*firstQueuePosition == LOWEST_QUEUE_LIMIT - 1)
  {
    return false;
  }
  if (*firstQueuePosition == *lastQueuePosition)
  {
    *firstQueuePosition = LOWEST_QUEUE_LIMIT - 1;
    *lastQueuePosition = LOWEST_QUEUE_LIMIT - 1;
  }
  else if (*firstQueuePosition == HIGHEST_QUEUE_LIMIT)
  {
    *firstQueuePosition = LOWEST_QUEUE_LIMIT;
  }
  else
  {
    (*firstQueuePosition)++;
  }
  return true;
}

int main()
{
  int userSelectedOption, firstQueuePosition, lastQueuePosition;
  bool sucess;
  Book queue[ARRAY_SIZE];

  setlocale(LC_ALL, "Portuguese");
  initializeQueue(&firstQueuePosition, &lastQueuePosition);

  printOptionsMenu();
  scanf("%i", &userSelectedOption);
  while (userSelectedOption != EXIT_OPTION_CODE)
  {
    switch (userSelectedOption)
    {
    case INSERT_OPTION_CODE:
      sucess = false;
      break;
    case DELETE_OPTION_CODE:
      sucess = false;
      break;
    case PRINT_LAST_OPTION_CODE:
      sucess = false;
      break;
    default:
      printf("Código inexistente!\n");
      sucess = false;
      break;
    }
    if (!sucess)
    {
      printf("\n********************************\n");
      printf("Operação não pode ser realizada!\n");
      printf("********************************\n");
    }
    if (firstQueuePosition >= LOWEST_QUEUE_LIMIT)
    {
      printf("\n");
      printf("O valor da posição %i (primeira) é:\n", firstQueuePosition);
      printBookData(queue[firstQueuePosition]);
    }
    else
    {
      printf("\n\nA fila está totalmente vazia! \n");
    }
    printOptionsMenu();
    scanf("%i", &userSelectedOption);
  }
}
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

typedef struct person
{
  int age;
  float height;
  float weight;
} Person;

#define FIRST_STACK_POSITION 0
#define ARRAY_SIZE 3
#define STACK_LIMIT ARRAY_SIZE - 1

#define INSERT_OPTION_CODE 1
#define DELETE_OPTION_CODE 2
#define PRINT_LAST_OPTION_CODE 3
#define EXIT_OPTION_CODE 10

void printOptionsMenu()
{
  printf("******* MENU - PILHA SEQUENCIAL ********\n");
  printf("* %i Inserir                           *\n", INSERT_OPTION_CODE);
  printf("* %i Remover                           *\n", DELETE_OPTION_CODE);
  printf("* %i Verificar conteúdo do último nodo *\n", PRINT_LAST_OPTION_CODE);
  printf("* %i Finalizar aplicação              *\n", EXIT_OPTION_CODE);
  printf("****************************************\n");
}

void printPersonData(Person person)
{
  printf("Pessoa: \n");
  printf("  Idade: %i\n", person.age);
  printf("  Altura: %.2f\n", person.height);
  printf("  Peso: %.2f\n", person.weight);
  printf("\n\n");
}

Person readPersonData()
{
  Person person;

  printf("\n");
  printf("Informar dados da pessoa:\n");
  printf("Digite a idade:\n");
  scanf("%i", &person.age);
  printf("Digite a altura:\n");
  scanf("%f", &person.height);
  printf("Digite o peso:\n");
  scanf("%f", &person.weight);
  return person;
}

bool pushItemToStack(int *lastStackPosition, Person stack[])
{
  if (*lastStackPosition >= STACK_LIMIT)
  {
    return false;
  }
  (*lastStackPosition)++;
  stack[*lastStackPosition] = readPersonData();
  return true;
}

bool popStackItem(int *lastStackPosition, Person stack[])
{
  if (*lastStackPosition < FIRST_STACK_POSITION)
  {
    return false;
  }
  (*lastStackPosition)--;
  return true;
}

bool printStackItem(int *lastStackPosition, Person stack[])
{
  if (*lastStackPosition < FIRST_STACK_POSITION)
  {
    return false;
  }
  printPersonData(stack[*lastStackPosition]);
}

void initializeStackConditions(int *lastStackPosition)
{
  *lastStackPosition = FIRST_STACK_POSITION - 1;
}

int main()
{
  int lastStackPosition, userSelectedOption = 0;
  bool success;
  Person stack[ARRAY_SIZE];

  setlocale(LC_ALL, "Portuguese");
  initializeStackConditions(&lastStackPosition);

  printOptionsMenu();
  scanf("%i", &userSelectedOption);
  while (userSelectedOption != EXIT_OPTION_CODE)
  {
    switch (userSelectedOption)
    {
    case INSERT_OPTION_CODE:
      success = pushItemToStack(&lastStackPosition, stack);
      break;
    case DELETE_OPTION_CODE:
      success = popStackItem(&lastStackPosition, stack);
      break;
    case PRINT_LAST_OPTION_CODE:
      success = printStackItem(&lastStackPosition, stack);
      break;
    default:
      printf("Código inexistente!\n");
      success = false;
      break;
    }
    if (!success)
    {
      printf("\n********************************\n");
      printf("Operação não pode ser realizada!\n");
      printf("********************************\n");
    }
    if (lastStackPosition >= FIRST_STACK_POSITION)
    {
      printf("\n");
      printf("O valor da posição %i (última) é:\n", lastStackPosition);
      printPersonData(stack[lastStackPosition]);
    }
    else
    {
      printf("\n\nA pilha está totalmente vazia! \n");
    }
    printOptionsMenu();
    scanf("%i", &userSelectedOption);
  }
}
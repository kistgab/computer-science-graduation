#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct node
{
  int data;
  struct node *nextNode;
} Node;

typedef struct descriptor
{
  Node *first;
  Node *last;
} Descriptor;

Node *createNode(int value)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Impossível alocar memória.\n");
    exit(1);
  }
  newNode->data = value;
  newNode->nextNode = NULL;
  return newNode;
}

void insert(Descriptor **descriptor, int value)
{
  Node *newNode = createNode(value);
  if ((*descriptor)->first == NULL)
  {
    (*descriptor)->first = newNode;
  }
  else
  {
    (*descriptor)->last->nextNode = newNode;
  }
  (*descriptor)->last = newNode;
}

void pop(Descriptor **descriptor)
{
  if ((*descriptor)->first == NULL)
  {
    printf("Impossível remover pois não existem nodos na lista.");
    return;
  }
  Node *oldValue = (*descriptor)->first;
  (*descriptor)->first = oldValue->nextNode;
  free(oldValue);
  if ((*descriptor)->first == NULL)
  {
    (*descriptor)->last = NULL;
  }
}

void printFirstQueueNode(Descriptor *descriptor)
{
  if (descriptor->first == NULL)
  {
    printf("Impossível imprimir pois não existem nodos na lista.");
    return;
  }
  printf("Primeiro valor da lista: %i", descriptor->first->data);
}

void printMenu()
{
  printf("\nEscolha a opção desejada: ");
  printf("\n1. Inserir um nódo");
  printf("\n2. Remover um nódo");
  printf("\n3. Consultar");
  printf("\n999. Sair\n");
}

int main()
{
  int selectedOption = 0;
  Descriptor *descriptor = malloc(sizeof(Descriptor));
  descriptor->first = NULL;
  descriptor->last = NULL;

  setlocale(LC_ALL, "Portuguese");
  while (selectedOption != 999)
  {
    printMenu();
    scanf("%i", &selectedOption);
    switch (selectedOption)
    {
    case 1:
      int valueToInsert;
      printf("\nDigite um valor para inserir: ");
      scanf("%i", &valueToInsert);
      insert(&descriptor, valueToInsert);
      break;
    case 2:
      pop(&descriptor);
      break;
    case 3:
      printFirstQueueNode(descriptor);
    default:
      break;
    }
  }
}
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct Node
{
  int data;
  struct Node *nextNode;
} Node;

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

void insert(Node **top, int value)
{
  Node *newNode = createNode(value);
  newNode->nextNode = *top;
  *top = newNode;
}

void printAll(Node *top)
{
  Node *currentNode = top;
  while (currentNode != NULL)
  {
    printf("%d\n", currentNode->data);
    currentNode = currentNode->nextNode;
  }
}

void pop(Node **top)
{
  if (*top == NULL)
  {
    printf("Impossível remover pois não existem nodos.");
    return;
  }
  Node *oldStackValue = *top;
  *top = (*top)->nextNode;
  free(oldStackValue);
  printf("Registro removido!");
}

void getTop(Node *top)
{
  if (top == NULL)
  {
    printf("Impossível consultar pois não existem nodos.");
    return;
  }
  printf("Valor do Topo: %d", top->data);
}

void printMenu()
{
  printf("\nEscolha a opção desejada: ");
  printf("\n1. Inserir um nódo");
  printf("\n2. Remover um nódo");
  printf("\n3. Consultar o topo");
  printf("\n999. Sair\n");
}

int main()
{
  Node *stackTop = NULL;
  int selectedOption = 0;
  setlocale(LC_ALL, "Portuguese");
  while (selectedOption != 999)
  {
    printMenu();
    scanf("%i", &selectedOption);
    switch (selectedOption)
    {
    case 1:
      int valueToInsert;
      printf("Digite o valor que você deseja inserir: ");
      scanf("%i", &valueToInsert);
      insert(&stackTop, valueToInsert);
      break;
    case 2:
      pop(&stackTop);
    case 3:
      getTop(stackTop);
    default:
      break;
    }
  }
}
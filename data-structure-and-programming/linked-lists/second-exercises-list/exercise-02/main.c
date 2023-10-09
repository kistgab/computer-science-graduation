#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *nextNode;
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

void push(Node **listHead, int newData)
{
  Node *newCreatedNode = createNode(newData);
  if (*listHead == NULL)
  {
    *listHead = newCreatedNode;
    return;
  }
  Node *lastNode = *listHead;
  while (lastNode->nextNode != NULL)
  {
    lastNode = lastNode->nextNode;
  }
  lastNode->nextNode = newCreatedNode;
}

int countNodes(Node *head)
{
  int count = 0;
  Node *current = head;
  while (current != NULL)
  {
    count++;
    current = current->nextNode;
  }
  return count;
}

void countHigherAndEqual(Node *head, int valor)
{
  int contador_igual = 0;
  int contador_maior = 0;
  int posicao = 1;
  Node *current = head;

  while (current != NULL)
  {
    if (current->data == valor)
    {
      contador_igual++;
      printf("Nodo com valor %d encontrado na posição %d\n", valor, posicao);
    }
    else if (current->data > valor)
    {
      contador_maior++;
    }
    current = current->nextNode;
    posicao++;
  }

  printf("Total de nodos com valor igual a %d: %d\n", valor, contador_igual);
  printf("Total de nodos com valor maior que %d: %d\n", valor, contador_maior);
}

void printList(Node *head)
{
  Node *current = head;
  while (current != NULL)
  {
    printf("%d ", current->data);
    current = current->nextNode;
  }
  printf("\n");
}

void printMenu()
{
  printf("***********************************\n");
  printf("*         PREENCHA A LISTA        *\n");
  printf("***********************************\n");
  printf("Digite os valores da lista (digite -1 para encerrar a entrada):\n");
}

int main()
{
  Node *head = NULL;
  int oldValue, newValue, inputValue;
  printMenu();
  while (1)
  {
    scanf("%d", &inputValue);
    if (inputValue == -1)
    {
      break;
    }
    push(&head, inputValue);
  }

  printf("Digite o valor para pesquisar na lista: ");
  scanf("%d", &oldValue);

  countNodes(head);
  countHigherAndEqual(head, oldValue);
}

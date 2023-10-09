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

int incrementReplaceTimes()
{
  static int totalTimes = 0;
  totalTimes++;
  return totalTimes;
}

int replaceAndCount(Node **head, int oldValue, int newValue)
{
  Node *current = *head;
  int totalTimes = 0;

  while (current != NULL)
  {
    if (current->data == oldValue)
    {
      current->data = newValue;
      totalTimes = incrementReplaceTimes();
    }
    current = current->nextNode;
  }
  return totalTimes;
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

  printf("Digite o valor antigo a ser substituído: ");
  scanf("%d", &oldValue);

  printf("Digite o valor novo: ");
  scanf("%d", &newValue);

  int count = replaceAndCount(&head, oldValue, newValue);
  printf("Lista após a substituição:\n");
  printList(head);
  printf("Total de trocas efetuadas: %d\n", count);
}

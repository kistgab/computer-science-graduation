#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct node
{
  int value;
  struct node *next;
} Node;

Node *createNode(int value)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL)
  {
    printf("Impossível alocar memória.\n");
    exit(1);
  }
  newNode->value = value;
  newNode->next = NULL;
  return newNode;
}

void insertAtPosition(Node **head, int value, int position)
{
  if (position < 1)
  {
    printf("Posição inválida. Posição deve ser >= 1.\n");
    return;
  }
  Node *newNode = createNode(value);
  if (position == 1)
  {
    newNode->next = *head;
    *head = newNode;
    return;
  }
  Node *current = *head;
  int currentPosition = 1;
  while (current != NULL && currentPosition < position - 1)
  {
    current = current->next;
    currentPosition++;
  }
  if (current == NULL)
  {
    printf("A posição que deseja é maior que o tamanho da lista.\n");
    free(newNode);
    return;
  }
  newNode->next = current->next;
  current->next = newNode;
}

void removeFromPosition(Node **head, int position)
{
  if (position < 1)
  {
    printf("Posição inválida. Posição deve ser >= 1.\n");
    return;
  }
  if (*head == NULL)
  {
    printf("A lista está vazia! Nada para remover!\n");
    return;
  }
  if (position == 1)
  {
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
    return;
  }
  Node *current = *head;
  int currentPosition = 1;
  while (current != NULL && currentPosition < position - 1)
  {
    current = current->next;
    currentPosition++;
  }
  if (current == NULL || current->next == NULL)
  {
    printf("A posição que deseja é maior que o tamanho da lista.\n");
    return;
  }
  Node *temp = current->next;
  current->next = current->next->next;
  free(temp);
}

void searchAtPosition(Node *head, int position)
{
  if (position < 1)
  {
    printf("Posição inválida. Posição deve ser >= 1.\n");
    return;
  }
  Node *current = head;
  int currentPosition = 1;
  while (current != NULL && currentPosition < position)
  {
    current = current->next;
    currentPosition++;
  }
  if (current == NULL)
  {
    printf("A posição que deseja é maior que o tamanho da lista.\n");
    return;
  }
  printf("Valor encontrado: %d \n", current->value);
}

void printList(Node *head)
{
  Node *current = head;

  while (current != NULL)
  {
    printf("%d -> ", current->value);
    current = current->next;
  }
  printf("FIM\n");
}

int replaceAndCount(Node **head, int oldValue, int newValue)
{
  Node *current = *head;
  int totalTimes = 0;
  while (current != NULL)
  {
    if (current->value == oldValue)
    {
      current->value = newValue;
      totalTimes++;
    }
    current = current->next;
  }
  return totalTimes;
}

int countNodes(Node *head)
{
  int count = 0;
  Node *current = head;
  while (current != NULL)
  {
    count++;
    current = current->next;
  }
  return count;
}

void countHigherAndEqual(Node *head, int valueToCompare)
{
  int equalCounter = 0;
  int higherCounter = 0;
  int currentPosition = 1;
  Node *current = head;

  while (current != NULL)
  {
    if (current->value == valueToCompare)
    {
      equalCounter++;
      printf("Nodo com valor %d encontrado na posição %d\n", valueToCompare, currentPosition);
    }
    else if (current->value > valueToCompare)
    {
      higherCounter++;
    }
    current = current->next;
    currentPosition++;
  }

  printf("Total de nodos com valor igual a %d: %d\n", valueToCompare, equalCounter);
  printf("Total de nodos com valor maior que %d: %d\n", valueToCompare, higherCounter);
}

void readNodeValue(int *value, int *positionToInsert)
{
  printf("\nDigite o valor que deseja inserir: ");
  scanf("%d", value);
  printf("\nDigite em qual posição deseja inserir: ");
  scanf("%d", positionToInsert);
}

void printMenu()
{
  printf("\nEscolha a opção desejada: ");
  printf("\n1. Inserir um valor na Lista");
  printf("\n2. Remover um valor da Lista");
  printf("\n3. Consultar a Lista");
  printf("\n4. Imprimir toda a Lista");
  printf("\n5. Contar todos nodos da lista");
  printf("\n6. Contar todos valores maiores e os iguais a X");
  printf("\n7. Trocar um valor por outro e contar qtd. de trocas");
  printf("\n999. Sair");
}

int main()
{
  setlocale(LC_ALL, "Portuguese");

  int selectedOption = 0;
  Node *head = NULL;

  while (selectedOption != 999)
  {
    printMenu();
    printf("\nOpção desejada: ");
    scanf("%d", &selectedOption);
    switch (selectedOption)
    {
    case 1:
      int value, positionToInsert;
      readNodeValue(&value, &positionToInsert);
      insertAtPosition(&head, value, positionToInsert);
      break;
    case 2:
      int positionToRemove;
      printf("Digite a posição que deseja remover: \n");
      scanf("%d", &positionToRemove);
      removeFromPosition(&head, positionToRemove);
      break;
    case 3:
      int positionToSeach;
      printf("Digite a posição que deseja procurar: \n");
      scanf("%d", &positionToSeach);
      searchAtPosition(head, positionToSeach);
      break;
    case 4:
      printList(head);
      break;
    case 5:
      printf("A lista tem %d nodos\n", countNodes(head));
      break;
    case 6:
      int valueToCompare;
      printf("Informe o valor de X: ");
      scanf("%i", &valueToCompare);
      countHigherAndEqual(head, valueToCompare);
      break;
    case 7:
      int oldValue, newValue;
      printf("Informe o valor que deseja substituir: \n");
      scanf("%i", &oldValue);
      printf("Informe o valor para substituir: \n");
      scanf("%i", &newValue);
      printf("Foram substituidos %d valores", replaceAndCount(&head, oldValue, newValue));
      break;
    default:
      break;
    }
  }
}
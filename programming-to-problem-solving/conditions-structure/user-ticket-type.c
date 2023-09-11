// 4. Escreva um programa para determinar o tipo de bilhete que cada visitante de um parque de diversões deve comprar. O tipo de bilhete é determinado em função da idade do visitante, de acordo com a seguinte tabela:
// Idade          - Bilhete
// Inferior a 6   - Isento de pagamento
// Entre 6 e 12   - Bilhete de criança
// Entre 13 e 65  - Bilhete normal
// Mais de 65     - Bilhete da terceira idade

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define NOT_PAYED_TICKET_ID 1
#define KIDS_TICKET_ID 2
#define NORMAL_TICKET_ID 3
#define SENIORS_TICKET_ID 4

int getTicketTypeIdByAge(int age)
{
  if (age < 6)
  {
    return NOT_PAYED_TICKET_ID;
  }
  if (age < 12)
  {
    return KIDS_TICKET_ID;
  }
  if (age < 65)
  {
    return NORMAL_TICKET_ID;
  }
  return SENIORS_TICKET_ID;
}

void printTicketTypeByAge(int age)
{
  char ticketType[40];
  int ticketTypeId;

  ticketTypeId = getTicketTypeIdByAge(age);
  if (ticketTypeId == NOT_PAYED_TICKET_ID)
  {
    strcpy(ticketType, "Isento de pagamento");
  }
  else if (ticketTypeId == KIDS_TICKET_ID)
  {
    strcpy(ticketType, "Bilhete de criança");
  }
  else if (ticketTypeId == NORMAL_TICKET_ID)
  {
    strcpy(ticketType, "Bilhete normal");
  }
  else
  {
    strcpy(ticketType, "Bilhete da terceira idade");
  }

  printf("O ticket dessa pessoa é da categoria: \"%s\"", ticketType);
}

int main()
{
  int userAge;
  setlocale(LC_ALL, "Portuguese");

  printf("Informe a sua idade:\n");
  scanf("%i", &userAge);
  printTicketTypeByAge(userAge);
}
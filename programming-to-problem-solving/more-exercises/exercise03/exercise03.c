#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

#define POINTS_PER_CORRECT_GUESS 5
#define POINTS_PER_CORRECT_WINNER_OR_DRAW_GUESS 10

typedef struct bet
{
  int firstTeamScore;
  int secondTeamScore;
} Bet;

typedef struct gambler
{
  char name[50];
  Bet bet;
  int points;
} Gambler;

void readTeamsNames(char *firstTeamName, char *secondTeamName)
{
  system("clear");
  printf("********************************** \n");
  printf("*         DADOS DOS TIMES        * \n");
  printf("********************************** \n");
  printf("Digite o nome do primeiro time do jogo: \n");
  scanf("%s", firstTeamName);
  printf("Digite o nome do segundo time do jogo: \n");
  scanf("%s", secondTeamName);
  system("clear");
}

void readGamblersData(Gambler gamblers[], int quantityOfGamblers, char *firstTeamName, char *secondTeamName)
{
  system("clear");
  for (int i = 0; i < quantityOfGamblers; i++)
  {
    gamblers[i].points = 0;
    printf("** Participante %i **\n", i);
    printf("Qual seu nome?\n");
    scanf("%s", &gamblers[i].name);
    printf("Qual o seu palpite para o time %s (1):\n", firstTeamName);
    scanf("%i", &gamblers[i].bet.firstTeamScore);
    printf("Qual o seu palpite para o time %s (2):\n", secondTeamName);
    scanf("%i", &gamblers[i].bet.secondTeamScore);
  }
}

bool isFirstTeamWinner(int firstTeamScore, int secondTeamScore)
{
  return firstTeamScore > secondTeamScore;
}

bool isDraw(int firstTeamScore, int secondTeamScore)
{
  return firstTeamScore == secondTeamScore;
}

void fillGamblersScores(Gambler gamblers[], int quantityOfGamblers, int firstTeamFinalScore, int secondTeamFinalScore)
{
  for (int i = 0; i < quantityOfGamblers; i++)
  {
    Gambler *gambler = &gamblers[i];
    bool betFirstTeamWon = isFirstTeamWinner(gambler->bet.firstTeamScore, gambler->bet.secondTeamScore);
    bool betDraw = isDraw(gambler->bet.firstTeamScore, gambler->bet.secondTeamScore);
    bool betSecondTeamWon = !betFirstTeamWon && !betDraw;

    bool wasDraw = isDraw(firstTeamFinalScore, secondTeamFinalScore);
    bool wasFirstTeamWinner = isFirstTeamWinner(firstTeamFinalScore, secondTeamFinalScore);
    bool wasSecondTeamWinner = !wasFirstTeamWinner && !wasDraw;

    bool guessedWinner = (betFirstTeamWon && wasFirstTeamWinner) || (betSecondTeamWon && wasSecondTeamWinner);
    bool guessedDraw = betDraw && wasDraw;
    bool guessedFirstTeamScore = gambler->bet.firstTeamScore == firstTeamFinalScore;
    bool guessedSecondTeamScore = gambler->bet.secondTeamScore == secondTeamFinalScore;

    if (guessedFirstTeamScore)
    {
      (gambler->points) += POINTS_PER_CORRECT_GUESS;
    }
    if (guessedSecondTeamScore)
    {
      (gambler->points) += POINTS_PER_CORRECT_GUESS;
    }
    if (guessedWinner)
    {
      (gambler->points) += POINTS_PER_CORRECT_WINNER_OR_DRAW_GUESS;
    }
    if (guessedDraw)
    {
      (gambler->points) += POINTS_PER_CORRECT_WINNER_OR_DRAW_GUESS;
    }
  }
}

void printFinalResult(Gambler gamblers[], int quantityOfGamblers)
{
  system("clear");
  printf("**************************************************\n");
  printf("*                 RESULTADOS                     *\n");
  printf("**************************************************\n");
  printf("--------------------------------------------------\n");
  for (int i = 0; i < quantityOfGamblers; i++)
  {
    Gambler *gambler = &gamblers[i];
    printf("Nome: %s --- Pontos: %i\n", gambler->name, gambler->points);
    printf("--------------------------------------------------\n");
  }
}

int main()
{
  int quantityOfGamblers, firstTeamFinalScore, secondTeamFinalScore;
  char firstTeamName[50], secondTeamName[50];

  setlocale(LC_ALL, "Portuguese");

  readTeamsNames(firstTeamName, secondTeamName);
  printf("Digite a quantidade de participantes: \n");
  scanf("%i", &quantityOfGamblers);
  Gambler gamblers[quantityOfGamblers];
  readGamblersData(gamblers, quantityOfGamblers, firstTeamName, secondTeamName);
  printf("Digite o placar final do time %s (1): \n", firstTeamName);
  scanf("%i", &firstTeamFinalScore);
  printf("Digite o placar final do time %s (2): \n", secondTeamName);
  scanf("%i", &secondTeamFinalScore);
  fillGamblersScores(gamblers, quantityOfGamblers, firstTeamFinalScore, secondTeamFinalScore);
  printFinalResult(gamblers, quantityOfGamblers);
}
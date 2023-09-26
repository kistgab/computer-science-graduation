// ************ CABEÇALHO *************
// Integrantes: Arthur Brixius da Costa e Gabriel Kist
// Grupo D
// ********** FIM CABEÇALHO ***********

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

#define NUMBER_TO_STOP_PROGRAM 0
#define INITIAL_NUMBER_OF_INTERVAL_OF_PLAYERS 1
#define FINAL_NUMBER_OF_INTERVAL_OF_PLAYERS 23
#define MAXIMUM_VOTES 128

typedef struct shirtNumberVote
{
  int shirtNumber;
  int totalVotes;
} ShirtNumberVote;

void readUserInput(int *userVotedShirtNumber)
{
  printf("Digite o número da camiseta do jogador que deseja votar: (1 a 23):");
  scanf("%i", userVotedShirtNumber);
}

bool alreadyHaveVotesInShirtNumber(int shirtNumber, ShirtNumberVote votesPerShirt[], int totalShirtsVoted)
{
  for (int i = 0; i < totalShirtsVoted; i++)
  {
    if (votesPerShirt[i].shirtNumber == shirtNumber)
    {
      return true;
    }
  }
  return false;
}

void incrementVotesInShirtNumber(int userVotedShirtNumber, ShirtNumberVote votesPerShirt[])
{
  for (int i = 0; i < MAXIMUM_VOTES; i++)
  {
    if (votesPerShirt[i].shirtNumber == userVotedShirtNumber)
    {
      votesPerShirt[i].totalVotes++;
    }
  }
}

void insertFirstVoteInShirtNumber(int userVotedShirtNumber, ShirtNumberVote votesPerShirt[], int totalShirts)
{
  votesPerShirt[totalShirts].shirtNumber = userVotedShirtNumber;
  votesPerShirt[totalShirts].totalVotes = 1;
}

bool validateShirtNumber(int shirtNumber)
{
  bool isBetweenFirstAndFinalShirtNumbers = shirtNumber >= INITIAL_NUMBER_OF_INTERVAL_OF_PLAYERS && shirtNumber <= FINAL_NUMBER_OF_INTERVAL_OF_PLAYERS;
  return isBetweenFirstAndFinalShirtNumbers;
}

void printErrorMessage(char customErrorMessage[])
{
  printf("*****     ATENÇÃO     ***** \n");
  printf("***** OCORREU UM ERRO *****: \n");
  printf("%s \n", customErrorMessage);
  printf("***************************: \n");
}

ShirtNumberVote getMostVotedPlayer(ShirtNumberVote votesPerShirt[], int totalVotedShirts)
{
  ShirtNumberVote mostVotedPlayer;
  mostVotedPlayer.totalVotes = 0;

  for (int i = 0; i < totalVotedShirts; i++)
  {
    if (votesPerShirt[i].totalVotes > mostVotedPlayer.totalVotes)
    {
      mostVotedPlayer.shirtNumber = votesPerShirt[i].shirtNumber;
      mostVotedPlayer.totalVotes = votesPerShirt[i].totalVotes;
    }
  }
  return mostVotedPlayer;
}

float calculatePercentageOfVotes(int totalShirtVotes, int totalVotes)
{
  float percentageOfVotesInShirt = ((float)totalShirtVotes / totalVotes) * 100;
  return percentageOfVotesInShirt;
}

void printPercentageOfVotesPerPlayer(ShirtNumberVote votesPerShirt[], int totalVotes, int totalShirtsVoted)
{
  printf("Jogador   Votos    Percentual\n");
  for (int i = 0; i < totalShirtsVoted; i++)
  {
    float percentageOfCurrentPlayer = calculatePercentageOfVotes(votesPerShirt[i].totalVotes, totalVotes);
    printf("%i        %i        %.2f% \n", votesPerShirt[i].shirtNumber, votesPerShirt[i].totalVotes, percentageOfCurrentPlayer);
  }
}

void printFinalResults(ShirtNumberVote votesPerShirt[], int totalVotes, int totalShirtsVoted)
{
  ShirtNumberVote mostVotedPlayer = getMostVotedPlayer(votesPerShirt, totalShirtsVoted);
  float mostVotedPercentageOfVotes = calculatePercentageOfVotes(mostVotedPlayer.totalVotes, totalVotes);

  printf("********* RESULTADO FINAL *********\n");
  printf("Total de votos: %i \n", totalVotes);
  printf("Jogador mais votado foi o n° :  %i, com %i votos, totalizando %.2f% \n", mostVotedPlayer.shirtNumber, mostVotedPlayer.totalVotes, mostVotedPercentageOfVotes);
  printPercentageOfVotesPerPlayer(votesPerShirt, totalVotes, totalShirtsVoted);
  printf("***********************************\n");
}

int main()
{
  setlocale(LC_ALL, "Portuguese");
  int userVotedShirtNumber = __INT16_MAX__, totalShirtsVoted = 0, totalVotes = 0;
  ShirtNumberVote votesPerShirt[128];

  while (userVotedShirtNumber != NUMBER_TO_STOP_PROGRAM)
  {
    readUserInput(&userVotedShirtNumber);
    if (userVotedShirtNumber == NUMBER_TO_STOP_PROGRAM)
    {
      break;
    }
    if (!validateShirtNumber(userVotedShirtNumber))
    {
      printErrorMessage("O número da camiseta precisa estar presente no intervalo definido");
      printf("Intervalo definido: %i - %i\n", INITIAL_NUMBER_OF_INTERVAL_OF_PLAYERS, FINAL_NUMBER_OF_INTERVAL_OF_PLAYERS);
      continue;
    }
    if (alreadyHaveVotesInShirtNumber(userVotedShirtNumber, votesPerShirt, totalShirtsVoted))
    {
      incrementVotesInShirtNumber(userVotedShirtNumber, votesPerShirt);
    }
    else
    {
      insertFirstVoteInShirtNumber(userVotedShirtNumber, votesPerShirt, totalShirtsVoted);
      totalShirtsVoted++;
    }
    totalVotes++;
  }

  printFinalResults(votesPerShirt, totalVotes, totalShirtsVoted);
}
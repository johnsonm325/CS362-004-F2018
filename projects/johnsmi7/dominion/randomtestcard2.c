/***********************************************
 * Michael Johnson
 * Assignment 3
 * CS362 - Fall 2018
 * ********************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

int k[10];

void randomize(int*, int, int, int);
void randomGameInitialize(int, struct gameState*);
void randomGameState(struct gameState*);

void randomize(int *array, int arrSize, int top, int bottom)
{
  int i = 0;
  int x;
  while(i<arrSize){
    int r = (rand() % (top - bottom + 1)) + bottom;

    for (x = 0; x < i; x++)
    {
      if(array[x] == r){
        break;
      }
    }
    if(x == i){
      array[i++] = r;
    }
  }
}

void randomGameInitialize(int seed, struct gameState *G)
{
  int upper = 26,
      lower = 7,
      numPlayers;
  
  do
  {
    randomize(k, 10, upper, lower);
  }while(k[0] == 16 || k[1] == 16 || k[2] == 16 || k[3] == 16 || k[4] == 16 ||
         k[5] == 16 || k[6] == 16 || k[7] == 16 || k[8] == 16 || k[9] == 16);
  k[0] = great_hall;

  numPlayers = (rand() % (4 - 2 + 1)) + 2;

  initializeGame(numPlayers, k, seed, G);
}

void randomGameState(struct gameState *G)
{
  int i,
      j,
      countUpper = 15,
      countLower = 0,
      tableCards[16],
      card,
      greatHallCounter;

  for(i = 7; i < 17; i++)
  {
    tableCards[i] = k[i-7];
  }

  for(i = 0; i < 7; i++)
  {
    tableCards[i] = i;
  }

  for(i = 0; i < G->numPlayers; i++)
  {
    do
    {
      G->handCount[i] = (rand() % (countUpper - countLower + 1)) + countLower;
      G->deckCount[i] = (rand() % (countUpper - countLower + 1)) + countLower;
      G->discardCount[i] = (rand() % (countUpper - countLower + 1)) + countLower;
    }while( ((G->deckCount[i] + G->discardCount[i]) < 1) || G->handCount[i] == 0);

    do
    {
      greatHallCounter = 0;
      for(j = 0; j < G->handCount[i]; j++)
      {
        card = (rand() % (countUpper - countLower + 1)) + countLower;
        G->hand[i][j] = tableCards[card];
        if (G->hand[i][j] == great_hall)
        {
          greatHallCounter++;
        }
      }
    }while(greatHallCounter == 0);

    for(j = 0; j < G->deckCount[i]; j++)
    {
      card = (rand() % (countUpper - countLower + 1)) + countLower;
      G->deck[i][j] = tableCards[card];
    }

    for(j = 0; j < G->discardCount[i]; j++)
    {
      card = (rand() % (countUpper - countLower + 1)) + countLower;
      G->discard[i][j] = tableCards[card];
    }
  }
}

int main()
{
  int i,
      j,
      k,
      returned,
      choice1 = 0,
      choice2 = 0,
      choice3 = 0,
      upper = 26,
      lower = 0,
      seed = 1000,
      handPos;
  srand(time(NULL));

  for(i = 0; i < 50; i ++)
  {
    printf("\nTurn #%d\n", (i+1));
    struct gameState G;
    struct gameState G2;
    randomGameInitialize(seed, &G);
    randomGameState(&G);
  

/************************************************************
 * TESTS
 * *********************************************************/
    for(j = 0; j < G.numPlayers; j++)
    {
      printf("\nPlayer %d\n", (j+1));
      G.playedCardCount = 0;
      G.numActions = 0;
      G.whoseTurn = j;
      
      choice1 = (rand() % (upper - lower + 1)) + lower;
      choice2 = (rand() % (upper - lower + 1)) + lower;
      choice3 = (rand() % (upper - lower + 1)) + lower;

      G2 = G;

      for(k = 0; k < G.handCount[j]; k++)
      {
        if(G.hand[j][k] == great_hall)
	{
          handPos = k;
	  break;
	}
      }

      returned = cardEffect(great_hall, choice1, choice2, choice3, &G, handPos, NULL);

      if(G.handCount[j] == G2.handCount[j])
      {
	printf("Correctly draw 1 card: PASSED\n");
      }
      else
      {
        printf("Correctly draw 1 card: FAILED\n");
      }

      if(G.playedCardCount == 1)
      {
        printf("Correctly played card: PASSED\n");
      }
      else
      {
        printf("Correctly played card: FAILED\n");
      }

      if(G.playedCards[0] == great_hall)
      {
        printf("Correctly played great hall card: PASSED\n");
      }
      else
      {
        printf("Correctly played great hall card: FAILED\n");
      }

      if(G.numActions == 1)
      {
        printf("Correctly increased number of actions: PASSED\n");
      }
      else
      {
        printf("Correctly increased number of actions: FAILED\n");
      }
    }
  }
  printf("RANDOM TEST - GREAT HALL CARD\n***********************************************************************************************************************************\n");
}

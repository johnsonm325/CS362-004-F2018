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
  int i,
      upper = 26,
      lower = 8,
      numPlayers;
      
  randomize(k, 10, upper, lower);
  k[0] = adventurer; 

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
      treasureCount;

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
    G->handCount[i] = (rand() % (countUpper - countLower + 1)) + countLower;
    do
    {
      G->deckCount[i] = (rand() % (countUpper - countLower + 1)) + countLower;
      G->discardCount[i] = (rand() % (countUpper - countLower + 1)) + countLower;
    }while((G->deckCount[i] + G->discardCount[i]) < 2);

    for(j = 0; j < G->handCount[i]; j++)
    {
      card = (rand() % (countUpper - countLower + 1)) + countLower;
      G->hand[i][j] = tableCards[card];
    }

    do
    {
      treasureCount = 0;
      for(j = 0; j < G->deckCount[i]; j++)
      {
        card = (rand() % (countUpper - countLower + 1)) + countLower;
        G->deck[i][j] = card;
	if(G->deck[i][j] == copper || G->deck[i][j] == silver || G->deck[i][j] == gold)
	{
          treasureCount++;
	}
      }

      for(j = 0; j < G->discardCount[i]; j++)
      {
        card = (rand() % (countUpper - countLower + 1)) + countLower;
        G->discard[i][j] = card;
	if(G->discard[i][j] == copper || G->discard[i][j] == silver || G->discard[i][j] == gold)
	{
          treasureCount++;
	}
      }
    }while(treasureCount < 2);
  }
}

int main()
{
  int i,
      j,
      k,
      returned,
      treasureCounter,
      choice1 = 0,
      choice2 = 0,
      choice3 = 0,
      upper = 26,
      lower = 0,
      seed = 1000;
  srand(time(NULL));

  for(i = 0; i < 100; i ++)
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
      treasureCounter = 0;
      G.whoseTurn = j;

      choice1 = (rand() % (upper - lower + 1)) + lower;
      choice2 = (rand() % (upper - lower + 1)) + lower;
      choice3 = (rand() % (upper - lower + 1)) + lower;

      G2 = G;
      returned = cardEffect(adventurer, choice1, choice2, choice3, &G, 0, NULL);

      for(k = 0; k < G2.deckCount[j]; k++)
      {
        treasureCounter++;
      }

      if(treasureCounter > 1)
      {
        if(G.handCount[j] == (G2.handCount[j] + 2))
	{
          if((G.hand[j][G.handCount[j]-1] > 3 && G.hand[j][G.handCount[j]-1] < 7) && (G.hand[j][G.handCount[j]-2] > 3 && G.hand[j][G.handCount[j]-2] < 7))
	  {
            printf("Two treasure cards in deck - added to hand: PASSED\n");
	  }
	  else
	  {
            printf("Two treasure cards in deck - added to hand: FAILED\n");
	  }
	}
	else
	{
	  printf("Treasure cards correctly added to hand from deck: FAILED\n");
	}
      }

      else
      {
        printf("Less than 2 treasure cards in deck\n");

        if((G.hand[j][G.handCount[j]-1] > 3 && G.hand[j][G.handCount[j]-1] < 7) && (G.hand[j][G.handCount[j]-2] > 3 && G.hand[j][G.handCount[j]-2] < 7))
	{
          printf("Deck had no treasure cards, shuffled first: PASSED\n");
	}
        else if((G.hand[j][G.handCount[j]-1] > 3 && G.hand[j][G.handCount[j]-1] < 7) && (G.hand[j][G.handCount[j]-2] != 4 && G.hand[j][G.handCount[j]-2] != 5 && G.hand[j][G.handCount[j]-2] != 6))
	{
          printf("Deck 1 treasure card, shuffled after drawing first card: PASSED\n");
	}
	else
	{
          printf("Shuffle failed\n");
	}

      }
    
    }
  }
  printf("RANDOM TEST - ADVENTURER CARD\n***********************************************************************************************************************************\n");
}

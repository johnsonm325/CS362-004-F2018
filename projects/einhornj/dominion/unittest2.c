/********************************************
 * Michael Johnson
 * Assignment 3
 * CS362 - Fall 2018
 * *****************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

void resetSupplyCount(struct gameState*);

void resetSupplyCount(struct gameState *G)
{
  int i;

  for(i = 0; i < 25; i++)
  {
    G->supplyCount[i] = 10;
  }
}

int main()
{
  int i,
  j,
  a,
  b,
  c,
  seed = 1000,
  numPlayer = 2,
  p,
  r,
  k[10] = {adventurer, council_room, feast, gardens, mine,
           remodel, smithy, village, baron, great_hall},
  maxHandCount = 5;
  struct gameState G;
  srand(time(0));

  memset(&G, 23, sizeof(struct gameState));
  r = initializeGame(numPlayer, k, seed, &G);

/*********************************************************
 * Check that the game isn't over
 * ******************************************************/
  p = isGameOver(&G);

  if(p == 0)
  {
    printf("isGameOver correctly returns 0: PASSED\n");
  }
  else printf("isGameOver correctly returns 0: FAILED\n");

/*********************************************************
 * Check that the Province supply count is at 0
 * ******************************************************/
  G.supplyCount[3] = 0;
  
  p = isGameOver(&G);

  if(p == 1)
  {
    printf("Stack of province cards are empty and game correctly ends: PASSED\n");
  }
  else printf("Stack of province cards are empty and game correctly ends: FAILED\n");

/*********************************************************
 * Check that the Province supply count is at 0
 * ******************************************************/
  for(i = 0; i < 10; i++)
  {
    do
    {
      a = rand() % 25;
    }while (a == 3);
    
    do
    {
      b = rand() % 25;
    }while(b == a || b == 3);

    do
    {
      c = rand() % 25;
    }while(c == a || c == b || c == 3);
 
    resetSupplyCount(&G);

    G.supplyCount[a] = 0;
    G.supplyCount[b] = 0;
    G.supplyCount[c] = 0;

    p = isGameOver(&G);

    if(p == 1)
    {
      printf("isGameOver correctly detect supply piles %d, %d and %d are empty: PASSED\n", a, b, c);
    }
    else printf("isGameOver correctly detect supply piles %d, %d and %d are empty: FAILED\n", a, b, c);
  }
}  

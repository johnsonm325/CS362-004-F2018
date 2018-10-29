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

int main()
{
  struct gameState G;
  int i,
      choice1 = 0,
      choice2 = 0,
      choice3 = 0,
      numPlayers = 2,
      seed = 1000,
      returned,
      test1[3],
      test2[2],
      testCounter = 0,
      k[10] = {adventurer, council_room, feast, gardens, mine,
               remodel, smithy, village, baron, great_hall};

  initializeGame(numPlayers, k, seed, &G);


/************************************************************
 * TESTS
 * *********************************************************/

  // Check for empty deck
  printf("TEST 1: If player 1 deck is empty, will shuffle cards.\n");
  G.deckCount[0] = 0;
  G.discardCount[0] = 5;
  
  //printf("deckCount: %d\n", G.deckCount[0]);
  //printf("discardCount: %d\n", G.discardCount[0]);

  for(i = 0; i < G.discardCount[0]; i++)
  {
    G.discard[0][i] = 4;
  }

  for(i = 0; i < G.handCount[0]; i++)
  {
    G.hand[0][i] = 4;
  }

  returned = cardEffect(adventurer, choice1, choice2, choice3, &G, 0, NULL);
  
  if(returned == 0)
  {
    printf("Function returns 0: PASSED\n");
  }
  else printf("Function returns 0: FAILED\n");

  for(i = 0; i < 3; i++)
  {
    test1[i] = 4;
  }

  for(i = 0; i < G.deckCount[0]; i++)
  {
    if(test1[i] == G.deck[0][i])
    {
      testCounter++;
    }
  }

  if(testCounter == 3)
  {
    printf("Three coins remain in deck and top 2 coin cards were removed: PASSED\n");
  }
  else printf("Three coins remain in deck and top 2 coin cards were removed: FAILED\n");


  // Check that cards have been removed from hand
  if(G.handCount[0] == 7)
  {
    printf("Hand count is 7: PASSED\n");
  }
  else printf("Hand count is 7: FAILED\n");

  if (G.discardCount[0] == 0)
  {
    printf("Discard count is 0: PASSED\n");
  }
  else printf("Discard count is 0: FAILED\n");
  printf("\n");

  printf("TEST 2: If player draws non coin card, will discard.\n");
  G.handCount[0] = 5;
  G.discardCount[0] = 0;
  G.deckCount[0] = 5;

  G.deck[0][0] = 4;
  G.deck[0][1] = 4;
  G.deck[0][2] = 4;
  G.deck[0][3] = 7;
  G.deck[0][4] = 7;

  returned = cardEffect(adventurer, choice1, choice2, choice3, &G, 0, NULL);

  if (returned == 0)
  {
    printf("Function returns 0: PASSED\n");
  }
  else printf("Function returns 0: FAILED\n");

  if(G.handCount[0] == 7)
  {
    printf("Hand count is 7: PASEED\n");
  }
  else printf("Hand count is 7: FAILED\n");

  if(G.discardCount[0] == 2)
  {
    printf("Discard count is 2 and contains non-coin cards: PASSED\n");
  }
  else printf("Discard count is 2 and contains non-coin cards: FAILED\n");


  for(i = 0; i < 2; i++)
  {
    test2[i] = 7;
  }

  testCounter = 0;
  for(i = 0; i < G.discardCount[0]; i++)
  {
    if(test2[i] == G.discard[0][i]);
    {
      testCounter++;
    }
  }

  if (testCounter == 2)
  {
    printf("Discard count is 2: PASSED\n");
  }
  else printf("Discard count is 2: FAILED\n");
  
  
  if(G.deckCount[0] == 1)
  {
    printf("Deck count is 1: PASSED\n");
  }
  else printf("Deck count is 1: FAILED\n");
  printf("\n");
}

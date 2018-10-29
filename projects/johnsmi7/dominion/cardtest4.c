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
      test1[4],
      testCounter = 0,
      k[10] = {adventurer, council_room, feast, gardens, mine,
               remodel, smithy, village, baron, great_hall};

  initializeGame(numPlayers, k, seed, &G);


/************************************************************
 * TESTS
 * *********************************************************/

  // Check for empty deck
  printf("TEST 1: If player deck has cards, will draw 1 card into hand and add an action.\n");
  G.playedCardCount = 0;
  
  for(i = 0; i < G.handCount[0]; i++)
  {
    G.hand[0][i] = 4;
  }
  G.hand[0][4] = 23;
  
  returned = cardEffect(outpost, choice1, choice2, choice3, &G, 4, NULL);

  if(returned == 0)
  {
    printf("Function returns 0: PASSED\n");
  }
  else printf("Function returns 0: FAILED\n");

  for(i = 0; i < 4; i++)
  {
    test1[i] = 4;
  }

  for(i = 0; i < G.handCount[0]; i++)
  {
    if(test1[i] == G.hand[0][i])
    {
      testCounter++;
    }
  }

  if(testCounter == 4)
  {
    printf("Four cards remain in hand and Outpost card was removed: PASSED\n");
  }
  else printf("Four cards remain in hand and Outpost card was removed: FAILED\n");

  if(G.playedCardCount == 1)
  {
    printf("Outpost card was played: PASSED\n");
  }
  else printf("Outpost card was played: FAILED\n");

  if(G.outpostPlayed == 1)
  {
    printf("Outpost flag set: PASSED\n");
  }
  else printf("Outpost flag set: FAILED\n");
  printf("\n");

  // Check for empty deck
  printf("TEST 2: If player has Outpost in middle of deck, will correctly remove.\n");
  G.handCount[0] = 5;
  G.playedCardCount = 0;
  G.outpostPlayed = 0;
  
  for(i = 0; i < G.handCount[0]; i++)
  {
    G.hand[0][i] = 4;
  }
  G.hand[0][2] = 23;
  
  returned = cardEffect(outpost, choice1, choice2, choice3, &G, 2, NULL);
  
  if(returned == 0)
  {
    printf("Function returns 0: PASSED\n");
  }
  else printf("Function returns 0: FAILED\n");

  testCounter = 0;

  for(i = 0; i < G.handCount[0]; i++)
  {
    if(test1[i] == G.hand[0][i])
    {
      testCounter++;
    }
  }

  if(testCounter == 4)
  {
    printf("Four cards in hand and Outpost card was removed: PASSED\n");
  }
  else printf("Four cards in hand and Outpost card was removed: FAILED\n");
  
  if(G.playedCardCount == 1)
  {
    printf("Outpost card was played: PASSED\n");
  }
  else printf("Outpost card was played: FAILED\n");
  
  if(G.outpostPlayed == 1)
  {
    printf("Outpost flag set: PASSED\n");
  }
  else printf("Outpost flag set: FAILED\n");
  printf("\n");
}

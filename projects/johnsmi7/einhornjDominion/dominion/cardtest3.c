/**********************************************************
 * Michael Johnson
 * Assignment 3
 * CS362 - Fall 2018
 * *******************************************************/

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
      test1[2],
      test2[7],
      testCounter = 0,
      k[10] = {adventurer, council_room, feast, gardens, mine,
               remodel, smithy, village, baron, great_hall};

  initializeGame(numPlayers, k, seed, &G);


/************************************************************
 * TESTS
 * *********************************************************/

  // Check for empty deck
  printf("TEST 1: If player deck has cards, will draw 1 card into hand and add an action.\n");
  G.deckCount[0] = 5;
  G.playedCardCount = 0;
  
  for(i = 0; i < G.deckCount[0]; i++)
  {
    G.deck[0][i] = 4;
  }
  
  for(i = 0; i < G.handCount[0]; i++)
  {
    G.hand[0][i] = 4;
  }
  G.hand[0][4] = 16;
  
  returned = cardEffect(great_hall, choice1, choice2, choice3, &G, 4, NULL);

  if(returned == 0)
  {
    printf("Function returns 0: PASSED\n");
  }
  else printf("Function returns 0: FAILED\n");

  for(i = 0; i < 4; i++)
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

  if(testCounter == 4)
  {
    printf("Four cards remain in deck and top card was removed: PASSED\n");
  }
  else printf("Four cards remain in deck and top card was removed: FAILED\n");

  testCounter = 0;
  for(i = 0; i < 5; i++)
  {
    test2[i] = 4;
  }
  
  for(i = 0; i < G.handCount[0]; i++)
  {
    if(test2[i] == G.hand[0][i])
    {
      testCounter++;
    }
  }

  if(testCounter == 5)
  {
    printf("Five cards in hand, Great Hall card was removed: PASSED\n");
  }
  else printf("Five cards in hand and Great Hall card was removed: FAILED\n");
  
  if(G.playedCardCount == 1)
  {
    printf("Great Hall card was played: PASSED\n");
  }
  else printf("Great Hall card was played: FAILED\n");

  if(G.numActions == 2)
  {
    printf("One action added: PASSED\n");
  }
  else printf("One action added: FAILED\n");
  printf("\n");

  // Check for empty deck
  printf("TEST 2: If player has Great Hall in middle of deck, will correctly remove.\n");
  G.handCount[0] = 5;
  G.deckCount[0] = 5;
  G.playedCardCount = 0;
  G.numActions = 1;
  
  for(i = 0; i < G.deckCount[0]; i++)
  {
    G.deck[0][i] = 4;
  }
  
  for(i = 0; i < G.handCount[0]; i++)
  {
    G.hand[0][i] = 4;
  }
  G.hand[0][2] = 16;
  
  returned = cardEffect(great_hall, choice1, choice2, choice3, &G, 2, NULL);
  
  if(returned == 0)
  {
    printf("Function returns 0: PASSED\n");
  }
  else printf("Function returns 0: FAILED\n");

  for(i = 0; i < 4; i++)
  {
    test1[i] = 4;
  }

  testCounter = 0;
  for(i = 0; i < G.deckCount[0]; i++)
  {
    if(test1[i] == G.deck[0][i])
    {
      testCounter++;
    }
  }

  if(testCounter == 4)
  {
    printf("Four cards remain in deck and top card was removed: PASSED\n");
  }
  else printf("Four cards remain in deck and top card was removed: FAILED\n");

  testCounter = 0;
  for(i = 0; i < 5; i++)
  {
    test2[i] = 4;
  }

  for(i = 0; i < G.handCount[0]; i++)
  {
    if(test2[i] == G.hand[0][i])
    {
      testCounter++;
    }
  }

  if(testCounter == 5)
  {
    printf("Five cards in hand and Great Hall card was removed: PASSED\n");
  }
  else printf("Five cards in hand and Great Hall card was removed: FAILED\n");
  
  if(G.playedCardCount == 1)
  {
    printf("Great Hall card was played: PASSED\n");
  }
  else printf("Great Hall card was played: FAILED\n");
  
  if(G.numActions == 2)
  {
    printf("One action added: PASSED\n");
  }
  else printf("One action added: FAILED\n");
  printf("\n");
}

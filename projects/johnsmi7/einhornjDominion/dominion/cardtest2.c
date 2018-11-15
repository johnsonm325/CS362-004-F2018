/***************************************************
 * Michael Johnson
 * Assignment 3
 * CS362 - Fall 2018
 * ************************************************/

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
  printf("TEST 1: If player deck has 3 cards, will draw 3 cards into hand.\n");
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
  G.hand[0][4] = 13;
  
  returned = cardEffect(smithy, choice1, choice2, choice3, &G, 4, NULL);
  
  if(returned == 0)
  {
    printf("Function returns 0: PASSED\n");
  }
  else printf("Function returns 0: FAILED\n");

  for(i = 0; i < 2; i++)
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

  if(testCounter == 2)
  {
    printf("Two cards remain in deck and top 3 cards were removed: PASSED\n");
  }
  else printf("Two cards remain in deck and top 3 cards were removed: FAILED\n");

  testCounter = 0;
  for(i = 0; i < 7; i++)
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

  if(testCounter == 7)
  {
    printf("Seven cards now in hand and smithy card was removed: PASSED\n");
  }
  else printf("Seven cards now in hand and smithy card was removed: FAILED\n");
  
  if(G.playedCardCount == 1)
  {
    printf("Smithy card was played: PASSED\n");
  }
  else printf("Smithy card was played: FAILED\n");
  printf("\n");


  // Check for empty deck
  printf("TEST 2: If player has smithy in middle of deck, will correctly remove.\n");
  G.handCount[0] = 5;
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
  G.hand[0][2] = 13;
  
  returned = cardEffect(smithy, choice1, choice2, choice3, &G, 2, NULL);
  
  if(returned == 0)
  {
    printf("Function returns 0: PASSED\n");
  }
  else printf("Function returns 0: FAILED\n");

  for(i = 0; i < 2; i++)
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

  if(testCounter == 2)
  {
    printf("Two cards remain in deck and top 3 cards were removed: PASSED\n");
  }
  else printf("Two cards remain in deck and top 3 cards were removed: FAILED\n");

  testCounter = 0;
  for(i = 0; i < 7; i++)
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

  if(testCounter == 7)
  {
    printf("Seven cards now in hand and smithy card was removed: PASSED\n");
  }
  else printf("Seven cards now in hand and smithy card was removed: FAILED\n");
  
  if(G.playedCardCount == 1)
  {
    printf("Smithy card was played: PASSED\n");
  }
  else printf("Smithy card was played: FAILED\n");
  printf("\n");
}

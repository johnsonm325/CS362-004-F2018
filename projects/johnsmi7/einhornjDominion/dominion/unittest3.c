/*******************************************
 * Michael Johnson
 * Assignment 3
 * CS362 - Fall 2018
 * ****************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

int main()
{
  int a;
  int b;
  int i;
  int result;
  int upper = 100;
  int lower = -100;

  srand (time(0));

  for (i = 0; i < 50; i++)
  {
    a = (rand() % (upper - lower + 1)) + lower;
    b = (rand() % (upper - lower + 1)) + lower;

    result = compare(&a, &b);
    
    if (a > b)
    {
      if(result == 1)
      {
        printf("Compare correctly determines %d > %d: PASSED\n", a, b);
      }
      else printf("Compare correctly determines %d > %d: FAILED\n", a, b);
      
    }
    else if (a < b)
    {
      if(result == -1)
      {
        printf("Compare correctly determines %d < %d: PASSED\n", a, b);
      }
      else printf("Compare correctly determines %d < %d: FAILED\n", a, b);
    }
    else
    {
      if(result == 0)
      {
        printf("Compare correctly determines %d == %d: PASSED\n", a, b);
      }
      else printf("Compare correctly determines %d == %d: FAILED\n", a, b);
    }
  }
  return 0;
}

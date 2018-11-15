/*****************************************
 * Michael Johnson
 * Assignment 3
 * CS362 - Fall 2018
 * **************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rngs.h"

int main()
{
  int card;
  int i;
  int result;

  for (i = 0; i < 28; i++)
  {
    result = getCost(i);

    if (i == 0 || i == 4)
    {
      if(result == 0)
      {
        printf("Cost of 0 successfully returned: SUCCESS\n");
      }
      else printf("Cost of 0 successfully returned: FAILED\n");
    }
    else if(i == 1 || i == 22)
    {
      if(result == 2)
      {
        printf("Cost of 2 successfully returned: SUCCESS\n");
      }
      else printf("Cost of 2 successfully returned: FAILED\n");
    }
    else if(i == 2 || i == 8 || i == 11 || i == 17 || i == 19 || i == 23)
    {
      if(result == 5)
      {
        printf("Cost of 5 successfully returned: SUCCESS\n");
      }
      else printf("Cost of 5 successfully returned: FAILED\n");
    }
    else if(i == 3)
    {
      if(result == 8)
      {
        printf("Cost of 8 successfully returned: SUCCESS\n");
      }
      else printf("Cost of 8 successfully returned: FAILED\n");
    }
    else if(i == 5 || i == 14 || i == 16 || i == 18 || i == 20)
    {
      if(result == 3)
      {
        printf("Cost of 3 successfully returned: SUCCESS\n");
      }
      else printf("Cost of 3 successfully returned: FAILED\n");
    }
    else if(i == 6 || i == 7)
    {
      if(result == 6)
      {
        printf("Cost of 6 successfully returned: SUCCESS\n");
      }
      else printf("Cost of 6 successfully returned: FAILED\n");
    }
    else if(i == 9 || i == 10 || i == 12 || i == 13 || i == 15 || i == 21 || i == 24 || i == 25 || i == 26)
    {
      if(result == 4)
      {
        printf("Cost of 4 successfully returned: SUCCESS\n");
      }
      else printf("Cost of 4 successfully returned: FAILED\n");
    }
    else
    {
      if(result == -1)
      {
        printf("Card does not exist");
      }
    }
  }
}

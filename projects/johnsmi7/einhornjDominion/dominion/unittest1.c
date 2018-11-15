/***********************************************
 * Michael Johnson
 * Assignment 3
 * CS362 - Fall 2018
 * ********************************************/

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

void randomize(int*, int, int, int);

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


int main()
{
  int i,
      a,
      original[10],
      *returned,
      upper = 26,
      lower = 7,
      testCounter = 0;

  srand(time(0));

  randomize(original, 10, upper, lower);

  returned = kingdomCards(original[0], original[1], original[2], original[3], original[4],
                          original[5], original[6], original[7], original[8], original[9]);

  printf("Testing kingdomCards:\n");

  for (i = 0; i < 10; i++)
  {
    if (original[i] == returned[i])
    {
      testCounter++;
    }
  }

  if (testCounter == 10)
  {
    printf("PASSED:\n");
    printf("Expected: [%d, %d, %d, %d, %d, %d, %d, %d, %d, %d]\n", 
            original[0], original[1], original[2], original[3], original[4],
            original[5], original[6], original[7], original[8], original[9]);

    printf("Actual: [%d, %d, %d, %d, %d, %d, %d, %d, %d, %d]\n", 
            returned[0], returned[1], returned[2], returned[3], returned[4],
            returned[5], returned[6], returned[7], returned[8], returned[9]);
  }
  else
  {
    printf("FAILED:\n");
    printf("Expected: [%d, %d, %d, %d, %d, %d, %d, %d, %d, %d]\n", 
            original[0], original[1], original[2], original[3], original[4],
            original[5], original[6], original[7], original[8], original[9]);

    printf("Actual: [%d, %d, %d, %d, %d, %d, %d, %d, %d, %d]\n", 
            returned[0], returned[1], returned[2], returned[3], returned[4],
            returned[5], returned[6], returned[7], returned[8], returned[9]);
  }
}

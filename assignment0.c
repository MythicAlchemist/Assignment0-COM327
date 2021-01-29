/*
@author Thomas McCoy & Jens Rasmussen
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define ARRAY_SIZE 5

//Function Headers

void print_map(int (*pileArr)[ARRAY_SIZE][ARRAY_SIZE]);
void rec_check(int (*pileArr)[ARRAY_SIZE][ARRAY_SIZE], int col, int row);
void helper(int (*pileArr)[ARRAY_SIZE][ARRAY_SIZE], int col, int row);

//Main
int main(int argc, char *argv[])
{
  int pileArr[ARRAY_SIZE][ARRAY_SIZE]; 
  for(int i = 0; i < ARRAY_SIZE; i++){
    for(int j = 0; j < ARRAY_SIZE; j++){
      pileArr[i][j] = 0;
    }
  }
  while(true){
    pileArr[ARRAY_SIZE / 2][ARRAY_SIZE / 2] += 1;
    rec_check((&pileArr), ARRAY_SIZE / 2, ARRAY_SIZE / 2);
    print_map(&pileArr);
  }
  return 0;
}

// Recursive
void rec_check(int (*pileArr)[ARRAY_SIZE][ARRAY_SIZE], int col, int row) 
{
  int j, i;

  for (j = -1; j <= 1; j++) {
    for (i = -1; i <= 1; i++) {
      if ((*pileArr)[j + col][i + row] > 8) {
        rec_check((pileArr), (j + col), (i + row));
      }
    }
  }
   helper((pileArr), j, i);
   (*pileArr)[col][row] = 1;
}

// Helper
void helper(int (*pileArr)[ARRAY_SIZE][ARRAY_SIZE], int col, int row)
{
  int j, i;
  
  for (j = -1; j <= 1; j++) {
    for (i = -1; i <= 1; i++) {
      if(!((j + col) < 0 || (j + col) > ARRAY_SIZE || (i + row) < 0 || (i + row) > ARRAY_SIZE)){
	printf("%d \n", *pileArr[1][2]);
	*pileArr[col + j][row + i] += 1;
      }
    }
  }
}

//Function prints the map of sand piles
void print_map(int (*pileArr)[ARRAY_SIZE][ARRAY_SIZE])
{
  int j, i;

  for(j = 0; j < ARRAY_SIZE; j++){
    for(i = 0; i < ARRAY_SIZE; i++){
      printf("%1d ", (*pileArr)[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}

/*
@author Thomas McCoy & Jens Rasmussen
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ARRAY_SIZE 5

//Function Headers
void print_map(int pileArr[ARRAY_SIZE][ARRAY_SIZE]);
void rec_check(int pileArr[ARRAY_SIZE][ARRAY_SIZE], int i, int j);
int *helper(int pileArr[ARRAY_SIZE][ARRAY_SIZE], int i, int j);

//Main
int main(int argc, char *argv[])
{
  int pileArr[ARRAY_SIZE][ARRAY_SIZE];
  int i, j;

  for(i = 0; i < ARRAY_SIZE / 2; i++) {
    for(j = 0; j < ARRAY_SIZE / 2; j++) {
      pileArr[i][j] = 0;
    }
  }
  
  while(1)
  {
    pileArr[ARRAY_SIZE / 2][ARRAY_SIZE / 2] += 1;
    rec_check(pileArr, ARRAY_SIZE / 2, ARRAY_SIZE / 2);
    print_map(pileArr);
  }
  
  return 0;
}
/*
//Function checks and topples piles of sand
void check_sand(int pileArr[ARRAY_SIZE][ARRAY_SIZE])
{
  int i, j, l, m;
  
  while(1){
    for(j = 0; j < ARRAY_SIZE; j++) {
      for (i = 0; i < ARRAY_SIZE; i++) {
        if(pileArr[j][i] > 8) {
          for(l = j - 1; l <= 1; l++)
            pileArr[j][i] = 1;
        }
      }
    }
    
  }
}
*/
// Recursive
void rec_check(int pileArr[ARRAY_SIZE][ARRAY_SIZE], int i, int j) 
{
  int m, n;

  for (m = -1; m <= 1; m++) {
    for (n = -1; n <= 1; n++) {
        if (pileArr[m + j][n + i] > 8) {
          rec_check(helper(pileArr[ARRAY_SIZE][ARRAY_SIZE], (n + i), (m + j)), (n + i), (m + j));
        }
    }
  }
}

// Helper
int *helper(int pileArr[ARRAY_SIZE][ARRAY_SIZE], int i, int j) 
{
  int m, n;

  for (m = -1; m <= 1; m++) {
    for (n = -1; n <= 1; n++) {
      pileArr[m + j][n + i] += 1; // Seg fault
    }
  }
  pileArr[i][j] = 1;

  return 0;
}

//Function prints the map of sand piles
void print_map(int pileArr[ARRAY_SIZE][ARRAY_SIZE])
{
  int i, j;

  for(j = 0; j < ARRAY_SIZE; j++){
    for(i = 0; i < ARRAY_SIZE; i++){
      printf("%4d ", pileArr[j][i]);
    }
    printf("\n");
  }
  printf("----------------\n");
}

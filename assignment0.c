/*
@author Thomas McCoy & Jens Rasmussen
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ARRAY_SIZE 23

//Function Headers
void check_sand(int pileArr[ARRAY_SIZE][ARRAY_SIZE]);
void print_map(int pileArr[ARRAY_SIZE][ARRAY_SIZE]);

//Main
int main(int argc, char *argv[])
{
  int pileArr[ARRAY_SIZE][ARRAY_SIZE];
  
  while(1)
  {
    pileArr[ARRAY_SIZE / 2][ARRAY_SIZE / 2] += 1;
    check_sand(pileArr);
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
void rec_check(int pileArr[ARRAY_SIZE][ARRAY_SIZE]) 
{
  int j, i;

  for (j = 0; j < 3; j++) {
    for (i = 0; i < 3; i++) {
      if (!(i == 2 && j == 2)) {
        if (pileArr[j][i] < 9) {
          break;
        } 
        else {
          rec_check(helper(pileArr[j][i]));
        }
      }
    }
  }
}

// Helper
int helper(int pileArr[ARRAY_SIZE][ARRAY_SIZE]) {
  int j, i;
  
  for (j = 0; j < 3; j++) {
    for (i = 0; i < 3; i++) {
      pileArr[j][i] += 1;
    }
  }
  return ;
}

//Function prints the map of sand piles
void print_map(int pileArr[ARRAY_SIZE][ARRAY_SIZE])
{
  int i, j;

  for(j = 0; j < 10; j++){
    for(i = 0; i < 10; i++){
      printf("%d ", pileArr[j][i]);
    }
    printf("\n");
  }
}

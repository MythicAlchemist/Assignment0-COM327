/*
@author Thomas McCoy & Jens Rasmussen
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

#define ARRAY_SIZE 5
#define DEFAULT_FPS 20

//Function Headers
void print_map(int (*pileArr)[ARRAY_SIZE][ARRAY_SIZE]);
void rec_check(int (*pileArr)[ARRAY_SIZE][ARRAY_SIZE], int col, int row);
void helper(int (**pileArr)[ARRAY_SIZE][ARRAY_SIZE], int col, int row);

//Main
int main(int argc, char *argv[])
{
  int pileArr[ARRAY_SIZE][ARRAY_SIZE];
  int i, j, k, fps;
  //Makes sure that all values in array are in fact 0
  for(int i = 0; i < ARRAY_SIZE; i++){
    for(int j = 0; j < ARRAY_SIZE; j++){
      pileArr[i][j] = 0;
    }
  }
  //Checks what the fps should be
  if(argv[1] != NULL && !strcmp(argv[1], "--fps")){
    fps = atoi(argv[2]);
    k = 3;
  }
  else{
    fps = DEFAULT_FPS;
    k = 1;
  }
  //Checks argv values for salt or sinks
  for(k; k < argc - 2;){
    if(atoi(argv[k + 2]) != -1){
      pileArr[atoi(argv[k])][atoi(argv[k + 1])] = atoi(argv[k + 2]);
    }
    else{
      pileArr[atoi(argv[k])][atoi(argv[k + 1])] = -1;
    }
    k += 3;
  }
  //Loop that controlls the simulation
  while(true){
    (pileArr)[ARRAY_SIZE / 2][ARRAY_SIZE / 2] += 1;
    rec_check((&pileArr), ARRAY_SIZE / 2, ARRAY_SIZE / 2);
    print_map((&pileArr));
    usleep(1000000 / fps);
    printf("%d fps \n", fps);
  }
  return 0;
}

// Recursive Function
void rec_check(int (*pileArr)[ARRAY_SIZE][ARRAY_SIZE], int col, int row) 
{
  int j, i;

  for (j = -1; j <= 1; j++) {
    for (i = -1; i <= 1; i++) {
      if ((*pileArr)[j + col][i + row] > 8) {
        helper((&pileArr), j + col, i + row);
        rec_check((pileArr), (j + col), (i + row));  
      }
    }
  }
}

// Recursive Helper
void helper(int (**pileArr)[ARRAY_SIZE][ARRAY_SIZE], int col, int row)
{
  int j, i;
  
  for (j = -1; j <= 1; j++) {
    for (i = -1; i <= 1; i++) {
      if(!((j + col) < 0 || (j + col) > ARRAY_SIZE || (i + row) < 0 || (i + row) > ARRAY_SIZE || (**pileArr)[col + j][row + i] == -1)){ //Checks "edge cases"
	      (**pileArr)[col + j][row + i] += 1;
      }
    }
  }
  (**pileArr)[col][row] -= 9;
}

//Function prints the map of sand piles
void print_map(int (*pileArr)[ARRAY_SIZE][ARRAY_SIZE])
{
  int j, i;

  for(j = 0; j < ARRAY_SIZE; j++){
    for(i = 0; i < ARRAY_SIZE; i++){
      if((*pileArr)[j][i] == -1){
        printf("# ");
      }
      else{
        printf("%1d ", (*pileArr)[j][i]);
      }
    }
    printf("\n");
  }
  printf("\n");
}

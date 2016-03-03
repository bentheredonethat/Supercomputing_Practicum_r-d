#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define ROW 2
#define COL 2
#define SECTOR_HEIGHT 1
#define SECTOR_WIDTH 1

#define NUM_THREADS 4

int array[ROW][COL] = {
  {0, 1},
  {2, 3}
};

// given row r and column c and thread ID t_id, you can map thread ID into region of array using following formula
// array(r,c) = array[r+m*t_id][c+m*t_id]
// in this case, m and n are sector height/width
void secureAccess(int threadID){
  for (int row = 0+(threadID/ROW); row < SECTOR_HEIGHT + (threadID/ROW); row++){
      for (int column = 0+(threadID/COL); column < SECTOR_WIDTH + (threadID%COL); column++){
    	int arrVal = array[row][column];
      printf("array value: %d, row: %d, col: %d, ThreadID: %d\n" , 
      	arrVal , row, column,threadID);
    }
  }
}
  
int main(int argc, char *argv[]){

//   omp_set_num_threads(NUM_THREADS);
// #pragma shared(array)
// #pragma omp parallel for

  for (int i = 0; i < NUM_THREADS; ++i)
    {
      printf("%d\n", i);
      secureAccess(i);
    }
  
  return 0;
}

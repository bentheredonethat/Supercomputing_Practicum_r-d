#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define ROW 2;
#define COL 2;

void secureAccess(int array[2][2], int threadID){
	// 1. Map threadID to location in array
	int row = threadID / ROW;
	int col = threadID % COL;
	
	// 2. Modify array based on this mapping
	printf("array value: %d, row: %d, col: %d, ThreadID: %d\n"
		, array[row][col], row, col, threadID);

}

int main(int argc, char *argv[]){
	int nthreads, tid;
	int array[ROW][COL] = {
		{0, 0},
		{0, 0}
	};

	#pragma omp parallel private(nthreads, tid)
	{

	tid = omp_get_thread_num();
	printf("Hello World from thead = %d\n", tid);
		if (tid == 0){
			nthreads = omp_get_num_threads();
			printf("Number of threads = %d\n", nthreads);
		}
	secureAccess(array, tid);
	}
	return 0;
}
#include<stdio.h>
#include "mpi.h"
#include<math.h>
#define x 2

int main(int argc,char*argv[])
{
	int rank;

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);
	int d=pow(x,rank);
	printf(" X = 2 raise to rank = %d is = %d\n",rank,d);

	MPI_Finalize();
	
	return 0;
}
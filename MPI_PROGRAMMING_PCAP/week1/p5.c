#include<stdio.h>
#include<string.h>
#include "mpi.h"


int main(int argc,char*argv[])
{
	int rank;
	char string[]="HeLLO";

	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);


	if(string[rank]>96 && string[rank]<127)
	{
		printf("RANK : %d\n",rank);
		string[rank]=string[rank]-32;
		printf("String is : %s\n",string);
	}	

	else if(string[rank]<90 && string[rank]>65)
	{
		printf("RANK : %d\n",rank);
		string[rank]=string[rank]+32;
		printf("String is : %s\n",string);
	}
	MPI_Finalize();
	return 0;
}
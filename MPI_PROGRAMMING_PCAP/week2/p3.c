#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int main(int argc,char**argv)
{
	int rank;
	MPI_Status st;
	int num,num1;
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	if(rank==0)
	{
		printf("The Master process :\n");
		for(int i=1;i<4;i++){
			printf("Enter the Number for Rank %d: \n",i);
			scanf("%d",&num);
			MPI_Send(&num,1,MPI_INT,i,1,MPI_COMM_WORLD);
		}
	}
	else
	{
		MPI_Recv(&num1,1,MPI_INT,0,1,MPI_COMM_WORLD,&st);
		printf("The Slave Rank is : %d\n",rank);
		printf("The Number Recieved  is : %d\n\n",num1);
	}
	MPI_Finalize();
	return 0;
}
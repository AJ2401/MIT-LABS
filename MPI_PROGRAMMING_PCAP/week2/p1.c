#include<stdio.h>
#include<mpi.h>
#include<string.h>
#define max 1024
int main(int argc,char**argv)
{
	MPI_Status st;
	int rank;
	char buff[max],arr[max];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	if(rank==0)
	{
		printf("RANK : %d",rank);
		printf("\t\t\tSENDER SIDE\n");
		printf("Enter the String : \n");
		scanf("%[^\n]s",buff);
		int a=strlen(buff);
		MPI_Send(&buff,a,MPI_CHAR,1,1,MPI_COMM_WORLD);
	}
	else
	{
		MPI_Recv(&arr,max,MPI_CHAR,0,1,MPI_COMM_WORLD,&st);
		int a=strlen(arr);
		arr[a+1]='\n';
		printf("RANK : %d",rank);
		printf("\t\t\tRECIEVER SIDE\n");
		printf("\nThe String is : \n%s\n",arr);
	}
	MPI_Finalize();
	return 0;
}
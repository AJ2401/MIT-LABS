#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>
#include<string.h>
#define max 25

int main(int argc,char**argv)
{
	int rank;
	MPI_Status st;
	MPI_Status st1;
	char buff[max],arr[max],nbuff[max];
	MPI_Init(&argc,&argv);
	MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	if(rank==0)
	{
		printf("RANK : %d",rank);
		printf("\t\t\tSENDER SIDE\n");
		printf("Enter the String : \n");
		scanf("%s",buff);
		int a=strlen(buff);
		MPI_Ssend(&buff,a,MPI_CHAR,1,1,MPI_COMM_WORLD);
		MPI_Recv(&nbuff,a,MPI_CHAR,1,0,MPI_COMM_WORLD,&st);
		nbuff[a+1]='\n';
		printf("\n\nTHE TOGGLED STRING IS : %s\n",nbuff);
	}
	else
	{
		MPI_Recv(&arr,max,MPI_CHAR,0,1,MPI_COMM_WORLD,&st1);
		printf("RANK : %d",rank);
		printf("\t\t\tRECIEVER SIDE\n");
		int a=strlen(arr);
		arr[a+1]='\n';
		printf("\n\nTHE STRING IS : %s\n",arr);
		for(int i=0;i<a;i++)
		{
			if(arr[i]>96 && arr[i]<123)
			{
				arr[i]=arr[i]-32;
			}
			else if(arr[i]>64 && arr[i]<91)
			{
				arr[i]=arr[i]+32;
			}
		}
		MPI_Ssend(&arr,a,MPI_CHAR,0,0,MPI_COMM_WORLD);
	}
	MPI_Finalize();
	return 0;

}
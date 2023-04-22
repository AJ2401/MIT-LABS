

#include<stdio.h>
#include "mpi.h"


int main(int argc,char*argv[])
{
	int a=1,b=7;
	int rank;
	int res;
	
		MPI_Init(&argc,&argv);
		MPI_Comm_rank(MPI_COMM_WORLD,&rank);

	if(rank==0)
	{
		printf("RANK = %d\n\n",rank);
		 printf("The value of a : %d\n",a);
		printf("The value of b : %d\n",b);
		res=a+b;
		printf("RESULT OF ADDITION IS : %d\n",res);

	}
	else if(rank==1)
	{
		printf("RANK = %d\n\n",rank);
		 printf("The value of a : %d\n",a);
		printf("The value of b : %d\n",b);
		if(a>b)
		{
			res=a-b;
		}
		else
		{
			res=b-a;
		}
		printf("RESULT OF SUBTRACTION IS : %d\n",res);

	}
	else if(rank==2)
	{
		printf("RANK = %d\n\n",rank);
		printf("The value of a : %d\n",a);
		printf("The value of b : %d\n",b);
		res=a*b;
		printf("RESULT OF MULTIPLICATION IS : %d\n",res);
	}
	else if(rank==3)
	{
		 printf("The value of a : %d\n",a);
		printf("The value of b : %d\n",b);
		printf("RANK = %d\n\n",rank);
		res=a/b;
		printf("RESULT OF DIVISION IS : %d\n",res);
	}
	else
	{
		printf("RANK = %d ??? \n\n",rank);
	}

	MPI_Finalize();
	return 0;
}
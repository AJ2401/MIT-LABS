#include<stdio.h>
#include<mpi.h>

int main(int argc,char**argv)
{
   int rank,size;
   int num;
   MPI_Init(&argc,&argv);
   MPI_Comm_rank(MPI_COMM_WORLD,&rank);
   MPI_Comm_size(MPI_COMM_WORLD,&size);
   int arr[size];

   if(rank==0)
   {
      printf("Enter the Elements : \n");
      for(int i=0;i<size;i++)
      {
         printf("Enter the Element : \n");
         scanf("%d",&arr[i]);
         `
      }
   }
   return 0;
}
// ARRAY Transfer
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
   int n;
   int fd;
   char filename[25];
   printf("Enter the FIFO File : \n");
   scanf("%s",filename);

   if(mkfifo(filename,0777)==-1)
   {
      printf("ERROR!\n");
   }

   fd=open(filename,O_WRONLY);

   if(fd==-1)
   {
      printf("ERROR!\n");
   }

   else{
      printf("Enter the Number of Array Size  : \n");
      scanf("%d",&n);
      int arr[n];
      write(fd,(void*)&n,sizeof(int));
      printf("Enter the Array Elements : \n");
      for(int i=0;i<n;i++)
      {
         printf("Enter the Element : %d \n",i+1);
         scanf("%d",&arr[i]);
         write(fd,(int*)&arr[i],sizeof(int));
      }
      printf("DONE!!\n");
 }


 return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>


int main()
{
   char filename[25];
   int fd,n;

   printf("Enter the Filename : \n");
   scanf("%s",filename);

   fd=open(filename,O_RDONLY);

   if(fd==-1)
   {
      printf("ERROR\n");
   }
   else{
      printf("The Array Size is : \n");
      read(fd,(void*)&n,sizeof(int));
      printf("\n%d\n",n);
      int arr[n];
      printf("The Array Elements are :\n");
      for(int i=0;i<n;i++)
      {
           read(fd,(int*)&arr[i],sizeof(int));
      }

       for(int i=0;i<n;i++)
      {
           printf("  %d  ",arr[i]);
      }
   }
   printf("DONE!!\n");
   close(fd);
   return 0;
}
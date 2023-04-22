#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#define max 1024*1024

int main()
{
   char filename[25],msg[max];
   printf("Enter the Filename : \n");
   scanf("%s",filename);
   
   int fd=open(filename,O_RDONLY);
   if(fd==-1)
   {
      printf("ERROR!\n");
      return 1;
   }
   else{
      read(fd,msg,max);
      printf("The MSG THROUGH FIFO IS : \n\n%s\n\n",msg);
      printf("DONE !!!\n\n");
   }

   return 0;
}
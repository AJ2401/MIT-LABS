#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#define max 1024

int main()
{
   int arr[2];
   char msg[max],buff[max];
   printf("Enter the Message : \n");
   scanf("%s",msg);

   pipe(arr);

   write(arr[1],msg,sizeof(msg));

   if(read(arr[0],buff,max)>0)
   {
      printf("The Message AFTER PIPE  is : %s\n",buff);
      return 0;
   }
   else{
      printf("ERROR");
      return 1;
   }
}
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#define max 1024*1024


int main()
{
   int fd;
   char msg[100],file[25];

   printf("Enter the Filename : \n");
   scanf("%s",file);
   if(mkfifo(file,0777)==-1)
   {
      printf("ERROR!!\n");
   }
   
   fd=open(file,O_WRONLY);
   if(fd==-1)
   {
      printf("ERROR!!\n");
      return 1;
   }
   else
   {
      printf("Enter the Message  : \n");
      fgets(msg,100,stdin);
     // gets(msg);
      write(fd,(void*)&msg,sizeof(msg));
      printf("DONE !!\n");
   }
   return 0;
}
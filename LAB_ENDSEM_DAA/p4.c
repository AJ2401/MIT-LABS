#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#define max 100


int main()
{
	char filename[25];
	int fd;
	printf("Enter the File : \n");
	scanf("%s",filename);
	if(mkfifo(filename,0777)==-1)
	{
		printf("ERROR!\n");
		return 1;
	}
	while(1)
	{
		fd=open(filename,O_WRONLY);
		char msg[max],buff[max];
		printf("Enter the Message Bro .. : \n");
		gets(msg);
		//fgets(msg,max,stdin);
		write(fd,msg,sizeof(msg));
		close(fd);
		fd=open(filename,O_RDONLY);
		read(fd,buff,max);
		printf("MESSAGE FROM S@ : %s\n",buff);
		close(fd);
	}
}
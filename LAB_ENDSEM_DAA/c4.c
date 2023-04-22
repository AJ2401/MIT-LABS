#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#define max 100


int main()
{
	int fd;
	char filename[25];
	printf("Enter the Filename : \n");
	scanf("%s",filename);
	while(1){
		fd=open(filename,O_RDONLY);
		char msg[max],buff[max];
		read(fd,buff,max);
		printf("MESSAGE RECIEVE FROM C@ : \n%s\n",buff);
		close(fd);
		fd=open(filename,O_WRONLY);
		printf("Enter the Message  : \n");
		gets(msg);
		//scanf("%[^\n]s",msg);
		//fgets(msg,max,stdin);
		write(fd,msg,sizeof(msg));
	}
}
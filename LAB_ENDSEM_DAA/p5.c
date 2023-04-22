#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#define max 100

int main()
{
	int n;
	int arr[2];
	char msg[max],buff[max];
	pipe(arr);

	while(1){
	int id=fork();
	if(id==0)
	{
		printf("\n--------------------\n");
		printf("IN CHILD \n");
		printf("Enter the Message : \n");
		fgets(msg,max,stdin);
		write(arr[1],msg,sizeof(msg));
		printf("DONE CHILD!!\n");
		sleep(1);
	}
	else
	{
		printf("\n--------------------\n");
		printf("\nIN PARENT : \n\n");
		read(arr[0],buff,max);
		printf("\n\nMESSGAE FROM CHILD is : \n%s\n",buff);
		printf("DONE PARENT!\n");
		sleep(2);
	}
}
}

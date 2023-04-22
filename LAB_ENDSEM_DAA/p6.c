#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>


int main()
{
	int n;
	int fd[2];
	printf("Enter the Size of the Array : \n");
	scanf("%d",&n);
	pipe(fd);
	int arr[n],buff[n];
	printf("Enter the Array Elements : \n");
	for(int i=0;i<n;i++)
	{
		printf("Enter the Element : %d\n",i+1);
		scanf("%d",&arr[i]);
		write(fd[1],(int*)&arr[i],sizeof(int));
	}
	printf("%d",arr[n-1]);
	printf("\n--------------------------------------------------\n\n");
	if(read(fd[0],buff,n)>0)
	{
		//read(fd[0],buff,n);
		for(int i=0;i<n;i++)
		{   
			read(fd[0],(int*)&buff[i],sizeof(int));		
		}
		for(int i=0;i<n;i++)
		{   
		  printf("%d",buff[i]);	
		}
		printf("DONE \n");
	}
}
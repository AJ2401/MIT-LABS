#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<sys/types.h>
#define port 1200

int main()
{
	int s;
	struct sockaddr_in add;
	s=socket(AF_INET,SOCK_DGRAM,0);
	add.sin_addr.s_addr=inet_addr("127.0.0.1");
	add.sin_port=htons(port);
	add.sin_family=AF_INET;
	int n;
	int len=sizeof(add);
	printf("Enter the Matrix Size : \n");
	scanf("%d",&n);
	sendto(s,&n,sizeof(n),0,(struct sockaddr*)&add,len);
	int buff[n][n];
	printf("Enter the Matrix : \n");
	for(int i=0;i<n;i++)
	{
		printf("Enter the Elements for Row :%d \n",i+1);
		for(int j=0;j<n;j++){
		printf("Enter the Element %d \n",j+1);
		scanf("%d",&buff[i][j]);

		}
	}
	int c=0;
	int arr[n];
	int rec,r;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			arr[j]=buff[i][j];
		}
		r=sendto(s,arr,sizeof(arr),0,(struct sockaddr*)&add,len);
		rec=recvfrom(s,arr,sizeof(arr),0,(struct sockaddr*)&add,&len);
	}
	return(0);
}
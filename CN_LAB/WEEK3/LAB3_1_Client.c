#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<arpa/inet.h>
#define port 8080

int main()
{
	int S;
	struct sockaddr_in address;

	S=socket(AF_INET,SOCK_DGRAM,0);
	address.sin_addr.s_addr=inet_addr("127.0.0.1");
	address.sin_family=AF_INET;
	address.sin_port=htons(port);
	int n;
	printf("Enter the Matrix Size :\n");
	scanf("%d",&n);
	int buff[n][n];
	int len=sizeof(address);
	int len1=sizeof(buff);
	int j;
	printf("Enter the MATRIX : \n");
	for(int i=0;i<n;i++)
	{
		printf("Enter Elements For Row : %d \n\n",i+1);
		for(j=0;j<n;j++)
			{
				printf("Enter Element %d ",j+1);
				scanf("%d",&buff[i][j]);
			}
	}
	//int num1=n;
	int c=0;
	int buff1[n];
	int rec,r;
	for(int i=0;i<n;i++){
	 for(int j=0;j<n;j++)
		{
			buff1[j]=buff[i][j];
		}
		r=sendto(S,buff1,sizeof(buff1),0,(struct sockaddr*)&address,len);
	    rec=recvfrom(S,buff1,sizeof(buff1),0,(struct sockaddr*)&address,&len);
	}
	return(0);
}

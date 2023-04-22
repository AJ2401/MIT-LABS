#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#define port 1200
#define max 5
int main()
{
	int s;
	int max1;
	struct sockaddr_in sadd,cadd;
	s=socket(AF_INET,SOCK_DGRAM,0);
	sadd.sin_addr.s_addr=inet_addr("127.0.0.1");
	sadd.sin_port=htons(port);
	sadd.sin_family=AF_INET;
	int res=bind(s,(struct sockaddr*)&sadd,sizeof(sadd));
	int len=sizeof(cadd);
	recvfrom(s,&max1,sizeof(max1),0,(struct sockaddr*)&cadd,&len);
	int buff[max1];
	while(1){
	int rec=recvfrom(s,buff,sizeof(buff),0,(struct sockaddr*)&cadd,&len);
	printf("The Server Got the Message !!\n");
	//int max1=sizeof(buff)/sizeof(int);
	for(int i=0;i<max1;i++)
	{
		printf(" %d ",buff[i]);
	}
	printf("\n");
	int sed=sendto(s,buff,sizeof(buff),0,(struct sockaddr*)&cadd,len);
	
	}
	return(0);
}

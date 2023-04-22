//UDP PROGRAMMING 
//MAKING SERVER
//HERE WE DONT HAVE NO ACCEPT() and LISTEN()
//INSTEAD WE HAVE RECIEVE() and SEND()
//Server.c
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<sys/socket.h>
#define port 8080
#define max 100
int main()
{
	//fflush("LAB3_1_Server.c");
	int S;
	int buff[max];
	struct sockaddr_in sadd,cadd;
	S=socket(AF_INET,SOCK_DGRAM,0);
	sadd.sin_addr.s_addr=inet_addr("127.0.0.1");
	sadd.sin_port=htons(port);
	sadd.sin_family=AF_INET;
	int res=bind(S,(struct sockaddr*)&sadd,sizeof(sadd));
	int len=sizeof(cadd);
	int r=recvfrom(S,buff,sizeof(buff),0,(struct sockaddr*)&cadd,&len);
	printf("The server Got the Message is : \n");
	int max1=sizeof(buff)/sizeof(int);
	//puts(buff);
	for(int i=0;i<max1;i++)
	{
		printf(" %d ",buff[i]);
	}
	printf("\n");
	int n=sendto(S,buff,sizeof(buff),0,(struct sockaddr*)&cadd,len);
	return(0);
}

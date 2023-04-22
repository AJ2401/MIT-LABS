//Client Side
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#define port_num 8054
int main()
{
	int socket1;
	socket1=socket(AF_INET,SOCK_STREAM,0);
	struct sockaddr_in server_address;
	server_address.sin_family=AF_INET;

	server_address.sin_port=htons(port_num);

	server_address.sin_addr.s_addr=INADDR_ANY;

	int c=connect(socket1,(struct sockaddr*)&server_address,sizeof(server_address));

	if(c==0)
	{
		printf("Connection is Made Successfully !! ");
	}
	if(c==-1)
	{
		printf("Connection Failed !!"); 
	}
	char response[300];
	recv(socket1,&response,sizeof(response),0);

	printf("The Server Sent the Data which is %s \n",response);

	close(socket1);

	return(0);
}
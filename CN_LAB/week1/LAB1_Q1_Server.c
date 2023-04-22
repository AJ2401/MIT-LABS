//Server Side
#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdlib.h>
#include<netinet/in.h>
#define port 8054
int main()
{
	char message[300]=" Hello Welcome to the Server !! ";
	int socket1;
	socket1=socket(AF_INET,SOCK_STREAM,0);

	struct sockaddr_in server_address;
	server_address.sin_port=htons(port);
	server_address.sin_addr.s_addr=INADDR_ANY;

	bind(socket1,(struct sockaddr*)&server_address,sizeof(server_address));
	listen(socket1,10);

	int client_socket;

	client_socket=accept(socket1,NULL,NULL);

	send(client_socket,message,sizeof(message),0);
	close(socket1);
	return(0);
}
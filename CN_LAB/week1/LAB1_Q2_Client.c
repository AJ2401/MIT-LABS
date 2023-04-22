#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<sys/socket.h>
#define port 8054
int create_socket()
{
	int s;
	s=socket(AF_INET,SOCK_STREAM,0);
	return(s);
}
/*int connecting(int s,struct sockaddr_in server_add,int n)
{
	int c=connect(s,(struct sockaddr*)&server_add,n);
	return(c);
}*/
void recieve(int s)
{
	char response[350];
	recv(s,&response,sizeof(response),0);

	printf("\n\nThe Server Send the data which is :\n\t\t%s",response);
}
void terminate(int s)
{
	close(s);
}
int main()
{
	int s1;
	s1=create_socket();
	struct sockaddr_in server_address;
	server_address.sin_family=AF_INET;
	server_address.sin_port=htons(port);
	server_address.sin_addr.s_addr=INADDR_ANY;

	int c=connect(s1,(struct sockaddr*)&server_address,sizeof(server_address));
	if(c==0)
	{
		printf("Connection is Made Successfully !! ");
	}
	if(c==-1)
	{
		printf("Connection Failed !!"); 
	}
	recieve(s1);
	terminate(s1);
	return(0);
}
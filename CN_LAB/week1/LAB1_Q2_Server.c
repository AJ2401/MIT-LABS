//Server Side
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#define port 8054

int Create_socket()
{
	int s;
	s=socket(AF_INET,SOCK_STREAM,0);
	return(s);
}
void Terminate_Sock(int s)
{
	close(s);
}
void sending(int cs,char arr[],int n){
	send(cs,arr,n,0);
}
int Client_Socket(int s)
{
	int cs;
	cs=accept(s,NULL,NULL);

	return(cs);
}
int main()
{
	char message[300]="Hello and Welcome to the Server Side !! \nI am Abhishek Jhawar !! \n\nMy Registration Number is 200905144 \n\n";
	//char msg1[200]="I am Abhishek Jhawar !! ";
	//char msg2[200]="My Registration Number is 200905144 ";

	int socket1=Create_socket();
	int socket2=Create_socket();
	int socket3=Create_socket();

	struct sockaddr_in add1,add2,add3;
	add1.sin_port=htons(port);
	add1.sin_addr.s_addr=INADDR_ANY;

	//add2.sin_port=htons(port);
	//add2.sin_addr.s_addr=INADDR_ANY;
	
	//add3.sin_port=htons(port);
	//add3.sin_addr.s_addr=INADDR_ANY;
	
	bind(socket1,(struct sockaddr*)&add1,sizeof(add1));
	listen(socket1,10);

	//bind(socket2,(struct sockaddr*)&add2,sizeof(add2));
	//listen(socket2,10);

	//bind(socket3,(struct sockaddr*)&add3,sizeof(add3));
	//listen(socket3,10);

	int cs1=Client_Socket(socket1);
	//int cs2=Client_Socket(socket2);
	//int cs3=Client_Socket(socket3);

	sending(cs1,message,sizeof(message));
	//sending(cs1,msg1,sizeof(msg1));
	//sending(cs1,msg1,sizeof(msg1));
	//sending(cs1,msg2,sizeof(msg2));

	Terminate_Sock(socket1);
//Terminate_Sock(socket2);
//	Terminate_Sock(socket2);
	return(0);
}
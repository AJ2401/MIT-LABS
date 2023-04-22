#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<time.h>

#define port 8750
int Create_socket()
{
	int s;
	s=socket(AF_INET,SOCK_STREAM,0);
	return(s);
}
int main()
{
	int socket1;
	struct sockaddr_in address;
	struct tm*time;
	int result;

	int h,m,s;

	socket1=Create_socket();

	//struct sockaddr_in address;
	address.sin_port=htons(port);
	address.sin_addr.s_addr=INADDR_ANY;
	//char*ip=inet_ntoa(address.sin_addr);
	printf("THE IP ADDRESS IS \nand\nPORT NUMBER IS : %d \n",port);
	int len=sizeof(address);
	result=connect(socket1,(struct sockaddr*)&address,len);

char*ans;
	//read(socket1,&h,1);
	//read(socket1,&m,1);
	//read(socket1,&s,1);
	int n=read(socket1,&ans,1);
	printf("HOURS : MINS : SECONDS  : %s \n",ans);

	close(socket1);
	exit(0);
	return(0);
}


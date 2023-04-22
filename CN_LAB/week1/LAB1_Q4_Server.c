// LAB 1 Q4
//SERVER
//Server Side
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<time.h>
#include<unistd.h>

#define port 8750
int Create_socket()
{
	int s;
	s=socket(AF_INET,SOCK_STREAM,0);
	return(s);
}
int main()
{
	time_t t;
	struct tm*t1;
	char*ans;
	int socket1,socket2;
	struct sockaddr_in s_address;
	struct sockaddr_in c_address;
	int h,m,s;

	socket1=Create_socket();

	s_address.sin_port=htons(port);
	s_address.sin_addr.s_addr=INADDR_ANY;

	bind(socket1,(struct sockaddr*)&s_address,sizeof(s_address));

	listen(socket1,2);

int n=1;
	while(n>0)
	{
		char ch;
		int len=sizeof(c_address);
		socket2=accept(socket1,(struct sockaddr*)&c_address,&len);

		char*ip_add=inet_ntoa(c_address.sin_addr);

		printf("IP ADDRESS %s : \n and \n PORT NUMBER : %d \n",ip_add,port);

		time(&t);

		t1=localtime(&t);

		ans=asctime(t1);

		/*printf("THE CURRENT TIME IS %s \n\n",ans);
		h=t1->tm_hour;
		m=t1->tm_min;
		s=t1->tm_sec;*/

		write(socket2,&ans,1);
		//write(socket2,&m,1);
		//write(socket2,&s,1);
	}
	return(0);
}
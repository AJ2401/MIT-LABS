#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 8080

int createConnection(char* ipaddr, int port);
void clientTask(int sockfd);

int main()
{
    int sockfd = createConnection("127.0.0.1", PORT);
    clientTask(sockfd);
    close(sockfd);
    exit(EXIT_SUCCESS);
}




int createConnection(char* ipaddr, int port)
{
    int sockfd;
    struct sockaddr_in address;

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket error: ");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ipaddr);
    address.sin_port = htons(port);

    if(connect(sockfd, (struct sockaddr*)&address, (socklen_t)sizeof(address)) < 0)
    {
        perror("Could not connect.");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

void clientTask(int sockfd)
{
    char buffer[1024];
    while(read(sockfd, buffer, sizeof(buffer)))
        printf("Message from server: %s\n", buffer);
}
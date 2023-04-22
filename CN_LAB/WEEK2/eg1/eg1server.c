#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT  8080
#define true  1
#define false 0

int createServerSocket(char* ipaddr, int port);
int acceptConnection(int sockfd, struct sockaddr_in* cliaddress);
void childProcess(int newsockfd);
int handleConnection(int sockfd, int newsockfd);

int main()
{
    int sockfd = createServerSocket("127.0.0.1", PORT);

    int newsockfd;
    struct sockaddr_in cliaddress;
    while(true)
    {
        printf("Server waiting...\n");
        newsockfd = acceptConnection(sockfd, &cliaddress);
        handleConnection(sockfd, newsockfd);
    }

    close(sockfd);
    exit(EXIT_SUCCESS);
}




int createServerSocket(char* ipaddr, int port)
{
    int sockfd, opt = 1;
    struct sockaddr_in address;

    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket error: ");
        exit(EXIT_FAILURE);
    }

    int option = 1;
    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) < 0)
    {
        perror("socket options error: ");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ipaddr);
    address.sin_port = htons(port);

    if(bind(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0)
    {
        perror("Bind error: ");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 5);
    return sockfd;
}

int acceptConnection(int sockfd, struct sockaddr_in* cliaddress)
{
    int clilen = sizeof(*cliaddress);
    int newsockfd;
    if((newsockfd = accept(sockfd, (struct sockaddr*)cliaddress, (socklen_t*)&clilen)) < 0)
    {
        perror("Couldn't accept: ");
        exit(EXIT_FAILURE);
    }
    return newsockfd;
}

void childProcess(int newsockfd)
{
    time_t t;
    time(&t);
    struct tm* tdat = localtime(&t);
    char* chartime = asctime(tdat);
    printf("chartime is %s", chartime);
    printf("Sending local time to client...\n");
    write(newsockfd, chartime, (strlen(chartime)+1) * sizeof(char));
    close(newsockfd);
    exit(EXIT_SUCCESS);
}

int handleConnection(int sockfd, int newsockfd)
{
    int child = fork();
    printf("pid: %d\n", child);
    if(child == -1)
    {
        printf("Couldn't create child process\n");
        exit(EXIT_FAILURE);
    }

    /* One problem is that if you encounter any errors in the child process 
     * it's difficult to debug. So if your child process seems to have been freezed 
     * or suspended there might have been an exception occured there. */

    if(child == 0)
    {
        close(sockfd);
        childProcess(newsockfd);
    }
    else
        close(newsockfd);
        
    if(child == 0)
        printf("Service done...");
    
    return 0;
}
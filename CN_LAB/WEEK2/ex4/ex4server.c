/* Server Side Program to sort a set of integers passed on to it. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define true  1
#define false 0

int strsort(char* buffer, char operator);
void strtoints(char* buffer, int* nums, int size);
int getnextspace(char* text);

int createSocket(char* ip, int port, int maxcon);
int acceptConnection(int sockfd, struct sockaddr_in* cliaddress);
int handleRequests(int sockfd);

int main()
{
    int sockfd = createSocket("127.0.0.1", 8080, 10), newsockfd;
    struct sockaddr_in cliaddress;
    printf("Main socket created: %d\n", sockfd);
    // To get concurrent client service we use select()
    while(true)
    {
        newsockfd = acceptConnection(sockfd, &cliaddress);
        if(fork() == 0)
        {
            close(sockfd);
            handleRequests(newsockfd);
            exit(EXIT_SUCCESS);
        }
        else
            close(newsockfd);
    }
       
    exit(EXIT_SUCCESS);
}

int handleRequests(int sockfd)
{
    char buffer[1024];
    char result[1024];
    read(sockfd, buffer, sizeof(buffer));

    char operator = buffer[0];
    char* temp = buffer + getnextspace(buffer) + 1;

    printf("Array received: %s\n", temp);
    int num = strsort(temp, operator);
    printf("Evaluated sent to client: %d\n", num);

    sprintf(result, "%d", num);
    result[getnextspace(result)] = '\0';

    write(sockfd, result, sizeof(char)*(strlen(result)+1));
    close(sockfd);
    return 0;
}

int acceptConnection(int sockfd, struct sockaddr_in* cliaddress)
{
    int clilen = sizeof(*cliaddress);
    int newsockfd;
    if((newsockfd = accept(sockfd, (struct sockaddr*)cliaddress, (socklen_t*)&clilen)) < 0)
    {
        perror("Connection wasn't Accepted: ");
        return -1;
    }
    return newsockfd;
}

int createSocket(char* ip, int port, int maxcon)
{
    int sockfd;
    struct sockaddr_in address;
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket Error: ");
        return -1;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr(ip);
    // htons to convert host byte order to network byte order 
    address.sin_port = htons(port);
    if(bind(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0)
    {
        perror("Bind Error: ");
        return -1;
    }
    listen(sockfd, maxcon);
    return sockfd;
}

int strsort(char* buffer, char operator)
{
    int nums[2];
    strtoints(buffer, nums, 2);
    switch(operator)
    {
        case '+':
            return nums[0] + nums[1];
        case '-':
            return nums[0] - nums[1];
        case '*':
            return nums[0] * nums[1];
        case '/':
            return nums[0] / nums[1];
        case '%':
            return nums[0] % nums[1];
        default:
            return -1;
    }
}

int getnextspace(char* text)
{
    for(int i = 0; i < strlen(text); i++)
    {
        if(text[i] == ' ')
            return i;
    }
    return -1;
}

void strtoints(char* buffer, int* nums, int size)
{
    char* iterate = buffer;
    for(int i = 0; i < size; i++)
    {
        nums[i] = atoi(iterate);
        iterate += getnextspace(iterate) + 1;
    }
}
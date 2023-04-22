#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define true  1
#define false 0

int createConnection(char* ip, int port);
int sendRequest(int sockfd, char* buffer);

/*void terminateStrings(char* text)
{
    int i = 0;
    while(text[i] != '\n')
    i++;
    text[i] = '\0';
}
*/
int main()
{
    int sockfd = createConnection("127.0.0.1", 10200);
    printf("Enter a space separated array starting with size: \n");
    char buffer[15]={14,9,6,4,13};
    char result[15];
    //terminateStrings(buffer);

    sendRequest(sockfd, buffer);

    //read(sockfd, result, sizeof(result));
    printf("Sorted array sent from server:\n%s\n", result);

    close(sockfd);
    exit(EXIT_SUCCESS);
}

int sendRequest(int sockfd, char* buffer)
{
    write(sockfd, buffer, sizeof(char) * (strlen(buffer) + 1));
    printf("Message sent to the server: %s\n", buffer);
    return 0;
}

int createConnection(char* ip, int port)
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
    address.sin_port = htons(port);

    if(connect(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0)
    {   
        perror("Connection Error: ");
        return -1;
    }

    return sockfd;
}
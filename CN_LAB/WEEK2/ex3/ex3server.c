/* Server Side Program to sort a set of integers passed on to it. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define true  1
#define false 0

void strsort(char* buffer, char* result, int size);
void strtoints(char* buffer, int* nums, int size);
void intstostr(char* buffer, int* nums, int size);
int getnextspace(char* text);

int createSocket(char* ip, int port, int maxcon);
int acceptConnection(int sockfd, struct sockaddr_in* cliaddress);
int handleRequests(int sockfd);

void swap(int* a, int* b);
void bubbleSort(int arr[], int n);

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

    int size = atoi(buffer);

    char* temp = buffer + getnextspace(buffer) + 1;

    printf("Array received: %s\n", temp);
    strsort(temp, result, size);
    printf("Sorted array sent to client: %s\n", result);

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

void strsort(char* buffer, char* result, int size)
{
    int* nums = (int*)calloc(sizeof(int), size);
    strtoints(buffer, nums, size);
    bubbleSort(nums, size);
    intstostr(result, nums, size);
    free(nums);
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

void intstostr(char* buffer, int* nums, int size)
{
    char* iterate = buffer;
    for(int i = 0; i < size; i++)
    {
        sprintf(iterate, "%d ", nums[i]);
        iterate += getnextspace(iterate)+1;
    }
    *(iterate - 1) = '\0';
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr + j, arr + (j + 1));
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
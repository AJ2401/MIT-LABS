#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
#define M_TRUE 1
#define M_FALSE 0
typedef struct
{
 int front, rear;
 char array[MAX];
} Queue;
void PushR(Queue *q, char key)
{
 if (q->rear == MAX - 1)
 printf("\nThe queue is full");
 else
 {
 if (q->front == -1 && q->rear == -1)
 q->front++;
 q->array[++q->rear] = key;
 }
}
char PopR(Queue *q)
{
 char temp = q->array[q->rear];
 q->rear--;
 if (q->front > q->rear)
 {
 q->front = -1;
 q->rear = -1;
 }
 return temp;
}
char PopL(Queue *q)
{
 char temp = q->array[q->front];
 q->front++;
 if (q->front > q->rear)
 {
 q->front = -1;
 q->rear = -1;
 }
 return temp;
}
int main()
{
printf("\nABHISHEK JHAWAR (200905144)\n");
 int flag = 1;
 Queue queue;
 queue.front = queue.rear = -1;
 char element[50];
 printf("Please enter the string :\n");
 scanf(" %s", element);

 int pos = (int)strlen(element);

 for(int i = 0; i < pos; i++)
 PushR(&queue, element[i]);

 pos = pos/2;
 while(pos--)
 {
 if(PopL(&queue) != PopR(&queue)){
 flag = 0;
 break;
 }
 }

 if(flag == M_TRUE)
 printf("The string is a Palindrome.\n");
 else
 printf("The string is not a Palindrome.\n");
 return 0;
}

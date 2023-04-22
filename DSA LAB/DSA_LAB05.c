#include<stdio.h>
#include<stdlib.h>
#define max 8
struct queue
{
    int rear,front;
    int arr[max];
};
void intial(struct queue*);
void create(struct queue*,int data);
int del(struct queue*);
void display(struct queue*,int len);
int main()
{
    printf("ABHISHEK JHAWAR 200905144");
    struct queue q;
    intial(&q);
    int n,num;
    printf("\nEnter the Number of Elements in the array: \n");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the Elements of the Array :\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        create(&q,arr[i]);
    }
    printf("The Queue is :\n");
    display(&q,n);
    num=del(&q);
    if(num!=NULL)
    {
        printf("\n%d Element is Deleted\n",num);

    }
    num=del(&q);
    if(num!=NULL)
    {
        printf("\n%d Element is Deleted\n",num);

    }
    num=del(&q);
    if(num!=NULL)
    {
        printf("\n%d Element is Deleted\n",num);

    }
    printf("\nThe Queue after deletion is :\n");
    display(&q,n);
}
void intial(struct queue* q)
{
    q->front=-1;
    q->rear=-1;
}
void create(struct queue* q,int data)
{
    if(q->front>=max-1)
    {
        printf("The Queue is Full\n");
    }
    else
    {
     q->rear++;
     q->arr[q->rear]=data;
     if(q->front==-1)
     {
         q->front=0;
     }
    }
}
int del(struct queue* q)
{
    int data;
    if(q->front<=-1)
    {
        printf("The Queue is Empty \n");
    }
    else
    {
        data=q->arr[q->front];
        q->arr[q->front]=0;
        if(q->front==q->rear)
        {
            q->rear=-1;
            q->front=-1;
        }
        else
        {
            q->front++;
        }
        return(data);
    }
}
void display(struct queue* q,int len)
{
    int i=0;
    for(int i=0;i<len;i++)
    {
        printf(" %d ",q->arr[i]);
    }
}

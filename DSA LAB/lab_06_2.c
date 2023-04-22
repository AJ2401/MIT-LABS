#include <stdio.h>
#define MAX 5
typedef struct
{
    int front   ;
    int rear    ;
    int count   ;
    int ele[MAX]    ;
}DQueue;
void initDQueue(DQueue * q)
{
    q->front =  0;
    q->rear  = -1;
    q->count =  0;
}
int isFull(DQueue * q)
{
    int full=0;

    if(q->count == MAX)
        full = 1;

    return full;
}
int isEmpty(DQueue * q)
{
    int empty=0;

    if(q->count == 0)
        empty = 1;

    return empty;
}
void insertDQueueAtRear(DQueue * q, int item)
{
    if( isFull(q) )
    {
        printf("\nQueue Overflow");
        return;
    }

    q->rear = (q->rear+1)%MAX;
    q->ele[q->rear] = item;

    q->count++;

    printf("\nAfter insert At Rear FRONT : %d, REAR : %d",q->front,q->rear);
    printf("\nInserted item : %d\n",item);
}
int deleteDQueueAtFront(DQueue * q, int *item)
{
    if( isEmpty(q) )
    {
        printf("\nQueue Underflow");
        return -1;
    }

    *item    = q->ele[q->front];

    q->front = (q->front+1)%MAX;

    q->count--;

    printf("\nAfter Delete At Front FRONT : %d, REAR : %d",q->front,q->rear);
    return 0;
}
void insertDQueueAtFront(DQueue * q, int item)
{
    if( isFull(q) )
    {
        printf("\nQueue Overflow");
        return;
    }

    if ( q->front == 0)
        q->front = MAX - 1;
    else
        q->front = q->front - 1;
    q->ele[q->front] = item;

    q->count++;
    printf("\nAfter Insert At Front FRONT : %d, REAR : %d",q->front,q->rear);
    printf("\nInserted item : %d\n",item);
}
int deleteDQueueAtRear(DQueue * q, int *item)
{
    if( isEmpty(q) )
    {
        printf("\nQueue Underflow");
        return -1;
    }

    *item = q->ele[q->rear];

    if(q->rear == 0)
        q->rear = MAX - 1;
    else
        q->rear = q->rear - 1;

    printf("\nAfterDeleteAtRear FRONT : %d, REAR : %d",q->front,q->rear);
    q->count--;
    return 0;
}
int main()
{
    printf("\nABHISHEK JHAWAR (200905144) \n");
    int item=0;
    DQueue q;

    initDQueue(&q);

    insertDQueueAtRear(&q, 10);
    insertDQueueAtRear(&q, 20);
    insertDQueueAtRear(&q, 30);
    insertDQueueAtFront(&q, 40);
    insertDQueueAtFront(&q, 50);
    insertDQueueAtFront(&q, 60);

    if ( deleteDQueueAtFront( &q, &item ) == 0 )
        printf("\nDeleted item is : %d\n",item);


    if ( deleteDQueueAtFront( &q, &item ) == 0 )
        printf("\nDeleted item is : %d\n",item);


    if ( deleteDQueueAtFront( &q, &item ) == 0 )
        printf("\nDeleted item is : %d\n",item);


    if ( deleteDQueueAtRear( &q, &item ) == 0 )
        printf("\nDeleted item is : %d\n",item);


    if ( deleteDQueueAtRear( &q, &item ) == 0 )
        printf("\nDeleted item is : %d\n",item);



    if ( deleteDQueueAtRear( &q, &item ) == 0 )
        printf("\nDeleted item is : %d\n",item);

    printf("\n");
    return 0;
}

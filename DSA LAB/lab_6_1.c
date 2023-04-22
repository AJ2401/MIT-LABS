#include<stdio.h>
typedef struct que
{
    int d1,d2;
    struct que *next;
}node;
void insert(node**,node**,int,int);
void serve(node**,node**);
void display(node*);
int main()
{
    printf("\nABHISHEK JHAWAR (200905144)\n");
    node *front=NULL,*rear=NULL;
    int ch,pr,num,c=0;
    printf("Enter the number of iterations : ");
    scanf("%d",&c);
    printf("Menu\n1)Insert\n2)serve\n3)Display\nChoose : ");
    do
    {
        scanf("%d",&ch);
        switch(ch)
        {
             case 1: printf("\nEnter the number to be inserted and its priority : ");
             scanf("%d  %d",&num,&pr);
             insert(&front,&rear,num,pr);
             break;
             case 2: if(front==NULL)
             printf("\nNo elements are present in the Priority Queue");
             else
             serve(&front,&rear);
             break;
             case 3: if(front==NULL)
             printf("\nNo elements in the Priority Queue");
             else
             display(front);
             break;
             default:
             printf("\nEnter the correct choice");
        }
        c--;
    }while(c>0);
}
void insert(node **front,node **rear,int num,int pr)
{
    node *p=NULL,*tmp=*front;
    p=(node*)malloc(sizeof(node));
    if(p!=NULL)
    {
         p->d1=num;
         p->d2=pr;
         p->next=NULL;
    }
    if((*rear)==NULL)
    {
         (*front)=(*rear)=p;
    }
    else
    {
         if((p->d2)>((*rear)->d2))
         {
              (*rear)->next=p;
              (*rear)=p;
         }
         else if(p->d2<((*front)->d2))
         {
              p->next=(*front);
              (*front)=p;
         }
         else
         {
              while(((tmp->next)->d2)<(p->d2))
              tmp=tmp->next;
              p->next=tmp->next;
              tmp->next=p;
         }
    }
}
void serve(node **front,node **rear)
{
    node*tmp=*front;
    if((*front)==(*rear))
    {
        printf("The served element is %d",(*front)->d1);
        (*rear)=(*front)=NULL;
    }
    else
    {
        printf("The served element is %d",(*front)->d1);
        (*front)=(*front)->next;
    }
    free(tmp);
}
void display(node *front)
{
    node *tmp;
    tmp=front;
    while(tmp!=NULL)
    {
         printf("%d ",tmp->d1);
         tmp=tmp->next;
    }
}

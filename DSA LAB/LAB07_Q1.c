#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node*link;
};
struct Q
{
   struct node*front;
   struct node*rear;
};
void intial(struct Q*q)
{
   q->front=NULL;
   q->rear=NULL;
}
void add_Q(struct Q*q,int item)
{
   struct node*temp=(struct node*)malloc(sizeof(struct node));
   temp->data=item;
   temp->link=NULL;
   if(temp==NULL)
   {
      printf("Queue is FULL !!! ");
   }
   if(q->front==NULL)
   {
      q->rear=q->front=temp;
   }
      q->rear->link=temp;
      q->rear=q->rear->link;
}
void del_Q(struct Q*q)
{
   struct node*temp;
   int item;
   item=q->front->data;
   temp=q->front;
   q->front=q->front->link;
   free(temp);
   printf("%d Element is Deleted \n",item);
}
void display_Q(struct Q*q)
{
   int c=0;
   struct node*t=q->front;
   while(t!=NULL)
   {
      printf(" %d <- ",t->data);
      t=t->link;
      c++;
   }
   printf("\n Number of Nodes are %d ",c);
}
int main()
{
   printf("ABHISHEK JHAWAR 200905144 \n");
   struct Q*q;
   int n;
   printf("\nEnter the Number of Iteration to be Done : \n");
   scanf("%d",&n);
   int opt,ele;
   while(n>0)
   {
      printf("\nChoose your Option : \n1)Add Element \n2)Delete Element \n3)Display \n");
      scanf("%d",&opt);
      switch(opt)
      {
         case 1:
         printf("Enter the Element : \n");
         scanf("%d",&ele);
         add_Q(q,ele);
         break;
         case 2:
         del_Q(q);
         break;
         case 3:
         printf("\n");
         display_Q(q);
         break;
         default:
         break;
      }
   }
   return 0;
}

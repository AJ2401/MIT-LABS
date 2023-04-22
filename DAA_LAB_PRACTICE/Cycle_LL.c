#include<stdio.h>
#include<stdlib.h>
struct node
{
     int data;
     struct node*link;
};
void append(struct node**head,int item)
{
     struct node*temp=(struct node*)malloc(sizeof(struct node));
     temp->data=item;
     temp->link=NULL;
     if(*head==NULL)
     {
          *head=temp;
     }
     else
     {
          struct node*t=*head;
          while(t->link!=NULL)
          {
               t=t->link;
          }
          t->link=temp;
     }
}
void display(struct node*head)
{
     int c=0;
     struct node*t=head;
     while(t->link!=NULL)
     {
          printf("%d  ->  ",t->data);
          t=t->link;
          c++;
     }
     printf("The Number of nodes are %d ",c);
}
int Remove(struct node**head)
{

struct node*fast=*head;
     struct node*slow=*head;
     while(fast!=NULL && fast->link!=NULL)
     {
          fast=fast->link->link;
          slow=slow->link;
          if(slow==fast)
          {
              fast->link=NULL;
              return(1);
          }
     }
     return(0);
}
int Cycle(struct node**head)
{
     struct node*fast=*head;
     struct node*slow=*head;
     while(fast->link!=NULL && fast->link!=NULL)
     {
          fast=fast->link->link;
          slow=slow->link;
          if(slow==fast)
          {
               return(1);
          }
     }
     return(0);
}
void Create_Cycle(struct node**head,int pos)
{
     struct node*t=*head;
     struct node*temp=*head;
     int count=0;
     int opt;
     while(temp->link!=NULL)
     {
          temp=temp->link;
     }
     while(t->link!=NULL && count!=pos)
     {
          t=t->link;
          count++;
     }
     temp->link=t;
}
void main()
{
     struct node*head=NULL;
     int item,opt,n=1,pos,o,option,re;
     while(n>0)
     {
          printf("Choose your Option \n1)ADD \n2)Display\n3)Detect the Cycle in Linked List \n4)Remove the Cycle in Linked List \n5)Create a Cycle \n");
          scanf("%d",&opt);
          switch(opt)
          {
               case 1:
               printf("Enter the element : ");
               scanf("%d",&item);
               append(&head,item);
               break;
               case 2:
               printf("The Linked List is : ");display(head);
               break;
               case 3:
                option=Cycle(&head);
               if(option==1)
               {
                    printf("The Linked List have Cycle !");
               }
               else if(option==0)
               {
                    printf("The Linked List dosen't have Cycle !");
               }
               break;
               case 5:
               printf("Enter the Position : ");
               scanf("%d",&pos);
               Create_Cycle(&head,pos);
               break;
               case 4:
                    re=Remove(&head);
               if(re==1)
               {
                    printf("Removed Successful !! ");
               }
               else
               {
                    printf("Removal Unsuccessful !! ");
               }
               default:
               break;
          }
     }
}
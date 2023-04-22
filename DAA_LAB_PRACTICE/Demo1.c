#include<stdio.h>
#include<stdlib.h>

struct node
{
     int data;
     struct node*link;
};
void Create(struct node**head,int item)
{
     struct node*temp=(struct node*)malloc(sizeof(struct node));
     temp->data=item;
     temp->link=NULL;

     if(*head==NULL)
     {
          *head=temp;
     }
     else{
          struct node*t=*head;
          while(t->link!=NULL)
          {
               t=t->link;
          }
          t->link=temp;
     }
}    
int Del(struct node**head,int pos)
{
     int c=0;
     struct node*t=*head;
     while(t->link!=NULL)
     {
          if(c+1==pos)
          {
               struct node*temp=t->link;
               t->link=temp->link;
               free(temp);
          }
          c++;
          t=t->link;
     }
}
void display(struct node*head)
{
     struct node*t=head;
     int c=0;
     while(t!=NULL)
     {
          printf("%d  -> ",t->data);
          t=t->link;
          c++;
     }
     printf(" \n%d number of Nodes \n",c);
}
struct node*reverse(struct node**head)
{
     struct node*pre=NULL;
     struct node*curr=*head;
     struct node*next;
     while(curr!=NULL)
     {
          next=curr->link;
          curr->link=pre;
          pre=curr;
          curr=next;
     }
     return(pre);
 }
struct node*reverseK(struct node*head,int k)
{
     struct node*pre=NULL;
     struct node*curr=head;
     struct node*next;
     int c=0;
     while(curr!=NULL && c<k)
     {
          next=curr->link;
          curr->link=pre;
          pre=curr;
          curr=next;
          c++;
     }
     if(next!=NULL)
     {
          head->link=reverseK(next,k);
     }
     return(pre);
}
void main()
{
          struct node*head=NULL;
          int val,opt,n,del,pos,k;
          struct node*rev=NULL;
          struct node*revK=NULL;
          n=1;
          while(n>0)
          {
               printf("Choose your option : \n1)Add\n2)Delete\n3)Display\n4)Reverse LL\n5)Reverse K nodes\n6)EXIT\n");
               scanf("%d",&opt);
               switch(opt)
               {
                    case 1:
                    printf("Enter the Data : \n");
                    scanf("%d",&val);
                    Create(&head,val);
                    break;
                    case 2:
                    printf("Enter the Position : \n");
                    scanf("%d",&pos);
                    del=Del(&head,pos);
                    printf("%d is Deleted !! \n");
                    break;
                    case 3:
                    printf("The Linked List is : \n");
                    display(head);
                    break;
                    case 4:
                    rev=reverse(&head);
                    printf("The reversed Linked List is : \n");
                    display(rev);
                    break;
                    case 5:
                    printf("Enter the Value of K : \n");
                    scanf("%d",&k);
                    revK=reverseK(head,k);
                    display(revK);
                    break;
                    case 6:
                    n=0;
                    break;
               }
          }   
}
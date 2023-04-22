#include<stdio.h>
#include<stdlib.h>
struct node
{
     struct node*left;
     struct node*right;
     int data;
};
void append(struct node**head,int item)
{
     struct node*temp=(struct node*)malloc(sizeof(struct node));
     temp->data=item;
     temp->left=NULL;
     temp->right=NULL;
     if(*head==NULL)
     {
          *head=temp;
     }
     else
     {
          struct node*t=*head;
          while(t->right!=NULL)
          {
               t=t->right;
          }
          t->right=temp;
          temp->left=t;
     }
}
void add_beg(struct node**head,int item)
{
     struct node*t=*head;
     struct node*temp=(struct node*)malloc(sizeof(struct node*));
     temp->data=item;
     temp->left=NULL;
     temp->right=t;
     t->left=temp;
     *head=temp;
}
void add_after(struct node**head,int item,int pos)
{
     int count=0;
     struct node*t=*head;
     struct node*temp=(struct node*)malloc(sizeof(struct node));
     temp->data=item;
     temp->left=NULL;
     temp->right=NULL;
     while(t->right!=NULL && count<=pos)
     {
          t=t->right;
          count++;
     }
     temp->left=t;
     t->right->left=temp;
     temp->right=t->right;
     t->right=temp;
}
int delete(struct node**head,int pos)
{
    int count=0;
     struct node*t=*head;
     while(t->right!=NULL && count!=pos)
     {
          t=t->right;
          count++;
     }
     struct node*del=t;
     int ele=del->data;
     t->right->left=t->left;
     t->left->right=t->right;
     free(t);
     return(ele);
}
void display(struct node*head)
{
     struct node*t=head;
     int c=0;
     while(t->right!=NULL)
     {
          printf(" <-  %d  -> ",t->data);
          t=t->right;
          c++;
     }
     printf("The Number of Nodes are : %d",c);
}
void display_sub(struct node*head,int ll,int ul)
{
     struct node*t=head;
     int c=0;
     for(int i=0;i<ll;i++)
     {
          t=t->right;
     }
     for(int i=ll;i<=ul;i++)
     {
          printf(" <- %d -> ",t->data);
          t=t->right;
          c++;
     }
     printf("Number of Nodes are %d ",c);
}
void main()
{
     struct node*head=NULL;
     int pos,opt,ll,ul,n=1,item,ele;
     while(n>0)
     {
          printf("Choose your option \n1)ADD\n2)Add Begging \n3)Add After\n4)Delete\n5)Display\n6)Display Sub Linked List\n");
          scanf("%d",&opt);
          switch(opt)
          {
               case 1:
               printf("Enter the Number : ");
               scanf("%d",&item);
               append(&head,item);
               break;
               case 2:
               printf("Enter the Number : ");
               scanf("%d",&item);
               add_beg(&head,item);
               break;
               case 3:
               printf("Enter the Number : ");
               scanf("%d",&item);
               printf("Enter the Position : ");
               scanf("%d",&pos);
               add_after(&head,item,pos);
               break;
               case 4:
               printf("Enter the Positon : ");
               scanf("%d",&pos);
               ele=delete(&head,pos);
               break;
               case 5:
               printf("The Linked List is : ");
               display(head);
               break;
               case 6:
               printf("Enter the Lower Limit : ");
               scanf("%d",&ll);
               printf("Enter the Upper Limit : ");
               scanf("%d",&ul);
               printf("The Linked list from %d to %d is : ",ll,ul);
               display_sub(head,ll,ul);
               break;
               default:
               break;

          }
     }
}
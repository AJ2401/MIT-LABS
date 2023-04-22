#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node*link;
};
void display(struct node*head)
{
   int c=0;
   while(head!=NULL)
   {
      printf(" %d -> ",head->data);
      head=head->link;
      c++;
   }
   printf("\n%d of number of Nodes are there .\n",c);
}
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
void Inter(struct node**head1,struct node**head2)
{
   int n=9;
   struct node*result=NULL;
   struct node*t1=*head1;
   struct node*t2=*head2;
   while(n>0)
   {
      if(t1->link!=NULL || t2->link!=NULL)
      {
         while(t1->link!=NULL)
         {
            while(t2->link!=NULL)
            {
               if(t1->data==t2->data)
               {
                   int d=t1->data;
                  append(&result,d);
               }
               t2=t2->link;
            }
            t1=t1->link;
         }
      }
      else
      {
         break;
      }
   }
   printf("The Intersection Elements are : \n");
   display(result);
}
void Union(struct node**head1,struct node**head2)
{
   struct node*t1=*head1;
   struct node*t2=*head2;
   struct node*result=NULL;
   while(t1!=NULL)
   {
      append(&result,t1->data);
      t1=t1->link;
   }
   while(t2!=NULL)
   {
      append(&result,t2->data);
      t2=t2->link;
   }
   printf("The Union of Two Linked List is  : \n");
   display(result);
}
int main()
{
    printf("\nAbhishek Jhawar (200905144)\n");
   struct node*head1=NULL;
   struct node*head2=NULL;
   int n=10;
   int opt,ele,c;
   while(n>0)
   {
      printf("Choose your Option \n1)Add Element \n2)Find the Intersection \n3)Find the Union \n4)Display \n");
      scanf("%d",&opt);

      switch (opt)
      {
      case 1:

      printf("Choose anyone of the Lists \n1)List 1\n2)List 2\n");
      scanf("%d",&c);
      switch (c)
      {
      case 1 :
      printf("Enter the Element to be Add : \n");
      scanf("%d",&ele);
      append(&head1,ele);
         break;
      case 2 :
      printf("Enter the Element to be Add : \n");
      scanf("%d",&ele);
      append(&head2,ele);
         break;
      default:
         break;
      }
      break;
      case 2:
      Inter(&head1,&head2);
      break;
      case 3:
      Union(&head1,&head2);
      break;
      case 4:
     printf("Choose anyone of the Lists \n1)List 1\n2)List 2\n");
      scanf("%d",&c);
      switch (c)
      {
      case 1:
      display(head1);
         break;
      case 2:
    display(head2);
         break;
      }
      break;
      default:
      break;
      }
   }
   return 0;
}

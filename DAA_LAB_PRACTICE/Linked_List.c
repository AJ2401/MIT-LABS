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
         // free(t);
     }
}
void add_beg(struct node**head,int item)
{
     struct node*temp=(struct node*)malloc(sizeof(struct node));
     temp->data=item;
     temp->link=*head;
     *head=temp;
}
void display(struct node*head)
{
     int c=0;
     struct node*t=head;
     while(t!=NULL)
     {
          printf("%d  ->  ",t->data);
          t=t->link;
          c++;
     }
     printf("\nThe number of Nodes are %d\n",c);
}
int del(struct node**head,int ele)
{
     struct node*t=*head;
     if(head==NULL)
     {
          return(-1);
     }
     else
     {
     while(t->data==ele)
     {
          t=t->link;
     }
     struct node*d=t->link;
     int item=t->data;
     t->link=d->link;
     free(d);
     return(item); 
     }
}
int del_cert(struct node**head,int pos)
{
     struct node*t=*head;
     int c=0;
     while(c==pos)
     {
          t=t->link;
          c++;
     }
     t=t->link;
     struct node*temp=t->link;
     t->link=temp->link;
     int ele=temp->data;
     free(temp);
     return(ele);
}
void add_cert(struct node**head,int item,int pos)
{
     int c=0;
     struct node*temp=(struct node*)malloc(sizeof(struct node));
     temp->data=item;
     temp->link=NULL;
     struct node*t=*head;
     while(c==pos)
     {
          t=t->link;
          c++;
     }
     t=t->link;
     temp->link=t->link;
     t->link=temp;
}
void display_sub(struct node*head,int ll,int ul)
{
     int count=0;
     struct node*t=head;
     for(int i=0;i<=ll;i++)
     {
          t=t->link;
     }
     for(int i=ll;i<=ul;i++)
     {
          printf("%d  ->  ",t->data);
          t=t->link;
          i++;
          count++;
     }
     printf("The  Number of Nodes are from %d to %d are %d",ll,ul,count);
}
void main()
{
     struct node*head=NULL;
     int opt,del_i,item,n,pos,ele,ul,ll;
     printf("\nEnter the Number of Iterations to be Done : \n");
     scanf("%d",&n);
     while(n>0){
     printf("\nChoose your Option : \n1)ADD at End \n2)ADD at Begging \n3)Display\n4)Delete\n5)Delete At Certain\n6)Add At Certain Position\n7)Display At Certain Positions \n");
     scanf("%d",&opt);
     switch(opt)
     {
          case 1:
          printf("\nEnter the Element to be Add at the End : \n");
          scanf("%d",&item);
          append(&head,item);
          break;
          case 2:
          printf("\nEnter the Element to be Add at  the Begging : \n");
          scanf("%d",&item);
          add_beg(&head,item);
          break;
          case 3:
          printf("\nThe Linked List is : \n");
          display(head);
          break;
          case 4:
          printf("\nThe Item which is to be Deleted : \n");
          scanf("%d",&del_i);
           ele=del(&head,del_i);
          printf("\nThe Item Deleted is %d !!\n",del_i);
          break;
          case 6:
          printf("Add At Certain Positon : \n");
          printf("\nEnter the Element :\n");
          scanf("%d",&item);
          printf("\nEnter the Position : \n");
          scanf("%d",&pos);
          add_cert(&head,item,pos);
          break;
          case 5:
          printf("\nEnter the Position for which element should be Deleted : \n");
          scanf("%d",&pos);
          ele=del_cert(&head,pos);
          printf("\nThe %d Element is Deleted !! \n",ele);
          case 7:
          printf("\n Enter the Lower Limit : \n");
          scanf("%d",&ll);
          printf("Enter the Upper Limit : \n");
          scanf("%d",&ul);
          display_sub(head,ll,ul);
          break;
          default:
          break;
          }
           n--;
     }
}
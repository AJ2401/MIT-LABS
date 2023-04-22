#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node1
{
   char*name[25];
   int ph_num;
   struct node1*link1;
};
struct node2
{
   char name[25];
   int ph_num;
   char f;
   struct node2*link2;
};
void append1(struct node1**head1,char*name,int ph_num)
{
   struct node1*temp=(struct node1*)malloc(sizeof(struct node1));
   strcpy(temp->name,name);
   temp->ph_num=ph_num;
   temp->link1=NULL;
   if(*head1==NULL)
   {
      *head1=temp;
   }
   else
   {
      struct node1*t=*head1;
      while(t->link1!=NULL)
      {
         t=t->link1;
      }
      t->link1=temp;
   }
}
void append2(struct node2**head2,struct node1*head1,char*name,int ph_num,char f)
{
   struct node2*temp=(struct node2*)malloc(sizeof(struct node2));
    strcpy(temp->name,name);
   temp->ph_num=ph_num;
   temp->f=f;
   temp->link2=NULL;
   if(*head2==NULL)
   {
      *head2=temp;
   }
   else
   {
      struct node2*t=*head2;
      while(t->link2!=NULL)
      {
         t=t->link2;
      }
      t->link2=temp;
   }
   while(head1!=NULL)
   {
      head1=head1->link1;
   }
   head1->link1=*head2;
}
void display1(struct node1*head1)
{
  int c=0;
   while(head1!=NULL)
   {
      printf("Name - : %s \n",head1->name);
      printf("Phone Number - :%d \n",head1->ph_num);
      head1=head1->link1;
      c++;
   }
   printf("\nThe Number of Passengers are : %d\n",c);
   if(c<10)
   {
      printf("\nThe Couch Residing is  Couch 1 \n");
   }
   else if(c>10 && c<20)
   {
      printf("\nThe Couch Residing is Couch 2 \n");
   }
   else if(c>20 && c<30)
   {
      printf("\nThe Couch Residing is Couch 3\n");
   }
   if(c==30)
   {
      printf("\nThe Chair Seats are Booked !! Please try in Executive Chair \n");
   }
}
void display2(struct node2*head2)
{
    int c=0;
   while(head2!=NULL)
   {
      printf("Name - : %s \n",head2->name);
      printf("Phone Number - :%d \n",head2->ph_num);
      if(head2->f=='V' || head2->f=='v')
      {
      printf("Prefered Food is Veg !\n");
      }
      else
      {
         printf("Preffered Food Non Veg !\n");
      }
      head2=head2->link2;
      c++;
   }
   printf("\nThe Number of Passengers are : %d\n",c);
   if(c<5)
   {
      printf("\nThe Couch Residing is  Ex-Couch 1 \n");
   }
   else if(c>5 && c<5)
   {
      printf("\nThe Couch Residing is Ex-Couch 2 \n");
   }
   if(c==10)
   {
      printf("\nThe Executive Chair Seats are Booked !! Please try Again After some Time\n");
   }
}
void main()
{
   struct node1*head1=NULL;
   struct node2*head2=NULL;
   int ph_num,opt,o1,o2,n=40,count1=0,count2=0;
   char name[25],f;
   while(n>0)
   {
      printf("Choose any \n1)Add \n2)Display\n");
      scanf("%d",&opt);
      switch (opt)
      {
      case 1:
      printf("Choose your class \n1)Chair \n2)Executive Chair\n");
      scanf("%d",&o1);
      switch (o1)
      {
      case 1:
      count1++;
      if(count1==30){
         break;
      }
      printf("Enter Your Name : \n");
      scanf("%s",&name);
      
      printf("Enter your Phone Number : \n");
      scanf("%d",&ph_num);
      append1(&head1,name,ph_num);
         break;
         
      case 2:
      count2++;
      if(count2==10)
      {
         break;
      }
      printf("Enter your name : \n");
      scanf("%s",&name);
      printf("Enter your Phone Number : \n");
      scanf("%d",&ph_num);
      printf("Choose Veg  or Non Veg : \n");
      scanf("%s",&f);
      append2(&head2,head1,&name,ph_num,f);
         break;
      default:
         break;
      }
         break;

      case 2:
      printf("Choose your class \n1)Chair \n2)Executive Chair\n");
      scanf("%d",&o2);
      switch (o2)
      {
      case 1:
      display1(head1);
         break;
      case 2:
      display2(head2);
         break;

      default:
         break;
      }
         break;
         
      default:
         break;
      }
      n--;
   }
}

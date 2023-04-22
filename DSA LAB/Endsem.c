#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct cc
{
   int number;
   char name[25];
   struct cc*link;
};
struct ec
{
   int number;
   char name[20];
   char f;
   struct ec*link;
};
void append1(struct cc**abhishekjhawar,int number,char name[])
{
   struct cc*temp=(struct cc*)malloc(sizeof(struct cc));
   temp->number=number;
   for(int i=0;i<20;i++){
   temp->name[i]=name[i];
   }
   temp->link=NULL;
   if(*abhishekjhawar==NULL)
   {
      *abhishekjhawar=temp;
   }
   else
   {
      struct cc *t=*abhishekjhawar;
      while(t->link!=NULL)
      {
         t=t->link;
      }
      t->link=temp;
   }
}
void display1(struct cc*abhishekjhawar)
{
   int c=0;
   while(abhishekjhawar!=NULL)
   {
      for(int i=0;i<20;i++){
      printf("Name - %s \n",abhishekjhawar->name[20]);
      }
      printf("Phone Number - %d  ->  ",abhishekjhawar->number);
      abhishekjhawar=abhishekjhawar->link;
      c++;
   }
   printf("\nNumber of Passengers : %d\n",c);
}
void append2(struct ec**reg200905144,int number,char name[20],char f)
{
   struct ec*temp=(struct ec*)malloc(sizeof(struct ec));
   temp->number=number;
   for(int i=0;i<20;i++)
   {
   temp->name[i]=name[i];
   }
   temp->f=f;
   temp->link=NULL;
   if(*reg200905144==NULL)
   {
      *reg200905144=temp;
   }
   else
   {
      struct ec*t=*reg200905144;
      while(t->link!=NULL)
      {
         t=t->link;
      }
      t->link=temp;
   }
}
void display2(struct ec*reg200905144)
{
   int c=0;
   while(reg200905144=NULL)
   {
      for(int i=0;i<20;i++){
      printf("%c  ->  ",reg200905144->name);
      }
      printf("%d  ->  ",reg200905144->number);
      printf("%c  ->  ",reg200905144->f);
      reg200905144=reg200905144->link;
      c++;
   }
   printf("\nNumber of Passangers are : %d",c);
}
int main()
{
    struct cc*abhishekjhawar=NULL;
    struct ec*reg200905144=NULL;
    int opt,o,o2,num,n=1,n1;
    char name[20],f;
    while(n>0)
    {
       printf("Choose your option \n1)ADD \n2)Display\n");
       scanf("%d",&opt);
       switch (opt)
       {
       case 1:
       printf("Choose your option \n1)Chair Car \n2)Executive Chair Car \n");
       scanf("%d",&o);
       switch (o)
       {
       case 1:
       printf("Enter your Name :\n");
       scanf("%s",&name[20]);
       
       printf("Enter your Phone Number : \n");
       scanf("%d",&num);

       append1(&abhishekjhawar,num,name);
          break;
       case 2:
       printf("Enter your Name :\n");
       scanf("%s",&name[20]);
       printf("Enter your Phone Number : \n");
       scanf("%d",&num);
       printf("Enter your Preference (Veg or Non Veg) :\n");
       scanf("%c",&f);
       append2(&reg200905144,num,name,f);
          break;
       default:
          break;
       }
          break;
      case 2:
       printf("Choose your option \n1)Chair Car \n2)Executive Chair Car \n");
       scanf("%d",&o2);
       switch (o2)
       {
       case 1:
       display1(abhishekjhawar);
          break;
       case 2:
       display2(reg200905144);
          break;
       default:
          break;
       }
       default:
          break;
       }
    }
}



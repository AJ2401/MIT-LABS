#include <stdlib.h>
#include<stdio.h>
typedef struct dll
{
 int data;
 struct dll *prev;
 struct dll *next;
}DLL;
void insertFront(DLL *head, int num)
{
 DLL *temp = (DLL *)malloc(sizeof(struct dll));
 temp->data = num; temp->next = NULL;
 temp->prev = NULL;
 if (head->next == head)
 {
 temp->next = head;
 temp->prev = head;
 head->next = temp;
 head->prev = temp;
 head->data++;
 return;
 }
 temp->next = head->next;
 temp->prev = head;
 head->next->prev = temp;
 head->next = temp;
 head->data++;
}

void insertRear(DLL *head, int num)
{
 DLL *temp = (DLL *)malloc(sizeof(struct dll));
 temp->data = num;
 temp->next = NULL;
 temp->prev = NULL;
 if (head->next == head)
 {
 temp->next = head;
 temp->prev = head;
 head->next = temp;
 head->prev = temp;
 head->data++;
 return;
}
 temp->prev = head->prev;
 temp->next = head;
head->prev->next = temp;
 head->prev = temp;
 head->data++;
}

void deleteFront(DLL *head)
{
 DLL *temp;
 if (head->data == 0)
 {
 printf("DLL is empty");
 return;
 }
 temp = head->next;
 temp->next->prev = head;
 head->next = temp->next;
 head->data--;
 free(temp);
}

void deleteRear(DLL *head)
{
 DLL *temp;
 if (head->data == 0)
 {
 printf("DLL is empty");
 return;
 }
 temp = head->prev;
 temp->prev->next = head;
 head->prev = temp->prev;
 head->data--;
 free(temp);
}

void display(DLL *head)
{
 DLL *temp;
 if (head->prev == head)
 {
 printf("List is empty\n");
 return;
 }
 printf("\n");
 temp = head->next;
 while (temp->next != head)
 {
 printf("%d", temp->data);
 temp = temp->next;
 }
 printf("%d", temp->data);
}
DLL *addLongInt(DLL *a, DLL *b)
{
 DLL *add = (DLL *)malloc(sizeof(struct dll));
 add->data = 0;
 add->prev = add;
 add->next = add;
int carry = 0, rem = 0;
 int sum;
 DLL *temp1 = a->prev, *temp2 = b->prev;
 while (temp1 != a || temp2 != b)
 {
 sum = (temp1 != a ? temp1->data : 0) + (temp2 != b ? temp2->data : 0) + carry;
 rem = sum % 10;
 carry = sum / 10;
 insertFront(add, rem);
 if (temp1 != a)
 temp1 = temp1->prev;
 if (temp2 != b)
 temp2 = temp2->prev;
 }
 return add;
}

int main()
{
 printf("ABHISHEK JAHWAR 200905144\n");
 char num1[30], num2[30];
 printf("Enter two long numbers:-");
 printf("\n\nNUMBER 1: \n\n");
 scanf("%s",&num1);
 printf("\n\nNUMBER 2: \n\n");
 scanf("%s",&num2);
 printf("\n\nNumbers are:\n\n");
 printf("Number 1  : %s\n\n",num1);
 printf("Number 2  :%s\n\n",num2);
 DLL *a = (DLL *)malloc(sizeof(struct dll));
 a->data = 0;
 a->prev = a;
 a->next = a;
 DLL *b = (DLL *)malloc(sizeof(struct dll));
 b->data = 0;
 b->prev = b;
 b->next = b;
 DLL *c = (DLL *)malloc(sizeof(struct dll));
 c->data = 0;
 c->prev = c;
 c->next = c;
 int i;
 for (i = 0; num1[i] != '\0'; ++i)
 {
 insertRear(a, num1[i] - '0');
 }
 for (i = 0; num2[i] != '\0'; ++i)
 {
 insertRear(b, num2[i] - '0');
 }
 DLL *add = addLongInt(a, b);
 printf("\n\n Addition of two Long Integers of  %s  and   %s  is  :   \n",num1,num2);
 display(add);
 printf("\n\n");
 return 0;
}

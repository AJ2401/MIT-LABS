#include<stdio.h>
#include<stdlib.h>
#define max 100

void display(int arr[],int n)
{
	if(n==0)
	{
		printf("STACK is EMPTY!\n");
	}
	for(int i=0;i<n;i++)
	{
		printf("  %d  ",arr[i]);
	}

	printf("\n\n");
}
int main()
{
	int pro[max],cons[max],n;

	printf("Enter the Stack Value :\n\n");
	scanf("%d",&n);

	int c1=0,c2=0;
	int opt;
	while(1)
	{
		printf("\n\n---------------------------------------- PRODUCER STACK ------------------------------\n\n");
		display(pro,c1);
		printf("\n\n----------------------------------------CONSUMER STACK ------------------------------\n\n");
		display(cons,c2);
		printf("Choose your option 1)PRODUCER\t\t2)CONSUMER \n");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
			if(c1==n)
			{
				printf("PRODUCER STACK is FULL \n");
			}
			else
			{
				printf("Enter the ITEM : \n");
				scanf("%d",&pro[c1]);
				c1++;
			}
			break;
			case 2:
			if(c2=n)
			{
				printf("CONSUMER STACK is FULL \n");
			}
			else
			{
				printf("Enter the ITEM : \n");
				scanf("%d",&cons[c2]);
				c2++;
			}
			break;
			default:
			printf("WRONG CHOICE !!\n");
			break;
		}
	}

	return 0;
}
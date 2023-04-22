#include<stdio.h>
#include<stdlib.h>

void display(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("   %d   ",arr[i]);
	}
	printf("\n\n");
}

int main()
{
	int n;
	printf("Enter the Value of N : \n");
	scanf("%d",&n);

	int opt,temp,c1=0,c2=0;
	int pro[n],cus[n];


	while(1)
	{
		printf("\n\n--------------------------Producer--------------------------------\n\n");
		display(pro,c1);
		printf("\n\n--------------------------Consumer--------------------------\n\n");
		display(cus,c2);
		printf("Enter your Choice : \n1)Producer \n2)Consumer \n");
		scanf("%d",&opt);

		switch(opt)
		{
			case 1:
			if(c1==n)
			{
				printf("Producer Stack is FULL \n");
				break;
			}
			else{
			 printf("Enter the Element :\n");
			 scanf("%d",&pro[c1]);
			 c1++;
			}
			break;

			case 2:
			if(c2==n)
			{
				printf("Customer Stack is FULL \n");
				break;
			}
			else{
			 printf("Enter the Element :\n");
			 scanf("%d",&cus[c2]);
			 c2++;
			}
			break;

			default:
			printf("WRONG CHOICE !!\n");
			break;
		}


	}

}

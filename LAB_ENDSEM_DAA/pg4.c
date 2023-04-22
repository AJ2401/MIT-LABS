//First Fit && Best Fit && Worst Fit
#include<stdio.h>
#include<stdlib.h>

void Fallocating(int proc[],int block[],int p,int b)
{
	int alloc[p];
	int op[b];
	for(int i=0;i<p;i++)
	{
		alloc[i]=-1;
	}
	for(int i=0;i<b;i++)
	{
		op[i]=0;
	}
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<b;j++)
		{
			if(block[j]>=proc[i] && op[j]!=1)
			{
				alloc[i]=j+1;
				block[j]-=proc[i];
				op[i]=1;
				break;
			}
		}
	}
	printf("\n\n------------------------FIRST FIT------------------------------\n\n");
	printf("\nPROCESS\t\tPROCESS SIZE\t\tBLOCK NUMBER \n");
	for(int i=0;i<p;i++)
	{
		printf("\n\t\t%d\t\t%d\t\t%d\n",i+1,proc[i],alloc[i]);
	}
}
void Ballocating(int proc[],int block[],int p,int b)
{
	int alloc[p];
	int op[b];
	for(int i=0;i<p;i++)
	{
		alloc[i]=-1;
	}
	for(int i=0;i<b;i++)
	{
		op[i]=0;
	}
	for(int i=0;i<p;i++)
	{
		int best=-1;
		for(int j=0;j<b;j++)
		{
			if(block[j]>=proc[i] && op[j]==0){
				if(best==-1)
				{
					best=j;
				}
					if(block[best]>block[j])
					{
						best=j;
					}
		 }
		}
		if(best!=-1)
		{
			alloc[i]=best+1;
			block[best]-=proc[i];
			op[best]=1;
		}
	}
	printf("\n\n------------------------BEST FIT------------------------------\n\n");
	printf("\nPROCESS\t\tPROCESS SIZE\t\tBLOCK NUMBER \n");
	for(int i=0;i<p;i++)
	{
		printf("\n\t\t%d\t\t%d\t\t%d\n",i+1,proc[i],alloc[i]);
	}
}
void Wallocating(int proc[],int block[],int p,int b)
{
	int alloc[p];
	int op[b];
	for(int i=0;i<p;i++)
	{
		alloc[i]=-1;
	}
	for(int i=0;i<b;i++)
	{
		op[i]=0;
	}
	for(int i=0;i<p;i++)
	{
		int worst=-1;
		for(int j=0;j<b;j++)
		{
			if(block[j]>=proc[i] && op[j]==0){
				
				if(worst==-1)
				{
					worst=j;
				}
					if(block[worst]<block[j])
					{
						worst=j;
					}
		 }
		
		}

		if(worst!=-1)
		{
			alloc[i]=worst+1;
			block[worst]=block[worst]-proc[i];
			op[worst]=1;
		}
	}
	printf("\n\n------------------------WORST FIT------------------------------\n\n");
	printf("\nPROCESS\t\tPROCESS SIZE\t\tBLOCK NUMBER \n");
	for(int i=0;i<p;i++)
	{
		printf("\n\t\t%d\t\t%d\t\t%d\n",i+1,proc[i],alloc[i]);
	}
}
int main()
{
	int p,b;
	printf("Enter the Number of Processes : \n");
	scanf("%d",&p);
	printf("Enter the Number of MEMO Blocks : \n");
	scanf("%d",&b);

	int proc[p];
	int block[b];
	printf("Enter the Process Sizes : \n");
	for(int i=0;i<p;i++)
	{
		printf("Process  %d: \n",i+1);
		scanf("%d",&proc[i]);
	}
	printf("Enter the Block Sizes : \n");
	for(int i=0;i<b;i++)
	{
		printf("Block  %d: \n",i+1);
		scanf("%d",&block[i]);
	}
	Fallocating(proc,block,p,b);
	Ballocating(proc,block,p,b);
	Wallocating(proc,block,p,b);
}
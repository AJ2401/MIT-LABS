#include<stdio.h>
#include<stdlib.h>

void Fallocating(int proc[],int blocks[],int p,int b)
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
			if(blocks[j]>proc[i] && op[j]==0)
			{
				op[j]=1;
				alloc[i]=j+1;
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
void Ballocating(int proc[],int blocks[],int p,int b)
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
	int best=-1;
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<b;j++)
		{
			if(blocks[j]>proc[i] && opt[j]==0)
			{
				if(best==-1)
				{
					best=j;
				}
				if(blocks[best]>blocks[j])
			    {
						best=j;
				}
			}
		}

		if(best!=-1)
		{
			alloc[i]=best+1;
		}
	}
}
int main()
{

}
#include<stdio.h>
#include<stdlib.h>


int main()
{
	int p,f;
	printf("Enter the Page size : \n");
	scanf("%d",&p);

	printf("Enter the Frame size : \n");
	scanf("%d",&f);

	int pages[p],frames[f],j,pf=0;

	for(int i=0;i<f;i++)
	{
		frames[i]=-1;
	}
	printf("Enter the Pages : \n");
	for(int i=0;i<p;i++)
	{
		printf(" %d :\t",i+1);
		scanf("%d",&pages[i]);
	}

	for(int i=0;i<p;i++)
	{
		printf("\n\nPAGE :  %d\n",i+1);
		for(j=0;j<f;j++)
		{
			if(frames[j]==pages[i])
			{
				break;
			}
		}
		if(f==j)
		{
			frames[pf%f]=pages[i];
			pf++;
		}
		printf("\n\n--------------------------------------------------------------\n\n");
		for(int j=0;j<f;j++)
		{
			printf("  %d  ",frames[j]);
		}
	}
	printf("NUMBER  of PAGE Faults %d\n",pf);
}
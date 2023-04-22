#include<stdio.h>
#include<stdlib.h>


int main()
{
	int pf=0,c=0,f,p;
	printf("Enter the Number of Pages : \n");
	scanf("%d",&p);

	printf("Enter the Number of Frames : \n");
	scanf("%d",&f);

	int frames[f],page[p];
	for(int i=0;i<f;i++)
	{
		frames[i]=-1;
	}
	printf("Enter the Pages : \n");
	for(int i=0;i<p;i++)
	{
		printf(" %d :\t",i+1);
		scanf("%d",&page[i]);
	}
	int j;
	for(int i=0;i<p;i++)
	{
		printf("\nPAGE : %d\n",i+1);
		for(j=0;j<f;j++)
		{
			if(frames[j]==page[i])
			{
				break;
			}
		}
		if(j==f)
			{
				frames[pf%f]=page[i];
				pf++;
			}
		printf("\n\n--------------------------------------------------------------\n\n");
		for(int j=0;j<f;j++)
		{
			printf("  %d  ",frames[j]);
		}
	}

	printf("TOTAL NUMBER OF PAGE FAULTS IS : %d",pf);
}
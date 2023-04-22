//FIFO
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n,f;
	printf("Enter the Number of Pages : \n");
	scanf("%d",&n);
	printf("Enter the Frame size : \n");
	scanf("%d",&f);
	
	int pages[n],frames[f];

	for(int i=0;i<f;i++)
	{
		frames[i]=-1;
	}

	printf("Enter the String of Page reference : \n");
	for(int i=0;i<n;i++)
	{
		printf("Enter : %d\t",i+1);
		scanf("%d",&pages[i]);
	}

	int pf=0;
	for(int i=0;i<n;i++)
	{
		int j;
		printf("\n%d:\n",i+1);
		for(j=0;j<f;j++)
		{
			if(frames[j]==pages[i])
			{
				break;
			}
		}
		if(j==f)
		{
			frames[pf%f]=pages[i];
			pf++;
		}
		printf("\n\n------------------------------------------------\n\n");
		for(int j=0;j<f;j++){
			printf("  %d  ",frames[j]);
		}
		printf("\n\n------------------------------------------------\n\n");
	}
	printf("\n\nNumber of Page Falults : %d\n",pf);
}
#include<stdio.h>
#include<stdlib.h>


int main()
{
	int f,n,pf=0,pos;
	printf("Enter the Number of Pages : \n");
	scanf("%d",&n);
	printf("Enter the Number of Frames : \n");
	scanf("%d",&f);

	int frames[f],pages[n],temp[f];
	int c=0,a,b;

	for(int i=0;i<f;i++)
	{
		frames[i]=-1;
	}
	printf("Enter the PAGE SEQ : \n");
	for(int i=0;i<n;i++)
	{
		printf("Enter %d : \t",i+1);
		scanf("%d",&pages[i]);
	}


	for(int i=0;i<n;i++)
	{
		printf("\n\nPAGE : %d \n",i+1);
		a=0,b=0;
		for(int j=0;j<f;j++)
		{
			if(frames[j]==pages[i])
			{
				a=1;
				b=1;
				break;
			}
		}
		if(a==0)
		{
			for(int j=0;j<f;j++)
			{
				if(frames[j]==-1)
				{
					frames[j]=pages[i];
					b=1;
					pf++;
					break;
				}
			}
		}
		if(b==0)
		{
			for(int j=0;j<f;j++)
			{
				temp[j]=0;
			}
			int c=1;
			for(int j=i-1;c<f;j--)
			{
				for(int k=0;k<f;k++)
				{
					if(frames[k]==pages[j])
					{
						temp[k]=1;
					}
				}
				c++;
			}
			for(int j=0;j<f;j++)
			{
				if(temp[j]==0)
				{
					pos=j;
				}
			}
			frames[pos]=pages[i];
			pf++;
		}
		printf("\n\n------------------------------------------------\n");
		for(int j=0;j<f;j++)
		{
			printf("  %d  ",frames[j]);
		}
				printf("\n\n------------------------------------------------\n");

	}

	printf("\n\nThe Page Faults are : %d \n",pf);
}
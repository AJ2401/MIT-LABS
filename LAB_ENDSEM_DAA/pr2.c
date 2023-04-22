#include<stdio.h>
#include<stdlib.h>


int main()
{
	int f,p;
	printf("Enter the Page Size : \n");
	scanf("%d",&p);
	printf("Enter the Frame size : \n");
	scanf("%d",&f);

	int pages[p],frames[f],temp[f],pf=0,a,b;

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
		a=0,b=0;
		printf("\nPAGE : %d\n",i+1);
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
			int c=0;
			for(int j=0;j<f;j++)
			{
				temp[j]=0;
			}

			for(int k=p-1;c<f;k--)
			{
				for(int j=0;j<f;j++){
				if(frames[j]==pages[k])
				{
					temp[j]=1;
				}
			}
				c++;
			}
			int pos;
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
		printf("\n\n--------------------------------------------------------------\n\n");
		for(int j=0;j<f;j++)
		{
			printf("  %d  ",frames[j]);
		}
	}

	printf("NUMBER  of PAGE Faults %d\n",pf);
}
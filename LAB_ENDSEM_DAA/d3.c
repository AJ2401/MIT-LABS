//BANKER'S ALGO
#include<stdio.h>
#include<stdlib.h>


int main()
{
	int r,p;
	printf("Enter the Number of Resources : \n");
	scanf("%d",&r);
	printf("Enter the Number of Processes : \n");
	scanf("%d",&p);

	int max[p][r],need[p][r],alloc[p][r],avail[r],f[p],ans[p];

	for(int i=0;i<p;i++)
	{
		f[i]=0;
	}
	printf("Enter Max Resources for Processes : \n");
	for(int i=0;i<p;i++)
	{
		printf("\n\nPROCESS %d \t\n",i+1);
		for(int j=0;j<r;j++)
		{
			printf("Resource %d : \t",j+1);
			scanf("%d",&max[i][j]);
		}
	}

	printf("Enter ALLOCATED Resources for Processes : \n");
	for(int i=0;i<p;i++)
	{
		printf("\n\nPROCESS %d \t\n",i+1);
		for(int j=0;j<r;j++)
		{
			printf("Resource %d : \t",j+1);
			scanf("%d",&alloc[i][j]);
		}
	}
	    printf("\n\nEnter avail Resource \n");
		for(int j=0;j<r;j++)
		{
			printf("Resource %d : \t",j+1);
			scanf("%d",&avail[j]);
		}
	for(int i=0;i<p;i++)
	{
		// printf("\n\nPROCESS %d \t\n",i+1);
		for(int j=0;j<r;j++)
		{
		 need[i][j]=max[i][j]-alloc[i][j];	
		}
	}

	int c=0;

	for(int i=0;i<p;i++)
	{
		for(int j=0;j<p;j++)
		{
			if(f[j]==0)
			{
				int flag=0;
				for(int k=0;k<r;k++)
				{
					if(need[j][k]>avail[k])
					{
						flag=1;
						break;
					}
				}

				if(flag==0)
				{
					ans[c++]=j;
					for(int q=0;q<r;q++)
					{
						avail[q]=avail[q]+alloc[j][q];
						f[j]=1;
					}
				}
			}
		}
	}

	for(int i=0;i<p;i++)
	{
		if(f[i]==0)
		{
			printf("Unsafe State !\n");
			break;
			return -1;
		}
	}
	printf("\nSAFE SEQ :   \n");
	for(int i=0;i<p;i++)
	{
		printf("  <%d>  ",ans[i]);
	}

	return 0;
}
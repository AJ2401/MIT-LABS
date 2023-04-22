#include<stdio.h>
#include<stdlib.h>

int main()
{
	int p,r;
	printf("Enter the Number of Resources : \n");
	scanf("%d",&r);
	printf("Enter the Number of Process : \n");
	scanf("%d",&p);


	int max[p][r],need[p][r],alloc[p][r],avail[r],f[p],ans[p];
	int c=0;

	for(int i=0;i<p;i++)
	{
		f[i]=0;
	}

	printf("Enter the Max Resources : \n");
	for(int i=0;i<p;i++)
	{
		printf("PROCESS %d: \n",i+1);
		for(int j=0;j<r;j++)
		{
			printf("Resource %d : \t",j+1);
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter the ALLOCATED Resources : \n");
	for(int i=0;i<p;i++)
	{
		printf("PROCESS %d: \n",i+1);
		for(int j=0;j<r;j++)
		{
			printf("Resource %d : \t",j+1);
			scanf("%d",&alloc[i][j]);
		}
	}
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-alloc[i][j];
		}
	}
		printf("AVAILABLE Resource : \n");
		for(int j=0;j<r;j++)
		{
			printf("Resource %d : \t",j+1);
			scanf("%d",&avail[j]);
		}

		for(int i=0;i<p;i++)
		{
			for(int j=0;j<p;j++)
			{
				if(f[j]==0){
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
						for(int k=0;k<r;k++)
						{
							avail[k]=avail[k]+alloc[j][k];
						}
						f[j]=1;
				    }
			   }
			}

		}


		for(int i=0;i<p;i++)
		{
			if(f[i]==0)
				{
					printf("UNSAFE STATE !!\n");
					break;
					return -1;
				}
		}
		printf("\nSAFE SEQ \n");
		for(int i=0;i<p;i++)
		{
			printf("  <%d>  ",ans[i]);
		}

		return 0;
}
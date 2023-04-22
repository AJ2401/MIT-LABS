//Banker Algo
#include<stdio.h>
#include<stdlib.h>

int main()
{
	system("clear");
	int n,m;
	printf("Enter the Number of Resources : \n");
	scanf("%d",&n);
	printf("Enter the Number of Processes : \n");
	scanf("%d",&m);

	int max[n][m],need[n][m],alloc[n][m],avail[n],out[m];

	printf("Enter the Max Requirement \n\n");
	for(int i=0;i<m;i++)
	{
		printf("------------------------Process : \t%d\n",i+1);
		for(int j=0;j<n;j++)
		{
			printf("Resource : \t%d\t",j+1);
			scanf("%d",&max[j][i]);
		}
	}

	printf("Enter the Allocated Resources \n\n");
	for(int i=0;i<m;i++)
	{
		printf("----------------------------Process : \t%d\n",i+1);
		for(int j=0;j<n;j++)
		{
			printf("Resource : \t%d\t",j+1);
			scanf("%d",&alloc[j][i]);
		}
	}
	printf("Enter the Available Resources : \n\n");
	for(int i=0;i<n;i++)
	{
		printf("Resource : \t%d\t",i+1);
		scanf("%d",&avail[i]);
	}

	printf("The Need Required is : \n\n");
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			need[j][i]=max[j][i]-alloc[j][i];
			printf("\t%d\t",need[i][j]);
		}
		printf("\n");
	}

	printf("\n\n\n\n");
	int p=-1;
	int c=0;
	int f[m],s[m];
	for(int i=0;i<m;i++)
	{
		f[i]=0;
	}

	for(int i=0;i<m;i++)
	{
		if(f[i]==0)
		{
			p=i;
			for(int j=0;j<n;j++)
			{
				if(avail[j]<need[j][i])
				{
					p=-1;
					break;
				}
			}
		}
		if(p!=-1)
		{
			break;
		}
	}
	do{
	if(p!=-1)
	{
		s[c++]=p;
		for(int j=0;j<n;j++)
		{
			avail[j]+=alloc[j][p];
			alloc[j][p]=0;
			max[j][p]=0;
			f[p]=1;
		}
	}
	else{
		break;
	}
	}while(c!=m && p!=-1);

	if(c==m)
	{
		printf("The Safe Sequence is : \n\n");
		for(int i=0;i<m;i++)
		{
			printf("  %d  ",s[i]);
		}
	}
	else
	{
		printf("UNSAFE STATE !!\n\n");
	}
}
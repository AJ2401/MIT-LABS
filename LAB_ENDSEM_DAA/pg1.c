//LRU
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int pos;
	int a,b,pf=0;
	int f,n,c=0;;


	printf("Enter the Number of PAGES : \n");
	scanf("%d",&n);
	printf("Enter the Number of Frames :\n");
	scanf("%d",&f);
	int arr[n];
	int frame[f];
	int temp[f];
	for(int i=0;i<f;i++)
	{
		frame[i]=-1;
	}
	printf("Enter the String : \n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("\n\n");

	for(int i=0;i<n;i++)
	{
		printf("Page : %d\n",arr[i]);
		a=0;
		b=0;
		for(int j=0;j<f;j++)
		{
			if(frame[j]==arr[i])
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
				if(frame[j]==-1)
				{
					frame[j]=arr[i];
					b=1;
					pf++;
					break;
				}
			}
			if(b==0)
			{
				for(int j=0;j<f;j++)
				{
					temp[j]=0;
				}
				for(int j=i-1;c<f;j--)
				{
					for(int k=0;k<f;k++)
					{
						if(frame[k]==arr[j])
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
				frame[pos]=arr[i];
				pf++;
			}
		}
		printf("\n---------------------------------------------------------------\n");
		for(int j=0;j<f;j++)
		{
			printf("  %d  ",frame[j]);
		}
		printf("\n\n");
	}

	printf("\n\n\nPAGE FAULTS :  %d \n",pf);
}
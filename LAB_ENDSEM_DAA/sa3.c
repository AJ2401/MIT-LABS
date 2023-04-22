//RR SCHEDULING

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	printf("Enter the Number of Process : \n");
	scanf("%d",&n);

	int pro[n];
	int bt[n];
	int wt[n];
	int tat[n];
	int rem[n];
	float avgt;
	float avgtt;
	int t1;
	int ta;
	int c=0;
	int q1;
	int d=0;
	int temp;

	printf("Enter the Processes and Burst Time : \n");
	for(int i=0;i<n;i++)
	{
		printf("Enter the Process : \n");
		scanf("%d",&pro[i]);
		printf("Enter the Burst Time : \n");
		scanf("%d",&bt[i]);
		rem[i]=bt[i];
	}

	printf("\n\n Enter the Quantum Time : \n");
	scanf("%d",&q1);

	while(1)
	{
		for(int i=0;i<n;i++)
		{
			temp=q1;
			if(rem[i]==0)
			{
				c++;
				continue;
			}
			if(rem[i]>q1)
			{
				rem[i]=rem[i]-q1;
			}
			else
			{
				if(rem[i]>=0)
				{
					temp=rem[i];
					rem[i]=0;
				}
			}
			   d=d+temp;
				tat[i]=d;
		}
		if(c==n)
		{
			break;
		}
	}

	printf("\nPROCESS\t\tBURST TIME\t\tWAITING TIME\t\tTURN AROUND TIME\n");
	int w=0,a=0;
	for(int i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
		w=w+wt[i];
		a=a+tat[i];
	}
	for(int i=0;i<n;i++)
	{
		printf("%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\n",pro[i],bt[i],wt[i],tat[i]);
	}
	avgt=(float)w/n;
	avgtt=(float)a/n;

	printf("\n\nThe TOTAL WAITING TIME is : \t%d\n",w);
	printf("\nThe AVERAGE WAITING TIME is : \t%f\n",avgt);
	printf("\n\nThe TOTAL TAT TIME is : \t%d\n",a);
	printf("\nThe AVERAGE TAT TIME is : \t%f\n",avgtt);

}
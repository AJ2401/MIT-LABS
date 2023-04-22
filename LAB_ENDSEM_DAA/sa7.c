#include<stdio.h>
#include<stdlib.h>


int main()
{
	int n;
	printf("Enter the Number of Processes : \n");
	scanf("%d",&n);

	int pro[n],bt[n],wt[n],tat[n],ar[n];
	int t,t1;
	float tavg,tatavg;

	printf("Enter the Process Description : \n");
	for(int i=0;i<n;i++)
	{
		printf("Enter the process Number: \n");
		scanf("%d",&pro[i]);
		printf("Enter the Burst Time : \n");
		scanf("%d",&bt[i]);
		printf("Enter the Arival Time : \n");
		scanf("%d",&ar[i]);
	}
	int temp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(bt[i]<bt[j])
			{
				temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;

				temp=pro[i];
				pro[i]=pro[j];
				pro[j]=temp;
			}
		}
	}

	wt[0]=0;
	for(int i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1]+ar[i];
	}
	for(int i=0;i<n;i++)
	{
		t=wt[i]+t;
		tat[i]=wt[i]+bt[i];
		t1=t1+tat[i];
	}
	printf("\nPROCESS\t\tBURST TIME\t\tARRIVAL TIME\t\tWAITING TIME\t\tTURN AROUND\n");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t\n",pro[i],bt[i],ar[i],wt[i],tat[i]);
	}
	tavg=(float)t/n;
	tatavg=(float)t1/n;
	printf("The Total WAITING TIME is : %d \n",t);
	printf("The AVERAGE WAITING TIME is : %f\n",tavg);
	printf("The Total TAT is : %d \n",t1);
	printf("The AVERAGE TAT is : %f\n",tatavg);
}
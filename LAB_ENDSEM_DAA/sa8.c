//SJF WITHOUT ARRIVAL TIME
#include<stdio.h>
#include<stdlib.h>


int main()
{
	int n;
	printf("Enter the Number of Processes : \n");
	scanf("%d",&n);

	int bt[n],wt[n],tat[n],pro[n];
	int t,t1;
	float avgt,avgtat;

	printf("Enter the Process Descp : \n");
	for(int i=0;i<n;i++)
	{
		printf("Enter the process : \n");
		scanf("%d",&pro[i]);
		printf("Enter the Burst Time : \n");
		scanf("%d",&bt[i]);
	}
	int temp;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(bt[j]>bt[j+1])
			{
				temp=bt[j];
				bt[j]=bt[j+1];
				bt[j+1]=temp;

				temp=pro[j];
				pro[j]=pro[j+1];
				pro[j+1]=temp;
			}
		}
	}

	wt[0]=0;
	for(int i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
	}
	for(int i=0;i<n;i++)
	{
		t=t+wt[i];
		tat[i]=wt[i]+bt[i];
		t1=tat[i]+t1;
	}
	printf("\nPROCESS\t\tBURST TIME\t\tWAITING TIME\t\tTURN AROUND TIME\n");

	for(int i=0;i<n;i++)
	{
		printf("\n%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t \t\n",pro[i],bt[i],wt[i],tat[i]);
	}
	printf("\n------------------------------------------------\n");
	avgt=(float)t/n;
	avgtat=(float)t1/n;
	printf("Total WAITING TIME : %d\n",t);
	printf("Average WAITING TIME : %f\n",avgt);
	printf("Total TAT TIME : %d\n",t1);
	printf("Average TAT TIME : %f\n",avgtat);
}

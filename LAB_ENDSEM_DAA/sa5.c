//FCFS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n;
	printf("Enter the Number of Process : \n");
	scanf("%d",&n);

	int pro[n],bt[n],wt[n],tat[n];
	int t,t1,avgt,avgtat;

	printf("Enter the Burst Time : \n");
	for(int i=0;i<n;i++)
	{
		printf("Enter the Process Number : \n");
		scanf("%d",&pro[i]);
		printf("Enter the Process BT : \n");
		scanf("%d",&bt[i]);
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
	avgt=t/n;
	avgtat=t1/n;
	printf("Total WAITING TIME : %d\n",t);
	printf("Average WAITING TIME : %d\n",avgt);
	printf("Total TAT TIME : %d\n",t1);
	printf("Average TAT TIME : %d\n",avgtat);
}
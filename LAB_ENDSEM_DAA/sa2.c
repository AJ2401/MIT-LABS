//NON-PRE-EMPTIVE
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	printf("Enter the Number of Process : \n");
	scanf("%d",&n);

	int pro[n];
	int wt[n];
	int bt[n];
	int tt[n];
	float avgt;
	int t;
	int tt1;
	float avgtt;

	printf("Enter the Burst Time :  \n");
	for(int i=0;i<n;i++)
	{
		printf("Enter the Process : \n");
		scanf("%d",&pro[i]);
		printf("Enter the Burst Time : %d \n",i+1);
		scanf("%d",&bt[i]);
	}
	printf("\n----------------------------------\n");
	//Bubble Sort
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
	t=0;
	wt[0]=0;
	for(int i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		t=t+wt[i];
	}
	avgt=(float)t/n;
	tt1=0;
	for(int i=0;i<n;i++)
	{
		tt[i]=wt[i]+bt[i];
		tt1=tt1+tt[i];
	}
	avgtt=(float)tt1/n;

	printf("\nPROCESS\t\tBURST TIME\t\tWAITING TIME\t\tTHOUGH TIME \t\t\n");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t\t\t%d\t\t\t%d\t\t\t%d\n",pro[i],bt[i],wt[i],tt[i]);
	}
	printf("\n\n------------------------------------------------GANTT CHART ---------------------------------------------------------\n\n");
	for(int i=0;i<n;i++)
	{
		printf("\t%d\t",wt[i]);
	}
		printf("\n\n-----------------------------------------------------------------------------------------------\n\n");

	for(int i=0;i<n;i++)
	{
		printf("        %d       ",pro[i]);
	}
	printf("\n\n-------------------------\n\n");
	printf("TOTAL WAITING TIME : \t%d\n",t);
	printf("AVGERAGE WAITING TIME : \t%f\n",avgt);
	printf("TOTAL THOUGH PUT TIME : \t%d\n",tt1);
	printf("AVGERAGE THOUGH PUT TIME : \t%f\n",avgtt);
}
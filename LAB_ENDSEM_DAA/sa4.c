#include<stdio.h>
#include<stdlib.h>
#define max 5

int main()
{
	int n;
	printf("Enter the Number of Processes : \n");
	scanf("%d",&n);

	int bt[n],tat[n],pri[n],pos,wt[n],temp;

	printf("Enter the Process Burst Time AND PRIRORITY : \n");
	for(int i=0;i<n;i++)
	{
		printf("Enter Bt of Element %d \n",i+1);
		scanf("%d",&bt[i]);
		printf("Enter PRIRORITY of Element %d \n",i+1);
		scanf("%d",&pri[i]);
	}	

	for(int i=0;i<n;i++)
	{
		pos=i;
		for(int j=i+1;j<n;j++)
		{
			if(pri[j]<pri[pos])
			{
				pos=j;
			}
		}
		temp=pri[i];
		pri[i]=pri[pos];
		pri[pos]=temp;

		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
	}
	wt[0]=0;
	int w,a;
	for(int i=1;i<n;i++)
	{
		wt[i]=wt[i-1]+bt[i-1];
		w=w+wt[i];
	}
	for(int i=0;i<n;i++)
	{
		tat[i]=wt[i]+bt[i];
		a=a+tat[i];
	}
	float avgt=(float)w/n;
	float avgtt=(float)a/n;

	printf("\n\nPROCESS\t\tBURST TIME\t\tWAITING TIME\t\tTHROUGHT OUT\n");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t\t\t%d\t\t\t%d\t\t%d\t\t",i+1,bt[i],wt[i],tat[i]);
	}
	printf("\n---------------------------------------------------\n");
	printf("\nTOTAL WAITING TIME : \t%d\n",w);
	printf("\nAVERAGE WAITING TIME : \t%f\n",avgt);
	printf("\nTOTAL TAT TIME : \t%d\n",a);
	printf("\nAVERAGE TAT TIME : \t%f\n",avgtt);
}
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	printf("Enter the Number of Process : \n");
	scanf("%d",&n);

	int pro[n],bt[n],wt[n],tat[n];
	int t,t1;
	float tavg,tatavg;


	printf("Enter the Burst Time and Processes : \n");
	for(int i=0;i<n;i++)
	{
		printf("Enter the Proccess Number : \n");
		scanf("%d",&pro[i]);
		printf("Enter the Burst Time : \n");
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

	printf("\nPROCESS\t\tBURST TIME\t\tWAITING TIME\t\tTURN AROUND\n");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t\n",pro[i],bt[i],wt[i],tat[i]);
	}
	tavg=(float)t/n;
	tatavg=(float)t1/n;
	printf("The Total WAITING TIME is : %d \n",t);
	printf("The AVERAGE WAITING TIME is : %f\n",tavg);
	printf("The Total TAT is : %d \n",t1);
	printf("The AVERAGE TAT is : %f\n",tatavg);

}
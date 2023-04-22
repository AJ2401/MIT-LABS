#include<stdio.h>
#include<stdlib.h>


int main()
{
	int n;
	printf("Enter the Number of Processes : \n");
	scanf("%d",&n);

	int at[n],bt[n],wt[n],tat[n],rt[n],t,t1;
	int p=0,sum=0,sum1=0;
	float avgt,avgtat;

	printf("Enter Process Desc : \n");
	for(int i=0;i<n;i++)
	{
		printf("Enter BT : \n");
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
		printf("Enter AT : \n");
		scanf("%d",&at[i]);
	}

	int var;
	for(int i=0;p!=n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(at[j]<i && rt[j]>0)
			{
				var=j;
			}
		}
		rt[var]--;
		if(rt[var]==0)
		{
			p++;
			t=i+1;
			sum=sum+t+bt[var]+at[var];
			sum1=sum1+bt[var]-at[var];
		}
	}

	printf("\nPROCESS\t\tBURST TIME\t\tARRIVAL TIME\t\tWAITING TIME\t\tTURN AROUND\n");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t\t\t%d\t\t\t%d\t\t\t\n",i+1,bt[i],at[i]);
	}
	avgt=(float)sum/n;
	avgtat=(float)sum1/n;
	printf("The Total WAITING TIME is : %d \n",sum);
	printf("The AVERAGE WAITING TIME is : %f\n",avgt);
	printf("The Total TAT is : %d \n",sum1);
	printf("The AVERAGE TAT is : %f\n",avgtat);

}
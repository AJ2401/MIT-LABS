#include<stdio.h>
#include<stdlib.h>


int main()
{
	int n;
	printf("Enter the Number of Process : \n");
	scanf("%d",&n);

	int pro[n],wt[n],bt[n],tat[n],rem[n];
	int t,t1,qt,c=0;
	float tavg,tatavg;
	printf("Enter the Process Desc : \n");
	for(int i=0;i<n;i++){
		printf("Enter the Process Number : \n");
		scanf("%d",&pro[i]);
		printf("Enter the Burst Time : \n");
		scanf("%d",&bt[i]);
		rem[i]=bt[i];
	}
	
	printf("Enter the Quantum Time : \n");
	scanf("%d",&qt);

	int a=0;
	while(1)
	{
		for(int i=0;i<n;i++)
		{
			int temp=qt;
			if(rem[i]==0)
			{
				c++;
				continue;
			}
			if(rem[i]>qt){
				rem[i]=rem[i]-qt;
			}
			else
			{
				if(rem[i]>=0)
				{
					temp=rem[i];
					rem[i]=0;
				}
			}
			a=a+temp;
			tat[i]=a;
		}

		if(c==n)
		{
			break;
		}
	}

	for(int i=0;i<n;i++)
	{
		wt[i]=tat[i]-bt[i];
	}
	for(int i=0;i<n;i++)
	{
		t=wt[i]+t;
		t1=tat[i]+t1;
	}

	printf("\nPROCESS\t\tBURST TIME\t\tWAITING TIME\t\tTURN AROUND\n");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\n",pro[i],bt[i],wt[i],tat[i]);
	}
	tavg=(float)t/n;
	tatavg=(float)t1/n;
	printf("The Total WAITING TIME is : %d \n",t);
	printf("The AVERAGE WAITING TIME is : %f\n",tavg);
	printf("The Total TAT is : %d \n",t1);
	printf("The AVERAGE TAT is : %f\n",tatavg);
}
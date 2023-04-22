//Scheduling ALGOS 
//FCFS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main()
{
	int n;
	printf("Enter the Number of processes : \n");
	scanf("%d",&n);

	int burst[n];
	int wait[n];
	int t;
	float avg;

	printf("Enter the Burst Time : \n");
	for(int i=0;i<n;i++)
	{
		printf("Enter the Burst time for Process %d\n",i+1);
		scanf("%d",&burst[i]);
	}

	wait[0]=0;
	for(int i=1;i<n;i++)
	{
		wait[i]=wait[i-1]+burst[i-1];
	}
	t=0;
	for(int i=0;i<n;i++)
	{
		t=t+wait[i];
	}
	avg=t/n;

	printf("\n\nPROCESS\t\tBURST TIME\t\tWAITING TIME\t\t\n");
	for(int i=0;i<n;i++)
	{
		printf("\n%d\t\t\t%d\t\t\t%d\t\t",i+1,burst[i],wait[i]);
	}
	printf("\n---------------------------------------------------\n");
	printf("\nTOTAL WAITING TIME : \t%d\n",t);
	printf("\nAVERAGE WAITING TIME : \t%f\n",avg);
}
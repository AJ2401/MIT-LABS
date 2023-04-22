#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define max 10
int flag[2];
int turn;
int ans=0;


void locking()
{
	flag[0]=flag[1]=0;
	turn=0;
}
void lock(int a)
{
	flag[a]=1;
	turn=1-a;

	while(flag[1-a]==1 && turn==1-a);
}
void unlock(int a)
{
	flag[a]=0;
}

void*func(void*a)
{
	int i=0;
	int s=(int)a;
	printf("Thread Entered %d \n",s);
	lock(s);
	for(int i=0;i<max;i++)
	{
		ans++;
	}

	unlock(s);
}

int main()
{
	locking();
	pthread_t t1,t2;

	pthread_create(&t1,NULL,func,(void*)0);
	pthread_create(&t2,NULL,func,(void*)1);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	printf("ACTUAL COUNT %d \n",ans);
}
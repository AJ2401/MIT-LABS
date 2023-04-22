#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char*arr[]={"int","char","if","else","switch","case","float","double","long","break","continue","singed","unsinged"};

int Keywords(char*key)
{
	for(int i=0;i<sizeof(arr)/sizeof(char*);i++)
	{
		if(strcmp(key,arr[i])==0)
		{
			printf("\nIt is a Keyword  : %s\n",key);
			return(1);			
		}
	}
	return(0);
}
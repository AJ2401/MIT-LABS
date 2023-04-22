#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char*arr1[]={"*","|","&",".",";","_","-"};
int Special(char*s)
{
	for(int i=0;i<sizeof(arr1)/sizeof(char*);i++){
	if(strcmp(s,arr1[i])==0){
		printf("\nIT is a Special Character : %s \n",s);
		return(1);
	}
}
	return(0);
}

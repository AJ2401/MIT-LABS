
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char*arr[]={"char","int","cosnt","float","unsinged","singed","long","double","if","else","switch","case","break","continue"};
int search(char*a)
{
	for(int i=0;i<sizeof(arr)/sizeof(char*);++i)
	{
		if(strcmp(a,arr[i])==0)
		{
			return(1);
		}
	}
	return(0);
}

int main()
{
	FILE *F1,*F2;
	int a,b=0,c;
	char buff[12];
	F1=fopen("prog.c","r");

	if(F1==NULL)
	{
		printf("Cannot open the File !! "); 
	}

	//F2=fopen("out.c","w+");
	//a=getc(F1);
	a=getc(F1);
	while(a!=EOF)
	{
		if(a>='A' && a<='Z' && a>='a' && a<='z')
		 //if(isalpha(a))
		{
				while(a!=' ' && a!=EOF)
				{
					buff[b++]=a;
					a=getc(F1);
				}
				if(search(buff)==1)
				{
					printf("  %s \n",buff);
				}
		}
		b=0;
			//putc(a,F2);
		a=getc(F1);
	}
	//printf("Copied the Content into the Another File \n");
	fclose(F1);
	//fclose(F2);
	return(0);
}

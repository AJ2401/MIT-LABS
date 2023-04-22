#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *f1,*f2;
	char file[100],c;
	printf("Enter the filename :");
	scanf("%s",file);
	f1=fopen(file,"r");
	if(f1==NULL)
	{
		printf("Cannot open");
		exit(0);
	}
	else
	{
	
		printf("Enter the Filename to open :");
		scanf("%s",file);
		f2=fopen(file,"w");
		fseek(f1,0,SEEK_END);
		int s=ftell(f1);
		printf(" The Number of Characters are %d ",s);
		c=fgetc(f1);
		for(int i=2;i<s;i++)
		{
			fseek(f1,-i,SEEK_END);
			fputc(c,f2);
			c=fgetc(f1);
		}
		printf("Contents Copied ");
		fclose(f1);
		fclose(f2);
		return(0);
	}
}

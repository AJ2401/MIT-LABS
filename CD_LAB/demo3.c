#include<stdio.h>
#include<stdlib.h>

int main()
{
	FILE *F1,*F2,*F3;
	char file[100],c1,c2;
	printf("Enter the First File : \n");
	scanf("%s",file);
	F1=fopen(file,"r");
	printf("Enter the Second File : \n");
	scanf("%s",file);
	F2=fopen(file,"r");
	if(F1==NULL|| F2==NULL)
	{
	printf("Cannot Open up the Files \n");
	exit(0);
	}
	printf("Enter the Filename to open To Write : \n");
	scanf("%s",file);
	F3=fopen(file,"w+");
	c1=fgetc(F1);
	c2=fgetc(F2);
	while(c1!=EOF && c2!=EOF)
	{
			
		while(c1!='\n' && c1!=EOF)
		{
		fputc(c1,F3);
		//printf("%c",c1);
		c1=fgetc(F1);
		}
	c1=getc(F1);
	
		while(c2!='\n'&& c2!=EOF)
		{
		      fputc(c2,F3);
				//printf("%c",c2);
		      c2=fgetc(F2);
		}
	c2=getc(F2);
	}
	while(c2!=EOF)
		{
		      fputc(c2,F3);
				//printf("%c",c2);
		      c2=fgetc(F2);
		}

		while(c1!=EOF)
		{
		fputc(c1,F3);
		//printf("%c",c1);
		c1=fgetc(F1);
		}

	printf("\nContents copied into %s ",file);
	fclose(F1);
	fclose(F2);
	fclose(F3);
	return(0);
}
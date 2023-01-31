#include<stdio.h>
#include<string.h>

void bruteforcestringmatch(char*,char*);

void main()
{
	char t[10];
  	char p[10];
  	printf("enter the text string:");
  	scanf("%s",t);
  	printf("enter the pattern string:");
  	scanf("%s",p);
	bruteforcestringmatch(p,t);
}


void bruteforcestringmatch(char*p,char*t)
{
	for(int i=0;i<=strlen(t)-strlen(p);i++)
	{
		int j;
		for(j=0;j<strlen(p);j++)
		{
			if(t[i+j]!=p[j])
				break;
		}
		if(j==strlen(p))
			printf("Pattern found at index %d.\n",i);
	}
}

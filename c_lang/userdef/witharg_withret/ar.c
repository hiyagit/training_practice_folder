#include<stdio.h>
int sum(int,int);
void main()
{int a,b,c;
	printf("Enter two numbers:");
	scanf("%d%d",&a,&b);
	c=sum(a,b);
	printf("Sum: %d",c);
}
int sum(int a,int b)
{int c;
	c=a+b;
	return c;
}

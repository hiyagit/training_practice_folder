#include<stdio.h>
void sum(int,int);
void main()
{int a,b;
	printf("Enter two numbers:");
	scanf("%d%d",&a,&b);
	sum(a,b);
}
void sum(int a,int b)
{int c;
	c=a+b;
	printf("Sum: %d",c);
}

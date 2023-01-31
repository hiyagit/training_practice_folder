#include<stdio.h>
void sum();
void main()
{
	 sum();
}
void sum()
{int a,b,c;
	printf("Enter two numbers:");
	scanf("%d%d",&a,&b);
	c=a+b;
	printf("Sum: %d",c);
}


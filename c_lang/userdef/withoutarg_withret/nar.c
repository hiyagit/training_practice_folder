#include<stdio.h>
int sum();
void main()
{int c;
	c=sum();
	printf("Sum: %d",c);
}
int sum()
{int a,b,c;
	printf("Enter two numbers:");
	scanf("%d%d",&a,&b);
	c=a+b;
	return c;
}

#include<stdio.h>

int main()
{ int x,y,z,n,s;
	printf("Enter the 1st and 2nd digits:");
	scanf("%d%d",&x,&y);
	printf("Series length:");
	scanf("%d",&n);
	printf("Fibonacci series:%d %d",x,y);
	for(z=0;z<=n;z++)
	{	s=x+y;
		printf(" %d ",s);
	        x=y;
	       y=s;
	}
 return 0;
} 

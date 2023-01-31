#include<stdio.h>

int main()
{
	int i,n,count=0;
	printf("Enter any number:");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
	{ if(n%i==0)
		count++;
	}
	if(count==2)
	{ printf("Number is prime number.");
	}
	else
	{ printf("Number is not prime number.");
	}
	return 0;
}


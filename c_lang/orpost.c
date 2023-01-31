#include<stdio.h>

int main()
{ int n,i=0,j=1,k=1;

	n = i++||j++||k++;
		printf("%d%d%d%d",n,i,j,k);
	
	return 0;
}


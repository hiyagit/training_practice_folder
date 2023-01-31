#include<stdio.h>
void swap(int a[],int*,int*);
void main()
{int i,j,n,loc;
	printf("Enter the limit of array:");
        scanf("%d",&n);
        int a[n];
        printf("Enter the element of arrays:");
        for(i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
        }
	for(i=0;i<n-1;i++)
	{
		loc=i;
		for(j=i+1;j<=n-1;j++)
		{
			if(a[j]<a[loc])
				loc=j;
		}
		if(loc!=i)
			swap(a,&a[i],&a[loc]);
	}
	printf("Selection sorted array: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

void swap(int a[],int *b,int *c)
{int temp;
	temp=*b;
	*b=*c;
	*c=temp;
}


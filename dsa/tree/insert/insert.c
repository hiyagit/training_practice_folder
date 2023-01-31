#include<stdio.h>

void main()
{int i,j,n,temp;
	printf("Enter the limit of array:");
        scanf("%d",&n);
        int a[n];
        printf("Enter the element of arrays:");
        for(i=0;i<n;i++)
        {
                scanf("%d",&a[i]);
        }
	for(i=1;i<=n-1;i++)
	{
		j=i-1;
		temp=a[i];
		while(j>=0&&a[j]>temp)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
	printf("Insertion sorted array: ");
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}

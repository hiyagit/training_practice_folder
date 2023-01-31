#include<stdio.h>
void swap(int a[],int *,int *);
//void swap(int*,int*);
void main()
{int n,i,j,temp;
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
		int flag=0;
		for(j=0;j<=n-2-i;j++)
		{
			if(a[j]>a[j+1])
			{
				//temp=a[j];
				//a[j]=a[j+1];
				//a[j+1]=temp;
				swap(a,&a[j],&a[j+1]);
				flag=1;
			}
		}
		if(flag==0)
			break;
	}
	printf("Bubble sorted elements of array: ");
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


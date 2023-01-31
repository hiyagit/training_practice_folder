#include<stdio.h>

int n;
int a[10];

void swap(int *n1,int *n2)
{
   int temp=*n1;
   *n1=*n2;
   *n2=temp;
}

void quick(int low,int high)
{
	int pivot=a[low];
 	int i=low+1;
	int j=high;
	if(low<high)
	{
	  while(1)
	  {
		while(a[j]>pivot)
		  j--;
		while(i<=high&&a[i]<pivot)
		  i++;
		if(i<j)
		swap(&a[i],&a[j]);
		else
		 break;
	  }
	swap(&a[low],&a[j]);
	quick(low,j-1);
	quick(j+1,high);
	}
}


void main()
{
  
  int i;
  printf("\nenter the size:");
  scanf("%d",&n); 
  printf("enter the array element:");
 
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);
  
  printf("quick sort:");
  quick(0,n-1);
  
  for(int i=0;i<n;i++)
   {
     printf("%d",a[i]);
   }

}


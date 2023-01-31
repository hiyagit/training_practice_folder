#include<stdio.h>
#include<stdlib.h>

void msort();
void merge();

int a[50], size; 

void msort(int low, int high)
	{
		if(low < high)
		{
			int mid = (low + high)/2;
			msort(low,mid);
			msort(mid+1,high);
			merge(low, mid, high);
		}
	}

void merge(int low, int mid, int high)
	{
		int i, j, k = 0, index = low;
		i = low, j = mid+1;
		int *l3;
		l3 = (int *)malloc(sizeof(high-low+1));

		while(i <= mid && j <= high)
		{
			if(a[i] < a[j])
				l3[index++] = a[i++];
			else
				l3[index++] = a[j++];
		}
		while(i <= mid)
			l3[index++] = a[i++];
		while(j <= high)
			l3[index++] = a[j++];
		for(k = low; k<index;k++)
			a[k] = l3[k];
		free(l3);
	}

int main()
	{
		printf("\nEnter the array size: ");
		scanf("%d",&size);

		printf("\nEnter the elements of array: ");
		for(int i =0; i < size; i++)
		{
			scanf("%d", &a[i]);
		}
		
		printf("\nArray: ");
		for(int i =0; i < size; i++)
		{
			printf(" %d ", a[i]);
		}
		printf("\n");


		msort(0,size-1);

		printf("\nArray after sorting: ");
		for(int i = 0; i < size; i++)
		{
			printf(" %d ", a[i]);
		}
		printf("\n");

	}

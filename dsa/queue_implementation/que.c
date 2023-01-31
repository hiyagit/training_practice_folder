/*Queue implementation using array implementation*/

#include<stdio.h>

struct queue{
	int size;
	int front,rear;
	int q[];
}que;

int frontElement()
{
	return que.q[que.front];
}

int rearElement()
{
	return que.q[que.rear];
}

int underflow()
{
	if(que.front==-1&&que.rear==-1)
		return 1;
	return 0;
}

int overflow()
{
	if(que.rear==que.size-1)
		return 1;
	return 0;
}

void Display()
{int i;
	if(!underflow())
	{
		for(i=que.front;i<=que.rear;i++)
		{
			printf("Element at %d is %d",i,que.q[i]);
		}
	}
	else
		printf("Queue is empty.\n");
}

void Enqueue(int element)
{
	if(!overflow())
	{
		if(que.front==-1&&que.rear==-1)
			que.front++;
		que.rear++;
		que.q[que.rear]=element;
		printf("Enqueued element: %d\n",que.q[que.rear]);
	}
	else
		printf("Queue is full.\n");
}

int Dequeue()
{int x=-1;
	if(!underflow())
	{x=que.q[que.front];
		if(que.front==que.rear)
		{	que.front=-1;
			que.rear=-1;
		}
		else
			que.front++;
	}
	else
		printf("Queue is empty.\n");
	return x;
}

int main()
{
	que.size;
	que.rear=-1;
	que.front=-1;
	printf("Enter the number of element:");
	scanf("%d",&que.size);
	que.q[que.size];
	printf("Enter the %d elements of array:",que.size);
	int i;
	for(i=0;i<que.size;i++)
	{int j;
		scanf("%d",&j);
		Enqueue(j);
	}
	printf("Front element: %d\n",frontElement());
	printf("Rear element: %d\n",rearElement());
	for(i=0;i<=que.size;i++)
	{
		printf("Dequeued element: %d\n",Dequeue());
	}
	printf("Front element: %d\n",frontElement());
	printf("Rear element: %d\n",rearElement());

	return 0;
}

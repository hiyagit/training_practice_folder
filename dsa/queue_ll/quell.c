/*Queue implementation using linked list implementation*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *front;
struct node *rear;

void Enqueue(int element)
{
	struct node *temp;
	temp=malloc(sizeof(struct node));
	temp->data=element;
	temp->next=NULL;
	if(front==NULL&&rear==NULL)
	{
		front=temp;
		rear=temp;
	}
	else
	{
		rear->next=temp;
		rear=temp;
	}
}

int Dequeue()
{int x=-1;
	struct node *temp;
	if(front!=NULL)
	{
		temp=front;
		x=temp->data;
		front=temp->next;
		free(temp);
	}
	else
		printf("Queue is Empty...");
	return x;
}

void Display()
{
	if(front==NULL&&rear==NULL)
		printf("Queue is Empty...");
	else
	{
		struct node *temp;
        	temp=malloc(sizeof(struct node));
		temp=front;
		while(temp)
		{
			printf("%d",temp->data);
			temp=temp->next;
		}
	}
}
			

void menu()
{int n,j;
	while(1)
	{       printf("****************************************************************************\n");
		printf("Enter 1 to Display the Queue.\n");
		printf("Enter 2 to Enqueue an element into Queue.\n");
		printf("Enter 3 to Dequeue an element of Queue.\n");
		printf("Enter 5 to Exit from the program.\n");
		scanf("%d",&n);
		printf("****************************************************************************\n");
		switch(n)
		{
			case 1:
				printf("Elements inside the Queue:");
				Display();
				printf("\n");
				break;
			case 2:
				printf("Enter the element you want to enqueue into queue:");
				scanf("%d",&j);
				Enqueue(j);
				break;
			case 3:
				printf("Dequeued element: %d\n",Dequeue());
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("You have entered Invalid Input.\n");
		}//switch
	}//while
}//func


void main()
{
	menu();
}

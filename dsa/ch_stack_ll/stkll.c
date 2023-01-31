/*Stack implementation using linked list implementation*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *list;

struct stack{
	struct node *tos;
};
struct stack *sta;

int IsEmpty()
{
	if(sta->tos==NULL)
		return 1;
	return 0;
}

int length()
{
	int size=0;
	if(IsEmpty())
		return 0;
	list=sta->tos;
	while(list)
	{
		size++;
		list=list->next;
	}
	return size;
}

void push(int data)
{
	list=malloc(sizeof(struct node));
	list->data=data;
	list->next=sta->tos;
	sta->tos=list;
	printf("Pushed element: %d\n",data);
}

int pop()
{
	int data;
	if(!IsEmpty())
	{
		list=sta->tos;
		sta->tos=sta->tos->next;
		data=list->data;
		free(list);
	}
	else
	{
		printf("Stack is Empty    (pop)\n");
	}
	return data;
}

int peek()
{ 
	if(!IsEmpty())
	{
		return sta->tos->data;
	}
	else
		printf("Stack is Empty    (peek)\n");
}
void Display()
{
	list=sta->tos;
	if(sta->tos==NULL)
	{
		printf("Stack is Empty.\n");
	}
	while(list!=NULL)
	{
		printf("%d ",list->data);
		list=list->next;
	}
	printf("\n");
}

void menu()
{int n,i,j;
	while(1)
	{       printf("****************************************************************************\n");
		printf("Enter 1 for the Size of Stack.\n");
		printf("Enter 2 for the Top of Stack.\n");
		printf("Enter 3 to Display the Stack.\n");
		printf("Enter 4 to Push an element into Stack.\n");
		printf("Enter 5 to Pop an element of Stack.\n");
		printf("Enter 9 to Exit from the program.\n");
		scanf("%d",&n);
		printf("****************************************************************************\n");
		switch(n)
		{
			case 1:
				printf("Stack size: %d\n",length());
				break;
			case 2:
				printf("Top Element: %d\n",peek());
				break;
			case 3:
				printf("Elements inside the Stack:");
				Display();
				break;
			case 4:
				printf("Enter the element you want to push into stack:");
				scanf("%d",&j);
				push(j);
				break;
			case 5:
				printf("Popped element: %d\n",pop());
				break;
			case 9:
				exit(0);
				break;
			default:
				printf("You have entered Invalid Input.\n");
		}//switch
	}//while
}//func


void main()
{
	sta = (struct stack*)malloc(sizeof(struct stack));
	sta->tos=NULL;
	menu();
	/*int i,j;
	printf("Enter the size of stack:");
	scanf("%d",&j);
	for(i=0;i<=j;i++)
	{
		push(i);
	}
	printf("Top Element: %d\n",peek());
	printf("Stack size: %d\n",length());
	printf("Enter number of element to pop:");
	scanf("%d",&j);
	for(i=0;i<j;i++)
	{
		printf("Popped element: %d\n",pop());
	}
	Display();
	if(IsEmpty())
	{
		printf("Stack is Empty\n");
	}
	else
	{
		printf("Stack is not Empty\n");
	}*/

}

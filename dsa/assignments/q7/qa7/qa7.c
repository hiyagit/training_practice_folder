/*Stack application: Balancing symbols*/

#include<stdio.h>
#include<string.h>
int IsEmpty();
int IsFull();
void Display();
void push();
int pop();
int peek();
struct stack{
	int size;
	int tos;
	int s[];
}sta;

int IsEmpty()
{
	if(sta.tos==-1)
		return 1;
	return 0;
}

int IsFull()
{
	if(sta.tos==sta.size-1)
		return 1;
	return 0;
}

void Display()
{int i=0;
	if(!IsEmpty())
	{
		for(;i<=sta.tos;i++)
		{
			printf("Element at %d is %d",i,sta.s[i]);
		}
	}
	else
		printf("Stack is Empty\n");
}

void push(int element)
{
	if(!IsFull())
	{
		sta.s[++sta.tos]=element;
		printf("Pushed element: %d\n",sta.s[sta.tos]);
	}
	else
		printf("Stack is Full\n");
}

int pop()
{int x=-1;
	if(!IsEmpty())
	{
		x=sta.s[sta.tos];
		sta.tos--;
	}
	else
		printf("Stack is Empty\n");
	return x;
}

int peek()
{int x=-1;
	if(!IsEmpty())
	{
		x=sta.s[sta.tos];
	}
	else
		printf("Stack is Empty\n");
	return x;
}

void main()
{
	sta.size;
	sta.tos=-1;
	printf("Enter the number of element:");
	scanf("%d",&sta.size);
	sta.s[sta.size];
	int i,len,flag;
	char ch,p,infix[50];
	printf("Enter the elements:");
	scanf("%s",infix);
	len=strlen(infix);
	for(i=0;i<len;i++)
	{ch=infix[i];
		switch(ch)
		{
			case'(':
			case'[':
			case'{':
				push(ch);
				break;
			case')':
			case']':
			case'}':
				if(!IsEmpty())
				{
					p=peek();
					if((ch==')'&&p=='(')||(ch==']'&&p=='[')||(ch=='}'&&p=='{'))
						p=pop();
				}
				else
					flag=1;
				break;
			default:
				;
		}
		if(flag==1)
			break;
	}
	if(i==len&&IsEmpty())
		printf("Expression is Balanced\n");
	else
		printf("Expression is Unbalanced\n");
}

/*Stack application: Postfix evaluation*/

#include<stdio.h>
#include<string.h>

struct stack{
	int size;
	char tos;
	char s[];
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

void push(int element)
{
	if(!IsFull())
	{
		sta.s[++sta.tos]=element;
		printf("Pushed element: %c\n",sta.s[sta.tos]);
	}
	else
		printf("Stack is Full\n");
}

int pop()
{int x;
	if(!IsEmpty())
	{
		x=sta.s[sta.tos];
		sta.tos--;
	}
	else
		printf("Stack is Empty  (pop)\n");
	return x;
}

int peek()
{int x=-1;
	if(!IsEmpty())
	{
		x=sta.s[sta.tos];
	}
	else
		printf("Stack is Empty   (peek)\n");
	return x;
}

int prec(char ch)
{switch(ch)
	{
		case'*':
		case'/':
			return 3;
		case'+':
		case'-':
			return 2;
		case'(':
		case'[':
		case'{':
			return 1;
	}
}

int integer(char ch)
{
	int num=0;
	num=num*10+(ch-48);
	return num;
}

void main()
{
	sta.size;
	sta.tos=-1;
	printf("Enter the number of element:");
	scanf("%d",&sta.size);
	sta.s[sta.size];
	int i,len=0;
	char ch,j=0,p,infix[sta.size],postfix[sta.size];
	printf("Enter the postfix expression:");
	scanf("%s",postfix);
	int a,b,n;
	len=strlen(postfix);
	printf("Length of the string: %d\n",len);
	for(i=0;i<len;i++)
	{ch=postfix[i];
		switch(ch)
		{
			case'+':
				a=pop();
				b=pop();
				push(b+a);
				break;
			case'-':
				a=pop();
				b=pop();
				push(b-a);
				break;
			case'*':
				a=pop();
				b=pop();
				push(b*a);
				break;
			case'/':
				a=pop();
				b=pop();
				push(b/a);
				break;
			default:
				push(integer(ch));
				break;
		}
	}
//	printf("%c\n",pop());
	printf("\nResult: %d",sta.s[1]);
}
			

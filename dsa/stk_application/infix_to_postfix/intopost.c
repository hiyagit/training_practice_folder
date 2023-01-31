/*Stack application: Infix to postfix*/

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

void main()
{
	sta.size;
	sta.tos=-1;
	printf("Enter the number of element:");
	scanf("%d",&sta.size);
	sta.s[sta.size];
	int i,len=0;
	char ch,j=0,p,infix[sta.size],postfix[sta.size];
	printf("Enter the expression:");
	scanf("%s",infix);
	len=strlen(infix);
	printf("Length of the string: %d\n",len);
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
				while(1)
				{
					p=pop();
					if(p=='('||p=='['||p=='{')
						break;
					postfix[j++]=p;
				        printf("Popped element: %c\n",p);
				}
				break;
			case'*':
			case'+':
			case'-':
			case'/':
				while(!IsEmpty()&&prec(peek())>=prec(ch))
				{
				
					p=postfix[j++]=pop();
					printf("Popped element: %c\n",p);
				}
				push(ch);
				break;
			default:
			       postfix[j++]=ch;
			       printf("Postfix: %c\n",ch);
			       
		}

	}
	while(!IsEmpty())
	{
		postfix[j++]=pop();
		postfix[j++]='\0';
	}
	printf("Postfix Expression is: ");
	printf("%s",postfix);
	printf("\n");
}
			

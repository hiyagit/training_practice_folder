/*Stack application: Infix to prefix*/

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
		case')':
		case']':
		case'}':
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
	int i,len=0, k=0;
	char ch,j=0,p,infix[sta.size],prefix[sta.size];
	printf("Enter the expression:");
	scanf("%s",infix);
	len=strlen(infix);
	printf("Length of the string: %d\n",len);
	for(i=len-1;i>=0;i--)
	{ch=infix[i];
		switch(ch)
		{
			case')':
			case']':
			case'}':
				push(ch);
				k++;
				k++;
				break;
			case'(':
			case'[':
			case'{':
				while(1)
				{
					p=pop();
					if(p==')'||p==']'||p=='}')
						break;
					prefix[j++]=p;
      				        printf("Popped element: %c\n",p);
				}
				break;
			case'*':
			case'+':
			case'-':
			case'/':
				while(!IsEmpty()&&prec(peek())>prec(ch))
				{
				
					p=prefix[j++]=pop();
					printf("Popped element: %c\n",p);
				}
				push(ch);
				break;
			default:
			       prefix[j++]=ch;
			       printf("Prefix: %c\n",ch);
			       
		}

	}
	while(!IsEmpty())
	{
		prefix[j++]=pop();
		prefix[j++]='\0';
	}
	printf("Prefix Expression is: ");
	for(i=len-k;i>=0;i--)
	{
		printf("%c",prefix[i]);
	}
	printf("\n");
}
			

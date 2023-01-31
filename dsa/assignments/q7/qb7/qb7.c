#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int isempty();
void display();
int pop();
int peek();
void push(int );
int isfull();
struct value
{
  char s[30];
  int tos;
  int size;
};
struct value stk;
int integer(char ch)
{
  int num=0;
  num=num*10+(ch-48);

  return num;
}

void main()
{
  char ch,infix[30];
  stk.size=10;

  int a,b,l,i;
  printf("enter the array element: \n");
  scanf("%s",infix);
  l=strlen(infix);
  for(i=0;i<l;i++)
    {
       ch=infix[i];
       switch(ch)
       {
         case '+':  a=pop();
                    b=pop();
                    push(b+a);
                    break;
         case '-':  a=pop();
                    b=pop();
                    push(b-a);
                    break;
         case '*':  a=pop();
                    b=pop();
                    push(b*a);
                    break;
         case '/':a=pop();
                  b=pop();
                  push(b/a);
                  break;
         default :
                   push(integer(ch));
                   break;
       }
   }
   printf("result is:%d",stk.s[1]);
}
int isempty()
{
  if(stk.tos==-1)
    {
      return 1;
    }
  else
  {
   return 0;
  }
}

int isfull()
{
  if(stk.tos==stk.size-1)
   {
     return 1;
   }
else
  {
    return 0;
  }
}

void display()
 {
     if(!isempty())
      {
        for(int i=0;i<stk.tos;i++)
         {
             printf("\narray of stack:%s\n",stk.s[i]);
         }
      }
       else
        {
           printf("\n1stack is empty\n");
        }
}

void push(int element)
{
    if(!isfull())
     {
       stk.tos++;
       stk.s[stk.tos]=element;

     }
    else
    {
      printf("\nstack is full");
    }
}

int pop()
{
   int x=-1;
   if(!isempty())
    {
       x=stk.s[stk.tos];
       stk.tos--;
    }
   else
   {
    printf("\nstack is empty\n");
   }
 //  printf("%d",x);
   return x;
 }

int peek()
{
    int x=-1;
    if(!isempty())
    {
      x=stk.s[stk.tos];
     
    }
    else
    {
      printf("3stack is empty");
    }
      return x;
}

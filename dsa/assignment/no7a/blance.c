#include<stdio.h>
#include<string.h>
int isempty();
void display();
int pop();
int peek();
void push();
int isfull();
struct value
{
  char s[30];
  int tos;
  int size;
};
struct value stk;
void main()
{
  char ch,p,infix[30];
  stk.size=10;
  stk.tos=-1;
  int i,l,flag;
  printf("enter the array element: \n");
  scanf("%s",infix);
  l=strlen(infix);
  for(i=0;i<l;i++)
    {
       ch=infix[i];
       switch(ch)
       {
         case '(':
         case '{':
         case '[':  push(ch);
                    break;
         case ')':
         case '}':
         case ']':
                  if(!isempty())
                   {
                    p=peek();
                  if((ch==')'&& p=='(')||(ch=='}'&& p=='{')||(ch=='['&& p==']'))
                    p=pop();
		   }
		  else
                   {
                     flag=1;
                     break;
                   }
          }
    if(flag==1)
    break;
   }
   if(i=l && isempty())
    printf("\nblanced");
   else
    printf("\nnot balanced");
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
             printf("\narray of stack:%d",stk.s[i]);
          }
      }
       else
        {
           printf("\nstack is empty");
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
      printf("stack is full");
    }
}

int pop()
{
   int x=-1;
   if(!isempty())
    {
       x=stk.s[stk.tos--];
    }
   else
   {
    printf("stack is empty");
   }
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
      printf("stack is empty");
    }
      return x;
}

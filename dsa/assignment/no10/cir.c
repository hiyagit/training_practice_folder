#include<stdio.h>
#include<stdlib.h>
void inque();
int deque();
int underflow();
int overflow();
void display();
struct queue
{
   int q[50];
   int size;
   int f,r;
};
struct queue que;


int underflow()
{
   if(que.f==-1&&que.r==-1)
    {
       return 1;
    }
  return 0;
}

int overflow()
{
  if((que.r+1)%que.size==que.f)
   {
        return 1;
    }
 return 0;
}

void display()
{  
  int i;
  if(!underflow())
   {
     for (i=que.f;i!=que.r;i=(i+1)%que.size)
      {
        printf("\nqueue elements:%d",que.q[i]);
      }
    printf("\nqueue elements:%d",que.q[i]);
   }
   else
    printf("this is empty");
}

void inque()
{
   
   if(!overflow())
   {    
        int element;
   printf("\nenter the element:");
   scanf("%d",&element);
     if(que.f==-1&&que.r==-1)
            que.f++;
    que.r=(que.r+1)%que.size;
    que.q[que.r]=element;
   }
  else
   {
    printf("queue is full");
   }
}

int deque()
{
   int x=-1;
   if(!underflow())
   {
      x=que.q[que.f];
      if(que.f==que.r)
       {
         que.f=que.r=-1;
       }
      else
       {
        que.f=(que.f+1)%que.size;
       }
    }
    else

     printf("queue is empty");
     return x;
 }
int main()
{
   int n;
   que.f=-1;
   que.r=-1;
   printf("\nenter the size of queue:");
   scanf("%d",&que.size);
   while(1)
   {
     printf("\nenter your choice");
     printf("\n1.nqueue\n2.dqueue\n3.display\n4.exit\n");
     scanf("%d",&n);
     switch(n)
        {
           case 1:inque();
                  break;
           case 2 :deque();
                //  display();
                  break;
          case 3:display();
                  break;
          case 4: exit(1);
          default :printf("worng choice");
                   break;
       }//switch end
  }//while end
  return 0;
}


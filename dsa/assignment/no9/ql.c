#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node*next;
   
};
struct node *temp;
struct node*front=NULL;
struct node*rear=NULL;
void nqueue(int ele)
{
   temp=(struct node*)malloc(sizeof(struct node*));
    temp->data=ele;
    temp->next=NULL;
    if(front==NULL&&rear==NULL)
     {
        front=rear=temp;
     }
    else
     {
      rear->next=temp;
       rear=temp;
     }
 }
  
int dequeue()
{
   if(front==NULL)
    {
       printf("\nqueue underflow");
       return -1;
     }
   else
     {
        temp=(struct node*)malloc(sizeof(struct node*));
        int data=front->data;
        front=front->next;
        return data;
     }
}

void display()
{
    if(front==NULL&&rear==NULL)
       printf("\nstack is empty");
    else
    {
      printf("\n\tqueue is:\n");
      temp=front;
      while(temp)
      {
         printf("\t%d\n",temp->data);
         temp=temp->next;
      }
        
    }
}


int main()
{
   int n,c,element;
   while(1)
   {
      printf("\n1.nqueue\n2.dequeue\n3.display\n4.exit\n");
      printf("\nenter your choice:");
      scanf("%d",&n);
      switch(n)
        {
            case 1: printf("\n\tenter the element:");
                    scanf("%d",&element);
                    nqueue(element);
                    break;
            case 2: c=dequeue();
                    printf("\n\tdequeued element:%d",c);
                    break;
	   case 3:display();
                   break;
           case 4:exit(1);
                  break;
           default :printf("\n\tenter worng choice");
       }//switch
   }//while
 }//main                 
 


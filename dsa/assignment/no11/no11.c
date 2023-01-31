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
  void ins_front(int ele)
   {
      temp=(struct node*)malloc(sizeof(struct node*));
      temp->data=ele;
      temp->next=NULL;
   //   if(front!=NULL);
         temp->next=front;
         front=temp;
    }
void dequeue()
{
   if(front==NULL)
    {
       printf("\nqueue underflow");

     }
   else
     {  
        int data=front->data;
        front=front->next;
        printf("deleted element:%d",data);
     }
}
void end()
{
  if(rear->next==NULL)
   {
       int data=rear->data;
        rear=rear->next;
        printf("deleted element:%d",data);
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


void main()
{
   int n,c,element;
   while(1)
   {
      printf("\n1.insert last\n2.delete front\n3.insert front\n4.delete end\n5.display\n6.exit\n");
      printf("\nenter your choice:");
      scanf("%d",&n);
      switch(n)
        {
            case 1: printf("\n\tenter the element:");
                    scanf("%d",&element);
                    nqueue(element);
                    break;
            case 2: dequeue();
                    //printf("\n\tdeteled front element:%d",c);
                    break;
	   case 3: printf("\n\tenter the element:");
                    scanf("%d",&element);
                    ins_front(element);
                   break;
           case 4: end();
                  //  printf("\n\tdeleted end element:%d",c);
                    break;
           case 5:display();
                  break;
           case 6:exit(1);
                  break;
           default :printf("\n\tenter worng choice");
       }//switch
   }//while
 }//main                 
 


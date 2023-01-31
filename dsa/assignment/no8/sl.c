#include<stdio.h>
#include<stdlib.h>
struct node
{
   int data;
   struct node*next;
   
};
struct node *temp;
struct node*top=NULL;

int pop()
{
    int data_pop;
    if(top==NULL)
      {
        printf("empty");
      }
     else
      {  
          temp=top;
          data_pop=top->data;
          top=top->next;
          free(temp);
       }
   return data_pop;
      
}

void push(int ele)
{
   temp=(struct node*)malloc(sizeof(struct node*));
    temp->data=ele;
    if(top==NULL)
     {
        temp->next=NULL;
     }
    else
      temp->next=top;
     top=temp;
 }
  
void display()
{
    if(top==NULL)
       printf("\nstack is empty");
    else
    {
      printf("\n\tstack is:\n");
      temp=top;
      while(temp->next!=NULL)
      {
         printf("\t%d\n",temp->data);
         temp=temp->next;
      }
       printf("\t%d\n",temp->data);  
    }
}
int main()
{
   int n,c,element;
   while(1)
   {
      printf("\n1.push\n2.pop\n3.display\n4.exit\n");
      printf("\nenter your choice:");
      scanf("%d",&n);
      switch(n)
        {
            case 1: printf("\n\tenter the element:");
                    scanf("%d",&element);
                    push(element);
                    break;
            case 2: c=pop();
                    printf("\n\tpoped element:%d",c);
                    break;
	   case 3:display();
                   break;
           case 4:exit(1);
                  break;
           default :printf("\n\tenter worng choice");
       }//switch
   }//while
 }//main                 
 

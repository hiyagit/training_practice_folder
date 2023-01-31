/*Doubly linked-list implementation*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node*next;
   struct node*prev;
   
};
struct node *dll;
struct node *temp;
struct node *curr;

void insert_begin(int ele)
{
   temp=(struct node *)malloc(sizeof(struct node *));
   temp->data=ele;
   temp->prev=NULL;
   temp->next=dll;
   if(dll!=NULL)
      dll->prev=temp;
   dll=temp;
}

void forward()
{
  curr=dll;
   while(curr!=NULL)
   {
     printf("%d ",curr->data);
     curr=curr->next;
   }
}

void insert_end(int ele)
{
   temp=(struct node*)malloc(sizeof(struct node*));
   temp->data=ele;
   temp->next=NULL;
    if(dll==NULL)
     {
        temp->prev=dll;
        dll=temp;
      }
    else
     {
	     curr=dll;while(curr->next!=NULL)
		     curr=curr->next;
	     temp->prev=curr;
	     curr->next=temp;
     }
}

void insert_after(int a,int ele)
{
       	if(dll==NULL)
     	{
       		printf("List is Empty\n");
     	}
  	else
  	{
	  	curr=dll;
	  	while(curr!=NULL&&curr->data!=a)
		  	curr=curr->next;
		if(curr==NULL)
			printf("Element not found\n");
		else
		{
                
			temp=(struct node*)malloc(sizeof(struct node*));
			temp->data=ele;
			temp->next=curr->next;
			temp->prev=curr;
			if(curr->next!=NULL)
				curr->next->prev=temp;
			curr->next=temp;
		}
	}
}

void insert_before(int a,int ele)
 {
       if(dll!=NULL)
          { 
             curr=dll;
             while(curr!=NULL&&curr->next->data!=a)
                 {
                    curr=curr->next;
                 }
             if(curr==NULL)
             printf("node is not present\n");
             else
              {
                temp=(struct node*)malloc(sizeof(struct node*));
                temp->data=ele;
                temp->prev=curr->prev;
                temp->next=curr;
                if(curr->prev==NULL)
                    dll=temp;
                curr->prev=temp;
              }
          }
     else
       printf("List is not present\n");

}

int del_begin()
{
    int x=-1;
     if(dll!=NULL)
       {
	 temp=dll;
         x=temp->data;
         dll=temp->next;
         if(temp->next!=NULL)
         temp->next->prev=NULL;
          free(temp);
       }
     else
       
         printf("List is empty\n");
       
   return x;
 }

int del_last()
{

   int x=-1;
    if(dll!=NULL)
      {  
        curr=dll;
         while(curr->next!=NULL)
            curr=curr->next;
        x=curr->data;
        if(curr->prev!=NULL)
           curr->prev->next=NULL;
        else
        dll=NULL;
       }
   else
    printf("List is empty\n");
   return x;
 }

void del_specific(int a)
{
   if(dll!=NULL)
    {
           curr=dll;
           while(curr!=NULL&&curr->data!=a)
                curr=curr->next;
           if(curr!=NULL)
           {
             if(curr->prev!=NULL)
               curr->prev->next=curr->next;
             else
                dll=curr->next;
             if(curr->next!=NULL)
               curr->next->prev=curr->next;
	     free(curr);
            }
           else
             printf("Element not found\n");
    }
   else
     printf("List is empty\n");
}

void travel_back()
{
     curr=dll;
    if(curr!=NULL)
   {  
      while(curr->next!=NULL)
       curr=curr->next;
      while(curr!=NULL)
      {
        printf("%d ",curr->data);
        curr=curr->prev;
      }
   }
}

int main()
{
  int i,n,element,c,a;
  
  while(1)
  {
     printf("*******************************************\n");
     printf("Enter your choice:");
     printf("\n1.Insert at begining\n2.Insert at the end\n3.Display from front\n4.Insert after\n5.Insert before");
     printf("\n6.Delete beginning\n7.Delete last\n8.Delete specific\n9.Display from back\n10.Exit\n");
     scanf("%d",&n);
     printf("*******************************************\n");
     switch(n)
      {
        case 1: printf("\nEnter the element:");
                scanf("%d",&element);
                insert_begin(element);
                break;
        case 2: printf("\nEnter the element:");
                scanf("%d",&element);
                insert_end(element);
                break;
	case 3: printf("Elements in the list from front: ");
		forward();
		printf("\n");
                break;
        case 4:printf("\nEnter the search element and new element:");
               scanf("%d%d",&a,&element);
               insert_after(a,element);
                break;
        case 5:printf("\nEnter the search element and new element:\n");
               scanf("%d%d",&a,&element);
               insert_before(a,element);
                break;
        case 6:del_begin();
               break;
        case 7: del_last();
                break;
        case 8:printf("\nEnter the element you want to delete:\n");
               scanf("%d",&c);
               del_specific(c);
               break;
	case 9:printf("Elements in the list from back: ");
	       travel_back();
	       printf("\n");
               break;
        case 10: exit(1);
                break;
        default:printf("Invalid choice...\n");
                 break;
      }
   }
}


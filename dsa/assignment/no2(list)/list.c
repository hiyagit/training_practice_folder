#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node*next;
   
};
struct node*list;
struct node *temp;
struct node*curr;

void insert_begin(int ele)
{
   temp=(struct node *)malloc(sizeof(struct node *));
   temp->data=ele;
   temp->next=list;
   list=temp;
}

void forward()
{
  curr=list;
   while(curr!=NULL)
   {
     printf("%d\t",curr->data);
     curr=curr->next;
   }
}

void insert_end(int ele)
{
   temp=(struct node*)malloc(sizeof(struct node*));
   temp->data=ele;
   temp->next=NULL;
    if(list==NULL)
      list=temp;
    else
      {
        curr=list;
        while(curr->next!=NULL)
            curr=curr->next;
        curr->next=temp;
         
      }
}

void insert_after(int a,int ele)
{
       curr=list;
       while(curr!=NULL&&curr->data!=a)
         { curr=curr->next; }
       if(curr!=NULL)
        {
           temp=(struct node*)malloc(sizeof(struct node*));
           temp->data=ele;
           temp->next=curr->next;
           curr->next=temp;
        }
       else
        
           printf("Element not present\n");
        
}
  

void insert_before(int a,int ele)
 {
       if(list!=NULL)
        {
          if(list->data==a)
           {
             temp=(struct node*)malloc(sizeof(struct node*));
             temp->data=ele;
             temp->next=list;
             list=temp;
           }
         
          else
           {
             curr=list;
             while(curr!=NULL&&curr->next->data!=a)
                 {
                    curr=curr->next;
                 }
             if(curr==NULL)
             printf("Node is not present\n");
             else
              {
                temp=(struct node*)malloc(sizeof(struct node*));
                temp->data=ele;
                temp->next=curr->next;
                curr->next=temp;
              }
           }
      }
     else
       printf("List is not present\n");

}

int del_begin()
{
    int x=-1;
     if(list!=NULL)
       {
	 temp=list;
         x=temp->data;
         list=temp->next;
          free(temp);
       }
     else
       
         printf("List is empty\n");
       
   return x;
 }

int del_last()
 {
	struct node *temp;
	struct node*curr;

   int x=-1;
    if(list!=NULL)
      {  
        if(list->next==NULL)
        {
         temp=list;
         x=temp->data;
         list=NULL;
          free(temp);
        }
       else
       {
        curr=list;
         while(curr->next->next!=NULL)
          {
            curr=curr->next;
          }
        temp=curr->next;
        x=temp->data;
        curr->next=NULL;
        free(temp);
      }
    }//end if
   else
    printf("List is empty\n");
    return x;
 }

void del_specific(int a)
{
   if(list!=NULL)
    {
       if(list->data==NULL)
        {
           temp=list;
           list=temp->next;
           free(temp);
        }
       else
        {
           curr=list;
           while(curr->next!=NULL&&curr->next->data!=a)
                curr=curr->next;
           if(curr->next!=NULL)
           {
           temp=curr->next;
           curr->next=temp->next;
           free(temp);
           }
           else
             printf("Element not found\n");
        }
    }
   else
     printf("List is empty\n");
}

void travel_back()
{
    if(list!=NULL)
      {
          display(list);
      }
    else
       printf("List is empty\n");
}

int display(struct node*curr)
{
  if(curr==NULL)
   return (display(curr->next));
  printf("%d",curr->data);
}

void rev()
{
    struct node *rev=NULL;
    while(list!=NULL)
     {
        curr=list;
        list=curr->next;
        curr->next=rev;
        rev=curr;
     }
   list=rev;
}
int main()
{
  int i,n,element,c,a;
  
  while(1)
  {
     printf("\nEnter your choice");
     printf("\n1.Insert at begining\n2.Insert at the end\n3.Move forward\n4.Inser after\n5.Insert before");
     printf("\n6.Delete begining\n7.Delete last\n8.Delete specific\n9.Reverse\n10.Travel back\n11.Exit");
     scanf("%d",&n);
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
        case 3: forward();
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
        case 8:printf("Enter the element you want to delete:\n");
               scanf("%d",&c);
               del_specific(c);
               break;
        case 9:rev();
                break;
        case 10:travel_back();
                break;
        case 11: exit(1);
                break;
        default:printf("Invalid choice...\n");
                 break;
      }
   }
}

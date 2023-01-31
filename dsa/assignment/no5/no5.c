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
struct node*list1;


struct node*insert(int ele)
{
  
   temp=(struct node *)malloc(sizeof(struct node *));
   temp->data=ele;
   temp->next=list;
   list=temp;
   return list;
}

void forward(struct node*list1)
{
  curr=list;
   while(curr!=NULL)
   {
     printf("%d\t",curr->data);
     curr=curr->next;
   }
}

int find(int ele)
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
           while(curr->next!=NULL&&curr->next->data!=ele)
                curr=curr->next;
           if(curr->next!=NULL)
           {
           
           temp=curr->next;
           curr->next=temp->next;
           free(temp);
           }
           else
             printf("element not found\n");
        }
    }
   else
     printf("list is empty");
   
}



void main()
{
  int ele,x,n;

     while(1)
      { 

          printf("\nenter the choice:");
          printf("\n1.insert\n2.find\n3.exit:");
          scanf("%d",&n);
           switch(n)
           {
  	         case 1: printf("\t\nenter the list:");
			scanf("%d",&ele);
			list1=insert(ele);
			printf("\n\tlist is:");
			forward(list1);
 	     		break;
	   	case 2: printf("which element you want to search:");
	 	        scanf("%d",&x);
	 		find(x);
			insert(x);
 	        	forward(list1);
			break;
                case 3: exit(1);
		        break;
           }
      }
   
}

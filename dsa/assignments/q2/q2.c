/*Single Linked-list implementation*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};   //structure
struct node *list;
struct node *curr;

void Insert_begin(int element)
{
       	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
  	temp->data = element;
  	temp->next = list;
  	list = temp;
}//insert in the beginning

void Insert_end(int element)
{ 

	struct node *temp;
      	temp = (struct node*)malloc(sizeof(struct node));
  	temp->data = element;
  	temp->next = NULL;
  
	if(list == NULL)
    	{
       		list =temp;
    	}	  
  	else
    	{
      		curr=list;
      		while(curr->next!=NULL)
	      		curr = curr->next;
      		curr->next = temp;
    	}	  
}//insert in the end

void Insert_before(int select, int element)
{
	if(list->data == select) //if select is in 1st postion
    	{	
      		struct node *temp;
      		temp = (struct node*)malloc(sizeof(struct node));
      		temp->data = element;
      		temp->next = list;
      		list = temp;
    	}
  	else  //not in 1st position then go on
    	{
      		curr = list;
      		while(curr->next!=NULL && curr->next->data!=select)
	      		curr = curr->next;
      		if(curr->next == NULL) // not in the list
	      		printf("\n Select not found!!!");
      		else //select found
      		{
        		 struct node *temp;
			 temp = (struct node*)malloc(sizeof(struct node));
			 temp->data = element;
			 temp->next = curr->next;
			 curr->next = temp;
		}
	}		
}//insert before an element

void Insert_after(int select, int element)
{
  	curr=list;
  	while(curr!=NULL && curr->data!=select)
		  curr = curr->next;
       	if(curr!=NULL) 
    	{
      		struct node *temp;
      		temp = (struct node*)malloc(sizeof(struct node));
      		temp->data = element;
      		temp->next = curr->next;
      		curr->next = temp;
    	}	  
  	else
    		printf("\n Select not found!!!");	  
}// insert after an element	

int Delete_beg()
{
  	int x=-1;
  	struct node *temp;
  	temp = (struct node*)malloc(sizeof(struct node));
  	if(list!=NULL)//if there r elements in list
    	{
      		temp=list;
      		x=temp->data;
      		list=temp->next;
      		free(temp);
    	}	  
        else
     		printf("\n List is empty....(Del beg)");
  	return x;  
}//del the 1st element

int Delete_last()
{
	int x=-1;
  	struct node *temp;
  	temp = (struct node*)malloc(sizeof(struct node));
  	if(list!=NULL)//if there r elements in list
   	{
    		if(list->next == NULL)//if there is only 1 element in list
      		{
         		temp=list;
	 		x=temp->data;
	 		list=NULL;
	 		free(temp);
      		}	    
    		else //if the elements are >1 in the list
      		{
        		curr=list;
			while(curr->next->next!=NULL)//till last element
				curr = curr->next;
			temp=curr->next;
			x=temp->data;
			curr->next=NULL;
			free(temp);
      		}
   	} 	  
  	else
   		printf("\n List is empty.....(del end)");
 	return x; 
}//del the last element

int Delete_specific(int element)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
  	if(list!=NULL)//if there r elements in list
   	{
     		if(list->next == NULL)//if there is only 1 element in list
       		{
         		temp=list;
      	 		list=temp->next;
	 		free(temp);
       		}
     		else//if element are >1
       		{
         		curr=list;
	 		while(curr->next!=NULL && curr->next->data!=element)//till we found element
		 		curr=curr->next;
         		if(curr->next == NULL)//last element
		 		printf("\n Element not found!!!");
	 		else//element found
           		{
	     			temp = curr->next;
	     			curr->next = temp->next;
	     			free(temp);
	   		}		 
       		}	     
   	} 
  	else
     		printf("\n List is Empty......(del sp)");	  
}//del specific element

void Travel_forward()
{
  	struct node *curr;
  	curr=list;
  	while(curr!=NULL)
     	{
       		printf(" %d",curr->data);
       		curr=curr->next;
     	}	  
}//forward 	

void Travel_backward()
{
  	if(list!=NULL)
		Print(list);
  	else
      		printf("\n List is empty.....(travel back)");	  
}//backward	

void Print(struct node *curr)
{
	if(curr == NULL)
		return ;
	Print(curr->next);
  	printf(" %d",curr->data);
}//print	

void search(int sele)
{
	curr=list;
	while(curr!=NULL && curr->data!=sele)
		curr=curr->next;
	if(curr->data==sele)
		printf("Found the element.\n");
	else
		printf("Element doesn't exist in the list.\n");
}//search

void Reverse()
{
	struct node *rev;
  	rev=NULL;
  	while(list!=NULL)//till end
     	{
       		curr=list;
       		list=curr->next;
       		curr->next=rev;
       		rev=curr;
     	}	  
  	list=rev;
}//reverse

/*int choices()
{
  int ch;
  printf("\n 1.Insertion \n 2.Deletion \n 3.Traverse \n 4.Reverse \n 5.Quit");
  printf("\n Enter your choice: ");
  scanf("%d",&ch);
  return ch;
}//choices*/


int main()
{
	int ch;
  	int ch1;
  	int ch2;
  	int ch3;
  	int element;
  	int select;
  	while (1)
   	{	  
	        printf("\n **************************\n");
	        printf("\n **************************\n");
     		printf("\n 1.Insertion \n 2.Deletion \n 3.Travel \n 4.Search \n 5.Reverse \n 6.Quit");
     		printf("\n Enter your choice: ");
     		scanf("%d",&ch);
	        printf("\n **************************\n");
	        printf("\n **************************\n");
     
     		printf("\n %d",ch);
     		switch(ch) 
        	{
           		case 1://insertion
	  	//       int ch1;  
	         		printf("\n **************************\n");
	         		printf("\n 1.Insert in the beginning \n 2.Insert in the end \n 3.Insert before an element \n 4.Insert after an element");
	         		printf("\n Enter your choice: ");
	         		scanf("%d",&ch1);
                 		printf("\n ***************************\n");
	              		switch(ch1)
	                	{
	                   		case 1://beginning
		                 		printf("\n Enter the element you want to insert in beginning: ");
	                         		scanf("%d",&element);
	                         		Insert_begin(element);
				 		Travel_forward();
	                         		break;
	                   		case 2://end
             		         		printf("\n Enter the element you want to insert at the end: ");
		                 		scanf("%d",&element);
		       		 		Insert_end(element);
				 		Travel_forward();
		       		 		break;
	                   		case 3://before
		       		 		printf("\n Enter the element you want to insert: ");
		       		 		scanf("%d",&element);
		       		 		printf("\n Enter the element before which you want to insert a new element: ");
		       		 		scanf("%d",&select);
		      		 		Insert_before(select,element);
				 		Travel_forward();
		     	  	 		break;
	                   		case 4://after
		       		 		printf("\n Enter the element you want to insert: ");
		       		 		scanf("%d",&element);
		       		 		printf("\n Enter the element after which you want to insert a new element: ");
		       		 		scanf(" %d",&select);
		       		 		Insert_after(select,element);
				 		Travel_forward();
                       		 		break;
	                   		default:
	                         		printf("\n INVALID CHOICE!!!");
	                         		break;	      
	                	}//switch insert
	   
	         		break;
           		case 2://deletion
            		//     int ch2;
                		printf("\n ***************************\n");
                 		printf("\n 1.Delete the 1st element \n 2.Delete the last element \n 3.Delete a specific element");
                 		printf("\n Enter your choice: ");
                 		scanf("%d",&ch2);
                 		printf("\n ***************************\n");
                 		switch(ch2)
                    		{
	                		case 1://1st element
		              			Delete_beg();	 
				 		Travel_forward();
		       	      			break;	 
		 			case 2://last element
		              			Delete_last();
				 		Travel_forward();
		              			break;
		 			case 3://specific element
		              			printf("\n Enter the element you want to delete: ");
		              			scanf("%d",&element);
		              			Delete_specific(element);
				 		Travel_forward();
	                      			break;
	         			default:
	                      			printf("\n INVALID CHOICE!!!");
	                      			break;	       
	            		}//switch delete
                 		break;	    
           		case 3://travel
				//  int ch3;
                 		printf("\n ***************************\n");
                 		printf("\n 1.Forward Travel \n 2.Backward Travel");
                 		printf("\n Enter your choice: ");
                 		scanf("%d",&ch3);
                 		printf("\n ***************************\n");
                 		switch(ch3)
                    		{
		       			case 1:
			     			Travel_forward();  
			     			break;  
		       			case 2:
			     			Travel_backward();
			     			break;
		       			default:
		              			printf("\n INVALID CHOICE!!!");
	                      			break;		      
		    		}//switch travel

                 		break;
			case 4://search
				printf("\nEnter the element you want to search:");
				scanf("%d",&select);
				Travel_forward();
				search(select);
				break;
           		case 5://reverse
                 		Reverse();
                 		break;
           		case 6:
                 		exit(0);
                 		break;
          		default:
                 		printf("\n INVALID CHOICE !!!");
                 		break;	    
        	}//ch	
   	}//while  
  	return 0;
}//main	

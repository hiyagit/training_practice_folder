#include<stdio.h>
#include<stdlib.h>

int max();
struct node
{
        int data;
	struct node*l;
	struct node*r;	
};
struct node*bst;
struct node*temp;
struct node*curr;
void insert(int ele)
{
	temp=(struct node*)malloc(sizeof(struct node*));
	temp->data=ele;
	temp->l=temp->r=NULL;
	if(bst==NULL)
	 bst=temp;
	else
	{
		curr=bst;

		while(1)
		{
			if(ele<curr->data)
			{
                           if(curr->l!=NULL)
			     curr=curr->l;
			   else
			   {
			     curr->l=temp;
			     break;
			   }
		        }
			else if(ele>curr->data)
			{
			  if(curr->r!=NULL)
                             curr=curr->r;
                          else
                           {
                            curr->r=temp;
                             break;
                           }
			}
		}
	}
}

/*void ()
{
	if(bst!=NULL)
            display(bst);
	else
	   printf("tree is empty");
}*/

void inorder(struct node *curr)
{
	if(curr!=NULL)
	 {
		inorder(curr->l);
		printf("\t%d ",curr->data);
		inorder(curr->r);
	 }
}
void preorder(struct node*curr)
{

	if(curr!=NULL)
	{
	  printf(" %d ",curr->data);
	  preorder(curr->l);
	  preorder(curr->r);
	}
	//else
	//printf("empty");
}

void postorder(struct node *curr)
{
  	if(curr!=NULL)
	{
	  postorder(curr->l);
	  postorder(curr->r);
	  printf(" %d ",curr->data);
	}
	//else
	 //printf("empty");
}

int leaf(struct node *curr)
{
	 if(curr==NULL)
	      return 0;
	if(curr->l==NULL&&curr->r==NULL)
	    return 1;
	return(leaf(curr->l)+leaf(curr->r));
}

int nonlf(struct node*curr)
{
	 if(curr==NULL)
	      return 0;
	if(curr->l==NULL&&curr->r==NULL)
	    return 1;
	return(nonlf(curr->l)+nonlf(curr->r)+1);
}
int height(struct node*curr)
{
	 if(curr==NULL)
	      return -1;
	if(curr->l==NULL&&curr->r==NULL)
	    return 0;
	return(max(height(curr->l),height(curr->r))+1);
}
int max(int n1,int n2)
{
  if(n1>n2)
    return n1;
  else
     return n2;
}
int findmax(struct node*curr)
{
   int x=-1;
   if(curr!=NULL)
    {
      while(curr->r!=NULL)
       curr=curr->r;
      x=curr->data;
     }
return x;
}

int min(struct node*curr)
{
   int x=-1;
   if(curr!=NULL)
    {
      while(curr->l!=NULL)
       curr=curr->l;
      x=curr->data;
     }
return x;
}

struct node *delete(struct node *curr,int ele)
{
   if(curr!=NULL)
     {
       if(ele<curr->data)
          curr->l=delete(curr->l,ele);
       else if(ele>curr->data)
           curr->r=delete(curr->r,ele);
       else
       {
         if(curr->l!=NULL&&curr->r!=NULL)
           {
             curr->data=findmax(curr->l);
	     curr->l=delete(curr->l,curr->data);
	   }
         else
          {
            temp=curr;
            if(curr->r==NULL)
              curr=curr->l;
            else
              curr=curr->r;
            free(temp);
          }
       }
      return curr;
      }//end if
}

int n,ele;

void main()
{
    
	while(1)
   {
    printf("\n1.insert element\n2.preorder\n3.inorder\n4.postorder\n5.leaf node\n6.non leaf\n7.max\n8.min\n9.height\n10.delete\n11.exit");
    printf("\nenter your choice:");
    scanf("%d",&n);
    switch(n)
      {
	case 1: printf("\nenter the element:");
 		scanf("%d",&ele);
		insert(ele);
		break;
	case 2:printf("\npreorder:");
		preorder(bst);
		break;		
  	case 3:printf("\ninorder:");
		inorder(bst);
		break;
	case 4:printf("\npostorder:");
		postorder(bst);
		break;
	case 5:printf("\nleafnode:%d",leaf(bst));
		
		break;
	case 6:printf("\nnon leaf:%d",nonlf(bst));
	
		break;
	case 7:printf("\nmaximum:%d",findmax(bst));
		
		break;
	case 8:printf("\nminimum:%d",min(bst));
		
		break;
	case 9:printf("\nheight:%d",height(bst));
		
		break;
	case 10:printf("\nenter the element want to be deleted:");
		scanf("%d",&ele);
		delete(bst,ele);
		break;
	case 11: exit(1);
		break;
	default:printf("\nenter worng choice");
      		break;
	}
    }
}













	

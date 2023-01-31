#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *lchild;
	struct node *rchild;
};
struct node *bst;

void Insert(int ele)
{
	struct node *temp, *curr;
	temp=malloc(sizeof(struct node));
	temp->data=ele;
	temp->lchild=temp->rchild=NULL;
	if(bst==NULL)
		bst=temp;
	else
	{
		curr=bst;
		while(1)
		{
			if(ele<curr->data)
			{
				if(curr->lchild!=NULL)
					curr=curr->lchild;
				else
				{
					curr->lchild=temp;
					break;
				}
			}
			else//ele>curr->data
			{
				if(curr->rchild!=NULL)
					curr=curr->rchild;
				else
				{
					curr->rchild=temp;
					break;
				}
			}
		}
	}
}

/*void Inorder()
{
	if(bst!=NULL)
		print(bst);
	else
		printf("Tree is Empty.\n")
}*/
void Inorder(struct node *curr)
{
	if(curr!=NULL)
	{
		print(curr->lchild);
		printf("%d",curr->data);
		print(curr->rchild);
	}
	else
		printf("Tree is Empty.\n");
}

void Preorder(struct node *curr)
{
	if(curr!=NULL)
	{
		printf("%d",curr->data);
		Preorder(curr->lchild);
		Preorder(curr->rchild);
	}
	else	
		printf("Tree is Empty.\n");
}

void Postorder(struct node *curr)
{
	if(curr!=NULL)
	{
		Postorder(curr->lchild);
		Postorder(curr->rchild);
		printf("%d",curr->data);
	}
	else
		printf("Tree is Empty.\n");	
}

int ln(struct node *curr)
{
	if(curr==NULL)
	{
		return 0;
	}
	if(curr->lchild==NULL&&curr->rchild==NULL)
	{
		return 1;
	}
	return (ln(curr->lchild)+ln(curr->rchild));
}

int nln(struct node *curr)
{
	if(curr==NULL)
		return 0;
	if(curr->lchild==NULL&&curr->rchild==NULL)
		return 0;
	return(nln(curr->lchild)+nln(curr->rchild)+1);
}

int height(struct node *curr)
{
	if(curr==NULL)
		return -1;
	if(curr->lchild==NULL&&curr->rchild==NULL)
		return 0;
	return (max(height(curr->lchild),height(curr->rchild))+1);
}

int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int findmax(struct node *curr)
{
	int x=-1;
	if(curr!=NULL)
	{
		while(curr->rchild!=NULL)
			curr=curr->rchild;
		x=curr->data;
	}
	return x;
}

int findmin(struct node *curr)
{
	int x=-1;
	if(curr!=NULL)
	{
		while(curr->lchild!=NULL)
			curr=curr->lchild;
		x=curr->data;
	}
	return x;
}

struct node * Delete_ele(struct node *curr,int ele)
{
	if(currr!=NULL)
		curr->lchild=Delete_ele(curr->lchild,ele);
	else
	{
		if(ele>curr->data)
			curr->rchild=Delete_ele(curr->rchild,ele);
		else
		{
			if(curr->lchild!=NULL&&curr->rchild!=NULL)
			{
				curr->data=findmax(curr->lchild);
				curr->lchild=Delete_ele(curr->lchild,curr->data)
			}
			else
			{
				temp=curr;
				if(curr->rchild==NULL)
					curr=curr->lchild;
				else
					curr=curr->rchild;
				free(temp);
			}
		}
	}
	return curr;
}

void main()
{int 



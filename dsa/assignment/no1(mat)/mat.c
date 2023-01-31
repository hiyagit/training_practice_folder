#include<stdio.h>
#include<stdlib.h>
void main()
{

 int a[20][20];
 int row,column,sum=0;
 printf("enter the  row and column:");
 scanf("%d%d",&row,&column);
 printf("enter the element:\n");
 for(int i=0;i<row;i++)
  {
    for(int j=0;j<column;j++)
    {
       scanf("%d",&a[i][j]);
    }
  }
printf("matrix:\n");
for(int i=0;i<row;i++)
  {
    for(int j=0;j<column;j++)
    {
       printf("%d\t",a[i][j]);
    }
       printf("\n");
  }
for(int i=0;i<row;i++)
  {
    for(int j=0;j<column;j++)
    {
       if(i>j)
       {
         sum=sum+a[i][j];
       }
    }

  }
printf("lower triangler matrix sum :%d",sum);

}

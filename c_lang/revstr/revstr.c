#include<stdio.h>
void size(char*);
void rev(char*);
int main()
{
	char s[50];
	printf("enter the string:");
	scanf("%s",s);
	size(s);
	rev(s);
	printf("\n");	
	//revstr(s,0)
	return 0;
}
void rev(char *s)
{
	if(*s!='\0')
	{
		rev(s+1);
		printf("%c",*s);
	}

}

void size(char s[])
{int i=0;
	while(s[i]!='\0')
	{
		i++;
	//	printf("%d",count);
	}
	printf("%d",i+1);
}


/*int revstr(char *s,int n)
{
	char tmp;
	tmp=s[n];
	s[n]=s[];

*/








































/*size=strlen(a);
	printf("\nSize: %d",size);
	rev_string(a,0,size-1);
	printf("\nReversed string: ");
	puts(a);
}
int rev_string(char a[40],int n,int size)
{char tmp;
	tmp=a[n];
	a[n]=a[size-n];
	a[size-n]=tmp;
	if(n==size/2)
	{
		return a;
	}
	return rev_string(a,++n,size);
}
*/

#include<stdio.h>
int main()
{int a=3;
	int *p;
	int **ptr;
	p= &a;
	ptr= &p;

	printf("Address of a: %p\n",&a);
	printf("Value of p=Address of a: %d\n",*p);
	printf("addres of p: %p\n",&p);
	printf("Value of *p:value of a: %d\n",*p);
	printf("Value of ptr:Address of p: %p\n",ptr);
	printf("Value of *ptr:Value of p: %p\n",*ptr);
	printf("Value of **ptr:Value of a: %d\n",**ptr);
	printf("Address of ptr: %p\n",&ptr);
}

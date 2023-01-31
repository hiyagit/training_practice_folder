#include<stdio.h>

void funct(int x,int y)
{ printf("%d%d\n",x,y);
}
void main()
{int var=15;
       // funct(var);
	//funct(var++);
	//funct(++var);
	funct(var++,++var);
	//funct(var,var++);
	//funct(var,++var);
}


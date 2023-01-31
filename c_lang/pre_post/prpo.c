#include <stdio.h>

void main()
{
    int a,b;
    printf("a: ");
    scanf("%d",&a);
    b = a++ + ++a;
    printf("a: %d   b: %d\n",a,b);
}
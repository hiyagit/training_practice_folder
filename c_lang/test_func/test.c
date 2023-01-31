#include <stdio.h>

int i = 10;
void f()
{
    int i = 5;
    i = 7;
}
void g()
{
    i = 9;
}
int main()
{
    i = 1;
    g();
    f();
    printf("%d\n",i);
    return 0;
}

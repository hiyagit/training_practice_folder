#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    printf("Before exec\n");
    execl("../barrier/bar","","-al",NULL);
    printf("After exec\n");

    return 0;
}
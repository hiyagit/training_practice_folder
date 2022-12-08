
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf("Before fork\n");
    fork();
    printf("After fork\nPID: %d     PPID: %d\n",getpid(),getppid());

    return 0;
}
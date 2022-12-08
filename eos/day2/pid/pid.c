
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid = getpid();
    pid_t ppid = getppid();

    printf("Process ID: %d\n",getpid());
    printf("Parent Process ID: %d\n",getppid());

    return 0;

}

#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t id;
    pid_t id1;
    printf("Hyd\n\n");
    id = fork();
    printf("Bng     PID: %d     PPID: %d    ID: %d\n\n",getpid(),getppid(),id);
    id1 = fork();
    printf("Pune    PID: %d     PPID: %d    ID1: %d\n\n",getpid(),getppid(),id1);

    return 0;
}

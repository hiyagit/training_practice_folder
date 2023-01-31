
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t id;
    printf("Before fork\n");
    id = fork();
    printf("After fork\nPID: %d     PPID: %d    ID: %d\n",getpid(),getppid(),id);
    
    if(0==id)
    {
        execl("/home/training/hiya/eos/day9/barrier/bar","","-al",NULL);
        printf("Child Process\n"); //Data processing
    }
    else
    {
        printf("Parent Process\n"); //Data Processing
        // wait();
    }

    return 0;
}

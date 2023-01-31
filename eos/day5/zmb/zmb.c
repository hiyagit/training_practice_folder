
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,const char *argv[])
{
    int fd = 0;
    pid_t id;
    pid_t ret_wait;

    id = fork();
    if(id == 0)
    {
        //child process
        printf("Child process\n");
        printf("PID: %d  PPID: %d    Ret: %d\n",getpid(),getppid(),id);
        printf("Child state\n");
    }
    else
    {
        //parent process
        printf("Parent process\n");
        printf("PID: %d     PPID: %d    Ret: %d\n",getpid(),getppid(),id);
        // ret_wait = wait(NULL);
        // if(ret_wait == -1)
        // {
        //     perror("wait");
        //     exit(EXIT_FAILURE);
        // }
        sleep(10);
        printf("Parent state finished\n");
    }
// ps -el |grep bin

    return 0;
}
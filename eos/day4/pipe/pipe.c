
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t id;
    int fd[2];
    unsigned char buff[128];
    size_t nbytes_read;
    size_t nbytes_write;
    pipe(fd);
    id = fork();
    if (0==id)
    {   //Child process
        close(fd[1]);//closing write system call
        nbytes_read = read(fd[0],buff,128);//will return no. of successful bytes read
        printf("Parent sent: %s\n",buff);
        printf("Read number of bytes: %ld\n",nbytes_read);
        close(fd[0]);//closing read system call
    }
    else
    {   //Parent process
        close(fd[0]);//closing read system call
        nbytes_write = write(fd[1],"Inter Process Communication(IPC)-PIPES\n",39);//will return no. of successful bytes written
        printf("Written number of bytes: %ld\n",nbytes_write);
        close(fd[1]);//closing write system call
    }

    return 0;
}
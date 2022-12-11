
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
        close(fd[1]);
        nbytes_read = read(fd[0],buff,128);
        printf("Parent sent: %s\n",buff);
        printf("Read number of bytes: %ld\n",nbytes_read);
        close(fd[0]);
    }
    else
    {   //Parent process
        nbytes_write = write(fd[1],"Inter Process Communication(IPC)-PIPES\n",39);
        printf("Written number of bytes: %ld\n",nbytes_write);
        close(fd[1]);
    }

    return 0;
}
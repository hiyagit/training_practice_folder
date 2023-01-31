
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    pid_t id;
    int fd1[2];
    int fd2[2];
    ssize_t nbytes_read;
    ssize_t nbytes_write;
    char read_msg1[128],read_msg2[128];
    char write_msg1[] = {"Pipe1 message"};
    char write_msg2[] = {"Pipe2 message"};

    pipe(fd1);
    pipe(fd2);
    id = fork();
    
    if (0==id)
    {   
        close(fd1[1]);
        close(fd2[0]);
        nbytes_read = read(fd1[0],read_msg1,sizeof(read_msg1));
        printf("Parent sent: %s\n",read_msg1);
        printf("Read number of bytes: %ld\n",nbytes_read);
        nbytes_write = write(fd2[1],write_msg1,sizeof(write_msg1));
        close(fd1[0]);
        close(fd2[1]);
    }
    else
    {   
        close(fd1[0]);
        close(fd2[1]);
        nbytes_write = write(fd1[1],write_msg2,sizeof(write_msg2));
        printf("Written number of bytes: %ld\n",nbytes_write);
        nbytes_read = read(fd2[0],read_msg2,sizeof(read_msg2));
         printf("Child sent: %s\n",read_msg2);
        close(fd1[1]);
        close(fd2[0]);
    }

    return 0;
}
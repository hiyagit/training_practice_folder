
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <error.h>
#include <errno.h>
#include <stdlib.h>


int main(int argc,const char *argv[])
{
    int fd = 0;
    ssize_t nbytes_write;
    int ret_close;

    fd = open("desdfifo",O_WRONLY);
    if(-1 == fd)
    {
        
        perror("Source File Error");
        exit(EXIT_FAILURE);
    }
    nbytes_write = write(fd,"FIFO are also called Named Pipes.\n",34);
    if(-1 == nbytes_write)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    printf("Written number of bytes: %ld\n",nbytes_write);
    ret_close = close(fd);
    if(-1 == ret_close)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    return 0;
}


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
    ssize_t nbytes_read;
    int ret_close;
    unsigned char buff[128];

    fd = open("desdfifo",O_RDONLY);
    if(-1 == fd)
    {
        
        perror("Source File Error");
        exit(EXIT_FAILURE);
    }
    nbytes_read = read(fd,buff,128);
    if(-1 == fd)
    {
        perror("Destination File Error");
        exit(EXIT_FAILURE);
    }
    printf("Received: %s",buff);
    printf("Read number of bytes: %ld\n",nbytes_read);
    if(-1 == nbytes_read)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    ret_close = close(fd);
    if(-1 == ret_close)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    return 0;
}

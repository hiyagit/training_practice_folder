
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <error.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc,const char *argv[])
{
    int fd_file1;
    int fd_file2;
    unsigned char buff[128];
    ssize_t nbytes_read;
    ssize_t nbytes_write;
    int ret_close1;
    int ret_close2;

    fd_file1 = open(argv[1],O_RDONLY);
    if(-1 == fd_file1)
    {
        
        perror("Source File Error");
        exit(EXIT_FAILURE);
    }

    nbytes_read = read(fd_file1,buff,128);

    fd_file2 = open(argv[2],O_WRONLY);
    if(-1 == fd_file2)
    {
        perror("Destination File Error");
        exit(EXIT_FAILURE);
    }

    nbytes_write = write(fd_file2,buff,strlen(buff));
    if(-1 == nbytes_write)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    ret_close1 = close(fd_file1);
    if(-1 == ret_close1)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    ret_close2 = close(fd_file2);
    if(-1 == ret_close2)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }


    return 0;
}
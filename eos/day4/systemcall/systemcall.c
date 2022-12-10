
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <error.h>
#include <errno.h>
#include <stdlib.h>


int main()
{
    int fd;
    fd = open("os.txt",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
    write(fd,"system call implementation",26);
    if(-1==fd)
    {
        perror("Error\n");
        exit(EXIT_FAILURE);
    }
    close(fd);
    
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <unistd.h>
#include <sys/types.h>

int *count_s;
int main()
{
    int fd = 0; //shared memory descriptor
    int err = 0;
    int err_cl = 0;
    /*
    This is the API for creating or opening shared memory objects.
    int shm_open(const char *name, int oflag, mode_t mode);
    */
    fd = shm_open("/desdshm", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if(fd == -1)
    {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }
    
    err = ftruncate(fd, sizeof(int));
    if(err == -1)
    {
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    count_s = (int *)mmap(NULL,sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    while(1)
    {
        (*count_s)++;
        printf("Sending count: %d\n",(*count_s));
        sleep(1);
    }

    err_cl = close(fd);
    if(err_cl == -1)
    {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return 0;
}
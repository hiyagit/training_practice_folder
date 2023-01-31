
#include<stdio.h>
#include <pthread.h>
#include <unistd.h>
int count = 0;

void *inc(void *data)
{
    while(1)
    {
        count++;
        printf("inc:%d\n",count);
    }
}

void *dec(void *data)
{
    while(1)
    {
        count--;
        printf("dec: %d\n",count);
    }
}

int main(int argc,const char *argv[])
{
    pthread_t thread1,thread2;
    printf("inside main\n");
    sleep(2);
    pthread_create(&thread1,NULL,inc,NULL);
    pthread_create(&thread2,NULL,dec,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);

    return 0;
}
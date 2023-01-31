#include <stdio.h>
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
    pthread_attr_t thread_attr;
    pthread_attr_init(&thread_attr);
    pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
    pthread_create(&thread1,&thread_attr,inc,NULL);
    // pthread_create(&decId,&thread2,NULL,dec,NULL)
    sleep(1);
    pthread_attr_destroy(&thread_attr);
    pthread_exit(NULL);

    return 0;
}
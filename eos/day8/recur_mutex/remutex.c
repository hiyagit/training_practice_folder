#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
int count = 0;
pthread_mutex_t lock;
pthread_mutexattr_t mutexat;

void *inc(void *data)
{

    while(1)
    {
        pthread_mutex_lock(&lock);
        pthread_mutex_lock(&lock);
        count++;
        printf("inc:%d\n",count);
        pthread_mutex_unlock(&lock);
        pthread_mutex_unlock(&lock);
    }
}
void *dec(void *data)
{
      while(1)
    {
        pthread_mutex_lock(&lock);
        count--;
        printf("dec: %d\n",count);
        pthread_mutex_unlock(&lock);
    }
}

int main(int argc,const char *argv[])
{
    pthread_t thread1,thread2;
    // pthread_attr_t thread_attr;
    // pthread_attr_init(&thread_attr);
    // pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
    pthread_mutexattr_init(&mutexat);
    pthread_mutexattr_settype(&mutexat,PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&lock,&mutexat);
    pthread_create(&thread1,NULL,inc,NULL);
    pthread_create(&thread2,NULL,dec,NULL);
    sleep(1);
    // pthread_join(thread1,NULL);
    // pthread_join(thread2,NULL);
    pthread_mutex_destroy(&lock);
    // pthread_attr_destroy(&thread_attr);
    // pthread_exit(NULL);

    return 0;
}
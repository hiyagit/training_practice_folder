#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
int count = 0;
sem_t sem_lock;
void *inc(void *data)
{

    while(1)
    {
        sem_wait(&sem_lock);
        count++;
        printf("inc:%d\n",count);
        sem_post(&sem_lock);
    }
}
void *dec(void *data)
{
      while(1)
    {
        sem_wait(&sem_lock);
        count--;
        printf("dec: %d\n",count);
        sem_post(&sem_lock);
    }
}

int main(int argc,const char *argv[])
{
    pthread_t thread1,thread2;
    sem_init(&sem_lock,0,1);
    pthread_create(&thread1,NULL,inc,NULL);
    pthread_create(&thread2,NULL,dec,NULL);
    sleep(1);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    sem_destroy(&sem_lock);
    // pthread_exit(NULL);

    return 0;
}
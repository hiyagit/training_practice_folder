#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_barrier_t barrier3;

void *th1(void *data)
{
    printf("Thread1: Init_start\n");
    sleep(2);
    printf("Thread1: Init_end\n");
    pthread_barrier_wait(&barrier3);
    printf("Thread1: functionality_start\n");

}

void *th2(void *data)
{
    printf("Thread2: Init_start\n");
    sleep(5);
    printf("Thread2: Init_end\n");
    pthread_barrier_wait(&barrier3);
    printf("Thread2: functionality_start\n");

}

void *th3(void *data)
{
    printf("Thread3: Init_start\n");
    sleep(7);
    printf("Thread3: Init_end\n");
    pthread_barrier_wait(&barrier3);
    printf("Thread3: functionality_start\n");

}

int main()
{
    pthread_t thread1,thread2,thread3;
    pthread_barrier_init(&barrier3,NULL,3);
    pthread_create(&thread1,NULL,th1,NULL);
    pthread_create(&thread2,NULL,th2,NULL);
    pthread_create(&thread3,NULL,th3,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_join(thread3,NULL);
    pthread_barrier_destroy(&barrier3);

    return 0;
}
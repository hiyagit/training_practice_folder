/*Q. Write a pthread to create 3 threads to print Hello World*/

#include<stdio.h>
#include<pthread.h>

void *th1(void *data)
{
    printf("Hello World! This is from thread1.\n");
}
void *th2(void *data)
{
    printf("Hello World! This is from thread2.\n");
}
void *th3(void *data)
{
    printf("Hello World! This is from thread3.\n");
}

int main()
{
    pthread_t thread1,thread2,thread3;
    pthread_create(&thread1,NULL,th1,NULL);
    pthread_create(&thread2,NULL,th2,NULL);
    pthread_create(&thread3,NULL,th3,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_join(thread3,NULL);

    return 0;
}
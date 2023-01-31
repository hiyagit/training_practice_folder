#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int a,b;
pthread_rwlock_t rw_lock;

void *write(void *data)
{
    pthread_rwlock_wrlock(&rw_lock);
    printf("Enter the values of a and b\n");
    scanf("%d%d",&a,&b);
    pthread_rwlock_unlock(&rw_lock);
}
void *read(void *data)
{
    pthread_rwlock_rdlock(&rw_lock);
    printf("Values of a and b are %d and %d\n",a,b);
    pthread_rwlock_unlock(&rw_lock);
}
void *read1(void *data)
{
    pthread_rwlock_rdlock(&rw_lock);
    printf("Hello! This is thread3. Values of a and b are %d and %d\n",a,b);
    pthread_rwlock_unlock(&rw_lock);
}

int main()
{
    pthread_t thread1, thread2, thread3;
    pthread_rwlock_init(&rw_lock,NULL);
    pthread_create(&thread1,NULL,write,NULL);
    pthread_create(&thread2,NULL,read,NULL);
    pthread_create(&thread3,NULL,read1,NULL);
    sleep(1);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    pthread_join(thread3,NULL);
    pthread_rwlock_destroy(&rw_lock);

    return 0;
}
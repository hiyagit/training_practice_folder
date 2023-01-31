
#include<stdio.h>
#include <pthread.h>

void *add(void *data)
{
    printf("Inside thread\n");
    int a=10;
    int b=20;
    int c=a+b;
    printf("Value of c: %d\n",c);
}

int main(int argc,const char *argv[])
{
    printf("In main\n");
    pthread_t thread_1;
    printf("Before thread\n");
    pthread_create(&thread_1,NULL,add,NULL);
    pthread_join(thread_1,NULL);
    //for compilation need to give "gcc -o pthread pthread.c -lpthread"

    return 0;
}

#include<stdio.h>
#include <pthread.h>
#include <unistd.h>

void *add(void *data)
{
    printf("Inside Add thread\n");
    int a=20;
    int b=10;
    int c=a+b;
    printf("(Addition)Value of c: %d\n",c);
}

void *sub(void *data)
{
    printf("Inside Subtract thread\n");
    int a=20;
    int b=10;
    int c=a-b;
    printf("(Subtraction)Value of c: %d\n",c);
}

void *mul(void *data)
{
    printf("Inside Multiply thread\n");
    int a=20;
    int b=10;
    int c=a*b;
    printf("(Multiplication)Value of c: %d\n",c);
}

void *div(void *data)
{
    printf("Inside Division thread\n");
    int a=20;
    int b=10;
    int c=a/b;
    printf("(Division)Value of c: %d\n",c);
}

void *mod(void *data)
{
    printf("Inside Modulus thread\n");
    int a=20;
    int b=10;
    int c=a*b;
    printf("(Modulus)Value of c: %d\n",c);
}

int main(int argc,const char *argv[])
{
     pthread_t thread1,thread2,thread3,thread4;
    printf("Inside main\n");
    // sleep(2);
    pthread_create(&thread1,NULL,add,NULL);
    pthread_create(&thread2,NULL,sub,NULL);
    pthread_create(&thread3,NULL,div,NULL);
    pthread_create(&thread4,NULL,mod,NULL);
    // pthread_join(thread1,NULL);
    // pthread_join(thread2,NULL);
    // pthread_join(thread3,NULL);
    // pthread_join(thread4,NULL);

    return 0;
}
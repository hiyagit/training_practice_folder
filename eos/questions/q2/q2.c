/*Q. Write a pthread program to find the sum of n integers.*/

#include<stdio.h>
#include<pthread.h>
#include <stdlib.h>

 void *sumn(void *data)
 {
    int n,i=0,sum=0;
    printf("Enter value of n integer: ");
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        sum += i;
    }
    printf("Sum of %d integers is %d\n",n,sum);

 }

 int main()
 {
    pthread_t thread1;
    int err=0,err1=0;
    err = pthread_create(&thread1,NULL,sumn,NULL);
    if(0 != err)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }
    err1 = pthread_join(thread1,NULL);
    if(0 != err1)
    {
        perror("Error");
        exit(EXIT_FAILURE);
    }

    return 0;
 }
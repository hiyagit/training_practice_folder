
#include<stdio.h>
#include"arith.h"
#include"arithmat.h"
#include"arithmetic.h"

int main()
{
    int sum=0,diff=0,prod=0,quo=0,rem=0,square=0;
    sum = add(16,8);
    printf("Addition: %d\n",sum);
    diff = sub(25,16);
    printf("Subtraction: %d\n",diff);
    prod = mul(13,4);
    printf("Product: %d\n",prod);
    quo = div(87,3);
    printf("Quotient: %d\n",quo);
    rem = mod(45,4);
    printf("Remainder: %d\n",rem);
    square = sqr(6);
    printf("Square: %d\n",square);
    return 0;
}
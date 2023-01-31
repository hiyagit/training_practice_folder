
#include<stdio.h>

int main()
{   
    int sale = 0;
    int hover_m = (10*2000000)+1000000;
    int sold = 0;
    printf("Enter sales made that month:");
    scanf("%d",&sale);
    sold = sale * 3000000;
    if(sold>hover_m)
    {
        printf("Profit\n");
    }
    else if(sold<hover_m)
    {
        printf("Loss\n");
    }
    else
    {
        printf("Broke Even\n");
    }

    return 0;
}
#include<stdio.h>

void main()
{
    float n;
    float tot = 0;
    float tot1 = 0;
    float discount = 0;
    float tax = 0;
    printf("Enter the number of kaleidoscope you want: ");
    scanf("%f",&n);

    if(n>1)
    {
        discount = ((4.5)*(n));
        tax = discount * 0.07;
        tot = discount + tax;
        printf("Total cost: %.2f\n",tot);
    }
    else
    {
        tot1 = 5 + 0.35;
        printf("Total cost: %.2f\n",tot1);
    }

}
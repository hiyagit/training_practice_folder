#include<stdio.h>
#include "stringf.h"
int main()
{
    char string1[] = "String Library";
    char string2[] = "String Functions";

    printf("String1: %s\n",string1);
    printf("String1 length: %d\n",strlength(string1));
    // if(strcharacter(string1,'z')==Null)
    // {
    //     printf("Character not found\n");
    // }
    // else
    // {
    printf("Character present: %s\n",strcharacter(string1,'i') );
    // }
    printf("String2: %s\n",string2);
    printf("String2 length: %d\n",strlength(string2));
    printf("Compare result: %d\n",strcompare(string1,string2));
    // printf("Reverse string: %s\n",rev(string1));

    return 0;
}
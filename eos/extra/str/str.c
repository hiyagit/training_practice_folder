/*
syntax: char str_name[str_len] = "string";
        char str_name[str_len] = {'r','e','d','\0'};
*/

#include<stdio.h>

int main()
{
    char str1[6]= "hello";
    char str2[5]= {'w','o','r','l','d'};
    printf("Result string: %s",str2);

    return 0;
}


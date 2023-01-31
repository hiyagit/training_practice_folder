
#include<stdio.h>

void main()
{
    char str[500];
    char ch;
    int count=0;
    printf("Enter the string: ");
    scanf("%[^\n]%*c", str);
    // printf("%s", str);
    for(int i=0;str[i]!='\0';i++)
    {
        ch=str[i];
        if(ch=='a'||ch=='A'||ch=='e'||ch=='E'||ch=='i'||ch=='I'||ch=='o'||ch=='O'||ch=='u'||ch=='U')
        {
            count++;
        }
    }
    printf("Total number of vowels in the string: %d\n",count);

}
/*
int strcmp(const char *s1, const char *s2);
            => Compare the strings s1 with s2.

*/
int strcompare(char *str1,char *str2)
{
    while(*str1 == *str2)
    {
        if(*str1 == '\0')
        {
            return 0;
        }
        str1++;
        str2++;
    }
    return (*str1-*str2);
}
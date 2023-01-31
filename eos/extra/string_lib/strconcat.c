/*
char *strcat(char *dest, const char *src);
            => Append the string src to the string dest, returning a pointer dest.
*/
char *strconcat(char *str1,char *str2)
{
    char *p = str1;
    while(*p != '\0')
    {
        p++;
    }
    while(*p++ = *str2++)
    {
        ;
    }
    return str1;
}
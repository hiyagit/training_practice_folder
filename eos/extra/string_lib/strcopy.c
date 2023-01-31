/*
char *stpcpy(char *dest, const char *src);
    => Copy a string from src to dest, returning a pointer to the end of the resulting string at dest.
*/
char *strcopy(char *str1,char *str2)
{
    while((*str1 = *str2)!= '\0')
    {
        str1++;
        str2++;
    }
    return str1;
}
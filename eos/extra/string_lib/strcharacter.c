/*
char *strchr(const char *s, int c);
            => Return a pointer to the first occurrence of the character c in the string s.
*/
char *strcharacter(char *str, int c)
{
    char *p = str;
    int i=0;
    while(*str != c)
    {   
        str++;
        i++;
    }
    if(*str == c)
    {
        return p+i;
    }
    else
    {
        return 0;
    } 
}
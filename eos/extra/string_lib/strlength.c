/*
size_t strlen(const char *s);
        => Return the length of the string s.
*/
int strlength(char *str)
{
    char *p = str;
    while(*p != '\0')
    {
        p++;
    }
    return p-str;
}
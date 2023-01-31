/*****************************************************************************************
Author Name - Hiya Pandey
Department - PG-DESD Student
/*****************************************************************************************
/*****************************************************************************************

Function Name - strcompare
Return Value - Returns a value 0 if the two strings matches, otherwise returns a non-zero
               value.
Description - This function is used for comparison of two strings. 

******************************************************************************************/

int strcompare(char *str1,char *str2);

/*****************************************************************************************

Function Name - strconcat
Return Value - Return a pointer to the resulting string.
Description - This function is used to append a copy of a string at the other end of 
              other string. 

******************************************************************************************/
char *strconcat(char *str1,char *str2);

/*****************************************************************************************

Function Name - strcopy
Return Value - Return a pointer to the destination string.
Description - This function is used for copying one string to another string. 

******************************************************************************************/
char *strcopy(char *str1,char *str2);

/*****************************************************************************************

Function Name - strlength
Return Value - Returns the length of the string.
Description - This function takes one argument which is pointer to the first character of
              the string.

******************************************************************************************/
int strlength(char *str);

/*****************************************************************************************

Function Name - strcharacter
Return Value - Returns a pointer to the first occurance of the character in the string or 
               NULL if character is not present in the sting. 
Description - This function returns a pointer to the first occurrence of the character in 
              the string. 

******************************************************************************************/
char *strcharacter(char *str, int c);
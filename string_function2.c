#include "main.h"


/**
 * str_remove - Remove a specified substring
 * from a string and allocate memory for the result
 * @str: The original string
 * @s: The substring to be removed
 * Return: new command
 */


char *str_remove(const char *str, const char *s)
{
int i = 0;
int j = 0;
int match = 0;
int c;
char *line;

while (str[c] != '\0')
{
if (str[c] != *s)
{
i++;
}
else
{
match++;
}
c++;
s++;
}


match++;
line = (char *)malloc(i + 2);

while (j < i)
{
line[j] = str[match + j];
j++;
}
(line)[j] = '\0';
return (line);
}

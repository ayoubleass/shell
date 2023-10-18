#include "main.h"

/**
 * printString - Prints a string of a specified length.
 *
 * @str: The string to print.
 * @length: The length of the string to print.
 */
void printString(char *str, ssize_t length)
{
	int i = 0;
	while (i < length)
	{
		_putchar(str[i]);
		i++;
	}
}

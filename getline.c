#include "main.h"

#define BUFFER_SIZE 1024
static char *buf;

/**
 * _getline - Read a line from a FILE stream and store it in a buffer.
 * @buffer: A pointer to a pointer that
 * will store the line read from the stream.
 * @n: A pointer to a ssize_t variable
 * that will store the length of the read line.
 * @stream: A pointer to a FILE stream (e.g., a file)
 * from which to read the line.
 * Return: The length of the line read, or -1 in case of an error.
 */


ssize_t _getline(char **buffer, ssize_t *n, FILE *stream)
{
	ssize_t size = 0;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (-1);
	size = read(fileno(stream), buf, BUFFER_SIZE);
	if (size < 0)
	{
		free(buf);
		return (-1);
	}

	if (*buffer != NULL)
		*buffer = (char *)malloc(size + 1);
	else
		*buffer = (char *)realloc(*buffer, (*n + size + 1));

	if (*buffer == NULL)
	{
		free(buf);
		return (-1);
	}
	*n = size;
	_strcpy(*buffer, buf);
	(*buffer)[*n] = '\0';
	free(buf);
	return (*n);
}

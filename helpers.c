#include "main.h"

/**
 * setexecveArgs - Tokenizes a string into an array of arguments for execve
 * @lineptr: The input string to tokenize
 * Return: A dynamically allocated array of strings (arguments), or NULL on
 * failure
 */
char **setexecveArgs(char *lineptr)
{
	char *token;
	int i = 0;
	int j;
	char **argv;
	char *linecpy = malloc(_strlen(lineptr + 1));

	if (lineptr == NULL || linecpy == NULL)
		return (NULL);

	_strcpy(linecpy, lineptr);
	argv = malloc(sizeof(char *));

	if (argv == NULL)
		return (NULL);

	token = strtok(linecpy, " \t\n");

	while (token != NULL)
	{
	argv[i] = malloc(strlen(token) + 1);
	if (argv[i] == NULL)
	{
		for (j = 0; j < i; j++)
		{
			free(argv[j]);
		}
		free(argv);
		return (NULL);
	}

	_strcpy(argv[i], token);
	token = strtok(NULL, " \t\n");
	i++;
	}

	argv[i] = NULL;
	free(linecpy);
	return (argv);
}
/**
 * _putchar - Writes a single character to standard output.
 *
 * @c: The character to write.
 *
 * Return: On success, 1 is returned. On error,
 * -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	ssize_t n;

	n = write(1, &c, 1);
	return (n);
}

/**
 * print_env - Prints each environment variable separately
 *
 * @env: The array of environment variables
 */
void print_env(char **env)
{
	int i = 0;
	int j;

	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] != '\0')
		{
			_putchar(env[i][j]);
			j++;
		}
		_putchar('\n');
		i++;
	}
}

/**
 * extractToken - Extracts a token from a string.
 *
 * @lineptr: The string from which to extract a token.
 *
 * Return: The extracted token.
 */
char *extractToken(char *lineptr)
{
	int i = 0, j = 0;
	char *result = malloc(i + 1);

	while (lineptr[i] != '\0' && lineptr[i] != ' ' && lineptr[i] != '\n')
	{
		i++;
	}

	if (i > 0)
	{
		if (result == NULL)
			return (NULL);

		for (j = 0; j < i; j++)
		{
		result[j] = lineptr[j];
		}
		result[i] = '\0';

		return (result);
	}
	return (lineptr);
}

/**
 * removenewtag - Removes the newline character from the end of a string.
 *
 * @lineptr: The string to process.
 * @linelen: The length of the string.
 */
void removenewtag(char *lineptr, ssize_t linelen)
{
	if (linelen > 0 && lineptr[linelen - 1] == '\n')
	{
		lineptr[linelen - 1] = '\0';
		linelen--;
	}
}

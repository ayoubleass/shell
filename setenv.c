#include "main.h"
/**
 * _setenv - Sets or updates an environment variable
 * @name: The name of the environment variable to set or update
 * @value: The new value for the environment variable
 * @overwrite: Flag to indicate whether to overwrite the variable if it exists
 * Return: 0 on success, or -1 on failure (e.g., if memory allocation fails)
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	int i = 0;
	int j = 0;
	int c = 0;
	char *newValue = malloc(_strlen(name) + _strlen("=") + _strlen(value) + 1);
	/*extern char **environ;*/
	if (newValue == NULL)
	{
		free(newValue);
		return (-1);
	}
	while (environ[i] != NULL)
	{
		if (_strcmp(environ[i], name) == 1)
		{
			while (j < _strlen(name))
			{
				newValue[j] = environ[i][j];
				j++;
			}
			newValue[j] = '=';
			j++;
			while (c < _strlen(value))
			{
				newValue[j + c] = value[c];
				c++;
			}
			newValue[c] = '\0';

			if (overwrite)
			{
				environ[i] = newValue;
				return (0);
			}
		}
		i++;
	}
	free(newValue);
	return (0);
}

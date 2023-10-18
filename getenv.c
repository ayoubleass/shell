#include "main.h"

/**
 * _search - Searches for a character in a specific environment variable.
 *
 * @env: The array of environment variables to search.
 * @name: The name of the environment variable to search.
 * @c: The character to search for within the environment variable.
 *
 * Return: If the character is found in the environment variable, a new string
 *         containing the characters after the first occurrence of 'c' is
 * returned. If the character is not found or any memory allocation fails, NULL
 * is returned.
 */

char *_search(char **env, char *name, char c)
{
	int i = 0;
	char *result = malloc(sizeof(char));

	while (env[i] != NULL)
	{
		if (str_containe(env[i], name) == 0)
		{
			while (*env[i] != '\0')
			{
				if (*env[i] == c)
				{
					env[i]++;
					result = malloc(_strlen(env[i]) + 1);
					result = _strcpy(result, env[i]);
				}
				env[i]++;
			}
		}
		i++;
	}
	if (result)
	{
		return (result);
	}
	return (NULL);
}

/**
 * _getenv - Retrieves the value of an environment variable by name
 * @name: The name of the environment variable to retrieve
 * Return: A pointer to the value of the specified environment variable,
 *         or NULL if the variable is not found
 */

char *_getenv(char *name)
{
	extern char **environ;
	char *result;

	result = _search(environ, name, '=');
	return (result);
}


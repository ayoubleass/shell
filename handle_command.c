#include "main.h"

/**
 * handleCommand - Locate and construct the full path to a command executable.
 *
 * @path_copy: A copy of the PATH environment variable.
 * @lineptr: The input line containing the command.
 * @cmd: A pointer to store the full path of the command.
 *
 * Return: If the command is found in any of the directories specified in the
 * PATH, this function returns the directory where it was found (a token from
 * PATH). If the command is not found, it returns NULL.
 * If any memory allocation fails, NULL is returned.
 */

char *handleCommand(char *path_copy, char *lineptr, char **cmd)
{
	struct stat st;
	char *token = strtok(path_copy, ":");

	while (token != NULL)
	{
		*cmd = malloc(strlen(token) + strlen("/") + strlen(lineptr) + 1);
		if (cmd == NULL)
			return (NULL);

		_strcpy(*cmd, token);
		*cmd = _strcat(*cmd, "/");
		*cmd = _strcat(*cmd, extractToken(lineptr));
		if (stat(*cmd, &st) == 0)
		{
			return (token);
		}
		token = strtok(NULL, ":");
	}
	return (NULL);
}


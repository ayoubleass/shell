#include "main.h"

/**
 * pipedCommand - run the piped command.
 * @filename: executable name.
 */
void pipedCommand(char *filename)
{
	char *lineptr;
	ssize_t n = 0;
	ssize_t line_length;
	char *arg[3];
	int i = 0;
	char **argv;
	pid_t pid;

	line_length = _getline(&lineptr, &n, stdin);
	if (line_length)
	{
		removenewtag(lineptr, line_length);
		argv = setexecveArgs(lineptr);

		arg[0] = argv[0];
		arg[1] = NULL;

		while (argv[i] != NULL)
		{
			pid = fork();
			if (pid  == 0)
			{
				if (execve(argv[i], arg, NULL) == -1)
				{
					char *error =  malloc(1024);

					_strcpy(error, filename);
					error =  _strcat(error, ": ");
					error = _strcat(error, argv[i]);
					printf("%s: not found\n", error);
					free(error);
					exit(98);
				}
			}
			else
				wait(NULL);
			i++;
		}
	}
	exit(0);
}

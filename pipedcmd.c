#include "main.h"

/**
 * pipedCommand - run the piped command.
 */
void pipedCommand(void)
{
	char *lineptr;
	ssize_t n = 0;
	ssize_t line_length;
	char *arg[3];
	int i = 0;
	char **argv;

	line_length = _getline(&lineptr, &n, stdin);
	if (line_length)
	{
		removenewtag(lineptr, line_length);
		argv = setexecveArgs(lineptr);

		arg[0] = argv[0];
		arg[1] = NULL;

		while (argv[i] != NULL)
		{
			execve(argv[i], arg, NULL);
			i++;
		}
	}
	exit(0);
}

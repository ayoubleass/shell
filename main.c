#include "main.h"


/**
 * execute - Executes a command in a child process
 * @cmd: The command to execute
 * @arguments: An array of arguments for the command
 * @environ: The environment variables
 * @filename: executable name
 */
void execute(char *cmd, char **arguments, char **environ, char *filename)
{
	int status;
	struct stat st;
	char *fullcmd;
	char *path = _getenv("PATH"), *pathcpy = malloc(_strlen(path) + 1);

	_strcpy(pathcpy, path);*/
	if (str_containe(cmd, "/bin") == 0)
	{
		fullcmd = malloc(_strlen(cmd) + 1);
		_strcpy(fullcmd, cmd);
		_strcpy(fullcmd, extractToken(cmd));
	}

	else 
		handleCommand(pathcpy, extractToken(cmd), &fullcmd);

	if (stat(fullcmd, &st) == 0)
	{
		pid_t pid = fork();

		if (pid == 1)
			perror("fork");
		else if (pid == 0)
			execve(fullcmd, arguments, environ);
		else
		{
			wait(&status);
			free(cmd);
			free(fullcmd);
			free(pathcpy);
		}
	}
	else
	{
		perror(filename);
		free(cmd);
		free(pathcpy);
	}
}

/**
 * main - Interpret Unix commands
 * @argc: Number of parameters passed to the main function
 * @argvv:  Array of strings containing command-line arguments
 * @env: environnement variables
 * Return: Returns an exit status/error code to the operating system
 */



int main(int argc, char **argvv, char **env)
{
	while (1)
	{
		char *lineptr;
		ssize_t n = 0;
		ssize_t line_length;
		char **argv;

		if (isatty(STDIN_FILENO))
		{
			printString("$ ", 2);
			line_length = _getline(&lineptr, &n, stdin);
			removenewtag(lineptr, line_length);
			argv = setexecveArgs(lineptr);
			if (line_length < 1)
			{
				_putchar('\n');
				exit(0);
			}
			if (_strcmp(lineptr, "exit") == 0)
			{
				free(lineptr);
				printString("exit", 4);
				_putchar('\n');
				return (argv[1] ? atoi(argv[1]) : 0);
			}
			if (line_length)
			{
				execute(lineptr, argv, env, argvv[argc - 1]);
				continue;
			}
		}
		else
			pipedCommand(argvv[0]);
	}
	return (0);
}


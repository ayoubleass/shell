#include "main.h"

/**
 * main - Interpret Unix commands
 * @argc: Number of parameters passed to the main function
 * @argvv:  Array of strings containing command-line arguments
 * Return: Returns an exit status/error code to the operating system
 */



int main(int argc, char **argvv, char **env)
{
	char *path = _getenv("PATH");
	char *path_copy = malloc(strlen(path) + 1);

	while (1)
	{
		char *cmd = malloc(sizeof(char));
		char *lineptr;
		ssize_t n = 0;
		ssize_t line_length;
		pid_t pid;
		char **argv;
		int status;
		char *token;
		int ch;

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
				exit(98);
			}

			if (_strcmp(lineptr, "env") == 0)
			{
				print_env(env);
				continue;
			}

			if (str_containe(lineptr, "/bin") == 0)
				cmd = _strcpy(cmd, extractToken(lineptr));

			if (strcmp(argv[0], "cd") == 0)
			{
				char *buffer = malloc(1024);

				if (!argv[1])
				{
					ch = chdir(_getenv("HOME"));
					if (ch == 0)
						_setenv("PWD", _getenv("HOME"), 1);
				}
				else if (_strcmp(argv[1], "-") == 0)
				{
					if(chdir(_getenv("OLDPWD")))
						_setenv("PWD", getcwd(buffer, 1024), 1);
				}
				else
				{
					if (chdir(argv[1]) == 0)
					_setenv("PWD", getcwd(buffer, 1024), 1);
					else
						perror("chdir");
					free(buffer);
				}
				continue;
			}

			if (str_containe(lineptr, "/bin") != 0)
			{
				_strcpy(path_copy, path);
				token = handleCommand(path_copy, lineptr, &cmd);
				if (token == NULL)
				{
					perror(argvv[argc - 1]);
					free(lineptr);
					free(cmd);
					continue;
				}
			}

			if (cmd)
			{
				pid = fork();
				if (pid == 1)
				{
					perror("fork");
				}
				if (pid == 0)
				{
					argv = setexecveArgs(lineptr);
					execve(cmd, argv, environ);
				}
				else
				{
					wait(&status);
					free(lineptr);
				}
			}

		}
		else
		{
			pipedCommand();
		}
	}
	return (0);
}


#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

int _strcmp(char *s1, const char *s2);
int _strlen(const char *s);
char *_strcat(char *s, char *str);
char *_strcpy(char *dest, char *src);
int str_containe(char *s, char *str);

char *_getenv(char *name);
int _setenv(const char *name, const char *value, int overwrite);

char *_search(char **env, char *name, char c);
char **setexecveArgs(char *lineptr);
int _putchar(char c);
void print_env(char **env);
char *extractToken(char *lineptr);
void removenewtag(char *lineptr, ssize_t linelen);
void printString(char *str, ssize_t length);
ssize_t _getline(char **buffer, ssize_t *n, FILE *stream);
char *handleCommand(char *path_copy, char *lineptr, char **cmd);
void pipedCommand(char *filename);
char *str_remove(const char *str, const char *s);

#endif

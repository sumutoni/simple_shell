#ifndef SHELL_H
#define SHELL_H
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct variable - linked list of environment variables
 * @name: name of variable
 * @value: value of variable
 * @next: next variable
 *
typedef struct variable
{
	char *name;
	char *value;
	struct variable next;
} var;
*/
/**
 * struct command - struct of built-in commands
 * @name: name of command
 * @pointer: pointer to the command function
 */
typedef struct command
{
	char *name;
	int (*pointer) (char **args, char **env);
} command;

int initialize_shell(char **args, char **envp, char **envs);
int execute(char **args, char **env);
char *readline();

char **splitline(char *line, char *delimiter);
char *_strcat(char *dest, char *app);
int _strlen(char *str);

char *isfile_found(char **path, char *program);
int print_env(char **args, char **env);
int add_command(char *, int (*pointer) (char **, char **), command **);

int _putchar(char c);
int change_dir(__attribute__((unused))char **argv, __attribute__((unused))char **envp);
int _getline(char *buffer, size_t *n, FILE *stream);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int break_on_error(char *message);
char *_strtok(char *str, char *delim);

#endif

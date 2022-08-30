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
	int (*pointer) (char **args);	
} com;
int initialize_shell(char **args, char **envp);
int execute(char **args);
char *readline();
char **splitline(char *line);

#endif

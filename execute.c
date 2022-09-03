#include "shell.h"
#define SIZE 5

/**
 * execute - execute command passed to the shell
 * @args: pointer to line containing command and arguments
 *
 * Return: 1 for success, -1 for failure
 */
int execute(char **args, char **envp)
{
	com *commands = built_ins(args, envp);
	int i, result = -1;

	if (args[0] == NULL)
		return (1);
	for (i = 0; commands[i].name; i++)
	{
		if (strcmp(args[0], commands[i].name) == 0)
		{
			result = commands[i].pointer(args, envp);
			free(commands);
			return (result);
		}
	}
	return (result);
}
/**
 * built_ins - specify the builtin variables to handle
 * @args: the string of command and its arguments
 * @envp: the environemnt variables it may need
 *
 * Return: array of type com
 */
com *built_ins(char **args, char **envp)
{
	com *made_in_shell;

	(void) args, (void)envp;
	made_in_shell = malloc(sizeof(com) * SIZE);
	made_in_shell[0].name = "env";
	made_in_shell[0].pointer = print_env;

	return (made_in_shell);
}

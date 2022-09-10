#include "shell.h"

/**
 * execute - execute command passed to the shell
 * @args: pointer to line containing command and arguments
 * @env: array of environment environment variables
 *
 * Return: 1 for success, -1 for failure
 */
int execute(char **args, char **env)
{
	int i, result = -1, size;
	command **coms;


	if (args == NULL)
		return (-1);
	size = 0;
	coms = _calloc(sizeof(command), 1);
	/*testing if add_command works well*/
	size += add_command("env", print_env, coms);
	size += add_command("cd", change_dir, coms);
	coms[size] = NULL;
	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1] == NULL)
			__exit(0);
		else
			__exit(atoi(args[1]));
	}
	for (i = 0; i < size; i++)
	{
		if (strcmp(args[0], coms[i]->name) == 0)
		{
			result = coms[i]->pointer(args, env);
			return (result);
		}
	}
	for (i = 0; i < size; i++)
	{
		if (coms[i])
			free(coms[i]);
	}
	free(coms);
	return (result);
}

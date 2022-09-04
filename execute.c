#include "shell.h"

/**
 * execute - execute command passed to the shell
 * @args: pointer to line containing command and arguments
 *
 * Return: 1 for success, -1 for failure
 */
int execute(char **args, char **env)
{
	int i, result = -1;
	command **coms;

	if (args == NULL)
		return (-1);
	coms = malloc(sizeof(command));
	/*testing if add_command works well*/
	add_command("env", print_env, coms);
	add_command("cd", change_dir, coms);
	for (i = 0; i < 1; i++)
	{
		if (strcmp(args[0], coms[i]->name) == 0)
		{
			result = coms[i]->pointer(args, env);
			return (result);
		}
	}
	return (result);
}

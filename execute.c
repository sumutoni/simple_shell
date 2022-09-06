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
	int i, result = -1;
	command **coms;
	pid_t pid;

	if (args == NULL)
		return (-1);
	coms = malloc(sizeof(command));
	/*testing if add_command works well*/
	add_command("env", print_env, coms);
	add_command("cd", change_dir, coms);
	if (strcmp(args[0], "exit") == 0)
	{
		if (args[1] == NULL)
			__exit(0);
		else
			__exit(atoi(args[1]));
	}
	for (i = 0; i < 1; i++)
	{
		if (strcmp(args[0], coms[i]->name) == 0)
		{
			pid = fork();
			if (pid == -1)
				perror("Fork");
			if (pid == 0)
			{
				result = coms[i]->pointer(args, env);
				return (result);
			}
			else
			{
				wait(NULL);
			}
		}
	}
	return (result);
}

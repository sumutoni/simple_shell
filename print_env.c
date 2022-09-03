#include "shell.h"

/**
 * print_env - prints all environment variables
 */
int print_env(char **args, char **env)
{
	char *var;
	int size;
	(void)args;

	if (!env)
	{
		write(1, "No variables", 13);
		return (-1);
	}
	var = malloc(sizeof(char) * 1024);
	if (!var)
	{
		perror("Malloc failure");
		return (-1);
	}
	var = *env;
	while (var)
	{
		size = strlen(var);
		write(1, var, size);
		write(1, "\n", 1);
		env++;
		var = *env;
	}
	return (1);
}

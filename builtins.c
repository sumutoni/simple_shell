#include "shell.h"

/**
 * print_env - print the environment variables
 * @args: the arguments
 * @envp: pointer to the array of environment variables
 *
 * Return: 1 on success, -1 on failure
 */
int print_env(__attribute__((unused))char **args,
		__attribute__((unused))char **envp)
{
	int i;

	if (!(*envp))
		return (-1);
	for (i = 0; envp[i]; i++)
	{
		write(STDOUT_FILENO, envp[i], _strlen(envp[i]));
		_putchar('\n');
	}
	return (1);
}
/**
 * change_dir - change the current directory of the parent process
 * @args: the arguments
 * @envp: pointer to array of environment variables
 *
 * Return: 1 on success, -1 otherwise
 */
int change_dir(__attribute__((unused))char **args,
		__attribute__((unused))char **envp)
{
	if (args[2])
	{
		perror("chdir");
		return (-1);
	}
	return (chdir(args[1]));
}

#include "shell.h"
#define ALLOCATED 1
#define NOT_ALLOCATED 0

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
	int state;
	char *env;
	char *buf = _calloc(sizeof(char), 255);

	if (args[2])
	{
		perror("chdir");
		return (-1);
	}
	state = NOT_ALLOCATED;
	buf = getcwd(buf, 255);
	if (!args[1])
	{
		env = get_env("HOME");
		state = ALLOCATED;
	}
	else if (*args[1] == '-')
	{
		env = get_env("OLDPWD");
		state = ALLOCATED;
	}
	else
		env = args[1];
	setenv("OLDPWD", buf, 1);
	chdir(env);
	free(buf);
	if (state)
		free(env);
	return (1);
}
/**
 * __exit - exit out of a process
 * @status: exit status
 */
int __exit(int status)
{
	return (status);

}

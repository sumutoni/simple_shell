#include "shell.h"

/**
 * main - launches the shell
 *
 * Return: 0 for success, -1 for failure
 */
int main(__attribute__((unused))int ac, __attribute__((unused))char **av, char **envs)
{
	int status;
	char **arguments;
	char *line, *delim, *path_env, **path;

	delim = " \n";
	path_env = getenv("PATH");
	path = splitline(path_env, ":");
	do {
		_putchar('$');
		_putchar(' ');
		line = readline();
		/* condition to check if newline character is entered*/
		if (*line == '\n')
			continue;
		arguments = splitline(line, delim);

		if (strcmp(arguments[0], "exit") == 0)
			break;
		status = execute(arguments, envs);
		if (status == -1)
			status = initialize_shell(arguments, path, envs);
	} while (status);
	return (status);
}

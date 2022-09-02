#include "shell.h"

/**
 * main - launches the shell
 *
 * Return: 0 for success, -1 for failure
 */
int main(void)
{
	int status;
	char **arguments;
	char *line, *delim, *path_env, **path;

	delim = " \n";
	path_env = getenv("PATH");
	path = splitline(path_env, ":");
	do {
		printf("$ ");
		line = readline();
		arguments = splitline(line, delim);
		if (strcmp(arguments[0], "exit") == 0)
			break;
		status = initialize_shell(arguments, path);
	} while (status);
	return (status);
}

#include "shell.h"

/**
 * main - launches the shell
 * @ac: number of arguments
 * @av: pointer to string arguments
 *
 * Return: 0 for success, -1 for failure
 */
int main(void)
{
	int status;
	char **arguments;
	char *line, *delim, *path_env;

	delim = " \n";
	path_env = getenv("PATH");
	do {
		printf("$ ");
		line = readline();
		arguments = splitline(line, delim);
		status = initialize_shell(arguments, &path_env);
	} while (status);
	return (status);
}

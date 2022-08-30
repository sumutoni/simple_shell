#include "shell.h"

/**
 * main - launches the shell
 * @ac: number of arguments
 * @av: pointer to string arguments
 *
 * Return: 0 for success, -1 for failure
 */
int main(int ac, char **av)
{
	int status;
	char **arguments;
	char *line;

	do {
		printf("$ ");
		line = readline();
		arguments = splitline(line);
		status = initialize_shell(arguments, NULL, av[0]);
	} while (status);
	return (status);
}

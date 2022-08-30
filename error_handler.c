#include "shell.h"

/**
 * print_command_error -  prints error message in case command not found
 * @command: the command that caused an error
 */
void print_command_error(char *command)
{
	printf("%s: no such file or directory\n", command);
}

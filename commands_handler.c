#include "shell.h"

/**
 * check_command - checks if command already exists
 * @name: name of command
 *
 * Return: 1 if it exists, 0 if not
 */
int check_command(char *name, command **coms)
{
	int i;

	if (!coms)
		return (0);
	for (i = 0; coms[i]; i++)
	{
		if (!(coms[i]->name) && strcmp(coms[i]->name, name) == 0)
				return (1);
	}
	return (0);
}
/**
 * add_command - adds a command to array of commands
 * @name: name of command
 * @pointer: function pointer to command
 *
 * Return: 1 for success -1 for failure
 */
int add_command(char *name, int (*pointer) (char **, char **), command **coms)
{
	command *com;/* **sub;*/
	int count = 0, i;

	if (!name || !pointer)
		return (-1);
	if (check_command(name, coms))
		return (1);
	
	com = malloc(sizeof(command));
	if (!com)
	{
		perror("malloc");
		return (-1);
	}
	com->name = name;
	com->pointer = pointer;

	while (*coms)
	{
		count++;
		coms++;
	}
	_realloc((void *)coms, count, count+1);
	for (i = 0; i < (count + 1); i++)
	{
		if (!coms[i])
		{
			coms[i] = com;
		}
	}
	return (1);
}

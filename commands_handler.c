#include "shell.h"

/**
 * check_command - checks if command already exists
 * @name: name of command
 *
 * Return: 1 if it exists, 0 if not
 */
int check_command(char *name)
{
	if (!coms)
		return (0);
	while (*coms)
	{
		if (strcmp((*coms)->name, name) == 0)
			return (1);
		coms++;
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
int add_command(char *name, int (*pointer) (char **, char **))
{
	command *com, **sub;
	int count = 0;

	if (!name || !pointer)
		return (-1);
	if (check_command(name))
		return (1);
	com = malloc(sizeof(command) * 10);
	if (!com)
	{
		return (-1);
	}
	com->name = name;
	com->pointer = pointer;
	if (!coms)
	{
		coms = malloc(sizeof(command *));
		if (!coms)
			return (-1);
		*coms = NULL;
	}
	while (*coms)
	{
		count++;
		coms++;
	}
	count++;
	sub = malloc(sizeof(command *) * count);
	if (!sub)
		return (-1);
	sub = coms;
	coms = malloc(sizeof(command *) * count);
	while (*sub)
	{
		*coms = *sub;
		sub++;
		coms++;
	}
	*coms = com;
	return (1);
}

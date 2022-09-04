#include "shell.h"
#define BUFSIZE 1024
/**
 * readline - reads in input
 *
 * Return: line read in
 */
char *readline()
{
	char *line;
	size_t buf = BUFSIZE;
	int bytes;

	line = malloc(sizeof(char) * BUFSIZE);
	if (!line)
		exit(EXIT_SUCCESS);
	bytes = _getline(line, &buf, stdin);
	if (bytes < 0)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}
/**
 * splitline - split a line commands and arguments
 * @args: line to split
 * @delimiter: the delimiter
 *
 * Return: pointer to argument strings
 */
char **splitline(char *args, char *delimiter)
{
	char **arguments;
	char *argument;
	int index = 0;

	arguments = malloc(sizeof(char *) * BUFSIZE);
	if (!arguments)
		exit(EXIT_FAILURE);
	argument = strtok(args, delimiter);
	while (argument != NULL)
	{
		arguments[index] = malloc(sizeof(char) * BUFSIZE);
		arguments[index] = argument;
		index++;
		argument = strtok(NULL, delimiter);
	}
	arguments[index] = NULL;
	return (arguments);
}

/**
 * _getline - get a line of input from the stdin
 * @buffer: where to store the resulting line
 * @n: the size of the buffer
 * @stream: the stream of input, where we read from
 *
 * Return: number of chars read
 */
int _getline(char *buffer, size_t *n, FILE *stream)
{
	int i, fd, rd;

	fd = fileno(stream);
	fd = dup(fd);
	if (fd == -1)
		return (-1);
	if ((!buffer) && *n == 0)
	{
		buffer = malloc(sizeof(char) * 1024);
		if (!buffer)
			break_on_error("malloc");
	}
	if ((rd = read(fd, buffer, 1024)) == -1)
		break_on_error("malloc");

	for (i = 0; i < rd; i++)
	{
		if (buffer[i] == '\n')
			break;
	}
	buffer[++i] = '\0';

	close(fd);
	return(i);
}


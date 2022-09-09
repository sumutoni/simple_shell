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

	line = _calloc(sizeof(char), BUFSIZE);
	if (!line)
		exit(EXIT_SUCCESS);
	bytes = getline(&line, &buf, stdin);
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

	arguments = _calloc(sizeof(char *), BUFSIZE);
	if (!arguments)
		exit(EXIT_FAILURE);
	argument = _strtok(args, delimiter);
	while (argument[0] != '\0')
	{
		arguments[index] = argument;
		index++;
		argument = _strtok(NULL, delimiter);
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
		buffer = _calloc(sizeof(char), 1024);
		if (!buffer)
			break_on_error("malloc");
	}
	rd = read(fd, buffer, 1024);
	if (rd == -1)
		break_on_error("malloc");

	for (i = 0; i < rd; i++)
	{
		if (buffer[i] == '\n')
			break;
	}
	buffer[++i] = '\0';

	close(fd);
	return (i);
}
/**
 * _strtok - string tokenizer
 * @str: the string to parse
 * @delim: the delimiter to use parsing
 *
 * Return: pointer to the new fragment
 */
char *_strtok(char *str, char *delim)
{
	char *token;
	static char *remember_me;
	int i;

	if (str)
	{
		remember_me = _realloc(remember_me, _strlen(remember_me), _strlen(str) + 2);
	}
	token = _calloc(sizeof(char), 255);

	/* string validity checks */
	if (!remember_me || !token)
	{
		break_on_error("malloc");
		return (NULL);
	}
	if (!str && !remember_me)
	{
		free(token);
		break_on_error("invalid pointer");
		return (NULL);
	}
	if (str)
	{
		strcpy(remember_me, str);
	}
	/* tokenizing */
	for (i = 0; remember_me[i] != '\n' && remember_me[i] != '\0'; i++)
	{
		if (remember_me[i] == *delim)
			break;
		token[i] = remember_me[i];
	}
	token[i] = '\0';
	remember_me += i + 1;

	return (token);
}

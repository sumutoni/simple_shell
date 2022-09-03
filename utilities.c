#include "shell.h"
/**
 * isfile_found - check if program executable file is
 *	in $PATH
 * @path: array of directories in variable $PATH
 * @program: the executable file name to find in the path
 *
 * Return: String to the correct path, NULL if otherwise
 */
char *isfile_found(char **path, char *program)
{
	int i;
	char *possible_path;

	for (i = 0; path[i]; i++)
	{
		possible_path = _strcat(path[i], program);
		if (access(possible_path, F_OK) == 0)
		{
			return (possible_path);
		}
		else
		{
			free(possible_path);
			possible_path = NULL;
		}
	}

	return (NULL);
}

/**
 * _strcat - concatenate two strings
 * @dest: the first file
 * @app: the appendee
 *
 * Return: pointer to new string consisting of first two
 */
char *_strcat(char *dest, char *app)
{
	int i, j;
	char *new_str;

	new_str = malloc(sizeof(*dest) * _strlen(dest) + _strlen(app) + 1);
	if (!new_str)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	for (i = 0; dest[i] != '\0'; i++)
		new_str[i] = dest[i];

	new_str[i] = '/';

	for (j = 0, i++; app[j] != '\0'; j++, i++)
		new_str[i] = app[j];
	new_str[i] = '\0';
	return (new_str);
}
/**
 * _strlen - find the length of a string
 * @str: the string to search length for
 *
 * Return: length of the string
 */
int _strlen(char *str)
{
	int i;

	if (!str)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{
		;
	}
	return (i);
}
/**
 * _putchar - write one character to stdout
 * @c: the character to print
 *
 * Return: number of chars printed
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
/**
 * _getline - get a line of input from the stdin
 * @buffer: where to store the resulting line
 * @n: the size of the buffer
 * @stream: the stream of input, where we read from
 *
 * Return: number of chars read
 */
int _getline(char *buffer, int n, FILE *stream)
{
	int len;

	if (n == 0 && !buffer)
	{
		buffer = malloc(sizeof(char) * 1024);
		if (!buffer)
			return (0);
		len = read(STDIN_FILENO, buffer, 1024);
	else
	{
		len = read(STDIN_FILENO, buffer, n);



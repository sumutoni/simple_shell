#include "shell.h"

/**
 * get_env -  retrieves environment variable
 * @env: environement variable to get
 *
 * Return: environment variable
 */
char *get_env(char *env)
{
	char *s, *val;
	int i;

	s = _calloc(sizeof(char), 1024);
	val = _calloc(sizeof(char), 1024);
	if (!s || !val)
		return (NULL);
	if (!env)
		return (NULL);
	if (!envp)
		return (NULL);
	for (i = 0; envp[i]; i++)
	{
		if (strstr(envp[i], env))
		{
			strcpy(val, envp[i]);
			strtok(val, "=");
			s = strtok(NULL, "=");
			break;
		}
	}
	return (s);
}

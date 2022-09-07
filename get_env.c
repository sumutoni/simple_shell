#include "shell.h"

/**
 * get_env -  retrieves environment variable
 * @env: environement variable to get
 *
 * Return: environment variable
 */
char *get_env(char *env)
{
	char *s;
	int i;

	s = malloc(sizeof(char) * 1024);
	if (!s)
		return (NULL);
	if (!env)
		return (NULL);
	if (!envp)
		return (NULL);
	for (i = 0; envp[i]; i++)
	{
		if (strstr(envp[i], env))
		{
			strtok(envp[i], "=");
			s = strtok(NULL, "=");
			break;
		}
	}
	return (s);
}

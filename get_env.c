#include "shell.h"

/**
 * get_env -  retrieves environment variable
 * @env: environement variable to get
 * @envp: array of environment variables
 *
 * Return: environment variable
 */
char *get_env(char *env, char **envp)
{
	char *s;

	s = NULL;
	if (!env)
		return (NULL);
	if (!envp)
		return (NULL);
	while (envp)
	{
		if (strstr(*envp, env))
		{
			strtok(*envp, "=");
			s = strtok(NULL, "=");
		}
		envp++;
	}
	return (s);
}

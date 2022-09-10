#include "shell.h"

/**
 * get_env -  retrieves environment variable
 * @env: environement variable to get
 *
 * Return: environment variable
 */
char *get_env(char *env)
{
	char *val;
	int i;

	val = _calloc(sizeof(char), 1024);
	if (!val)
		return (NULL);
	if (!env)
		return (NULL);
	if (!envp)
		return (NULL);
	for (i = 0; envp[i]; i++)
	{
		if (strncmp(envp[i], env, _strlen(env)) == 0)
		{
			strcpy(val, envp[i] + _strlen(env));
			break;
		}
	}
	return (val);
}

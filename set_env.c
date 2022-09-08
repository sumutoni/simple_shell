#include "shell.h"

/**
 * create_list - creates linked list of environment variables
 * @count: counts number of variables
 * @envp: array of environment variables
 *
 * Return: head of the list
 */
var *create_list(int *count, char **envp)
{
	var *head, *curr;
	int i;

	curr = malloc(sizeof(var));
	if (!curr)
		return (NULL);
	i = 0;
	if (!envp)
		return (NULL);
	while (envp[i])
	{
		curr->name = strtok(envp[i], "=");
		curr->value = strtok(NULL, "=");
		curr->next = NULL;
		(*count)++;
		if (i == 0)
			head = curr;
		curr = curr->next;
		i++;
	}
	return (head);
}
/**
 * populate_arr - populates array of environment variables
 * @head: head of linkedlist
 * @count: current number of variables
 * @envp: array of environment variables
 */
void populate_arr(var *head, int count, char **envp)
{
	char **env;
	char *va;
	var *curr;

	curr = head;
	if (count > 0)
	{
		env = malloc(sizeof(char *) * (count + 1));
		if (!env)
			exit(EXIT_FAILURE);
	}
	while (curr)
	{
		va = strcat(curr->name, "=");
		va = strcat(va, curr->value);
		if (*envp)
		{
			*envp = va;
		}
		envp++;
		curr = curr->next;
	}
}
/**
 * set_env - creates a new env
 * @name: name of variable
 * @value: value of variable
 * @overwrite: overwrite status; 0 for no overwrite,
 * a nonzero value for overwrite
 * @envp: array of environment variables
 *
 * Return: 1 for success, -1 for failure
 */
int set_env(char *name, char *value, int overwrite, char **envp)
{
	var *curr, *head;
	int count = 0, status = -1;

	if (!name || !value)
		return (status);
	head = create_list(&count, envp);
	curr = head;
	if (!overwrite)
	{
		while (curr)
			curr = curr->next;
		curr->name = name;
		curr->value = value;
		curr->next = NULL;
	}
	populate_arr(head, count, envp);
	return (1);
}

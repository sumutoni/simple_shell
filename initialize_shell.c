#include "shell.h"
/**
 * initialize_shell - initializes shell
 * @args: pointer to arguments passed
 * @envp: pointer to environment variables
 * @s: argument passed to start shell
 *
 * Return: 1 if initialization is successful, -1 if failed
 */
int initialize_shell(char **args, char **envp)
{
	pid_t pid;
	int status;
	char **path, *delim, *program_file;
	
	delim = ":";
	if (!(*envp))
	{
		perror("getenv");
		return (-1);
	}
	path = splitline(*envp, delim);

	program_file = isfile_found(path, args[0]);
	if (!program_file)
	{
		perror("access");
		return (-1);
	}

	pid = fork();
	if (pid < 0)
	{
		perror("Fork");
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(program_file, args, NULL) == -1)
		{
			free(program_file);
			perror("execve");
			return (-1);
		}
	}
	else
	{
		do {
			wait(&status);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	free(program_file);
	return (1);
}

#include "shell.h"
/**
 * initialize_shell - initializes shell
 * @args: pointer to arguments passed
 * @path: PATH variable containing directories to look through
 * @envp: pointer to environment variables
 *
 * Return: 1 if initialization is successful, -1 if failed
 */
int initialize_shell(char **args, char **path, char **envp)
{
	pid_t pid;
	int status;
	char *program_file;

	if (!(*envp))
	{
		perror("getenv");
		return (-1);
	}
	if (**args == '/')
		program_file = args[0];
	else
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
		if (execve(program_file, args, envp) == -1)
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

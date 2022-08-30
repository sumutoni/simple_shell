#include "shell.h"
/**
 * initialize_shell - initializes shell
 * @args: pointer to arguments passed
 * @envp: pointer to environment variables
 * @s: argument passed to start shell
 *
 * Return: 1 if initialization is successful, -1 if failed
 */
int initialize_shell(char **args, char **envp, char *s)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		printf("Forking error\n");
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			print_command_error(s);
			return (-1);
		}
		execve(args[0], args, NULL);
	}
	else
	{
		do {
			wait(&status);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

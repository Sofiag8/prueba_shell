#include "holberton.h"
/**
 * forkwaitexec - executes the commands passed
 * @argv: commands passed in CL
 * Return: 0 success otherwise 1
 */
int forkwaitexec(char *argv)
{
	pid_t shell_pid;
	int status;
	char *args[] = {argv, NULL};

	argv = strtok(argv, "\n");
	shell_pid = fork();
	if (shell_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (shell_pid == 0)
	{
		shell_pid = execve(args[0], args, NULL);
		write(STDERR_FILENO, ": command not found\n", 21);
		exit(EXIT_FAILURE);
	}
	else
		shell_pid = wait(&status);
	return (0);
}

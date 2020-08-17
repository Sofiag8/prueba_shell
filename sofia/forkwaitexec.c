#include "holberton.h"
/**
 * forkwaitexec - processes, wait and execute what receives from strtok
 * @argv: the string entered as command
 * Return: the execution and end
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
		write(STDERR_FILENO, "hsh:command not found\n", 23);
		exit(EXIT_FAILURE);
	}
	else
		shell_pid = wait(&status);
	return (0);
}

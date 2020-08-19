#include "holberton.h"
/**
 * forkwaitexec - executes the commands passed
 * @argv: commands passed in CL
 * Return: 0 success otherwise 1
 */
int forkwaitexec(char *argv)
{
	pid_t shell_pid;
	int status, exec = 0;
	char *args[] = {argv, NULL};

	argv = strtok(argv, " \n\t\r");
	shell_pid = fork();
	if (shell_pid == -1)
	{
		perror("Error");
		return (1);
	}
	if (shell_pid == 0)
	{
		shell_pid = execve(args[0], args, NULL);
		write(STDERR_FILENO, argv, _strlen(argv));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, args[0], _strlen(args[0]));
		write(STDERR_FILENO, ": not such file or directory\n", 30);
	}
	else
	{
		shell_pid = wait(&status);
		if (WIFEXITED(status) && status != 0)
			exec = WEXITSTATUS(status);
	}
	return (exec);
}

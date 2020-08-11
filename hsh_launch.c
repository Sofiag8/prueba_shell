#include "holberton.h"

int hsh_launch(char **av)
{
	pid_t pid, parent;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (pid == 0)
	{
		execve(av[0], av, NULL);
	}
	else
		parent = waitpid(pid, &status, WUNTRACED);
	return (1);
}

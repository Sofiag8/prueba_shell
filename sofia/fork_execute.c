#include "holberton.h"
/**
 * forkwaitexec - executes the commands passed
 * @argv: commands passed in CL
 * Return: 0 success otherwise 1
 */
void forkwaitexec(char **args, int *count)
{
<<<<<<< HEAD
||||||| merged common ancestors
	pid_t shell_pid;
	int status;
	char *args[] = {argv, NULL};
=======
	pid_t shell_pid;
	int status, exec = 0;
	char *args[] = {argv, NULL};
>>>>>>> 5c7504ce06207ba24254043b2d5129046c9cca31

<<<<<<< HEAD
	if (access(args[0], X_OK) == 0)
||||||| merged common ancestors
	argv = strtok(argv, "\n");
	shell_pid = fork();
	if (shell_pid == -1)
=======
	argv = strtok(argv, " \n\t\r");
	shell_pid = fork();
	if (shell_pid == -1)
>>>>>>> 5c7504ce06207ba24254043b2d5129046c9cca31
	{
<<<<<<< HEAD
		if (fork() == 0)
			execve(args[0], args, NULL);
		else
			wait(NULL);
||||||| merged common ancestors
		perror("Error:");
		return (1);
=======
		perror("Error");
		return (1);
>>>>>>> 5c7504ce06207ba24254043b2d5129046c9cca31
	}
	else if (access(args[0], F_OK) != 0)
	{
<<<<<<< HEAD
		print_string("sh: ");
		print_count(count);
		print_string(": ");
		perror(args[0]);
||||||| merged common ancestors
		shell_pid = execve(args[0], args, NULL);
		write(STDERR_FILENO, ": command not found\n", 21);
		exit(EXIT_FAILURE);
=======
		shell_pid = execve(args[0], args, NULL);
		write(STDERR_FILENO, argv, _strlen(argv));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, args[0], _strlen(args[0]));
		write(STDERR_FILENO, ": not such file or directory\n", 30);
>>>>>>> 5c7504ce06207ba24254043b2d5129046c9cca31
	}
	else if (access(args[0], F_OK) == 0 && access(args[0], X_OK) != 0)
	{
<<<<<<< HEAD
		print_string("sh: ");
		print_count(count);
		print_string(": ");
		perror(args[0]);
	}
	free(args);
}

/**
 *
 */
void print_count(int *count)
{
	int cnt, len, i, n;
	unsigned int base = 1, max, a;

	n = *count;
	max = n;
	a = max;
	do{
		a /= 10;
		++len;
	}while (a != 0);
	cnt += len;
	for (i = 0; i < len - 1; i++)
		base *= 10;
	write(STDOUT_FILENO, "0", 1) + (max/base);
	if (len > 1)
	{
		for (i = 0; i < len - 2; i++)
		{
			base /= 10;
			a = max / base;
			write(STDOUT_FILENO, "0", 1) + a % 10;
		}
		write(STDOUT_FILENO, "0", 1) + (max % 10);
||||||| merged common ancestors
		shell_pid = wait(&status);
		if (WIFEXITED(status) && status != 0)
			exit(WEXITSTATUS(status));
=======
		shell_pid = wait(&status);
		if (WIFEXITED(status) && status != 0)
			exec = WEXITSTATUS(status);
>>>>>>> 5c7504ce06207ba24254043b2d5129046c9cca31
	}
<<<<<<< HEAD
||||||| merged common ancestors
	return (0);
=======
	return (exec);
>>>>>>> 5c7504ce06207ba24254043b2d5129046c9cca31
}

#include "holberton.h"
/**
 * shell_loop - loop into functions that runs the shell
 * @argv: commands passed to the CL
 * @env: environment variable
 * Return: status of the proccess or 1 in error
 */
int shell_loop(char **argv, char **env)
{
	char *args;
	int status;

	do {
		args = read_command(env);
		status = forkwaitexec(args);
	}
	while (!status)
		;
	return (status);
}
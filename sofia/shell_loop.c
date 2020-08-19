#include "holberton.h"
/**
 * shell_loop - loop into functions that runs the shell
 * @argv: commands passed to the CL
 * @env: environment variable
 * Return: status of the proccess or 1 in error
 */
int shell_loop(char **argv, char **env)
{
<<<<<<< HEAD
	char *args;
||||||| merged common ancestors
	char *args;
	int status;
=======
	char *args = NULL;
	int status = 0;
	(void)**argv;
>>>>>>> 5c7504ce06207ba24254043b2d5129046c9cca31

	do {
		args = read_command(env);
	}
	while (1 == 1)
		;
<<<<<<< HEAD
	return (0);
||||||| merged common ancestors
	return (status);
=======
	free(args);
	return (status);
>>>>>>> 5c7504ce06207ba24254043b2d5129046c9cca31
}

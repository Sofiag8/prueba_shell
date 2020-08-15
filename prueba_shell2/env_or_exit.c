#include "holberton.h"
/**
 * env_or_exit - check if the command passed is env or exit builtins
 * @string: pointer containing what was passed to the command line
 * @token: pointer with the command to be check
 * Return: 1 in success 0 if not
 */
int env_or_exit(char *string, char *token)
{
	if ((_strcmp("exit", token)) == 0)
	{
		free(string);
		exit(0);
	}
	else if ((_strcmp("env", token)) == 0)
	{
		environment();
		return (1);
	}
	return (0);
}
/**
 * environment - the function created to print the environment
 * Return: nothing
 */
void environment(void)
{
	unsigned int runner_environ;
	unsigned int length_environ;

	if (environ == NULL || *environ[0] == '\0')
		return;
	runner_environ = 0;
	while (!environ[runner_environ])
	{
		length_environ = _strlen(environ[runner_environ]);
		write(STDOUT_FILENO, environ[runner_environ], length_environ);
		write(STDOUT_FILENO, "\n", 1);
		runner_environ++;
	}
}

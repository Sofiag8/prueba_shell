#include "holberton.h"

/**
 *
 */
void built_in(char *string, char **argv, char **env)
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		free(argv);
		free(string);
		exit (0);
	}
	if (_strcmp(argv[0], "env") == 0)
		printenv(env);
}

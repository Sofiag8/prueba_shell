#include "holberton.h"
/**
 * built_in - compare argv passed with the builtins commands
 * @string: pointer with the line saved
 * @argv: the arguments passed
 * @env: environment variable
 * Return: void
 */
void built_in(char *string, char **argv, char **env)
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		free(argv);
		free(string);
		exit(0);
	}
	if (_strcmp(argv[0], "env") == 0)
		printenv(env);
	if (_strcmp(argv[0], "cd") == 0)
		func_cd(argv, env);
}

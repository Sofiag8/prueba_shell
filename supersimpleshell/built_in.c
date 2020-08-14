#include "holberton.h"
char main(int argc, char **argv, char **env)
{
	built_in(argv, env);
	return(env);
}
/**
 *
 *
 *
 */
void built_in(char **argv, char **env)
{
	if (_strcmp(argv[0], "exit") == 0)
	{
		free(argv);
		free(string);
		exit(0);
	}
	if (_strcmp(argv[0], "env") == 0)
		printenv(env);
}
/**
 * _strcmp - compares two strings
 * @s1: character string 1
 * @s2: character string 2
 *
 * Return: an integer less than, equal to, or greater than zero if s1
 * found, respectively, to be less then, to march, or be greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return ((int) s1[i] - s2[i]);
		i++;
	}
	return (0);
}

#include "holberton.h"
/**
 * func_ctrl_d - allows use of ctrl d as way of shutting down shell
 * @string: the argument passed
 * @read: size of the saved string
 * Return: 0 success, otherwise 1
 */
int func_ctrl_d(char *string, ssize_t read)
{
	int i = 0;

	if (read == EOF && isatty(STDIN_FILENO) == 0)
	{
		free(string);
		exit(EXIT_SUCCESS);
	}
	if (read == EOF)
	{
		free(string);
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	if (_strcmp(string, "\n") == 0)
	{
		return (1);
	}
	while (string[i] != '\n')
	{
		if (string[i] != ' ' && string[i] != '\t')
			return (0);
		++i;
	}
	return (1);
}

#include "holberton.h"

/**
 *
 */
int func_ctrl_c(char *string, ssize_t read)
{
	int i;

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

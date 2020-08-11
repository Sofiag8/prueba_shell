#include "holberton.h"

char *read_shell(void)
{
	char *line = NULL;
	ssize_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	return (line);
}

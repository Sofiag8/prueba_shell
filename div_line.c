#include "holberton.h"

char **div_line(char *line)
{
	int bufsize = 64, position = 0;
	char **tokens = malloc(bufsize * sizeof(char));
	char *token;
	const char *delim = " ";

	token = strtok(line, delim);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = realloc(tokens, bufsize * sizeof(char));
		}
		token = strtok(NULL, delim);
	}
	tokens[position] = NULL;
	return (tokens);
}

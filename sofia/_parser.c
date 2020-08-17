#include "holberton.h"

char **_parser(char *string)
{
	char **args;

	char *parsed = NULL;
	char *parsed2 = NULL;
	char *linecopy = NULL;
	int arg_num = 0, i = 0;

	printf("parser: %s\n", string);
	linecopy = _strdup(string);
	printf("lynecopy: %s\n", linecopy);
	parsed = strtok(linecopy, " \t");

	while (parsed != NULL)
	{
		arg_num++;
		parsed = strtok(NULL, " \t");
	}

	args = malloc(sizeof(char *) * (arg_num + 1));

	if (args == NULL)
		return (NULL);

	parsed2 = strtok(string, " \t");

	while (parsed2 != NULL)
	{
		args[i] = parsed2;
		parsed2 = strtok(NULL, " \t");
		i++;
	}

	args[i] = NULL;
	free(linecopy);
	return (args);
}

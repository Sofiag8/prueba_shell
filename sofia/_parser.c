#include "holberton.h"
/**
 * _parser - function to allocate memory and tokenize
 * @string: the argument passed  saved on getline
 * Return: double pointer
 */
char **_parser(char *string)
{
	char **args;
	char *parsed = NULL;
	char *parsed2 = NULL;
	char *linecopy = NULL;
	int arg_num = 0, i = 0;

	linecopy = _strdup(string);
	parsed = strtok(linecopy, " \t\n\r");

	while (parsed != NULL)
	{
		arg_num++;
		parsed = strtok(NULL, " \t\n\r");
	}

	args = malloc(sizeof(char *) * (arg_num + 1));

	if (args == NULL)
		return (NULL);

	parsed2 = strtok(string, " \t\n\r");

	while (parsed2 != NULL)
	{
		args[i] = parsed2;
		parsed2 = strtok(NULL, " \t\n\r");
		i++;
	}

	args[i] = NULL;
	free(linecopy);
	return (args);
}

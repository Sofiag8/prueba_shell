#include "holberton.h"

/**
 *
 */
int _path(char *args, char **entra, char **env)
{
	int i;
	char *tmp, *izq, *der;
	char *copy, *envcp, *new;
	char *path = "PATH";

	for (i = 0; env[i] != '\0'; i++)
	{
		envcp = _strdup(env[i]);
		izq = strtok(envcp, "=\t");
		tmp = strtok(NULL, "=\t");
		if (_strcmp(izq, path) == 0)
		{
			der = strtok(tmp, ":\t");
			while (der)
			{
				new = print_path(der, args);
				if (fork() == 0)
					execve(new, entra, NULL);
				else
					wait(NULL);
				free(new);
				free(envcp);
				return (0);
			}
			der = strtok(NULL, ":\t");
			free(new);
		}
		free(envcp);
	}
	return (2);
}

/**
 *
 */
char *print_path(char *der, char *args)
{
	char *token, *copy;
	int tk_leng, leng;

	token = der;
	tk_leng = _strlen(token);
	leng = _strlen(args);
	copy = malloc((tk_leng + leng + 2) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	copy[0] = '\0';
	_strncat(copy, der);
	_strncat(copy, "/");
	_strncat(copy, args);
	_strncat(copy, "\0");
	return (copy);
}

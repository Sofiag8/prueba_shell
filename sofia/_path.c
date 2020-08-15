#include "holberton.h"

/**
 *
 */
int _path(char *args, char **argv, char **env)
{
	int i;
	char *tmp, *izq, *der;
	char *copy, *envcp;
	printf("(%s) %s (%s)\n", args, *argv, *env);
	for (i = 0; env[i] != NULL; i++)
	{
		envcp = _strdup(env[i]);
		izq = strtok(envcp, "= \t");
		printf("izq: %s\n", izq);
		tmp = strtok(NULL, "= \t");
		printf("tmp: %s\n", tmp);
		if (_strcmp(izq, "PATH") == 0)
		{
			der = strtok(tmp, ": \t");
			printf("der: %s\n", der);
			while (der)
			{
				copy = print_path(der, args);
				printf("copy: %s\n", copy);
				if (fork() == 0)
					execve(copy, argv, NULL);
				else
					wait(NULL);
				free(copy);
				free(envcp);
				return (0);
			}
			der = strtok(NULL, ": \t");
			free(copy);
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

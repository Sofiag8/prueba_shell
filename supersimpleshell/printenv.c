#include "holberton.h"
/**
 * printenv - prints the environment
 * @env: double pointer with the env
 * Return: 0 success
 */
void printenv(char **env)
{
        unsigned int runner;
	unsigned int lenght;

	if (environ == NULL || *environ[0] == '\0')
		return;

	environ = env;
        runner = 0;
        while (environ[runner] != NULL)
        {
                lenght = _strlen(environ[runner]);
		write(STDOUT_FILENO, environ[runner], lenght);
		write(STDOUT_FILENO, "\n", 1);
                runner++;
        }
}
/**
 * _strlen - function return length of string
 * @s: string
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}

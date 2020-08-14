#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
char printenv(char **env)
{
	unsigned int i;
	unsigned int lenght;

	i = 0;
	while (env[i] != NULL)
	{
		lenght = strlen(env[i]);
		write(STDOUT_FILENO, env[i], lenght);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
void main(int ac, char **av, char **env)
{
	printenv(env);
}

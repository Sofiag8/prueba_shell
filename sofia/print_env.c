#include "holberton.h"
/**
 * printenv - prints the environment
 * @env: environment variable
 * Return: Always 0 in success. Otherwise 1.
 */
int printenv(char **env)
{
        unsigned int i;
        int j, print;

        for (i = 0; env[i] != NULL; i++)
        {
                print_string(env[i]);
                write(STDOUT_FILENO, "\n", 1);
        }
        return (EXIT_SUCCESS);
}
/**
 *  print_string - auxiliar function to print each linea of env
 * @env: environment variable passed from printenv
 * Return: void
 */
void print_string(char *env)
{
        int i, print;

        for (i = 0; env[i] != '\0'; i++)
                ;
        print = write(STDOUT_FILENO, env, i);
        if (print == EOF)
                return;
}

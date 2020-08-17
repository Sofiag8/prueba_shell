#include "holberton.h"
/**
 * main function
 * @argc: number of arguments
 * @argv: arguments
 * @env: env
 * Return: exit success
 */
int main(int argc, char **argv, char **env)
{
        shell_loop(argv);
        return (EXIT_SUCCESS);
}

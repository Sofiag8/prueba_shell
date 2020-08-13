#include "holberton.h"
/**
 * read_command - read a line from stdin
 * Description: print command prompt, read argumt entered from standar input
 * Return: a pointer contaning the string passed to the CLI
 */
char *read_command(void)
{
        char *string = NULL;
        /* have getline allocate a buffer for us */
        size_t bufsize = 0;

        write(STDOUT_FILENO, "shell$ ", 7);
        if (getline(&string, &bufsize, stdin) == -1)
        {
                if (feof(stdin))
                {
                        write(STDOUT_FILENO, "\n", 1);
                        exit(EXIT_SUCCESS);
                }
                else
                {
                        perror("Error:");
                        exit(EXIT_FAILURE);
                }
        }
        return (string);
}

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
	ssize_t buffer = 0;
	int args_counter = 1;
	int exec = 0;

        write(STDOUT_FILENO, "shell$ ", 7);
        while ((buffer = getline(&string, &bufsize, stdin)))
        {
                if (buffer == EOF)
                {
			free(string);
                        write(STDOUT_FILENO, "\n", 1);
                        exit(EXIT_SUCCESS);
                }
                if (*string == '\n')
                {
			write(STDOUT_FILENO, "shell$ ", 7);
			args_counter++;
                        continue;
                }
		exec = forkwaitexec(&string, &bufsize, &args_counter);
		write(STDOUT_FILENO, "shell$ ", 7);
        }
        return (exec);
}

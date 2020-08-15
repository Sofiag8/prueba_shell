#include "holberton.h"
/**
 * shell_loop - loops for all the shell functions
 * @argv: double pointer receving the arguments in the CLI
 * Return: status
 */
int shell_loop(char **argv)
{
/* char *read_command(void);
   int forkwaitexec(char **string, size_t *bufsize, int *args_counter); */

        char *args;
	size_t *bufsize;
	int *args_counter;
	/*char **split_string;*/
        int status;

        do
        {
                args = read_command();
                status = forkwaitexec(args, bufsize, args_counter);
        }
        while (!status)
                ;
        return (status);
}

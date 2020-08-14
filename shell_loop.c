#include "holberton.h"
/**
 * shell_loop - loops for all the shell functions
 * @argv: double pointer receving the arguments in the CLI
 * Return: status
 */
int shell_loop(char **argv)
{
        char *args;
        int status;

        do
        {
                args = read_command();
                status = forkwaitexec(args);
        }
        while (!status)
                ;
        return (status);
}

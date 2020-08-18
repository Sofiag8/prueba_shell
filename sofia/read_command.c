#include "holberton.h"
/**
 * read_command - read a line from stdin
 * @env: the argument passed
 * Description: first we print the command prompt
 * then we read the command from standar input
 * Return: a pointer contaning the string passed to the CLI
 */
char *read_command(char **env)
{
	char *string = NULL;
	size_t bufsize = 0;
	char **args = NULL;
	ssize_t read;
	int status, i;

	if (signal(SIGINT, sighandler) == SIG_ERR)
		perror("Error: \n");
	while (1 == 1)
	{
		if (isatty(STDIN_FILENO) == 1)
			simple_print_shell("shell$ ");

		read = getline(&string, &bufsize, stdin);
		if (read == EOF)
		{
			free(string);
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		if (string[0] == '/')
			return (string);
		rm_new_line(string);
		args = _parser(string);
		built_in(string, args, env);
		status = _path(args[0], args, env);
	}
	return (0);
}

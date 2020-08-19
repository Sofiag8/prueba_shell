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

	static int count;

	if (signal(SIGINT, sighandler) == SIG_ERR)
		perror("Error: \n");
	while (1 == 1)
	{
		if (isatty(STDIN_FILENO) == 1)
			simple_print_shell("shell$ ");

		read = getline(&string, &bufsize, stdin);
		++count;
		if (read == EOF)
		{
			free(string);
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		rm_new_line(string);
		args = _parser(string);
		built_in(string, args, env);
		 _path(args[0], args, env);
		forkwaitexec(args, &count);
		fflush(stdin);
	}
	free(string);
	return (0);
}

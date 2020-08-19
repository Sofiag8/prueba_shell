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
<<<<<<< HEAD
	int i;
	static int count;
||||||| merged common ancestors
	int status, i;
=======
	int status = 0;
>>>>>>> 5c7504ce06207ba24254043b2d5129046c9cca31

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
<<<<<<< HEAD

||||||| merged common ancestors
		if (string[0] == '/')
			return (string);
=======
		if (string[0] == '/')
		{
			return (string);
		}
>>>>>>> 5c7504ce06207ba24254043b2d5129046c9cca31
		rm_new_line(string);
		args = _parser(string);
		built_in(string, args, env);
<<<<<<< HEAD
		 _path(args[0], args, env);
		 printf("count: %d", count);
		forkwaitexec(args, &count);
		fflush(stdin);
||||||| merged common ancestors
		status = _path(args[0], args, env);
=======
		status = _path(args[0], args, env);
		fflush(stdin);
>>>>>>> 5c7504ce06207ba24254043b2d5129046c9cca31
	}
	free(string);
	return (0);
}

#include "holberton.h"
/**
 * read_command - read a line from stdin
 * Description: first we print the command prompt
 * then we read the command from standar input
 * Return: a pointer contaning the string passed to the CLI
 */
char *read_command(char **env)
{
	char *string = NULL;
	/* have getline allocate a buffer for us */
 	size_t bufsize = 0;
	char **args = NULL;
	ssize_t read;
	int status, i;

	while (1 == 1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "shell$ ", 7);
		read = getline(&string, &bufsize, stdin);
		if (string[0] == '/')
			return (string);



		/**if (feof(stdin))
			{
				write(STDOUT_FILENO, "\n", 1);
				exit(EXIT_SUCCESS);
			}
		else
			{
				perror("Error:");
				exit(EXIT_FAILURE);
				}*/
		rm_new_line(string);
		args = _parser(string);
		built_in(string, args, env);
		status = _path(args[0], args, env);
	}
	return (0);
}

void rm_new_line(char *string)
{
	int i = 0;

	while (string[i])
	{
		if (string[i] == '\n')
		{
			string[i] = '\0';
			return;
		}
		i++;
	}
}
/**
 * ctrl_D - ends our shell wwhen passed ctrl D by the user
 * @string: the string received
 * @bufsize: size of string in bytes
 * Return: 0 success 1 if failed
 */
int ctrl_D(char *string, size_t bufsize)
{
	int i;

	if (bufsize == EOF && isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(string);
		exit (0);
	}
	if (bufsize == EOF && isatty(STDIN_FILENO) == 0)
	{
		free(string);
		exit (0);
	}
	i = 0;
	while (string[i] != '\n')
	{
		if (string[i] != ' ' && string[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}
/**
 * split_command - tokenize the received line
 * @string: pointer to the received string in getline
 * Return: the string tokenized
 */
char **split_command(char *string)
{
	int bufsize = LSH_TOK_BUFSIZE;
	int position = 0;
	char **tokens;
	char *token;

	tokens = malloc(bufsize * sizeof(char *));
	if (!tokens)
	{
		write(STDERR_FILENO, ": allocation error\n", 20);
		exit(EXIT_FAILURE);
	}
	token = strtok(string, LSH_TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += LSH_TOK_BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char*));
			if (!tokens)
			{
				write(STDERR_FILENO, ": allocation error\n", 20);
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, LSH_TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}
/* int main(int argc, char *argv[], char *envp[]) */
int forkwaitexec(char *argv)
{
	pid_t shell_pid;
	int status;
	char *args[] = {argv, NULL};

	argv = strtok(argv, "\n");
	shell_pid = fork();
	if (shell_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (shell_pid == 0)
	{
		shell_pid = execve(args[0], args, NULL);
		write(STDERR_FILENO, ": command not found\n", 21);
		exit(EXIT_FAILURE);
	}
	else
		shell_pid = wait(&status);
	return (0);
}
int shell_loop(char **argv, char **env)
{
	char *args;
	int status, status1;
	char **line = NULL;

	do
	{
		args = read_command(env);
		status = forkwaitexec(args);
	}
	while (!status)
		;
	return (status);
}
/**
 * main - prints the environment
 *
 * Return: Always 0.
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
void print_string(char *string)
{
	int i, print;

	for (i = 0; string[i] != '\0'; i++)
		;
	print = write(STDOUT_FILENO, string, i);
	if (print == EOF)
		return;
}
/**
 *
 *
 */
int main(int argc, char **argv, char **env)
{
	(void)argc, (void)**argv;

	shell_loop(argv, env);
	/*printenv(env);*/
	return (EXIT_SUCCESS);
}

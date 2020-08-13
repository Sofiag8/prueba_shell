#include "holberton.h"
/**
 * read_command - read a line from stdin
 * Description: first we print the command prompt
 * then we read the command from standar input
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
/**
 * main - prints the environment
 *
 * Return: Always 0.
 *
char printenv(char **env)
{
        unsigned int i;

        i = 0;
        while (env[i] != NULL)
        {
                printf("%s\n", env[i]);
                i++;
        }
        return (0);
}
/**
 *
 *
 */
int main(int argc, char *argv[], char *env[])
{
	shell_loop(argv);
	/*printenv(env);*/
	return (EXIT_SUCCESS);
}

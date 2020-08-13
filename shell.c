#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
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
/* char *split_command(char *args)
{
	const char space[1] = " ";
	char *token;
	char *str;

	token = strtok(str,space);
	while (token != NULL)
		token = strtok(NULL, space);
	return (token);
	}*/
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
		write(STDOUT_FILENO, "./shell: command not found\n", 29);
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

	do{
		args = read_command();
		status = forkwaitexec(args);
	}
	while (!status)
		;
	return (status);
}
#include <stdio.h>
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
char printenv(int ac, char **av, char **env)
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
	printenv(argc, argv, env);
	return (EXIT_SUCCESS);
}

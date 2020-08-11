#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *read_command(void)
{
	char *string = NULL;
	size_t size = 1024;

	printf("#cisfun$ ");
	getline(&string, &size, stdin);
	return (string);
}
char *split_command(char *args)
{
	const char space[1] = " ";
	char *token;
	char *str;

	token = strtok(str,space);
	while (token != NULL)
		token = strtok(NULL, space);
	return (token);
}

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
		printf("Execute failure\n");
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
		/**
		 *args = split_command(token);
		 */
		status = forkwaitexec(args);
	}
	while (!status)
		;
	return (status);
}
int main(int argc, char *argv[])
{
	shell_loop(argv);
	return (EXIT_SUCCESS);
}

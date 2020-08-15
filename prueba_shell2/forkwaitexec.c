#include "holberton.h"
/**
 * forkwaitexec - processes, wait and execute what receives from CL
 * @argv: the string entered as command
 * Return: the execution and end
 */
int forkwaitexec(char **string, size_t *bufsize, int *args_counter)
{
	pid_t child_proccess;
	int status, exec = 0;
	char *token = NULL, *saved_token = NULL, *tmp_token = NULL;
	char **entered_commands;

	token = strtok(*string, "\n\t\r");
	if (!token)
	{
		if (env_or_exit(*string, token) == 1)
		{
			free(string);
			*string = NULL;
			*bufsize = 0;
			return (0);
		}
		tmp_token = token;
		/*saved_token = funcion que busca en el PATH y se le pasa la direccion de token */
	/* aquí va la busqueda de PATH*/
	child_proccess = fork();
	if (child_proccess == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child_proccess == 0)
	{
		/* aqui se debe ejecutar el proceso hijo creado */
		/*child_proccess = execve();*/
		write(STDERR_FILENO, "hsh:command not found\n", 23);
                exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			exec = WEXITSTATUS(status);
	}
}

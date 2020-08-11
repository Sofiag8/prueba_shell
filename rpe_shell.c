#include "holberton.h"

void rpe_shell(void)
{
	char *line;
	char **av;
	int status;

	do
	{
		printf("$ ");
		line = read_shell();
		av = div_line(line);
		status = exe(av);
	}
	while (status);
}

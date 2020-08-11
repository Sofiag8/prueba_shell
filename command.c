#include "holberton.h"

char *comm[] = {
	"/bin/ls",
	"exit"

};
int (*comm_func[])(char **) = {
	&hsh_ls,
	&hsh_exit
};
int hsh_ls(char **av)
{
	if (chdir(av[1]) != 0)
		perror("hsh");
	return (1);
}

int hsh_exit(char **av)
{
	return (0);
}

int num_builtins()
{
	return sizeof(comm) / sizeof(char *);
}

int exe(char **av)
{
	int i;

	if (av[0] == NULL)
		return (1);
	for (i = 0; i < num_builtins(); i++)
		if (strcmp(av[0], comm[i]) == 0)
			return (*comm_func[i])(av);
	return hsh_launch(av);
}

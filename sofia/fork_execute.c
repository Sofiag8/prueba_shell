#include "holberton.h"
/**
 * forkwaitexec - executes the commands passed
 * @argv: commands passed in CL
 * Return: 0 success otherwise 1
 */
void forkwaitexec(int status, char **args, int *count)
{
	if (status == 1)
	{
		if (access(args[0], X_OK) == 0)
			if (fork() == 0)
				execve(args[0], args, NULL);
			else
				wait(NULL);
		else if (access(args[0], F_OK) != 0)
		{
			print_string("sh: ");
			print_count(count);
			print_string(": ");
			perror(args[0]);
		}
		else if (access(args[0], F_OK) == 0 && access(args[0], X_OK) != 0)
		{
			print_string("sh: ");
			print_count(count);
			print_string(": ");
			perror(args[0]);
		}
	}
	free(args);
}

/**
 *
 */
void print_count(int *count)
{
	int cnt, len, i, n;
	unsigned int base = 1, max, a;

	n = *count;
	max = n;
	a = max;
	do{
		a /= 10;
		++len;
	}while (a != 0);
	cnt += len;
	for (i = 0; i < len - 1; i++)
		base *= 10;
	_putchar('0' + (max/base));
	if (len > 1)
	{
		for (i = 0; i < len - 2; i++)
		{
			base /= 10;
			a = max / base;
			_putchar('0' + a % 10);
		}
		_putchar('0' + (max % 10));
	}
}

int _putchar(char c)
{
	return (write(1, &c, 1));
}

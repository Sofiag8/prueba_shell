#include <stdio.h>
int maint(void)
{
	char argv;

	scanf("%s", &argv);
	printf("%s", argv);
	return (0);
}

ssize_t getline(char **lineptr, size_t *n, FILE *stream)

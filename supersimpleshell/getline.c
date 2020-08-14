#include <stdio.h>
/**
 * ssize_t getline(char **lineptr, size_t *n, FILE *stream);
 */
int main(void)
{
	char *string;
	size_t size = 1024;

	printf("$ ");
	getline(&string, &size, stdin);
	printf("%s", string);
	return (0);
}

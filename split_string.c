#include <string.h>
#include <stdio.h>
/*  ssize_t getline(char **lineptr, size_t *n, FILE *stream) */
void main (void)
{
	char *str;
	const char s[2] = " ";
	char *token;
	size_t size = 0;

	getline(&str, &size, stdin);
	/* get the first token */
	token = strtok(str, s);
	/* walk through other tokens */
	while (token != NULL)
	{
		printf( "%s", token);
		token = strtok(NULL, s);
		if (token != NULL)
			printf("\n");
	}
}

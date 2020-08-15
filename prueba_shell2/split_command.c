#include "holberton.h"
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
	int count = 0;

        while (string[position])
	{
		if (string[position] == ' ')
			count++;
		position++;
	}
	position = 0;
	tokens = malloc(count * sizeof(char *));
        if (!tokens)
        {
                write(STDERR_FILENO, ": allocation error\n", 20);
                exit(EXIT_FAILURE);
        }
        token = strtok(string, LSH_TOK_DELIM);
        while (token != NULL)
        {
		tokens[position] = strdup(token);
                position++;
                token = strtok(NULL, LSH_TOK_DELIM);
        }
        tokens[position] = NULL;
        return (tokens);
}

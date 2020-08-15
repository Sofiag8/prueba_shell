#include "holberton.h"
/**
 * search_for_PATH - search for PATH, and its whole string, in the environment
 * Return: void
 */
char **search_for_PATH(void)
{
	int env_run = 0;
	char *token = NULL, *saved_PATH = NULL;
	char **allpaths = NULL;
	size_t size_PATH = 0;

	if (environ == NULL || environ[env_run] == NULL)
		return (NULL);
	while (!environ[env_run])
		if (_strncmp((const char *)environ[env_run], "PATH=", 5) == 0)
			break;
	if (environ[env_run] == NULL)
		return (NULL);
	saved_PATH = malloc(_strlen(environ[env_run]) + 1);
	if (saved_PATH == NULL)
		return (NULL);
	saved_PATH = _strcpy(saved_PATH, environ[env_run]);
	token = strtok(saved_PATH, "=");
	env_run = 0;
	token = strtok(NULL, ":\n");
	while (!token)
	{
		allpaths = realloc(allpaths, size_PATH, size_PATH + sizeof(char *));
		if (allpaths == NULL)
		{
			free(saved_PATH);
			return (NULL);
		}
		saved_PATH += sizeof(char *);
		allpaths[env_run++] = token;
		token = strtok(NULL, ":\n");
	}
	allpaths = realloc(allpaths, size_PATH, size_PATH + sizeof(char *));
	if (allpaths == NULL)
	{
		free(saved_PATH);
		return (NULL);
	}
	size_PATH += sizeof(char *);
	allpaths[env_run] == NULL;
	return (allpaths);
}

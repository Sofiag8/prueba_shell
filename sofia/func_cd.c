#include "holberton.h"
/**
 * func_cd - function which is used to change the current working directory.
 * @string: line of arguments
 * @env: variable environment
 * Return: 0
 */
int func_cd(char **string, char **env)
{
	char *obj, *home, pwd[1024];

	home = _getenv("HOME", env);
	if (string[1])
	{
		if (string[1][0] == '~' && string[1][1] != '\0')
			obj = home;
		else if (string[1][0] == '-' && string[1][1])
			obj = _getenv("OLDPWD", env);
		else
			obj = string[1];
	}
	else
		obj = home;
	if (obj == home)
		chdir(obj);
	else if (access(obj, F_OK | R_OK) == 0)
		chdir(obj);
	else
		simple_print_shell("Could not find directory\n");
	setenv("OLDPWD", _getenv("PWD", env), 1);
	setenv("PWD", getcwd(pwd, sizeof(pwd)), 1);
	return (0);
}
/**
 * _getenv - get the address of directory
 * @string: line of arguments
 * @env: variable environment
 * Return: NULL
 */
char *_getenv(char *string, char **env)
{
	int i, j, count, len;
	char *tmp;

	if (string == NULL)
		return (NULL);
	for (i = 0; env[i] != NULL; i++)
		;
	for (i = 0; env[i]; i++)
	{
		for (count = 0; env[i][count] != '='; count++)
			;
		count++;
		tmp = malloc(count * sizeof(char));
		len = count - 1;
		_memcpy(tmp, env[i], len);
		tmp[len - 1] = '\0';
		if (_strcmp(string, tmp), _strlen(tmp) == 0)
		{
			free(tmp);
			tmp = NULL;
			for (j = 0; env[i][j]; j++)
			{
				if (env[i][j] == '=')
				{
					tmp = &env[i][j + 1];
					break;
				}
			}
			return (tmp);
		}
		free(tmp);
		tmp = NULL;
	}
	return (NULL);
}

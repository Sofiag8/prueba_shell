#include <stdio.h>
#include <stdlib.h>
/**
 * _getenv - search the environment list to find
 * the enviroment varuable passed to the function through *name
 * Return: a pointer to the value in the environment
 * or NUll if there is no match
 */
char *_getenv(const char *name)
{
	char *stringvalue;

	for (; *name != '0'; name++)
	{
		if (name == stringvalue)
			return (stringvalue);
	}
	if (name == stringvalue)
		return (stringvalue);
}

int main(void)
{
	printf("PATH : %s\n", getenv("PATH"));
	return (0);
}

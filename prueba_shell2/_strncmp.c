#include "holberton.h"
/**
 * strncmp - compare bytes between strings
 * @s1: string 1
 * @s2: string 2
 * @sizebytes: bytes to compare
 * Return: 1 in equality or number of bytes
 */
int _strncmp(const char *s1, const char *s2, size_t size)
{
	size_t runner;

	while(runner < size && s1[runner] != '\0' && s2[runner] != '\0')
	{
		if (s1[runner] != s2[runner])
			return (s1[runner] - s2[runner]);
		runner++;
	}
	if (runner == size)
		return (0);
	if (s1[runner] != '\0' || s2[runner] != '\0')
		return (s1[runner] - s2[runner]);
	return (0);
}

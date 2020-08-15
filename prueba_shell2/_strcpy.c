/**
 * _strcpy - copy string from source to destination including
 * terminating null byte
 * @dest: destination for string to be copied
 * @src: string to be copied
 *
 * Return: pointer to destinationng
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (i <= _strlen(src))
	{
		dest[i] = src[i];
			i++;
	}
	return (dest);
}

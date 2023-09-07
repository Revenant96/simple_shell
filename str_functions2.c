#include "shell.h"

/**
 * _strcpy - function that copies string
 * @dest: pointer to destination string
 * @src: pointer to source string
 * Return: pointer to copied string
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (des == src || src == 0)
		return (dest);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - duplicates string
 * @str: string to duplicate
 * Return: duplicated string
 */

char *_strdup(const char *str)
{
	int i = 0;
	char *s;

	if (str == NULL)
		return (NULL);

	while (*str++)
		i++;

	s = malloc(sizeof(char) * (i + 1));

	if (!s)
		return (NULL);

	for (i++; i--;)
		s[i] = *--str;
	return (s);
}
/**
 * _putchar - function that prints char
 * @c: string to print
 * Return: 1 on success -1 on failure
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
	{
		buf[i++] = c;
	}
	return (1);
}

/**
 * _puts - function that puts string
 * @str: string to print
 * Return: Void
 */

void _puts(char *str)
{
	int i = 0;

	if (!str)
		return (NULL);

	while (str[i] != NULL)
	{
		_putchar(str[i]);
		i++;
	}
}


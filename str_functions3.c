#include "shell.h"

/**
 * _strncpy - fucntion to copy string
 * @dest: pointer to destination str
 * @src: pointer to source str
 * @n: number of characters to be copie
 * Return: Concated string
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0, j;
	char *s = dest;

	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 * _strncat - function that concates 2 strings
 * @dest: pointer to destination str
 * @src: pointer to source str
 * @n: number of characters to be copie
 * Return: Concated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;
	char *s = dest;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		j++;
		i++;
	}

	if (j < n)
		dest[i] = '\0';

	return (s);
}

/**
 * _strchr - function that locates a char in str
 * @s: pointer to string to be searched
 * @c: pointer to character to look for
 * Return: pointer to memory s
 */

char *_strchr(char *s, char c)
{
	while (*s++ != '\0')
		if (*s == c)
			return (s);
	return (NULL);
}

#include "shell.h"

/**
 * _strlen - function that finds str length
 * @s: pointer to string to check
 * Return: length of str
 */

int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - compares 2 strings
 * @s1: pointer to first string
 * @s2: pointer to second string
 *
 * Return: negative if s2 is bigger
 * psitive is s1 is bigger
 * zero if equal
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);

		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checks needle in a haystack
 * @haystack: string to search
 * @needle: string to find
 * Return: address of next char to haystack
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - contactes 2 strings
 * @dest: pointer to destination string
 * @src: pointer to source string
 * Return: Concated string
 */

char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = *src;
	return (s);
}

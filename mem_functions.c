#include "shell.h"

/**
 * _memset - function to fill memory
 * @s: pointer to memory area
 * @b: byte to fill memory with
 * @n: amount of bites to be filled
 * Return: pointer to fille memory
 */
char _memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * ffree - function to free memory
 * @pp: address to pointer to free
 * Return: Void
 */

void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - function to reallocate memory
 * @ptr: pointert to previous memory allocated
 * @old_size: old memory size
 * @new_size: new memory size
 * Return: Void
 */

void *_realloc(coid *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));

	if (!new_size)
		return (free(ptr), NILL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

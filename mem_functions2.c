#include "shell.h"

/**
 * bfree - frees pointer
 * @ptr: address to pointer to be freed
 * Return: 1 on success 0 on failure
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

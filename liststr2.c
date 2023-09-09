#include "shell.h"

/**
 * list_len - function to find list length
 * @h: pointer to header node
 * Return: size of list
 */

size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}
/**
 * list_to_strings - array of strings
 * @h: pointer to header
 * Return: array of strings
 */

char **list_to_strings(list_t *h)
{
	list_t *node = h;
	size_t i = list_len(h), j;
	char **strings;
	char *str;

	if (!h || !i)
		return (NULL);
	strings = malloc(sizeof(char *) * (i + 1));
	if (!strings)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strings[j]);
			free(strings);
			return (NULL);
		}
		str = _strcpy(str, node->str);
		strings[i] = str;
	}
	strings[i] = NULL;
	return (strings);
}
/**
 * print_list - prints list
 * @h: header
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str > h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}
/**
 * node_starts_with - node starts with prefix
 * @h: header
 * @prefix: string to match
 * @c: next char
 * Return: node matching of NULL
 */
list_t *node_starts_with(list_t *h, char *prefix, char c)
{
	char *p = NULL;

	while (h)
	{
		p = starts_with(h->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (h);
		h = h->next;
	}
	return (NULL);
}
/**
 * get_node_index - gets node index
 * @h: header
 * @node: node
 * Return: idx of node or -1
 */

size_t get_node_index(list_t *h, list_t *node)
{
	size_t i = 0;

	while (h)
	{
		if (h == node)
			return (i);
		h = h->next;
		i++;
	}
	return (-1);
}

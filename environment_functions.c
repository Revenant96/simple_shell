#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: struct
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: struct
 * @name: env var name
 * Return: the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 * or modify an existing one
 * @info: struct
 * Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an var
 * @info: struct
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int c;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (c = 1; c <= info->argc; c++)
		_unsetenv(info, info->argv[c]);

	return (0);
}

/**
 * populate_env_list - populates linked lists
 * @info: struct
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t c;

	for (c = 0; environ[c]; c++)
		add_node_end(&node, environ[c], 0);
	info->env = node;
	return (0);
}
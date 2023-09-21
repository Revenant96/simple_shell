#include "shell.h"
/**
 * _eputchar - prints c to stderr
 * @c: str to print
 * Return: 1 on success -1 on failure
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _eputs - prints an input string
 * @str: pointer tro string
 * Return: Void
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != NULL)
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _putfd - writes char to fd
 * @c: str to print
 * @fd: file descriptor
 * Return: 1 on success, -1 on failure
 */

int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
/**
 * _putsfd - prints str err
 * @str: string to print
 * @fd: file descriptor
 * Return: number of chars
 */

int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}

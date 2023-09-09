#include "shell.h"
/**
 * _erratoi - converts str to int
 * @s: string to convert
 * Return: 0 on failure, converted int on success
 * -1 on error
 */

int _erratoi(char *s)
{ int  i = 0;
	unsigned long int r = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] != NULL; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			r *= 10;
			r += (s[i] - '0');
			if (r > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (r);
}
/**
 * print_d - function that prints a float
 * @input: input
 * @fd: file descriptor
 * Return: number of chars printed
 */
int print_d(int input, int fd)
{ int (*__putchar)(char) = _putchar;
	int i, c = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		c++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i)'
				c++;
		}
		current %= i;
	}
	__putchar('0' + current);
	c++;
	return (c);
}
/**
 * print_error - prints an error msg
 * @info: paraemeter and return info struct
 * @estr: string concating error type
 * Return: 0 on failure, converted number on success
 * -1 on error
 */

void print_error(info_t *info, char *estr)
{
	_eputs(info->name);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->agrv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * convert_number - converts int to str
 * @num: int to conver
 * @base: represents int base
 * @flags: args flags
 * Return: str
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array, buffer[50];
	char sign = 0, *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = ' - ';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" :
		"0123456789ABCDEF"; ptr = &buffer[49]; *ptr = NULL;
	while (n != 0)
	{
		*--ptr = array[n % base];
		n /= base;
	}
	if (sign)
		*--ptr = sign;
	return (ptr);
}
/**
 * remove_comments - function to replace comment # with NULL
 * @buf: pointer to string to replace
 * Return: always 0
 */
void remove_comments(char *buf)
{
	int i;
	for (i = 0; buf[i] != NULL; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = NULL;
			break;
		}
}

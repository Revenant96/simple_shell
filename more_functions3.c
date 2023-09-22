#include "shell.h"

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
			__putchar('0' + current / i);
				c++;
		}
		current %= i;
	}
	__putchar('0' + current);
	c++;
	return (c);
}

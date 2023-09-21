#include "shell.h"
/**
* print_error - prints an error msg
* @info: paraemeter and return info struct
* @estr: string concating error type
* Return: 0 on failure, converted number on success-1 on error
*/
void print_error(info_t *info, char *estr)
{_eputs(info->name);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->agrv[0]);
	_eputs(": ");
	_eputs(estr); }
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
	{n = -num;
		sign = ' - '; }
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = NULL;
	while (n != 0)
	{*--ptr = array[n % base];
		n /= base; }
	if (sign)
		*--ptr = sign;
	return (ptr); }

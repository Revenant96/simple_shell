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
	return (r); }
/**
* remove_comments - function to replace comment # with NULL
* @buf: pointer to string to replace
* Return: always 0
*/
void remove_comments(char *buf)
{int i;
	for (i = 0; buf[i] != NULL; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = NULL;
			break; }}

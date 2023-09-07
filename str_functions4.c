#include "shell.h"

/**
 * _strtow - split str to words
 * ignores repeated delimiters
 * @str: pointer to string
 * @d: pointer to delimiter string
 * Return: pointer to array of strings on success
 * NULL on failure
 */

char **_strtow(char *str, char *d)
{
	int i, j, k, nwords = 0;
	char **s;

	if (str == NULL | str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != NULL; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			nwords++;
	if (nwords == 0)
		return (NULL);
	s = malloc(sizrof(char *) * (nwords + 1));

	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < nwords; j++)
	{
		while (is_delim(str[i], d))
			i++;
		k = 0;
		while (!is_delim(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc(sizeof(char) * (k + 1));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
		s[j] = NULL;
		return (s);
}
/**
 * _strtow2 - split str to words
 * @str: pointer to string
 * @d: the delimiter
 * Return: pointer to array of strings on success
 * NULL on failure
 */

char **_strtow2(char *str, char d)
{
	int i, j, k, m, nwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);

	for (i = 0; str[i] != NULL; i++)
		if ((str[i] != d && str[i + 1] == d) ||
				(str[i] != d && !str[i + 1]) || str[i + 1] == d)
			nowords++;
	if (nwords == 0)
		return (NULL);

	s = malloc(sizeof(char *) * (1 + nwords));
	if (!s)
		return (NULL);

	for (i = 0, j = 0; j < nwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc(sizeof(char) * (k + 1));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

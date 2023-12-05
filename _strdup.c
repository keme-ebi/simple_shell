#include "shell.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: string to duplicate
 *
 * Return: NULL if str = NULL, NULL if insufficient memory was available
 * otherwise, pointer to duplicate string
 */
char *_strdup(char *str)
{
	char *dup;
	int i, len = _strlen(str);

	if (!*str)
	{
		return (NULL);
	}
	dup = malloc(sizeof(char) * len);

	for (i = 0; i <= len; i++)
	{
		dup[i] = str[i];
	}

	return (dup);

}

#include "shell.h"

/**
 * set_arg - puts strings into an array to be used
 * @arg: array to append strings to
 * @src: source of string
 * @delim: delimeter
 */
void set_arg(char **arg, char *src, char *delim)
{
	char *new;
	int count;

	if (!src || !delim)
	{
		return;
	}

	new = strtok(src, delim);
	count = 0;
	while (new != NULL)
	{
		arg[count] = malloc(sizeof(char) * _strlen(new));
		arg[count] = _strdup(new);
		new = strtok(NULL, delim);
		count++;
	}
	arg[count] = NULL;
}

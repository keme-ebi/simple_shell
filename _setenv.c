#include "shell.h"

/**
 * _setenv - changes or adds an environment variable without using setenv
 * @name: name of the variable to search for
 * @value: value to set the variable to
 * @overwrite: indication/flag to overwrite
 *
 * Return: zero on success, or -1 on error
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	int len1 = _strlen(name), len2 = _strlen(value), i;
	char *env, *new;

	if (!name || len1 == 0 || len2 == 0 || _check(name) == -1)
	{
		return (-1);
	}

	if (overwrite)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			env = environ[i];
			if (!_strncmp(name, env, len1))
			{
				new = new_env(name, value, (len1 + len2 + 1));
				_strcpy(environ[i], new);
				free(new);
				return (0);
			}
		}
		new = new_env(name, value, (len1 + len2 + 2));
		environ[i] = new;
		environ[i + 1] = NULL;
		return (0);
	}
	return (-1);
}

/**
 * _strcat - concatenates two strings
 * @dest: string to concatenate to.
 * @src: string to append to dest.
 *
 * Return: pointer to dest.
 */
char *_strcat(char *dest, const char *src)
{
	int len = _strlen(dest);
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[len + i] = src[i];
	}
	dest[len + i] = src[i];

	return (dest);
}

/**
 * _strcpy - copies a string from a source to a destination
 * @dest: destination to copy string to
 * @src: string source
 *
 * Return: pointer to copied string
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _check - checks if a string contains "="
 * @str: string to check
 *
 * Return: 0 if no "=", else -1
 */
int _check(const char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '=')
		{
			return (-1);
		}
	}

	return (0);
}

/**
 * new_env - creates or replaces an environ variable
 * @name: name of the variable
 * @value: value of the variable
 * @length: length of the new environ variable
 *
 * Return: pointer to newly created environ variable
 */
char *new_env(const char *name, const char *value, int length)
{
	char *new;

	new = malloc(sizeof(char) * length);
	if (!new)
	{
		return (NULL);
	}
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);

	return (new);
}

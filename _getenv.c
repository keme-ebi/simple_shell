#include "shell.h"

/**
 * _getenv - gets an environment variable withot using getenv
 * @name: name of the variavble to get
 *
 * Return: pointer to the value of the variable, else NULL if it doesn't exist
 */
char *_getenv(const char *name)
{
	int i, len = _strlen(name);
	char *env;

	i = 0;
	while (environ[i])
	{
		env = environ[i];

		if (env[len] == '=' && (!_strncmp(name, env, len)))
		{
			return (env + len + 1);
		}
		i++;
	}

	return (NULL);
}

/**
 * _strncmp - compares two strings according to the number of n bytes
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to compare
 *
 * Return: 0 if both strings are the same, < 0 if s1 < s2, > 0 if s1 > s2
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int i = 0, j = 0;

	for (; j == 0 && i < n; i++)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
		{
			break;
		}
		j = s1[i] - s2[i];
	}
	return (j);
}

/**
 * _strlen - gets the length of a string
 * @s: string
 *
 * Return: length of the string
 */
int _strlen(const char *s)
{
	int i = 0, len = 0;

	for (; s[i] != '\0'; i++)
	{
		len++;
	}

	return (len);
}

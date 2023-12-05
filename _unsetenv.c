#include "shell.h"

/**
 * _unsetenv - deletes the variable name from the environment without
 * using unsetenv
 * @name: name of the variable to delete
 *
 * Return: zero on success, or -1 on error
 */
int _unsetenv(const char *name)
{
	int pos = _getpos(name);
	int i;

	if (pos != -1)
	{
		for (i = pos; environ[i] != NULL; i++)
		{
			environ[i] = environ[i + 1];
		}
		return (0);
	}

	return (-1);
}

/**
 * _getpos - gets the positon of a variable from the environ
 * @name: name of the variable
 *
 * Return: position of the variable
 */
int _getpos(const char *name)
{
	int i, len = _strlen(name), check = _check(name);
	char *env;

	if (!name || len == 0 || check == -1)
	{
		return (-1);
	}

	i = 0;
	while (environ[i])
	{
		env = environ[i];
		if (env[len] == '=' && (!_strncmp(name, env, len)))
		{
			return (i);
		}
		i++;
	}

	return (-1);
}

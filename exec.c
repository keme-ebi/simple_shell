#include "shell.h"

/**
 * exec - executes a command
 * @argv: array
 */
void exec(char **argv)
{
	if (argv)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("Error:");
		}
	}
}

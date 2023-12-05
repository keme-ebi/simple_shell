#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - first version of a simple shell that can run commands
 * with their full path without any argument
 *
 * Return: Always 0.
 */
int main(void)
{
	char *prompt = "$ ";
	char *line = NULL, *delim = " \n", *line_cpy, **argv;
	size_t len = 0;
	/*pid_t child_pid;
	int status, read;*/
	int read;

	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		read = getline(&line, &len, stdin);
		line_cpy = malloc(sizeof(char) * len);
		argv = malloc(sizeof(char *) * len);

		if (read == -1)
		{
			perror("Error:");
			return (1);
		}

		/*child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}*/
		/*if (child_pid == 0)
		{*/
		_strcpy(line_cpy, line);
		set_arg(argv, line_cpy, delim);

		exec(argv);
		/*	sleep(2);
		}
		else
		{
			wait(&status);
		}*/

		free_arr(argv);
		free(line_cpy);
		free(line);
	}
	return (0);
}

#include "shell.h"

/**
 * free_arr - frees an array
 * @arr: pointer to the array
 */
void free_arr(char **arr)
{
	int i;

	if (arr != NULL)
	{
		for (i = 0; arr[i] != NULL; i++)
		{
			free(arr[i]);
		}
		free(arr);
	}
}

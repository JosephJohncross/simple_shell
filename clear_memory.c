#include "shell.h"

/**
 * clear_memory - function that frees allocated memory
 * @buffer: The pointer allocated memory that will be freed
 *
 * Return: void (Nothing)
 */

void clear_memory(char **buffer)
{
	size_t j = 0;

	if (buffer == NULL)
		return;

	while (buffer[j] != NULL)
	{
		free(buffer[j]);
		j++;
	}

	free(buffer);
}

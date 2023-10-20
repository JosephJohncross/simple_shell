#include "shell.h"

/**
 * print_out_env - print environment variables and values
 *
 * Return: Nothing.
 */

void print_out_env(void)
{
	size_t i = 0;

	while (environment[i] != NULL)
	{
		write(STDOUT_FILENO, environment[i], _strlen(environment[i])); /* use _strlen() */
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
#include "shell.h"

/**
 * handle_error_message - prints error message
 * @tokens: array of strings storing the command and its
 * arguments
 * @full_path: the absolute path to the command executable
 * @shell: name of the shell program
 * @count: count of commands run in shell
 *
 * Return: Nothing.
 */

void handle_error_message(char **tokens, char *full_path, char *shell, size_t count)
{
	char count_char = count + '0';

	if (full_path == NULL)
	{
		write(STDOUT_FILENO, shell, _strlen(shell));
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, &count_char, 1);
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, tokens[0], _strlen(tokens[0]));
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, "not found\n", 10);
		free_memory(tokens);
	}
}
#include "shell.h"

/**
 * execute_cmd - executes the command (first string in tokens)
 * @tokens: array of strings that stores the commands
 * @shell: name of the shell
 * @absolute_path: the full path of command executable
 * @env: the environment variables of the process
 *
 * Return: Nothing.
 */

int execute_cmd(char **tokens, char *absolute_path, char *shell, char **env)
{
	struct stat file_status;

	if (stat(tokens[0], &file_status) == 0)
	{
		if (execve(tokens[0], tokens, env) == -1)
		{
			free_memory(tokens);
			perror(shell);

			return (2);
		}
	}
	else if (stat(absolute_path, &file_status) == 0)
	{
		if (execve(absolute_path, tokens, env) == -1)
		{
			free_memory(tokens);
			free(absolute_path);
			perror(shell);

			return (2);
		}
	}
	return (0);
}
#include "shell.h"

/**
 * main - entry point, runs the shell program
 * @argc: number of arguments passed to the program
 * @argv: array of strings holding the arguments passed
 * to program
 * @env: the environment variables of process
 *
 * Return: Nothing
 */

int main(int argc, char *argv[], char **env)
{
	char *buf = NULL, **tokens = NULL, *absolute_path = NULL, **path = NULL;
	size_t n = 0, count = 0;
	ssize_t no_bytes;
	int exit_status = 0;

	(void) argc;
	while (1)
	{
		size_t i = 0;

		signal(SIGINT, handle_signalling);
		prompt(), count++;
		no_bytes = getline(&buf, &n, stdin);
		if (no_bytes == EOF)
			_EOF(buf);
		tokens = _strtok(buf, " \n");
		if (tokens == NULL)
			continue;
		free(buf);
		if (_strcmp(tokens[0], "exit") == 0)
			exit_shell_environment(tokens, argv[0], count, exit_status);
		else if (_strcmp(tokens[0], "cd") == 0)
			changedir(tokens[1]), clear_memory(tokens);
		else if (_strcmp(tokens[0], "env") == 0)
			print_out_env(), clear_memory(tokens);
		else
		{
			path = get_path(env);
			do {
				absolute_path = get_full_cmd(path[i], tokens[0]);
				if (absolute_path)
					exit_status = fork_process(tokens, absolute_path, argv[0], env);
				i++;
			} while (path[i] != NULL && absolute_path == NULL);
			clear_memory(path);
			handle_error_message(tokens, absolute_path, argv[0], count);
		}
		buf = NULL;
	}
	return (2);
}
#include "shell.h"

/**
 * get_full_cmd - get the full path to the executable
 * @path: the directory to use in PATH environment variable
 * @command: the command to be run
 *
 * Return: the full path to the command executable
 */

char *get_full_cmd(char *path, char *command)
{
	char *full_path = NULL;

	full_path = malloc(_strlen(path) + _strlen(command) + 2);

	if (full_path != NULL)
	{
		_strcpy(full_path, path);
		_strcat(full_path, command);
		if (access(full_path, X_OK) == 0 || access(command, X_OK) == 0)
			return (full_path);
	}
	free(full_path);
	return (NULL);
}
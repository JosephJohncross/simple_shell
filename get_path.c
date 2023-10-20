#include "shell.h"

/**
 * get_path - get the paths to the command executables
 * @env: the environment variables
 *
 * Return: an array to the paths in PATH variable
 */

char **get_path(char **env)
{
	char **dir = NULL, *var = NULL, *val = NULL, *var_dup = NULL;
	size_t i = 0;

	var_dup = _strdup(env[i]);
	var = strtok(var_dup, "=");
	while (var_dup != NULL)
	{
		i++;
		if (strcmp(var, "PATH") == 0)
		{
			val = strtok(NULL, "\n");
			dir = _strtok(val, ":");
			free(var_dup);
			return (dir);
		}
		free(var_dup);
		var_dup = _strdup(env[i]);
		var = strtok(var_dup, "=");
	}
	return (NULL);
}
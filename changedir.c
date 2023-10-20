#include "shell.h"

/**
 * changedir - change the current directory
 * @path: the path to change to
 *
 * Return: 0 on success, errno value on failure
 */

int changedir(const char *path)
{
    char *cwd = NULL;
    size_t size = 0;

    if (path == NULL)
        path = getcwd(cwd, size);

    if (chdir(path) == -1)
    {
        perror(path);
        return (errno);
    }
    free(cwd);
    return (0);
}

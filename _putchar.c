#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: 1 (on Success)
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
    /* Write the character to stdout */ 
    int bytes_written = write(STDOUT_FILENO, &c, 1);

    /* Check if the write operation was successful */ 
    if (bytes_written == -1) {
        /* Return -1 and set errno appropriately */ 
        return -1;
    }

    /* Return 1 on success */ 
    return 1;
}
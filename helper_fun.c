#include "shell.h"


/**
 * _isdigit - function that checks if input is a number
 * @num: the input to check
 *
 * Return: 1 if num is a number, 0 otherwise
 */

int _isdigit(char *num)
{
    /* Check if the input is NULL*/ 
    if (num == NULL) {
        return (0);
    }

    /* Iterate over the input string */ 
    for (int i = 0; num[i] != '\0'; i++) {
        /* Check if the current character is a digit */ 
        if (num[i] < '0' || num[i] > '9') {
            return (0);
        }
    }

    /* If we reach here, the input is a number */ 
    return (1);
}

/**
 * _atoi - function that converts a string to an integer
 * @s: the string to convert
 *
 * Return: the resulting integer
 */

int _atoi(char *s)
{
    /* Check if the input is NULL */ 
    if (s == NULL) {
        return (0);
    }

    /*Initialize the sign and number variables */ 
    int sign = 1;
    unsigned int number = 0;

    /*Skip any leading whitespace*/ 
    while (*s == ' ') {
        s++;
    }

    /*Check for a negative sign*/ 
    if (*s == '-') {
        sign = -1;
        s++;
    }

    /*Iterate over the remaining string, converting each digit to an integer*/ 
    for (; *s != '\0'; s++) {
        char c = *s;
        if (c < '0' || c > '9') {
            break;
        }

        number *= 10;
        number += c - '0';
    }

    /*Return the converted number, multiplied by the sign*/ 
    return (number * sign);
}


/**
 * _EOF - function that handles "end of file" condition
 * @buf: the input
 *
 * Return: void (nothing)
 */
void _EOF(char *buf)
{
    /* Check if the input buffer is not NULL*/ 
    if (buf != NULL) {
        /*Free the input buffer*/ 
        free(buf);
        buf = NULL;
    }

    /*Check if the standard input is a terminal*/ 
    if (isatty(STDIN_FILENO)) {
        /*Write a newline character to standard output*/ 
        write(STDOUT_FILENO, "\n", 1);
    }

    /*Exit the program with success*/ 
    exit(EXIT_SUCCESS);
}


/**
 * exit_shell_environment - function that exits the shell
 * @args: pointer to tokenized command
 * @shell: the name of the shell program
 * @count: number of times commands are run in the shell
 * @exit_status: exit status
 *
 * Return: void (Nothing)
 */
void exit_shell_environment(char **args, char *shell, size_t count, int exit_status)
{
    /* Check if the exit status is specified */ 
    if (args[1] != NULL) {
        /* Check if the exit status is a valid number */ 
        if (_isdigit(args[1])) {
            /* Convert the exit status to an integer */ 
            int status = _atoi(args[1]);

            /* Check if the exit status is within the valid range */ 
            if (status >= 0 && status <= 255) {
                exit(status);
            } else {
                /* Print an error message and exit with a status of 2 */ 
                print_error_message(shell, count, args[0], "Illegal number", args[1]);
                exit(2);
            }
        } else {
            /* Print an error message and exit with a status of 2 */ 
            print_error_message(shell, count, args[0], "Illegal number", args[1]);
            exit(2);
        }
    }

    /* Exit with the specified exit status */ 
    exit(exit_status);
}
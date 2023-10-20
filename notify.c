#include "shell.h"

/**
 * prompt - print prompt to screen
 *
 * Return: Nothing
 */

void prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}

/**
 * handle_signalling - handle CTRL+C signal
 * @signum: signal that triggered the hanler
 *
 * Return: Nothing.
 */

void handle_signalling(int signum)
{
	(void) signum;
	write(STDOUT_FILENO, "\n", 1);
	prompt();
}
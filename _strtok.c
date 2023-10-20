#include "shell.h"

/**
 * _strtok - tokenizes a string and stores each token
 * in an array of strings
 * @str: string to tokenize
 * @delim: the delimeter by which strin is tokenized
 *
 * Return: array of strings storing tokens.
 */

char **_strtok(char *str, char *delim)
{
    static char *saved_str = NULL;
    char *token;

    /*If str is not NULL, initialize saved_str to str.*/ 
    if (str != NULL)
    {
        saved_str = str;
    }

    /* If saved_str is NULL, there are no more tokens to return. */ 
    if (saved_str == NULL)
    {
        return NULL;
    }

    /*Find the start of the token.*/ 
    while (*saved_str != '\0' && strchr(delim, *saved_str) != NULL)
    {
        saved_str++;
    }

    /*If saved_str is now NULL, there are no more tokens to return.*/ 
    if (*saved_str == '\0')
    {
        saved_str = NULL;
        return NULL;
    }

    /*Set token to the start of the token.*/ 
    token = saved_str;

    /*Find the end of the token.*/ 
    while (*saved_str != '\0' && strchr(delim, *saved_str) == NULL)
    {
        saved_str++;
    }

    /*If saved_str is not NULL, null-terminate the token and increment saved_str.*/ 
    if (*saved_str != '\0')
    {
        *saved_str = '\0';
        saved_str++;
    }

    /*Return a pointer to the token.*/ 
    return &token;
}
#ifndef MAIN_H
#define MAIN_H

#include <errno.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environment;

char **_strtok(char *str, char *delim);
int changedir(const char *path);

/* Forks a child process */
int fork_process(char **tokens, char *absolute_path,
                 char *shell, char **env);
void print_out_env(void);
void exit_shell_environment(char **args, char *shell, size_t count, int exit_status);

int _isdigit(char *num);
void _EOF(char *buf);
int _atoi(char *s);

/* error messages */
void handle_error_message(char **tokens, char *full_path, char *shell, size_t count);
int execute_cmd(char **tokens, char *absolute_path, char *shell, char **env);
char *get_full_cmd(char *path, char *command);
char **get_path(char **env);

/* clear memory after operation */
void clear_memory(char **buffer);

/* string methods */
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);

void prompt(void);
void handle_signalling(int signum);

#endif
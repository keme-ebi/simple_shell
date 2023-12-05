#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

/* functions for manipulation of the environ variables */
char *_getenv(const char *name); /* gets the value of a variable */
/* sets up a new variable or replaces the value of existing variable */
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name); /* removes or deletes a variable */
int _getpos(const char *name); /* gets the position of a variable */
/* checks if an environ variable name starts with or has the character '=' */
int _check(const char *str);
/* creates or replaces a new environ variable */
char *new_env(const char *name, const char *value, int length);

/* functions for string manipulation */
int _strlen(const char *s); /* gets the length of a string */
/* compares two strings to see if they contain same characters */
int _strncmp(const char *s1, const char *s2, int n);
/* copies a string fron src to dest */
char *_strcpy(char *dest, const char *src);
/* concatenates string to dest from src */
char *_strcat(char *dest, const char *src);
char *_strdup(char *str); /* points to a new string which is a duplicate of str */
void free_arr(char **arr); /* frees an array allocated with malloc */

void exec(char **argv); /* executes a command */
void set_arg(char **arg, char *src, char *delim);

#endif /* SHELL_H */

#ifndef HOLBERTON_H
#define HOLBERTON_H

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

/* shell basic process */
int shell_loop(char **argv);
char *read_command(void);
int forkwaitexec(char **string, size_t *bufsize, int *args_counter);
char **split_command(char *string);

/* environment and PATH*/
void environment(void);
char **search_for_PATH(void);

extern char **environ;

/* built in */
int env_or_exit(char *string, char *token);

/* global variable for env */
extern char **environ;


/* auxiliar functions by us */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t size);
char *_strcpy(char *dest, char *src);

#endif

#ifndef HOLBERTON_H
#define HOLBERTON_H

#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"

#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>

/* string manipulations functions */
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strncat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
void print_string(char *string);

/* shell basic process */
int main(int argc, char *argv[], char *env[]);
int shell_loop(char **argv, char **env);
char *read_command(char **env);
char **split_command(char *string);
int forkwaitexec(char *argv);
void rm_new_line(char *string);
int _path(char *args, char **argv, char **env);
char *print_path(char *der, char *args);
char **_parser(char *string);
void built_int(char *string, char **argv, char **env);
int printenv(char **env);

/* function signal */
void sighandler(int sig);
#endif

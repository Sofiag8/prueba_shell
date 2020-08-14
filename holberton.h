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
int main(int argc, char *argv[], char *env[]);
int shell_loop(char **argv);
char *read_command(void);
char **split_command(char *string);
int forkwaitexec(char *argv);

#endif

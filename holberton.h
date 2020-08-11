#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void rpe_shell(void);
char *read_shell(void);
char **div_line(char *line);
int hsh_launch(char **av);
int hsh_ls(char **av);
int hsh_exit(char **av);
int num_builtins();

#endif

/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** all prototypes.
*/

#ifndef MY_H
#define MY_H

#include "../Include/my.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct my_struct_s {
    int env_line;
    char **env;
    char **path;
} my_t;

void env_function(my_t *msh, char *line);
void exit_function(my_t *msh, char *line);
void setenv_function(my_t *msh, char *line);
char *no_back_slash_n(char *str);
char *my_getenv(char **env, char *str);
void unsetenv_function(my_t *msh, char *line);
char *anti_spaces(my_t *msh, char *line);
void cd_function(my_t *msh, char *line);
void path_function(my_t *msh, char *line);
void cd_errors(my_t *msh, char **setenv_tab);

#endif
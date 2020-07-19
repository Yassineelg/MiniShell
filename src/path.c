/*
** EPITECH PROJECT, 2020
** path.c
** File description:
** path
*/

#include "my.h"

void execve_errors(char **avv)
{
    if (errno == EACCES) {
        my_putstr(avv[0]);
        my_putstr(": Permission denied.\n");
    } if (errno == ENOENT) {
        my_putstr(avv[0]);
        my_putstr(": Command not found.\n");
    }
}

void path_execve(my_t *msh, char **setenv_tab, int valide, char *path_command)
{
    pid_t pid = 0;

    if (setenv_tab[0][0] == '.' || setenv_tab[0][0] == '/') {
        if ((fork()) == 0) {
            execve(setenv_tab[0], setenv_tab, msh->env);
            execve_errors(setenv_tab);
            exit(0);
        } else wait(&pid);
        return;
    } if (valide) {
        if ((fork()) == 0)
            execve(path_command, setenv_tab, msh->env);
        else wait(&pid);
    } else {
        write(2, setenv_tab[0], my_strlen(setenv_tab[0]));
        write(2, ": Command not found.\n", 22);
    }
}

void path_function(my_t *msh, char *line)
{
    char **setenv_tab = NULL;
    char *path_command = NULL;
    int tab_arguments = 0;
    int valide = 0;

    line = no_back_slash_n(line);
    if (line) setenv_tab = my_str_to_word_array(line, ' ');
    if (!my_getenv(msh->env, "PATH=")) {
        write(2, setenv_tab[0], my_strlen(setenv_tab[0]));
        write(2, ": Command not found.\n", 22);
        return;
    } msh->path = my_str_to_word_array(my_getenv(msh->env, "PATH="), ':');
    for (int i = 0; msh->path && msh->path[i]; i++) {
        path_command = my_strcat(msh->path[i], my_strcat("/", setenv_tab[0]));
        if (access(path_command , X_OK) == 0) {
            valide = 1;
            break;
        }
    } path_execve(msh, setenv_tab, valide, path_command);
}
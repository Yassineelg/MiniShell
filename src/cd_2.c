/*
** EPITECH PROJECT, 2020
** cd_2.c
** File description:
** cd_2
*/

#include "my.h"

void cd_errors(my_t *msh, char **setenv_tab)
{
    if (errno == ENOENT) {
        write(2, setenv_tab[1], my_strlen(setenv_tab[1]));
        write(2, ": No such file or directory.\n", 29);
    } if (errno == ENOTDIR) {
        write(2, setenv_tab[1], my_strlen(setenv_tab[1]));
        write(2, ": Not a directory.\n", 20);
    }
}
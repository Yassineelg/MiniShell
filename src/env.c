/*
** EPITECH PROJECT, 2020
** env.c
** File description:
** env
*/

#include "my.h"

void env_function(my_t *msh, char *line)
{
    char **env_tab = NULL;

    if (my_strcmp(line, "env\n")) {
        for (int i = 0; msh->env[i] && msh->env; i++)
            my_printf("%s\n", msh->env[i]);
    } else {
        env_tab = my_str_to_word_array(line, ' ');
        write(2, "env: '", 7);
        write(2, env_tab[1], my_strlen(env_tab[1]));
        write(2, "': No such file or directory\n", 30);
    }
}
/*
** EPITECH PROJECT, 2020
** setenv
** File description:
** setenv
*/

#include "my.h"

void setenv_already_exist(my_t *msh, char **setenv_tab)
{
    char *new_line = NULL;
    int line = 0;
    int tab_arguments = 0;

    for (; setenv_tab && setenv_tab[tab_arguments]; tab_arguments++);
    if (tab_arguments == 3)
        new_line = my_strcat(setenv_tab[1], my_strcat("=", setenv_tab[2]));
    if (tab_arguments == 2) new_line = my_strcat(setenv_tab[1], "=");
    for (; msh->env[line]; line++) {
        if (my_strncmp(msh->env[line], setenv_tab[1],
        my_strlen(setenv_tab[1]))) break;
    } msh->env[line] = malloc(sizeof(char) * my_strlen(new_line) - 1);
    for (int i = 0; new_line[i] && new_line; i++)
        if (new_line[i] != '\n') msh->env[line][i] = new_line[i];
}

void setenv_non_exist(my_t *msh, char **setenv_tab)
{
    char *new_line = NULL;
    char **temp_env = msh->env;
    int tab_arguments = 0;

    for (; setenv_tab && setenv_tab[tab_arguments]; tab_arguments++);
    if (tab_arguments == 3)
        new_line = my_strcat(setenv_tab[1], my_strcat("=", setenv_tab[2]));
    if (tab_arguments == 2) new_line = my_strcat(setenv_tab[1], "=");
    for (msh->env_line = 0; msh->env[msh->env_line]; msh->env_line++);
    msh->env_line += 1;
    msh->env = malloc(sizeof(char *) * (msh->env_line + 1));
    for (int i = 0; temp_env[i] && temp_env; i++)
        msh->env[i] = temp_env[i];
    msh->env[msh->env_line - 1] = malloc(sizeof(char) * my_strlen(new_line));
    for (int i = 0; new_line[i] && new_line; i++)
        if (new_line[i] != '\n') msh->env[msh->env_line - 1][i] = new_line[i];
    msh->env[msh->env_line] = NULL;
}

void setenv_function(my_t *msh, char *line)
{
    char **setenv_tab = NULL;
    int tab_arguments = 0;

    if (my_strcmp(line, "setenv\n") || my_strcmp(line, "setenv \n")) {
        env_function(msh, "env\n");
        return;
    } setenv_tab = my_str_to_word_array(line, ' ');
    for (; setenv_tab && setenv_tab[tab_arguments]; tab_arguments++);
    if (tab_arguments > 3) {
        write(2, "setenv: Too many arguments.\n", 29);
        return;
    } if (tab_arguments == 2) setenv_tab[1] = no_back_slash_n(setenv_tab[1]);
    if (my_getenv(msh->env, my_strcat(setenv_tab[1], "="))) {
        setenv_already_exist(msh, setenv_tab);
    } else setenv_non_exist(msh, setenv_tab);
}
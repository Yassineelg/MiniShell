/*
** EPITECH PROJECT, 2020
** unsetenv
** File description:
** unsetenv
*/

#include "my.h"

void unsetenv_delete_stuff(my_t* msh, int line)
{
    char **temp_env = NULL;

    for (msh->env_line = 0; msh->env[msh->env_line]; msh->env_line++);
    msh->env_line -= 1;
    temp_env = malloc(sizeof(char *) * (msh->env_line + 1));
    for (int y = 0, j = 0; msh->env && msh->env[y]; y++) {
        if (y != line) {
            temp_env[j] = msh->env[y];
            j++;
        }
    } temp_env[msh->env_line] = NULL;
    msh->env = temp_env;
}

void unsetenv_no_few_arg(my_t* msh, char **setenv_tab, int i)
{
    int deleting = 0;
    int line = 0;

    for (; msh->env && msh->env[line]; line++) {
        if (my_strncmp(msh->env[line], my_strcat(setenv_tab[i], "="),
        my_strlen(my_strcat(setenv_tab[i], "=")))) {
            deleting = 1;
            break;
        }
    } if (deleting == 1) unsetenv_delete_stuff(msh, line);
}

void unsetenv_function(my_t *msh, char *line)
{
    char **setenv_tab = NULL;
    int tab_arguments = 0;

    setenv_tab = my_str_to_word_array(line, ' ');
    for (; setenv_tab && setenv_tab[tab_arguments]; tab_arguments++);
    if (tab_arguments == 1) {
        write(2, "unsetenv: Too few arguments.\n", 30);
        return;
    } setenv_tab[tab_arguments - 1] = no_back_slash_n(setenv_tab[tab_arguments
    - 1]);
    for (int i = 0; setenv_tab && setenv_tab[i]; i++) {
        unsetenv_no_few_arg(msh, setenv_tab, i);
    }
}
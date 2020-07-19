/*
** EPITECH PROJECT, 2020
** cd
** File description:
** cd
*/

#include "my.h"

void reset_env(my_t *msh, char *new_pwd, char *new_old_pwd)
{
    int mark = 0;

    if (!new_pwd || !new_old_pwd) return;
    for (mark = 0; msh->env[mark]; mark++) {
        if (my_strncmp(msh->env[mark], "PWD=", 4))
            msh->env[mark] = new_pwd;
    } for (mark = 0; msh->env[mark]; mark++)
        if (my_strncmp(msh->env[mark], "OLDPWD=", 7))
            msh->env[mark] = new_old_pwd;
}

void cd_minus(my_t *msh, char *new_pwd, char *new_old_pwd)
{
    if (chdir(my_getenv(msh->env, "OLDPWD=")) == -1 &&
    my_getenv(msh->env, "OLDPWD=")) {
        if (errno == ENOENT) {
            write(2, my_getenv(msh->env, "OLDPWD="),
            my_strlen(my_getenv(msh->env, "OLDPWD=")));
            write(2, ": No such file or directory.\n", 29);
        } if (errno == ENOTDIR) {
            write(2, my_getenv(msh->env, "OLDPWD="),
            my_strlen(my_getenv(msh->env, "OLDPWD=")));
            write(2, ": Not a directory.\n", 20);
        } return;
    } new_pwd = my_strcat("PWD=", my_getenv(msh->env, "OLDPWD="));
    reset_env(msh, new_pwd, new_old_pwd);
}

void cd_two_arg(my_t *msh, char **setenv_tab, char *line)
{
    char *new_old_pwd = NULL;
    char *name_dir = NULL;
    char *new_pwd = NULL;
    int mark = 0;

    if (my_getenv(msh->env, "PWD="))
        new_old_pwd = my_strcat("OLDPWD=", my_getenv(msh->env, "PWD="));
    setenv_tab[1] = no_back_slash_n(setenv_tab[1]);
    if (my_strcmp("-", setenv_tab[1])) {
        cd_minus(msh, new_pwd, new_old_pwd);
        return;
    } else {
        if (chdir(setenv_tab[1]) == -1 && setenv_tab[1]) {
            cd_errors(msh, setenv_tab);
            return;
        } new_pwd = my_strcat("PWD=", getcwd(NULL, 500));
        reset_env(msh, new_pwd, new_old_pwd);
    }
}

void cd_one_arg(my_t *msh, char *line)
{
    int mark = 0;
    char *new_pwd = my_strcat("PWD=", my_getenv(msh->env, "HOME="));
    char *new_old_pwd = my_strcat("OLDPWD=", my_getenv(msh->env, "PWD="));

    chdir(my_getenv(msh->env, "HOME="));
    if (chdir(my_getenv(msh->env, "HOME=")) == -1 &&
    my_getenv(msh->env, "HOME=")) {
        if (errno == ENOENT) {
            write(2, my_getenv(msh->env, "HOME="),
            my_strlen(my_getenv(msh->env, "HOME=")));
            write(2, ": No such file or directory.\n", 29);
        } if (errno == ENOTDIR) {
            write(2, my_getenv(msh->env, "HOME="),
            my_strlen(my_getenv(msh->env, "HOME=")));
            write(2, ": Not a directory.\n", 20);
        } return;
    } reset_env(msh, new_pwd, new_old_pwd);
}

void cd_function(my_t *msh, char *line)
{
    char **setenv_tab = NULL;
    char *new_pwd = NULL;
    char *new_old_pwd = NULL;
    int tab_arguments = 0;

    if (my_getenv(msh->env, "HOME="))
        new_old_pwd = my_getenv(msh->env, "HOME=");
    setenv_tab = my_str_to_word_array(line, ' ');
    for (; setenv_tab && setenv_tab[tab_arguments]; tab_arguments++);
    if (tab_arguments == 1) {
        cd_one_arg(msh, line);
    } else if (tab_arguments == 2) {
        cd_two_arg(msh, setenv_tab, line);
    } else write(2, "cd: Too many arguments.\n", 24);
}
/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "my.h"

char *set_actual_dir(my_t *msh, char *actual_dir)
{
    actual_dir = malloc(sizeof(char) *
    my_strlen(my_getenv(msh->env, "PWD=")));
}

void prompt_function(my_t *msh)
{
    int pwd_len = 0;
    char *actual_dir = NULL;
    char *actual_pwd = NULL;

    if (my_getenv(msh->env, "PWD=") && my_getenv(msh->env, "HOME=") &&
    !my_strcmp(my_getenv(msh->env, "PWD="), my_getenv(msh->env, "HOME=")) &&
    my_getenv(msh->env, "NAME=")) {
        actual_dir = set_actual_dir(msh, actual_dir);
        actual_pwd = my_getenv(msh->env, "PWD=");
        for (; actual_pwd && actual_pwd[pwd_len]; pwd_len++);
        for (; pwd_len != 0 && actual_pwd[pwd_len] != '/'; pwd_len--);
        for (int i = 0; actual_pwd && actual_pwd[pwd_len]; i++, pwd_len++) {
            actual_dir[i] = actual_pwd[pwd_len];
            if (actual_pwd[pwd_len + 1] == '\0') actual_dir[i + 1] = '\0';
        } my_printf("%s:~%s> ", my_getenv(msh->env, "NAME="), actual_dir);
    } else if (my_getenv(msh->env, "PWD=") && my_getenv(msh->env, "HOME=") &&
    my_strcmp(my_getenv(msh->env, "PWD="), my_getenv(msh->env, "HOME=")) &&
    my_getenv(msh->env, "NAME=")) {
        my_printf("%s:~> ", my_getenv(msh->env, "NAME="));
    } else my_printf("%s: ", getcwd(NULL, 500));
}

int main_3(my_t *msh, char *line, int path)
{
    if (my_strncmp("cd", line, 2) &&
    (line[2] == ' ' || line[2] == '\n')) {
        path = 0;
        cd_function(msh, line);
    } return (path);
}

int main_2(my_t *msh, char *line, int path)
{
    if (my_strncmp("env", line, 3) &&
    (line[3] == ' ' || line[3] == '\n')) {
        path = 0;
        env_function(msh, line);
    } if (my_strncmp("setenv", line, 6) &&
    (line[6] == ' ' || line[6] == '\n')) {
        path = 0;
        setenv_function(msh, line);
    } if (my_strncmp("unsetenv", line, 8) &&
    (line[8] == ' ' || line[8] == '\n')) {
        path = 0;
        unsetenv_function(msh, line);
    } if (my_strncmp("exit", line, 4) &&
    (line[4] == ' ' || line[4] == '\n')) {
        path = 0;
        exit_function(msh, line);
    } path = main_3(msh, line, path);
    return (path);
}

int main(int ac, char **av, char **env)
{
    my_t *msh = malloc(sizeof(my_t));
    char *line = NULL;
    ssize_t read = 0;
    size_t len = 0;
    int path = 1;

    msh->env = my_tabcpy(msh->env, env);
    while (1) {
        path = 1;
        prompt_function(msh);
        read = getline(&line, &len, stdin);
        if (read == -1) {
            my_putstr("exit\n");
            return (0);
        } line = anti_spaces(msh, line);
        path = main_2(msh, line, path);
        if (path) {
            path_function(msh, line);
        }
    } return (0);
}
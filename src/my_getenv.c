/*
** EPITECH PROJECT, 2020
** my_getenv.c
** File description:
** my_getenv
*/

#include "my.h"

char *my_getenv(char **env, char *str)
{
    char *str2 = NULL;

    for (int y = 0; env != NULL && env[y]; y++)
        if (my_strncmp(env[y], str, my_strlen(str))) {
            str2 = malloc(sizeof(char) * my_strlen(env[y]));
            str2 = env[y] + my_strlen(str);
        }
    return (str2);
}
/*
** EPITECH PROJECT, 2020
** tool_box.c
** File description:
** tool_box
*/

#include "my.h"

char *no_back_slash_n(char *str)
{
    char *str2 = str;
    int nb_b_s_n = 0;

    for (int i = 0; str && str[i]; i++) {
        if (str[i] == '\n') nb_b_s_n++;
    } str = malloc(sizeof(char) * my_strlen(str2) - nb_b_s_n);
    for (int i = 0; str2 && str2[i]; i++) {
        if (str2[i] != '\n') str[i] = str2[i];
    } return (str);
}
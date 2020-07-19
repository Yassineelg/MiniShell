/*
** EPITECH PROJECT, 2020
** my_str_to_word_array.c
** File description:
** my_str_to_word_array
*/

#include <stdio.h>
#include <stdlib.h>

char **my_str_to_word_array(char *str, char c)
{
    int space = 0;
    char **command = NULL;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c) space++;
    command = malloc(sizeof(char *) * space + 1);
    for (int j = 0, i = 0; j <= space; j++, i++) {
        for (; str[i] != '\0' && str[i] != c; i++);
        command[j] = malloc(sizeof(char) * i);
    } for (int i = 0, j = 0, x = 0; i <= space; i++, x++) {
        for (j = 0; str[x] != c && str[x] != '\0'; j++, x++)
            command[i][j] = str[x];
        command[i][j] = '\0';
    } command[space + 1] = NULL;
    return (command);
}
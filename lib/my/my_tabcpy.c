/*
** EPITECH PROJECT, 2020
** my_tabcpy.c
** File description:
** my_tabcpy
*/

#include <stdlib.h>
#include "../../Include/my.h"

char **my_tabcpy(char **dest, char **src)
{
    int lines = 0;
    int columns = 0;

    for (int y = 0, x = 0; src && src[y]; y++) {
        lines++;
    } dest = malloc(sizeof(char *) * (lines + 1));
    for (int y = 0, x = 0; src && src[y]; y++, x++) {
        for (x = 0, columns = 0; src[y][x]; x++) columns++;
        dest[y] = malloc(sizeof(char) * (columns + 1));
    } for (int y = 0, x = 0; src && src[y]; y++, x++) {
        for (x = 0; src[y][x]; x++) dest[y][x] = src[y][x];
    } return (dest);
}
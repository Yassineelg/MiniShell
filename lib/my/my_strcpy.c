/*
** EPITECH PROJECT, 2019
** my_strcpy.c
** File description:
** Copies a string into another
*/

#include <stdlib.h>
#include "../../Include/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    dest = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)));
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
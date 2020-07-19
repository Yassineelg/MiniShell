/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** concatenates two strings
*/

#include <stdlib.h>

int my_strlen(char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int compt = 0;
    char *dest_tmp = dest;

    dest = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)));
    for (int i = 0; dest_tmp[i] != '\0'; i++) dest[i] = dest_tmp[i];
    while (dest[compt] != '\0')
        compt++;
    while (src[i] != '\0') {
        dest[compt + i] = src[i];
        i++;
    }
    dest[compt + i] = '\0';
    return (dest);
}

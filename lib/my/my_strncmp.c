/*
** EPITECH PROJECT, 2020
** my_strncmp.c
** File description:
** my_strncmp
*/

int my_strncmp(char *str1, char *str2, int nb)
{
    int i = 0;

    for (; str1[i] == str2[i] && str1[i] && str2[i] && i < nb; i++);
    if (i == nb)
        return (1);
    else
        return (0);
}
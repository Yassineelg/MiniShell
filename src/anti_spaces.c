/*
** EPITECH PROJECT, 2020
** anti_sapces.c
** File description:
** anti_spaces
*/

#include "my.h"

int just_for_norme(char *line, int i)
{
    for (; line[i] == ' ' || line[i] == '\t'; i++);
    return (i);
}

char *anti_spaces(my_t *msh, char *line)
{
    int f_spaces = 0;
    char *tmp_line = malloc(sizeof(char) * my_strlen(line));

    for (; line && line[f_spaces] &&
    (line[f_spaces] == ' ' || line[f_spaces] == '\t'); f_spaces++);
    for (int i = f_spaces, j = 0; line[i] && line; i++, j++) {
        if (line[i] == ' ' || line[i] == '\t') {
            i = just_for_norme(line, i);
            tmp_line[j] = ' ';
            j++;
        } if (line[i] != ' ') tmp_line[j] = line[i];
        if (line[i] == '\n' && !line[i + 1] && tmp_line[j - 1] == ' ') {
            tmp_line[j - 1] = '\n';
            tmp_line[j] = '\0';
            break;
        }
    } line = tmp_line;
    return (line);
}
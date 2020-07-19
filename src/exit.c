/*
** EPITECH PROJECT, 2020
** exit
** File description:
** exit
*/

#include "my.h"

void exit_2_arg(my_t *msh, char **setenv_tab, char *line)
{
    int alphabetic_char = 0;
    int first_letter_nb = 0;

    setenv_tab[1] = no_back_slash_n(setenv_tab[1]);
    if (setenv_tab[1][0] <= '9' && setenv_tab[1][0] >= '0')
        first_letter_nb = 1;
    for (int i = 0; setenv_tab && setenv_tab[1][i]; i++) {
        if (setenv_tab[1][i] > '9' || setenv_tab[1][i] < '0')
            alphabetic_char = 1;
    } if (first_letter_nb && alphabetic_char)
        write(2, "exit: Badly formed number.\n", 27);
    else if (!first_letter_nb && alphabetic_char)
        write(2, "exit: Expression Syntax.\n", 26);
    if (first_letter_nb && !alphabetic_char) {
        my_putstr("exit\n");
        exit(my_getnbr(setenv_tab[1]));
    }
}

void exit_other_case(my_t *msh, char **setenv_tab, char *line)
{
    int alphabetic_char = 0;
    int first_letter_nb = 0;

    setenv_tab[1] = no_back_slash_n(setenv_tab[1]);
    if (setenv_tab[1][0] <= '9' && setenv_tab[1][0] >= '0')
        first_letter_nb = 1;
    for (int i = 0; setenv_tab && setenv_tab[1][i]; i++) {
        if (setenv_tab[1][i] > '9' || setenv_tab[1][i] < '0')
            alphabetic_char = 1;
    } if (first_letter_nb && alphabetic_char)
        write(2, "exit: Badly formed number.\n", 27);
    else write(2, "exit: Expression Syntax.\n", 26);
}

void exit_function(my_t *msh, char *line)
{
    char **setenv_tab = my_str_to_word_array(line, ' ');
    int tab_arguments = 0;

    for (; setenv_tab && setenv_tab[tab_arguments]; tab_arguments++);
    if (tab_arguments == 1) {
        my_putstr("exit\n");
        exit(0);
    } else if (tab_arguments == 2) {
        exit_2_arg(msh, setenv_tab, line);
    } else exit_other_case(msh, setenv_tab, line);
}
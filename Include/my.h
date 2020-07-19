/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** all prototypes.
*/

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int flag_searcher(char *flags, char c);
void my_printf(char *str, ...);
int my_getnbr(char const *str);
void my_put_nbr(int nb);
void my_putchar(char c);
void my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strncpy(char *dest, char const *src, int n);
void my_swap(int *a, int *b);
void get_modulo_s(va_list *list, char *str, int *i);
void get_modulo_c(va_list *list, char *str, int *i);
void get_modulo_d(va_list *list, char *str, int *i);
void get_modulo_o(va_list *list, char *str, int *i);
void get_modulo_x(va_list *list, char *str, int *i);
void get_modulo_u(va_list *list, char *str, int *i);
void get_modulo_p(va_list *list, char *str, int *i);
void get_modulo_n(va_list *list, char *str, int *i);
void get_modulo_b(va_list *list, char *str, int *i);
void get_modulo_gs(va_list *list, char *str, int *i);
void get_modulo_gx(va_list *list, char *str, int *i);
void get_modulo_modulo(va_list *list, char *str, int *i);
void no_flag(va_list *list, char *str, int *i);
void convert_dec_hex(unsigned int nb);
void convert_dec_oct(unsigned int nb);
void convert_dec_octs(unsigned int nb);
void my_put_unsignedint(unsigned int nb);
int my_strcmp(char *str1, char *str2);
int my_strncmp(char *str1, char *str2, int nb);
char **my_str_to_word_array(char *str, char c);
char **my_tabcpy(char **dest, char **src);


/*
** EPITECH PROJECT, 2023
** lib
** File description:
** destroy_my_str_to_word_array.c
*/

#include "../../include/my.h"

void destroy_my_str_to_word_array(char **str)
{
    for (int i = 0; str[i] != NULL; i++)
        free(str[i]);
    free(str);
}

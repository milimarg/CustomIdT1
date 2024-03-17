/*
** EPITECH PROJECT, 2022
** CPOOL_CWorkshopLib
** File description:
** my_str_to_word_array.c
*/

#include <stdlib.h>
#include "../../include/my.h"

static int *count_words_len(char const *str, int words_nb)
{
    int i = 0;
    int k = 0;
    int next_index = 0;
    int *full_len = (int *)malloc(sizeof(int) * words_nb);

    while (str[i] != '\0') {
        if (my_char_isvisible(str[i]) && !my_char_isvisible(str[i + 1])) {
            full_len[k] = i - next_index + 1;
            next_index = i + 2;
            k++;
        }
        i++;
    }
    return (full_len);
}

static char *word_saver(int i, int j, const char *str, int current_word_len)
{
    int k = 0;
    char *word = (char *)malloc(sizeof(char) * (current_word_len + 1));

    while (j <= i) {
        word[k] = (my_char_isvisible(str[j])) ? str[j] : '\0';
        k += (my_char_isvisible(str[j]));
        j++;
    }
    word[k] = '\0';
    return (word);
}

static char **divide_array(char const *str, int words_nb)
{
    char **result = (char **)malloc(sizeof(char *) * (words_nb + 1));
    char *word = NULL;
    int *words_len = count_words_len(str, words_nb);
    int current_word_len = 0;
    int j = 0;
    int l = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_char_isvisible(str[i]) && !my_char_isvisible(str[i + 1])) {
            current_word_len = words_len[l];
            word = word_saver(i, j, str, current_word_len);
            j = i + 2;
            result[l++] = word;
        }
    }
    result[l] = NULL;
    free(words_len);
    return (result);
}

char **my_str_to_word_array(char const *str)
{
    int words_nb = 0;
    char **result;

    for (int i = 0; str[i] != '\0'; i++)
        if (my_char_isvisible(str[i]) && !my_char_isvisible(str[i + 1]))
            words_nb++;
    result = divide_array(str, words_nb);
    return (result);
}

void destroy_my_str_to_word_array(char **str)
{
    for (int i = 0; str[i] != NULL; i++)
        free(str[i]);
    free(str);
}

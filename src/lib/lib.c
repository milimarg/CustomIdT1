/*
** EPITECH PROJECT, 2023
** doom
** File description:
** lib.c
*/

#include <unistd.h>

void my_put_nbr_fd(int nb, unsigned int fd)
{
    char c = 0;

    if (nb == 0) {
        write(fd, "0", 1);
        return;
    }
    if (nb < 0) {
        write(fd, "-", 1);
        nb *= -1;
    }
    if (nb > 9)
        my_put_nbr_fd(nb / 10, fd);
    c = nb % 10 + '0';
    write(fd, &c, 1);
}

void my_extra_int_memset(int *s, int c, size_t n)
{
    for (int i = 0; i < n; i++)
        s[i] = c;
}

void my_swap(int *a, int *b)
{
    int c = 0;

    c = *a;
    *a = *b;
    *b = c;
}

int my_array_len(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return (i);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    int nb = 0;

    while (str[i] == '-' || str[i] == '+')
        neg *= (str[i++] == '-') ? (-1) : 1;
    for (; str[i] >= '0' && str[i] <= '9'; i++)
        nb = (nb * 10) + (str[i] - '0');
    return (nb * neg);
}

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

int my_array_len(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return (i);
}

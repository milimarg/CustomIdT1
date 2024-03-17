/*
** EPITECH PROJECT, 2023
** prototype-raycasting-and-doom_old
** File description:
** lib.h
*/
#ifndef LIB_H_
    #define LIB_H_
void my_put_nbr_fd(int nb, unsigned int fd);
char **my_str_to_word_array(char const *str);
int fix_angle(int angle);
int calc_dist(int x1,int y1, int x2,int y2);
int my_array_len(char **array);
void sort_sectors(my_idt1 &world);
#endif /*LIB_H_*/

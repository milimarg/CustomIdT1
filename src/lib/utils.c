/*
** EPITECH PROJECT, 2023
** doom
** File description:
** utils.c
*/

#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "../../include/my.h"

int fix_angle(int angle)
{
    angle += (angle < 0) ? 360 : 0;
    angle -= (angle > 359) ? 360 : 0;
    return (angle);
}

int calc_dist(int x1, int y1, int x2,int y2)
{
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

static void my_swap_sectors_condition(sectors_t *sector_a, sectors_t *sector_b)
{
    sectors_t temp = {0};

    if (sector_a->d < sector_b->d) {
        temp = *sector_a;
        *sector_a = *sector_b;
        *sector_b = temp;
    }
}

void sort_sectors(my_idt1 *world)
{
    for (int i = 0; i < world->sectors_nb - 1; i++) {
        for (int j = 0; j < world->sectors_nb - i - 1; j++) {
            my_swap_sectors_condition(world->sectors[j], world->sectors[j + 1]);
        }
    }
}

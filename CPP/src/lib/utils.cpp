/*
** EPITECH PROJECT, 2023
** doom
** File description:
** utils.c
*/

#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
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

static bool descendingOrder(sectors_t *a, sectors_t *b) {
    return a->d < b->d;
}

void sort_sectors(my_idt1 &world)
{
    /*
     * sectors_t *a;
    sectors_t *b;
    sectors_t *temp;

    for (int i = 0; i < world->sectors_nb - 1; i++) {
        for (int j = 0; j < world->sectors_nb - i - 1; j++) {
            a = world->sectors[j];
            b = world->sectors[j + 1];

            temp = *a;
            a = *world->sectors[j + 1];
            b = temp;
        }
    }
     */

    std::sort(world.sectors, world.sectors + world.sectors_nb, descendingOrder);
}

/*
** EPITECH PROJECT, 2023
** doom
** File description:
** draw.c
*/

#include "../../include/my.h"

void clear_points(my_idt1 *world)
{
    for (size_t i = 0; i < world->points_len; i++) {
        world->points[i].position.x = 0;
        world->points[i].position.y = 0;
        world->points[i].color.r = 0;
        world->points[i].color.g = 0;
        world->points[i].color.b = 0;
        world->points[i].color.a = 0;
    }
}

void draw_point(int x, int y, id_Color color, my_idt1 *world)
{
    size_t index = x * world->win_size.x + y;
    world->points[index] = (id_vertex){.position = {x, y}, .color = color};
}

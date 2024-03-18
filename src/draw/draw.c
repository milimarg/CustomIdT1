/*
** EPITECH PROJECT, 2023
** doom
** File description:
** draw.c
*/

#include "../../include/my.h"

void clear_points(my_idt1 *world)
{
    for (size_t i = 0; i < sizeof(world->points) / sizeof(world->points[0]); i++) {
        world->points[i] = (id_vertex){0};
    }
}

void draw_point(int x, int y, id_Color color, my_idt1 *world)
{
    size_t index = x * 192 + y; // TODO: 192 is width of screen
    world->points[index] = (id_vertex){.position = {x, y}, .color = color};
}

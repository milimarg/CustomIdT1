/*
** EPITECH PROJECT, 2023
** my_idt1
** File description:
** set_ground_sky.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../include/my.h"

void set_ground_and_sky(sfRenderWindow *window, my_idt1 *world)
{
    sfColor ground_color = sfRed;
    sfColor ceiling_color = {114, 137, 218, 255};
    sfVector2f ceiling_size = {world->map.opengl_size.x / 2.0,
    world->map.opengl_size.y / 2.0};

    sfRenderWindow_setFramerateLimit(window, 20);
    sfRenderWindow_setActive(window, sfTrue);
    world->map.ground = sfRectangleShape_create();
    world->map.sky = sfRectangleShape_create();
    sfRectangleShape_setSize(world->map.sky, ceiling_size);
    sfRectangleShape_setPosition(world->map.sky, (sfVector2f){0, 0});
    sfRectangleShape_setSize(world->map.ground, world->map.opengl_size);
    sfRectangleShape_setPosition(world->map.ground, (sfVector2f){0,
    world->map.opengl_size.y / 2});
    sfRectangleShape_setFillColor(world->map.ground, ground_color);
    sfRectangleShape_setFillColor(world->map.sky, ceiling_color);
    sfRectangleShape_setOutlineThickness(world->map.ground, 0);
    sfRectangleShape_setOutlineThickness(world->map.ground, 0);
    glPointSize(world->map.pixel_scale);
    gluOrtho2D(0, world->map.opengl_size.x, 0, world->map.opengl_size.y);
}

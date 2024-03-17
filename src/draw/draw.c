/*
** EPITECH PROJECT, 2023
** doom
** File description:
** draw.c
*/

#include <SFML/Graphics.h>
#include <GL/gl.h>
#include "../../include/my.h"

void draw_point(int x, int y, id_Color color, my_idt1 *world)
{
    glColor3ub(color.r, color.g, color.b);
    glBegin(GL_POINTS);
    glVertex2i(x * world->map.pixel_scale, y * world->map.pixel_scale);
    glEnd();
}

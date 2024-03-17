/*
** EPITECH PROJECT, 2023
** doom
** File description:
** move_strafe.c
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "../../include/my.h"

void strafe_left(my_idt1 *world, Vec2 *delta)
{
    world->player.x += delta->x;
    world->player.y -= delta->y;
}

void strafe_right(my_idt1 *world, Vec2 *delta)
{
    world->player.x -= delta->x;
    world->player.y += delta->y;
}

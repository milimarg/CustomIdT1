/*
** EPITECH PROJECT, 2023
** doom
** File description:
** move_player.c
*/

#include "../../include/my.h"

void move_player(my_idt1 *world, bool key_actions[KEY_ACTIONS_NUMBER])
{
    static void (*functions[])(my_idt1 *, id_Vec2 *) = {&move_front,
    &move_back, &turn_left, &turn_right, &go_up, &go_down, &lean_to_ground,
    &lean_to_sky, &strafe_left, &strafe_right};
    id_Vec2 delta = {
            world->pre_sin[world->player.angle] * 10.0,
            world->pre_cos[world->player.angle] * 10.0
    };

    for (int i = 0; i < KEY_ACTIONS_NUMBER; i++)
        if (key_actions[i])
            functions[i](world, &delta);
}

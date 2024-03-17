/*
** EPITECH PROJECT, 2023
** doom
** File description:
** move_player.c
*/

#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "../../include/my.h"

static void move_with_joystick(my_idt1 *world,
void (*functions[])(my_idt1 *, id_Vec2 *))
{
    id_Vec2 delta = {0};
    float stick_turn = sfJoystick_getAxisPosition(0, sfJoystickU);
    float stick_move = sfJoystick_getAxisPosition(0, sfJoystickY);
    float stick_view = sfJoystick_getAxisPosition(0, sfJoystickV);

    delta.x = world->pre_sin[world->player.angle] * fabs(stick_move) / 15.0;
    delta.y = world->pre_cos[world->player.angle] * fabs(stick_move) / 15.0;
    if (stick_turn == -100)
        functions[2](world, &delta);
    if (stick_turn == 100)
        functions[3](world, &delta);
    if (stick_move < -10)
        functions[0](world, &delta);
    if (stick_move > 10)
        functions[1](world, &delta);
    if (stick_view == 100)
        functions[6](world, &delta);
    if (stick_view == -100)
        functions[7](world, &delta);
}

void move_player(my_idt1 *world)
{
    static sfKeyCode keys[] = {sfKeyW, sfKeyS, sfKeyLeft, sfKeyRight,
    sfKeyPageUp, sfKeyPageDown, sfKeyUp, sfKeyDown, sfKeyComma, sfKeySemicolon,
    -1};
    static void (*functions[])(my_idt1 *, id_Vec2 *) = {&move_front,
    &move_back, &turn_left, &turn_right, &go_up, &go_down, &lean_to_ground,
    &lean_to_sky, &strafe_left, &strafe_right};
    id_Vec2 delta = {0};

    delta.x = world->pre_sin[world->player.angle] * 10.0;
    delta.y = world->pre_cos[world->player.angle] * 10.0;
    for (int i = 0; keys[i] != -1; i++) {
        if (sfKeyboard_isKeyPressed(keys[i]))
            functions[i](world, &delta);
    }
    if (world->joystick_connected)
        move_with_joystick(world, functions);
}

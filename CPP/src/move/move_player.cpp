/*
** EPITECH PROJECT, 2023
** doom
** File description:
** move_player.c
*/

#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../../include/my.h"

static void move_with_joystick(my_idt1 *world,
void (*functions[])(my_idt1 *, Vec2 *))
{
    Vec2 delta(0, 0);
    float stick_turn = sf::Joystick::getAxisPosition(0, sf::Joystick::U);
    float stick_move = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);
    float stick_view = sf::Joystick::getAxisPosition(0, sf::Joystick::V);

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

void move_player(my_idt1 &world)
{
    static sf::Keyboard::Key keys[] = {sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::Left, sf::Keyboard::Right,
    sf::Keyboard::PageUp, sf::Keyboard::PageDown, sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Comma, sf::Keyboard::SemiColon,
    sf::Keyboard::Unknown};
    static void (*functions[])(my_idt1 *, Vec2 *) = {&move_front,
    &move_back, &turn_left, &turn_right, &go_up, &go_down, &lean_to_ground,
    &lean_to_sky, &strafe_left, &strafe_right};
    Vec2 delta = {0};

    delta.x = world.pre_sin[world.player.angle] * 10.0;
    delta.y = world.pre_cos[world.player.angle] * 10.0;
    for (int i = 0; keys[i] != -1; i++) {
        if (sf::Keyboard::isKeyPressed(keys[i]))
            functions[i](&world, &delta);
    }
    if (world.joystick_connected)
        move_with_joystick(&world, functions);
}

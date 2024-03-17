/*
** EPITECH PROJECT, 2023
** my_idt1
** File description:
** example.c
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include "include/my.h"

int main(void)
{
    const char *filepath = "../config_files/example_config";
    sf::Event event;
    my_idt1 world((char *)filepath, RAW_CONFIG, sf::Keyboard::R);

    sf::VideoMode mode(world.map.opengl_size.x, world.map.opengl_size.y, 32);
    sf::RenderWindow window(mode, "it's doomsday");

    sf::VertexArray a;

    //set_ground_and_sky(window, world);
    world.joystick_connected = sf::Joystick::isConnected(0);
    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        move_player(world);
        display_world(world);
        window.draw(world->points);
        window.display();
        if (reload_world(world, (char *)filepath) == 1)
            return 1;
    }
    destroy_world(world);
    return (0);
}

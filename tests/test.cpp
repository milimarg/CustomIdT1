/*
** EPITECH PROJECT, 2023
** my_idt1
** File description:
** example.c
*/

#include <iostream>
#include <dlfcn.h>
#include <SFML/Graphics.hpp>
#include "../CPP/include/my.hpp"

static sf::Keyboard::Key keys[KEY_ACTIONS_NUMBER] = {
        sf::Keyboard::W,         // move front
        sf::Keyboard::S,         // move back
        sf::Keyboard::Left,      // turn left
        sf::Keyboard::Right,     // turn right
        sf::Keyboard::PageUp,    // go up
        sf::Keyboard::PageDown,  // go down
        sf::Keyboard::Up,        // lean to ground
        sf::Keyboard::Down,      // lean to sky
        sf::Keyboard::Comma,     // strafe left
        sf::Keyboard::Semicolon // strafe right
};

int main(void)
{
    const char *filepath = "./config_files/example_config";
    sf::Event event;
    sf::VertexArray vertexArray;
    my_idt1 *world = create_world((char *)filepath, RAW_CONFIG, 5, (id_Vec2){384, 216});
    std::array<bool, KEY_ACTIONS_NUMBER> actions = {false};

    if (world == nullptr)
        return 1;
    sf::VideoMode mode(world->opengl_size.x, world->opengl_size.y);
    sf::RenderWindow window(mode, "it's doomsday++");

    window.setFramerateLimit(20);

    while (window.isOpen()) {
        window.clear();
        clear_points(world);
        vertexArray.clear();
        vertexArray.setPrimitiveType(sf::PrimitiveType::Quads);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        for (int i = 0; i < KEY_ACTIONS_NUMBER; i++)
            actions[i] = sf::Keyboard::isKeyPressed(keys[i]);

        move_player(world, actions);
        display_world(world);

        for (auto &point : world->points) {
            const int x = point.first.first;
            const int y = point.first.second;
            const id_vertex v = point.second;

            const int final_x = x * world->pixel_scale;
            const int final_y = y * world->pixel_scale;
            vertexArray.append(sf::Vertex(sf::Vector2f(final_x, final_y),
                                          sf::Color(v.color.r, v.color.g, v.color.b)));
            vertexArray.append(sf::Vertex(sf::Vector2f(final_x + world->pixel_scale, final_y),
                                          sf::Color(v.color.r, v.color.g, v.color.b)));
            vertexArray.append(sf::Vertex(sf::Vector2f(final_x + world->pixel_scale, final_y + world->pixel_scale),
                                          sf::Color(v.color.r, v.color.g, v.color.b)));
            vertexArray.append(sf::Vertex(sf::Vector2f(final_x, final_y + world->pixel_scale),
                                          sf::Color(v.color.r, v.color.g, v.color.b)));
        }

        window.draw(vertexArray);
        window.display();
        bool pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::R);
        if (reload_world(world, (char *)filepath, pressed) == 1)
            return 1;
    }
    destroy_world(world);
    return (0);
}

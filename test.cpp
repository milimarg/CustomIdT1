/*
** EPITECH PROJECT, 2023
** my_idt1
** File description:
** example.c
*/

#include <iostream>
#include <dlfcn.h>
#include <SFML/Graphics.hpp>
#include "include/struct.h"

typedef my_idt1 *(*create_world_function)(char *filepath, map_type type, int pixel_scale,
    id_Vec2 win_size);
typedef void (*move_player_function)(my_idt1 *world, bool key_actions[KEY_ACTIONS_NUMBER]);
typedef void (*display_world_function)(my_idt1 *world);
typedef int (*reload_world_function)(my_idt1 *world, char *filepath, bool isReloadKeyPressed);
typedef void (*destroy_world_function)(my_idt1 *world);
typedef void (*clear_points_function)(my_idt1 *world);

create_world_function create_world;
move_player_function move_player;
display_world_function display_world;
reload_world_function reload_world;
destroy_world_function destroy_world;
clear_points_function clear_points;

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

static void get_functions(void *handle)
{
    create_world = (create_world_function)dlsym(handle, "create_world");
    move_player = (move_player_function)dlsym(handle, "move_player");
    display_world = (display_world_function)dlsym(handle, "display_world");
    reload_world = (reload_world_function)dlsym(handle, "reload_world");
    destroy_world = (destroy_world_function)dlsym(handle, "destroy_world");
    clear_points = (clear_points_function)dlsym(handle, "clear_points");
}

int main(void)
{
    void *handle = dlopen("./libidt1.so", RTLD_LAZY);
    const char *filepath = "./config_files/example_config";
    sf::Event event;
    sf::VertexArray vertexArray;
    get_functions(handle);
    my_idt1 *world = create_world((char *)filepath, RAW_CONFIG, 10, (id_Vec2){192, 108});
    bool actions[KEY_ACTIONS_NUMBER] = {false};

    if (world == NULL)
        return 1;
    sf::VideoMode mode(world->opengl_size.x, world->opengl_size.y);
    sf::RenderWindow window(mode, "it's doomsday++");

    window.setFramerateLimit(20);

    while (window.isOpen()) {
        window.clear();
        clear_points(world);
        vertexArray.clear();
        vertexArray.setPrimitiveType(sf::PrimitiveType::Points);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        for (int i = 0; i < KEY_ACTIONS_NUMBER; i++)
            actions[i] = sf::Keyboard::isKeyPressed(keys[i]);

        move_player(world, actions);
        display_world(world);

        for (int y = 0; y < world->win_size.y; y++) {
            for (int x = 0; x < world->win_size.x; x++) {
                id_vertex v = world->points[x * world->win_size.x + y];
                vertexArray.append(sf::Vertex(
                        sf::Vector2f(x, y),
                        sf::Color(v.color.r, v.color.g, v.color.b))
                );
            }
        }

        window.draw(vertexArray);
        window.display();
        bool pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::R);
        if (reload_world(world, (char *)filepath, pressed) == 1)
            return 1;
    }
    destroy_world(world);
    dlclose(handle);
    return (0);
}

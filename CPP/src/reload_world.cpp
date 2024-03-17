/*
** EPITECH PROJECT, 2023
** doom
** File description:
** reload_world.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "../include/my.h"

int reload_world(my_idt1 *world, char *filepath)
{
    if (sf::Keyboard::isKeyPressed(world->map.reload_key) && !world->no_spam_key) {
        world->no_spam_key = 1;
        write(1, "Updating world's matrix...\n", 27);
        for (int i = 0; i < world->sectors_nb; i++) {
            free(world->sectors[i]->walls);
            free(world->sectors[i]);
        }
        free(world->sectors);
        world->filepath = filepath;
        convert_dante_to_config(world->filepath);
        if (parse_file(world) == 1)
            return 1;
    }
    if (!sf::Keyboard::isKeyPressed(world->map.reload_key) && world->no_spam_key) {
        world->no_spam_key = 0;
    }
    return 0;
}

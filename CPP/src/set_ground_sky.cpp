/*
** EPITECH PROJECT, 2023
** my_idt1
** File description:
** set_ground_sky.c
*/

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../include/my.h"

void set_ground_and_sky(sf::RenderWindow &window, my_idt1 *world)
{
    sf::Color ground_color = sf::Color::Red;
    sf::Color ceiling_color = {114, 137, 218, 255};
    sf::Vector2f ceiling_size = {world->map.opengl_size.x / 2.0f,
    world->map.opengl_size.y / 2.0f};

    window.setFramerateLimit(20);
    window.setActive(true);
    world->map.sky.setSize(ceiling_size);
    world->map.sky.setPosition((sf::Vector2f){0, 0});
    world->map.ground.setSize(world->map.opengl_size);
    world->map.ground.setPosition((sf::Vector2f){0, world->map.opengl_size.y / 2});
    world->map.ground.setFillColor(ground_color);
    world->map.sky.setFillColor(ceiling_color);
    world->map.ground.setOutlineThickness(0);
    world->map.ground.setOutlineThickness(0);
    glPointSize(world->map.pixel_scale);
    gluOrtho2D(0, world->map.opengl_size.x, 0, world->map.opengl_size.y);
}

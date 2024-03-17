/*
** EPITECH PROJECT, 2023
** doom
** File description:
** world_handler.c
*/

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include "../include/my.h"

void set_map_infos(my_idt1 *world, map_type type, sfKeyCode reload_key)
{
    world->map.pixel_scale = 8;
    world->map.win_size = (sfVector2f){800, 600};
    world->map.opengl_size.x = world->map.win_size.x * world->map.pixel_scale;
    world->map.opengl_size.y = world->map.win_size.y * world->map.pixel_scale;
    world->map.type = type;
    world->map.reload_key = reload_key;
    if (world->map.type == DANTE)
        convert_dante_to_config(world->filepath);
}

my_idt1 *create_world(char *filepath, map_type type, sfKeyCode reload_key)
{
    my_idt1 *world = malloc(sizeof(my_idt1));
    world->pre_cos = malloc(sizeof(double) * 360);
    world->pre_sin = malloc(sizeof(double) * 360);
    for (int i = 0; i < 360; i++) {
        world->pre_cos[i] = cos(deg_to_rad(i));
        world->pre_sin[i] = sin(deg_to_rad(i));
    }
    world->player = (my_idt1_player){0, 0, 30, 0, 0};
    world->points = sfVertexArray_create();
    world->no_spam_key = 0;
    world->filepath = filepath;
    set_map_infos(world, type, reload_key);
    if (parse_file(world) == 1)
        return NULL;
    return (world);
}

void destroy_world(my_idt1 *world)
{
    for (int i = 0; i < world->sectors_nb; i++) {
        free(world->sectors[i]->walls);
        free(world->sectors[i]->points_surface);
        free(world->sectors[i]);
    }
    free(world->sectors);
    free(world->pre_cos);
    free(world->pre_sin);
    free(world);
}

void display_world(my_idt1 *world)
{
    Vec3 *wpos = malloc(sizeof(Vec3) * 4);

    sort_sectors(world);
    for (int s = 0; s < world->sectors_nb; s++) {
        world->sectors[s]->d = 0;
        set_surface_type(world, s);
        for (int loop = 0; loop < 2; loop++) {
            draw_one_wall(world, loop, s, wpos);
            world->sectors[s]->d /= world->sectors[s]->walls_nb;
            world->sectors[s]->surface *= -1;
        }
    }
    free(wpos);
}

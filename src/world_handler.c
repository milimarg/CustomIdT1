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

static void set_map_infos(my_idt1 *world, map_type type, int pixel_scale,
    id_Vec2 win_size)
{
    world->pixel_scale = pixel_scale;
    world->win_size = win_size;
    world->opengl_size.x = world->win_size.x * world->pixel_scale;
    world->opengl_size.y = world->win_size.y * world->pixel_scale;
    world->type = type;
    if (world->type == DANTE)
        convert_dante_to_config(world->filepath);
}

my_idt1 *create_world(char *filepath, map_type type, int pixel_scale,
    id_Vec2 win_size)
{
    my_idt1 *world = (my_idt1 *)malloc(sizeof(my_idt1));
    world->pre_cos = (double *)malloc(sizeof(double) * 360);
    world->pre_sin = (double *)malloc(sizeof(double) * 360);
    for (int i = 0; i < 360; i++) {
        world->pre_cos[i] = cos(deg_to_rad(i));
        world->pre_sin[i] = sin(deg_to_rad(i));
    }
    world->player = (my_idt1_player){0, 0, 30, 0, 0};
    world->points = sfVertexArray_create();
    world->no_spam_key = 0;
    world->filepath = filepath;
    set_map_infos(world, type, pixel_scale, win_size);
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
    id_Vec3 *wpos = (id_Vec3 *)malloc(sizeof(id_Vec3) * 4);

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

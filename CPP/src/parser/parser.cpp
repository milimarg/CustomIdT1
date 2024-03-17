/*
** EPITECH PROJECT, 2023
** doom
** File description:
** parser.c
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "../../include/my.h"

static void check_parameters_are_right(char **output)
{
    if (my_array_len(output) != 7) {
        write(2, "polyhedron parameters are wrong\n", 32);
    }
}

void get_line_info(int index, my_idt1 *world, char *buffer)
{
    char **output = NULL;

    if (index == 0) {
        world->sectors_nb = atoi(buffer);
        world->sectors = (sectors_t **)malloc(sizeof(sectors_t *) * world->sectors_nb);
        for (int i = 0; i < world->sectors_nb; i++) {
            world->sectors[i] = (sectors_t *)malloc(sizeof(sectors_t));
            world->sectors[i]->points_surface = (int *)malloc(sizeof(int) *
            world->map.win_size.x);
        }
    } else {
        output = my_str_to_word_array(buffer);
        check_parameters_are_right(output);
        Vec3 pos(atoi(output[1]), atoi(output[2]), atoi(output[3]));
        Vec3 size(atoi(output[4]), atoi(output[5]), atoi(output[6]));
        fill_sector(world->sectors[index - 1], RECTANGLE, &pos, &size);
    }
}

int parse_file(my_idt1 *world)
{
    FILE *fd = NULL;
    char *buffer = NULL;
    size_t s = 0;
    int index = 0;
    const char *types[] = {world->filepath, "3d_config"};

    fd = fopen(types[world->map.type], "r");
    if (fd == NULL) {
        write(2, "fd returns NULL\n", 16);
        return 1;
    }
    while (getline(&buffer, &s, fd) != -1) {
        get_line_info(index, world, buffer);
        index++;
    }
    fclose(fd);
    return 0;
}

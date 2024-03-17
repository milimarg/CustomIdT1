/*
** EPITECH PROJECT, 2023
** idt1
** File description:
** sectors.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.hpp>
#include "../include/my.h"

static sf::IntRect *set_values_for_rectangle(int *walls_nb, Vec3 *size, Vec3 *pos)
{
    sf::IntRect *rect = NULL;

    *walls_nb = 4;
    rect = (sf::IntRect *)malloc(sizeof(sf::IntRect) * (*walls_nb));
    rect[0] = (sf::IntRect){pos->x, pos->y, pos->x + size->x, pos->y};
    rect[1] = (sf::IntRect){rect[0].width, rect[0].height, pos->x + size->x,
    pos->y + size->y};
    rect[2] = (sf::IntRect){rect[1].width, rect[1].height, pos->x, pos->y +
    size->y};
    rect[3] = (sf::IntRect){rect[2].width, rect[2].height, rect[0].left,
    rect[0].top};
    return (rect);
}

static void fill_walls_info(sectors_t *sector, sf::IntRect *rect,
sf::Color wall_color[2], int walls_nb)
{
    for (int w = 0; w < walls_nb; w++) {
        sector->walls[w].point1.x = rect[w].left;
        sector->walls[w].point1.y = rect[w].top;
        sector->walls[w].point2.x = rect[w].width;
        sector->walls[w].point2.y = rect[w].height;
        sector->walls[w].color = wall_color[(w % 2)];
    }
}

void fill_sector(sectors_t *sector, shape_type shape, Vec3 *pos, Vec3 *size)
{
    int walls_nb = 0;
    sf::IntRect *rect = NULL;
    sf::Color top_color = {220, 220, 220, 255};
    sf::Color bottom_color = {112, 128, 144, 255};
    sf::Color wall_color[2] = {{105, 105, 105, 255}, {211, 211, 211, 255}};

    if (shape == RECTANGLE)
        rect = set_values_for_rectangle(&walls_nb, size, pos);
    if (walls_nb == 0 || rect == NULL) {
        write(2, "walls number can't be null\n", 27);
    }
    sector->walls_nb = walls_nb;
    sector->walls = (wall_t *)malloc(sizeof(wall_t) * walls_nb);
    sector->z1 = pos->z;
    sector->z2 = size->z - pos->z;
    sector->top = top_color;
    sector->bottom = bottom_color;
    fill_walls_info(sector, rect, wall_color, walls_nb);
    free(rect);
}

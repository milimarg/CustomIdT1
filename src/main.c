/*
** EPITECH PROJECT, 2023
** my_idt1
** File description:
** main.c
*/

#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "../include/my.h"

/*
int main(void)
{
    sfEvent event = {0};
    char *filepath = "../mess/tom_map";
    my_idt1 *world = create_world(filepath, DANTE, sfKeyR);
    sfVideoMode mode = {world->map.opengl_size.x, world->map.opengl_size.y, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "it's doomsday",
    sfDefaultStyle, NULL);

    set_ground_and_sky(window, world);
    world->joystick_connected = sfJoystick_isConnected(0);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, event)) {
            if (event->type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        move_player(world);
        display_world(world);
        sfRenderWindow_display(window);
        reload_world(world, filepath);
    }
    destroy_world(world);
    sfRenderWindow_destroy(window);
    return (0);
}
*/

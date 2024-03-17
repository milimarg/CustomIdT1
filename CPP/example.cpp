/*
** EPITECH PROJECT, 2023
** my_idt1
** File description:
** example.c
*/

#include <SFML/Graphics.hpp>
#include "include/my.h"

int main(void)
{
    const char *filepath = "../config_files/example_config";
    sf::Event event;
    my_idt1 *world = create_world(filepath, RAW_CONFIG, sfKeyR);
    sfVideoMode mode;
    sf::RenderWindow &window = NULL;

    if (world == NULL)
        return 1;
    mode = (sfVideoMode){world->map.opengl_size.x, world->map.opengl_size.y, 32};
    window = sfRenderWindow_create(mode, "it's doomsday", sfDefaultStyle, NULL);

    set_ground_and_sky(window, world);
    world->joystick_connected = sfJoystick_isConnected(0);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        move_player(world);
        display_world(world);
        sfRenderWindow_display(window);
        if (reload_world(world, filepath) == 1)
            return 1;
    }
    destroy_world(world);
    sfRenderWindow_destroy(window);
    return (0);
}

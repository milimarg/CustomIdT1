/*
** EPITECH PROJECT, 2023
** my_idt1
** File description:
** example.c
*/

#include <SFML/Graphics.h>
#include <dlfcn.h>
#include "include/struct.h"

typedef my_idt1 *(*create_world_function)(char *filepath, map_type type, sfKeyCode reload_key);
typedef void (*set_ground_and_sky_function)(sfRenderWindow *window, my_idt1 *world);
typedef void (*move_player_function)(my_idt1 *world);
typedef void (*display_world_function)(my_idt1 *world);
typedef int (*reload_world_function)(my_idt1 *world, char *filepath);
typedef void (*destroy_world_function)(my_idt1 *world);

create_world_function create_world;
set_ground_and_sky_function set_ground_and_sky;
move_player_function move_player;
display_world_function display_world;
reload_world_function reload_world;
destroy_world_function destroy_world;

static void get_functions(void *handle)
{
    create_world = dlsym(handle, "create_world");
    set_ground_and_sky = dlsym(handle, "set_ground_and_sky");
    move_player = dlsym(handle, "move_player");
    display_world = dlsym(handle, "display_world");
    reload_world = dlsym(handle, "reload_world");
    destroy_world = dlsym(handle, "destroy_world");
}

int main(void)
{
    void *handle = dlopen("./libidt1.so", RTLD_LAZY);
    char *filepath = "./config_files/example_config";
    sfEvent event = {0};
    get_functions(handle);
    my_idt1 *world = create_world(filepath, RAW_CONFIG, sfKeyR);
    sfVideoMode mode;
    sfRenderWindow *window = NULL;

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
    dlclose(handle);
    return (0);
}

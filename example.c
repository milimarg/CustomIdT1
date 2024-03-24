/*
** EPITECH PROJECT, 2023
** my_idt1
** File description:
** example.c
*/

#include <dlfcn.h>
#include <SFML/Graphics.h>
#include "C/include/struct.h"

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

static sfKeyCode keys[KEY_ACTIONS_NUMBER] = {
        sfKeyW,         // move front
        sfKeyS,         // move back
        sfKeyLeft,      // turn left
        sfKeyRight,     // turn right
        sfKeyPageUp,    // go up
        sfKeyPageDown,  // go down
        sfKeyUp,        // lean to ground
        sfKeyDown,      // lean to sky
        sfKeyComma,     // strafe left
        sfKeySemicolon // strafe right
};

static void get_functions(void *handle)
{
    create_world = dlsym(handle, "create_world");
    move_player = dlsym(handle, "move_player");
    display_world = dlsym(handle, "display_world");
    reload_world = dlsym(handle, "reload_world");
    destroy_world = dlsym(handle, "destroy_world");
    clear_points = dlsym(handle, "clear_points");
}

int main(void)
{
    void *handle = dlopen("./C/libidt1.so", RTLD_LAZY);
    char *filepath = "./config_files/example_config";
    sfEvent event = {0};
    get_functions(handle);
    my_idt1 *world = create_world(filepath, RAW_CONFIG, 10, (id_Vec2){192, 108});
    bool actions[KEY_ACTIONS_NUMBER] = {false};
    sfRenderWindow *window = NULL;
    sfVertexArray *array = sfVertexArray_create();

    if (world == NULL)
        return 1;
    sfVideoMode mode = {world->opengl_size.x, world->opengl_size.y, 32};
    window = sfRenderWindow_create(mode, "it's doomsday", sfDefaultStyle, NULL);

    sfRenderWindow_setFramerateLimit(window, 20);

    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        clear_points(world);
        sfVertexArray_clear(array);
        sfVertexArray_setPrimitiveType(array, sfQuads);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }

        for (size_t i = 0; i < KEY_ACTIONS_NUMBER; i++)
            actions[i] = sfKeyboard_isKeyPressed(keys[i]);

        move_player(world, actions);
        display_world(world);

        for (int y = 0; y < world->win_size.y; y++) {
            for (int x = 0; x < world->win_size.x; x++) {
                const id_vertex v = world->points[x * world->win_size.x + y];
                const int final_x = x * world->pixel_scale;
                const int final_y = y * world->pixel_scale;
                sfVertexArray_append(array,
                    (sfVertex){.position = {final_x, final_y},
                    .color = {v.color.r, v.color.g, v.color.b, 255}});
                sfVertexArray_append(array,
                    (sfVertex){.position = {final_x + world->pixel_scale, final_y},
                    .color = {v.color.r, v.color.g, v.color.b, 255}});
                sfVertexArray_append(array,
                    (sfVertex){.position = {final_x + world->pixel_scale, final_y + world->pixel_scale},
                    .color = {v.color.r, v.color.g, v.color.b, 255}});
                sfVertexArray_append(array,
                    (sfVertex){.position = {final_x, final_y + world->pixel_scale},
                    .color = {v.color.r, v.color.g, v.color.b, 255}});
            }
        }

        sfRenderWindow_drawVertexArray(window, array, NULL);
        sfRenderWindow_display(window);
        sfBool pressed = sfKeyboard_isKeyPressed(sfKeyR);
        if (reload_world(world, filepath, pressed) == 1)
            return 1;
    }
    destroy_world(world);
    sfRenderWindow_destroy(window);
    dlclose(handle);
    return (0);
}

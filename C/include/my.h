/*
** EPITECH PROJECT, 2023
** doom
** File description:
** my.h
*/

#ifndef MY_IDT1_H_
    #define MY_IDT1_H_
    #define deg_to_rad(x) (x / 180.0 * M_PI)
    #define char_isalpha(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    #define my_char_isvisible(c) (c >= '!' && c <= '~')
    #include "struct.h"
    #include "lib.h"
    #include <stdio.h>

void move_player(my_idt1 *world);
my_idt1 *create_world(char *filepath, map_type type, sfKeyCode reload_key);
void draw_point(int x, int y, sfColor color, my_idt1 *world);
void draw_wall(coordinates_wall *wall, sfColor color, int s, my_idt1 *world);
int reload_world(my_idt1 *world, char *filepath);
void convert_dante_to_config(char *filepath);
void clip_behind_player(Vec3 *one, Vec3 *two);
void draw_one_wall(my_idt1 *world, int loop, int s, Vec3 *wpos);
void set_some_points_values(Vec2 *one_two, my_idt1 *world,
wall_t *wall, int loop);
coordinates_wall set_walls_pos_depending_of_window_position(Vec3 *wpos,
my_idt1 *world);
void set_surface_type(my_idt1 *world, int s);
void set_wpos_values(Vec3 *wpos, Vec2 *one_two,
int s, my_idt1 *world);
void destroy_world(my_idt1 *world);
void move_front(my_idt1 *world, Vec2 *delta);
void move_back(my_idt1 *world, Vec2 *delta);
void turn_left(my_idt1 *world, Vec2 *delta);
void turn_right(my_idt1 *world, Vec2 *delta);
void go_up(my_idt1 *world, Vec2 *delta);
void go_down(my_idt1 *world, Vec2 *delta);
void lean_to_ground(my_idt1 *world, Vec2 *delta);
void lean_to_sky(my_idt1 *world, Vec2 *delta);
void get_line_info(int index, my_idt1 *world, char *buffer);
int parse_file(my_idt1 *world);
void fill_sector(sectors_t *sector, shape_type shape, Vec3 *pos, Vec3 *size);
void strafe_left(my_idt1 *world, Vec2 *delta);
void strafe_right(my_idt1 *world, Vec2 *delta);
void display_world(my_idt1 *world);
void set_ground_and_sky(sfRenderWindow *window, my_idt1 *world);
#endif /*MY_IDT1_H_*/

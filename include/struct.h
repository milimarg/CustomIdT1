/*
** EPITECH PROJECT, 2023
** prototype-raycasting-and-doom_old
** File description:
** struct.h
*/
#ifndef STRUCT_H_
    #define STRUCT_H_
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <stdbool.h>
    #define KEY_ACTIONS_NUMBER 10

typedef struct {
    int x;
    int y;
} id_Vec2;

typedef struct {
    int x;
    int y;
    int z;
} id_Vec3;

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} id_Color;

typedef enum shape_type {
    RECTANGLE = 0,
    TRIANGLE,
} shape_type;

typedef enum wall_type {
    SIDE = 0,
    BOTTOM,
    TOP,
} wall_type;

typedef struct wall_s {
    sfVector2f point1;
    sfVector2f point2;
    id_Color color;
} wall_t;

typedef struct sectors_s {
    int walls_nb;
    int z1, z2;
    int d;
    id_Color top;
    id_Color bottom;
    int *points_surface;
    int surface;
    wall_t *walls;
} sectors_t;

typedef enum {
    RAW_CONFIG = 0,
    DANTE,
} map_type;

typedef struct my_idt1_player {
    float x;
    float y;
    float z;
    int angle;
    int look;
} my_idt1_player;

typedef struct my_idt1 {
    double *pre_cos;
    double *pre_sin;
    char *filepath;
    int no_spam_key;
    int sectors_nb;
    sectors_t **sectors;
    sfVertexArray *points;
    my_idt1_player player;
    int pixel_scale;
    id_Vec2 win_size;
    id_Vec2 opengl_size;
    map_type type;
} my_idt1;

typedef struct coordinates_wall {
    int x1;
    int x2;
    int bottom1;
    int bottom2;
    int top1;
    int top2;
} coordinates_wall;

#endif /*STRUCT_H_*/

/*
** EPITECH PROJECT, 2023
** prototype-raycasting-and-doom_old
** File description:
** struct.h
*/
#ifndef STRUCT_H_
    #define STRUCT_H_
    #include <stdbool.h>
    #include <array>
    #include <vector>
    #include <unordered_map>
    #include "Pair.hpp"
    #define KEY_ACTIONS_NUMBER 10

/* CUSTOM DATA TYPES */

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

typedef struct {
    int left;
    int top;
    int width;
    int height;
} id_rect;

typedef struct {
    id_Vec2 position;
    id_Color color;
} id_vertex;

/* DATA TYPES ENUM */

typedef enum shape_type {
    RECTANGLE = 0,
    TRIANGLE,
} shape_type;

typedef enum wall_type {
    SIDE = 0,
    BOTTOM,
    TOP,
} wall_type;

/* misc */

typedef struct wall_s {
    id_Vec2 point1;
    id_Vec2 point2;
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
    std::array<double, 360> pre_cos;
    std::array<double, 360> pre_sin;
    char *filepath;
    int no_spam_key;
    int sectors_nb;
    std::vector<sectors_t *> sectors;
    unsigned int points_len;
    std::unordered_map<std::pair<int, int>, id_vertex> points;
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

/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Manager_Structs
*/

#ifndef MANAGER_STRUCTS_H
    #define MANAGER_STRUCTS_H

    #include "entity_structs.h"

typedef struct {
    Entity entities[70000];
    int entity_count;
    sfTexture* plane_texture;
    sfTexture* tower_texture;
    sfFont* timer_font;
    sfText* timer_text;
    sfTexture* bg_texture;
    sfSprite* bg_sprite;
    bool show_hitboxes;
    bool show_sprites;
    bool is_paused;
    bool game_over;
    sfText* game_over_text;
    bool total_planes_landed;
    bool total_planes_collided;
    bool update_timer;
    int active_planes_count;
    int planes_arrived;
    int planes_to_take_off;
} Manager;

#endif // MANAGER_STRUCTS_H

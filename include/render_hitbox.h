/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Render_Hitbox
*/

#ifndef RENDER_HITBOX_H
    #define RENDER_HITBOX_H

    #include "manager_structs.h"

void draw_plane_hitbox(sfRenderWindow* window, Entity* entity);
void draw_tower_area(sfRenderWindow* window, Entity* ent, int greatest_side);
void render_timer(sfRenderWindow* window, Manager* manager);
void render_bg(sfRenderWindow* win, float x, float y, sfFloatRect* text_rect);

#endif // RENDER_HITBOX_H

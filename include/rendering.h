/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Rendering
*/

#ifndef RENDERING_H
    #define RENDERING_H

    #include "manager_structs.h"

void render_entities(sfRenderWindow* window, Manager* manager, int great_side);
void render_ent(sfRenderWindow* win, Entity* ent, Manager* man, int gr_side);
void render_plane(sfRenderWindow* window, Entity* entity, Manager* manager);
void render_tower(sfRenderWindow* win, Entity* ent, Manager* man, int gr_side);
void render(sfRenderWindow* window, Manager* manager, const AppConfig* config);

#endif // RENDERING_H

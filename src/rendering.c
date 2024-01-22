/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Rendering
*/

#include "all_headers.h"
#include <SFML/Graphics.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void render_entities(sfRenderWindow* window, Manager* manager, int great_side)
{
    for (int i = 0; i < manager->entity_count; ++i) {
        if (manager->entities[i].is_active) {
            render_ent(window, &manager->entities[i], manager, great_side);
        }
    }
}

void render_ent(sfRenderWindow* win, Entity* ent, Manager* man, int gr_side)
{
    if (ent->type == PLANE) {
        render_plane(win, ent, man);
    } else if (ent->type == TOWER) {
        render_tower(win, ent, man, gr_side);
    }
}

void render_plane(sfRenderWindow* window, Entity* entity, Manager* manager)
{
    if (manager->show_sprites) {
        sfRenderWindow_drawSprite(window, entity->sprite, NULL);
    }
    if (entity->type == PLANE && manager->show_hitboxes) {
        draw_plane_hitbox(window, entity);
    }
}

void render_tower(sfRenderWindow* win, Entity* ent, Manager* man, int gr_side)
{
    if (man->show_sprites) {
        sfRenderWindow_drawSprite(win, ent->sprite, NULL);
    }
    if (ent->type == TOWER && man->show_hitboxes) {
        draw_tower_area(win, ent, gr_side);
    }
}

void render(sfRenderWindow* window, Manager* manager, const AppConfig* config)
{
    int greatest_side = config->window_width > config->window_height ?
    config->window_width : config->window_height;

    if (manager->bg_sprite) {
        sfRenderWindow_drawSprite(window, manager->bg_sprite, NULL);
    }
    if (manager->game_over) {
        sfRenderWindow_drawText(window, manager->game_over_text, NULL);
    }
    render_entities(window, manager, greatest_side);
    render_timer(window, manager);
    render_active_planes(window, manager);
    render_arrived_planes(window, manager);
    render_planes_to_take_off(window, manager);
    sfRenderWindow_display(window);
}

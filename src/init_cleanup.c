/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Init_Cleanup
*/

#include "all_headers.h"
#include <SFML/Graphics.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void init_manager_basic(Manager* manager)
{
    manager->entity_count = 0;
    srand(time(NULL));
    manager->is_paused = false;
    manager->show_hitboxes = true;
    manager->show_sprites = true;
    manager->game_over = false;
    manager->total_planes_landed = 0;
    manager->total_planes_collided = 0;
    manager->active_planes_count = 0;
    manager->planes_arrived = 0;
}

void init_manager_text_elements(Manager* manager, sfRenderWindow* window)
{
    sfVector2u window_size = sfRenderWindow_getSize(window);

    manager->timer_font = sfFont_createFromFile("assets/Font.ttf");
    manager->timer_text = sfText_create();
    sfText_setFont(manager->timer_text, manager->timer_font);
    sfText_setCharacterSize(manager->timer_text, 24);
    sfText_setColor(manager->timer_text, sfWhite);
    sfText_setPosition(manager->timer_text,
    (sfVector2f){window_size.x - 100, 10});
    manager->game_over_text = sfText_create();
    sfText_setFont(manager->game_over_text, manager->timer_font);
    sfText_setCharacterSize(manager->game_over_text, 24);
    sfText_setColor(manager->game_over_text, sfWhite);
    sfText_setPosition(manager->game_over_text,
    (sfVector2f){window_size.x / 2 - 100, window_size.y / 2 - 50});
}

int load_textures(Manager* manager)
{
    manager->plane_texture = sfTexture_createFromFile
    ("assets/plane.png", NULL);
    if (manager->plane_texture == NULL) {
        return 84;
    }
    manager->tower_texture = sfTexture_createFromFile
    ("assets/tower.png", NULL);
    if (manager->tower_texture == NULL) {
        return 84;
    }
    return 0;
}

void cleanup(Manager* manager)
{
    for (int i = 0; i < manager->entity_count; ++i) {
        if (manager->entities[i].sprite != NULL) {
            sfSprite_destroy(manager->entities[i].sprite);
        }
    }
    if (manager->plane_texture != NULL) {
        sfTexture_destroy(manager->plane_texture);
    }
    if (manager->tower_texture != NULL) {
        sfTexture_destroy(manager->tower_texture);
    }
}

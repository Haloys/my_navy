/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Entity_Management
*/

#include "all_headers.h"
#include <SFML/Graphics.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calculate_rotation_angle(Vector2 direction)
{
    return atan2f(direction.y, direction.x) * (180.0f / M_PI);
}

sfSprite* create_sprite(sfTexture* texture, float scale)
{
    sfSprite* sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, (sfVector2f){scale, scale});
    return sprite;
}

void add_entity_to_manager(Entity* entity, Manager* manager)
{
    if (manager->entity_count < 70000) {
        manager->entities[manager->entity_count] = *entity;
        sfSprite_setPosition(manager->entities[manager->entity_count].sprite,
        (sfVector2f){entity->position.x, entity->position.y});
        manager->entity_count++;
    }
}

void update_target_for_plane(Manager* manager, int i)
{
    int nearest_tower_index = find_nearest_tower(manager->entities,
    manager->entity_count, manager->entities[i].target);

    if (nearest_tower_index != -1) {
        manager->entities[i].target =
        manager->entities[nearest_tower_index].position;
    }
}

void assign_nearest_towers(Manager* manager)
{
    for (int i = 0; i < manager->entity_count; ++i) {
        if (manager->entities[i].type == PLANE) {
            update_target_for_plane(manager, i);
        }
    }
}

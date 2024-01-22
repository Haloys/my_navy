/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Entity_Updating
*/

#include "all_headers.h"
#include <SFML/Graphics.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void update_plane_entity(Manager *manager, int i, float delta_time)
{
    Vector2 direction = calculate_direction(manager->entities[i].position,
    manager->entities[i].target);
    float angle = calculate_rotation_angle(direction);

    manager->entities[i].position.x += direction.x *
    manager->entities[i].speed * delta_time;
    manager->entities[i].position.y += direction.y *
    manager->entities[i].speed * delta_time;
    sfSprite_setPosition(manager->entities[i].sprite,
    (sfVector2f){manager->entities[i].position.x,
    manager->entities[i].position.y});
    sfSprite_setRotation(manager->entities[i].sprite, angle);
    if (is_close_to_target(manager->entities[i])) {
        manager->planes_arrived++;
        remove_entity(manager, &i);
    }
}

void remove_entity(Manager *manager, int *i)
{
    if (manager->entities[*i].type == PLANE) {
        manager->active_planes_count--;
    }
    sfSprite_destroy(manager->entities[*i].sprite);
    manager->entities[*i] = manager->entities[manager->entity_count - 1];
    manager->entity_count--;
    (*i)--;
}

void update_entity_if_plane(Manager *manager, int i, float delta_time)
{
    if (manager->entities[i].type != PLANE) {
        return;
    }
    update_plane_entity(manager, i, delta_time);
    if (is_close_to_target(manager->entities[i])) {
        remove_entity(manager, &i);
    }
}

void refa_activate_entity(Entity* entity, float elapsed_time, Manager* man)
{
    if (entity->is_active || entity->delay > elapsed_time) {
        return;
    }
    entity->is_active = true;
    if (entity->type == PLANE) {
        man->active_planes_count++;
        man->planes_to_take_off--;
    }
}

void activate_entities(Manager *manager, float elapsed_time)
{
    for (int i = 0; i < manager->entity_count; ++i) {
        refa_activate_entity(&manager->entities[i], elapsed_time, manager);
    }
}

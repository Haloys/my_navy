/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Collision_Handling
*/

#include "all_headers.h"
#include <SFML/Graphics.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void check_plane(Manager *man, int i, float delta_time, bool *remove)
{
    update_plane_entity(man, i, delta_time);
    if (is_close_to_target(man->entities[i])) {
        remove[i] = true;
    }
}

bool remove_plane(Entity entity_a, Entity entity_b, Coli_check *context)
{
    if (!check_collision(entity_a, entity_b)) {
        return false;
    }
    return !is_within_control_area(entity_a, context->manager,
        context->window_width, context->window_height) &&
        !is_within_control_area(entity_b, context->manager,
        context->window_width, context->window_height);
}

void check_collisions_for_plane(Coli_check *context, int i, bool *remove)
{
    Entity entity_a = context->manager->entities[i];
    Entity entity_b;

    for (int j = i + 1; j < context->manager->entity_count; ++j) {
        entity_b = context->manager->entities[j];
        if (entity_b.is_active && entity_b.type == PLANE &&
            remove_plane(entity_a, entity_b, context)) {
            remove[i] = true;
            remove[j] = true;
            break;
        }
    }
}

void remove_marked_entities(Manager *manager, bool *remove)
{
    for (int i = manager->entity_count - 1; i >= 0; i--) {
        if (remove[i]) {
            remove_entity(manager, &i);
        }
    }
}

void process_plane_entity(plane_context *context)
{
    check_plane(context->manager, context->index,
    context->delta_time, context->remove);
    if (!context->remove[context->index]) {
        check_collisions_for_plane(context->collision_context,
        context->index, context->remove);
    }
}

/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Init_Entity
*/

#include "all_headers.h"
#include <SFML/Graphics.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool is_close_to_target(Entity entity)
{
    float arrival_threshold = 10.0f;
    float dx = entity.position.x - entity.target.x;
    float dy = entity.position.y - entity.target.y;
    float distance = sqrt(dx * dx + dy * dy);

    return distance < arrival_threshold;
}

plane_context init(Manager *man, int i, float delta, Coli_check *coli)
{
    plane_context process_context;

    process_context.manager = man;
    process_context.index = i;
    process_context.delta_time = delta;
    process_context.collision_context = coli;
    return process_context;
}

void update_ent(Manager *man, float delta_time, int width, int height)
{
    static float elapsed_time = 0;
    bool remove[70000] = {false};
    Coli_check collision_context = {man, width, height};
    plane_context process_context;

    elapsed_time += delta_time;
    activate_entities(man, elapsed_time);
    for (int i = 0; i < man->entity_count; ++i) {
        if (man->entities[i].is_active && man->entities[i].type == PLANE) {
            process_context.manager = man;
            process_context.index = i;
            process_context.delta_time = delta_time;
            process_context.remove = remove;
            process_context.collision_context = &collision_context;
            process_plane_entity(&process_context);
        }
    }
    remove_marked_entities(man, remove);
}

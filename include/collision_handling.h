/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Collision_Handling
*/

#ifndef COLLISION_HANDLING_H
    #define COLLISION_HANDLING_H

    #include <stdbool.h>
    #include "app_config.h"
    #include "manager_structs.h"

void check_plane(Manager *man, int i, float delta_time, bool *remove);
bool remove_plane(Entity entity_a, Entity entity_b, Coli_check *context);
void check_collisions_for_plane(Coli_check *context, int i, bool *remove);
void remove_marked_entities(Manager *manager, bool *remove);
void process_plane_entity(plane_context *context);

#endif // COLLISION_HANDLING_H

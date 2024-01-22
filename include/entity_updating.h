/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Entity_Updating
*/

#ifndef ENTITY_UPDATING_H
    #define ENTITY_UPDATING_H

    #include <stdbool.h>
    #include "app_config.h"
    #include "manager_structs.h"

void update_plane_entity(Manager *manager, int i, float delta_time);
bool is_close_to_target(Entity entity);
void remove_entity(Manager *manager, int *i);
void update_entity_if_plane(Manager *manager, int i, float delta_time);
void activate_entities(Manager *manager, float elapsed_time);

#endif // ENTITY_UPDATING_H

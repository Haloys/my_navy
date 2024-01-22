/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Entity_Management
*/

#ifndef ENTITY_MANAGEMENT_H
    #define ENTITY_MANAGEMENT_H

    #include "manager_structs.h"

void add_entity_to_manager(Entity* entity, Manager* manager);
sfSprite* create_sprite(sfTexture* texture, float scale);
void assign_nearest_towers(Manager* manager);
void update_target_for_plane(Manager* manager, int i);
float calculate_rotation_angle(Vector2 direction);

#endif // ENTITY_MANAGEMENT_H

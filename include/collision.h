/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Collision
*/

#ifndef COLLISION_H
    #define COLLISION_H

    #include "manager_structs.h"

bool check_collision(Entity a, Entity b);
bool is_entity_within_radius(Entity ent, Entity tower, int greatest_side);
bool is_within_control_area(Entity ent, Manager* man, int width, int height);

#endif // COLLISION_H

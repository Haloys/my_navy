/*
** EPITECH PROJECT, 2023
** Header
** File description:
** Utils
*/

#ifndef UTILS_H
    #define UTILS_H

    #include "entity_structs.h"

Vector2 calculate_direction(Vector2 from, Vector2 to);
float calculate_distance(Vector2 from, Vector2 to);
int find_nearest_tower(Entity* ent, int entity_count, Vector2 plane_position);

#endif // UTILS_H

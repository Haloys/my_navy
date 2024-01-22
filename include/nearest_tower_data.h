/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Nearest_Tower_Data
*/

#ifndef NEAREST_TOWER_DATA_H
    #define NEAREST_TOWER_DATA_H

    #include "entity_structs.h"

typedef struct {
    Vector2 plane_position;
    float min_distance;
    int nearest_tower_index;
} NearestTowerData;

#endif // NEAREST_TOWER_DATA_H

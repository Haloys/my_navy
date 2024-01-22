/*
** EPITECH PROJECT, 2023
** Utils
** File description:
** Utils
*/

#include "all_headers.h"
#include <SFML/Graphics.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

Vector2 calculate_direction(Vector2 from, Vector2 to)
{
    Vector2 dir = {to.x - from.x, to.y - from.y};
    float length = sqrt(dir.x * dir.x + dir.y * dir.y);

    if (length != 0) {
        dir.x /= length;
        dir.y /= length;
    }
    return dir;
}

void update_nearest_tower(Entity* ent, int i, NearestTowerData* data)
{
    float dx = data->plane_position.x - ent[i].position.x;
    float dy = data->plane_position.y - ent[i].position.y;
    float distance = sqrt(dx * dx + dy * dy);

    if (distance < data->min_distance) {
        data->min_distance = distance;
        data->nearest_tower_index = i;
    }
}

int find_nearest_tower(Entity* ent, int entity_count, Vector2 plane_position)
{
    NearestTowerData data = {plane_position, FLT_MAX, -1};

    for (int i = 0; i < entity_count; ++i) {
        if (ent[i].type == TOWER) {
            update_nearest_tower(ent, i, &data);
        }
    }
    return data.nearest_tower_index;
}

/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Collision
*/

#include "all_headers.h"
#include <SFML/Graphics.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

bool check_collision(Entity a, Entity b)
{
    const float collision_distance = 20.0f;
    float dx = a.position.x - b.position.x;
    float dy = a.position.y - b.position.y;
    float distance_squared = dx * dx + dy * dy;

    return distance_squared < collision_distance * collision_distance;
}

bool is_entity_within_radius(Entity ent, Entity tower, int greatest_side)
{
    float actual_radius = (tower.radius / 100.0f) * greatest_side;
    float dx = ent.position.x - tower.position.x;
    float dy = ent.position.y - tower.position.y;
    float distance = sqrt(dx * dx + dy * dy);

    return distance <= actual_radius;
}

bool is_within_control_area(Entity ent, Manager* man, int width, int height)
{
    int greatest_side = width > height ? width : height;
    int i;

    for (i = 0; i < man->entity_count; ++i) {
        if (man->entities[i].type != TOWER) {
            continue;
        }
        if (is_entity_within_radius(ent, man->entities[i], greatest_side)) {
            return true;
        }
    }
    return false;
}

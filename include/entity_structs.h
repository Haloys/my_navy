/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Entity_Structs
*/

#ifndef ENTITY_STRUCTS_H
    #define ENTITY_STRUCTS_H

    #include <stdbool.h>
    #include <SFML/Graphics.h>

typedef enum {
    PLANE,
    TOWER
} EntityType;

typedef struct {
    float x;
    float y;
} Vector2;

typedef struct {
    EntityType type;
    Vector2 position;
    Vector2 target;
    sfSprite* sprite;
    float speed;
    float delay;
    bool is_active;
    int radius;
    bool has_collided;
} Entity;

#endif // ENTITY_STRUCTS_H

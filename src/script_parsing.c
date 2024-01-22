/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Script_Parsing
*/

#include "all_headers.h"
#include <SFML/Graphics.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void parse_plane(char *line, Entity *entity, Manager *manager)
{
    char *ptr = line + 2;
    float plane_scale = 0.07f;

    entity->position.x = parse_float(&ptr);
    entity->position.y = parse_float(&ptr);
    entity->target.x = parse_float(&ptr);
    entity->target.y = parse_float(&ptr);
    entity->speed = parse_float(&ptr);
    entity->delay = parse_int(&ptr);
    entity->is_active = false;
    entity->type = PLANE;
    entity->sprite = create_sprite(manager->plane_texture, plane_scale);
    add_entity_to_manager(entity, manager);
    manager->planes_to_take_off++;
}

void parse_tower(char *line, Entity *entity, Manager *manager)
{
    char *ptr = line + 2;
    float tower_scale = 0.1f;

    entity->position.x = parse_float(&ptr);
    entity->position.y = parse_float(&ptr);
    entity->radius = parse_int(&ptr);
    entity->type = TOWER;
    entity->sprite = create_sprite(manager->tower_texture, tower_scale);
    add_entity_to_manager(entity, manager);
}

void parse_script(const char *filepath, Manager *manager)
{
    FILE* file = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    manager->planes_to_take_off = 0;
    if (file == NULL) {
        perror("Error opening script file");
        return;
    }
    read = getline(&line, &len, file);
    while (read != -1) {
        parse_line(line, manager);
        read = getline(&line, &len, file);
    }
    free(line);
    fclose(file);
    assign_nearest_towers(manager);
}

void parse_line(char *line, Manager *manager)
{
    Entity entity;

    if (line[0] == 'A') {
        parse_plane(line, &entity, manager);
    } else if (line[0] == 'T') {
        parse_tower(line, &entity, manager);
    }
}

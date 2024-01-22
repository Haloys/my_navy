/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Script_Parsing
*/

#ifndef SCRIPT_PARSING_H
    #define SCRIPT_PARSING_H

    #include "manager_structs.h"

void parse_script(const char *filepath, Manager *manager);
void parse_line(char *line, Manager *manager);
void parse_plane(char *line, Entity *entity, Manager *manager);
void parse_tower(char *line, Entity *entity, Manager *manager);

#endif // SCRIPT_PARSING_H

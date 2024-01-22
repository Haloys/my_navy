/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Init_Entity
*/

#ifndef INIT_ENTITY_H
    #define INIT_ENTITY_H

    #include <stdbool.h>
    #include "app_config.h"
    #include "manager_structs.h"

plane_context init(Manager *man, int i, float delta, Coli_check *coli);
void update_ent(Manager *man, float delta_time, int width, int height);

#endif // INIT_ENTITY_H

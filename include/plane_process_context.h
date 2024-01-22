/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Plane_Process_Context
*/

#ifndef PLANE_PROCESS_CONTEXT_H
    #define PLANE_PROCESS_CONTEXT_H

    #include "manager_structs.h"
    #include "coli_check.h"

typedef struct {
    Manager *manager;
    int index;
    float delta_time;
    bool *remove;
    Coli_check *collision_context;
} plane_context;

#endif // PLANE_PROCESS_CONTEXT_H

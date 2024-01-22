/*
** EPITECH PROJECT, 2023
** My_Radar
** File description:
** Init_Cleanup
*/

#ifndef INIT_CLEANUP_H
    #define INIT_CLEANUP_H

    #include "manager_structs.h"

void init_manager_basic(Manager* manager);
void init_manager_text_elements(Manager* manager, sfRenderWindow* window);
int load_textures(Manager* manager);
void cleanup(Manager* manager);

#endif // INIT_CLEANUP_H

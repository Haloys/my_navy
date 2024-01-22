/*
** EPITECH PROJECT, 2024
** My_Radar
** File description:
** Game_Display
*/

#ifndef GAME_DISPLAY_H
    #define GAME_DISPLAY_H

    #include "manager_structs.h"

void render_active_planes(sfRenderWindow* window, Manager* manager);
void render_arrived_planes(sfRenderWindow* window, Manager* manager);
void render_planes_to_take_off(sfRenderWindow* window, Manager* manager);

#endif // GAME_DISPLAY_H

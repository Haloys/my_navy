/*
** EPITECH PROJECT, 2024
** My_Radar
** File description:
** Game_Display
*/

#include "all_headers.h"
#include <SFML/Graphics.h>
#include <SFML/Graphics/Types.h>
#include <SFML/System/Clock.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void render_active_planes(sfRenderWindow* window, Manager* manager)
{
    char active_planes_str[50];
    sfText* active_planes_text = sfText_create();
    char display_str[60] = "Active Planes: ";

    my_long_to_string((long)manager->active_planes_count,
    active_planes_str);
    my_strcat(display_str, active_planes_str);
    sfText_setString(active_planes_text, display_str);
    sfText_setFont(active_planes_text, manager->timer_font);
    sfText_setCharacterSize(active_planes_text, 24);
    sfText_setColor(active_planes_text, sfWhite);
    sfText_setPosition(active_planes_text, (sfVector2f){270, 950});
    sfRenderWindow_drawText(window, active_planes_text, NULL);
    sfText_destroy(active_planes_text);
}

void render_arrived_planes(sfRenderWindow* window, Manager* manager)
{
    char arrived_planes_str[50];
    sfText* arrived_planes_text = sfText_create();
    char display_str[60] = "Planes Arrived: ";

    my_long_to_string((long)manager->planes_arrived, arrived_planes_str);
    my_strcat(display_str, arrived_planes_str);
    sfText_setString(arrived_planes_text, display_str);
    sfText_setFont(arrived_planes_text, manager->timer_font);
    sfText_setCharacterSize(arrived_planes_text, 24);
    sfText_setColor(arrived_planes_text, sfWhite);
    sfText_setPosition(arrived_planes_text, (sfVector2f){760, 950});
    sfRenderWindow_drawText(window, arrived_planes_text, NULL);
    sfText_destroy(arrived_planes_text);
}

void render_planes_to_take_off(sfRenderWindow* window, Manager* manager)
{
    char planes_to_take_off_str[50];
    sfText* planes_to_take_off_text = sfText_create();
    char display_str[60] = "Planes to Take Off: ";

    my_long_to_string((long)manager->planes_to_take_off,
    planes_to_take_off_str);
    my_strcat(display_str, planes_to_take_off_str);
    sfText_setString(planes_to_take_off_text, display_str);
    sfText_setFont(planes_to_take_off_text, manager->timer_font);
    sfText_setCharacterSize(planes_to_take_off_text, 24);
    sfText_setColor(planes_to_take_off_text, sfWhite);
    sfText_setPosition(planes_to_take_off_text, (sfVector2f){1350, 950});
    sfRenderWindow_drawText(window, planes_to_take_off_text, NULL);
    sfText_destroy(planes_to_take_off_text);
}
